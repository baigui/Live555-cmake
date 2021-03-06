# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)
add_definitions(
		-DOMIT_REGISTER_HANDLING
		-fexceptions
		-DSOCKLEN_T=socklen_t
		-DNO_SSTREAM=1
		-D_LARGEFILE_SOURCE=1
		-D_FILE_OFFSET_BITS=64
		-DXLOCALE_NOT_USED
		-DOMIT_REGISTER_HANDLING
		-D__arm__
)

file(GLOB groupsock
        live555/groupsock/*.c
        live555/groupsock/*.cpp
        )

set(Live_inc
        live555/UsageEnvironment
        live555/BasicUsageEnvironment
        live555/groupsock
        live555/liveMedia
        live555/UsageEnvironment/include
        live555/BasicUsageEnvironment/include
        live555/groupsock/include
        live555/liveMedia/include
        live555/mediaServer
        )

file(GLOB mediaServer
        live555/mediaServer/*.c
        live555/mediaServer/*.cpp
        )
file(GLOB BasicUsageEnvironment
        live555/BasicUsageEnvironment/*.c
        live555/BasicUsageEnvironment/*.cpp
        )

file(GLOB UsageEnvironment
        live555/UsageEnvironment/*.c
        live555/UsageEnvironment/*.cpp
        )

file(GLOB liveMedia
        live555/liveMedia/*.c
        live555/liveMedia/*.cpp
        )

set(LIVE_SRC
        ${UsageEnvironment}
		${BasicUsageEnvironment}
		${groupsock}
		${liveMedia}
		${mediaServer}
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
                       log
                       )