#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int resurch(int sudoku[9])
{
	return 0;
}
int main()
{
	int sudoku[9][9];
	int temp[10], temp2[10], num_out[10];
	int i = 0, count = 0, a, j = 1, m;
	for (i = 0; i < 10; i++)
	{
		temp[i] = 0;
	}
	temp2[0] = 5;
	while (count != 10)
	{
		a = rand() % 10;
		if (temp[a] == 0)
		{
			temp[a] = 1;
			count++;
			if (a != 0 && a != 5)
			{
				temp2[j] = a;
				j++;
			}
		}
	}
	for (i = 0; i < 9; i++)
		sudoku[i][0] = temp2[i];
	for (i = 1; i < 9; i++)
	{
		m = 0, j = 0, count = 0;
		for (m = 0; m < 10; m++)
		{
			temp[m] = 0;
		}
		while (count != 10)
		{
			a = rand() % 10;
			if (temp[a] == 0)
			{
				temp[a] = 1;
				count++;
				if (a != 0)
				{
					sudoku[j][i] = a;
					j++;
				}
			}
		}
	}
	int t = 0;
	for (i = 0; i < 9; i++)
	{
		for (m = 0; m < 10; m++)
		{
			temp[m] = 0;
			temp2[m] = 0;
		}
		m = 0;
		for (j = 0; j < 9; j++)
		{
			temp[sudoku[i][j]]++;

			temp2[sudoku[i][j]] = j + temp2[sudoku[i][j]] * 10;
			if (temp[sudoku[i][j]]>1)
			{
				num_out[m] = sudoku[i][j];//记录多出的数字
			}
		}
		m = 0;
		for (t = 1; t < 10; t++)
		{
			int tt1;
			int t2 = 0, t3 = 0;

			if (temp[t] == 0)//发现行缺少的数字t//从重复的数字的列中寻找列中缺少数字的位置
			{
				tt1 = temp2[num_out[t2]] % 10;
				int flag = 0; int plus = 10;
				while (flag == 0)
				{

					for (t3 = i + 1; t3 < 9; t3++)
					{
						if (sudoku[t3][tt1] == t)//
						{
							int temps = sudoku[t3][tt1];
							sudoku[t3][tt1] = sudoku[i][tt1];
							sudoku[i][tt1] = temps;

							temp2[num_out[t2]] = temp2[num_out[t2]] - tt1*(plus / 10);
							flag = 1;
							temp[num_out[t2]]--;
							t2++;
							temp[t] = 1;
							break;
						}
					}
					if (flag == 0)
					{

						plus = plus * 10;
						tt1 = (temp2[num_out[t2]] % plus) / (plus / 10);
					}
				}
			}

		}
		for (int kk = 0; kk<9; kk++)
		{
			for (int jj = 0; jj<9; jj++)
				printf("%2d ", sudoku[kk][jj]);
			printf("\n");
		}
		printf("\n");


	}

}