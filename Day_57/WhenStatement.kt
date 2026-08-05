fun main() {

    var a = 50
    var b = 5

    var opr = "sub"

    // as a statement when is actually switch statement
    when (opr) {
        "add" -> println("Addition of $a and $b is ${a+b}")
        "div" -> println("Division of $a and $b is ${a-b}")
        "sub" -> {
            var c = a - b
            println("Subtraction of b from a is: $c")
        }
        else -> println("undefined operation")
    }

    // as an expression
    var result =
            when (opr) {
                "add" -> a + b
                "div" -> a + b
                "sub" -> {
                    a - b
                }
                else -> 0
            }

    println("Result is: $result")

    // in range case
    var x = 21
    when (x) {
        2 -> println("x is 2")
        3 -> println("x is 2")
        in 11..15 -> println("x is btw 11 and 15")
        !in 16..20 -> println("x is not btw 16 and 20")
        in 20 until 25 -> println("upper bound is not included")
        else -> println("undefined value")
    }
}
