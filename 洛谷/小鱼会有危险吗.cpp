#include <bits/stdc++.h>
using namespace std;

int main()
{
    double x = 0, s = 0, j = 0, t = 0;
    cin >> x >> s;
    for (double i = 0; i < 100; i++)
    {
        j = j + 7 * pow(0.98, i);
        if (j > x - s )
        {
            t = i;
            break;
        }
    }

    if (j > x + s )
    {
        cout << "n";
    }

    if (j < x + s )
    {
        j = j + 7 * pow(0.98, (t + 1));
        if (j < x + s )
        {
            cout << "y";
        }
        else
        {
            cout << "n";
        }
    }
    
    if(x<s&&x+s>=7)
	{
    	cout << "y";	
	}

    return 0;
}

