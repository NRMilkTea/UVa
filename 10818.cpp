#include <bits/stdc++.h>
using namespace std;

#define io ios::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

int move[4][2] = {{1,0},{-1,0},{1,0},{0,-1}};
char map[20][20];
int sx, sy;

int main(){ io;
	
	int r, c;
	string str;
	
	while(cin >> r >> c){
		if(r == 0 && c == 0) break;
		
		//read the map
		for(int i=0; i<r; ++i){
			cin >> str;
			for(int j=0; j<c; ++j){
				map[i][j] = str[j];
				if(map[i][j] == 'S'){
					sx = i; sy = j;
				}
			}
		}
		
		
	}

	return 0;
}
