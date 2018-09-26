#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string str;
	int count, beat;
	
	while(cin >> str){
		if(str == "*") break;
		count = 0;
		beat = 0;
		for(int i=0; i<str.size(); ++i){
			switch(str[i]){
				case 'W':
					beat += 64;
					break;
				case 'H':
					beat += 32;
					break;
				case 'Q':
					beat += 16;
					break;
				case 'E':
					beat += 8;
					break;
				case 'S':
					beat += 4;
					break;
				case 'T':
					beat += 2;
					break;
				case 'X':
					beat += 1;
					break;
				case '/':
					if(beat == 64) count++;
					beat = 0;
					break;
			}
		}
		cout << count << endl;
	}
	
	return 0;
}

