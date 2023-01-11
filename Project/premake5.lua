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
		"src/**.cpp",
		"vendor/glm/glm/**.hpp",
		"vendor/glm/glm/**.inl",
	}

	includedirs
	{
		"../Core/src",
		"../Core/vendor",
		"../Core/%{IncludeDir.GLFW}",
		"../Core/%{IncludeDir.GLAD}",
		"../Core/%{IncludeDir.glm}",
		"../Core/%{IncludeDir.ImGui}",
		"../Core/%{IncludeDir.Box2D}"
	}

	links
	{
		"Fractured Engine"
	}

	resources = os.mkdir("Resources")

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"FR_PLATFORM_WINDOWS"
		}

		postbuildcommands 
		{
			"{COPYDIR} Resources %{cfg.targetdir}/Resources"
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
		kind "WindowedApp"
		runtime "Release"
        optimize "on"