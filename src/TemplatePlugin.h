#pragma once
#include <IPlugin.h>

#include <TemplateLogin.h>

class TemplatePlugin : public plugin::IPlugin
{
public:
    const std::string &pluginName() const override;
    const std::string &pluginVersion() const override;
    int pluginID() const override;
    const std::string &pluginDescription() const override;
    AbstractLogin &loginer() override;

private:
    std::string m_name{"template"};
    std::string m_version{"1.0.0"};
    std::string m_description{"this is a template plugin for sVanilla."};
    TemplateLogin login;
};