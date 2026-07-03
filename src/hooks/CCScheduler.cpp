#include <Geode/Geode.hpp>

#include "bot/bot.hpp"
#include "bot/updater.hpp"

using namespace geode::prelude;

#include <Geode/modify/CCScheduler.hpp>

struct SLCCScheduler : Modify<SLCCScheduler, CCScheduler> {
    void callOriginalUpdate(float dt) {
        CCScheduler::update(dt);
    }

    void update(float dt) override {
        const auto bot = Bot::get();
        if (bot->updater().m_onlyRefresh || !bot->isEnabled()) {
            CCScheduler::update(dt);  // only update at the cocos level
            return;
        }

        bot->updater().runUpdates(
            [this](float dt) { this->callOriginalUpdate(dt); }, dt, false);
    }
};
