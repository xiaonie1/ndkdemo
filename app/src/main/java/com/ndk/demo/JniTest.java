package com.ndk.demo;

/**
 * Created by nhj on 2018/6/21.
 */

public class JniTest {
    /**
     * 在c中计算两个数的和
     * @param x
     * @param y
     * @return
     */
    public native int add(int x,int y) ;

    /**
     * 在c中拼接一个字符串并返回
     * @param str
     * @return
     */
    public native String sayHello(String str) ;

    public native int [] increaseArrayElem(int [] array);

    public native int checkPsw(String psw) ;
}
