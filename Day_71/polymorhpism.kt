fun main() {
    var obj = Cash()
    // obj.method()
    var array = arrayOf(Cash(), Card(), Online())
    for (v in array) {
        v.method()
    }
}

open class Payment {
    open fun method() {
        println("Default method")
    }
}

class Cash : Payment() {
    override fun method() {
        println("Paying via Cash")
    }
}

class Card : Payment() {
    override fun method() {
        println("Paying via Card")
    }
}

class Online : Payment() {
    override fun method() {
        println("Paying via Online paying method")
    }
}
