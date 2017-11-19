#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <Python.h>
#include <string>
const char * encrypt(const char * raw,const char * key);
const char * decrypt(const char * raw,const char * key);
int main()
{
	 setenv("PYTHONPATH", ".", 1);
	const  char * row="welcome to this world";
	const  char * key="amr";
	const char * f=encrypt("welcome to this world","amr");
  	printf("%s",decrypt(f,"amr"));
    return 0;
}

const char * encrypt(const char * raw,const char * key){
	PyObject *pName, *pModule, *pDict, *pFunc;
    PyObject *pArgs, *pValue;
    int i;

    Py_Initialize();
    /* Error checking of pName left out */

    pModule = PyImport_ImportModule("aes");
    
    if (pModule != NULL) {
        pFunc = PyObject_GetAttrString(pModule, "encrypt");
        /* pFunc is a new reference */

        if (pFunc && PyCallable_Check(pFunc)) {
            pArgs = PyTuple_New(2);
            
                pValue = PyString_FromString(raw);
                if (!pValue) {
                    Py_DECREF(pArgs);
                    Py_DECREF(pModule);
                    fprintf(stderr, "Cannot convert argument\n");
                    std::string ret_val="-1";
                    return ret_val.c_str();
                }
                  /* pValue reference stolen here: */
                PyTuple_SetItem(pArgs, 0, pValue);
            

                pValue = PyString_FromString(key);
                if (!pValue) {
                    Py_DECREF(pArgs);
                    Py_DECREF(pModule);
                    fprintf(stderr, "Cannot convert argument\n");
                    std::string ret_val="-1";
                    return ret_val.c_str();
                }

                /* pValue reference stolen here: */
                PyTuple_SetItem(pArgs, 1, pValue);
            	
            pValue = PyObject_CallObject(pFunc,pArgs);
            Py_DECREF(pArgs);
            if (pValue != NULL) {
                //printf("Result of call: %s\n", PyString_AsString(pValue));
                return (const char* )PyString_AsString(pValue);
                Py_DECREF(pValue);
            }
            else {
                Py_DECREF(pFunc);
                Py_DECREF(pModule);
                PyErr_Print();
                fprintf(stderr,"Call failed\n");
                std::string ret_val="-1";
                    return ret_val.c_str();
            }
        }
        else {
            if (PyErr_Occurred())
                PyErr_Print();
            fprintf(stderr, "Cannot find function " );
            std::string ret_val="-1";
                    return ret_val.c_str();
        }
        Py_XDECREF(pFunc);
        Py_DECREF(pModule);
    }
    else {
        PyErr_Print();
        fprintf(stderr, "Failed to load module ");
        std::string ret_val="-1";
                    return ret_val.c_str();
        //return 1;
    }
    Py_Finalize();

}

const char * decrypt(const char * raw,const char * key){


	PyObject *pName, *pModule, *pDict, *pFunc;
    PyObject *pArgs, *pValue;
    int i;

    Py_Initialize();
    /* Error checking of pName left out */

    pModule = PyImport_ImportModule("aes");
    
    if (pModule != NULL) {
        pFunc = PyObject_GetAttrString(pModule, "decrypt");
        /* pFunc is a new reference */

        if (pFunc && PyCallable_Check(pFunc)) {
            pArgs = PyTuple_New(2);
            
                pValue = PyString_FromString(raw);
                if (!pValue) {
                    Py_DECREF(pArgs);
                    Py_DECREF(pModule);
                    fprintf(stderr, "Cannot convert argument\n");
                    std::string ret_val="-1";
                    return ret_val.c_str();
                }
                  /* pValue reference stolen here: */
                PyTuple_SetItem(pArgs, 0, pValue);
            

                pValue = PyString_FromString(key);
                if (!pValue) {
                    Py_DECREF(pArgs);
                    Py_DECREF(pModule);
                    fprintf(stderr, "Cannot convert argument\n");
                    std::string ret_val="-1";
                    return ret_val.c_str();
                }

                /* pValue reference stolen here: */
                PyTuple_SetItem(pArgs, 1, pValue);
            	
            pValue = PyObject_CallObject(pFunc,pArgs);
            Py_DECREF(pArgs);
            if (pValue != NULL) {
                //printf("Result of call: %s\n", PyString_AsString(pValue));
                return (const char* )PyString_AsString(pValue);
                Py_DECREF(pValue);
            }
            else {
                Py_DECREF(pFunc);
                Py_DECREF(pModule);
                PyErr_Print();
                fprintf(stderr,"Call failed\n");
                std::string ret_val="-1";
                    return ret_val.c_str();
            }
        }
        else {
            if (PyErr_Occurred())
                PyErr_Print();
            fprintf(stderr, "Cannot find function " );
            std::string ret_val="-1";
                    return ret_val.c_str();
        }
        Py_XDECREF(pFunc);
        Py_DECREF(pModule);
    }
    else {
        PyErr_Print();
        fprintf(stderr, "Failed to load module ");
        std::string ret_val="-1";
                    return ret_val.c_str();
        //return 1;
    }
    Py_Finalize();

}
