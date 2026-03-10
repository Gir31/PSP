#include <iostream>
#include <string>

int main()
{
	std::string str;
	std::string explodStr;

	std::cin >> str >> explodStr;

	size_t expSize = explodStr.length();

	while (1)
	{
		size_t nPos = str.find(explodStr);

		if (nPos != std::string::npos) {
			str.erase(str.begin() + nPos, str.begin() + nPos + expSize);
		}
		else {
			std::cout << str << std::endl;
			break;
		}
	}

	

	return 0;
}