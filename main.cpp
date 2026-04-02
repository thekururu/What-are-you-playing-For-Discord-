#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

class $modify(MyPlayLayer, PlayLayer) {
    bool init(GJGameLevel* level, bool useReplay, bool dontSave) {
        if (!PlayLayer::init(level, useReplay, dontSave)) {
            return false;
        }
        auto webhookURL = Mod::get()->getSettingValue<std::string>("webhook-url");

        if (!webhookURL.empty()) {
            this->sendDiscordWebhook(webhookURL, level->m_levelName);
        }

        return true;
    }

    void sendDiscordWebhook(std::string url, std::string levelName) {
        
        log::info("Enviando nivel {} al webhook: {}", levelName, url);
    }
};
