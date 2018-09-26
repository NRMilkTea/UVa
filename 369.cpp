#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	unsigned long long int n, m, c;
	
	while(cin >> n >> m){
		if(n == 0 && m == 0) break;
		c=1;
		for(int i=0; i<m; i++){
			c=c*(n-i)/(i+1);
		}
		cout << n << " things taken " << m << " at a time is " << c << " exactly." << endl;
	}
	
	
	return 0;
}

