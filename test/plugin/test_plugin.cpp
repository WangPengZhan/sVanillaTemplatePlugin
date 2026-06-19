#include <gtest/gtest.h>

#include "IPlugin.h"
#include "TemplatePluginCall.h"

namespace
{
struct PluginDeinitGuard
{
    ~PluginDeinitGuard()
    {
        pluginDeinit();
    }
};
}  // namespace

TEST(TemplatePluginArtifactTest, ExposesExpectedPluginMetadata)
{
    auto handle = pluginInit();
    ASSERT_NE(handle, nullptr);
    const PluginDeinitGuard deinit;

    auto plugin = reinterpret_cast<plugin::IPlugin*>(handle);
    const auto& info = plugin->pluginMessage();
    EXPECT_EQ(info.name, "template");
    EXPECT_EQ(info.pluginId, 0);
    EXPECT_EQ(info.domain, "https://sVanilla.app");
    EXPECT_FALSE(plugin->websiteIcon().empty());
}
