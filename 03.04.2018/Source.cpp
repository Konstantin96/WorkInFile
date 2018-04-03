#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>

using namespace std;

void main()
{
	srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//system("chcp 1251");
	int nz;
	printf("Enter number task: ");
	scanf("%d", &nz);
	if (nz == 1)
	{
		/*1.	������� �������������� ���� � �������� � ����:
a.	����� 500
b.	����� 4,5
c.	����� ������
*/
		FILE * fp = NULL;
		int d = 500;
		double s = 4.5;
		char *slovo = "Privet";

		if ((fp = fopen("test.txt", "w")) == NULL)
		{
			printf("Sorry file not opened!!!\n");
			exit(1);
			//exit(EXIT_FAILURE);
		}
		else
		{
			printf("File created!\n");
			fprintf(fp, "%d\n%f\n%s\n", d, s, slovo);
		}

	}
	else if (nz == 2)
	{
		/*2.	������� �������������� ���� � �������� � ���� (������������ ����� � ����� �������� � ����������)
a.	5 ���������� ����� �����
b.	5 ���������� ������������ �����
c.	5 ���������� ����
*/
		FILE * fp = NULL;

		if ((fp = fopen("test1.txt", "w")) == NULL)
		{
			printf("Sorry file not opened!!!\n");
			exit(1);
			//exit(EXIT_FAILURE);
		}
		else
		{
			printf("File created!\n");
			int b[5];
			float s[5];
			char *w;
			w = (char*)malloc(15 * sizeof(char));
			printf("Enter number: ");
			scanf("%d", &b[0]);
			printf("Enter number float: ");
			scanf("%f", &s[0]);
			printf("Enter text: ");
			scanf("%s", &w);
			for (int i = 0; i < 5; i++)
			{
				fprintf(fp, "%d\n%2.1f\n%s\n", b[0], s[0], &w);
			}
		}
	}

	else if (nz == 3)
	{
		/*3.	��� ������ �� �������� ������������ �����. �������� ��� ����� ������� � �������������� ���� � ��� �� �������*/
		int mas[20];
		for (int i = 0; i < 20; i++)
		{
			mas[i] = 1 + rand() % 9;
		}
		FILE * fp = NULL;

		if ((fp = fopen("test2.txt", "w")) == NULL)
		{
			printf("Sorry file not opened!!!\n");
			exit(1);
			//exit(EXIT_FAILURE);
		}
		else
		{
			printf("File created!\n");
			for (int i = 0; i < 20; i++)
			{
				fprintf(fp, "%d ", mas[i]);
			}
		}
	}

	else if (nz == 4)
	{
		/*4.	� ����� ������������� ��������������� ����� ��������
a.	����� 0
b.	����� �� ��������!
*/
		FILE * fp = NULL;

		if ((fp = fopen("test2.txt", "at")) == NULL)
		{
			printf("Sorry file not opened!!!\n");
			exit(1);
			//exit(EXIT_FAILURE);
		}
		else
		{
			printf("File created!\n");
			int a = 0;
			char *sl = "Bye Bye!!!";
			fprintf(fp, "%d %s", a, sl);
		}
	}

	else if (nz == 5)
	{
		/*5.	� ����� ������������� ����� ��������
a.	6 ����� �����
b.	5 ������������ �����
c.	4 �����
*/
		FILE * fp = NULL;

		if ((fp = fopen("test2.txt", "at")) == NULL)
		{
			printf("Sorry file not opened!!!\n");
			exit(1);
			//exit(EXIT_FAILURE);
		}
		else
		{
			printf("File created!\n");
			int a = 3;
			float b = 4.6;
			char *sl = "GOOD";
			fprintf(fp, "%d %2.1f %s", a,b, sl);
		}
	}

	else if (nz == 6)
	{
		/*1.	��� �������������� ����, ���������� �������� �������� �����. ����������
a.	n-� �������
b.	��������� �������
*/
		FILE * fp = NULL;

		if ((fp = fopen("test2.txt", "rt")) == NULL)
		{
			printf("Sorry file not opened!!!\n");
			exit(1);
			//exit(EXIT_FAILURE);
		}
		else
		{
			printf("File created!\n");
			int a;
			printf("Enter number is search:");
			scanf("%d", &a);
			char m;
			int count=0;
			while (feof(fp) == 1);
			{
				m=fgetc(fp);
				if (m != ' ')count++;
			}
			printf("Count number = %d\n", count);

			for (int i = 0; i < a; i++)
			{
				fputs(m,fp);
			}
			printf("element in file %c", m);
		}
	}

	else if (nz == 999)
	{
		FILE * fp = NULL;
		int d = 1;

		if ((fp = fopen("test.txt", "r")) == NULL)
		{
			printf("Sorry file not opened!!!\n");
			exit(1);
			//exit(EXIT_FAILURE);
		}

		else
		{
			printf("File created!\n");

			/*for (int i = 0; i < 128; i++)
			{
				fputc(i, fp);
			}
	*/
			int codeError = fgetc(fp);

			/*while (codeError != EOF)*/


			while (feof(fp) == 1);
			{
				printf("%d - %c\t", d++, codeError);
				codeError = fgetc(fp);
			}

		}

		if (fclose(fp) == 0)
		{
			printf("File closed!\n");
		}
		else
		{
			printf("Error closed file!\n");
			exit(EXIT_FAILURE);
		}
	}
}