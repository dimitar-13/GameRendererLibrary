#pragma once
#include <fmt/core.h>
#include <fmt/format.h>
#include <fmt/color.h>
#include<string>
namespace SpriteRenderer {


	class Log
	{
	public:
		static void Init();
		static void info_message(std::string message);
		static void error_message(std::string message);
		static void warning_message(std::string message);
		static void fatal_message(std::string message);

		//HANDLE getConsole() { return this->appConsole; }
	};
#define RENDER_LOG_MESSAGE_INFO(...) Log::info_message(__VA_ARGS__)
#define RENDER_LOG_MESSAGE_WARNING(...) Log::error_message(__VA_ARGS__)
#define RENDER_LOG_MESSAGE_ERROR(...) Log::warning_message(__VA_ARGS__)
#define RENDER_LOG_MESSAGE_FATAL(...) fmt::print(fg(fmt::color::red) | (fmt::emphasis::bold)|(fmt::emphasis::underline),__VA_ARGS__);
}

