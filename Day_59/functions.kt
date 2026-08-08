fun main() {
    var a = 10
    var b = 40

    var c = addition(a, b)

    // via named parameters
    var d = subtraction(a1 = a, a2 = b)

    println("addition is $c")
    println("subtraction is $d")
    mulitiply(a1 = a, a2 = b)

    // function can also be assigned to a variable
    var shortCut = ::addition

    println("result of shortcut = ${shortCut(a ,b)}")
}

fun addition(a1: Int, a2: Int): Int {
    return a1 + a2
}

// function as an expression
fun subtraction(a1: Int, a2: Int) = a1 - a2

// Uint - work like void , function will also work if not written uint
fun mulitiply(a1: Int, a2: Int): Unit {
    println("mul:::: ${a1 * a2}")
}

// default parameter
fun div(a1: Int, a2: Int = 1): Unit {
    println("mul:::: ${a1 / a2}")
}

// function overloading
fun mulitiply(a1: Int, a2: Int, a3: Int): Unit {
    println("mul:::: ${a1 * a2 *a3}")
}

fun mulitiply(a1: Int, a2: Float): Unit {
    println("mul:::: ${a1 * a2}")
}
