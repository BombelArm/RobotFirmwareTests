#pragma once
#include <fstream>
#include <string>

class file_handler_type
{
private:
	std::ofstream file;
	char * filename_;
	int line_;
	std::string buffer_;
	int jump_to_line_r();
public:
	file_handler_type(char * filename);
	~file_handler_type();
	int readline(void);
	int writeline(std::string data);
	int r_next_line(void);
	int r_i_line(int line);
	int w_i_line(int line, std::string data);

	

};