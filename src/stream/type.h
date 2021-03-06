/*
 * type.h
 *
 * StreamCode Type Structure Headfile.
 * author: RedoC
 *
 * 2020, DiggieBro. All right reserved.
 * This file is under MIT license.
 * check LICENSE to get license information.
 * */

#ifndef TYPE_HEADER
#define TYPE_HEADER

// include header
#include <string>

// basic namespace
using namespace std;

// types enum
//
// in streamcode, we support integer, double, string, and bool types(void too).
enum Types {
    INT,
    DOUBLE,
    STRING,
    BOOL,
    VOID,
    VARIABLE,
};


// variable structure
struct Variables {
    Types type;
    string value;
};

// memory structure
struct VariableMem {
    Types type;
    string varname;
    int integerMem;
    double doubleMem;
    string stringMem;
    bool booleanMem;
};

#endif
