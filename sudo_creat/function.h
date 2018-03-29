#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<fstream>
#include <math.h>
#include <time.h>
using namespace std;
typedef struct node
{
	int col;
	int row;
	int value[10];
} Node;
int findvalue(int sudoku[9][9], Node * node);
int general_inspection(int sudoku[9][9]);
int blank_num(int sudoku[9][9]);
Node * mem_alloc(int num_of_empty);
void trace(int sudoku[9][9], Node * node_stack, int num_of_empty);
void print_sudoku(int sudoku[9][9]);
void hang_methon(int sudoku[9][9]);
void print_sudoku(int sudoku[9][9]);
void lie_methon(int sudoku[9][9]);
void num_methon(int sudoku[9][9]);
void save(int a[9][9]);
int creat(int in_time);
