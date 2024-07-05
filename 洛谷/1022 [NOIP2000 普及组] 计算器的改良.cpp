#include<bits/stdc++.h>
using namespace std;

int main()
{
		char c,x;//x记录未知数
		int deng = 1, jiaj = 1,s = 0,kx = 0, k0 = 0;
		while(cin>>c)
		{
			if(c >= 'a' && c <= 'z')
			{
				x = c;
				if(s == 0)
				{
					s = 1;
				}
				kx += s * deng * jiaj;
				s = 0; 
			}
			if(c >= '0' && c <= '9')
			{
				s = s * 10 + c - '0';
			}
			if(c == '=')
			{
				k0 += s * deng * jiaj;
				s = 0;
				deng = -1;
				jiaj = 1;
			}
			if(c == '+')
			{
				k0 += s * deng * jiaj;
				s = 0;
				jiaj = 1;
			}
			if(c == '-')
			{
				k0 += s * deng * jiaj;
				s = 0;
				jiaj = -1;
			}
		}
		k0 += s * deng * jiaj;
		cout<<fixed<<setprecision(3)<<x<<"="<<-1.0 * k0 / kx;
		return 0;
}