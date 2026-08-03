fun main() {

    val name = "Aftab" // val == final in dart
    // name = "ahm"; it is not allowed due to val keyword

    var age = 30
    age = 20 // it is allowed

    println("Name is $name")
    println("Name is $age")
    println("Next year I will be ${age + 1}")

    var a: Int = 89
    var b: Int = 9

    println("${a>b}")
    println("${a<b}")
    println("${a>=b}")
    println("${a<=b}")
    println("${a==b}")
    println("${a!=b}")

    println("${a+b}")
    println("${a-b}")
    println("${a/b}")
    println("${a%b}")
    println("${a*b}")
  
}
