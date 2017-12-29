
/*
2017/12/ 29 
author：huanghefu
Priciple：
保证一个类只有一个实例，并提供一个访问它的全局访问点。首先，需要保证一个类只有一个实例；在类中，要构造一个实例，
就必须调用类的构造函数，如此，为了防止在外部调用类的构造函数而构造实例，需要将构造函数的访问权限标记为protected或private；
最后，需要提供要给全局访问点，就需要在类中定义一个static函数，返回在类内部唯一构造的实例。
Function : 构造访问的全局变量 

*/

#pragma once
#include<iostream>

using namespace ::std;

#define DEFAULT_CONTENT	_T("text to be sent")
#define DEFAULT_ADDRESS	_T("127.0.0.1")     //本机IP 
#define DEFAULT_PORT	_T("5555")  

class GlobalVaton
{
public:
	static GlobalVaton* Instance(); 
	static void DestoryInstance();
private: 
	static GlobalVaton *m_GlobalVaton;
	// important part   使用过后 忘记销毁 
	class GC{
	public:
		~GC(){
			if (m_GlobalVaton != nullptr)
			{
				delete m_GlobalVaton;
				m_GlobalVaton = NULL;
			}
		};
		static GC gc;
	};
	
protected:
	GlobalVaton(){};  // 如果是私有属性，子类将无法访问父类的构造函数 
	string Util;
	
};

