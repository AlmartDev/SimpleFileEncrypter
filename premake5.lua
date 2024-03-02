workspace "Encrypter" 
    configurations { "Debug", "Release" }
    location "build"
    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"
    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"
    filter "configurations:Dist"
        defines { "NDEBUG" }
        optimize "On"
    filter {}

project "sfe"
    files { "src/**.h", "src/**.cpp" }
    kind "ConsoleApp" -- for now
    language "C++"
    targetdir "bin/%{cfg.buildcfg}"
    includedirs { "src" }
