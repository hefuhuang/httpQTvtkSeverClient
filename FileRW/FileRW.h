#pragma once

#include "filerw_global.h"
#include<fstream>
#include<iomanip>
#include<iostream>
#include<string>
#include<list> 
#include<windows.h>

 // 访问者模式 
class Element;    

class FILERW_EXPORT FileRW
{
public:
    FileRW(const char* Str); 
	~FileRW();

	void writeString(const char* section, char* pszEntry, std::string Str);   // Writing String code  
	void writeInt(char* section, char* pszEntry, int* data);    // Writing Int code 
	void WriteBool(char* section, char* pszEntry, bool flag);
	void WriteFloat(char* section,char* pszEntry,float value);
	
	std::string ReadSrting(const char* section, char* pszEntry, std::string Str);
	int ReadInt(const char* section, char* pszEntry, int data);
	bool ReadBool(const char* section, char* pszEntry, bool flags);
	float ReadFloat(const char* section, char* pszEntry, float data);

	void *ReCopy(char* src,char* dest);

private:
	char  fileName[_MAX_PATH];

};
