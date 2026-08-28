fun main() {
    var x = 5
    println(square(x))

    var sq = ::square

    println("Square via shortcut variable is ${sq(8)}")

    var a = 10
    var b = 5
    arithmeticOpr(a, b, ::sub)
    arithmeticOpr(a, b, ::add)

    arithmeticOpr(
            a,
            b,
            fun(a: Int, b: Int): Int {
                return a + b
            }
    )
}

fun square(a: Int): Int {
    return a * a
}

fun add(a: Int, b: Int): Int {
    return a + b
}

fun sub(a: Int, b: Int): Int {
    return a - b
}

fun arithmeticOpr(a: Int, b: Int, func: (Int, Int) -> Int) {
    var result = func(a, b)
    println("Result is $result")
}

// in higher order functions we can pass fun in parameter and also return fun from another fun
