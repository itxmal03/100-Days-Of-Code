fun main() {

    var dir = Directions.East

    println(dir.ordinal)

    var time = Time.AM

    println(time)

    time.method()
}

enum class Directions {
    East,
    West,
    North,
    South,
}

enum class Time(var t: Int) {
    AM(1),
    PM(2);

    fun method() {
        println("hello this is $this") // it points to thie current object
    }
}

/*
 enum class is used when we already know how many
 objects will be
*/
