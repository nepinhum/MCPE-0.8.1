#pragma once
#include <_types.h>
#ifndef ANDROID
#include <AppPlatform_sdl.hpp>

extern AppPlatform_sdl appPlatform;
#else
#include <android/AppPlatform_android23.hpp>
extern bool contextWasLost;
extern jobject mainActivity_ref;
extern struct NinecraftApp* ninecraftApp;
extern AppPlatform_android23 appPlatform;
extern pthread_mutex_t _D6E04480;
extern std::string nativeUtf8Input;
#endif
