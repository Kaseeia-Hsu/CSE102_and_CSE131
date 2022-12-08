#include <stdio.h>

int main()
{
	// main 和 sub 陣列內為主餐與附餐金額 
	int main[4]={60, 80, 70, 90};
	int sub[3]={30, 40, 40};
	int ice[3]={1, 2, 3};
	int salt[2]={1, 2};
	int i, j, k, h;
	char discount, ans;
	
	printf("請輸入您想點的主食: 1.漢堡 2.潛艇堡 3.沙拉 4.義大利麵\n");
	scanf("%d", &i);
	printf("請輸入您想點的附食: 1.紅茶 2.薯條 3.濃湯\n");
	scanf("%d", &j);
	
	if(j==1){	//若附餐輸入1. 紅茶 
	printf("紅茶的冰塊: 1.正常 2.微冰 3.去冰\n");
	scanf("%d", &k);
	}
	
	if(j==2){	//若附餐輸入2, 薯條 
	printf("薯條鹹度: 1.正常鹽 2.去鹽\n");
	scanf("%d", &h);
	}
	
	printf("請問是否有折扣碼? 若有請輸入折扣碼, 無請輸入(N)\n");
	scanf(" %c", &discount);
	
	printf("您所點的為以下:\n");
	
	if(i>=1 && i<=4)	//判斷客人主餐選擇 
	switch(i){
		case 1:
			printf("漢堡x1\n");
			break;
		case 2:
			printf("潛艇堡x1\n");
			break;
		case 3:
			printf("沙拉x1\n");
			break;
		case 4:
			printf("義大利麵x1\n");
			break;
	}
	
	else{
	printf("輸入有誤!請重試\n");
	return 0;	
	}
	
	if(j>=1 && j<=3)	//判斷客人附餐選擇 
	switch(j){
		case 1:
			printf("紅茶");
			break;
		case 2:
			printf("薯條");
			break;
		case 3:
			printf("濃湯x1");
			break;
	}
	
	else{
	printf("輸入有誤!請重試");
	return 0;	
	}
	
	
	
	if(j==1)	//判斷若客人點了紅茶, 其冰量多寡 
	{
		if(k>=1 && k<=3)
		switch(k){
		case 1:
			printf(" 正常x1\n");
			break;
		case 2:
			printf(" 微冰x1\n");
			break;
		case 3:
			printf(" 去冰x1\n");
			break;
		}
		else
		{
		printf("輸入有誤!請重試");
		return 0;	
		}
	}

	if(j==2)	//判斷若客人點了薯條, 其鹽量多寡 
	{
		if(h>=1 && h<=2)
		switch(h){
		case 1:
			printf(" 正常鹽x1\n");
			break;
		case 2:
			printf(" 去鹽x1\n");
			break;
		}
		else
		{
		printf("輸入有誤!請重試");
		return 0;	
		}
	}
	
	switch(discount){	//判斷是否有折扣碼, 若啟用折扣碼, 且消費過百, 則印出明細金額將打八折 
		case 'e': case 'E':
			{
			if(main[i-1]+sub[j-1]>=100)	//判斷有折扣碼狀況下的消費金額 
				{
				printf("總金額為: %.0f\n", (float)(main[i-1]+sub[j-1])*0.8);
				break;
				}
			else
				{
				printf("總金額為: %d\n", main[i-1]+sub[j-1]);
				break;	
				}
			}
			
		case 'n': case 'N':
			printf("總金額為: %d\n", main[i-1]+sub[j-1]);
			break;
		
		default:{
			printf("折扣碼輸入有誤! 請重試");
			return 0;
		}
	}

	printf("是否正確?\n");	//要求客人確認明細是否正確 
	scanf(" %c", &ans);
	
	switch(ans){
		case 'y': case 'Y':
			printf("確認"); 
			break;
		case 'n': case 'N':
			printf("重試");
			break;
	}
	
	return 0;
}
