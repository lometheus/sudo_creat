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
				//���������
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
				//������ھŹ���
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
	//�������������д�����Ŀհ���
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
		printf("�ڴ����ʧ�ܣ�\n");
		exit(1);
	}
	return node_stack;
}

int findvalue(int sudoku[9][9], Node * node)
{
	int m, n, i = node->col, j = node->row;
	//��ʼ��ջ�д洢��ѡֵ������
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

	//node->value[0]��¼��ѡֵ������ǰ���ѭ�����ܻ��޸ĵ�������Ҫ���¸�0ֵ
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

	//���غ�ѡֵm�����޺�ѡֵ���ã����ش�����-1
	if (m == 10)
		return -1;
	else
		return m;
}

void trace(int sudoku[9][9], Node * node_stack, int num_of_empty)
{
	int i, j, index, k = 0;
	//���ݷ��������
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
							//��ջ�գ�˵�����������޽�
							if (k == 0)
							{
								printf("�������޽⣡\n");
								//free(node_stack);	//Ϊɶ����һ�ͷ��ڴ棬�͵���debug assertion failed���ڰ���
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
	//ջ�ռ�ʹ�ý������ͷ�
	free(node_stack);
	node_stack = NULL;
}



void print_sudoku(int sudoku[9][9])
{
	//��ӡ����
	int i, j;
	for (i = 0; i<9; i++)
	{
		for (j = 0; j<9; j++)
			printf("%2d ", sudoku[i][j]);
		printf("\n");
	}
}