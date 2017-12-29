#include "GlobalVAton.h"

/*
静态初始化在程序开始时，也就是进入主函数之前，由主线程以单线程方式完成了初始化，
所以静态初始化实例保证了线程安全性。在性能要求比较高时，就可以使用这种方式，
从而避免频繁的加锁和解锁造成的资源浪费。
*/
GlobalVaton *GlobalVaton::m_GlobalVaton = new GlobalVaton; 
//GlobalVaton ::GC GlobalVaton ::gc;   //静态变量和全局变量在内存中，都是存储在静态存储区的，所以在析构时，是同等对待的 
GlobalVaton* GlobalVaton::Instance()
{
	/*   线程安全问题， 多线程时存在缺陷 
	使用的所谓的“双检锁”机制。因为进行一次加锁和解锁是需要付出对应的代价的，
	而进行两次判断，就可以避免多次加锁与解锁操作，同时也保证了线程安全。但是，
	这种实现方法在平时的项目开发中用的很好，也没有什么问题？但是，如果进行大数据的操作，
	加锁操作将成为一个性能的瓶颈；

	if (globalVaton== NULL)
	{
	lock();   //boost库提供锁 
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


