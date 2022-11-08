#include <sstream>
#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]\nI love having exra bacon for my 7XL-double-chees-triple-pickle-special-ketchup burger.\nI really do!" << std::endl;
}
void	Harl::info(void)
{
	std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money.\nYou didn't put enough bacon in my buger!\nIf you did, I wouldn't be asking for more!" << std::endl;
}
void	Harl::warning(void)
{
	std::cout << "[ WARNING ]\nI t hink I deserve to have some extra bacon for free.\nI've been coming for years whereas you started working here since last month." << std::endl;
}
void	Harl::error(void)
{
	std::cout << "[ ERROR ]\nThis is unacceptable!\nI want to speak to the managet now." << std::endl;
}




void	Harl::complain(std::string level)
{
	void (Harl::*f[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string input[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	int i(0);
	while (level.compare(input[i]) && i < 4)
		i++;
	switch (i)
	{
	case 4:
		std::cout << "Wrong input!" << std::endl;
		break;
	default:
		(this->*f[i])();
		break;
	}
	// (this->*f[i])();
}
