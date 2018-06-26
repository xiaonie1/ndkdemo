package com.ndk.demo;

import android.util.Log;

/**
 * Created by nhj on 2018/6/21.
 */

public class CToJava {

    public native void callbackJavaAdd();

    public native void callbackJavaStr();

    public int add(int x,int y){
        Log.i("@@",""+(x+y));
        return x+y ;
    }

    public static void printString(String str){
        Log.i("@@",str) ;
    }
}
