
/*
2017/12/ 29 
author��huanghefu
Priciple��
��֤һ����ֻ��һ��ʵ�������ṩһ����������ȫ�ַ��ʵ㡣���ȣ���Ҫ��֤һ����ֻ��һ��ʵ���������У�Ҫ����һ��ʵ����
�ͱ��������Ĺ��캯������ˣ�Ϊ�˷�ֹ���ⲿ������Ĺ��캯��������ʵ������Ҫ�����캯���ķ���Ȩ�ޱ��Ϊprotected��private��
�����Ҫ�ṩҪ��ȫ�ַ��ʵ㣬����Ҫ�����ж���һ��static���������������ڲ�Ψһ�����ʵ����
Function : ������ʵ�ȫ�ֱ��� 

*/

#pragma once
#include<iostream>

using namespace ::std;

#define DEFAULT_CONTENT	_T("text to be sent")
#define DEFAULT_ADDRESS	_T("127.0.0.1")     //����IP 
#define DEFAULT_PORT	_T("5555")  

class GlobalVaton
{
public:
	static GlobalVaton* Instance(); 
	static void DestoryInstance();
private: 
	static GlobalVaton *m_GlobalVaton;
	// important part   ʹ�ù��� �������� 
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
	GlobalVaton(){};  // �����˽�����ԣ����ཫ�޷����ʸ���Ĺ��캯�� 
	string Util;
	
};

