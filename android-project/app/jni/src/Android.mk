LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := main

SDL_PATH := ../SDL

LOCAL_C_INCLUDES := $(LOCAL_PATH)/$(SDL_PATH)/include

# Add your application source files here...
LOCAL_SRC_FILES := ../../../../Source/Main.cpp \
                   ../../../../Source/Game.cpp \
                   ../../../../Source/Renderer.cpp \
                   ../../../../Source/InputManager.cpp \
                   ../../../../Source/Board.cpp \
                   ../../../../Source/Background.cpp \
                   ../../../../Source/Bird.cpp \
                   ../../../../Source/Column.cpp \
                   ../../../../Source/Sound.cpp \

LOCAL_SHARED_LIBRARIES := SDL2 SDL2_image SDL2_mixer

LOCAL_LDLIBS := -lGLESv1_CM -lGLESv2 -lOpenSLES -llog -landroid

include $(BUILD_SHARED_LIBRARY)
