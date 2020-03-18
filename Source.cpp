#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//#define scanf scanf_s

#define MAXCNT 5

int main(void) {

	char in_name[10] = {};
	int in_code[10] = {};

	char co_name[10] = {};
	int co_code[10] = {};


	int in_ten = 0, in_kosuu[10] = { 0 };
	int total = 0;

	FILE* gf_pt;


	int judge = 0;

	int command = 0;

	typedef struct {
		char name[10];
		int code[10];
		int tanka;
	}shape;


	shape syohin[MAXCNT];


	if (fopen_s(&gf_pt, "gakusei.dat", "w+") != NULL) {
		printf("FILE OPEN ERROR\n");
		exit(EXIT_FAILURE);
	}


	printf("データを入力\n");
	rewind(stdin);
	while (judge != 1) {
		rewind(stdin);
		scanf_s("%s %d %d", in_name, 10,in_code,10, &in_ten, 10);
		fprintf(gf_pt, "%10s %3d %3d", in_name, in_code, in_ten);
		rewind(stdin);
		printf("入力を続けますか？ (Y:0/N:1)\n");
		scanf_s("%d", &judge);
	}


	for (int i = 0; i < MAXCNT; i++) {
		if (fscanf_s(gf_pt, "%s %d %d", syohin[i].name,10, syohin[i].code,10, &syohin[i].tanka,10))
			break;
	}


	printf("\nコードと数量を入力\n");
	judge = 0;
	while (judge != 1) {
		command++;
		rewind(stdin);
		scanf_s("%s %d", co_code, 10, &in_kosuu, 10);
		
		for (int i = 0; i < command; i++) {
			for (int j = 0; j < MAXCNT; j++) {
				if (co_code[i] == *syohin[j].code) {
					break;
				}
				else {
					if (j == MAXCNT - 1)
						printf("%sは存在しません。", co_code[i]);
					continue;
				}
			}
		
		}
		rewind(stdin);
		printf("入力を続けますか？ (Y:0/N:1)\n");
		scanf_s("%d", &judge);
	}

	for (int i=0;i<command;i++){
		for (int j = 0; j < MAXCNT; j++) {
			if (co_code[i] == *syohin[j].code) {
				printf("%s * %d %d円 ", syohin[j].name, in_kosuu[i], syohin[j].tanka * in_kosuu[i]);
				total += syohin[j].tanka * in_kosuu[i];
			}
		}
	}

	printf("合計 %d", total);

	/*
	printf("\nデータを表示します\n");
	rewind(gf_pt);
	while ((fscanf(gf_pt, "%10s %3d", &in_name, &in_ten)) != EOF) {
		//w_goukei += in_ten;
		printf("%-10s %3d\n", in_name, in_ten);
	}

	//printf("    %4d\n", w_goukei);
	*/
	if (fclose(gf_pt) == EOF) {
		printf("FILE CLOSE ERROR\n");
		exit(EXIT_FAILURE);
	}

	system("pause");
	return 0;

}