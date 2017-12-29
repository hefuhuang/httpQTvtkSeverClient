#include "Rebuild.h"
#include "GlobalVAton.h" 
#include "FileRW.h"
#include "Qt3DRebuild.h"

Rebuild::Rebuild(QWidget *parent)
	: QMainWindow(parent)
{
	GlobalVaton *singletonObj = GlobalVaton::Instance();   

	ui.setupUi(this);
}

void Rebuild::fileOperation()
{   
	const char* filePath = "../System.ini";
	FileRW file(filePath);

}
