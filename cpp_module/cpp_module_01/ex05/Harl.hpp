#ifndef IOSTRAM
#define	IOSTRAM

#include <iostream>

#endif

#ifndef HARL_HPP
#define HARL_HPP

typedef enum status {
	debug = 0,
	info,
	warning,
	error,
} e_status;

class Harl {

	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
		// void	(*functionPoint[4])(void);

	public:
		Harl();
		~Harl();
		void	complain(std::string level);
		void	set(void);

};

#endif