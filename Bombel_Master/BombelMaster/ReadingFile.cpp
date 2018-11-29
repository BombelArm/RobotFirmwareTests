
#include "ReadingFile.h"
#include <string>
#include <iostream>

file_handler_type::file_handler_type(char * filename)
{
	filename_ = filename;
	file.open(filename_);
	line_ = 0;
}

file_handler_type::~file_handler_type()
{
//	file.close;
}

int file_handler_type::readline(void)
{
	if (1)//file.is_open == 1)
	{
		//std::getline(file, buffer_);
		std::cout << buffer_;

		return 0;
	}
	else
	{
		return 1;
	}
}
