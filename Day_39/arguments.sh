#!/bin/bash

# for accepting arguments from command line use $1 for first argument and so on ... 
# echo "you entered argument $1"

# add check so that user can't enter empty input $# for number of arguments . . . . 

if [ $# -ne 1 ] 
then 
   echo "exactly one argument is needed to run this script!!!!!!"
   exit 1 
fi


lines=$(ls -alh $1 | wc -l)

echo "There are $((lines-1)) lines in this directory !!!" 
