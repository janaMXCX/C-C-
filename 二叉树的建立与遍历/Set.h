#ifndef SET_H_INCLUDED
#define SET_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <stack>
#include <queue>
#include "create.h"
#include "traverse.h"
#include "Nonrecursive.h"
#include "Strataorder.h"
#include "depth.h"
#include "leaf.h"

#define OK 1
#define ERROR 0
#define OVERFLOW -2

using namespace std;
typedef int Status;

void menu();
void select_menu();
void menu2();
void select_menu2();

void Leaf_run_first();
void Depth_run_first();
void Traversal_first();
void create_first();

#endif // SET_H_INCLUDED
