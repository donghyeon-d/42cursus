#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <exception>

// class easyFindException : public std::exception
// {
// 	public:
// 		const char *what() const throw()
// 		{
// 			return ("can not find");
// 		}
// };

// template <typename T>
// bool easyfind(T container, int element)
// {
// 	try
// 	{
// 		int i(0);
// 		while (container[i] != element)
// 			i++;
// 		return true;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		return false;
// 	}
	

// }

template <typename Iter>
typename Iter::iterator easyfind(Iter &container, int element)
{
	return (std::find(container.begin(), container.end(), element));
}

// template <typename Iter>
// bool easyfind(Iter container, int element)
// {
// 	if (std::find(container.begin(), container.end(), element) == container.end())
// 		return false;
// 	else
// 		return true;
// }

#endif