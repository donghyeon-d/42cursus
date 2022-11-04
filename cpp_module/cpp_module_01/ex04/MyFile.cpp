#include "MyFile.hpp"

MyFile::MyFile(const std::string &fileName)
{
	this->fileName = fileName;
}

MyFile::~MyFile()
{
}

bool	MyFile::readToBuf()
{
	std::fstream readFile(this->fileName, std::fstream::in);
	if (readFile.is_open() == false) {
		std::cout << "File error : can't open" << std::endl;
		return (false);
	}
	else {
		readFile.seekg(0, std::ios::end);
		int size = readFile.tellg();
		this->buf.resize(size);
		readFile.seekg(0, std::ios::beg);
		readFile.read(&this->buf[0], size);
	}
	return (true);
}

bool	MyFile::writeToFile(const std::string &text, const int &len)
{
	std::fstream writeFile(this->fileName, std::fstream::out);//std::fstream::app | 
	if (writeFile.is_open() == false) {
		std::cout << "File error : can't open" << std::endl;
		return (false);
	}
	else
	{
		writeFile << text.substr(0, len);
	}
	return (true);
}

void	MyFile::replaceBuf(std::string s1, std::string s2)
{
	int index(this->buf.find(s1, 0));

	while (index != -1)
	{
		this->buf.erase(index, s1.length());
		this->buf.insert(index, s2);
		index = this->buf.find(s1, index);
	}
}

std::string	MyFile::getBuf()
{
	return (this->buf);
}

int		MyFile::getBufSize()
{
	return (this->buf.length());
}