/*
 * memory.h
 *
 * StreamCode Runtime Memory & Variable Headfile 
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
#include <string>
#include "../stream/type.h"

// basic namespace
using namespace std;

// class VariableManager
// manage variable
class VariableManager {
    public:
        // struct Variables* declareVariable(struct Variables& variable)
        // declare variable from param.
        //
        // malloc it and return the pointer heading new variable.
        struct VariableMem declareVariable(struct Variables& varname, struct Variables& variable) {
            // if (varname.type != VARIABLE) break
            struct VariableMem mem {variable.type, varname.value, 0, 0.0, "", true};

            if (variable.type == INT) {
                mem.integerMem = stoi(variable.value);
            } else if (variable.type == DOUBLE) {
                mem.doubleMem = stof(variable.value);
            } else if (variable.type == STRING) {
                mem.stringMem = variable.value;
            } else if (variable.type == BOOL) {
                mem.booleanMem = variable.value == "false" ? false : true;
            } else {
                // :TODO hmmmm..... 
            }

            return mem;
        }

        // void editVariable(struct VariableMem& mem, struct Variables& variable)
        // modify mem's heading value to variable
        void editVariable(struct VariableMem* mem, struct Variables& variable) {
            if (variable.type != mem->type) return;
            if (mem->type == INT) {
                int nvariable = mem->integerMem;
                nvariable = atoi(variable.value.c_str());
            } else if (mem->type == DOUBLE) {
                double nvariable = mem->doubleMem;
                nvariable = atof(variable.value.c_str());
            } else if (mem->type == STRING) {
                string nvariable = mem->stringMem;
            } else if (mem->type == BOOL) {
                bool nvariable = mem->booleanMem;
                nvariable = variable.value == "false" ? false : true;
            }
        }

        // struct Variables getVariable(struct VariableMem& mem)
        // return variable structure from mem
        struct Variables getVariable(struct VariableMem* mem) {
            struct Variables variable {mem->type, ""};
            if (mem->type == INT) variable.value = to_string(mem->integerMem);
            else if (mem->type == DOUBLE) variable.value = to_string(mem->doubleMem);
            else if (mem->type == STRING) variable.value = mem->stringMem;
            else if (mem->type == BOOL) variable.value = (mem->booleanMem == true ? "true" : "false");
            return variable;
        }
};
#endif
