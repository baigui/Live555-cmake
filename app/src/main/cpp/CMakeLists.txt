# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

set(Live_inc
        live/UsageEnvironment
        live/BasicUsageEnvironment
        live/groupsock
        live/liveMedia
        live/UsageEnvironment/include
        live/BasicUsageEnvironment/include
        live/groupsock/include
        live/liveMedia/include
        )

file(GLOB BasicUsageEnvironment
        live/BasicUsageEnvironment/*.c
        live/BasicUsageEnvironment/*.cpp
        )

file(GLOB UsageEnvironment
        ../../../../../../../CrossLib/LiveLib/live/UsageEnvironment/*.c
        ../../../../../../../CrossLib/LiveLib/live/UsageEnvironment/*.cpp
        )
file(GLOB groupsock
        live/groupsock/*.c
        live/groupsock/*.cpp
        )

file(GLOB liveMedia
        live/BasicUsageEnvironment/*.c
        live/BasicUsageEnvironment/*.cpp
        )

set(LIVE_SRC
		${BasicUsageEnvironment}
		${UsageEnvironment}
		${groupsock}
		${liveMedia}
		)

set(VIDEO_SRC
		${LIVE_SRC}
		native-lib.cpp
		)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.




find_library(VIDEO_LIB
        android
        cpufeatures
        log
        EGL
        GLESv2
        z
        )


add_library(
             native-lib
             SHARED
             ${VIDEO_SRC}
             )
target_include_directories(native-lib PRIVATE
        ${Live_inc}
		)
# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
                       native-lib

                       # Links the target library to the log library
                       # included in the NDK.
                       ${VIDEO_LIB}
                       )