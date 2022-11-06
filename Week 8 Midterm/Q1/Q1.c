/*
 *
 *
 *
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <time.h>


int main( const  int argc, const char *argv[])
{
	int srcMat[16][16] ;
	double kernel[3][3] ;
	double v;
	int ibaisMat[14][14] ;

	FILE *file ;
	int i , k ;
	int ii , kk ;

	srand(5);
	file = fopen( "Matrix.txt" , "w" );
	printf( "input:\n\n" );
	for( i = 0 ; i <16 ; ++i )
	{
		for( k = 0 ; k < 16 ; ++k )
		{
			srcMat[i][k] = (rand()%21 )- 10 ; // -10 ¨ì 10
			fprintf( file , " %4d" , srcMat[i][k] );
			printf(  " %4d" , srcMat[i][k] );
		}
		fprintf( file , "\n");
		printf( "\n");
	}
	fclose( file );
	//
	// kernel.txt
	file = fopen( "kernel.txt" , "r" );
	for( i = 0 ; i <3 ; ++i )
		for( k = 0 ; k < 3 ; ++k )
			fscanf( file , "%lf" , &kernel[i][k] );
	fclose( file );

	//
	// baisMat
	file = fopen( "bais.txt" , "w" );

	printf( "\nbais:\n\n" );
	for( i = 0 ; i <14 ; ++i )
	{
		for( k = 0 ; k < 14 ; ++k )
		{
			ibaisMat[i][k] = 1 ;
			fprintf( file , " %4d" , ibaisMat[i][k]);
			printf(  " %4d" , ibaisMat[i][k]);

		}
		fprintf( file , "\n");
		printf( "\n");

	}
	fclose( file );

	// Convolution :
	file = fopen( "conv.txt" , "w" );
	printf( "\nConvolution :\n\n" );
	for( i = 0 ; i <14 ; ++i )
	{
		for( k = 0 ; k < 14 ; ++k )
		{
			v = 0 ;
			for( ii = 0 ; ii < 3 ; ++ii )
				for( kk = 0 ; kk < 3 ; ++kk )
					v += srcMat[i+ii][k+kk] * kernel[ii][kk] ;
			// ©ñ
			ibaisMat[i][k] += ((int)( v + 0.5 ));
			fprintf( file , " %4d" , ibaisMat[i][k]);
			printf(  " %4d" , ibaisMat[i][k]);
		}
		fprintf( file , "\n");
		printf( "\n");
	}


	// Convolution :
	file = fopen( "7-1_Result.txt" , "w" );
	printf( "\nResult :\n\n" );
	for( i = 0 ; i <14 ; ++i )
	{
		for( k = 0 ; k < 14 ; ++k )
		{
			// ©ñ
			if(  ibaisMat[i][k] < 0 )
				ibaisMat[i][k] = 0 ;
			fprintf( file , " %4d" , ibaisMat[i][k]);
			printf(  " %4d" , ibaisMat[i][k]);
		}
		fprintf( file , "\n");
		printf( "\n");
	}
	return 0;
}



