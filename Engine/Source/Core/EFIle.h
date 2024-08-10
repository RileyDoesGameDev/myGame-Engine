#pragma once
#include <filesystem>
#include<string>


namespace File
{
	std::string GetFilePath();

	bool SetFilePath(const std::string& filepath);
	bool FileExists(const std::string& filepath);
	bool GetFileSize(const std::string& filepath, int& size);

	bool ReadFile(const std::string& filepath, std::string& buffer);
}