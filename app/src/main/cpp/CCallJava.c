//
// Created by nhj on 2018/6/21.
//

#include "jni.h"
#include<android/log.h>

#define TAG "myDemo-jni" // 这个是自定义的LOG的标识
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,TAG ,__VA_ARGS__) // 定义LOGD类型
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,TAG ,__VA_ARGS__) // 定义LOGI类型
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN,TAG ,__VA_ARGS__) // 定义LOGW类型
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,TAG ,__VA_ARGS__) // 定义LOGE类型
#define LOGF(...) __android_log_print(ANDROID_LOG_FATAL,TAG ,__VA_ARGS__) // 定义LOGF类型

JNIEXPORT void JNICALL Java_com_ndk_demo_CToJava_callbackJavaAdd
        (JNIEnv *env, jobject instance){
    const char* s = "com/ndk/demo/CToJava" ;

    jclass jclazz = (*env)->FindClass(env,s) ;

//    jobject instace_obj = (*env)->AllocObject(env,jclazz) ;
    jmethodID method = (*env)->GetMethodID(env,jclazz,"add","(II)I");
//
    LOGD("i am from s%","c");
    (*env)->CallIntMethod(env,instance,method,1,11) ;

}

JNIEXPORT void JNICALL
Java_com_ndk_demo_CToJava_callbackJavaStr(JNIEnv *env, jobject instance) {

    // TODO
    jclass jclazz = (*env)->FindClass(env,"com/ndk/demo/CToJava") ;
    //第一个字符串为方法名，第二个为方法签名 通过指令 javap -s 全类名 class
    jmethodID method = (*env)->GetMethodID(env,jclazz,"add","(Ljava/lang/String;)V");
     (*env)->CallStaticVoidMethod(env,jclazz,method);
}



