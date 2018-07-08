#include <jni.h>
#include <string>
#include <thread>
#include <Livesssmediaserver.h>

void start_server1(){
    start_server();
};
extern "C" JNIEXPORT jstring

JNICALL
Java_com_vf_cantimage_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {

    std::thread *thread = new std::thread(start_server1);
    thread->detach();

    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
