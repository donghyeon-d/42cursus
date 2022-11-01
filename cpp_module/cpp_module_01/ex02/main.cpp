#include <iostream>

int main()
{
	std::string stringVariable ("HI THIS IS BRAIN");
	std::string *stringPTR (&stringVariable);
	std::string &stringREF (stringVariable);

	std::cout << "<----- memory address ----->" << std::endl;
	std::cout << "[%p]stringVariable : " << &stringVariable << std::endl;
	std::cout << "[%p]stringPTR      : " << stringPTR << std::endl;
	std::cout << "[%p]stringREF      : " << &stringREF << std::endl;
	std::cout << std::endl;

	std::cout << "<----- value ----->" << std::endl;
	std::cout << "[%s]stringVariable : " << stringVariable << std::endl;
	std::cout << "[%s]stringPTR      : " << *stringPTR << std::endl;
	std::cout << "[%s]stringREF      : " << stringREF << std::endl;
}