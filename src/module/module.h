/*
 * module.h
 *
 * StreamCode Module Structure Headfile.
 * author: RedoC
 *
 * 2020, DiggieBro. All right reserved.
 * This file is under MIT license.
 * check LICENSE to get license information.
 * */

#ifndef MODULE_HEADER
#define MODULE_HEADER

// include header
#include <string>
#include <vector>

// basic namespace
using namespace std;

struct Module {
    string module_names_;
    string configure_file_;
    vector<string> module_files_;
};
#endif
