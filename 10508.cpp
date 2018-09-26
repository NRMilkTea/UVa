#include <bits/stdc++.h>
using namespace std;

#define io ios::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

inline int diff(string a, string b, int size){
	int d = 0;
	for(int i=0; i<size; ++i) if(a[i] != b[i]) ++d;
	return d;
}

int main(){io;
	
	int n, m;
	vector<string> str;
	string s;
	
	while(cin >> n >> m){
		str.resize(n);
		
		cin >> str[0];
		cin >> str[n-1];
		for(int i=2; i<n; ++i){
			cin >> s;
			str[diff(s, str[0], m)] = s;
		}
		
		for(int i=0; i<n; ++i){
			cout << str[i] << endl;
		}
	}

	return 0;
}

