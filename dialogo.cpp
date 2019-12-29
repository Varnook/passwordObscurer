#include "dialogo.h"

char * dialogo(const char * password, int size) {
	PyObject *pName, *pModule, *pFunc, *pArgs, *pPassword, *pLength, *pValue;

	Py_Initialize();
	PyRun_SimpleString("import sys");
	PyRun_SimpleString("sys.path.append('/home/juan/Programs/passwordObscurer')");
	pName = PyUnicode_DecodeFSDefault("pObscurer");
	pModule = PyImport_Import(pName);
    Py_DECREF(pName);

	pFunc = PyObject_GetAttrString(pModule, "obscurePassword");

	pArgs = PyTuple_New(2);    
	pPassword = PyUnicode_FromString(password); 
	pLength = PyLong_FromLong(size);
	PyTuple_SetItem(pArgs, 0, pPassword);
	PyTuple_SetItem(pArgs, 1, pLength);

	pValue = PyObject_CallObject(pFunc, pArgs);
	
	Py_DECREF(pArgs);

	PyObject *temp_bytes = PyUnicode_AsEncodedString(pValue, "UTF-8", "strict");
	char* result = PyBytes_AS_STRING(temp_bytes);
	Py_DECREF(temp_bytes);
    

	Py_DECREF(pValue);
	Py_DECREF(pFunc);
	Py_DECREF(pModule);

	Py_Finalize();
	return result;
}
