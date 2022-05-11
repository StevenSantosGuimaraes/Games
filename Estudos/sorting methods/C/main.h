#ifndef MAIN_H
#define MAIN_H

// General variables:
int length;
float *values;

// Default library:
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Custom library:
#include "basic_function.h"
#include "sort_function.h"

int screenMain();
int screenSort();

#endif
