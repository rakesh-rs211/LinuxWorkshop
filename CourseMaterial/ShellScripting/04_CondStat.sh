#!/bin/bash
#echo $(dirname $0)
if [ -z $1 ]
then
	echo "No arguments passed"
else
	echo "The first argument is: $1"
fi

if [ -f $1 ] && [ -n $1 ]
then
	ls -la $1
else
	echo "The file doesn't exist"
fi

# if command1
# then
# 	runcommand1
# elif
# then
#	runcommand2
# else
#	runcommand3
# if
