#pragma once
#include <Python.h>
#include <string>

class PythonConnector
{
public:
    /// <summary>
    /// To call this function, pass the name of the Python function you wish to call and the string parameter you want to send.
    /// <para>Example: int x = callIntFunc("DoubleValue", 5);</para>
    /// <para>Output: Python will return 10.</para>
    /// </summary>
    /// <param name="procedureName">Name of the procedure to call.</param>
    /// <param name="param">Integer parameter required by the procedure.</param>
    /// <returns>Integer response from Python function.</returns>
    static int callIntFunc(std::string procedureName, int param);

    /// <summary>
    /// To call this function, simply pass the function name in Python that you wish to call and the int param it requires.
    /// <para>Example: callProcedure("MultiplicationTable", 6);</para>
    /// <para>Output: Python will print the multiplication table for 6 on the screen.</para>
    /// </summary>
    /// <param name="procedureName">Name of the procedure to call.</param>
    /// <param name="param">Integer parameter required by the procedure.</param>
    static void callProcedure(std::string procedureName, int param);

    /// <summary>
    /// To call this function, simply pass the function name in Python that you wish to call and the int param it requires.
    /// <para>Example: callProcedure("MultiplicationTable", 6);</para>
    /// <para>Output: Python will print the multiplication table for 6 on the screen.</para>
    /// </summary>
    /// <param name="procedureName">Name of the procedure to call.</param>
    /// <param name="param">String parameter required by the procedure.</param>
    static void callProcedure(std::string procedureName, std::string param);

    /// <summary>
    /// To call this function, simply pass the function name in Python that you wish to call.
    /// <para>Example: callProcedure("PrintSomething");</para>
    /// <para>Output: Python will print something on the screen.</para>
    /// </summary>
    /// <param name="procedureName">Name of the procedure to call.</param>
    static void callProcedure(std::string procedureName);

private:
    /// <summary>
    /// To call this function, pass the name of the Python function you wish to call and the string parameter you want to send.
    /// <para>Example: int x = callPythonFunc("DoubleValue", 5);</para>
    /// <para>Output: Python will return a PyObject* with 10 as the value.</para>
    /// </summary>
    /// <param name="procedureName">Name of the procedure to call.</param>
    /// <param name="param">Integer parameter required by the procedure.</param>
    /// <returns>PyObject* response from Python function.</returns>
    static PyObject* callPythonFunc(std::string procedureName, int param);

    /// <summary>
    /// To call this function, pass the name of the Python function you wish to call and the string parameter you want to send.
    /// <para>Example: int x = callPythonFunc("DoubleValue", 5);</para>
    /// <para>Output: Python will return a PyObject* with 10 as the value.</para>
    /// </summary>
    /// <param name="procedureName">Name of the procedure to call.</param>
    /// <param name="param">String parameter required by the procedure.</param>
    /// <returns>PyObject* response from Python function.</returns>
    static PyObject* callPythonFunc(std::string procedureName, std::string param);

    /// <summary>
    /// To call this function, pass the name of the Python function you wish to call.
    /// <para>Example: callPythonFunc("PrintSomething");</para>
    /// <para>Output: Python will return a PyObject* with null as the value.</para>
    /// </summary>
    /// <param name="procedureName">Name of the procedure to call.</param>
    /// <returns>PyObject* response from Python function.</returns>
    static PyObject* callPythonFunc(std::string procedureName);

    /// <summary>
    /// Gets a PyObject form of a string param.
    /// </summary>
    /// <param name="param">String param to convert.</param>
    /// <returns>PyObject* of string param.</returns>
    static PyObject* getPythonValueString(std::string param);

    /// <summary>
    /// Gets the Python Function for a specified procedure name.
    /// </summary>
    /// <param name="procedureName">The name of the procedure for which to get the function.</param>
    /// <returns></returns>
    static PyObject* getPythonFunction(std::string procedureName);
};

