#include <stdio.h>  
#include <math.h>  
double s = 0,x = 0.5,jc = 1,trem = 0;
  
void jcjs(double p);

int main()
{
	s = x;
	jcjs(1);
	printf("%llf",s);
	return 0;
}

void jcjs(double p)
{	
	if(p >= 10)
	{
		return ;
	}

	 jc *= p;
	
	trem = (pow(-1,p)*pow(x,p*2+1))/((p*2+1)*jc);
	s += trem;	
	jcjs(p+1);
}