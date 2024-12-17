
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

void pluginDeinit()
{
    if (pPlugin)
    {
        delete pPlugin;
        pPlugin = nullptr;
    }
}
