
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
			for (i = 0; i < sizeof(argv[2]) - 1; i++)
			{
				input = input * 10;
				input += (int(argv[2][i]) - 48);

			}
			creat(input);
			printf("%d\n", input);
		}
		else//�����ļ�
		{
			int m=0, n=0;
			int sudoku[9][9];
			ofstream outf;
			outf.open("suduku.txt");
			FILE *fp;//�����ļ�ָ��
			if ((fp = fopen("data.txt", "r")) == NULL)//����ļ���������
			{
				printf("cantfind the file!");
			}//�����û���ҵ��ļ�
			while (!feof(fp))
			{
				m = 0;
				while (m != 9)
				{
					for (n = 0; n < 9; n++)
					{
						fscanf(fp, "%d", &sudoku[m][n]);//������ļ��е����ݷ���������
					}
					m++;
					int num_of_empty;
					//Ϊ����ջ����ռ�
					Node * node_stack;

					if (general_inspection(sudoku))
					{
						printf("���������ڴ�������\n");
						print_sudoku(sudoku);
						return 0;
					}
					num_of_empty = blank_num(sudoku);
					node_stack = mem_alloc(num_of_empty);
					trace(sudoku, node_stack, num_of_empty);
					save(sudoku);
					system("pause");
				}
			}
			fclose(fp);
		}
	}
	return 0;
}