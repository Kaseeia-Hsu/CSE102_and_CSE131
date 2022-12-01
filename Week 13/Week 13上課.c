struct node
{
	int data;
	struct *next;
}

insert(last, value)
{
	struct node *next;
	struct node *current = last; //從最後一個開始找 
	
	new = malloc(sizeof(struct node))
	new->data = value;
	new->next = NULL;

	//做好了要插到甚麼位置?
	//插入之前linked list由小排到大
	
	//特殊情況：插入者插入前linked list原本是空的
	if(last == NULL)
	{
		last = new;
		return;
	} 
	
	//特殊情況：插入者插入前linked list只有一個節點 
	if(last->next == NULL)
	{
		if(new->data > last->data)
			last->next = new;	
		
		else
		{
			new->next = last;
			last = new;
		}
	}
	
	//特殊情況：插入者比現在最小的還小 (min)
	if(new->data < last->data)
	{
		new->next = last; 
		last = new;
	}
 
	//current拜訪的現在這個比我小，下一個比我大，那我就插在他們倆個中間 
	while(!((current->data < new->data) && (current->next->data > new->data)))
	//Fig 1.1 //當找不到上述狀條件時，就要繼續
	{
		current = current->next; //移到下一個繼續
		//特殊情況：插入者比現在最大的還大(max) 
		if(current->next == NULL) //已到達最大值
			break; //遇到了就跳出，避免再進入while loop 
	}
	
	//插進去之後要建立哪些連結? //Fig 1.2 
	/*Link I*/new->next = current->next;
	/*Link II*/current->next = new; 
	//順序對調  Fig 1.3 II先做、I其次 
} 

//告訴他要到哪個linked list裡面找哪個值
//以指標型態傳值(住址)  //Why?
structnode *search(last, key) 
{
	struct node *current = last;
	while((current<>NULL) && (current->data != key)) //不能調換  
		current = current->next;  //沒有找光、找不到 的時候要繼續找
	
	return current; 
}

delete(last, key)
{
	//檢查linked list是否為空
	if(last == NULL)
		return;
		
	//呼叫search 
	struct node *found = search(last, key); //找到了就是該節點的住址，未找到則為空
	if(found = NULL)
		printf("NULL");
	struct node *current = last;
	
	while(current->next != found)
		current = current->next;

	//邊緣狀況 
	//delete最小值 
	//delete最大值
	//linked list內只有一個，刪完會變成空的
	//linked list內只有兩個 
	//刪除 
	current->next = found->next; //Fig 2.2
	free(found);
	
	//這個超級麻煩所以要介紹下一種叫做Binary 
}

//Binary雖然比較方便但代價是要付出很大的記憶體空間 
//其實Array才是最快的可是做起來很麻煩

//如果前後都要得付出超大的代價 記五個資料要花(4*5)*2=40bytes 
 
struct node
{
	struct node *back;
	int data;
	struct node *front;
	//Fig 3.1 是由三個房子組成的 
}

insert(head, tail, value)
{
	//記得要地&裝潢 
	new = malloc(sizeof(structnode));
	new->back = NULL;
	new->front = NULL;
	new->data = value;
	
	struct node *current = tail;
	while(!((current->data < new->data) && (current->front->data > new->data))) //Fig 3.2 
		current = current->front; //如果不是a<x<a+1的情況則繼續找 
	
	//Fig 3.2	
	//先建立跟new有關的房子比較容易 
	/*I*/new->back = current;
	/*II*/new->front = current->front; //房間! Fig 3.2.2 
	/*III*/current->front->back = new; //注意3、4位置不可對調 如果放在IV會先改變new 
	/*IV*/current->front = new;
}




 
 
