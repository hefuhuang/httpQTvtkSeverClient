#include "Rebuild.h"
#include "GlobalVAton.h" 
#include "FileRW.h"
#include "Qt3DRebuild.h"

Rebuild::Rebuild(QWidget *parent)
	: QMainWindow(parent)
{
	GlobalVaton *singletonObj = GlobalVaton::Instance();   
	fileOperation();
	ui.setupUi(this);
}

void Rebuild::fileOperation()
{   
	string filePath = "../System.ini";
	FileRW file(filePath.c_str()); 
	file.ReadINI(filePath); 
	file.SetValue("class1","name1","tom"); 

	file.SetValue("class1", "m", "1");
	file.SetValue("class1", "n", "2");
	file.WriteINI("../System.ini");
}
