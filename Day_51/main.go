package main

import "fmt"

// num := 500  not allowed
//
//	var num = 500   allowed

const Variable1 = "hello go lang" // intial capital letter means it is public

func main() {
	fmt.Println("Hello, Go!")
	var myName string = "Aftab Ali"
	fmt.Println(myName)
	fmt.Printf("type of variable is : %T \n ", myName)

	var isBool bool = false
	fmt.Println(isBool)
	fmt.Printf("type of var is : %T\n", isBool)

	var integerVal uint8 = 255
	fmt.Println(integerVal)
	fmt.Printf("type of var is : %T\n", integerVal)

	var smallFloat float32 = 255.987654
	fmt.Println(smallFloat)
	fmt.Printf("type of var is : %T\n", smallFloat)

	var float_64 float64 = 255.987654345673456777779
	fmt.Println(float_64)
	fmt.Printf("type of var is : %T\n", float_64)

	//default values and aliases
	var unitializedInt int
	fmt.Println(unitializedInt)
	fmt.Printf("type of var is : %T\n", unitializedInt)

	var unitializedStr string
	fmt.Println(unitializedStr)
	fmt.Printf("type of var is : %T\n", unitializedStr)

	// implicit type

	var variable2 = "this is variable created without data type and lexer will auto handle it and assign respective datatype"
	fmt.Println(variable2)
	fmt.Printf("type of var is : %T\n", variable2)

	//no var keyword
	num := 500 //allowed only in any method not globally
	fmt.Println(num)

	fmt.Println(Variable1)
	fmt.Printf("type of var is : %T\n", Variable1)

}
