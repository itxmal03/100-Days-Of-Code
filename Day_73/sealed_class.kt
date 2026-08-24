fun main() {

    // var obj = Result()  it is now allowed

    stateCheck(Failure())
}

fun stateCheck(state: Result) {
    when (state) {
        is Result.Loading -> println("state is loading")
        is Failure -> println("state is failure")
        is Success -> println("state is success")
    }
}

// by default sealed class is protected , only can its child classes can access it , its obj can't
// be created
sealed class Result {
    // can also create subclass

    class Loading : Result()
}

class Success : Result()

class Failure : Result()

/*
sealed class is motly used when we already know how much its sub classes
will be , and also its sub classes can't be created in any other file
*/
