#pragma once
#include <LoginApi.h>
#include <BaseVideoView.h>

class TemplateLogin : public AbstractLoginApi
{
public:
    // thread-safe
    LoginStatus getLoginStatus() override;
    bool getScanContext(std::string& content) override;
    void loginSuccess() override;

    bool supportsLogin() const override;
    std::string cookies() const override;
    void setCookies(std::string cookies) override;
    bool refreshCookies(std::string cookies) override;

    std::string domain() const override;

    UserInfo getUserInfo(std::string dir) override;
    bool isLoggedIn() const override;
    bool logout() override;
    std::vector<adapter::BaseVideoView> history() override;

    // resource
    const LoginResource& allResources() const override;
    const std::vector<uint8_t>& resource(ResourceIndex index) const override;

    // type
    int pluginId() const override;
};
