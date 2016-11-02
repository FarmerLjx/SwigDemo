#!/bin/bash

# @Author: Jiaxiang Li
# @Date:   2016-11-02 11:57:10
# @Last Modified by:   Jiaxiang Li
# @Last Modified time: 2016-11-02 15:12:08

# Need to change PROJECT_DIR,PACKAGE_NAME,OUT_DIR

PROJECT_DIR="/home/mobvoi/AndroidStudioProjects/FromGithub/JniDemo/app/src/main"
PACKAGE_NAME="cc.hutunotes.farmerljx.jnidemo.jni"
PACKAGE_PATH=`echo $PACKAGE_NAME |  sed 's/\./\//g'`
OUT_DIR=${PROJECT_DIR}"/java/"${PACKAGE_PATH}
JNI_LIBS_DIR=${PROJECT_DIR}"/jniLibs/"

if [ ! -d $OUT_DIR ]; then
    echo "Creating folder : "${OUT_DIR}
    mkdir -p $OUT_DIR
fi

if [ ! -d $JNI_LIBS_DIR ]; then
    echo "Creating folder : "${JNI_LIBS_DIR}
    mkdir -p $JNI_LIBS_DIR
fi

# swig
swig -c++ -java -package $PACKAGE_NAME -outdir $OUT_DIR -o jnidemo_wrap.cpp jnidemo.i

# ndk-build
ndk-build NDK_OUT=obj NDK_LIBS_OUT=libs NDK_PROJECT_PATH=. NDK_APPLICATION_MK=Application.mk APP_BUILD_SCRIPT=./Android.mk

# copy .so to jniLibs
cp -frp libs/* $JNI_LIBS_DIR
