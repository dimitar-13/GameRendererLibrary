#include "Log.h"



void SpriteRenderer::Log::Init()
{
}
void SpriteRenderer::Log::info_message(std::string message)
{
	fmt::print(fg(fmt::color::gray),
		"Hello, {}!\n", "world");
}

void SpriteRenderer::Log::error_message(std::string message)
{
	fmt::print(fg(fmt::color::red) | (fmt::emphasis::bold),
		"Hello, {}!\n", "world");

}

void SpriteRenderer::Log::warning_message(std::string message)
{
	fmt::print(fg(fmt::color::yellow),
		"Hello, {}!\n", "world");

}

void SpriteRenderer::Log::fatal_message(std::string message)
{
	std::string formatedMassage = fmt::format("This is a formated message with a number{0} and a string{1}",14,"a string");
	
}
