/*
 * io.h
 *
 * StreamCode IO module configuration Headfile.
 * author: RedoC
 *
 * 2020, DiggieBro. All right reserved.
 * This file is under MIT license.
 * check LICENSE to get license information.
 * */

#ifndef IO_MODULE_CONFIGURATION
#define IO_MODULE_CONFIGURATION

// include header
#include <string>
#include <vector>
#include "../module/module.h"
#include "../stream/type.h"
#include "../io/cio.h"

// basic namespace
using namespace std;

struct Module getIOModule() {
    struct Module ioModule;
    ioModule.module_names_ = "io";
    ioModule.configure_file_ = "io/config.strmcode";

    vector<string> module_vector;
    module_vector.push_back("io/cio.h");
    ioModule.module_files_ = module_vector;
    
    return ioModule;
}

struct Variables executor(string function, vector<struct Variables> param) {
    if (function == "print") {
        cio_std_out(param.at(0));
        struct Variables return_variable;
        return_variable.type = VOID;
        return_variable.value = "";
        return return_variable;
    } else {
        struct Variables return_variable;
        return_variable.type = VOID;
        return_variable.value = "";
        return return_variable;
    }
}

#endif
