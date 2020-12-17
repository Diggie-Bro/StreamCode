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

// stream structure
struct Stream {
    StreamType strm_type_;  // stream type
    Process* proc_node_;  // process node. Never NULL
    string strm_name_;  // stream name. just option
};

#endif

