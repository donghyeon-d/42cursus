#include <iostream>
#include <stack>
#include <deque>
#include <list>
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
		std::stack<int> s(mstack); // std::stack 상속 제대로 받아서 처리해주는 방식 아니면 이게 안됨.
		std::cout << s.size() << std::endl;
		std::cout << s.top() << std::endl;
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
		std::cout << "< --- print all --- >" << std::endl;
		mstack.printAllData();

		std::cout << "< --- copy test --- >" << std::endl;
		MutantStack<int> mstack_copy(mstack);
		mstack_copy.printAllData();
	}
	{
		std::cout << "\n< --- My test --- >" << std::endl;
		std::list<int> mstack;
		mstack.push_front(1);
		mstack.push_front(2);
		mstack.push_front(3);
		mstack.push_front(4);
		mstack.push_front(5);
		std::cout << "top() : " << mstack.front() << std::endl;
		std::cout << "< --- print all --- >" << std::endl;
		for (std::list<int>::iterator itr = mstack.begin(); itr != mstack.end(); itr++)
			std::cout << *itr << std::endl;
		// mstack.printAllData();

		std::cout << "< --- copy test --- >" << std::endl;
		std::list<int> mstack_copy(mstack);
		for (std::list<int>::iterator itr = mstack.begin(); itr != mstack.end(); itr++)
			std::cout << *itr << std::endl;
	}
	return 0;
}
