#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char pic[101][101];

typedef struct Node_s{
	int val;
	struct Node *next
}Node;

Node *top = NULL;

void push(int value){
	Node *newp = malloc(sizeof(Node));
	newp->val = value;
	newp->next = top;
	top = newp;
}

int pop(){
	Node *temp;
	int value;
    temp = top;
    value = temp->val;
    free(temp);
    return value;
}

void bubble(int x[], int y[], int);
void swap(int *, int *);
void selection(int x[], int y[], int);

int main(){
	int i;
	FILE *file = fopen("coordinate.txt", "w");
	srand(5);
	
	for(i=0; i<50; i++){
		push(rand()%101 -50);
		fprintf(file, "%d", pop());
		push(rand()%101 -50);
		fprintf(file, " %d\n", pop());
	}
	fclose(file);
	
	//b
	
	file = fopen("coordinate.txt", "r");
	
	int x[50], y[50];
	for(i=0; i<50; i++){
		fscanf(file, "%d %d", &x[i], &y[i]);
	}
	fclose(file);
	
	int type;
	printf("1 or 2");
	scanf("%d", &type);
	
	while(type>2 || type<1){
		printf("again!");
		scanf("%d", &type);
	}
	
	if(type==1){
		bubble(x, y, 50);
	}
	
	if(type==2){
		selection(x, y, 50);
	}
	
	file = fopen("coordinate.txt", "w");
	
	for(i=0; i<50; i++){
		fprintf(file, "%4d %4d\n", x[i], y[i]);
	}
	fclose(file);
	
	memset(pic, ' ',sizeof(pic));
	
	int Xmax=x[0], Xmin=x[0];
	int Ymax=y[0], Ymin=y[49];
	
	for(i=0; i<50; i++){
		if(x[i]>Xmax){
			Xmax=x[i];
		}
		else if(x[i]<Xmin){
			Xmin=x[i];
		}
	}
	
	int area = (Ymax-Ymin)*(Xmax-Xmin);
	printf("area=%d, Xmax=%d, Xmin=%d, Ymax=%d, Ymin=%d", area, Xmax, Xmin, Ymax, Ymin);
	
	for(i=Xmin; i<=Xmax; i++){
		pic[50-Ymax][50+i]='-';
		pic[50-Ymin][i+50]='-';
	}
	
	for(i=Ymax; i>=Ymin; i--){
			pic[50-i][Xmax+50]='|';
			pic[50-i][Xmin+50]='|';
	}
	
	for(i=0; i<101; i++){
		pic[50][i]='-';
		pic[i][50]='|';
	}
	
	for(i=0; i<50; i++){
		pic[50-y[i]][50+x[i]]='*';
	}
	
	pic[50][100]='>';
	pic[0][50]='^';
	pic[49][49]='0';
	
	for(i=-50; i<=50; i+=10){
		if(i!=0){
			sprintf(&pic[49][i+50], "%d", i);
			if(i<0)
			sprintf(&pic[i+50][52], "%d", abs(i));
			else if(i>0)
			sprintf(&pic[i+50][52], "%d", 0-i);
		}
	}
	
	int g;
	printf("\n");
	
	for(i=0; i<101; i++){
		for(g=0; g<101; g++){
			printf("%c", pic[i][g]);
		}
		printf("\n");
	}
}

void swap(int *fir, int *sec){
	int temp;
	temp = *fir;
	*fir = *sec;
	*sec = temp;
}

void bubble(int x[], int y[], int size){
	int i;
	
	if(size==1){
		return;
	}
	
	for(i=0; i<size-1; i++){
		if(y[i]<y[i+1]){
			swap(&y[i], &y[i+1]);
			swap(&x[i], &x[i+1]);
		}
		else if(y[i]==y[i+1] && x[i]>x[i+1]){
			swap(&x[i], &x[i+1]);
		}
	}
	
	bubble(x, y, size-1);
}

void selection(int x[], int y[], int size){
	int i, j, min;
	
	for(i=0; i<size-1; i++){
		min = i;
		
		for(j=i+1; j<50; j++){
			if(y[min]<y[j]){
				min = j;
			}
			
			else if(y[min]==y[j] && x[min]>x[j]){
				min = j;
			}
		}
		
		if(min != i){
			swap(&y[min], &y[i]);
			swap(&x[min], &x[i]);
		}
	}
}
