fun main() {
    try {
        var x = "abc".toInt()
    } catch (e: NumberFormatException) {

        println("The error is $e")
    } catch (e: Exception) // always use it at end
    {
        println("The error can not be converted")
    } finally {
        println("this is finally block")
    }

    isEven(3)
}

fun isEven(num: Int) {
    if (num % 2 != 0) {
        throw IllegalArgumentException("this is odd number")
    }
}
