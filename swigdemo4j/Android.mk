# File: Android.mk
MY_LOCAL_PATH := $(call my-dir)
LOCAL_PATH := $(MY_LOCAL_PATH)

include $(CLEAR_VARS)

LOCAL_MODULE    := swigdemo4j
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../src
LOCAL_SRC_FILES := jnidemo_wrap.cpp ../src/jni_test.cpp ../src/other.c
LOCAL_LDLIBS    += -llog

include $(BUILD_SHARED_LIBRARY)
