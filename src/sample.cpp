/*
* @Author: Jiaxiang Li
* @Date:   2016-11-02 09:54:41
* @Last Modified by:   Jiaxiang Li
* @Last Modified time: 2016-11-02 10:46:15
*/

#include <iostream>
#include "jni_test.h"

int main(){
    double data[] = {-3.4765625,-1.5488281,-0.06298828,0.71728516,0.9086914,0.5786133,-0.1875,-1.2617188,-2.6484375};

    int dataLen = sizeof(data)/sizeof(data[0]);
    JniTest *jniTest = new JniTest(data, dataLen);
    int index = 8;
    double val = jniTest->getVal(index);
    printf("Value No.%d = %.7lf\n", index+1, val);
    // result should be index + 5 + [length of data]
    printf("Test result is %d = %d + %d + %d\n", jniTest->jniTestAlgo(index), index, 5, dataLen);

    return 0;
}
