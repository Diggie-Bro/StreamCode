/*
 * execute.h
 *
 * StreamCode Runtime Code Executor Headfile.
 * author: RedoC
 *
 * 2020, DiggieBro. All right reserved.
 * This file is under MIT license.
 * check LICENSE to get license information.
 * */

#ifndef RUNTIME_EXECUTE_HEADER
#define RUNTIME_EXECUTE_HEADER
#include <vector>
#include <string>
#include "../stream/stream.h"
using namespace std;

class Executor {
    public:
        StreamCode code_;
        // :TODO error handler
        
        int executeCode() {
            string file_name_ = code_.file_name_;
            Importer importer_ = *code_.module_importer_;

            Stream *node_strm = code_.strm_node_;
            while (true) {
                Process *node_proc = node_strm->proc_node_;
                while (true) {
                    PerformFunction *node_perf = node_proc->perf_func_node_;
                    while (true) {
                        // TODO list
                        // - impl assign, return perform function 
                        // - in, out pipeline
                        importer_.executeIO(node_perf->perform_func_name_, node_perf->param_);

                        if (NULL == node_perf->perf_func_next_) break;
                        node_perf = node_perf->perf_func_next_;
                    }
                    if (NULL == node_proc->proc_next) break;
                    node_proc = node_proc->proc_next;
                }
                if (NULL == node_strm->strm_node_next_) break;
                node_strm = node_strm -> strm_node_next_;
            }
            return 0;
        }
};

#endif
