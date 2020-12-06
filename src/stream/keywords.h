#ifndef KEYWORDS_HEADER
#define KEYWORDS_HEADER

enum keywords {
    call_function = 0,  // =>
    lval_sub,   // lval = expr
    statm_if,   // if
    statm_for,  // for
    statm_while,    // while
    statm_switch    // switch
};

enum logic_oper {
    logic_bigger = 0,   // >
    logic_bigequal, // >=
    logic_smaller,  // <
    logic_smallequal, // <=
    logic_equal, // ==
    logic_nequal,   // !=
    logic_or,   // ||
    logic_and,  // &&
};

enum operations {
    oper_mul = 0,   // *
    oper_div,   // /
    oper_mod,   // %
    oper_add,   // +
    oper_min, // -
};

#endif
