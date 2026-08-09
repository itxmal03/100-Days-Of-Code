fun main() {

    val array1 = arrayOf(1, 2, 3, 4, 5)

    val array2 = arrayOf<String>("a", "b", "c", "d", "e")

    println(array1.joinToString())

    for (i in array2) {
        println(i)
    }

    for ((i, e) in array1.withIndex()) {
        println("$i $e")
    }

    println("${array2[1]}")

    println("${array2.get(2)}")

    // for setting values

    var arr = arrayOf(3, 4)
    arr[0] = 10
    arr.set(1, 20)

    var array3: Array<Int?> = arrayOfNulls(3)

    println(array3.joinToString())
}
