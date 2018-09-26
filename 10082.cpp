#include <iostream>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	char shift[] = "`1234567890-=QWERTYUIOP[]\ASDFGHJKL;'ZXCVBNM,./";
	string str;
	
	while(1){
		getline(cin, str);
		if(str == "") break;
		for(int i=0; i<str.size(); ++i){
			if(str[i] == ' ') cout << ' ';
			else{
				int j=0;
				while(str[i] != shift[j]) j++;
				cout << shift[j-1];
			}
		}
		cout << '\n';
	}
	
	return 0;
}

