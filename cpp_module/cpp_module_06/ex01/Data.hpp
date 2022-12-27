#ifndef DATA_HPP
#define DATA_HPP

class Data
{
    private :
        int _data;

    public :
        Data();
        Data(int data);
        Data(Data const &data);
        ~Data();
        Data &operator=(Data const &data);
        int getData() const;
        void setData(int newData);
};

#endif
