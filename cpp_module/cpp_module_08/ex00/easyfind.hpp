#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <exception>

template <typename Iter>
typename Iter::iterator easyfind(Iter &container, int element)
{
	return (std::find(container.begin(), container.end(), element));
}

#endif
