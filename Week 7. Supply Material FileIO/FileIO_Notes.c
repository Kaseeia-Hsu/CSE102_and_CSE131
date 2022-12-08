#include <stdio.h>

/*
-----------------------------------------------------------------------
fprintf
1. Using a pointer to point out the file
2. Using "fopen" to open the file
3. Using "fprintf" to print what you want(format/content) into the file
4. Using "fclose" to close the file
-----------------------------------------------------------------------
*/

    int main()
{
//write a file
    printf("Write a file!");
    int a=0x31323334, b=2, c=100, d=10;

//write into a file
    FILE *text = fopen("text.txt","w");
    fprintf(text, "%d%d%d%d\n", a, b, c, d);
    fclose(text);
}

/*
----------------------------------------------------------------------
fwrite
1. Using a pointer to point out the file
2. Using "fopen" to open the file
3. Using "fwrite" to print what you want(format/content) into the file
4. Using "fclose" to close the file
----------------------------------------------------------------------
*/

int main()
{
//write binary file
    printf("Write a binary file!");
    int a=0x31323334, b=2, c=100, d=10;

//write into a file
    FILE *binary = fopen("text2.sav","wb"); //wb means binary write
    fwrite(&a, sizeof(a), 1, binary);   //1 means print one time into binary
    fclose(binary);
}

int main()
{
//write an array into a text file
    printf("write an array into a text file");
    int a[5]={0,1,2,3,4};
    int i;

//write into a file
    FILE *array = fopen("text3.txt", "w");
    for(i=0; i<sizeof(a)/sizeof(a[0]); i++) //sizeof(a) means 20x4=80byte/4byte
    fprintf(array, "%d\t", a[i]);
    fclose(array);
}

/*
---------------------------------------------
fread/fscanf
1. Using "fopen" to open the file
2. Using "fread"(for bin)/ "fscanf"(for txt)
3. Using "fclose" to close the file
---------------------------------------------
*/

int main()
{
    printf("read a text file!");
    int a[20]={0};
    int i;

//read a text file
    FILE *text = fopen("text4.txt", "r");
    for(i=0; i<=19; i++)
    fscanf(text, "%d", &a[i]);  //scan original file(should be from 1~20) into a[i]
    fclose(text);

//print array out
    for(i=0; i<=19; i++)
    printf("%d",a[i]);  //print out a[i] after the file had been scanned(stored) in it
}

/*
---------------
Conclusion now
---------------
*/

    char str[30]={'\0'}, str2[30]={'\0'}
    FILE *pointer = fopen("nameof.txt","w");
    fprintf(pointer, "%s", str);
    fscanf(pointer,"%s", str2);
    fclose(pointer);

/*
----------------
fputs and fgets
----------------
*/

    FILE *pointer = fopen("nameof.txt","r");
    char str[100]={'\0'};

    fgets(str, 20, pointer);    //from pointer, we take 20 characters out, and get it into str string
    puts(str);  //just like printf

    char string[]= "test";
    FILE *pointer = fopen("nameof.txt", "w");
    fputs("hello world\n", pointer);    //print these words into pointer
    fputs(string, pointer); //print string("test") into pointer

/*
---------------------
characters and string
---------------------
*/

    char string1[] = {'h','e','l','l','o'}; //This is characters
    char string2[]="Hello"; //This is a string, will add a \0 in the end(length++)
