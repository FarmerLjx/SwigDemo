package cc.hutunotes.farmerljx.jnidemo;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import cc.hutunotes.farmerljx.jnidemo.jni.JniTest;

public class MainActivity extends AppCompatActivity implements View.OnClickListener{
    private static final String TAG = "JniDemo";

    static {
        System.loadLibrary("swigdemo4j");
    }
    
    
    private TextView mStatusView;
    private Button mRunBtn;
    private JniTest jniTest;
    double[] mData;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        mRunBtn = (Button) findViewById(R.id.run);
        mStatusView = (TextView) findViewById(R.id.status);
        mData = new double[]{-3.4765625,-1.5488281,-0.06298828,0.71728516,0.9086914,0.5786133,-0.1875,-1.2617188,-2.6484375};
        jniTest = new JniTest(mData, mData.length);
        
        mRunBtn.setOnClickListener(this);
    }
    
    @Override
    public void onClick(View v) {
        switch (v.getId()) {
            case R.id.run:
                mRunBtn.setEnabled(false);
                int index = (int) Math.ceil(Math.random() * (mData.length - 1));
                int res = jniTest.jniTestAlgo(index);
                mStatusView.setText("Result is " + res + " = " + index + " + " + mData.length + " + 5");
                mRunBtn.setEnabled(true);
                break;
            default:
                break;
        }
    }
    
    @Override
    public void onDestroy() {
        super.onDestroy();
        /**
         * release memory
         * */
        jniTest.delete();
    }
}
