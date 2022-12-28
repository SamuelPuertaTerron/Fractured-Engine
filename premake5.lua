workspace("Fractured Engine")
	configurations { "Debug", "Release" }
	architecture("x64")
	
  	flags
	{
		"MultiProcessorCompile"
	}

  outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

  IncludeDir = {}
  IncludeDir["GLFW"] = "vendor/GLFW/include"
  IncludeDir["GLAD"] = "vendor/GLAD/include"
  IncludeDir["glm"] = "vendor/glm"
  IncludeDir["stb_image"] = "vendor/stb_image"
  
  group "Dependencies"
    include "Core/vendor/GLFW"
	include "Core/vendor/GLAD"
  group ""

	filter "Debug"
		defines { "DEBUG", "_DEBUG" }
		symbols "on"

    filter "Release"
		defines { "NDEBUG" }
		optimize "on"

    include "Core"
	include "Project"