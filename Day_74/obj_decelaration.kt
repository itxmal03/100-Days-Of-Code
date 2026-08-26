fun main() {

    println(ABC.name)
    ABC.getName()

    // object expression
    var ob = Object {
        init { println("anonymous object called") }

        var name2 = "anon"
        fun getNameX() {
            println("the name is $name2 ")
        }
    }

    ob.getNameX()


}

// this is called object declearation
// its constructor can not be created
// it can inherit any class or interface
object ABC : X() {
    init {
        println("object called")
    }
    var name = "abc"
    fun getName() {
        println("the name is $name ")
    }
}

open class X {}
