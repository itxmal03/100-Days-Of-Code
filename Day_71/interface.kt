fun main() {
    var obj = Cash2()
    // obj.method()
    var array = arrayOf(Cash2(), Card2(), Online2())
    for (v in array) {
        v.method()
        v.name()
    }
}


/*
interface is by default abstract and the methods and variable in it
are by default abstract , if we write there body also then they
become automatically non abstract an a normal method or member
*/

interface Name {
    fun name()
}

interface Type {
    fun type()
    //  var variable:String

}

abstract class Payment2 : Name, Type {
    open fun method() {
        println("Default method")
    }

    override fun name() {
        println("name is Payment")
    }
}

class Cash2 : Payment2() {
    override fun method() {
        println("Paying via Cash")
    }

    override fun name() {
        println("name is cash2")
    }

    override fun type() {
        println("Type is payment")
    }
}

class Card2 : Payment2() {
    override fun method() {
        println("Paying via Card")
    }

    override fun name() {
        println("name is card2")
    }
    override fun type() {
        println("Type is payment")
    }
}

class Online2 : Payment2() {
    override fun method() {
        println("Paying via Online paying method")
    }

    override fun name() {
        println("name is online 2")
    }
    override fun type() {
        println("Type is payment")
    }
}

class Animals : Name, Type {

    override fun name() {
        println("name is animal")
    }

    override fun type() {
        println("Type is payment")
    }
}
