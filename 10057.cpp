#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, a;
	vector<int> num;
	while(cin >> n){
		num.clear();
		for(int i=0; i<n; i++){cin >> a; num.push_back(a);}
		sort(num.begin(), num.end());
		
		
		int n1 = num[((n-1) >> 1)], n2 = num[((n-1) >> 1)+ 1];
		cout << num[((n-1) >> 1)] << ' ';//print answers
		if(n&1){
			cout << upper_bound(num.begin(), num.end(), n1)
				  - lower_bound(num.begin(), num.end(), n1) << " 1\n";
		}
		else{
			cout << upper_bound(num.begin(), num.end(), n2)
				  - lower_bound(num.begin(), num.end(), n1) << ' ' << n2 - n1 + 1 << '\n';
			;
		}
	}
	
	return 0;
}

