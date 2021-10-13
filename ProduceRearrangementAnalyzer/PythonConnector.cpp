#include "PythonConnector.h"
#include <Python.h>
#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

int PythonConnector::callIntFunc(string procedureName, int param)
{
	return _PyLong_AsInt(callPythonFunc(procedureName, param));
}

void PythonConnector::callProcedure(string procedureName, int param)
{
	callPythonFunc(procedureName, param);
}

void PythonConnector::callProcedure(std::string procedureName)
{
	callPythonFunc(procedureName);
}

PyObject* PythonConnector::callPythonFunc(string procedureName, int param)
{
	PyObject* pFunction = getPythonFunction(procedureName);

	PyObject* pValue = Py_BuildValue("(i)", param);
	PyErr_Print();

	PyObject* pResult = PyObject_CallObject(pFunction, pValue);
	Py_Finalize();

	return pResult;
}

PyObject* PythonConnector::callPythonFunc(std::string procedureName)
{
	PyObject* pFunction = getPythonFunction(procedureName);

	PyObject* pResult = PyObject_CallObject(pFunction, NULL);
	Py_Finalize();

	return pResult;
}

PyObject* PythonConnector::getPythonFunction(string procedureName)
{
	char* procName = new char[procedureName.length() + 1];
	std::strcpy(procName, procedureName.c_str());

	Py_Initialize();
	PyObject* pModule = PyImport_ImportModule("PythonCode");
	PyErr_Print();

	PyObject* pFunction = PyObject_GetAttrString(pModule, procName);

	delete[] procName;

	return pFunction;
}
