
#include"function.h"

int main(int argc, char ** argv)
{
	int i;
	int input;
	/*for (i = 0; i < argc; i++)
		printf("Argument %d is %s\n", i, argv[i]);*/
	if (argc>=3)
	{
		if (argv[1][1] == 'c')//输入数字
		{
			input = 0;
			int mp = strlen(argv[2]);
			for (i = 0; i <mp ; i++)
			{
				input = input * 10;
				input += (int(argv[2][i]) - 48);

			}
			creat(input);
			printf("%d\n", input);
		}
		else//传入文件
		{
			int te;
			int m=0, n=0;
			int sudoku[9][9];
			ofstream out;
			out.open("suduku.txt");
			
			FILE *fp;//定义文件指针
			if ((fp = fopen(argv[2], "r")) == NULL)//如果文件名不存在
			{
				printf("cantfind the file!");
			}//则输出没有找到文件
			while (!feof(fp))
			{
				sudoku[9][9] = {0};
				for (int a = 0; a < 9; a++)
				{
					for (int b = 0; b < 9; b++)
						sudoku[a][b]=0;
				}
				m = 0;
				while (m != 9)
				{
					for (n = 0; n < 9; n++)
					{
						te=fscanf(fp, "%d", &sudoku[m][n]);//逐个将文件中的数据放入数组中
						
					}
					m++;
				}
				if (te == -1)
					break;
				int num_of_empty;
				//为回溯栈分配空间
				Node * node_stack;

				if (general_inspection(sudoku))
				{
					printf("此数独存在错误！请检查\n");
					print_sudoku(sudoku);
					continue;
				}
				num_of_empty = blank_num(sudoku);
				node_stack = mem_alloc(num_of_empty);
				trace(sudoku, node_stack, num_of_empty);

				char space = 32;
				for (int i = 0; i<9; i++)
				{
					for (int j = 0; j < 9; j++)
					{
						//s[i][j] = a[i][j];
						out << sudoku[i][j];
						if (j<8)
							out << space;
					}
					out << '\n';
					//outf.write(s[i], strlen(s[i]));
				}
				out<< '\n';
			}
			fclose(fp);
			out.close();
		}
	}
	return 0;
}