#include <fstream>
#include <iostream>

#ifndef MYFILE_HPP
#define MYFILE_HPP

class MyFile {
	
	private:
		std::string		fileName;
		std::string		newFile;

	public:
		MyFile();
		MyFile(std::string fileName);
		~MyFile();
		const std::string &getFileName();
		void		setFileName(std::string fileName);
		const std::string &getNewFileName();
		void		setNewFileName();
		bool		replace(std::string s1, std::string s2);
	};


#endif