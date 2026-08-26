fun main() {

    var person = PersonX.create("student")
    println(person.type)

    var person2 = PersonX.xyz.name
    println(person2)
}

class PersonX(var type: String) {
    // we can also create object inside in class
    // if we use companion keyword then it will act as class's normal member
    companion object Factory {
        fun create(t: String): PersonX {
            return when (t) {
                "student" -> PersonX(type = "student")
                "teacher" -> PersonX(type = "teacher")
                else -> PersonX(type = "person")
            }
        }
    }

    object xyz {
        var name = "xyz"
    }
}
