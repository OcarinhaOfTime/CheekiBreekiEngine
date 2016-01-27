#include <Core\IOUtils.h>
#include <stdio.h>
#include <string>
#include <fstream>

using std::string;
using std::ifstream;
using std::cout;
using std::endl;

namespace CheekiBreekiEngine {
	std::string IOUtils::readFile(const char * filePath) {
		ifstream input(filePath);
		if (!input.good()) {
			cout << "File path not found: " << filePath << endl;
			return "";
		}
		std::string ret;
		ret = std::string(std::istreambuf_iterator<char>(input),
			std::istreambuf_iterator<char>());

		return ret;
	}
}