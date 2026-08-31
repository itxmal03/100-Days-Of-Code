import kotlinx.coroutines.*

/*
 * JOB vs DEFERRED (The Core Difference)
 * ======================================
 * - Job      : Returned by launch. Fire-and-forget. No result.
 * - Deferred<T> : Returned by async. Produces a result (T). Extends Job.
 * 
 * JOB HIERARCHY (Parent / Child)
 * ================================
 * - When you launch a coroutine inside another, the outer becomes the parent.
 * - Parent cancellation → all children are cancelled automatically.
 * - Exception in a child → cancels parent AND all siblings (unless SupervisorJob).
 * - SupervisorJob   : child failure does NOT affect siblings or parent.
 * 
 * COOPERATIVE CANCELLATION (Very Important)
 * =========================================
 * - Cancellation is NOT automatic for CPU‑heavy loops.
 * - You MUST check isActive or call ensureActive() periodically.
 */

fun main(): Unit = runBlocking {
    println("=== Starting Demo ===")

    // 1. Show basic job hierarchy (parent → child)
    jobHierarchy()

    // 2. Show cooperative cancellation with infinite loop
    jobHierarchy2()

    println("=== Demo Complete ===")
}

// -----------------------------------------------------------------
// 1. BASIC JOB HIERARCHY (Parent cancels children)
// -----------------------------------------------------------------
suspend fun jobHierarchy() {
    // Create a custom scope with a plain Job (NOT SupervisorJob)
    val scope = CoroutineScope(Dispatchers.Default + Job())

    // Parent job
    val parentJob = scope.launch {
        println("[Parent] Started")

        // Child job - inherits parent's scope automatically
        val childJob = launch {
            try {
                println("[Child] Started")
                delay(2000) // Simulate work
                println("[Child] Completed normally")
            } catch (e: CancellationException) {
                // This runs when parent cancels this child
                println("[Child] was CANCELLED by parent")
            }
        }

        println("[Parent] Waiting for 1 second before cancelling...")
        delay(1000) // Wait 1s, then cancel everything

        // Cancel the parent → this automatically cancels all children
        parentJob.cancel()
        println("[Parent] Cancelled itself (and all children)")
    }

    // Wait for the parent job to finish (including its children)
    parentJob.join()
    println("[Main] jobHierarchy() completed")
}

// -----------------------------------------------------------------
// 2. COOPERATIVE CANCELLATION (The Infinite Loop Problem)
// -----------------------------------------------------------------
suspend fun jobHierarchy2() {
    val scope = CoroutineScope(Dispatchers.Default + Job())

    val parentJob = scope.launch {
        println("[Parent2] Started")

        // Child job with an infinite loop
        val childJob = launch {
            var i = 0

            // ❌ WRONG WAY (your original code):
            // while (true) {
            //     if (isActive) { println("val is $i"); i++ }
            // }
            // PROBLEM: if parent cancels, isActive becomes false,
            //          but the loop never exits → still runs forever.

            // ✅ CORRECT WAY: use isActive as the loop condition
            while (isActive) {
                println("[Child2] Counting: $i")
                i++
                // Simulate some work (without suspending, because suspending
                // would automatically check cancellation anyway).
                // We add a small yield to avoid burning CPU.
                yield() // Pauses briefly, also checks cancellation
            }

            println("[Child2] Exited cleanly because isActive became false")
        }

        println("[Parent2] Running for 1 second, then cancelling...")
        delay(1000)

        // Cancel the parent → child's isActive becomes false → loop exits
        parentJob.cancel()
        println("[Parent2] Cancelled itself")
    }

    parentJob.join()
    println("[Main] jobHierarchy2() completed")
}