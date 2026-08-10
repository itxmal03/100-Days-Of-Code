fun main() {

    var obj = ME(1, 20)

    println("name is ${obj.name}")

    obj.getName()
    obj.getAge()
    obj.getExp()
}

class ME(var exp: Int, var age: Int) {
    var name: String = "Ali"

    fun getName() {
        println("name is $name")
    }

    fun getAge() {
        println("age is $age")
    }
    fun getExp() {
        println("experienced is $exp")
    }
}
