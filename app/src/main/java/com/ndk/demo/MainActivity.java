package com.ndk.demo;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("hello");
    }

    private JniTest jniTest;
    private CToJava cToJava;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

         jniTest = new JniTest() ;
          cToJava = new CToJava();

        // Example of a call to a native method
        TextView tv = (TextView) findViewById(R.id.sample_text);
        tv.setText(sayHello());
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();

    public native String sayHello() ;

    public void add(View view) {
        Log.i("@@",""+jniTest.add(99,1)) ;
    }

    public void string(View view) {
        Log.i("@@",""+jniTest.sayHello("i am from java")) ;
    }

    public void array(View view) {
        int [] a = {1,2,3,4,5,6};
        int [] aa =jniTest.increaseArrayElem(a);
        for(int i=0;i<aa.length;i++){
            Log.i("@@",""+aa[i]) ;
        }

    }

    public void checkPsw(View view) {
        Log.i("@@",""+jniTest.checkPsw("123456")) ;
    }

    public void callBackJavaToAdd(View view) {
        cToJava.callbackJavaAdd();
    }
}
