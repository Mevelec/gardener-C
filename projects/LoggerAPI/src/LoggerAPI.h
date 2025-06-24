#pragma once

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#include "LoggerAPIExport.h"

namespace LoggerAPI
{
	class LOGGER_API Logger
	{
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }


	};
}

// Core log macros
#define CORE_TRACE(...) ::LoggerAPI::Logger::GetCoreLogger()->trace(__VA_ARGS__)
#define CORE_INFO(...)  ::LoggerAPI::Logger::GetCoreLogger()->info(__VA_ARGS__)
#define CORE_WARN(...)  ::LoggerAPI::Logger::GetCoreLogger()->warn(__VA_ARGS__)
#define CORE_ERROR(...) ::LoggerAPI::Logger::GetCoreLogger()->error(__VA_ARGS__)
#define CORE_FATAL(...) ::LoggerAPI::Logger::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define TRACE(...) ::LoggerAPI::Logger::GetClientLogger()->trace(__VA_ARGS__)
#define INFO(...)  ::LoggerAPI::Logger::GetClientLogger()->info(__VA_ARGS__)
#define WARN(...)  ::LoggerAPI::Logger::GetClientLogger()->warn(__VA_ARGS__)
#define ERROR(...) ::LoggerAPI::Logger::GetClientLogger()->error(__VA_ARGS__)
#define FATAL(...) ::LoggerAPI::Logger::GetClientLogger()->critical(__VA_ARGS__)