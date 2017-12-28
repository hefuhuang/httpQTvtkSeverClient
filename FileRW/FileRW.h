#pragma once

#include "filerw_global.h"
#include<fstream>
#include<iomanip>
#include<iostream>
#include<string>
#include<list> 

 // 访问者模式 
class Element;    

class FILERW_EXPORT FileRW
{
public:
    FileRW(std::string Str); 
	~FileRW();
	void writeString(std::string Str);   // Writing String code  
	std::string ReadSrting();
	void writeInt(int data);    // Writing Int code 
	int ReadInt();

private:
	std::string  fileName;

};
