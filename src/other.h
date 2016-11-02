/*
* @Author: Jianodesiang Li
* @Date:   2016-10-31 00:32:18
* @Last Modified by:   Jiaxiang Li
* @Last Modified time: 2016-10-31 01:37:37
*/

#ifndef FARMERLJX_CODEC_OTHER_H_
#define FARMERLJX_CODEC_OTHER_H_

// Here may be include some other c/c++ standard library
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    int index;
    double value;
}TestNode;

enum {ZERO = 0, ONE, TWO, THREE, FOUR, FIVE};

/* Global variable for readline function*/
static int gValue = ZERO;

/* Here canb be some algorithm*/
TestNode* init(double *data, int len);
int algo(TestNode *pNodes);
double get_value(const TestNode *pNodes, int index);
void memory_free(TestNode *pNodes);

#ifdef __cplusplus
}
#endif

#endif /* GESTURE_CODEC_SIMPLE_SVM_H_ */
