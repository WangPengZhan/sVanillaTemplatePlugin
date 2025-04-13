#include <iostream>

#include <spdlog/spdlog.h>
#include <spdlog/sinks/rotating_file_sink.h>
#include <spdlog/async.h>

#include <TemplatePluginCall.h>

#include "TemplatePlugin.h"
#include "TemplatePluginLog.h"

TemplatePlugin* pPlugin = nullptr;
constexpr int logFileMaxSize = 100 * 1024 * 1024;  // 20M

void initDir(const char* dir)
{
    TemplatePlugin::setDir(dir);
    try
    {
        if (!spdlog::get(templatePluginName))
        {
            spdlog::rotating_logger_mt<spdlog::async_factory>(templatePluginName, std::string(dir) + "log/" + templatePluginName + ".log", logFileMaxSize, 100);
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
