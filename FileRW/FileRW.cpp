#include "FileRW.h"
/*
ofstream    //文件写操作 内存写入存储设备
ifstream    //文件读操作，存储设备读区到内存中
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

string FileRW::GetValue(std::string root, std::string key)
{
	map<string, SubNode>::iterator itr = m_MapIni.find(root);
	map<string, string>::iterator m_SubItor = itr->second.m_SubNode.find(key);
	if (!(m_SubItor->second).empty())
		return m_SubItor->second;
	return "";
}
int FileRW::WriteINI(string path)
{
	ofstream OutConfFile(path.c_str());
	if (!OutConfFile)
		return -1;
	for (map<string, SubNode>::iterator itr = m_MapIni.begin(); itr != m_MapIni.end();++itr)
	{
		OutConfFile << "[" << itr->first << "]" << endl;
		for (map<string, string>::iterator SubItor = itr->second.m_SubNode.begin(); SubItor != itr->second.m_SubNode.end(); ++SubItor)
		{
			OutConfFile << SubItor->first << "=" <<SubItor->second<<endl; 
		}
		
	}

	OutConfFile.close();
	OutConfFile.clear();
	return 1;
}


void FileRW::writeString(const char* section, char* pszEntry, std::string Str)
{   
	using namespace std;
	std::ofstream Ofile;
	Ofile.open(fileName);
	Ofile << Str <<endl; 
	Ofile.close();
}

vector <ININode>::size_type FileRW::SetValue(string root, string key, string value)
{
	map<string, SubNode>::iterator itr = m_MapIni.find(root);
		if (m_MapIni.end()!=itr)
		{ 
			itr->second.m_SubNode.insert(pair<string,string>(key,value));
		}
		else
		{
			SubNode m_Sn;
			m_Sn.InsertElement(key,value);
			m_MapIni.insert(pair<string,SubNode>(root,m_Sn));
		}
		return  m_MapIni.size();
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
	while (getline(InConfFile, StrLine))
	{
		string::size_type LeftPos = 0;
		string::size_type RightPos = 0;
		string::size_type EqualDivPos = 0;
		string StrKey = "";
		string StrValue = "";
		if ((StrLine.npos != (LeftPos = StrLine.find("["))) && (StrLine.npos != (RightPos = StrLine.find("]"))))
		{
			StrRoot = StrLine.substr(LeftPos + 1, RightPos - 1);
		}
		if (StrLine.npos != (EqualDivPos = StrLine.find("=")))
		{
			StrKey = StrLine.substr(0, EqualDivPos);
			StrValue = StrLine.substr(EqualDivPos + 1, StrLine.size() - 1);
			StrKey = TrimString(StrKey);
			StrValue = TrimString(StrValue);
		}
		if ((!StrRoot.empty()) && (!StrKey.empty()) && (!StrValue.empty()))
		{
			ININode m_IniNode(StrRoot, StrKey, StrValue);
			VecIni.push_back(m_IniNode);
		}
	}
		InConfFile.close();
		InConfFile.clear();
		map<string, string> m_MapTmp;
		for (vector<ININode>::iterator itr = VecIni.begin(); itr != VecIni.end(); ++itr)
		{
			m_MapTmp.insert(pair<string, string>(itr->root, ""));
		}
		SubNode m_Sn;
		for (map<string, string>::iterator itr = m_MapTmp.begin(); itr != m_MapTmp.end(); ++itr)
		{
			for (vector<ININode>::iterator m_SubItr = VecIni.begin(); m_SubItr != VecIni.end(); ++m_SubItr)
			{
				m_Sn.InsertElement(m_SubItr->key, m_SubItr->value);
			}
			m_MapIni.insert(pair<string, SubNode>(itr->first, m_Sn));
		}

		return 1;

	}



	

