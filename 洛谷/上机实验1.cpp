#include<stdio.h>
#include<stdlib.h>

char month[12][20]={"JANUARY","FEBRUARY","MARCH","APRIL","MAY","JUNE","JULY","AUGUST","SEPTEMBER","OCTOBER","NOVEMBER","DECEMBER"};//月份的名字
int day1[12]={31,28,31,30,31,30,31,31,30,31,30,31};//每个月份的天数
int Day(int year, int month, int day) 
{  
    if (month < 3) {  
        month += 12;  
        year--;  
    }  
    int h = (day + 2 * month + 3 * (month + 1) / 5 + year + year / 4 - year / 100 + year / 400) % 7;  
    return h;  
}  
bool is(int n){
	if((n%4==0&&n%100!=0)||(n%400==0)){
		return 1;
	}
	else{
		return 0;
	}	
}

int main(int argc, char *argv[])
{
	if(argc!=3)
	{
	printf("参数太少或者太多,请重试\n");
	return 0;
	}
	int y= atoi(argv[2]);
	if(is(y)){
		day1[1]++;
	}
	
	for(int i=1;i<=12;i++)
	{
		printf("               =====%s=====             \n",month[i-1]);
		printf("Sun\tMon\tTue\tWed\tThur\tFri\tSat\n");
		int t = Day(y,i,1);//该月的第一天是星期几
		t++;
		for(int k = 1; k <= t; k++)
		{
			if(t == 7)
			{
			t-=7;
			break;
			}
			printf("\t");
		}
		for(int j = 1; j <= day1[i-1]; j++)
		{
			if(t % 7 == 0&&t!=0)
			{
				printf("\n");
			}
			printf("%2d\t",j);
			t++;
		}
		printf("\n");
	}


	return 0;
	
}