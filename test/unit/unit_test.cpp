#include <gtest/gtest.h>

#include "TemplatePlugin.h"

TEST(TemplatePluginUnitTest, StoresAndReturnsDirectory)
{
    TemplatePlugin::setDir("./temp");
    EXPECT_EQ(TemplatePlugin::getDir(), "./temp");

    TemplatePlugin::setDir("");
    EXPECT_EQ(TemplatePlugin::getDir(), "");
}
