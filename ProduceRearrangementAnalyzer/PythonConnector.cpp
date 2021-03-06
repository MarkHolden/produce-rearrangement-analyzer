// *****************************************
// 
// Author: Mark Holden
// Date: 10/18/2021
// CS-210-R1971 Programming Languages 21EW1
// 
// *****************************************

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

int PythonConnector::callIntFunc(string procedureName, string param)
{
	return _PyLong_AsInt(callPythonFunc(procedureName, param));
}

void PythonConnector::callProcedure(string procedureName, int param)
{
	callPythonFunc(procedureName, param);
}

void PythonConnector::callProcedure(string procedureName, string param)
{
	callPythonFunc(procedureName, param);
}

void PythonConnector::callProcedure(string procedureName)
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

PyObject* PythonConnector::callPythonFunc(string procedureName, string param)
{
	PyObject* pFunction = getPythonFunction(procedureName);
	PyObject* pValue = getPythonValueString(param);
	PyObject* pResult = PyObject_CallObject(pFunction, pValue);
	Py_Finalize();

	return pResult;
}

PyObject* PythonConnector::getPythonValueString(string param)
{
	char* paramVal = new char[param.length() + 1];
	strcpy(paramVal, param.c_str());

	PyObject* pValue = Py_BuildValue("(s)", paramVal);
	PyErr_Print();

	delete[] paramVal;

	return pValue;
}

PyObject* PythonConnector::callPythonFunc(string procedureName)
{
	PyObject* pFunction = getPythonFunction(procedureName);

	PyObject* pResult = PyObject_CallObject(pFunction, NULL);
	Py_Finalize();

	return pResult;
}

PyObject* PythonConnector::getPythonFunction(string procedureName)
{
	char* procName = new char[procedureName.length() + 1];
	strcpy(procName, procedureName.c_str());

	Py_Initialize();
	PyObject* pModule = PyImport_ImportModule("PythonCode");
	PyErr_Print();

	PyObject* pFunction = PyObject_GetAttrString(pModule, procName);

	delete[] procName;

	return pFunction;
}
