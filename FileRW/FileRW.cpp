#include "FileRW.h"

/*
ofstream         //�ļ�д���� �ڴ�д��洢�豸
ifstream     //�ļ����������洢�豸�������ڴ���
fstream    //��д�������Դ򿪵��ļ��ɽ��ж�д����
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

