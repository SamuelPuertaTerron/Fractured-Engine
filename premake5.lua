workspace("Fractured Engine")
	configurations { "Debug", "Release" }
	architecture("x64")
	startproject "Fractured-Sandbox"

  	flags
	{
		"MultiProcessorCompile"
	}

  outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

  IncludeDir = {}
  IncludeDir["GLFW"] = "vendor/GLFW/include"
  IncludeDir["GLAD"] = "vendor/GLAD/include"
  IncludeDir["ImGui"] = "vendor/imgui"
  IncludeDir["Box2D"] = "vendor/box2d/include"
  IncludeDir["glm"] = "vendor/glm"
  IncludeDir["stb_image"] = "vendor/stb_image"
  
  group "Dependencies"
    include "Core/vendor/GLFW"
	include "Core/vendor/GLAD"
	include "Core/vendor/imgui"
	include "Core/vendor/box2d"
  group ""

	filter "Debug"
		defines { "DEBUG", "_DEBUG" }
		symbols "on"

    filter "Release"
		defines { "NDEBUG" }
		optimize "on"

    include "Core"
	include "Project"