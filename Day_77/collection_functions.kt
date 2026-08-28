fun main() {

    var list = listOf("racecar", "Madam", "computer")

    var palindromeStrings = list.filter(::isPalind)

    println(palindromeStrings)

    var palindromeStrings2 =
            list.filter(
                    fun(str: String): Boolean {
                        return str.lowercase() == str.lowercase().reversed()
                    }
            )

    println(palindromeStrings2)

    var palindromeStrings3 = list.filter { isPalind(it) }
    println(palindromeStrings3)

    // all above has same effect

    var upperCase = list.map { it.uppercase() }

    println(upperCase)

    list.forEach { println(it) }

    println("total count of list ${list.count()}")
}

// fun isPalin(): Boolean {
//     return it.lowercase == it.lowercase.reversed()  // it will not work
// }

fun isPalind(str: String): Boolean {
    return str.lowercase() == str.lowercase().reversed()
}
