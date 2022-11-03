#include <sstream>
#include "Harl.hpp"

Harl::Harl()
{
	Harl::set();
}

void	Harl::debug(void)
{
	std::cout << "debug" << std::endl;
}
void	Harl::info(void)
{
	std::cout << "info" << std::endl;
}
void	Harl::warning(void)
{
	std::cout << "warning" << std::endl;
}
void	Harl::error(void)
{
	std::cout << "error" << std::endl;
}

void	Harl::set(void)
{
	Harl::functionPoint[0] = Harl::debug;
	Harl::functionPoint[1] = Harl::info;
	Harl::functionPoint[2] = Harl::warning;
	Harl::functionPoint[3] = Harl::error;
}



void	Harl::complain(std::string level)
{
	void (Harl::*functionPointer[4])(void);
	std::stringstream ss(level);
	// e_status status;
	// ss. >> status;
	e_status status(level);
	level.compare(status);
	// void	(Harl::functionPoint[4])(void);
	functionPointer[DEBUG] = Harl::debug;
	functionPointer[INFO] = Harl::info;
	functionPointer[WARNING] = Harl::warning;
	functionPointer[ERROR] = Harl::error;
}