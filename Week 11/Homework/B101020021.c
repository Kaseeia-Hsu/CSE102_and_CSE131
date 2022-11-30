#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <time.h>

typedef struct NODE
{
	int value;
	struct NODE *next;
}NODE, *LPNODE;

LPNODE getTail(LPNODE root)
{
	LPNODE node;
	if(root==NULL)
		return NULL;
	node=root;
	while(node->next!=root)	//找尾端 
		node=node->next;

	return node; 
}

LPNODE addNode(LPNODE root, int value)
{
	LPNODE node;
	LPNODE tail;
	node=malloc(sizeof(NODE));
	node->value=value;
	if(root==NULL)	//如果沒有其他node->則next=自己地址 
	{
		node->next=node;
		return node; 
	}
	tail=getTail(root);	//tail=尾端 
	tail->next=node;	//頭尾相連 
	node->next=root;
	return root;
}

LPNODE delNode(LPNODE root, LPNODE delNode)
{
	LPNODE tail;
	tail=getTail(delNode);	//for Example: delNode為3, tail為2, 
	tail->next=delNode->next;	//為刪除Node(3), 2要連到4, 也就是delNode(3)->next(4) 
	if(delNode==root)
	{
		//最後一個
		if(tail==root)
			root=NULL;
		else
			root=root->next;
	}


	return root;

}

LPNODE delAll(LPNODE root)	//刪除stack 
{
	LPNODE node;
	LPNODE next; 
	if(root==NULL)
		return NULL;
	node=root;
	while( node != NULL )
	{
		next=node->next ;
		free(node);
		node=next ;
		if(node==root)
			break ;
	}
	return NULL ;


}

LPNODE stackPush(LPNODE root, LPNODE node)
{
	node->next=root;
	return node;
}

LPNODE stackPop(LPNODE *root)
{
	LPNODE ret=*root;
	if(ret==NULL)
		return NULL;
	(*root)=(*root)->next;
	return ret;
}

void printLinked(LPNODE root) //印出 
{
	LPNODE node;
	node=root;
	if(node==NULL)
	{
		printf("NULL");
		return;
	}
	while(node!=NULL)
	{
		printf("%d", node->value);
		if(node->next!=NULL) 
			printf( "->" );
		else
		{
			printf( "->NULL" );
			return;
		}
		node=node->next;
		if(root==node)	//一回到root, 則停止印出 
			break;

	}
}

int main(const int argc, const char *argv[])
{
	FILE * input;
	LPNODE root;
	LPNODE stackA;
	LPNODE stackB;
	LPNODE node;
	LPNODE temp;
	int value;
	int i;
	int k;
	int runCount;
	int count;
	int ok=0;
	int round;

	input = fopen("test.txt", "r");
	if(input==NULL)	//錯誤處理 
	{
		printf("not open file input.txt\n");

		return 0;
	}

	root=NULL;
	stackA=stackB=NULL;
	count=0;
	
	while(1)	//讀取檔案內容, 並對每一個值做addNode 
	{
		if(fscanf(input, "%d", &value)<1)
			break;
		root=addNode(root, value);
		count++; 
	}
	fclose(input);

	printf("Please enter a value for k : ");
	scanf("%d", &runCount);
	round=0;
	printf("Orignal : ");
	printLinked(root);	//印出original queue 
	printf("\n");
	while(root!=NULL)
	{
		if(root->next==root)	//回到root時則break 
			break; 
		
		for(i=1; i<runCount; ++i)	//為移除第k位數, 做k-1輪root=root->next 
			root=root->next;
		node=root;
		root=delNode(root, node);	//delete node k
		stackA=stackPush(stackA ,node);	//And push it into stackA
		round++;
		printf(" round %d\n", round);
		printLinked(root);
		printf("\n" );

	}
	
	printf("The winner is No.%d\n", root->value);
	
	stackA=stackPush(stackA, root);	//把贏家也push進去 
	
	printf("\nunsorted stack\n");
	printLinked(stackA);
	printf("\n");
	runCount=0;
	while(1)
	{
		if(stackA==NULL)
			break;

		if(stackB==NULL)	// B is empty->directly push in
		{
			node=stackPop(&stackA);
			stackB=stackPush(stackB, node);
		}
		else
		{
			if(stackA->value>stackB->value) //Aval>Bval -> Pop A and Push B 
			{
				node=stackPop(&stackA);
				stackB=stackPush(stackB, node);
			}
			else
			{
				temp=stackPop(&stackA); //Pop A and save it in temp
				
				while(stackB!=NULL)
				{
					if(stackB->value<temp->value)
						break;	//break when Aval > Bval 
					node=stackPop(&stackB);	//Or, when Bval>Aval, pop B and push it back to A
					stackA=stackPush(stackA, node);

				}

				stackB=stackPush(stackB, temp); //最後再把temp push進B 

			}
		}

		runCount++;
		printf("\n第%d輪\n", runCount);
		printf("unsorted stack\n");
		printLinked(stackA);
		printf("\n");
		printf("sorted stack\n");
		printLinked(stackB);
		printf("\n");

	}


	delAll(stackB);

	system("pause");


	return 0;
}
