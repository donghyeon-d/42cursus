#include <iostream>
#include <sstream>
#include <climits>
#include <cmath>
#include "Convert.hpp"

Convert::~Convert()
{}

Convert::Convert()
: _nan(false), _inf(false), _infm(false), _infp(false), _else(false)
{}

Convert::Convert(char *str)
: _nan(false), _inf(false), _infm(false), _infp(false), _else(false)
{
    _literal = static_cast<std::string>(str);
    if (_literal.compare("nan") == 0)
        _nan = true;
    else if (_literal.compare("inf") == 0)
        _inf = true;
    else if (_literal.compare("-inf") == 0)
        _infm = true;
    else if (_literal.compare("+inf") == 0)
        _infp = true;
    else
    {
        if (_literal.length() != 1 && _literal[_literal.length() - 1] == 'f')
            _literal[_literal.length() - 1] = '\0';
        std::stringstream ssFloat(_literal);
        if (_literal.length() == 1 && !std::isdigit(str[0]))
        {
            _c = str[0];
            _i = static_cast<long long>(_c);
            _f = static_cast<float>(_c);
            _d = static_cast<double>(_c);
        }
        else if (ssFloat >> _d)
        {
            _c = static_cast<char>(_d);
            _i = static_cast<long long>(_d);
            _f = static_cast<float>(_d);
        }
        else
            _else = true;
    }
}

Convert::Convert(Convert const &convert)
{
    *this = convert;
}

Convert &Convert::operator=(Convert const &convert)
{
    _literal = convert._literal;
    _c = convert._c;
    _i = convert._i;
    _d = convert._d;
    _nan = convert._nan;
    _inf = convert._inf;
    _infm = convert._infm;
    _infp = convert._infp;
    _else = convert._else;
    return (*this);
}

void    Convert::printChar() const
{
    if (_else || _nan || _inf || _infm || _infp)
        std::cout << "char: impossible" << std::endl;
    else if (std::isprint(_c))
        std::cout << "char: '" << _c << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
}

void    Convert::printInt() const
{
    if (_else || _nan || _inf || _infm || _infp || _i > INT_MAX || _i < INT_MIN)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << _i << std::endl;
}

void    Convert::printFloat() const
{
    if (_else)
        std::cout << "float: impossible" << std::endl;
    else if (_nan || _inf || _infm || _infp)
        std::cout << "float: " << _literal << "f" << std::endl;
    else if (_f - _i == 0)
        std::cout << "float: " << _f << ".0f" << std::endl;
    else
        std::cout << "float: " << _f << "f" << std::endl;
}

void    Convert::printDouble() const
{
    if (_else)
        std::cout << "double: impossible" << std::endl;
    else if (_nan || _inf || _infm || _infp)
        std::cout << "double: " << _literal << std::endl;
    else if (_d - _i == 0)
        std::cout << "double: " << _d << ".0" << std::endl;
    else
        std::cout << "double: " << _d << std::endl;
}

void Convert::display() const
{
    printChar();
    printInt();
    printFloat();
    printDouble();
}
