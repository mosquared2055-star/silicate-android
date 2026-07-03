#include <Geode/Geode.hpp>
#include <Geode/binding/ForceBlockGameObject.hpp>
#include <Geode/binding/VideoOptionsLayer.hpp>

#include "../bot/bot.hpp"
#ifdef GEODE_IS_WINDOWS
#include "Geode/cocos/platform/win32/CCEGLView.h"
#include "ui/hook.hpp"
#endif
// #include "../recorder/recorder.hpp"

using namespace geode::prelude;

#include <Geode/modify/ForceBlockGameObject.hpp>
#include <Geode/modify/VideoOptionsLayer.hpp>

struct SLVideoOptionsLayer : Modify<SLVideoOptionsLayer, VideoOptionsLayer> {
    void onApply(cocos2d::CCObject* sender) {
        VideoOptionsLayer::onApply(sender);

        auto size = CCDirector::get()->getWinSizeInPixels();
#ifdef GEODE_IS_WINDOWS
        ImGuiHookCtx::get().handleResize(size.width, size.height);
#endif
    }
};
