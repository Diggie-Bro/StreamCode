#include <vector>
#include <string>
#include "../misc/headerimport.h"
using namespace std;
/*
 * import io;
 * main := ("hello world")=>(print);
 *
 * */

int main() {
    Importer importer; importer.importIOModule();
    struct Variables print_func_param {
        Types(STRING),
        "hello world",
    };

    vector<struct Variables> print_func_params; 
    print_func_params.push_back(print_func_param);

    struct PerformFunction print_func {
        Operators(CALLFUNC),
        NULL, 
        "print",
        print_func_params,
    };

    Process print_proc {
        NULL,
        "",
        vector<struct Variables> (0),
        vector<struct Variables> (0),
        &print_func,
    };

    Stream main_strm {
        NULL,
        StreamType(UNIT),
        &print_proc,
        "main",
    };

    StreamCode code {
        &main_strm,
        &importer,
        "hello_world.strmcode",
    };

    Executor exec_ = {
        code
    };

    exec_.executeCode();
}
