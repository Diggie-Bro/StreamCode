/*
 * stream.h
 * stream core framework header.
 *
 * mention @RedoC-github or @Diggie-Bro/streamcode for any help.
 * */

#ifndef STREAM_HEADER
#define STREAM_HEADER

// metadata
#include <string>

/*
 * class PerformFramework(code_)
 *
 * @author RedoC
 * Perform's framework class
 * */

class PerformFramework {
    private:
        char* parsed_code_;

    public:
        // constructor
        PerformFramework() {
            parsed_code_ = "";
        }

        char* code_;
        void parseCode() {}  // parse code_ to parsed_code_
        char* getParsedCode() {  // getter of parsed_code_
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
        char* tag_;    // process tag
        char* param_;  // process param. (e1, e2)...
        char* return_value_;   // process return. (e1, e2)...
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
        char* strm_tag_;
        Process* proc_head_;

        void connectStrmProc(Process* proc_next_) {
            proc_head_->proc_n_ = proc_next_;
        }
};

#endif
