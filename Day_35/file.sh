#!/bin/bash
# echo "hello world"
# name="Aftab"
# echo
# echo $name

# taking input from user
# echo "Enter any number: "
# read number
# ((number--))
# echo $number

#single () small brackets run inside code to a new sub shell
# echo "Enter number: "
# read n

# (
#     # will run into a subshell and not effect main program
#    ((n--))
# )

# echo $n

#if want to input in same line as showing output
# read -p "Enter number:" name
# echo $name

#my first script
# read -p 'Enter name of directory you want to create: ' name
# mkdir $name
# ls -alh

# pwd
# ls
# cd Day_35
# shfmt -w file.sh


# type of comments in bash : 3 types 

# first type by hash 
<<com
2nd type to use this symbol and a same word start and end  , can be use for multi-line . not to use extra spaces 
 this is called here-document
com

: '
 3rd type of comments 
'

