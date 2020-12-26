/*
 * importer.h
 *
 * StreamCode Module Importer Headfile.
 * author: RedoC
 *
 * 2020, DiggieBro. All right reserved.
 * This file is under MIT license.
 * check LICENSE to get license information.
 * */

#ifndef IMPORTER_HEADER
#define IMPORTER_HEADER

// include header
#include <string>
#include <vector>
#include "./module.h"
#include "../builtin/io.h"
#include "../io/cio.h"

// basic namespace
using namespace std;

class Importer {
    public:
        struct Module module_;

        void importIOModule() {
            module_ = getIOModule();
        }

        struct Variables executeIO(string func_name, vector<struct Variables> params) {
            return executor(func_name, params);
        }
};

#endif
