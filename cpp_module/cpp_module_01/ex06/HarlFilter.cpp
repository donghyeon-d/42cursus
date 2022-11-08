#include <sstream>
#include "HarlFilter.hpp"

HarlFilter::HarlFilter()
{
}

HarlFilter::~HarlFilter()
{
}

void	HarlFilter::debug(void)
{
	std::cout << "[ DEBUG ]\nI love having exra bacon for my 7XL-double-chees-triple-pickle-special-ketchup burger.\nI really do!\n" << std::endl;
}
void	HarlFilter::info(void)
{
	std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money.\nYou didn't put enough bacon in my buger!\nIf you did, I wouldn't be asking for more!\n" << std::endl;
}
void	HarlFilter::warning(void)
{
	std::cout << "[ WARNING ]\nI t hink I deserve to have some extra bacon for free.\nI've been coming for years whereas you started working here since last month.\n" << std::endl;
}
void	HarlFilter::error(void)
{
	std::cout << "[ ERROR ]\nThis is unacceptable!\nI want to speak to the managet now.\n" << std::endl;
}




void	HarlFilter::complain(std::string level)
{
	void (HarlFilter::*f[4])(void) = {&HarlFilter::debug, &HarlFilter::info, &HarlFilter::warning, &HarlFilter::error};
	std::string input[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	int i(0);
	while (level.compare(input[i]) && i < 4)
		i++;
	switch (i)
	{
	case 4:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		break;
	default:
		for (int j = 0; j + i < 4; j++)
			(this->*f[i + j])();
		break;
	}
	// (this->*f[i])();
}
