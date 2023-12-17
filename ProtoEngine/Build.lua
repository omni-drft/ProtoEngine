workspace "ProtoEngine"
   architecture "x64"
   configurations { "Debug", "Release", "Dist" }
   startproject "App"

   filter "system:windows"
      buildoptions { "/EHsc", "/Zc:preprocessor", "/Zc:__cplusplus" }

OutputDir = "%{cfg.buildcfg}"

group "engine"
	include "engine/Build-Core.lua"
group ""

include "sandbox/Build-App.lua"