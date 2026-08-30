fun main() {
    printVal(1, 4, 5, 6, 8, 9)

    printVal2(arrayOf(1, 4, 6, 8))

    var arr = arrayOf(1, 2, 3)
    // printVal(*arr) still it will not work becasue the fun parameter is of primitve type and varargs create array of obj not obj array

    var arr2 = intArrayOf(1, 2, 3)
    printVal(*arr2) // now it will work becuse * spread operator is used and also it is intArray not Array<Int> 

    var str = arrayOf("a", "b", "c")
    printVal3(*str) // this will work because string is not a primitve data type

}

// vararg is used when we dont sure how many number of arguments will be passed 

fun printVal(vararg number: Int) {
    for (i in number) {
        println(i)
    }
}


fun printVal2(number: Array<Int>) {
    for (i in number) {
        println(i)
    }
}


fun printVal3(vararg str: String) {
    for (i in str) {
        println(i)
    }
}

