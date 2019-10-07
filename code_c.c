#include <Python.h>

void PrintPython(){
	PyObject *mydef = PyImport_ImportModule("scripts.python");

	if(mydef){
		PyObject *printHello = PyObject_GetAttrString(mydef
				, "PrintMyDef");
		if(printHello){
			PyObject *r = PyObject_CallFunction(printHello
					, NULL);

			if(r == Py_None){
				printf("None is returned.\n");
				Py_XDECREF(r);
			}

			Py_XDECREF(printHello);
		}
		Py_XDECREF(mydef);
	}
}

int Multiply(int x, int y){
	PyObject *mydef = PyImport_ImportModule("scripts.python");
	int result;

	if(mydef){
		PyObject *multiply = PyObject_GetAttrString(mydef
				, "Multiply");

		if(multiply){
			PyObject *r = PyObject_CallFunction(multiply
					, "ii", x, y);

			if(r){
				result = (int)PyInt_AS_LONG(r);
				Py_XDECREF(r);
			}
			Py_XDECREF(multiply);
		}
		Py_XDECREF(mydef);
	}
	return result;
}

void SysPath(){
	printf("sys.path:");
	PyRun_SimpleString("import sys\nprint sys.path\nprint\n");
}

int main(int argc, char **argv){
	Py_SetProgramName(argv[0]);
	Py_Initialize();
	printf("GetProgramName: %s\n\n", Py_GetProgramName());

	if(Py_IsInitialized()){
		PySys_SetArg(argc, argv);
		printf("GetPath: %s\n\n", Py_GetPath());
		SysPath();
		PrintPython();
		printf("%d * %d = %d\n", 10, 15, Multiply(10, 15));
		Py_Finalize();
	}
	return 0;
}
