#include <stdio.h>
#include <stdlib.h>

int main()
{
	int type;
	char char_in_file=NULL;	// for Q1
	char cs1[100], cs2[100], cs3[100];	// for Q2
	char string[100];
	int length=40, read_data_times=1;
	
	printf("請選擇讀檔方式:\n1.用getc()讀取檔案\n2.fscanf()讀取檔案\n3.用fgets()讀取檔案\n4.用fread()讀取檔案\n0.離開");
	scanf("%d", &type);
	
	while(type<0 || type>4)
	{
		printf("請輸入正確數值");
		scanf("%d", &type);
	}
	
	if(type==0)
	return 0;
	
	// Q1
	else if(type==1)
	{
		FILE *file=fopen("File_Example.txt","r");
		
		if(file==NULL){
			printf("file doesn't exist.");
			return 1;
		}	
		else
		{
			do{
				char_in_file=getc(file);
				printf("%c", char_in_file);
			}
			while(char_in_file != EOF);
		}
		
		fclose(file);
		return 0;
	}
	
	// Q2
	else if(type==2)
	{
		FILE *file=fopen("File_Example.txt","r");
		
		if(file==NULL){
			printf("file doesn't exist.");
			return 1;
		}	
		else
		{
			fscanf(file, "%s %s %s", cs1, cs2, cs3);
			printf("%s %s %s", cs1, cs2, cs3);
		}
		
		fclose(file);
		return 0;
	}
	
	// Q3
	else if(type==3)
	{
		FILE *file=fopen("File_Example.txt","r");
		
		if(file==NULL){
			printf("file doesn't exist.");
			return 1;
		}	
		else
		{
			do{
				fgets(string, length, file);
				printf("%s\n", string);
			}while(fgets(string, length, file) != NULL);
		}
		
		fclose(file);
		return 0;
	}
	
	//Q4
	else if(type==4)
	{
		FILE *file=fopen("File_Example.txt","r");
		
		if(file==NULL){
			printf("file doesn't exist.");
			return 1;
		}	
		else
		{
			do{
				int read =fread(string, 1, 20, file);	//1 means for char, 20 means the length(1*20=20bytes)
				string[read]='\0';
				printf("%s", string);
			}while(!feof(file));
		}
		
		fclose(file);
		return 0;
	}	
}
