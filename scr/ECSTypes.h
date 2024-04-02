#pragma once
#include"iostream"
namespace ECSTypes {
	using Entity = std::uint32_t;
	const Entity MAX_ENTITIES = 5000;
	const std::uint32_t MAX_COMPONENTS = 32;
}