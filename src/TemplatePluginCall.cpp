#include <iostream>

#include <spdlog/spdlog.h>
#include <spdlog/sinks/rotating_file_sink.h>
#include <spdlog/async.h>

#include <TemplatePluginCall.h>
#include <LoggerRegisterHelper.h>

#include "TemplatePlugin.h"
#include "TemplatePluginLog.h"

TemplatePlugin* pPlugin = nullptr;

void initDir(const char* dir)
{
    if (!dir)
    {
        return;
    }

    TemplatePlugin::setDir(dir);
    try
    {
        if (!spdlog::get(templatePluginName))
        {
            LoggerHelper::registerLogger(templatePluginName, std::string(dir) + "log/" + templatePluginName + ".log");
        }
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

PluginHandle pluginInit()
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

void deinit()
{
    LoggerHelper::unregisterLogger(templatePluginName);
}
