#include <iostream>
#include <ctime>
#include "Span.hpp"

int main()
{
	{
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "< --- print All --- >" << std::endl;
		sp.printAll();

		std::cout << "< --- short span test --- >" << std::endl;
		std::cout << sp.shortestSpan() << std::endl;

		std::cout << "< --- long span test --- >" << std::endl;
		std::cout << sp.longestSpan() << std::endl;

		std::cout << "< --- Full Span --- >" << std::endl;
		try
		{
			sp.addNumber(1);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		sp.printAll();

		std::cout << "< --- Copy construct test --- >" << std::endl;
		Span span_copy_construct(sp);
		span_copy_construct.printAll();

		std::cout << "< --- operator= can test --- >" << std::endl;
		Span span_sms1;
		span_sms1 = sp;
		span_sms1.printAll();
	}
	
	{
		std::cout << "\n\n< --- No Span Test --- >" << std::endl;
		Span sp = Span(1);
		std::cout << "< --- No element --- >" << std::endl;
		try
		{
			std::cout << sp.shortestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << "< --- one element --- >" << std::endl;
		sp.addNumber(6);
		try
		{
			std::cout << sp.shortestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	{
		std::cout << "\n\n< --- big numbers --- >" << std::endl;
		Span big_span(10000);
		std::srand(std::time(NULL));
		for (int i = 0; i < 10000; i++)
			big_span.addNumber(static_cast<int>(std::rand()) % 100000);
		// big_span.printAll();
		std::cout << "long : " << big_span.longestSpan() 
		<< "\nshort : " << big_span.shortestSpan() << std::endl;
	}

	{
		std::cout << "\n\n< --- range fill --- >" << std::endl;
		Span big_fill_span(100);
		big_fill_span.fillRange(0, 9, 1);
		big_fill_span.fillRange(10, 19, 2);
		// big_fill_span.fillRange(5, 14, 3);
		// big_fill_span.fillRange(0, 0, 5);
		// big_fill_span.fillRange(-1, 0, 5);
		// big_fill_span.fillRange(0, 100, 5);
		big_fill_span.printAll();
	}
	{
		std::cout << "\n< --- Wrong range error --- >" << std::endl;
		Span big_fill_span(10);
		try
		{
			big_fill_span.fillRange(0, 10, 1);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		big_fill_span.printAll();
	}

	return (0);
}