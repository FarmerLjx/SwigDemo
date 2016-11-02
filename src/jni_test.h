/*
* @Author: Jiaxiang Li
* @Date:   2016-10-31 00:22:10
* @Last Modified by:   Jiaxiang Li
* @Last Modified time: 2016-10-31 00:38:44
*/

#ifndef FARMERLJX_CODEC_JNITEST_H_
#define FARMERLJX_CODEC_JNITEST_H_

#ifndef SWIG
#include "other.h"
#endif

class JniTest {
public:
    /* To wrap structor*/
    JniTest(double *data, int len);

#ifndef SWIG
    ~JniTest();
#endif

    /* Some functions to wrap*/
    double getVal(int index);
    int jniTestAlgo(int p1);

#ifndef SWIG

private:
    TestNode* p_nodes_;

#endif
};

#endif // !FARMERLJX_CODEC_JNITEST_H_
