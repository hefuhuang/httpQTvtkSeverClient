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

std::string &FileRW::TrimString(std::string &str)
{
	string::size_type pos = 0; 
	while (str.npos !=(pos=str.find(" ")))
	{
		str = str.replace(pos,pos+1,"");
		return str;
	}
}

int  FileRW::ReadINI(string path)
{
	ifstream InConfFile(path.c_str());
	if (!InConfFile)  return 0;
	string StrLine = "";
	string StrRoot = ""; 
	vector<ININode> VecIni;
	while (getline(InConfFile,StrLine))   
	{ 
		string::size_type LeftPos = 0;
		string::size_type RightPos = 0;
		string::size_type EqualDivPos = 0; 
		string StrKey = "";
		string StrValue = "";
		if ((StrLine.npos != (LeftPos = StrLine.find("["))) && (StrLine.npos != (RightPos = StrLine.find("]"))))
		{
			StrRoot = StrLine.substr(LeftPos+1,RightPos-1); 
	  }
		if (StrLine.npos!=(EqualDivPos=StrLine.find("=")))
		{
			StrKey = StrLine.substr(0,EqualDivPos); 
			StrValue = StrLine.substr(EqualDivPos+1,StrLine.size()-1);
			StrKey = TrimString(StrKey); 
			StrValue = TrimString(StrValue);
		}


}