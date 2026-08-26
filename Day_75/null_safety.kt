fun main() {

    val s: String = "not nullable variable"

    val str: String? = null

    val str2: String? = "nullable variable"

    println(s)
    println(str)
    println(str2)

    if (str != null) {
        println(str2)
    }

    // println(str2?.isPalindrome())

    // elvis operator
    var x = str?.length ?: 0

    println(x)

    str?.let { println(it.length) }
}

// fun String.isPalindrome(): Boolean {
//     return this.lowercase() == this.lowercase().reversed()
// }
