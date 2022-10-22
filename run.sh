#!/bin/sh

arrLen=100000000
rep=1000
threads=16

echo "Making executables" &&
make &&
echo "Generating large array" && 
input=$(python3 genInputs.py $arrLen $rep $threads) &&
echo -e "\nRunning concurrent" &&
time echo $input | ./concurrent &&
echo -e "\nRunning sequential" &&
time echo $input | ./sequential
