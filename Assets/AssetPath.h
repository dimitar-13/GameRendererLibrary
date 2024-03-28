#pragma once
#include"Rendererpch.h"
namespace SpriteRenderer {

	struct AssetPath {
		std::string path = {};
	};
	inline AssetPath currentAssetPath = {};
	//Helper class for asset folder path.
	class AssetPathHelper {
	public:
		static std::string& GetAssetPath()
		{
			if (!currentAssetPath.path.empty())
				return currentAssetPath.path;

			std::filesystem::path current_file(__FILE__);

			currentAssetPath.path = current_file.parent_path().string();
			return currentAssetPath.path;
		}
	};

}