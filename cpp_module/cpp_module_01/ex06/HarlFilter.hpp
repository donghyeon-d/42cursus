#include <iostream>

#ifndef HARLFILTER_HPP
#define HARLFILTER_HPP

class HarlFilter {

	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);

	public:
		HarlFilter();
		~HarlFilter();
		void	complain(std::string level);

};

#endif