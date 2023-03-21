#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <stack>

// float ftStof(std::string str) {
// 	std::stringstream ssFloat(str);
// 	float value(0);
// 	ssFloat >> value;
// 	return value;
// }

// int main() {
// 	std::string s1("1d");
// 	std::string s2("-1d");
// 	std::string s3("1.1d1");
// 	std::string s4("-1.d11");

// 	float f1(ftStof(s1));
// 	float f2(ftStof(s2));
// 	float f3(ftStof(s3));
// 	float f4(ftStof(s4));

// 	std::cout << s1 << " : " << f1 << std::endl;
// 	std::cout << s2 << " : " << f2 << std::endl;
// 	std::cout << s3 << " : " << f3 << std::endl;
// 	std::cout << s4 << " : " << f4 << std::endl;
// }

int main () {
	// std::stack<int> _stack;

	// if (!_stack.empty())
	// 	int a = _stack.top();

	int a = 3;
	int b = a / 0;
	std::cout << a;
}