#pragma once
#include <iostream>

namespace CheekiBreekiEngine {
	class IOUtils {
	public:
		static std::string readFile(const char* filePath);
	};
}