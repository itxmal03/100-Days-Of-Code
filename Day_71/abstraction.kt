fun main() {
    var obj = Cash1()
    // obj.method()
    var array = arrayOf(Cash1(), Card1(), Online1())
    for (v in array) {
        v.method()
        println(v.abs)
    }
}

abstract class PaymentMethods {
    abstract fun method()
    abstract var abs: Int
}

class Cash1 : PaymentMethods() {
    override fun method() {
        println("Paying via Cash")
    }

    override var abs: Int = 1
}

class Card1 : PaymentMethods() {
    override fun method() {
        println("Paying via Card")
    }
    override var abs: Int = 2
}

class Online1 : PaymentMethods() {
    override fun method() {
        println("Paying via Online paying method")
    }
    override var abs: Int = 3
}
