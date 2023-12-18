project "engine"
   kind "StaticLib"
   language "C++"
   cppdialect "C++17"
   targetdir "bin/%{cfg.buildcfg}"
   staticruntime "off"

   files { "src/**.h", "src/**.cpp", "src/**.hpp", "src/**.c" }

   includedirs
   {
        "src",
        "../vendor/GLEW/glew-2.1.0/include",
        "../vendor/GLFW/glfw-3.3.9.bin.WIN64/include"

   }

   libdirs
   {
       "../vendor/GLEW/glew-2.1.0/lib/Release/x64",
       "../vendor/GLFW/glfw-3.3.9.bin.WIN64/lib-vc2022"
   }

   links
    {
        "glew32s.lib",
        "glfw3.lib",
        "opengl32.lib"
    }


   targetdir ("../bin/" .. OutputDir .. "/%{prj.name}")
   objdir ("../bin/intermediates/" .. OutputDir .. "/%{prj.name}")

   filter "system:windows"
       systemversion "latest"
       defines { }

   filter "configurations:Debug"
       defines { "DEBUG" }
       runtime "Debug"
       symbols "On"

   filter "configurations:Release"
       defines { "RELEASE" }
       runtime "Release"
       optimize "On"
       symbols "On"

   filter "configurations:Dist"
       defines { "DIST" }
       runtime "Release"
       optimize "On"
       symbols "Off"