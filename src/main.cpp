#if defined(__clang__)
#pragma clang diagnostic ignored "-Wdollar-in-identifier-extension"
#endif

#include <Geode/Geode.hpp>
#include <Geode/modify/CCScheduler.hpp>

using namespace geode::prelude;

#include "bot/bot.hpp"

$on_mod(Loaded) { Bot::get()->initialize(); }
