#pragma once
#include <IPlugin.h>

#include <TemplateLogin.h>

class TemplatePlugin : public plugin::IPlugin
{
public:
    const PluginMessage& pluginMessage() const override;
    const std::vector<uint8_t>& websiteIcon() override;

    bool canParseUrl(const std::string& url) override;
    adapter::VideoView getVideoView(const std::string& url) override;

    std::shared_ptr<download::FileDownloader> getDownloader(const VideoInfoFull& videoInfo) override;

    LoginProxy loginer() override;

private:
    static PluginMessage m_pluginMessage;
    std::vector<uint8_t> m_empty;
    TemplateLogin m_login;
};
