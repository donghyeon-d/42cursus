#ifndef CONVERT_HPP
#define CONVERT_HPP
#include <string>

class Convert
{
    private:
        std::string _literal;
        char    _c;
        int     _i;
        float   _f;
        double  _d;
        bool    _nan;
        bool    _inf;
        bool    _infm;
        bool    _infp;
        bool    _else;
        bool    _i_imp;
        bool    _c_imp;
        void    printChar() const;
        void    printInt() const;
        void    printFloat() const;
        void    printDouble() const;

    public:
        Convert();
        Convert(char *str);
        Convert(Convert const &convert);
        ~Convert();
        Convert &operator=(Convert const &convert);
        void display() const;
};


#endif