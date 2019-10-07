#include <Python.h>
#include <stdio.h>

int main(){
	Py_Initialize();

	PyRun_SimpleString("print('1,2,3,4,5')");
	PyRun_SimpleString("print(range(5))");
	PyRun_SimpleString("import sys");
	PyRun_SimpleString("sys.path");
	PyRun_SimpleString("sys.path.append('/root/mine/python_c')");
	PyRun_SimpleString("import mytest");
	PyRun_SimpleString("print(mytest.mymulti(3,4))");
	PyRun_SimpleString("print(mytest.mymulti(5,6))");

	Py_Finalize();
	return 0;
}
