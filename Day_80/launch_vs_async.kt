import kotlinx.coroutines.*

fun main(): Unit = runBlocking {
    loadHomeScreen()
}

suspend fun loadHomeScreen() {
    // Launch the coroutine on IO dispatcher
    val job = CoroutineScope(Dispatchers.IO).launch {
        // Run async tasks in parallel
        val userDeferred = async {
            println("fetching username")
            delay(1000)
            "User NAME"
        }

        val subsDeferred = async {
            println("fetching SUBSC")
            delay(1000)
            "USER SUBSC"
        }

        val viewsDeferred = async {
            println("fetching VIEWS")
            delay(1000)
            "User VIEWS"
        }

        // Combine results (await waits for each to finish)
        val result = "${userDeferred.await()} | ${subsDeferred.await()} | ${viewsDeferred.await()}"
        println("Final Result: $result")
    }
    
    // CRITICAL: Wait for the coroutine to finish before exiting this function
    job.join()
}