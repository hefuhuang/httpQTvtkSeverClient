#include "GlobalVAton.h"

/*
��̬��ʼ���ڳ���ʼʱ��Ҳ���ǽ���������֮ǰ�������߳��Ե��̷߳�ʽ����˳�ʼ����
���Ծ�̬��ʼ��ʵ����֤���̰߳�ȫ�ԡ�������Ҫ��Ƚϸ�ʱ���Ϳ���ʹ�����ַ�ʽ��
�Ӷ�����Ƶ���ļ����ͽ�����ɵ���Դ�˷ѡ�
*/
GlobalVaton *GlobalVaton::m_GlobalVaton = new GlobalVaton; 
//GlobalVaton ::GC GlobalVaton ::gc;   //��̬������ȫ�ֱ������ڴ��У����Ǵ洢�ھ�̬�洢���ģ�����������ʱ����ͬ�ȶԴ��� 
GlobalVaton* GlobalVaton::Instance()
{
	/*   �̰߳�ȫ���⣬ ���߳�ʱ����ȱ�� 
	ʹ�õ���ν�ġ�˫���������ơ���Ϊ����һ�μ����ͽ�������Ҫ������Ӧ�Ĵ��۵ģ�
	�����������жϣ��Ϳ��Ա����μ��������������ͬʱҲ��֤���̰߳�ȫ�����ǣ�
	����ʵ�ַ�����ƽʱ����Ŀ�������õĺܺã�Ҳû��ʲô���⣿���ǣ�������д����ݵĲ�����
	������������Ϊһ�����ܵ�ƿ����

	if (globalVaton== NULL)
	{
	lock();   //boost���ṩ�� 
	if (globalVaton== NULL)
	{
		globalVaton = new GlobalVaton;
	}
    unlock();
	}
	*/
	printf("%s","construct successful");
	return m_GlobalVaton;
}
  
void GlobalVaton::DestoryInstance()
{
	if (m_GlobalVaton != nullptr)
	{
		delete m_GlobalVaton;
		m_GlobalVaton = NULL;
	}
}


