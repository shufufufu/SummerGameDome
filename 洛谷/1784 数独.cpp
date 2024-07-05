#include <bits/stdc++.h>
using namespace std;
int mp[10][10],vx[10][10],vy[10][10],vc[10][10],flag;
void dfs(int x, int y){
//	if(flag)return ;
	if(x==9){
		for(int i=0 ; i<9 ; i++){
			for(int j=0 ; j<9 ;j++){
				cout << mp[i][j] << " ";			
			}
			cout << endl;
		}
//		flag = 1;
		exit(0);
		return;
	}
	if(y==9){
		dfs(x+1,0);
		return;
	}		
	if(mp[x][y])
		dfs(x,y+1);
	else for(int i=1 ; i<=9 ; i++){
		if( !vx[x][i] && !vy[y][i] && !vc[x/3*3+y/3][i]){
			vx[x][i] = 1;
			vy[y][i] = 1;
			vc[x/3*3+y/3][i] = 1;
			mp[x][y] = i;
			dfs(x,y+1);
			mp[x][y] = 0;
			vx[x][i] = 0;
			vy[y][i] = 0;
			vc[x/3*3+y/3][i] = 0;
		}
	}
}
int main(){
	for(int i=0 ; i<9 ; i++){
		for(int j=0 ; j<9 ;j++){
			cin >> mp[i][j];
			vx[i][mp[i][j]] = 1;
			vy[j][mp[i][j]] = 1;
			vc[i/3*3+j/3][mp[i][j]] = 1;
		}
	}
	dfs(0,0);
	return 0;
}