#include <bits/stdc++.h>
using namespace std;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	
	string str;
	vector<int> z;
	int Case = 0, n, j, k;
	
	while(cin >> str){
		z.clear(); z.resize(str.size()+1);
		z[0] = str[0] - '0';
		for(int i=1; i<str.size(); ++i){
			z[i] = z[i-1] + int(str[i] - '0');
		}
		cout << "Case " << ++Case << ":\n"; 
		
		cin >> n;
		for(int i=0; i<n; ++i){
			cin >> j >> k;
			if(j>k) swap(j,k);
			if(((z[k] - z[j] + str[j] - '0') == 0) | ((z[k] - z[j] + str[j] - '0') == (k-j+1))) cout << "Yes\n";
			else cout << "No\n"; 
		}
	}
	
	return 0;
}

