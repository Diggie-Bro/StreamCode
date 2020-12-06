/*
 * stream.h
 * stream core framework header.
 *
 * mention @RedoC-github or @Diggie-Bro/streamcode for any help.
 * */

#ifndef STREAM_HEADER
#define STREAM_HEADER

// metadata
#include <vector>
#include <string>
#include "keywords.h"
using namespace std;


/*
 * class PerformFramework(code_)
 *
 * @author RedoC
 * Perform's framework class
 * */

class PerformFramework {
    private:
        string parsed_code_;

    public:
        // constructor
        PerformFramework() {
            parsed_code_ = "";
        }

        string code_;
        void parseCode() {  // parse code_ to parsed_code_
            parsed_code_ = code_;
        }

        string getParsedCode() {  // getter of parsed_code_
            return parsed_code_;
        }
};

/*
 * class Process(proc_n_, tag_, param_, return_value_, perform_)
 *
 * @author RedoC
 * Process(elements of Stream)'s framework class.
 * */

class Process {
    /*
     * process structure
     * TAG | PARAM -> RETURN :: <PERFORM>
     * <> : necessary element
     *
     * TAG: process's name
     * PARAM: process in-pipeline
     * RETURN: process out-pipeline
     * PERFORM: process's work.
     * */

    public:
        Process* proc_n_;   // pointer to next process. It can be null.
        string tag_;    // process tag
        string param_;  // process param. (e1, e2)...
        string return_value_;   // process return. (e1, e2)...
        PerformFramework* perform_; // process perform. It cannot be null.
};

/*
 * class Stream(strm_tag_, proc_head_)
 *
 * @author RedoC
 * Stream's framework class.
 * */

class Stream {
    public:
        string strm_tag_;
        Process* proc_head_;

        void connectStrmProc(Process* proc_next_) {
            proc_head_->proc_n_ = proc_next_;
        }
};

#endif
