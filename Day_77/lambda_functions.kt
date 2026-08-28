fun main() {

    // var lambdaFun1 = { x: Int, y: Int -> x + y }
    // println(lambdaFun1(5, 5))

    // var lambdaFun2 = { msg: String ->
    //     println("hello this is CS TechTube")
    //     println("the message is $msg")
    // }

    // lambdaFun2("Learning Lambdas Function")

    // var lambdaMinus:(Int ,Int)-> Int = {x , y-> x-y}
    // println(lambdaMinus(10 , 5))

    // var lamSquare: (Int) -> Int = { x -> x * x }

    // println(lamSquare(5))

    // var lambdaSquare: (Int) -> Int = { it -> it * it }
    // println(lambdaSquare(10))

    var x = 10
    var y = 5
    arithmeticOp(x, y) { x, y -> x + y }
    arithmeticOp(100, 5, {x, y -> x + y})
}

fun arithmeticOp(a: Int, b: Int, func: (Int, Int) -> Int) {
    var result = func(a, b)
    println("Result is $result")
}
