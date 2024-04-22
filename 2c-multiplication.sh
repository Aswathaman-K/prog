#!/bin/bash
echo Enter the Number :
read a
echo Multiplication Table of $a 
for((i=1;i<=10;i++))
do
echo $i*$a=$(($a*$i)) 
done
