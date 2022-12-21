project "Fractured-Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++20"
	staticruntime "on"

	targetdir ("../bin/" .. outputdir .. "/%{prj.name}")
	objdir ("../bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp"
	}

	includedirs
	{
		"../Core/src",
		"../Core/vendor",
		"../Core/%{IncludeDir.GLFW}",
		"../Core/%{IncludeDir.GLAD}",
	}

	links
	{
		"Fractured Engine"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"FR_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
        optimize "on"