#include "FileRW.h"
/*
ofstream         //文件写操作 内存写入存储设备
ifstream     //文件读操作，存储设备读区到内存中
fstream    //读写操作，对打开的文件可进行读写操作
*/

FileRW::FileRW(const char* Str) 
{
	strcpy(fileName, Str);
}

FileRW::~FileRW()
{
}
void* FileRW::ReCopy(char* src ,char* dest)
{
	char *tmp = dest;
	const char *s = src; 
	int i = sizeof(dest);
	while (i--)
	{
		*tmp++ = *s++;
	} 
	return dest;
}

void FileRW::writeString(const char* section, char* pszEntry, std::string Str)
{   
	using namespace std;
	std::ofstream Ofile;
	Ofile.open(fileName);
	Ofile << Str <<endl; 
	Ofile.close();
}
 
void FileRW::writeInt(char* section, char* pszEntry, int* data)
{

}
void FileRW::WriteBool(char* section, char*pszEntry, bool flag=0)
{

}
void FileRW::WriteFloat(char* section, char* pszEntry,float value)
{

}

std::string FileRW::ReadSrting(const char* section, char* pszEntry, std::string Str)
{   

	return Str;
}
int FileRW::ReadInt(const char* section, char* pszEntry, int data)
{

	return data;
}
bool FileRW::ReadBool(const char* section, char* pszEntry, bool flags =0)
{
	return flags;
}
float FileRW::ReadFloat(const char* section, char* pszEntry, float data)
{ 
	return data;
}
