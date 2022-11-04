#include <fstream>
#include <iostream>
#include <string>

#ifndef MYFILE_HPP
#define MYFILE_HPP

class MyFile {
	
	private:
		std::string		fileName;
		std::string		buf;
		std::string		newFile;

	public:
		MyFile(std::string fileName);
		~MyFile();
		bool	readToBuf(); // filename 에서 buf로 읽기 
		std::string	getBuf(); // buf 에서 len 만큼 읽기
		int		getBufSize();
		bool	writeToFile(const std::string &text, const int &len); // file에 text를 len 만큼 쓰기
		bool	writeNewFile();
		void	replaceBuf(std::string s1, std::string s2);
	};


#endif