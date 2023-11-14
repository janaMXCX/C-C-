#ifndef SET_H_INCLUDED
#define SET_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "conversion.h"
#include "dance.h"
#include "operation.h"
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;


void menu();
void select_menu();


void Conversion_first();
void Dance_first();
void Operation_first();

#endif // SET_H_INCLUDED
