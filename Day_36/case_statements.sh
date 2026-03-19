#!/bin/bash 

#case statements or like switch statements 
echo "Welcome to calculator in BASH LANGUAGE:"
read -p "Enter first number: " num1
read -p "Enter second number: " num2

echo -e "Press \n1-for Addition \n2-for Subtraction \n3-for Multiplication \n4-for Division"
read op 

case $op in 
        1) echo "Sum of $num1 and $num2 is: $(($num1+$num2))" ;; 
        2) echo "Diff of $num1 and $num2 is: $(($num1-$num2))" ;; 
        3) echo "Mul of $num1 and $num2 is: $(($num1*$num2))" ;; 
        4) echo "Div of $num1 and $num2 is: $(($num1/$num2))" ;; 
        *) echo "Please Enter correct option";;
esac 