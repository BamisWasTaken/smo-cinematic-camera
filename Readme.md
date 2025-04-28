# smo-cinematic-camera
(add video here)

SMO Cinematic Camera is an ExeFS mod for Super Mario Odyssey v1.0.0 that allows you to lock the game's camera whenever you want. This allows you to walk around freely with a locked camera angle, which is great for making videos!

This mod is compatible with [LunaKit](https://gamebanana.com/mods/432918), which is recommended for the best experience. You can use either console or Ryujinx.

The repo for this mod was generated from [LynxDev2](https://github.com/LynxDev2)'s [smo-exlaunch-base-clang](https://github.com/LynxDev2/smo-exlaunch-base-clang) template.

## How to use
Simply press `Dpad Up + Dpad Left` to lock the game's camera in it's current angle. At any point, press `Dpad Up + Dpad Left` again to return the camera to normal.

See the video at the top of the README.md for a demo / visual explanation.

## Installation with LunaKit
To use smo-cinematic-camera with LunaKit, do the following:

1. Install LunaKit as per the instructions on [GameBanana](https://gamebanana.com/mods/432918).
2. Rename this mod's `subsdk9` to `subsdk8` and add it next to LunaKit's `subsdk9`
3. Thank [Amethyst-szs](https://github.com/Amethyst-szs) for LunaKit cuz it's amazing 

------------------------------

## Original Exlaunch Clang Base Readme
A base project that allows you to create code mods for smo with exlaunch using clang.
This also includes a custom actor factory to allow adding custom actors.

This project uses [Sanae](https://github.com/Sanae6)'s [marsmallow](https://github.com/odyssey-modding/marshmallow) as a base. Marsmallow allows you to make switch mods using clang.

------------------------------

## Original Marshmallow Readme
A clang based version of [exlaunch](https://github.com/shadowninja108/exlaunch/) with some useful built-in tools.
Supporting clang directly allows better integration with IDEs via clangd and various other clang tools.
This project does not depend on the devkitPro switch toolchain.

## Setup
The only supported host platforms are Windows and Linux.

Dependencies: [CMake](https://cmake.org/)(>=v3.21) and [Ninja](https://ninja-build.org/).  
Both should be available from your package manager, be it `winget`, `apt`, `pacman` or anything else.

To configure the CMake project, run this command. See [definitions](#CMake definition args) for flags to add on.
```shell
cmake -S . -B build -G Ninja --toolchain=cmake/toolchain.cmake
```
And to build using Ninja, simply run:
```shell
ninja -C build
```
Any other target generators are untested and unsupported.

## Logging
As you can see in user/src/main.cpp, there's a few logger destinations available.
The default file location in that file is `sd:/mallow.log`.
If you want network logging, you can make a json file at `sd:/mallow.json` with the contents:
```json
{
  "logger": {
    // The address (hostname or IPv4) where the log server is hosted.
    "ip": "XXX.XXX.XXX.XXX",
    // The default port of choice is 3080.
    "port": 3080,
    // Reconnect when a server could not be found.
    "reconnect": false
  }
}
```
Hosting a log server on Linux (not WSL!) is as easy as running `nc -lk 3080`.
On Windows, there is an included logserver.js which also opens a raw tcp server.
You will need Node.js if you want to use logserver.js, otherwise you should make your own log server.

### CMake definition arguments:
- `-DFTP_IP=XXX.XXX.XXX.XXX`
  - optional, will enable FTP deployment builds if specified 
  - your switch's IP for deployment with the `subsdk9_deploy_ftp` target
- `-DFTP_PORT=5000`, `-DFTP_USERNAME=anonymous`, `-DFTP_PASSWORD=anonymous`
  - optional, uses defaults above
  - your switch's FTP port, username, and password
- `-DFTP_TITLE_ID=0100000000010000`
  - optional, uses defaults above
  - what title id to use when placing deployments into `/atmosphere/contents/FTP_TITLE_ID/exefs/`

## Credits
- [LynxDev2](https://github.com/LynxDev2)
  - [smo-exlaunch-base-clang](https://github.com/LynxDev2/smo-exlaunch-base-clang)
- [shadowninja108](https://github.com/shadowninja108)
  - [exlaunch](https://github.com/shadowninja108/exlaunch)
  - Lots of love <3
- [EngineLessCC](https://github.com/EngineLessCC)
  - [exlaunch-cmake](https://github.com/EngineLessCC/exlaunch-cmake/)
- [CraftyBoss](https://github.com/CraftyBoss)
  - [SMO-Exlaunch-Base](https://github.com/CraftyBoss/SMO-Exlaunch-Base/)
- [Atmosphère contributors](https://github.com/Atmosphere-NX/Atmosphere/graphs/contributors)
  - [Atmosphère](https://github.com/Atmosphere-NX/Atmosphere/)
- [Thog](https://github.com/Thog)
  - [oss-rtld](https://github.com/Thog/oss-rtld)
------------------------------
