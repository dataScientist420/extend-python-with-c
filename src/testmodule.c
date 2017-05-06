/******************************************************************************
                          ____     ____                                                 
                 		 / __/	  / __/__  __ _____________                            
                		/ /_	 _\ \/ _ \/ // / __/ __/ -_|                           
               			\__/	/___/\___/\___/_/  \__/\__/                            
                                                                                                                                                                          
*******************************************************************************
 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.

 @file: testmodule.c
 @description: This file implements a new extension module for Python 3.                                               
 @author: Victor Neville                                                                                              
 @date:  31/5/2014                                                                                                                                                                                             
******************************************************************************/

#include <Python.h>
#include <stdio_ext.h>

/******************************************************************************
 @name: __get_int
 @description: allows the user to enter an integer on the keyboard
 @args:
 - msg: the message to be displayed
 - max: the maximum integer value that the user can enter
 @return: the integer entered by the user
******************************************************************************/
static int __get_int(char *msg, int max)
{
	int val, ok;

	/* loop as long as the entered value is not an integer */
	do {
		system("clear");
		printf("%s", msg);
		ok = scanf("%d", &val);
		__fpurge(stdin);
		
	} while (!ok || val > max);

	return val;
}

/******************************************************************************
 @name: __fibonacci
 @description: computes the fibonacci sum of a number (n)
 @args: the integer received (n)
 @return: the fibonacci sum of n
******************************************************************************/
static int64_t __fibonacci(int n)
{
	return (n < 2) ? n : __fibonacci(n-1) + __fibonacci(n-2);
}

/******************************************************************************
 @name: __factorial
 @description: computes the factorial of a number (n)
 @args: the integer received (n)
 @return: the factorial of n
******************************************************************************/
static int64_t __factorial(int n)
{
	return (n <= 0) ? 1 : n * __factorial(n-1);
}

/******************************************************************************
 @name: __digits_sum
 @description: computes the digits sum of a number (n)
 @args: the integer received (n)
 @return: the digits sum of n
******************************************************************************/
static int __digits_sum(int n)
{
	int sum = 0;
	
	/* loop as long as there are digits */
	while (n > 0) {
		sum += (n % 10);
		n /= 10;
	}
	return sum;
}

/******************************************************************************
 @name: get_int
 @description: builds a new Python object for __get_int function
 @args:
 - PyObject *: a pointer to the module object for module-level functions
 - PyObject *: a pointer to a Python tuple object containing the arguments
 @return: a new Python object
******************************************************************************/
static PyObject *get_int(PyObject *self, PyObject *args)
{
	char *msg = NULL;
	int max = 0;

	if (!PyArg_ParseTuple(args, "si", &msg, &max))
		return NULL;

	return Py_BuildValue("i", __get_int(msg, max)); 
}

/******************************************************************************
 @name: fibonacci
 @description: builds a new Python object for __fibonacci function
 @args:
 - PyObject *: a pointer to the module object for module-level functions
 - PyObject *: a pointer to a Python object containing the arguments
 @return: a new Python object
******************************************************************************/
static PyObject *fibonacci(PyObject *self, PyObject *args)
{
	int n=0;

	if (!PyArg_ParseTuple(args, "i", &n))
		return NULL;

	return Py_BuildValue("l", __fibonacci(n));
}

/******************************************************************************
 @name: factorial
 @description: builds a new Python object for __factorial function
 @args:
 - PyObject *: a pointer to the module object for module-level functions
 - PyObject *: a pointer to a Python object containing the arguments
 @return: a new Python object
******************************************************************************/
static PyObject *factorial(PyObject *self, PyObject *args)
{
	int n=0;

	if (!PyArg_ParseTuple(args, "i", &n))
		return NULL;

	return Py_BuildValue("l", __factorial(n));
}

/******************************************************************************
 @name: digits_sum
 @description: builds a new Python object for __digits_sum function
 @args:
 - PyObject *: a pointer to the module object for module-level functions
 - PyObject *: a pointer to a Python object containing the arguments
 @return: a new Python object
******************************************************************************/
static PyObject *digits_sum(PyObject *self, PyObject *args)
{
	int n=0;

	if (!PyArg_ParseTuple(args, "i", &n))
		return NULL;

	return Py_BuildValue("i", __digits_sum(n)); 
}

/******************************************************************************
 Array of PyMethodDef structures used to describe a method of an extension type
******************************************************************************/
static PyMethodDef module_methods[] = {
	{"get_int", get_int, METH_VARARGS, "get an integer"},
	{"fibonacci", fibonacci, METH_VARARGS, "compute fibonacci"},
	{"factorial", factorial, METH_VARARGS, "compute factorial"},
	{"digits_sum", digits_sum, METH_VARARGS, "compute digits sum"},
	{NULL, NULL, 0, NULL}
};

/******************************************************************************
 The module struct, which holds all info needed to create a module object.
******************************************************************************/
static struct PyModuleDef testmodule = {
    PyModuleDef_HEAD_INIT, "testmodule", NULL, -1, module_methods
};

/******************************************************************************
 @name: PyInit_testmodule
 @description: initializes the module
 @return: a pointer to a Python object containing the module
******************************************************************************/
PyMODINIT_FUNC PyInit_testmodule(void)
{
    static PyObject *error = NULL;
    PyObject *m;

    m = PyModule_Create(&testmodule);
    
    if (!m)
        return NULL;

    error = PyErr_NewException("testmodule.error", NULL, NULL);
    Py_INCREF(error);
    PyModule_AddObject(m, "error", error);
    return m;
}

