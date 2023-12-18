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
        "/usr/include", -- GLUT headers are typically in /usr/include
   }

   links
    {
        "GL",
        "GLU",
        "glut" -- Link the GLUT library
    }

    linkoptions { "-Wl,--no-undefined", "-static-libgcc", "-static-libstdc++" }

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