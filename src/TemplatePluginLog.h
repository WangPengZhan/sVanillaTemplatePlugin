#pragma once
#include <spdlog/spdlog.h>
#include <spdlog/common.h>

const std::string templatePluginName = "Template";

#define TEMPLATE_LOG_TRACE(...)    SPDLOG_LOGGER_TRACE(spdlog::get(templatePluginName), __VA_ARGS__)
#define TEMPLATE_LOG_DEBUG(...)    SPDLOG_LOGGER_DEBUG(spdlog::get(templatePluginName), __VA_ARGS__)
#define TEMPLATE_LOG_INFO(...)     SPDLOG_LOGGER_INFO(spdlog::get(templatePluginName), __VA_ARGS__)
#define TEMPLATE_LOG_WARN(...)     SPDLOG_LOGGER_WARN(spdlog::get(templatePluginName), __VA_ARGS__)
#define TEMPLATE_LOG_ERROR(...)    SPDLOG_LOGGER_ERROR(spdlog::get(templatePluginName), __VA_ARGS__)
#define TEMPLATE_LOG_CRITICAL(...) SPDLOG_LOGGER_CRITICAL(spdlog::get(templatePluginName), __VA_ARGS__)
#define TEMPLATE_LOG_OFF(...)      SPDLOG_LOGGER_OFF(spdlog::get(templatePluginName), __VA_ARGS__)
