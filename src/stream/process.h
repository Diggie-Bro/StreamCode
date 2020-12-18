/*
 * process.h
 *
 * StreamCode Process Structure Headfile.
 * author: RedoC
 *
 * 2020, DiggieBro. All right reserved.
 * This file is under MIT license.
 * check LICENSE to get license information.
 * */

#ifndef PROCESS_HEADER
#define PROCESS_HEADER

// include header
#include <vector>
#include <string>
#include "type.h"

// basic namespace
using namespace std;

// operators enum.
enum Operators {
    ASSIGN,  // assign A to B -> B = A
    CALLFUNC,  // call function A with B -> B=>A
    RETURN,  // return A to out pipeline -> return A
};

// perform function
//
// what is perform? perform is the working code.
// 
// compare with python function
// def <tag>(<param>):
//     <perform>
// 
// please visit wiki for more detail.


// perform function structure
// perform function is the ds of line of perform code.
struct PerformFunction {
    PerformFunction* perf_func_next_;  // next perform function
    Operators oper_;  // operator
    vector<string> param_;  // parameter vector
};

// process
//
// what is process? process is the unit of stream.
// [proc] >> [proc] >> [proc] >> ...
//
// please visit wiki for more detail.


// process class
class Process {
    public:
        Process* proc_next;  // next process node
        string tag_;  // tag
        vector<Variables> in_pipeline_;  // parameter
        vector<Variables> out_pipeline_;  // return value
        PerformFunction* perf_func_node_;  // perform node pointer
        
        // connect perf_func_n to perf_func_node_ (push)
        void ConnectPerform(PerformFunction* perf_func_n) {
            perf_func_node_->perf_func_next_ = perf_func_n;
        }
};
#endif
