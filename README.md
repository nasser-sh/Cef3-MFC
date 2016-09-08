# Cef3-MFC

Cef3-MFC is a simple project that demonstrates how to integrate a Chromium browser into various MFC controls.

## Required tools
1. Visual Studio 2015. All editions work, including Community. 
2. CMake Version 3.1 or greater

## Compiling CEF3 
1. Download the latest CEF3 **Windows 64-bit** build from [cefbuilds.com](https://www.cefbuilds.com/).
2. Create the folder `C:\CEF3\`, and extract the contents of the downloaded archive into it. Once this is done, you should have directories such as `include\` and `libcef_dll\` directly under `C:\CEF3\`.
3. Generate the **VS2015 64-bit** build files with CMake.
4. Open the generated VS2015 solution and hit Build Solution.

For more detailed instructions, visit the CEF3 project [tutorial page](https://bitbucket.org/chromiumembedded/cef/wiki/Tutorial.md).  

## Compiling/Running Cef3-MFC
1. Clone the contents of this repository onto your machine and open the solution in VS2015.
2. Build the solution. (Don't run yet!)
3. Copy the contents of `C:\CEF3\Resources\` to the executable's directory. This applies to both Debug and Release configurations
4. Copy the `.dll` and `.bin` files from `C:\CEF3\$(Configuration)` (Where `$(Configuration)` is either Debug or Release) to the corresponding executable's directory.
5. Run the application.

Steps 3 and 4 may be configured as a Post-Build step if needed.

## License
This code may be redistributed in accordance with the BSD-Style license found in LICENSE.txt, which is located in the same directory as this README file.