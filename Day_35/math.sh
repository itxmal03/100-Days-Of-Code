# mathematical operations in bash  
# a=16
# b=10
#using expr command 
# echo `expr $a + $b`
#using brackets 
# echo $(expr $a + $b)
# echo $(expr $a \* $b) # use escape character to make * work as multiplication operator 



# using $ and square brackets []  This works, but it is deprecated (old style) ❌
# echo "The sum of 2 numbers is: $[a + b]"
# echo "The diff of 2 numbers is: $[a - b]"
# echo "The mul of 2 numbers is: $[a * b]"    # don't need to use escape character 
# echo "The div of 2 numbers is: $[a / b]"



# $((a + b)) modern style 
# echo "The sum of 2 numbers is: $((a + b))"
# echo "The diff of 2 numbers is: $((a - b))"
# echo "The mul of 2 numbers is: $((a * b))"    # don't need to use escape character 
# echo "The div of 2 numbers is: $((a / b))"
# echo "The power of 2 numbers is: $((a ** b))"
#  echo "The modulus of 2 numbers is: $((a % b))"



# using | bc -l  stands for basic calculator and -l use for math  library 
# echo "5 / 2" | bc -l  will give floating point division 
# echo "5 + 2" | bc -l 
# echo "5 - 2" | bc -l 
# echo "5 * 2" | bc -l  
#echo "5 % 2" | bc 

# echo $((sqrt(a))) | bc  incorrect 
# echo "sqrt($a)" | bc

# a=$(echo "sqrt(9)" | bc -l)
# echo "$a"
#!/bin/bash

# a=9           # Bash variable
# b=$(echo "sqrt($a)" | bc -l)  # Use bc to calculate
# echo "$b"

# a=25
# a=$(echo "sqrt($a)" | bc )
# echo $a

# a=$(echo "b = sqrt(16); b"| bc)
# echo $a 


c=5
f=3

div=$(echo "scale=2; $c / $f" |bc -l)

echo $div




