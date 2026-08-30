fun main() {
    printValue(10)
    printValue<String>("hi this is string")   // if we specified type then it will work only for that type
    printValue<Double>(9.99)


    var obj = GenericClass(5)
    obj.display();

    var obj2: GenericClass<String> = GenericClass("at")
    obj2.display()
}

fun <T> printValue(value: T) {
    println(value)
}

class GenericClass<T>(val v: T) {
    fun display() {
        println(v)
    }
}