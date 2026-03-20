#!/bin/bash

# directory base update

# if [ -d /etc/pacman.d ]; then
# 	#this is arch based disto so use following command to update
# 	sudo pacman -Syu
# elif [ -d /etc/apt ]; 
# then
# 	#this is  ubuntu or debian system so use following command to update

# 	echo "this is debian based system"

# 	sudo apt update
# else
# 	echo "non arch nor debian"
# fi


# sys=/etc/os-release

# if grep -q "Arch" $sys 
# then 
#     echo "this is arch based sys"
# elif grep -q "Ubuntu" $sys
# then 
#     echo "this is ubuntu based sys"
# else 
#     echo "any other distro"
# fi


error=error_file.txt
succ=success_file.txt


if [ -d /etc/pacman.d ]; then
	#this is arch based disto so use following command to update
	sudo pacman -Syu 2>> $error 1>>$succ
    if [ $? -ne 0 ]
    then echo "error has been occured! check error file!!!!!!"
    fi
elif [ -d /etc/apt ]; 
then
	#this is  ubuntu or debian system so use following command to update

	echo "this is debian based system"

	sudo apt update 2>> $error 1>>$succ
    if [ $? -ne 0 ]
    then echo "error has been occured! check error file!!!!!!"
    fi
else
	echo "non arch nor debian"
fi