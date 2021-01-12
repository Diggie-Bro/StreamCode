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

#include <iostream>
#include <vector>
#include <string>
#include "../stream/stream.h"
#include "memory.h"

// basic namespace
using namespace std;

// class Executor
// execute code.
class Executor {
    public:
        StreamCode code_;
        // :TODO error handler
        
        // int executeCode()
        // execute code (core system)
        int executeCode() {
            vector<struct VariableMem *> varStack_;
            VariableManager varmanger_;
            string file_name_ = code_.file_name_;
            Importer importer_ = *code_.module_importer_;

            Stream *node_strm = code_.strm_node_;
            while (true) {
                Process *node_proc = node_strm->proc_node_;
                while (true) {
                    PerformFunction *node_perf = node_proc->perf_func_node_;
                    while (true) {
                        Operators oper_ = node_perf->oper_;
                        if (oper_ == ASSIGN && node_perf->param_.size() == 2) {
                            bool isMade = false;
                            for (int i = 0; i < varStack_.size(); i++) {
                                if (node_perf->param_[0].value == varStack_[i]->varname) {
                                    struct Variables& variable = node_perf->param_[1];
                                    varmanger_.editVariable(varStack_[i], variable);
                                }
                            }
                            if (!isMade) {
                                struct Variables& variable = node_perf->param_[0];
                                struct Variables& expression = node_perf->param_[1];
                                struct VariableMem new_variable = varmanger_.declareVariable(variable, expression);
                                varStack_.push_back(&new_variable);
                            }
                        }
                        else if (oper_ == CALLFUNC) {
                            for (int i = 0; i < node_perf->param_.size(); i++) {
                                if (node_perf->param_[i].type == VARIABLE) {
                                    for (int j = 0; j < varStack_.size(); j++) {
                                        if (varStack_[j]->varname == node_perf->param_[i].value) {
                                            node_perf->param_[i] = varmanger_.getVariable(varStack_[j]);
                                        }
                                    }
                                }
                            }
                            importer_.executeIO(node_perf->perform_func_name_, node_perf->param_);
                        } else if (oper_ == RETURN) {
                            // :TODO return
                        }
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
