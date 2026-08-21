fun main() {
    var childObj = ChildClass()
    //   childObj.method()
}

open class ParentClass {
    init {
        println("Constructor of ParentClass Called")
    }
    open var name: String = "Parent"

    open fun method() {
        println("this is ${name}'s method")
    }
}

class ChildClass : ParentClass() {
    init {
        println("Constructor of ChildClass Called")
    }
    override var name: String = "Child"

    override fun method() {
        super.method()
        println("this is ${name}'s method")
    }
}
