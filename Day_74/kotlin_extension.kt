fun main() {

    var rad = Circle()
    rad.printRadius(3.3)
    rad.perimeter(3.3)

    var str = "Madam"
    println(str.isPalindrome())
}

class Circle {

    fun printRadius(rad: Double) {
        println("the radius is ${3.14*rad*rad}")
    }
}

// extension function

fun Circle.perimeter(rad: Double) {
    println("the perimeter is ${2*3.14*rad}")
}

// extension function can also be created on existing class . For example on string

fun String.isPalindrome(): Boolean {
    return this.lowercase() == this.lowercase().reversed()
}
