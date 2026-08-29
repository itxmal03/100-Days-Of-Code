fun main() {

    // var emp = Employe();
    // emp.apply {
    //     this.id = 1
    //     this.name = "Ali" // context is referredby this
    // }

    // emp.apply {
    //     id = 2
    //     name = "Ahmad"
    // }
    // println(emp.id)
    // println(emp.name)

    // var x = emp.apply {
    //     id = 2
    //     name = "Ahmad" 
    //     println("hi this is apply fun") // apply alway return the object no matter what is in its last line 
    // }
    // println(x.id)

    var empl: Employe? = null

    // empl?.let {   // operates only on non nullable values
    //     it.id = 1
    //     it.name = "Aftab" // it will return what is in last line 
    // }
    // println(empl.name) // it will print nothing because obj is null intially so none i.e error 


    // var emply: Employe? = Employe()

    // emply?.let {   // operates only on non nullable values
    //     println(emply.id)
    // }


    var em = Employe()

    // with(em){
    //     println(this.name) // it will return what is in last line 
    // }


    // var am = Employe()

    // am?.run {  // it also provide this functionality of let 
    //     println(this.name) // it will return what is in last line 
    // }
    
    
   var x =  em.also{
        println(it.name) // return object  used after intailization of object for extra functionality 
    }

    


}

/*
 scope functions 
 1.apply
 2.let
 3.with
 4.run 
 */

class Employe {
    var id = 0
    var name = "a"
}