import kotlinx.coroutines.*
import java.net.URL
import java.net.HttpURLConnection
import java.io.BufferedReader
import java.io.InputStreamReader

fun main(): Unit = runBlocking {
    val result = async { fetchUsers() }.await()
    println(result)
}

private suspend fun fetchUsers(): String {
    // 1. Make HTTP request (blocking, but we're on IO later)
    val url = URL("https://jsonplaceholder.typicode.com/users")
    val connection = url.openConnection() as HttpURLConnection
    connection.requestMethod = "GET"

    val reader = BufferedReader(InputStreamReader(connection.inputStream))
    val response = StringBuilder()
    var line: String?
    while (reader.readLine().also { line = it } != null) {
        response.append(line)
    }
    reader.close()
    connection.disconnect()

    // 2. Manually parse JSON without any external library
    val json = response.toString()
    return parseUsers(json)
}

// ⚠️ Manual parser – works only for this specific API response!
private fun parseUsers(json: String): String {
    val result = StringBuilder()
    // Split by "{" and "}" to find each user object
    val objects = json.split("},")
    var id = 0
    var name = ""
    for (obj in objects) {
        // Extract id
        val idMatch = Regex(""""id":(\d+)""").find(obj)
        id = idMatch?.groupValues?.get(1)?.toIntOrNull() ?: 0

        // Extract name
        val nameMatch = Regex(""""name":"(.*?)"""").find(obj)
        name = nameMatch?.groupValues?.get(1) ?: "Unknown"

        if (id != 0) {
            result.append("ID $id\nName $name\n\n")
        }
    }
    return result.toString()
}