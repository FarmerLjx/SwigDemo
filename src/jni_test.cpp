/*
* @Author: Jiaxiang Li
* @Date:   2016-10-31 00:58:21
* @Last Modified by:   peenut
* @Last Modified time: 2016-11-03 00:53:45
*/

#include "jni_test.h"
#include "other.h"

JniTest::JniTest(double *data, int len)
{
    this->p_nodes_ = init(data, len); // Call init function in other.h
}

JniTest::~JniTest()
{
    if (this->p_nodes_ != NULL) {
        memory_free(this->p_nodes_);
    }
}

double JniTest::getVal(int index)
{
    return get_value(this->p_nodes_, index);
}

int JniTest::jniTestAlgo(int p1)
{
    int res = algo(this->p_nodes_); // Call algo function in other.h
    return res + p1;
}
