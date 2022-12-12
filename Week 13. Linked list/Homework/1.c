
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <time.h>


//
typedef struct _NODE
{
	int index ;//debug ��
	int _value ;
	struct _NODE *_next ;
	struct _NODE *_prev ;
}NODE , *LPNODE ;

typedef struct _LINKED
{
	LPNODE _head ;
	LPNODE _tail ;
}LINKED , * LPLINKED ;

// ��l��
void InitRoot(  LPLINKED root )
{
	memset( root , 0 , sizeof( LINKED ));
}
// �إ�
LPNODE newNode( int value )
{
	LPNODE ret = (LPNODE)malloc( sizeof( NODE ));
	memset(ret, 0, sizeof(NODE));
	ret->_value = value ;
	return ret ; 
}

// �[��o�Ӫ��᭱
LPNODE InsertNext(LPLINKED root, LPNODE node, int value)
{
	LPNODE next = newNode( value );
	// �᭱�٦�
	if( node->_next != NULL )
	{
		node->_next->_prev = node ;
		next->_next = node->_next ;

	}
	node->_next = next ;
	next->_prev = node ;
	if( root->_tail == node )
		root->_tail = next ;
	return next ;
}
// �[��o�Ӫ��e��
LPNODE InsertPrev(LPLINKED root, LPNODE node, int value)
{
	LPNODE prev = newNode( value );
	if( node->_prev != NULL )
	{
		node->_prev->_next = prev ;
		prev->_prev = node->_prev ;
	}

	node->_prev = prev ;
	prev->_next = node ;
	if( root->_head == node )
		root->_head = prev ;
	return prev ;
}
//
// �[���
LPNODE InsertToTail( LPLINKED root , int value )
{
	LPNODE node = newNode( value );
	if( root->_head == NULL )
		return root->_head = root->_tail = node ;
	root->_tail->_next = node ;
	node->_prev = root->_tail ;
	root->_tail = node ; 
	return node ;
}

//
// �[���Y
LPNODE InsertToHead( LPLINKED root , int value )
{
	LPNODE node = newNode( value );
	if( root->_head == NULL )
		return root->_head = root->_tail = node ;
	root->_head->_prev = node ;
	node->_next = root->_head ;
	root->_head = node ; 
	return node ;
}

// ����  node
int DeleteNode(  LPLINKED root , LPNODE node )
{
	int retValue = node->_value ;
	LPNODE prev = node->_prev ;
	LPNODE next = node->_next ;
	retValue = node->_value  ;
	if( prev != NULL )
		prev->_next = next ;
	if( next != NULL )
		next->_prev = prev ;

	if( root->_head == node )
		root->_head = node->_next ;
	if( root->_tail == node )
		root->_tail = node->_prev ;
	free( node );
	return retValue ;
}

//
// ������
int DeleteTail( LPLINKED root  )
{
	//
	LPNODE node ;
	int retValue  ;
	//
	if( root->_tail == NULL )
		return 0 ;


	return DeleteNode( root , root->_tail ) ;
}
// �����D 
int DeleteHead( LPLINKED root  )
{
	//
	LPNODE node ;
	int retValue  ;
	//
	if( root->_head == NULL )
		return 0 ;

	return DeleteNode( root , root->_head ) ;
}

//
LPNODE Search( LPLINKED root , int value , int *outIndex )
{

	LPNODE node ;
	int index ;
	// ��ƶq
	node = root->_head ;
	index = 0 ;
	while( node != NULL )
	{
		index ++ ; 
		if( node->_value == value )
		{
			if( outIndex != NULL )
				(*outIndex) = index ; 
			return node ;
		}
		node = node->_next ;
	}

	return NULL ; 
}

// 
// ����
void Reverse( LPLINKED root )
{
	int i ;
	int count ;
	LPNODE node ;
	LPNODE *buf ;
	// ��ƶq
	count = 0 ;
	node = root->_head ;
	while( node != NULL )
	{
		node = node->_next ;
		count ++ ; 
	}

	buf = (LPNODE*)malloc( sizeof( LPNODE ) * count );
	node = root->_head ;
	i = count ;
	while( node != NULL )
	{
		i -- ;
		buf[i] = node ;
		node = node->_next ;
	}
	// ��
	for( i = 0 ; i < count ; ++i )
	{
		if( i == 0 )
			buf[i]->_prev = NULL ;
		else
			buf[i]->_prev = buf[i-1] ;
		if( i < (count-1))
			buf[i]->_next = buf[i+1] ;
		else
			buf[i]->_next = NULL ; 
	}
	root->_head = buf[0] ;
	root->_tail = buf[i-1] ;
	// ����
	free( buf );

}
//
int getValue( const char *str )
{

	char ch[256] ;
	int ret ;
	if( str != NULL )
		printf( str );
	while( 1 )
	{
		fgets( ch , sizeof( ch ) , stdin );
		if( sscanf( ch , "%d" , &ret ) >= 1 )
			break ;
		printf( "enter error\n" );
	}
	return ret ;
}
//
// �e
void printTree( LPLINKED root )
{
	LPNODE node ;
	int i ;
	char ch[7][256] ;
	memset( ch , 0 , sizeof( ch ));
	node = root->_head ;
	i = 0 ;
	while( node != NULL )
	{
		// �e
		sprintf( ch[0] + i , "********\n" );
		sprintf( ch[1] + i , "*      *\n" );
		sprintf( ch[2] + i , "*      *\n" );
		sprintf( ch[3] + i , "*   %d  *\n" , node->_value );
		sprintf( ch[4] + i , "*      *\n" );
		sprintf( ch[5] + i , "*      *\n" );
		sprintf( ch[6] + i , "********\n" );
		i += 7 ; 
		node = node->_next;

	}

	for( i = 0 ; i < 7 ; ++i )
		printf( ch[i] );
	
}
//
void runSearch( LPLINKED root )
{
	char ch[256] ;
	int value ;
	LPNODE node ;
	int index ; 
	// Please enter the value to search :
	value = getValue( "Please enter the value to search : " );
	// %d at %dst node
	node = Search( root , value , &index );
	if( node == NULL )
	{
		printf( "enter value not in the tree" );
		return ;
	}

	printf( "%d at %dst node\n" , value , index );
	while( 1 )
	{
		printf( "Please choose what you want to do at target node : ");
		printf( "1.insert a value to next ");
		printf( "2.insert a value to prev ");
		printf( "3.delete target value ");
		printf( "4.exit\n" );
		ch[0] = 0 ;
		fgets( ch , sizeof( ch ) , stdin );
		switch( ch[0] )
		{
		case '1' :
			value = getValue( "Please enter the value to add : " );
			InsertNext( root , node , value );
			return ;
		case '2' :
			value = getValue( "Please enter the value to add : " );
			InsertPrev( root , node , value );
			return ;
		case '3' :
			DeleteNode( root , node );
			return ;
		case '4' :
			return ;
		default :
			printf( "enter error\n" );
		}
	}
}

// �e
//
int main( const  int argc, const char *argv[])
{
	LINKED root ;
	int N ;
	char ch[256] ;
	int isRun ;
	InitRoot( &root );
	int value ;

	isRun = 1 ;
	while( isRun )
	{
		printf( "Pleas choose what you want to do : ");
		printf( "1.insert to tail ");
		printf( "2.insert to head ");
		printf( "3.delete tail ");
		printf( "4.delete head ");
		printf( "5.reverse ");
		printf( "6.search ");
		printf( "7.Exit\n" );

		ch[0] = 0 ;
		fgets( ch , sizeof( ch ) , stdin );
		switch( ch[0] )
		{
		case '1' :
			value = getValue( "Please enter the value to add : " );
			InsertToTail( &root , value );
			break ;
		case '2' :
			value = getValue( "Please enter the value to add : " );
			InsertToHead( &root , value );
			break ;
		case '3' :
			DeleteTail( &root );
			break ; 
		case '4' :
			DeleteHead( &root );
			break ;
		case '5' :
			Reverse( &root );
			break ;
		case '6' :
			runSearch( &root );
			break ; 
		case '7' :
			isRun = 0 ;
			break ;
		default :
			printf( "enter error" );
		}

		printTree( &root );
		printf( "\n" );

	}


	return 0;
}
