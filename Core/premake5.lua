project "Fractured Engine"
    kind "StaticLib"
    language "C++"
    cppdialect "C++20"
    staticruntime "on"

    targetdir ("../bin/" .. outputdir .. "/%{prj.name}")
	objdir ("../bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "frpch.h"
    pchsource "src/frpch.cpp"

    files
    {
        "src/**.h",
        "src/**.cpp",
        "vendor/stb_image/**.h",
		"vendor/stb_image/**.cpp",
		"vendor/glm/glm/**.hpp",
		"vendor/glm/glm/**.inl",
    }

    includedirs
    {
        "src",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.GLAD}",
        "%{IncludeDir.glm}",
		"%{IncludeDir.stb_image}"
    }

    links
    {
        "GLFW",
        "GLAD"
    }

    filter "system:windows"
        systemversion "latest"

        defines
        {
            "FR_PLATFORM_WINDOWS",
            "GLFW_INCLUDE_NONE"
        }

    filter "configurations:Debug"
        defines
        {
            "FR_DEBUG"
        }
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
        defines
        {
            "FR_RELEASE"
        }
		runtime "Release"
        optimize "On"
        symbols "off"