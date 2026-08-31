import kotlinx.coroutines.*

fun main(): Unit = runBlocking {
    println("Main thread: ${Thread.currentThread().name}")
    
    launch {
        first()
    }
    launch {
        second()
    }
    
    println("Both coroutines launched. Waiting...")
}

suspend fun first() {
    println("Fun1 Started on: ${Thread.currentThread().name}")
    delay(1000)
    println("Fun1 resumed on: ${Thread.currentThread().name}")
}

suspend fun second() {
    println("Fun2 Started on: ${Thread.currentThread().name}")
    delay(1000)
    println("Fun2 resumed on: ${Thread.currentThread().name}")
}