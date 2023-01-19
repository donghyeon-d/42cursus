#ifndef DATA_HPP
#define DATA_HPP
#include <ostream>

class Data 
{
	private:
		int _num;

	public:
		Data();
		Data(const Data &data);
		Data &operator=(const Data &data);
		~Data();
		Data operator++(int x);
		void setNum(int num);
		int getNum() const;
};

std::ostream& operator<<( std::ostream& os, const Data &ref );

#endif