#include <mallow/mallow.hpp>

#include "Library/Controller/InputFunction.h"
#include "ModOptions.h"
#include "Scene/StageScene.h"
#include "Library/Camera/CameraDirector.h"

using mallow::log::logLine;

bool freeze = false;

struct ScenePlayHook : public mallow::hook::Trampoline<ScenePlayHook> {
    static void Callback(StageScene* thisPtr) {
        if (al::isPadTriggerLeftUp(-1)) {
            freeze = !freeze;
        }
        Orig(thisPtr);
    }
};

struct StopJudgeHook : public mallow::hook::Trampoline<StopJudgeHook> {
    static bool Callback(al::CameraStopJudge* thisPtr) {
        if (freeze)
            return freeze;
        return Orig(thisPtr);
    }
};

extern "C" void userMain() {
    exl::hook::Initialize();
    mallow::init::installHooks();
    
    ScenePlayHook::InstallAtSymbol("_ZN10StageScene7exePlayEv");
    StopJudgeHook::InstallAtSymbol("_ZNK2al15CameraStopJudge6isStopEv");
}
