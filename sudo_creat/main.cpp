
#include"function.h"

int main(int argc, char ** argv)
{
	int i;
	int input;
	/*for (i = 0; i < argc; i++)
		printf("Argument %d is %s\n", i, argv[i]);*/
	if (argc>=3)
	{
		if (argv[1][1] == 'c')//��������
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
		else//�����ļ�
		{
			int te;
			int m=0, n=0;
			int sudoku[9][9];
			ofstream out;
			out.open("suduku.txt");
			
			FILE *fp;//�����ļ�ָ��
			if ((fp = fopen(argv[2], "r")) == NULL)//����ļ���������
			{
				printf("cantfind the file!");
			}//�����û���ҵ��ļ�
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
						te=fscanf(fp, "%d", &sudoku[m][n]);//������ļ��е����ݷ���������
						
					}
					m++;
				}
				if (te == -1)
					break;
				int num_of_empty;
				//Ϊ����ջ����ռ�
				Node * node_stack;

				if (general_inspection(sudoku))
				{
					printf("���������ڴ�������\n");
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