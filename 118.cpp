#include <bits/stdc++.h>
using namespace std;

bool out_of_border(int x, int y, int bx, int by){
	return (x < 0 | x > bx | y < 0 | y > by);
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie();
	
	int bx, by;
	int move[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
	bool mark[50+1][50+1];
	
	memset(mark,sizeof mark,false);
	
	cin >> bx >> by;
	
	int x, y, f, nx, ny;
	char facing;
	string command;
	
	while(cin >> x >> y >> facing){
		cin >> command;
		
		switch(facing){
			case 'N': f = 0; break;
			case 'E': f = 1; break;
			case 'S': f = 2; break;
			case 'W': f = 3; break;
		}
		
		bool lost = false;
		
		for(auto c:command){
			switch(c){
				case 'L': f = (f - 1 + 4) % 4; break;
				case 'R': f = (f + 1 + 4) % 4; break;
				case 'F':
					nx = x + move[f][0];
					ny = y + move[f][1];
					
					if(out_of_border(nx,ny,bx,by)){
						if(!mark[x][y]){
							lost = true;
							mark[x][y] = true;
						}
					}
					else{
						x = nx;
						y = ny;
					}
					break;
			}
			if(lost) break;
		}
		switch(f){
			case 0: facing = 'N'; break;
			case 1: facing = 'E'; break;
			case 2: facing = 'S'; break;
			case 3: facing = 'W'; break;
		}
		cout << x << ' ' << y << ' ' << facing;
		if(lost) cout << " LOST";
		cout << endl;
	}

	return 0;
}

