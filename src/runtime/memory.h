/*
 * memory.h
 *
 * StreamCode Runtime Memory Headfile 
 * author: RedoC
 *
 * 2020, DiggieBro. All right reserved.
 * This file is under MIT license.
 * check LICENSE to get license information.
 * */

#ifndef RUNTIME_MEMORY_HEADER
#define RUNTIME_MEMORY_HEADER

// include header
#include <cstdlib>
#include <malloc/malloc.h>
#include <string>
#include "../stream/type.h"

// basic namespace
using namespace std;

// struct Variables* declareVariable(struct Variables& variable)
// declare variable from param.
//
// malloc it and return the pointer heading new variable.
struct VariableMem declareVariable(struct Variables& variable) {
    struct VariableMem mem {variable.type, NULL, NULL, NULL, NULL};

    if (variable.type == INT) {
        int* new_variable = (int *)malloc(sizeof(int));
        mem.integerMem = new_variable;
    } else if (variable.type == DOUBLE) {
        double* new_variable = (double *)malloc(sizeof(double));
        mem.doubleMem = new_variable;
    } else if (variable.type == STRING) {
        string* new_variable = (string *)malloc(sizeof(string) * variable.value.length());
        mem.stringMem = new_variable;
    } else if (variable.type == BOOL) {
        bool* new_variable = (bool *)malloc(sizeof(bool));
        mem.booleanMem = new_variable;
    } else {
        // :TODO hmmmm..... 
    }

    return mem;
}

// void editVariable(struct VariableMem& mem, struct Variables& variable)
// modify mem's heading value to variable
void editVariable(struct VariableMem& mem, struct Variables& variable) {
    if (variable.type != mem.type) return;
    if (mem.type == INT) {
        int nvariable = *mem.integerMem;
        nvariable = atoi(variable.value.c_str());
    } else if (mem.type == DOUBLE) {
        double nvariable = *mem.doubleMem;
        nvariable = atof(variable.value.c_str());
    } else if (mem.type == STRING) {
        string nvariable = *mem.stringMem;
        nvariable = variable.value;
    } else if (mem.type == BOOL) {
        bool nvariable = *mem.booleanMem;
        nvariable = variable.value == "false" ? false : true;
    }
}

// struct Variables getVariable(struct VariableMem& mem)
// return variable structure from mem
struct Variables getVariable(struct VariableMem& mem) {
    struct Variables variable {mem.type, ""};
    if (mem.type == INT) variable.value = to_string(*mem.integerMem);
    else if (mem.type == DOUBLE) variable.value = to_string(*mem.doubleMem);
    else if (mem.type == STRING) variable.value = *mem.stringMem;
    else if (mem.type == BOOL) variable.value = (*mem.booleanMem == true ? "true" : "false");
    return variable;
}
#endif
