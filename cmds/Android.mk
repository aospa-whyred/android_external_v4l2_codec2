LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES:= \
        codec2.cpp \

LOCAL_C_INCLUDES += \
        $(TOP)/external/libchrome \
        $(TOP)/external/gtest/include \
        $(TOP)/external/v4l2_codec2/include \
        $(TOP)/external/v4l2_codec2/vda \
        $(TOP)/frameworks/av/media/libstagefright/include \
        $(TOP)/frameworks/native/include \
        $(TOP)/hardware/google/av/codec2/include \
        $(TOP)/hardware/google/av/codec2/vndk/include \

LOCAL_MODULE := v4l2_codec2_testapp
LOCAL_MODULE_TAGS := optional

LOCAL_SHARED_LIBRARIES := libbinder \
                          libchrome \
                          libcutils \
                          libgui \
                          liblog \
                          libmedia \
                          libstagefright \
                          libstagefright_codec2 \
                          libstagefright_foundation \
                          libstagefright_codec2_vndk \
                          libui \
                          libutils \
                          libv4l2_codec2 \
                          libv4l2_codec2_vda \
                          android.hardware.media.bufferpool@1.0 \

# -Wno-unused-parameter is needed for libchrome/base codes
LOCAL_CFLAGS += -Werror -Wall -Wno-unused-parameter
LOCAL_CLANG := true

# define ANDROID_VERSION from PLATFORM_VERSION major number (ex. 7.0.1 -> 7)
ANDROID_VERSION := $(word 1, $(subst ., , $(PLATFORM_VERSION)))

ifeq ($(ANDROID_VERSION),7)  # NYC
LOCAL_C_INCLUDES += $(TOP)/external/v4l2_codec2/vndk/include \

LOCAL_SHARED_LIBRARIES += libv4l2_codec2_vndk \

LOCAL_CFLAGS += -DANDROID_VERSION_NYC
else
LOCAL_SHARED_LIBRARIES += libmediaextractor
endif

include $(BUILD_EXECUTABLE)
