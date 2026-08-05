fun main() {

    var a = 50
    var b = 100

    println("a>b && a<b ${a>b && a<b}")
    println("a>b || a<b ${a>b || a<b}")
    println("!(a>b) ${!(a>b)}")

    var strenth = if (a > b) "a Greater" else "a smaller"
    println(strenth)
}
