#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char pic[101][101];

struct Node{
	int val;
	struct Node *ptr;
};

struct Node *top=NULL;

void push(int value){
	struct Node *newp;
	newp= malloc(sizeof(struct Node));
	newp->val=value;
	newp->ptr=top;
	top=newp;
}

int pop(){
	struct Node *temp;
	int value;
	temp=top;
	value=temp->val;
	free(temp);
	return value;
}

void bubble(int x[], int y[], int);
void swap(int *, int *);
void selection(int x[], int y[], int);

int main(){
	
	int x[50], y[50];
	FILE *file = fopen("coordinate.txt", "w");
	srand(5);
	
	int i;
	for(i=0; i<50; i++)
	{
		int xcord= rand()%41+0;
		int ycord=rand()%41+0;
		push(xcord);
		fprintf(file, "%d", pop());
		push(ycord);
		fprintf(file, " %d\n", pop());
	}
	fclose(file);
	
	//B
	
	file = fopen("coordinate.txt", "r");
	
	for(i=0; i<50; i++)
	{
		fscanf(file, "%d %d", &x[i], &y[i]);
	}
	fclose(file);
	
	int type;
	
	printf("請輸入要使用的排序法:");
	scanf("%d", &type);
	
	while(type>2 || type<1){
	printf("請輸入要使用的排序法:");
	scanf("%d", &type);	
	} 
	
	if(type==1){
		bubble(x, y, 50);
	}
	
	if(type==2){
		selection(x, y, 50);
	}
		
	//C
	
	int Ymax=y[0];
	int Ymin=y[49];
	int Xmax=x[0];
	int Xmin=x[0];
	
	for(i=1; i<50; i++)
	{
		if(x[i]<Xmin){
			Xmin=x[i];
		}
		else if(x[i]>Xmax){
			Xmax=x[i];
		}
	}
	
	int area=(Ymax-Ymin)*(Xmax-Xmin);
	
	printf("面積為%d", area);
	
	file = fopen("coordinate.txt", "w");
	for(i=0; i<50; i++)
	{
		fprintf(file, "%d %d\n", x[i], y[i]);
	}
	fclose(file);
	
	//D
	memset(pic, ' ', sizeof pic);
	
	for(i=Xmin; i<=Xmax; i++){
		if(Ymax>=0)
		pic[50-Ymax][i+50]='-';
		else
		pic[50+Ymax][i+50]='-';
		
		if(Ymin>=0)
		pic[50-Ymin][i+50]='-';
		else
		pic[50+Ymin][i+50]='-';
	}
	
	for(i=Ymin; i<=Ymax; i++){
		if(i>=0){
			pic[50-i][Xmin+50]='|';
			pic[50-i][Xmax+50]='|';			
		}
		else{
			pic[50+i][Xmin+50]='|';
			pic[50+i][Xmax+50]='|';				
		}
	}
	
	for(i=0; i<101;	i++){
		pic[51][i]='-';
		pic[i][51]='|';	
	}
	
	pic[51][100]='>';
	pic[0][51]='^';
	pic[49][49]='0';
	
	for(i=0; i<50; i++){
		if(y[i]>=0)
		pic[50-y[i]][x[i]+50]='*';
		else
		pic[50+y[i]][x[i]+50]='*';
	}

	printf("\n");
	
	for(i=-50; i<=50; i+=10){
		if(i!=0){
			sprintf(&pic[49][i+50], "%d", i);
			sprintf(&pic[i+50][52], "%d", i);
		}
	}

	int g;
	
	for(i=0; i<=100; i++){
		for(g=0; g<=100; g++){
			printf("%c", pic[i][g]);
		}
		printf("\n");
	}
}

void swap(int *fir, int *sec){
	int temp;
	temp=*fir;
	*fir=*sec;
	*sec=temp;	
}

void bubble(int x[], int y[], int size){
	int i;
	
	if(size==1)
	return;
	
	for(i=0; i<size-1; i++){
		if(y[i+1]>y[i]){
			swap(&y[i+1], &y[i]);
		}
		
		else if(y[i+1]==y[i] && x[i]>x[i+1]){
			swap(&x[i], &x[i+1]);
		}
	}
	
	bubble(x, y, size-1);
}

void selection(int x[], int y[], int size){
	int i, j;
	for(i=0; i<size-1; i++){
		int min=i;
		for(j=i+1; j<50; j++){
			if(y[min]<y[j]){
				min=j;
			}
			
			else if(y[min]==y[j] && x[min]>x[j]){
				min=j;
			}
		}
		
		if(min != i){
			swap(&y[min], &y[i]);
			swap(&x[min], &y[i]);
		}
	}
}
