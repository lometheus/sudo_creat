#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int col;
	int row;
	int value[10];
} Node;
int  general_inspection(int sudoku[9][9])
{
	int temp[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int temp2[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	int i, j, m, n;
	for (i = 0; i<9; i++)
		for (j = 0; j<9; j++)
			if (sudoku[i][j] != 0)
			{
				for (m = 0; m < 10; m++)
				{
					temp[m] = 0;
				}
				for (m = 0; m<9; m++)
					if (sudoku[i][m] != 0)
					{
						if (temp[sudoku[i][m]] == 0)
							temp[sudoku[i][m]] = 1;
						else
							return 1;
					}
				//检查所在列
				for (m = 0; m<10; m++)
					temp[m] = 0;
				for (m = 0; m<9; m++)
					if (sudoku[m][j] != 0)
					{
						if (temp[sudoku[m][j]] == 0)
							temp[sudoku[m][j]] = 1;
						else
							return 1;
					}
				//检查所在九宫格
				for (m = 0; m<10; m++)
					temp[m] = 0;
				for (m = 0; m<3; m++)
					for (n = 0; n<3; n++)
						if (sudoku[i / 3 * 3 + m][j / 3 * 3 + n] != 0)
						{
							if (temp[sudoku[i / 3 * 3 + m][j / 3 * 3 + n]] == 0)
								temp[sudoku[i / 3 * 3 + m][j / 3 * 3 + n]] = 1;
							else
								return 1;
						}

			}
			else
			{
				for (m = 0; m<10; m++)
					temp2[m] = 0;
				for (m = 1; m<10; m++)
				{
					temp2[sudoku[i][m - 1]] = 1;
					temp2[sudoku[m - 1][j]] = 1;
				}
				for (m = 0; m<3; m++)
					for (n = 0; n<3; n++)
						temp2[sudoku[i / 3 * 3 + m][j / 3 * 3 + n]] = 1;
				int count = 0;
				for (int x = 1; x < 10; x++)
				{
					if (temp2[x] == 1)
						count++;
				}
				if (count == 9)
					return 1;
			}
	return 0;
}

int blank_num(int sudoku[9][9])
{
	//计算所给数独中待填入的空白数
	int i, j, num = 0;
	for (i = 0; i<9; i++)
		for (j = 0; j<9; j++)
			if (sudoku[i][j] == 0)
				num++;
	return num;
}

Node * mem_alloc(int num_of_empty)
{
	Node * node_stack = (Node *)malloc(sizeof(struct node) * num_of_empty);
	if (node_stack == NULL)
	{
		printf("内存分配失败！\n");
		exit(1);
	}
	return node_stack;
}

int findvalue(int sudoku[9][9], Node * node)
{
	int m, n, i = node->col, j = node->row;
	//初始化栈中存储候选值的数组
	for (m = 0; m<10; m++)
		node->value[m] = 0;
	for (m = 1; m<10; m++)
	{
		node->value[sudoku[i][m - 1]] = 1;
		node->value[sudoku[m - 1][j]] = 1;
	}
	for (m = 0; m<3; m++)
		for (n = 0; n<3; n++)
			node->value[sudoku[i / 3 * 3 + m][j / 3 * 3 + n]] = 1;

	//node->value[0]记录候选值个数，前面的循环可能会修改掉它，需要重新赋0值
	node->value[0] = 0;
	for (m = 1; m<10; m++)
		if (node->value[m] == 0)	node->value[0]++;
	for (m = 1; m<10; m++)
		if (node->value[m] == 0)
		{
			node->value[m] = 1;
			node->value[0]--;
			break;
		}

	//返回候选值m，若无候选值可用，返回错误标记-1
	if (m == 10)
		return -1;
	else
		return m;
}

void trace(int sudoku[9][9], Node * node_stack, int num_of_empty)
{
	int i, j, index, k = 0;
	//回溯法求解数独
	while (num_of_empty)
	{
		for (i = 0; i<9; i++)
		{
			for (j = 0; j<9; j++)
			{
				if (sudoku[i][j] == 0)
				{
					(node_stack + k)->col = i;
					(node_stack + k)->row = j;
					sudoku[i][j] = findvalue(sudoku, node_stack + k);
					if (sudoku[i][j] == -1)
					{
						sudoku[i][j] = 0;
						k--;
						while ((node_stack + k)->value[0] == 0)
						{
							//当栈空，说明数独错误，无解
							if (k == 0)
							{
								printf("此数独无解！\n");
								//free(node_stack);	//为啥这里一释放内存，就弹出debug assertion failed窗口啊！
								exit(1);
							}
							sudoku[(node_stack + k)->col][(node_stack + k)->row] = 0;
							num_of_empty++;
							k--;
						}
						for (index = 1; index<10; index++)
							if ((node_stack + k)->value[index] == 0)
							{
								sudoku[(node_stack + k)->col][(node_stack + k)->row] = index;
								(node_stack + k)->value[index] = 1;
								(node_stack + k)->value[0]--;
								break;
							}
						num_of_empty++;
						i = (node_stack + k)->col;
						j = (node_stack + k)->row;
					}
					k++;
					num_of_empty--;
				}
			}
		}
	}
	//栈空间使用结束，释放
	free(node_stack);
	node_stack = NULL;
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