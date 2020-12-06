#include "../src/stream/stream.h"

/*
 * testfile description
 *
 * file: src/stream/proto/basic.streamcode
 * main := "hello world!"=>print;
 *
 * expect output: hello world!
 * */

int main() {
    // perform defination
    PerformFramework proc_perform;
    proc_perform.code_ = "callfunc (print) (\"hello world!\")";  // parsed code.
    proc_perform.parseCode();
    proc_perform.code_ = proc_perform.getParsedCode();

    // process defination
    Process stream_proc = {NULL, "", "", "", &proc_perform};

    // stream defination
    Stream strm = {"", &stream_proc};
    return 1;
}
