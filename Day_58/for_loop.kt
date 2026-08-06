fun main() {

    for (i in 1..10) {
        println(i)
    }

    // increase by 2
    for (i in 1..10 step 2) {
        println(i)
    }

    // upper bound is not included it means from 1 to 9
    for (i in 1 until 10) {
        println(i)
    }

    // reverse
    for (i in 10 downTo 1) {
        println(i)
    }

    //print table of 5 
    var num = 5
    for (i in 1..10) {
        println("$num * $i = ${num*i}")
    }
}
