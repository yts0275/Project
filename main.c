#include <Python.h>
#include <stdio.h>

int main(){
	Py_Initialize();

	PyRun_SimpleString("import sys");
	PyRun_SimpleString("sys.path");
	PyRun_SimpleString("sys.path.append('/root/mine')");
	PyRun_SimpleString("import histogram");
	PyRun_SimpleString("import equalization");
	PyRun_SimpleString("histogram.histogram()");
	PyRun_SimpleString("equalization.equalization()");

	Py_Finalize();
	return 0;
}
