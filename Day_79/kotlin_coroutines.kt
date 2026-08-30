/*
 * COROUTINES EXPLAINED (Your original notes + my expansions)
 * ============================================================
 * 
 * What are coroutines?
 * - "Co-operative routines" or functions that cooperate with each other.
 * - They are NOT actual OS threads. They manage threads intelligently.
 * - Kotlin team calls them "lightweight threads" because you can launch 
 *   thousands of them without crashing your app.
 * 
 * Why do we need them?
 * - OS threads are expensive: each thread holds ~1MB of memory.
 * - If you create too many threads, the app slows down or hangs.
 * - Coroutines solve this by "releasing" the thread when the task is waiting 
 *   (e.g., waiting for a network response). That thread can then be used 
 *   by another coroutine. This is called "suspension" - the coroutine 
 *   suspends, not the thread.
 * 
 * ------------ SYNTAX BREAKDOWN ------------
 * CoroutineScope.(coroutineContext).coroutineBuilder {
 *     // coroutine code
 * }
 * 
 * 1. CoroutineScope     → Where the coroutine lives (manages lifecycle).
 * 2. coroutineContext   → Dispatcher + Job + other metadata.
 * 3. Dispatcher         → Which thread(s) to use (Main, Default, IO).
 * 4. Job                → Lifecycle & cancellation control.
 * 5. coroutineBuilder   → launch (fire-and-forget) or async (returns a result).
 * 
 * This file demonstrates ALL of these concepts WITHOUT custom suspend functions.
 */

import kotlinx.coroutines.*

// main() is wrapped in runBlocking.
// runBlocking is a bridge between regular code and coroutines.
// It blocks the main thread until ALL coroutines inside it complete.
fun main(): Unit = runBlocking {
    println("=== COROUTINE DEMO START ===")
    println("Main thread: ${Thread.currentThread().name}")
    println()

    // ------------------------------------------------------------
    // 1. BASIC LAUNCH (Fire and forget)
    // - Uses Dispatchers.Default (CPU-intensive work).
    // - This is like starting a background thread, but much lighter.
    // ------------------------------------------------------------
    val job1 = CoroutineScope(Dispatchers.Default).launch {
        println("[Job 1] Started on thread: ${Thread.currentThread().name}")
        // Simulate heavy work (no suspend needed here because it's just a loop)
        var sum = 0
        for (i in 1..10_000_000) {
            sum += i
        }
        println("[Job 1] Sum = $sum")
        println("[Job 1] Finished on thread: ${Thread.currentThread().name}")
    }

    // ------------------------------------------------------------
    // 2. LAUNCH WITH DELAY (Simulates network call)
    // - delay() is a suspend function provided by the library.
    // - While delay() is running, the thread is RELEASED and can do other work.
    // - This is the "magic" of coroutines.
    // ------------------------------------------------------------
    val job2 = CoroutineScope(Dispatchers.Default).launch {
        println("[Job 2] Started on thread: ${Thread.currentThread().name}")
        delay(500) // Suspends, releases thread for 500ms
        println("[Job 2] After 500ms delay on thread: ${Thread.currentThread().name}")
    }

    // ------------------------------------------------------------
    // 3. ASYNC (Returns a result)
    // - async is like launch, but it returns a Deferred<T> object.
    // - You call .await() to get the result (which suspends until ready).
    // - This is perfect for parallel computation.
    // ------------------------------------------------------------
    val deferred = CoroutineScope(Dispatchers.Default).async {
        println("[Async] Calculating large sum on thread: ${Thread.currentThread().name}")
        var sum = 0
        for (i in 1..50_000_000) {
            sum += i
        }
        sum // This is the return value
    }

    // ------------------------------------------------------------
    // 4. CUSTOM SCOPE (With SupervisorJob)
    // - SupervisorJob means: if one child fails, others keep running.
    // - Regular Job would cancel all children if one fails.
    // ------------------------------------------------------------
    val customScope = CoroutineScope(Dispatchers.Default + SupervisorJob())

    val job3 = customScope.launch {
        println("[Job 3] Started on thread: ${Thread.currentThread().name}")
        var sum = 0
        for (i in 1..5_000_000) {
            sum += i
        }
        println("[Job 3] Sum = $sum")
    }

    val job4 = customScope.launch {
        println("[Job 4] Started on thread: ${Thread.currentThread().name}")
        delay(300) // Suspends
        println("[Job 4] After delay on thread: ${Thread.currentThread().name}")
    }

    // ------------------------------------------------------------
    // 5. WAITING FOR RESULTS (join / await)
    // - join() waits for a launch job to finish.
    // - await() waits for an async job and returns its result.
    // ------------------------------------------------------------
    job1.join() // Wait for job1
    job2.join() // Wait for job2
    job3.join() // Wait for job3
    job4.join() // Wait for job4

    val result = deferred.await() // Get the result from async
    println("[Async] Result from async: $result")

    // ------------------------------------------------------------
    // 6. CLEANUP
    // - Cancel the custom scope to free resources.
    // - This is equivalent to what you'd do in onDestroy() in Android.
    // ------------------------------------------------------------
    customScope.cancel()
    println("Custom scope cancelled.")

    println("=== COROUTINE DEMO END ===")
}

// ------------------------------------------------------------
// IMPORTANT NOTES (Read this after running the code)
// ------------------------------------------------------------
// 1. lifecycleScope.launch { ... } is ONLY for Android Activities/Fragments.
//    It automatically cancels when the Activity is destroyed.
//    In standalone scripts, you manage the scope yourself.
// 
// 2. Dispatchers.Main only exists on Android/JavaFX.
//    In terminal scripts, use Dispatchers.Default or Dispatchers.IO.
// 
// 3. Dispatchers.Default → CPU-heavy work (loops, calculations).
//    Dispatchers.IO → Network, file I/O, database.
// 
// 4. SupervisorJob vs Job:
//    - Job: if one child fails, all siblings are cancelled.
//    - SupervisorJob: if one child fails, siblings keep running.
// 
// 5. You NEVER need to write your own suspend function to use coroutines.
//    You can just use launch/async with regular functions.
//    suspend is only needed when you want to CALL delay/withContext/await
//    from your own custom function (which you haven't studied yet).