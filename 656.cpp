#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

string operate[5] = {"ADD", "DIV", "DUP", "MUL", "SUB"};

int Case = 0, n, x[10], y[10];
typedef struct{
	stack<int> s;
	vector<int> c;
} node; 

inline bool outOfRange(node k) {return (k.s.top() > 30000 || k.s.top() < -30000);}
inline bool maximumOperation(node k) {return k.c.size() == 10;}
inline bool canCompute(node k) {return k.s.size() > 1;}
inline bool divide0(node k) {return k.s.top() == 0;}

node calc(node p, int oper){
	if(oper == 0){
			int a = p.s.top(); p.s.pop();
			int b = p.s.top(); p.s.pop();
			p.s.push(b+a);
	}
	if(oper == 1){
			int a = p.s.top(); p.s.pop();
			int b = p.s.top(); p.s.pop();
			p.s.push(b/a);
	}
	if(oper == 2){
			int a = p.s.top();
			p.s.push(a);
	}
	if(oper == 3){
			int a = p.s.top(); p.s.pop();
			int b = p.s.top(); p.s.pop();
			p.s.push(b*a);
	}
	if(oper == 4){
			int a = p.s.top(); p.s.pop();
			int b = p.s.top(); p.s.pop();
			p.s.push(b-a);
	}
	p.c.push_back(oper);
	return p;
}

bool check(node k){
	for(int i=1; i<n; i++){
		node p; p.s.push(x[i]);
		for(int j=0; j<k.c.size(); j++){
			if(k.c[j] == 1 and divide0(p) or outOfRange(p)) return false;
			p = calc(p, k.c[j]);
		}
		if(p.s.top() != y[i]) return false;
	}
	return true;
}

void bfs(){
	queue<node> q;
	node init; init.s.push(x[0]); q.push(init);
	while(!q.empty()){
		node now = q.front(); q.pop();
		if(outOfRange(now)) continue;
		if(now.s.size() == 1 && now.s.top() == y[0]){
			if(check(now)){ 
				if(now.c.size() == 0) cout << "Empty sequence" << endl;
				else{
					cout << operate[now.c[0]];
					for(int i=1; i<now.c.size(); ++i) cout << ' ' << operate[now.c[i]];
					cout << endl;
				}
				return;
			}
		}
		if(maximumOperation(now)) continue;
		for(int action=0; action<5; ++action){
			if(action == 1 and divide0(now)) continue;
			if(action != 2 and !canCompute(now)) continue; 
			q.push(calc(now, action));
		}
	}
	cout << "Impossible" << endl; 
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	while(cin >> n){
		if(n == 0) break;
		for(int i=0; i<n; ++i) cin >> x[i];
		for(int i=0; i<n; ++i) cin >> y[i]; 
		cout << "Program " << ++Case << endl;
		bfs();
		cout << endl;
	}
	return 0;
}ow[i][size-1] = now[i][size-1] / now[i][size];
		}
		dfs(now, n, size-1, state+1, program + " DIV");
	}
	//DUP
	copy(now, stack_);
	for(int i=0; i<n; ++i){
		now[i][size+1] = now[i][size];
	}
	dfs(now, n, size+1, state+1, program + " DUP");
}

int main(){ //io;
	int n;
	int stack_[10][11];
	
	while(cin >> n){
		if(n == 0) return 0;
		ans = "";
		for(int i=0; i<n; ++i) cin >> stack_[i][1]; // function inputs 
		for(int i=0; i<n; ++i) cin >> stack_[i][0]; // function outputs
		dfs(stack_, n, 1, 0, "");
		cout << ans << endl; 
	}
	
	return 0;
}

