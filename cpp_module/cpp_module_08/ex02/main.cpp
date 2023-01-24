#include <iostream>
#include <stack>
#include <deque>
#include "MutantStack.hpp"



int main()
{
	{
		std::cout << "< --- in subject --- >" << std::endl;
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);
		
		std::cout << mstack.top() << std::endl;
		
		mstack.pop();
		
		std::cout << mstack.size() << std::endl;
		
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;

		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	{
		std::cout << "\n< --- My test --- >" << std::endl;
		MutantStack<int> mstack;
		mstack.push(1);
		mstack.push(2);
		mstack.push(3);
		mstack.push(4);
		mstack.push(5);
		std::cout << "top() : " << mstack.top() << std::endl;
		std::cout << "< --- print all [begin == top] --- >" << std::endl;
		mstack.printAllData();

		std::cout << "< --- copy test --- >" << std::endl;
		MutantStack<int> mstack_copy(mstack);
		mstack_copy.printAllData();
	}
	return 0;
}
