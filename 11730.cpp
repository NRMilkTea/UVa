#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N = 1000;
int Case = 0, s, t; 

bool notPrime[N+7] = {true, true, false};
bool used[N+7];
vector<int> prime;

void init(){
	prime.push_back(2);
	for(int i=2; i<=N; i+=2) notPrime[i] = true;
	for(int i=3; i<=N; i+=2){
		if(!notPrime[i]){
			prime.push_back(i);
			for(int j=i*i; j<=N; j+=i){
				notPrime[j] = true;
			}
		}
	}
}

int bfs(){
	memset(used, false, sizeof used); 
	queue<pair<int, int> > q;
	q.push(make_pair(s, 0));
	while(!q.empty()){
		int num = q.front().first; int rule = q.front().second; q.pop();
		//cout << "find: " << num << " rule: " << rule << endl;
		if(num == t) return rule;
		for(int i=0; prime[i]<=num; i++){
			if(__gcd(num, prime[i]) == 1) continue;
			int n = num + prime[i];
			if(__gcd(n, t) != 1 and !used[n]){
				used[n] = true;
				q.push(make_pair(n, rule+1));
			}
		}
	}
	
	return -1;
}

int main(){
	//ios::sync_with_stdio(false); cin.tie(0);
	init();
	
	while(cin >> s >> t){
		if(s == 0 and t == 0) return 0;
		cout << "Case " << ++ Case << ": " << bfs() << endl; 
	}
	
	return 0;
}

