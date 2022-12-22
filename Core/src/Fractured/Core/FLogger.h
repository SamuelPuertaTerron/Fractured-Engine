#pragma once

#include "frpch.h"

namespace FracturedInternal
{
	class FLogger
	{
	public:
		template <typename... Args>
		static void Log(const std::string& message, Args&&... args)
		{
			SetTextColour(15);
			LogInternal(message, args...);
			SetTextColour(15);
		}
		template <typename... Args>
		static void LogError(const std::string& message, Args&&... args)
		{
			SetTextColour(12);
			LogInternal(message, args...);
			SetTextColour(15);
		}
		template <typename... Args>
		static void LogInfo(const std::string& message, Args&&... args)
		{
			SetTextColour(10);
			LogInternal(message, args...);
			SetTextColour(15);
		}
	private:
		template <typename... Args>
		static void LogInternal(const std::string& message, Args&&... args)
		{
			auto tm = std::chrono::system_clock::now();
			std::cout << "[" << std::format("{:%X %Z}", tm) << "] : " << message << " ";
			((std::cout << args), ...);
			std::cout << "" << std::endl;
		}
		static void SetTextColour(int colour) //Set's the correct colours for logging
		{
			HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, colour);
		}
	};

#define FR_LOG(...)		  ::FracturedInternal::FLogger::Log(__VA_ARGS__)
#define FR_LOG_INFO(...)  ::FracturedInternal::FLogger::LogInfo(__VA_ARGS__)
#define FR_LOG_ERROR(...) ::FracturedInternal::FLogger::LogError(__VA_ARGS__)
}


