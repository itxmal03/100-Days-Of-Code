#!/bin/bash 

# function cd(){
#     target_directory="$*"
#     if [ $# -eq 0 ]
#     then 
#     target_directory=${HOME}
#     fi 
#     builtin cd "$target_directory" && /bin/ls -lhF --time-style=long-iso --color=auto --ignore=lost+found 
# }


# function keyword is optional here 
 cd(){
    target_directory="$*"
    if [ $# -eq 0 ]
    then 
    target_directory=${HOME}
    fi 
    builtin cd "$target_directory" && /bin/ls -lhF --time-style=long-iso --color=auto --ignore=lost+found 
}