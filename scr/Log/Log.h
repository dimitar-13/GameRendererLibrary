#pragma once
#include"Rendererpch.h"


namespace SpriteRenderer {




#ifdef RENDER_DEBUG
#define RENDER_LOG_MESSAGE_INFO(message,...)	fmt::print(fg(fmt::color::white),fmt::format(message,__VA_ARGS__));std::cout<<std::endl
#define RENDER_LOG_MESSAGE_WARNING(message,...) fmt::print(fg(fmt::color::yellow) | (fmt::emphasis::bold),fmt::format(message,__VA_ARGS__));std::cout<<std::endl
#define RENDER_LOG_MESSAGE_ERROR(message,...)	fmt::print(fg(fmt::color::red) | (fmt::emphasis::bold),fmt::format(message,__VA_ARGS__));std::cout<<std::endl
#define RENDER_LOG_MESSAGE_FATAL(message,...)	fmt::print(fg(fmt::color::red) | (fmt::emphasis::bold)|(fmt::emphasis::underline),fmt::format(message,__VA_ARGS__));std::cout<<std::endl
#else
#define RENDER_LOG_MESSAGE_INFO(message,...)	
#define RENDER_LOG_MESSAGE_WARNING(message,...) 
#define RENDER_LOG_MESSAGE_ERROR(message,...)	
#define RENDER_LOG_MESSAGE_FATAL(message,...)	
#endif // DEBUG

}

