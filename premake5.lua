workspace "Gardener"
	architecture "x64"
	startproject "Gardener"

	configurations {
		"debug",
		"release"
	}

	flags {
		"MultiProcessorCompile"
	}

	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/%{prj.name}"
    project_dir = "./projects/" .. "%{prj.name}"

	filter "configurations:debug"
		defines {"PROFILING", "DEBUG"}
		runtime "Debug"
		symbols "on"

	filter "configurations:release"
		defines {"NDEBUG"}
		runtime "Release"
		optimize "on"

	filter "system:linux"
		pic "On" -- position independent code, often needed for shared libs and Pi

project "Gardener"
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
		"./projects/LoggerAPI/src",
		"./projects/InstrumentorAPI/src",
		"./projects/GPIOInterface/src",
		"./projects/vendor/spdlog/include"
	}

	libdirs {
		"/usr/local/lib",
	}

	links { 
		"LoggerAPI",
		"InstrumentorAPI",
		"GPIOInterface",
		"pigpiod_if2"
	}
	dependson { 
		"LoggerAPI",
		"InstrumentorAPI",
		"GPIOInterface"
	}

project "LoggerAPI"
    kind "SharedLib"
    language "C++"
    cppdialect "C++17"
    location "./projects/LoggerAPI"
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-intermediates/" .. outputdir .. "/%{prj.name}")

    files
	{
		project_dir .. "/src/**.h",
		project_dir .. "/src/**.cpp",
	}

	includedirs
	{
		project_dir .. "/src",
		"./projects/vendor/spdlog/include"
	}

	defines { "LOGGER_EXPORTS" }

project "InstrumentorAPI"
    kind "SharedLib"
    language "C++"
    cppdialect "C++17"
    location "./projects/InstrumentorAPI"
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-intermediates/" .. outputdir .. "/%{prj.name}")

    files
	{
		project_dir .. "/src/**.h",
		project_dir .. "/src/**.cpp",
	}

	includedirs
	{
		project_dir .. "/src",
		"./projects/LoggerAPI/src",
		"./projects/vendor/spdlog/include"
	}

	filter "configurations:debug"
        defines { "INSTRUMENTOR_EXPORTS"}
    filter {}

	links { 
		"LoggerAPI",
	}
	dependson { 
		"LoggerAPI",
	}

project "GPIOInterface"
    kind "SharedLib"
    language "C++"
    cppdialect "C++17"
    location "./projects/GPIOInterface"
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-intermediates/" .. outputdir .. "/%{prj.name}")

    files
	{
		project_dir .. "/src/**.h",
		project_dir .. "/src/**.cpp",
	}

	includedirs
	{
		project_dir .. "/src",
		"./projects/LoggerAPI/src",
		"./projects/vendor/spdlog/include"
	}
	libdirs {
		"/usr/local/lib",
	}
	links { 
		"pigpiod_if2",
		"LoggerAPI",
	}
	dependson { 
		"LoggerAPI",
	}