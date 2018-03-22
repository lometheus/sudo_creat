#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void hang_methon(int sudoku[9][9]);
void print_sudoku(int sudoku[9][9]);
void lie_methon(int sudoku[9][9]);


int main()
{
	int i=0, number,way[5];
	int temp[10], temp2[10], num_out[10];
	int sudoku[9][9] = { { 5, 4, 6, 3, 9, 2, 8, 7, 1 },
	{ 3, 2, 8, 5, 7, 1, 9, 4, 6 },
	{ 9, 1, 7, 8, 6, 4, 2, 3, 5 },
	{ 7, 8, 2, 6, 1, 3, 5, 9, 4 },
	{ 1, 6, 5, 2, 4, 9, 3, 8, 7 },
	{ 4, 9, 3, 7, 5, 8, 1, 6, 2 },
	{ 6, 5, 9, 1, 3, 7, 4, 2, 8 },
	{ 8, 3, 1, 4, 2, 6, 7, 5, 9 },
	{ 2, 7, 4, 9, 8, 5, 6, 1, 3 } };
	int in_time;
	srand((unsigned)time(NULL)); //用时间做种，每次产生随机数不一样
	
	number = rand() % 4; //产生0-3的随机数
	while (i < 9)
	{
		lie_methon(sudoku);
		i++;
	}

}
void hang_methon(int sudoku[9][9])
{
	int i, j;
	int temp[9], temp2[9], number = 0, number2 = 0;
	while (number == 0) {
		number = rand() % 9;
		number2 = number;
	}
	if (number <= 2)
	{
		if (number == 2)
		{
			for (i = 0; i < 9; i++)
			{
				temp[i] = sudoku[2][i];
				sudoku[2][i] = sudoku[1][i];
				sudoku[1][i] = temp[i];
			}
		}
		if (number == 1)
		{
			for (i = 0; i < 9; i++)
			{
				temp[i] = sudoku[2][i];
				sudoku[2][i] = sudoku[1][i];
				sudoku[1][i] = temp[i];
			}
		}
	}
		else if (number <= 5)
		{
			while (number2 == number)
			{
				number2 = rand() % 3 + 3;
			}
			for (i = 0; i < 9; i++)
			{
				temp[i] = sudoku[number2][i];
				sudoku[number2][i] = sudoku[number][i];
				sudoku[number][i] = temp[i];
			}

		}
		else
		{
			while (number2 == number)
			{
				number2 = rand() % 3 + 6;
			}
			for (i = 0; i < 9; i++)
			{
				temp[i] = sudoku[number2][i];
				sudoku[number2][i] = sudoku[number][i];
				sudoku[number][i] = temp[i];
			}
		}
		print_sudoku(sudoku);
		printf("\n");
}
void lie_methon(int sudoku[9][9])
{
	int i, j;
	int temp[9], temp2[9], number = 0, number2 = 0;
	while (number == 0) {
		number = rand() % 9;
		number2 = number;
	}
	printf("%d\n", number);
	if (number <= 2)
	{
		if (number == 2)
		{
			for (i = 0; i < 9; i++)
			{
				temp[i] = sudoku[i][2];
				sudoku[i][2] = sudoku[i][1];
				sudoku[i][1] = temp[i];
			}
		}
		if (number == 1)
		{
			for (i = 0; i < 9; i++)
			{
				temp[i] = sudoku[i][2];
				sudoku[i][2] = sudoku[i][1];
				sudoku[i][1] = temp[i];
			}
		}
	}
	else if (number <= 5)
	{
		while (number2 == number)
		{
			number2 = rand() % 3 + 3;
		}
		for (i = 0; i < 9; i++)
		{
			temp[i] = sudoku[i][number2];
			sudoku[i][number2] = sudoku[i][number];
			sudoku[i][number] = temp[i];
		}

	}
	else
	{
		while (number2 == number)
		{
			number2 = rand() % 3 + 6;
		}
		for (i = 0; i < 9; i++)
		{
			temp[i] = sudoku[i][number2];
			sudoku[i][number2] = sudoku[i][number];
			sudoku[i][number] = temp[i];
		}
	}
	print_sudoku(sudoku);
	printf("\n");

}

void print_sudoku(int sudoku[9][9])
{
	//打印数独
	int i, j;
	for (i = 0; i<9; i++)
	{
		for (j = 0; j<9; j++)
			printf("%2d ", sudoku[i][j]);
		printf("\n");
	}
}