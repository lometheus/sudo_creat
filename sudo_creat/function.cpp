#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<fstream>
#include <math.h>
#include <time.h>
using namespace std;
int sudo_re[1000005][9][9];
typedef struct node
{
	int col;
	int row;
	int value[10];
} Node;
ofstream outf;
void save_q(int num)
{
	ofstream outfile;
	outfile.open("sudo.txt");
	for (int i = 0; i<num; i++) 
	{
		for (int j = 0; j < 9; j++)
		{
			for (int m = 0; m < 8; m++)
			{
				outfile << sudo_re[i][j][m] ;
				outfile <<" ";
			} 
			outfile << sudo_re[i][j][8];
			outfile << '\n';
		}
		if(num-1!=i)
		outfile << '\n';
	}
	
	outfile.close();
}
void save(int a[9][9])
{
	char space = 32;
	for (int i = 0; i<9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			//s[i][j] = a[i][j];
			outf << a[i][j];
			if (j<8)
				outf << space;
		}
		outf << '\n';
		//outf.write(s[i], strlen(s[i]));
	}
	outf << '\n';

}
void save_memory(int a[9][9], int tim)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			sudo_re[tim][i][j] = a[i][j];
		}
	}
}

void num_methon(int sudoku[9][9])
{
	int i, j, number = 0, number2 = 0, temp1, temp2, temp3;
	while (number == 0 || number == 5)
	{
		number = rand() % 10;
		number2 = number;
	}
	while (number2 == 0 || number2 == number || number2 == 5)
	{
		number2 = rand() % 10;
	}
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			if (number == sudoku[i][j])
				temp1 = j;
			if (number2 == sudoku[i][j])
				temp2 = j;
		}
		temp3 = sudoku[i][temp1];
		sudoku[i][temp1] = sudoku[i][temp2];
		sudoku[i][temp2] = temp3;
	}

}
int creat(int in_time)
{
	int i = 0, number;
	int sudoku[9][9] = { { 5, 4, 6, 3, 9, 2, 8, 7, 1 },
	{ 3, 2, 8, 5, 7, 1, 9, 4, 6 },
	{ 9, 1, 7, 8, 6, 4, 2, 3, 5 },
	{ 7, 8, 2, 6, 1, 3, 5, 9, 4 },
	{ 1, 6, 5, 2, 4, 9, 3, 8, 7 },
	{ 4, 9, 3, 7, 5, 8, 1, 6, 2 },
	{ 6, 5, 9, 1, 3, 7, 4, 2, 8 },
	{ 8, 3, 1, 4, 2, 6, 7, 5, 9 },
	{ 2, 7, 4, 9, 8, 5, 6, 1, 3 } };
	srand((unsigned)time(NULL)); //��ʱ�����֣�ÿ�β����������һ��
								 //scanf_s("%d", &in_time);
	clock_t startTime, endTime;
	startTime = clock();
	int n=0;
	while (in_time--)
	{
		i = 0;
		number = 0;
		while (number == 0)
		{
			number = rand() % 10; //����1-9�������
		}

		while (i <= number)
		{
			//hang_methon(sudoku);
			num_methon(sudoku);
			//lie_methon(sudoku);
			i++;
		}
		//print_sudoku(sudoku);
		save_memory(sudoku,n);
		n++;
	}
	outf.open("sudo.txt");
	for ( i = 0; i < n; i++)
	{
		save(sudo_re[i]);
	}
	
	endTime = clock();
	cout << "Totle Time : " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
	return 0;
}
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

void hang_methon(int sudoku[9][9])
{
	int i;

	int temp[9], number = 0, number2 = 0;
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

}
void lie_methon(int sudoku[9][9])
{
	int i;
	int temp[9], number = 0, number2 = 0;
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