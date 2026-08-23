fun main() {

    var obj = B()
    obj.method()
    var obj2 = A()
    // obj2.xy  can not be accessed 
}

var a = 5 // this is by default public and can be accessed in other files

private var ab = 8 // in this file 

internal var x = 9 // accessed in module 

open class A {
    private var xy = 80
    var t = 30
    protected var inSubClass = 90 ;

 private fun display(){
        println(" this is private function")
    }

  fun display2(){
        println(" this is private function")
    }


}
 

class B: A(){
       fun method(){
        println("this is protected variable $inSubClass")
       }


}