#include <jni.h>
#include <string>

extern "C"
JNIEXPORT jstring
JNICALL
Java_com_ndk_demo_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
//    .NewStringUTF(hello.c_str());
    return (*env).NewStringUTF(hello.c_str());
}



