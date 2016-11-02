/*
* @Author: Jianodesiang Li
* @Date:   2016-10-31 00:42:18
* @Last Modified by:   Jiaxiang Li
* @Last Modified time: 2016-11-02 10:45:26
*/

#include "other.h"

// #define DEBUG
// #define RELEASE

#ifdef DEBUG
// Android log print
#include <android/log.h>

#define TAG "svm4j-jni"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, TAG ,__VA_ARGS__) // 定义LOGD类型
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, TAG ,__VA_ARGS__)  // 定义LOGI类型
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN, TAG ,__VA_ARGS__)  // 定义LOGW类型
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, TAG ,__VA_ARGS__) // 定义LOGE类型
#define LOGF(...) __android_log_print(ANDROID_LOG_FATAL, TAG ,__VA_ARGS__) // 定义LOGF类型

#else // if not debug

#define LOGD(...)
#define LOGI(...)
#define LOGW(...)
#define LOGE(...)
#define LOGF(...)

#endif

TestNode* init(double *data, int len)
{
    if (data == NULL) {
        return NULL;
    }
    TestNode *nodes = NULL;
    nodes = (TestNode *) malloc(len* sizeof(TestNode));

    int i;
    for (i = 0; i < len; ++i) {
        nodes[i].index = i + 1;
        nodes[i].value = data[i];
    }
    gValue = len;

    return nodes;
}

int algo(TestNode *pNodes)
{
    int res = FIVE;
    /* Some algorithm*/


    return gValue + res;
}

double get_value(const TestNode *pNodes, int index)
{
    if (index >= gValue){
        return 0;
    }
    return (pNodes + index)->value;
}

void memory_free(TestNode *pNodes)
{
    int i = 0;
    for(i = 0; i < gValue; ++i) {
        free(pNodes + i);
    }
}
