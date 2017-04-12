#include"DancePartner_H.h"
#include<stdio.h>
#include<string.h>
#include<malloc.h>
int main() {
	int num = 10;
	Person dancer[10];
	dancer[0].sex = 'M';	
	strcpy(dancer[0].name, "wzb");

	strcpy(dancer[1].name, "qqq");
	dancer[1].sex = 'M';

	strcpy(dancer[2].name, "www");
	dancer[2].sex = 'M';

	strcpy(dancer[3].name, "eee");
	dancer[3].sex = 'M';

	strcpy(dancer[4].name, "rrr");
	dancer[4].sex = 'M';

	strcpy(dancer[5].name, "aaa");
	dancer[5].sex = 'F';

	strcpy(dancer[6].name, "sss");
	dancer[6].sex = 'F';

	strcpy(dancer[7].name, "ddd");
	dancer[7].sex = 'F';

	strcpy(dancer[8].name, "fff");
	dancer[8].sex = 'F';

	strcpy(dancer[9].name, "ggg");
	dancer[9].sex = 'F';


	DancePartner(&dancer[10], num);
	return OK;
}