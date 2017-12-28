#pragma once
#include<iostream>


using namespace ::std;

#define DEFAULT_CONTENT	_T("text to be sent")
#define DEFAULT_ADDRESS	_T("127.0.0.1")     //±¾»úIP 
#define DEFAULT_PORT	_T("5555")  

class GlobalVaton
{
public:
	static GlobalVaton* Instance(); 
	virtual void Show();

private: 
	static GlobalVaton *globalVaton;
	
protected:
	GlobalVaton(){};
	
};

