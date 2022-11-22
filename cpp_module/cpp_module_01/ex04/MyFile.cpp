#include "MyFile.hpp"

MyFile::MyFile() {}

MyFile::MyFile(std::string fileName)
{
	this->fileName = fileName;
	this->newFile = fileName.append(".replace");
}

MyFile::~MyFile()
{
}

const std::string &MyFile::getFileName()
{
	return (this->fileName);
}

void		MyFile::setFileName(std::string fileName)
{
	this->fileName = fileName;
}

const std::string &MyFile::getNewFileName()
{
	return (this->newFile);
}

void		MyFile::setNewFileName()
{
	if (this->getFileName().empty() == 0)
	{
		std::cout << "fileName is empty" << std::endl;
		return ;
	}
	this->newFile = fileName.append(".replace");
}

bool	MyFile::replace(std::string s1, std::string s2)
{
	if (s1.empty() || s2.empty()) {
		std::cout << "s1 or s2 is empty string" << std::endl;
		return (false);
	}

	// read file to buf
	std::fstream readFile(this->fileName, std::fstream::in);
	if (readFile.is_open() == false) {
		std::cout << "File error : can't open" << std::endl;
		return (false);
	}
	readFile.seekg(0, std::ios::end);
	int size = readFile.tellg();
	std::string buf;
	buf.resize(size);
	readFile.seekg(0, std::ios::beg);
	readFile.read(&buf[0], size);

	// buf에서 찾아서 바꾸기
	int index(buf.find(s1, 0));
	while (index != -1)
	{
		buf.erase(index, s1.length());
		buf.insert(index, s2);
		index = buf.find(s1, index + s2.length());
	}

	// newfile에 넣기
	std::fstream writeFile(this->newFile, std::fstream::out);
	if (writeFile.is_open() == false) {
		std::cout << "File error : can't open" << std::endl;
		return (false);
	}
	else
		writeFile << buf;
	return (true);
}