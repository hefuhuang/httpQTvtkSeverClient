#pragma once
#ifndef _FILERW_H_
#define _FILERW_H_

#include "filerw_global.h"
#include<fstream>
#include<iomanip>
#include<iostream>
#include<string>
#include<list> 
#include<vector>
#include<map>
#include<windows.h>

 // 访问者模式 
class Element;  
class ININode;
class SubNode;
using namespace std;

class FILERW_EXPORT FileRW
{
public:
    FileRW(const char* Str); 
	~FileRW();

	string &TrimString(string &str);
	int ReadINI(std::string path);
	std::string GetValue(std::string root, std::string key);
	vector<ININode>::size_type GetSize(){
		return map_ini.size();
	}
	vector<ININode>::size_type SetValue(string root, string key, string value);
	int WriteINI(string path);

	void Clear(){
		map_ini.clear();
	}

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
    map<std::string, SubNode> map_ini;
};

class ININode
{
public:
	ININode(string root, string key, string value)
	{
			this->root = root;
			this->key = key;
			this->value = value;
	}
		string root;
		string key;
		string value;
};
class SubNode
{
public:
	void InsertElement(std::string key, std::string value)
	{	
	sub_node.insert(pair<string, string>(key, value));
	}
	map<string, string> sub_node;
};

#endif