fun main() {
    var obj = OuterClass().InnerClass()
    obj.innerFun()
}

class OuterClass {
    // private can aslo be accessed in inner class if we use inner keyword
    private var name = "OuterClass"
    inner class InnerClass {
        fun innerFun() {
            println("hi this is $name accessed from inner class")
        }
    }
}

/*
    if we don not use inner keyword then
    we can not access outer class members in inner class ,
    because compiler treats it as a separate class
*/
