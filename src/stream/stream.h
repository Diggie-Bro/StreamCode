/*
 * stream.h
 *
 * StreamCode Stream Structure Headfile.
 * author: RedoC
 *
 * 2020, DiggieBro. All right reserved.
 * This file is under MIT license.
 * check LICENSE to get license information.
 * */

#ifndef STREAM_HEADER
#define STREAM_HEADER

// include header
#include "process.h"
#include <vector>

// basic namespace 
using namespace std;

// stream type. for future development
enum StreamType {
    UNIT,  // unit stream. it include one process
    IO,  // io stream. it include two process(in, out)
    IFO,  // ifo(in, filter, out) stream. 3 process.
};

// stream class
class Stream {
    public:
        Stream* strm_node_next_;  // stream node -> next.
        StreamType strm_type_;  // stream type
        Process* proc_node_;  // process node. Never NULL
        string strm_name_;  // stream name. just option

        void ConnectProc(Process* proc_n) {
            proc_node_->proc_next = proc_n;
        }
};

class StreamCode {
    public:
        Stream* strm_node_;  // stream node
        // :TODO module importer
        string file_name_;  // file name

        void ConnectStrm(Stream* strm_n) {
            strm_node_->strm_node_next_ = strm_n;
        }
};

#endif

