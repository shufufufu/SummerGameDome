#include <iostream>
int main()
{
	using namespace std;
	int a = 1 , b = 1;
	char v;
	while ( (v = cin.get() ) != '\n') a *= v - 'A' + 1;
	while ( (v = cin.get() ) != '\n') b *= v - 'A' + 1;
	if (a % 47 == b % 47) cout << "GO";
	else cout << "STAY";
	return 0;
}
