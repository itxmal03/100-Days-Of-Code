#!/bin/bash
# control=0
# match_case(){
# case $1 in 
#         1) echo "entered 1";;
#         2) echo "entered 2";;
#         3) echo "entered 3";;
#         4) echo "entered 4";;
#         5) control=1
#            echo "exit successfully!!!!!!!!!!!!!!!!!!!";;
#         *) echo "entered invalid choice"
# esac 
      
# }

# while [ $control -ne 1 ]
# do 
#     read -p "Enter choice: 1 2 3 4 5-to exit" choice
#     match_case $choice
# done




match_case(){
case $1 in 
        1) echo "entered 1";;
        2) echo "entered 2";;
        3) echo "entered 3";;
        4) echo "entered 4";;
        5) echo "exit successfully!!!!!!!!!!!!!!!!!!!"
           return 1;;
        *) echo "entered invalid choice"
esac 
      
}

control=0
while [ $control -ne 1 ]
do 
    read -r -p "Enter choice: 1 2 3 4 5-to exit" choice
    match_case "$choice"
    if [ $? -eq 1 ]
    then break
    fi
done