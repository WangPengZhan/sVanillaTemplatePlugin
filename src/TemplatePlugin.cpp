#include "TemplatePlugin.h"
#include "PluginMessage.h"
#include "Download/AbstractDownloader.h"

PluginMessage TemplatePlugin::m_pluginMessage = {
    templateplugin::pluginID,
    templateplugin::name,
    templateplugin::version,
    templateplugin::description,
    templateplugin::domain,
};

const PluginMessage &TemplatePlugin::pluginMessage() const
{
    return m_pluginMessage;
}

const std::vector<uint8_t> &TemplatePlugin::websiteIcon()
{
    return m_empty;
}

bool TemplatePlugin::canParseUrl(const std::string &url)
{
    return false;
}

adapter::VideoView TemplatePlugin::getVideoView(const std::string &url)
{
    return adapter::VideoView();
}

std::shared_ptr<download::FileDownloader> TemplatePlugin::getDownloader(const VideoInfoFull &videoInfo)
{
    return std::shared_ptr<download::FileDownloader>();
}

LoginProxy TemplatePlugin::loginer()
{
    return LoginProxy(m_login);
}
