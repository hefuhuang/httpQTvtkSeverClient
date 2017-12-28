#include "GlobalVAton.h"


GlobalVaton* GlobalVaton::Instance()
{
	if (globalVaton== NULL)
	{
		globalVaton = new GlobalVaton;
	}
	return globalVaton;
}
  



