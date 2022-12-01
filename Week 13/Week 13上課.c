struct node
{
	int data;
	struct *next;
}

insert(last, value)
{
	struct node *next;
	struct node *current = last; //�q�̫�@�Ӷ}�l�� 
	
	new = malloc(sizeof(struct node))
	new->data = value;
	new->next = NULL;

	//���n�F�n����ƻ��m?
	//���J���elinked list�Ѥp�ƨ�j
	
	//�S���p�G���J�̴��J�elinked list�쥻�O�Ū�
	if(last == NULL)
	{
		last = new;
		return;
	} 
	
	//�S���p�G���J�̴��J�elinked list�u���@�Ӹ`�I 
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
	
	//�S���p�G���J�̤�{�b�̤p���٤p (min)
	if(new->data < last->data)
	{
		new->next = last; 
		last = new;
	}
 
	//current���X���{�b�o�Ӥ�ڤp�A�U�@�Ӥ�ڤj�A���ڴN���b�L�̭ǭӤ��� 
	while(!((current->data < new->data) && (current->next->data > new->data)))
	//Fig 1.1 //��䤣��W�z������ɡA�N�n�~��
	{
		current = current->next; //����U�@���~��
		//�S���p�G���J�̤�{�b�̤j���٤j(max) 
		if(current->next == NULL) //�w��F�̤j��
			break; //�J��F�N���X�A�קK�A�i�Jwhile loop 
	}
	
	//���i�h����n�إ߭��ǳs��? //Fig 1.2 
	/*Link I*/new->next = current->next;
	/*Link II*/current->next = new; 
	//���ǹ��  Fig 1.3 II�����BI�䦸 
} 

//�i�D�L�n�����linked list�̭�����ӭ�
//�H���Ы��A�ǭ�(��})  //Why?
structnode *search(last, key) 
{
	struct node *current = last;
	while((current<>NULL) && (current->data != key)) //����մ�  
		current = current->next;  //�S������B�䤣�� ���ɭԭn�~���
	
	return current; 
}

delete(last, key)
{
	//�ˬdlinked list�O�_����
	if(last == NULL)
		return;
		
	//�I�ssearch 
	struct node *found = search(last, key); //���F�N�O�Ӹ`�I����}�A�����h����
	if(found = NULL)
		printf("NULL");
	struct node *current = last;
	
	while(current->next != found)
		current = current->next;

	//��t���p 
	//delete�̤p�� 
	//delete�̤j��
	//linked list���u���@�ӡA�R���|�ܦ��Ū�
	//linked list���u����� 
	//�R�� 
	current->next = found->next; //Fig 2.2
	free(found);
	
	//�o�ӶW�ų·ЩҥH�n���ФU�@�إs��Binary 
}

//Binary���M�����K���N���O�n�I�X�ܤj���O����Ŷ� 
//���Array�~�O�̧֪��i�O���_�ӫܳ·�

//�p�G�e�᳣�n�o�I�X�W�j���N�� �O���Ӹ�ƭn��(4*5)*2=40bytes 
 
struct node
{
	struct node *back;
	int data;
	struct node *front;
	//Fig 3.1 �O�ѤT�өФl�զ��� 
}

insert(head, tail, value)
{
	//�O�o�n�a&���C 
	new = malloc(sizeof(structnode));
	new->back = NULL;
	new->front = NULL;
	new->data = value;
	
	struct node *current = tail;
	while(!((current->data < new->data) && (current->front->data > new->data))) //Fig 3.2 
		current = current->front; //�p�G���Oa<x<a+1�����p�h�~��� 
	
	//Fig 3.2	
	//���إ߸�new�������Фl����e�� 
	/*I*/new->back = current;
	/*II*/new->front = current->front; //�ж�! Fig 3.2.2 
	/*III*/current->front->back = new; //�`�N3�B4��m���i��� �p�G��bIV�|������new 
	/*IV*/current->front = new;
}




 
 
