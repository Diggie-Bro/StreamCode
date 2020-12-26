/*
 * cio.h
 *
 * StreamCode IO module headerfile: console standard I/O module.
 * author: RedoC
 *
 * 2020, DiggieBro. All right reserved.
 * This file is under MIT license.
 * check LICENSE to get license information.
 * */
#ifndef CIO_MODULE_HEADER
#define CIO_MODULE_HEADER
#include <iostream>
#include <string>
#include "../stream/type.h"

using namespace std;

void cio_std_out(struct Variables str_value) {
    if (str_value.type == STRING) {
        cout << str_value.value;
    }
}
#endif

