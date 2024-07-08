#include <cstring>
#include <cctype>
#include <cstdio>

void strlower (char *a) {
	for(int i = 0; a[i]; i ++ ) {
		if(isupper(a[i])) a[i] = tolower(a[i]);
	}
}

int main () {
	
	char destination[1000001], *q, source[11], *p;
	bool flag = false;
	int ans = 0, ans1 = -1;
	
	gets(source);
	gets(destination);
		
	strlower(destination);
	strlower(source);
	
	int len = strlen(source);
	
	p = destination;
	
	for(; q = strstr(p, source); ) {
		if( q != NULL
		&& ( q == destination || *(q - 1) == ' ') 
		&& ( *(q + len) == '\0' || *(q + len) == ' ' ) ) {
			ans ++ ;
			if(flag == false) {
				flag = true;
				ans1 = q - destination;
			}
		}
		p = q + len;
	}
	
	if(flag == true)
		printf("%d %d" , ans, ans1);
	else 
		printf("%d", ans1);
	
	return 0;
}