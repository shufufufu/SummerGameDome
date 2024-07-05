#include <iostream>
using namespace std;
struct MyStruct
{
	string a;
	int b, c, d;
	int sum = 0;
}q[1005];
int main()
{
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> q[i].a >> q[i].b >> q[i].c >> q[i].d;
	}
	for (int i = 0; i < n; i++)
	{
		q[i].sum =q[i].b + q[i].c + q[i].d;
	}
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		if (q[i].sum > max)
			max = q[i].sum;
	}
	for (int i = 0; i < n; i++)
	{
		if (q[i].sum == max)
		{
			cout << q[i].a << " " << q[i].b << " " << q[i].c << " " << q[i].d << endl;
			return 0;
		}
	}
}