fun main() {
    // var list = listOf(1, 2, 3, 4, 5) // this is immuteable list
    // println(list)

    // println(list.get(2))

    // // list[0] = 9  it is not allowed because it is immutable list
    // var mutableList = mutableListOf(6, 7, 8)
    // println(mutableList)

    // println(mutableList.contains(10))

    // mutableList.addAll(list)
    // println(mutableList)

    // var setOfSubjects =
    //         setOf(
    //                 "maths",
    //                 "physics",
    //                 "maths"
    //         ) // this is immutable set it will only print unique elemnts

    // println(setOfSubjects)
    // println(setOfSubjects.contains("urdu"))
    // println(setOfSubjects.elementAt(0))

    // var mutableSet = mutableSetOf("a", "b")
    // mutableSet.add("d")
    // println(mutableSet)
    // mutableSet.remove("b")
    // println(mutableSet)

    var map =
            mapOf(
                    1 to "Ali",
                    2 to "Ahmad",
                    3 to "butt"
            ) // if keys are duplicate then it will replace the prev value
    println(map)

    var mutableMap = mutableMapOf<Int, String>()
    println(mutableMap)
    mutableMap.put(1, "Aftab")
    mutableMap.put(2, "Mehtab")
    mutableMap.put(3, "Sadaqat")
    println(mutableMap)
    mutableMap.replace(3, "Saqib")
    println(mutableMap)
    mutableMap.remove(2)
    println(mutableMap)


    for ((key , value) in mutableMap) {
        println("$key:$value")
    }
}
