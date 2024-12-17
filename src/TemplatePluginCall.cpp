
#include <TemplatePluginCall.h>
#include "TemplatePlugin.h"

TemplatePlugin *pPlugin = nullptr;

PluginHandle pluginHandle()
{
    if (!pPlugin)
    {
        pPlugin = new TemplatePlugin;
    }
    return PluginHandle(pPlugin);
}

PSTR pluginName()
{
    return pPlugin ? pPlugin->pluginName().c_str() : nullptr;
}

PSTR pluginVersion()
{
    return pPlugin ? pPlugin->pluginVersion().c_str() : nullptr;
}

void pluginDeinit()
{
    if (pPlugin)
    {
        delete pPlugin;
        pPlugin = nullptr;
    }
}

int pluginID()
{
    return pPlugin ? pPlugin->pluginID() : -1;
}

PSTR pluginDescription()
{
    return pPlugin ? pPlugin->pluginDescription().c_str() : nullptr;
}
