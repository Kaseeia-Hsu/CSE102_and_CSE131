# C Language Design & Experiment (I)

## Week 6

## Array

```c
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, sum = 0, a[5];
    
    for(i=1; i<=5; i++)
    {printf("please enter %d's grade:", i);
    scanf("%d", &a[i-1]);
    sum += a[i-1];}
    
    printf("avg:%d", sum/5);
    return 0;
}
```



```c
int main()
{
    int arr[5]=(5,6,8,3,9);
    int max= 0, mid= 0;
    for(int i=0; i<5; i++)
    {
        if(arr[i]>max)
        {
            mid = max;
            max - arr[i];
        }
        else if(arr[i]>mid)
            mid = arr[i]
    }
    print("%d%d", max, mid);
    return 0;
}
```



```c
int main()
{
    int arr[5]=(20,3,9,7,6);
    int i, j;
    
    for(i=0; i<5; i++)
    {
        printf("%d%d",i, arr[i]);
        for(j=0; j<arr[i]; j++)
            printf("%c", '*');
        printf("\n");
    }
    return 0;
}
```



```c
// a rating system.

#define RESPONSE_SIZE 40
#define FREQUENCY_SIZE 11

int main()
{
    int ans, rating;
    int frequency[FREQUENCY_SIZE]={0};
    int responses[RESPONSE_SIZE]={.....};
    
    for(ans=0; ans<RESPONSE_SIZE; ans++)
    {
        ++frequency[responses[ans]];	// responses[ans(0~39)] can only include 1~10, so we know the times where the value shows up in frequency[1~10].
    }
    
    printf("%s%17s\n","Rating","Frequency");
    for(rating=1; rating<FREQUENCY_SIZE; rating++)
    {
        printf("%d%17d",rating, frequency[rating]);
    }
    return 0;
}
```



```c
int main(void)
{
    char array[5];
    printf("%p\n %p\n %p\n", array &array[0], &array);	// array[0] is a value, while &array[0] is the address of this value where's also the start point of this array, so these 3 elements(address) is all the same.
    return 0;
}
```



You can not endow an array into another like arr1=arr2, you can only endow it by value and value like: arr1[i]=arr2[i].

## Linear Search

Flaw: Inefficient(for it's unsorted, so it's going to run N/2 times in avg.) While binary search is sorted and runs log(n) in avg.



```c
#define SIZE 10
int main()
{
    int search = 0;
    int element = -1;	// if we found the value or not
    int a[SIZE];
    int i, j;
    
    for(i=0; i<SIZE; i++)
        a[i] = 2 * i;
    
    printf("Enter a value");
    scanf("%d", &search);
    for(j=0 j<SIZE; j++)
    {
        if(a[j] == search)
            element = 1;
    }
    if(element != 1)
        printf("We found the value!");
    else
        printf("value not found");
    return 0;
}
```



## Sorting

### Bubble Sort

```c
// 5 3 8 4 6, for each round, there'll be one put into the right position, so it takes n-1 rounds for n elements to sort.

if(a[j]>a[j+1])
{
    temp = a[j];
    a[j] = a[j+1];
    a[j+1] = temp;
}

// Doing swap.
```



```c
int main()
{
    int i;
    int a[SIZE] = {bunch of number...};
    printf("Before arrangement");
    
    for(i=0; i<SIZE; i++)
        printf("%d", a[i]);
   
    int k, j, temp;
    for(k=0; k<SIZE-2; k++)	// For N elements, we do N-1 rounds
        for(j=0; j<SIZE-1-k; j++)	// When k rounds have ended, we only need to count SIZE-1-k elements since k elements have been sorted into the right positions.
            if(a[j]>a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
    printf("After arrangement");
    for(i=0; i<SIZE); i++)
        printf("%d",a[i]);
    
    return 0;
}
```



### Insertion Sort



```c
// 5 3 8 4 6.

temp = a[k];
for(j=k-1; j>=0; j--)	// a[k] comparing with the ones in its left side(k-1~0)
{
    if (a[j] > temp)	// for a[j] is bigger than a[k],
        a[j+1]=a[j];	//	we push p[j] one position toward.
    else
        break;
} 
a[j+1] = temp;	// If a[k] > a[j] and do the break command.
```



### Selection Sort



```c
int k, j, min, temp;

for(k=0; k<SIZE-1; k++)	// In round k.
{
    min = k;
    for(j = k+1; j<SIZE; j++)	// If the right side element is smaller than the left side(a[k]),
        if(a[j]<a[min])
          min = j;	// Set min from k to j.
    
    if(min != k){	//Once the min changed, doing swap.
        temp = a[min];
        a[min]=a[k];
        a[k]=temp;
    }
}
```



### Binary Search



```c
int search;
int data[]=(13 numbers);

scanf("%d", &search);

int low=0, high=13-1;
bool find - false;

while(low<=high)
{
    int mid = (low+high)/2;
    if(data[mid] == search)
    {
        printf("Found it!");
        find = true;
        break;
    }
    else if(data[mid] > search)
        high = mid - 1;
    else if(data[mid] < search)
        low = mid + 1;
}
if(!find)	// find is not true
    printf("can not find the value:(");
return 0;
```



## Size of



```c
int main()
{
    double data[4];
    printf("%d", sizeof(data[0]));	// 8
    printf("%d", sizeof(data));	// 32
    printf("$d", sizeof(data)/sizeof(double));	//4
    
    return 0;
}
```



## Binary Array



```c
int main()
{
    int i, j, score[2][5]
        for(i=0; i<2; i++)
            for(j=0; j<5, j++)
                score[i][j]=0;
}
```



C is row-major



```c
int i, j ,score[2][5];
int sum1=0, sum2=0;

for(i=0; i<2; i++)	// Two rows
    for(j=0; j<5; j++)	// Five grades
    {
        printf("Student %d: Grade %d", i+1, j+1);
        scanf("%d", &score[i][j]);
        if(i==0)	// i = 0 equals to the row of student 1
            sum1 += score[i][j];
        if(i==1)	// Student 2
            sum2 += score[i][j];
    }
printf("The avg grade of student 1 is %d", sum1/5);
printf("The avg grade of student 2 is %d", sum2/5);;
return 0;
```



## String



string is a combination of characters. \0, or non character is the common ending of a string in C language.



```c
// Declaring a string

char text[] = "Hello";
char text[] = {'H','E','L','L','O','\0'};
```



```c
printf("%d", sizeof(text)/sizeof(text[0]));	// Include null, so it's 6
printf("%d",strlen(text));	// 5, ignoring null
```



```c
int main()
{
    char string1[20];
    char string2[]= "string iteral";
    int i;
    printf("enter a string:");
    scanf("%s", string1);	// String1 is an array which is also an address itself.
    
    for(i=0; string1[i] != 0; i++);
    printf("%c", string1[i]);
    
    return 0;
}
```



```c
char month[12][10] = {	// Can store 12 strings, the upmost length of a string is 10(\0 included).
	"January", "February", "March", 
	"April", "May", "June", 
	"July", "August", "September",
 	"October", "November", "december"; 
}
```



### Copy String



```c
char *strcpy(char *dest, const char *src);
// Copy src into dest

char *strncpy(char *dest,const char *src,size_t n );
// Copy the first size_t char src into dest.

strcat(str2,str1);
// Connect str1 after str2.

strncat(str2,str1);
// Same as the strncpy command

strncmp(passwd, buf, 6);
// Comparing a 6 digit string passwd with buff that the user enter.
```



## Random Number



Using random number function rand(), we must use stdlib.h. rand() will give back a number between 0~RAND_MAX.



```c
a = rand() % 10;	//  0~9
a = rand() % 10 +1;	// 1~10
rand() % (maximun - minimun + 1) +minimum;
```

