#!/bin/bash

if [ -z "$1" ]; then
  echo "Usage: kotlin-run <path/to/file.kt>"
  echo "Example: kotlin-run Day_80/suspend_fixed.kt"
  exit 1
fi

# Use a fixed directory for the JAR (user-writable)
JAR_DIR="$HOME/.kotlin-jars"
mkdir -p "$JAR_DIR"
JAR_PATH="$JAR_DIR/kotlinx-coroutines-core-jvm-1.9.0.jar"

# Download the JAR if it doesn't exist (only ONCE!)
if [ ! -f "$JAR_PATH" ]; then
  echo "📦 Downloading coroutines JAR (this happens only once)..."
  curl -L -o "$JAR_PATH" "https://repo1.maven.org/maven2/org/jetbrains/kotlinx/kotlinx-coroutines-core-jvm/1.9.0/kotlinx-coroutines-core-jvm-1.9.0.jar"
  echo "✅ Download complete."
fi

# Get the directory and filename
FILE_PATH="$1"
DIR=$(dirname "$FILE_PATH")
BASENAME=$(basename "$FILE_PATH" .kt)

# Capitalize first letter for class name
FIRST_LETTER=$(echo "${BASENAME:0:1}" | tr '[:lower:]' '[:upper:]')
CLASS_NAME="${FIRST_LETTER}${BASENAME:1}Kt"

echo "⚙️  Compiling $FILE_PATH ..."
cd "$DIR" || { echo "❌ Directory not found: $DIR"; exit 1; }

kotlinc -cp "$JAR_PATH" "${BASENAME}.kt" -include-runtime -d "${BASENAME}_temp.jar"
if [ $? -ne 0 ]; then
  echo "❌ Compilation failed."
  exit 1
fi

echo "▶️  Running $CLASS_NAME ..."
java -cp "${BASENAME}_temp.jar:$JAR_PATH" "$CLASS_NAME"

rm "${BASENAME}_temp.jar"
echo "✅ Done."