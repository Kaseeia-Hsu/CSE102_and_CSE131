
#if !defined(_CRT_SECURE_NO_WARNINGS)
#define _CRT_SECURE_NO_WARNINGS 
#endif 



/*/// ------------------------------------------------------------------------------------

RUULLDLUR
LDLDDDURRRD
RLLUUDDURRDL
UUUUUDDDDD
LRLRLRLR
RDLUULDR
RLUDDD
LLLLLLLLL
DLURRDLU
RRRLLDRUUDL
DLLURURD
URRLLDDULR
LULUURRDDL
LUULRDRD
LLLUURDLUU
DRRULRRULRDLLRDLLU
UURDLLLLDDLURRR
DDDLLURRDULLDRRUU
UUUDRRLLUR
LLDRUUR
DLDLDLRURURU



/*/// ------------------------------------------------------------------------------------


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



//
int main()
{
	FILE *input ;
	FILE *output ;
	unsigned int buf[2] ;
	char ch ;
	int k ;
	int count ;

	input = fopen( "Test.txt" , "r" );
	output = fopen( "7-2_Result.txt" , "w" ); ;
	buf[0] = buf[1] = 0 ;

	k = 0 ;
	while( 1 )
	{

		ch = 0 ; // NULL

		if( 0 == fscanf( input , "%c" , &ch ))
			break ;
		if( ch == 0 )
			break ;
		// 印出
		if( ch == '\n' )
		{
			k ++ ;
			if(( buf[0] == 0 )&&( buf[1] == 0 ))
			{
				printf( "第%d個字串：True\n" , k );
				fprintf( output , "第%d個字串：True\n" ,k);
			}else
			{
				printf( "第%d個字串：False\n" , k );
				fprintf( output , "第%d個字串：False\n" , k );
			}
			buf[0] = buf[1] = 0 ;
		}
		
		else
		{
			if( ch == 'L' )
				buf[0] ++ ;
			else if(ch == 'R' )
				buf[0] -- ;
			else if(ch == 'D' )
				buf[1] ++ ;
			else if(ch == 'U' )
				buf[1] -- ;
		}
	}
	//
	// 最後一個
	k ++ ;
	if(( buf[0] == 0 )&&( buf[1] == 0 ))
	{
		printf( "第%d個字串：True\n" , k );
		fprintf( output , "第%d個字串：True\n" ,k);
	}else
	{
		printf( "第%d個字串：False\n" , k );
		fprintf( output , "第%d個字串：False\n" , k );
	}


	fclose( input );
	return 0 ;
}
