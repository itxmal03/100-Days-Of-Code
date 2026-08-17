fun main() {
    println("=== Example 1: Default (No custom getter/setter) ===")
    val p1 = Person()
    p1.age = 25
    println("Age: ${p1.age}") // 25 (stored and returned normally)

    println("\n=== Example 2: Custom Setter Only (Validation) ===")
    val p2 = PersonWithValidation()
    p2.age = 12  // Rejected
    println("Age: ${p2.age}") // 18 (default, because 12 was rejected)
    p2.age = 20  // Accepted
    println("Age: ${p2.age}") // 20

    println("\n=== Example 3: Custom Getter Only (Computed) ===")
    val rect = Rectangle()
    rect.width = 10
    rect.height = 5
    println("Area: ${rect.area}") // 50 (computed on the fly, NOT stored)

    println("\n=== Example 4: Custom Getter + Setter (Your Code Fixed) ===")
    val p3 = Voter()
    p3.age = 12  // Rejected (prints "less than 18")
    println("Age: ${p3.age}") // 18 (default)
    p3.age = 20  // Accepted
    println("Age: ${p3.age}") // 20
}

// Example 1: No custom logic. Kotlin generates get() = field and set(value) { field = value } automatically.
class Person {
    var age: Int = 18
}

// Example 2: Custom setter validates the input. Getter is default (returns field).
class PersonWithValidation {
    var age: Int = 18
        set(value) {
            if (value < 18) {
                println("Rejected: $value is too young. Keeping $field")
            } else {
                field = value // Only update if valid
            }
        }
    // Getter is DEFAULT: get() = field
}

// Example 3: Custom getter computes a value. No backing field for 'area' (it's a val).
class Rectangle {
    var width: Int = 0
    var height: Int = 0
    val area: Int
        get() = width * height // Computed each time you read it
    // No setter, because it's a val (read-only)
}

// Example 4: YOUR CODE, but fixed (getter actually returns the field).
class Voter {
    var age: Int = 18
        get() {
            return field  // FIXED: Now it returns the actual stored value
        }
        set(value) {
            if (value < 18) {
                println("less than 18")
            } else {
                field = value
            }
        }
}