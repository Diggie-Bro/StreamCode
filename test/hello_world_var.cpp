#include <vector>
#include <string>
#include "../misc/headerimport.h"
using namespace std;
/*
 * import io;
 * main := { 
 *     name = "dummy"
 *     (name)=>(print);
 * }
 * */

int main() {
    Importer importer; importer.importIOModule();
    struct Variables varname {
        Types(VARIABLE),
        "name",
    };
    struct Variables varvalue {
        Types(STRING),
        "dummy",
    };
    struct Variables print_perf_param {
        Types(VARIABLE),
        "name"
    };

    vector<struct Variables> var_name; 
    var_name.push_back(varname); var_name.push_back(varvalue);

    vector<struct Variables> print_proc_param;
    print_proc_param.push_back(print_perf_param);
    
    struct PerformFunction print_perf {
        CALLFUNC,
        NULL,
        "print",
        print_proc_param,
    };

    struct PerformFunction assignVar_name {
        ASSIGN,
        &print_perf, 
        "",
        var_name,
    };

    Process print_proc {
        NULL,
        "",
        vector<struct Variables> (0),
        vector<struct Variables> (0),
        &assignVar_name,
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
