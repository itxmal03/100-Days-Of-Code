#!/bin/bash 

#script used to compress file basic script 
# if [ $# -ne 1 ]
# then 
#    echo "Usage: zipf <file_name>"
#    exit 1
# fi
#    /usr/bin/bzip2 -k "$1" 



# directory_name=$1
# total_lines="$(ls -alh "$directory_name" | wc -l )"
# total_files="$((total_lines-1))"
# echo "total lines and files are $total_lines  $total_files"


# practice zipping all files using a loop



#================Mehtod 1 ============= learned array concept in bash 
# if [ $# -ne 1 ]
# then 
#    echo "Error:: Correct usage: zipf <directory_name>" 
#    exit 1 
# fi 
# directory_name=$1 
# #---put all the files in an array 
# files=("$directory_name"/*)

# total_files=${#files[@]}

# n=0
# while [ $n -lt "$total_files" ]
# do 
#     current_file=${files[$n]}
#     if [ -f "$current_file" ]
#     then 
#     echo "Compressing file.... $current_file"
#     /usr/bin/bzip2 -k "$current_file"
#     fi 
#      n=$((n+1))
# done



#================Mehtod 2 =============  using for loop for looping through files in a directory 
directory_name=$1

for file in "$directory_name"/*
do 
    if [ -f "$file" ]
    then 
    echo "Compressing file.... $file"
    /usr/bin/bzip2 -k "$file"
    fi
done 



