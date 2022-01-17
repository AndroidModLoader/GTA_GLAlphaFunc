LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_CPP_EXTENSION := .cpp .cc
LOCAL_MODULE    := glalphafunc
LOCAL_SRC_FILES := main.cpp
LOCAL_CFLAGS += -O2 -mfloat-abi=softfp -DNDEBUG -std=c++17
LOCAL_C_INCLUDES += ./include
LOCAL_LDLIBS += -llog $(LOCAL_PATH)/libGLESv2.so # Put your GLESv2 library here because NDK's built-in has no GLEXT functions :|
include $(BUILD_SHARED_LIBRARY)