#include "FileRW.h"

/*
ofstream         //文件写操作 内存写入存储设备
ifstream     //文件读操作，存储设备读区到内存中
fstream    //读写操作，对打开的文件可进行读写操作
*/


FileRW::FileRW(std::string Str) :fileName(Str)
{
}

FileRW::~FileRW()
{

}

void FileRW::writeString(std::string Str)
{
	using namespace std;
	std::ofstream Ofile;
	Ofile.open(fileName);
	Ofile << Str <<endl; 
	Ofile.close();

}

