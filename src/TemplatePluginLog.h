#pragma once
#include <spdlog/spdlog.h>
#include <spdlog/common.h>

const std::string templatePluginName = "Template";

#define TEMPLATE_LOG_TRACE(...)    SPDLOG_LOGGER_CALL(spdlog::get(templatePluginName), spdlog::level::trace, __VA_ARGS__)
#define TEMPLATE_LOG_DEBUG(...)    SPDLOG_LOGGER_CALL(spdlog::get(templatePluginName), spdlog::level::debug, __VA_ARGS__)
#define TEMPLATE_LOG_INFO(...)     SPDLOG_LOGGER_CALL(spdlog::get(templatePluginName), spdlog::level::info, __VA_ARGS__)
#define TEMPLATE_LOG_WARN(...)     SPDLOG_LOGGER_CALL(spdlog::get(templatePluginName), spdlog::level::warn, __VA_ARGS__)
#define TEMPLATE_LOG_ERROR(...)    SPDLOG_LOGGER_CALL(spdlog::get(templatePluginName), spdlog::level::err, __VA_ARGS__)
#define TEMPLATE_LOG_CRITICAL(...) SPDLOG_LOGGER_CALL(spdlog::get(templatePluginName), spdlog::level::critical, __VA_ARGS__)
#define TEMPLATE_LOG_OFF(...)      SPDLOG_LOGGER_CALL(spdlog::get(templatePluginName), spdlog::level::off, __VA_ARGS__)
