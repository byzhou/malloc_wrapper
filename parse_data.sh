#!/bin/bash
ms_print $1 | sed -n "/^ [ 0-9][0-9]/p" | sed "s/,//g" | awk '{print $2 "," $3}' | python -c "
import sys; 
import numpy as np; 
input_line		= sys.stdin.read().split('\n')[:-1]; 
ins_count 		= [int(line.split(',')[0]) for line in input_line]; 
heap_size		= [float(line.split(',')[1]) for line in input_line]; 
for ind,size in enumerate(heap_size[:-1]):
    if heap_size[ind + 1] > size:
        #print [heap_size[ind + 1] - size];
        print ins_count[ind + 1]
print input_line[-1].split(',')[0]
"
