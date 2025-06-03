workspace "gardener"
	architecture "x64"
	startproject "gardener"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	flags
	{
		"MultiProcessorCompile"
	}

	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/%{prj.name}"
    project_dir = "./projects/" .. "%{prj.name}"

		filter "configurations:Debug"
		defines "gardener"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "gardener"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "gardener"
		runtime "Release"
		optimize "on"

group "Dependencies"
	include "./projects/vendor/WiringPi/wiringPi" -- copy GLFW premake config
	
group ""

project "gardener"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	location "./projects/%{prj.name}"
	targetdir ("bin/" .. outputdir)
	objdir ("bin-intermediates/" .. outputdir)

	files
	{
		project_dir .. "/src/**.h",
		project_dir .. "/src/**.cpp",
	}

	includedirs
	{
		project_dir .. "/src",
		 "./projects/vendor/spdlog/include",
		 "./projects/vendor/WiringPi/wiringPi"
	}