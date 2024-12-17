#include "TemplateLogin.h"

AbstractLogin::LoginSatus TemplateLogin::getLoginStatus()
{
    return LoginSatus();
}

bool TemplateLogin::getScanContext(std::string &content)
{
    return false;
}

void TemplateLogin::loginSuccess()
{
}

UserInfo TemplateLogin::getUserInfo(std::string dir)
{
    return UserInfo();
}

bool TemplateLogin::isLogin() const
{
    return false;
}

bool TemplateLogin::logout()
{
    return false;
}

std::vector<adapter::BaseVideoView> TemplateLogin::history()
{
    return {};
}

const TemplateLogin::LoginResource &TemplateLogin::allResources() const
{
    return m_emptyArray;
}

const std::vector<uint8_t> &TemplateLogin::resource(ResourceIndex index) const
{
    return m_emptyString;
}

int TemplateLogin::type() const
{
    return 0;
}
