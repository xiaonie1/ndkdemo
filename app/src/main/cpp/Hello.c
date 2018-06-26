//
// Created by nhj on 2018/6/20.
//
#include <jni.h>
#include "string.h"

jstring Java_com_ndk_demo_MainActivity_sayHello(JNIEnv* env,jobject obj){
    char * c = "fuck you from c" ;
    return  (*env)->NewStringUTF(env,c);
}


JNIEXPORT jint JNICALL
Java_com_ndk_demo_JniTest_add(JNIEnv *env, jobject instance, jint x, jint y) {

    // TODO
    int temp = x+y ;
    return temp ;
}

JNIEXPORT jstring JNICALL
Java_com_ndk_demo_JniTest_sayHello(JNIEnv *env, jobject instance, jstring str_) {
    const char *str = (*env)->GetStringUTFChars(env, str_, 0);
    char* cc  = "add i am from c";
    strcat(str,cc);
    // TODO
    (*env)->ReleaseStringUTFChars(env, str_, str);

    return (*env)->NewStringUTF(env, str);
}

JNIEXPORT jintArray JNICALL
Java_com_ndk_demo_JniTest_increaseArrayElem(JNIEnv *env, jobject instance, jintArray array_) {
    jint *array = (*env)->GetIntArrayElements(env, array_, JNI_FALSE);

    // TODO
    jint length = (*env)->GetArrayLength(env,array_);
    int i=0;
    for(;i<length;i++){
        *(array+i)+=10 ;
    }
    (*env)->ReleaseIntArrayElements(env, array_, array, 0);
    return array_ ;
}

JNIEXPORT jint JNICALL
Java_com_ndk_demo_JniTest_checkPsw(JNIEnv *env, jobject instance, jstring psw_) {
    const char *psw = (*env)->GetStringUTFChars(env, psw_, 0);

    char * real_psw = "123456" ;
    // TODO
    int val = strcmp(psw,real_psw) ;
    (*env)->ReleaseStringUTFChars(env, psw_, psw);
    if(val==0){
        return 200 ;
    }else{
        return 400 ;
    }
}

