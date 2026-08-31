plugins {
    kotlin("jvm") version "1.9.22"
    application
}

repositories {
    mavenCentral()
}

dependencies {
    // All your dependencies go here (auto-downloaded!)
    implementation("org.jetbrains.kotlinx:kotlinx-coroutines-core:1.9.0")
}

tasks.withType<org.jetbrains.kotlin.gradle.tasks.KotlinCompile> {
    kotlinOptions.jvmTarget = "21"
}

// This task lets you run any main class by passing -PmainClass=
tasks.register<JavaExec>("runMain") {
    group = "application"
    description = "Run a specific main class"
    classpath = sourceSets["main"].runtimeClasspath
    // Default main class (change this to your current day)
    mainClass = project.properties["mainClass"] as String? ?: "day80.SuspendFixedKt"
}