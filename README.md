# sVanilla Plugin Template

This repository is a C++ template for building sVanilla plugins. It provides the basic plugin lifecycle entry points, plugin metadata, placeholder implementations for parsing/downloading/login APIs, logging setup, CMake integration, vcpkg dependency management, and GTest-based plugin and unit tests.

Use this project as the starting point for a new sVanilla site/platform plugin.

## Features

- Builds a shared library plugin target named `TemplatePlugin`
- Uses CMake and C++20
- Uses vcpkg manifest mode for third-party dependencies
- Integrates with `sVanillaPluginCommon`
- Uses `spdlog` for plugin logging
- Provides template implementations for `plugin::IPlugin` and `AbstractLoginApi`
- Includes optional GTest targets for the built plugin artifact and statically linked unit tests
- Includes helper scripts for code formatting and embedding binary resources

## Requirements

- CMake 3.15 or newer
- A C++20 compiler
  - Windows: Visual Studio 2022 / MSVC is recommended
  - Linux/macOS: GCC or Clang
- Git with submodule support
- Python 3, only required for helper scripts
- `clang-format`, only required by the formatting script
- vcpkg from the `ThirdParty/vcpkg` submodule

## Clone

Clone the repository with submodules over HTTPS:

```powershell
git clone --recursive https://github.com/WangPengZhan/sVanillaTemplatePlugin.git
cd sVanillaTemplatePlugin
```

If your GitHub account is configured for SSH, you can use:

```powershell
git clone --recursive git@github.com:WangPengZhan/sVanillaTemplatePlugin.git
cd sVanillaTemplatePlugin
```

If you already cloned the repository without `--recursive`, initialize its submodules from the repository directory:

```powershell
git submodule update --init --recursive
```

## Build

The root `CMakeLists.txt` already points to the bundled vcpkg toolchain:

```text
ThirdParty/vcpkg/scripts/buildsystems/vcpkg.cmake
```

Configure and build:

```powershell
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --config Release
```

For multi-config generators such as Visual Studio, build artifacts are usually placed under:

```text
build/<config>/
```

For single-config generators such as Ninja, build artifacts are usually placed under:

```text
build/
```

The build produces the `TemplatePlugin` shared library. The `spdlog` and `FFmpeg` shared libraries are copied to the same output directory after the plugin is built.

## Tests

Tests are disabled by default. Enable them with `ENABLE_TEST`:

```powershell
cmake -S . -B build -DENABLE_TEST=ON -DCMAKE_BUILD_TYPE=Debug
cmake --build build --config Debug
ctest --test-dir build -C Debug --output-on-failure
```

Enabling tests also builds `TemplatePlugin_static`, which allows unit tests to exercise plugin implementation code without loading the shared library. CTest runs two test executables:

- `TemplatePlugin_plugin_test` links to the built plugin and verifies its exported lifecycle, metadata, and website icon.
- `TemplatePlugin_unit_test` links to `TemplatePlugin_static` and verifies implementation behavior such as plugin-directory storage.

The plugin artifact test validates the default metadata:

- Plugin name: `template`
- Plugin ID: `0`
- Plugin domain: `https://sVanilla.app`

## Project Layout

```text
.
|-- CMakeLists.txt              # Main CMake build script
|-- vcpkg.json                  # vcpkg manifest dependencies
|-- src/
|   |-- PluginMessage.h         # Plugin ID, name, version, description, domain
|   |-- TemplatePlugin.h/.cpp   # plugin::IPlugin template implementation
|   |-- TemplateLogin.h/.cpp    # AbstractLoginApi template implementation
|   |-- TemplatePluginCall.cpp  # Plugin lifecycle entry points
|   `-- TemplatePluginLog.h     # Logger name and logging macros
|-- test/
|   |-- CMakeLists.txt          # Test targets
|   |-- plugin/
|   |   `-- test_plugin.cpp     # Shared plugin artifact tests
|   `-- unit/
|       `-- unit_test.cpp       # Statically linked unit tests
|-- scripts/
|   |-- clang_format_all.py     # Formats src/ and test/
|   `-- file_to_uint8_t.py      # Converts a file to a uint8_t array
`-- ThirdParty/
    |-- spdlog/
    |-- vcpkg/
    `-- sVanillaPluginCommon/
```

## Creating a New Plugin

When using this template for a real plugin, update the template identity and replace the placeholder implementations.

### 1. Update Plugin Metadata

Edit `src/PluginMessage.h`:

```cpp
namespace templateplugin
{
constexpr int pluginID = 0;
constexpr char name[] = "template";
constexpr char version[] = "1.0.0";
constexpr char description[] = "this is a template plugin for sVanilla.";
constexpr char domain[] = "https://sVanilla.app";
}
```

At minimum, replace:

- `pluginID`
- `name`
- `version`
- `description`
- `domain`

### 2. Implement URL Parsing and Video Extraction

Edit `src/TemplatePlugin.cpp`:

- `canParseUrl(const std::string& url)`: return whether this plugin supports the URL
- `getVideoView(const std::string& url)`: parse the URL and return a video view
- `getDownloader(const VideoInfoFull& videoInfo)`: create a downloader for resolved video information
- `websiteIcon()`: return the website icon resource

The URL parsing and download methods currently return `false`, empty objects, or null pointers. The template already includes a default website icon; replace it with the target platform's icon.

### 3. Implement Login Support

If the target platform requires login, edit `src/TemplateLogin.cpp`:

- `supportsLogin()`
- `getLoginStatus()`
- `getScanContext()`
- `loginSuccess()`
- `cookies()`
- `setCookies()`
- `refreshCookies()`
- `domain()`
- `getUserInfo()`
- `isLoggedIn()`
- `logout()`
- `history()`
- `allResources()`
- `resource()`
- `pluginId()`

If the plugin does not need login, keep `supportsLogin()` returning `false`.

### 4. Review Lifecycle and Logging

Plugin lifecycle entry points are implemented in `src/TemplatePluginCall.cpp`:

- `initDir(const char* dir)`: stores the plugin directory and initializes logging
- `pluginInit()`: creates the plugin instance
- `pluginDeinit()`: destroys the plugin instance
- `deinit()`: unregisters the logger

Logging identifiers are defined in `src/TemplatePluginLog.h`. Rename them when creating a real plugin so multiple plugins do not share the same logger name.

### 5. Rename the Template

For a real plugin, rename the project and symbols consistently:

- `project(TemplatePlugin ...)` in `CMakeLists.txt`
- `TestTarget` in `test/CMakeLists.txt`
- `name` in `vcpkg.json`
- C++ class names, namespaces, file names, and logger names where appropriate

## Dependencies

The vcpkg manifest declares:

- `curl`
- `nlohmann-json`
- `openssl`
- `gtest`

The repository also uses bundled third-party submodules:

- `spdlog`
- `sVanillaPluginCommon`

## Formatting

Format project source files with:

```powershell
python scripts/clang_format_all.py
```

The script formats `src/` and `test/`, while skipping `build/` and `ThirdParty/`. It searches for `clang-format` in common install locations on Windows, macOS, and Linux.

Convert a binary resource to a C++ `std::vector<uint8_t>` declaration with:

```powershell
python scripts/file_to_uint8_t.py --filePath path/to/resource --variant resource_name
```

Use `--filePaths`, `--variables`, and `--output` to generate a header containing multiple resources.

## Install

Install the plugin and required runtime library files with:

```powershell
cmake --install build --config Release --prefix out/install
```

Example install output:

```text
out/install/bin/
```

## Notes

- This repository is a template, not a complete production plugin.
- Most plugin and login methods intentionally return empty/default values until you implement the target platform logic.
- Keep `ThirdParty/` as submodules unless you intentionally change dependency management.
- After changing plugin metadata, update or extend `test/plugin/test_plugin.cpp`.
- Add isolated implementation tests under `test/unit/`.

## License

This project is licensed under GPL-3.0. See [LICENSE](LICENSE) for details.
