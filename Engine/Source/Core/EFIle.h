#pragma once
#include <filesystem>
#include<string>


namespace File
{
	std::string GetFilePath();

	bool SetFilePath(const std::string& filepath);
}