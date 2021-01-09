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
#include <malloc/_malloc.h>
#include <malloc/malloc.h>
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
        char** new_variable = (char **)malloc(sizeof(char) * variable.value.length());
        mem.stringMem = new_variable;
    } else if (variable.type == BOOL) {
        bool* new_variable = (bool *)malloc(sizeof(bool));
        mem.booleanMem = new_variable;
    } else {
        // :TODO hmmmm..... 
    }

    return mem;
}

void editVariable(struct VariableMem& mem, struct Variables& variable) {
    if (variable.type != mem.type) return;
    if (mem.type == INT) {
        int variable = *mem.integerMem
    }
}
#endif
