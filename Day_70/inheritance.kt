fun main() {

    var obj = DerivedClass()
    println("hi ${obj.name2}")
    obj.baseMethod()
    obj.derivedMethod()
}

open class BaseClass {
    var name: String = "Ahmad"

    fun baseMethod() {
        println("Hi this is $name from base class")
    }
}

class DerivedClass : BaseClass() {
    var name2: String = "Ali"

    fun derivedMethod() {
        println("this is  ${name2} form  derived class")
        println("Hi this is $name from base class")
    }
}
