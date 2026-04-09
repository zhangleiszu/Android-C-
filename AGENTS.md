# AGENTS.md

## Cursor Cloud specific instructions

### Overview

This repository contains two Android JNI sample projects stored as RAR archives (`jniArray.rar` and `MyApplication2.rar`). They must be extracted before building.

- **jniArray** — Multi-module Android project (app + library) with C++ native code compiled via CMake/NDK. Exposes `sumArray()` JNI function.
- **MyApplication2** — Single-module Android app that consumes the pre-built `jni-array.jar` and `.so` native libraries from jniArray.

### Prerequisites (installed in VM snapshot)

- **JDK 8** (`/usr/lib/jvm/java-8-openjdk-amd64`) — required for Gradle 5.1.1 / AGP 3.4.2
- **JDK 21** (`/usr/lib/jvm/java-21-openjdk-amd64`) — required for `sdkmanager` CLI
- **Android SDK** at `/opt/android-sdk`: platform 29, build-tools 29.0.0, NDK 20.1.5948944, CMake 3.10.2
- `unrar` for extracting the `.rar` archives

### Building

Both projects use Gradle 5.1.1 wrapper. **JAVA_HOME must be set to JDK 8** for Gradle builds:

```bash
export JAVA_HOME=/usr/lib/jvm/java-8-openjdk-amd64
export ANDROID_HOME=/opt/android-sdk
export ANDROID_SDK_ROOT=/opt/android-sdk
```

After extracting archives, update `local.properties` in each project to point to the correct SDK:

```
sdk.dir=/opt/android-sdk
ndk.dir=/opt/android-sdk/ndk/20.1.5948944
```

Build commands:
```bash
cd /workspace/jniArray && ./gradlew assembleDebug
cd /workspace/MyApplication2 && ./gradlew assembleDebug
```

### Lint & Tests

```bash
cd /workspace/jniArray && ./gradlew lint test
cd /workspace/MyApplication2 && ./gradlew lint test
```

### Gotchas

- The `sdkmanager` CLI requires JDK 11+ (use JDK 21), but Gradle builds require JDK 8. Switch `JAVA_HOME` accordingly.
- `local.properties` files inside the archives point to the original developer's macOS SDK paths and must be overwritten after extraction.
- These are 2019-era projects (AGP 3.4.2, Gradle 5.1.1). Do not upgrade without careful migration.
- There is no Android emulator in this VM — builds produce APKs but cannot be run on-device. End-to-end APK testing requires a physical device or emulator.
- The `jniArray` project's CMake output directory (`jniLibs/${ANDROID_ABI}`) writes `.so` files outside the standard build directory.
