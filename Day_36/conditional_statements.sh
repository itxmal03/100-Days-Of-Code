#!/bin/bash 

# if lsd
# then echo "yes ls command exists!"
# elif pwdc
# then echo "yes pwd command exists!"
# else 
#     echo "no command exists!"
# fi


# read a
# read b 
# if [ $a -eq $b ]  # this is old style  using single [] brackets and this bracket is a command - test $a -eq $b   spaces are needed within brackets  (equal to -eq)
# then echo "yes both numbers are equal"
# else 
#      echo "both numbers are not equal" 
# fi 

# read a
# read b
# if [[ $a -ne $b ]]  # this is modern style  using double [[]] brackets but still needs spaces inside   (not equal to -ne) 
# then echo "yes both numbers are not equal"
# else 
#      echo "both numbers are equal" 
# fi 


# read a 
# read b 
# if [[ $a -gt $b ]]  
# then echo "yes first number is greater than second!"
# else 
#      echo "First number is not greater than second!" 
# fi 


# read a 
# read b 
# if [[ $a -lt $b ]]  
# then echo "yes first number is less than second!"
# else 
#      echo "First number is not less than second!" 
# fi 


# read a 
# read b 
# if [[ $a -le $b ]]  
# then echo "yes first number is less than or equal to second!"
# else 
#      echo "First number is not less than or equal to second!" 
# fi 


# read a 
# read b 
# if [[ $a -ge $b ]]  
# then echo "yes first number is greater than or equal to second!"
# else 
#      echo "First number is not greater than or equal to second!" 
# fi 


# string comparision
# read str_a
# read str_b 

# if [[ $str_a = $str_b ]]         both will work single = or double ==
# then echo " yes both are equal " 
# else echo "both are not equal"
# fi


# read str_a
# read str_b 

# if [[ $str_a != $str_b ]]
# then echo " yes both are not equal " 
# else echo "both are equal"
# fi


# read str_a
# read str_b 

# if [[ $str_a != $str_b ]]
# then echo " yes both are not equal " 
# else echo "both are equal"
# fi 


# str_a="ali"

# if [[ -z $str_a ]]
# then echo " yes string is empty / zero length " 
# else echo " string is not empty "
# fi


# str_a=""

# if [[ -n $str_a ]]
# then echo " yes string is not empty " 
# else echo " string is  empty "
# fi



# read -p "Enter number to check even or odd: " num 
# if (( $num % 2 == 0 ))
# then echo "number is even! "
# else echo "number is odd! "
# fi  

# read -p "Enter value btw 1 and 3: " num 
# if [[ $num == 1 ]]
# then echo "You entered 1" 
# elif [[ $num == 2 ]]
# then echo "You entered 2" 
# else echo "You entered 3"
# fi 



# | Situation                     | Use                |
# | ----------------------------- | ------------------ |
# | Math / numbers / calculations | `(( ))` ✅          |
# | Strings, files, conditions    | `[ ]` or `[[ ]]` ✅ |



#function in bash 

# check_even()
# {
#   if (($1 % 2==0 ))
#   then echo "even!"
#   else echo "odd!"
#   fi
# } 

# read -p "Enter to check even or odd : " num 
# check_even $num
