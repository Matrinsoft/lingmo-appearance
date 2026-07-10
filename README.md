# lingmo-appearance

Theme and appearance management.

## Capabilities

LingmoTheme (dark/light mode), LingmoColor (23 grayscale + 8 accent colors), LingmoTextStyle (font levels), LingmoAccentColor

## Build

`ash
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Debug
make -j\
`

## CMake Usage

`cmake
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(LingmoSdk REQUIRED COMPONENTS Appearance)
`

## Dependencies

- Qt6 >= 6.5
- C++20
- lingmo-base
