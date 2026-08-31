import kotlinx.coroutines.*

/*
 * withContext vs async (The Real Difference)
 * ==========================================
 * 
 * withContext : Sequential execution inside a single coroutine.
 *               Waits for the block to finish before moving to the next line.
 *               SWITCHES the dispatcher (e.g., main → IO, IO → main).
 *               It is SUSPENDING (releases the thread while waiting).
 * 
 * async      : Starts a NEW coroutine (parallel execution).
 *               Returns a Deferred<T>.
 *               Use .await() to get the result later.
 * 
 * Both are non-blocking (they suspend, not block the OS thread).
 */

fun main(): Unit = runBlocking {
    println("=== Starting withContext Demo ===")
    println("Main thread: ${Thread.currentThread().name}")

    // Launch a coroutine
    val job = launch {
        withContextDemo()
    }

    // This prints immediately because launch is non-blocking
    println("Process launched (main is NOT blocked)")

    // Wait for the job to finish (otherwise main exits early)
    job.join()
    println("=== Demo Complete ===")
}

suspend fun withContextDemo() {
    println("\n[Demo] Started on thread: ${Thread.currentThread().name}")

    // 1. Sequential fetch (using withContext)
    // Each call waits for the previous one to finish.
    // Total time: 2s + 2s = 4s (because they run sequentially).
    println("\n--- Sequential (withContext) ---")
    val startTime = System.currentTimeMillis()

    val users = withContext(Dispatchers.IO) {
        fetchUsers()
    }
    println("Users fetched: $users (time: ${System.currentTimeMillis() - startTime}ms)")

    val subs = withContext(Dispatchers.IO) {
        fetchSubs()
    }
    println("Subscribers fetched: $subs (time: ${System.currentTimeMillis() - startTime}ms)")

    // 2. Parallel fetch (using async)
    // Both tasks start at the same time.
    // Total time: ~2s (because they run in parallel).
    println("\n--- Parallel (async) ---")
    val startTime2 = System.currentTimeMillis()

    // 🔥 FIX: Wrap async calls in coroutineScope to get a CoroutineScope receiver
    coroutineScope {
        val deferredUsers = async { fetchUsers() }
        val deferredSubs = async { fetchSubs() }

        // Await both results (they finish around the same time)
        val users2 = deferredUsers.await()
        val subs2 = deferredSubs.await()

        println("Users (parallel): $users2 (time: ${System.currentTimeMillis() - startTime2}ms)")
        println("Subscribers (parallel): $subs2 (time: ${System.currentTimeMillis() - startTime2}ms)")
    }
}

// Suspend functions (simulate network/database calls)
suspend fun fetchUsers(): String {
    delay(2000) // Simulate 2s network call
    println("[fetchUsers] Running on thread: ${Thread.currentThread().name}")
    return "User123"
}

suspend fun fetchSubs(): String {
    delay(2000) // Simulate 2s network call
    println("[fetchSubs] Running on thread: ${Thread.currentThread().name}")
    return "5,000"
}