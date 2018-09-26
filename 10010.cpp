#include <iostream>
using namespace std;
int m,n;
char f[50][50]={0};
char word[50]={0};

void fun(int len){
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(f[i][j]==word[0]){
				int a=i,b=j,k=1;
				while(a>1 && b>1 && f[a-1][b-1] == word[k]){//�����W�] 
					a--; b--; k++;
				}
				if(k==len){
					cout << i << ' ' << j << endl; return;
				}
				a=i;b=j;k=1;
				while(a>1 && b<n && f[a-1][b+1] == word[k]){//���k�W�] 
					a--; b++; k++;
				}
				if(k==len){
					cout << i << ' ' << j << endl; return;
				}
				a=i;b=j;k=1;
				while(a<m && b>1 && f[a+1][b-1] == word[k]){//�����U�] 
					a++; b--; k++;
				}
				if(k==len){
					cout << i << ' ' << j << endl; return;
				}
				a=i;b=j;k=1;
				while(a<m && b<n && f[a+1][b+1] == word[k]){//���k�U�] 
					a++; b++; k++;
				}
				if(k==len){
					cout << i << ' ' << j << endl; return;
				}
				a=i;b=j;k=1;
				while(a>1 && f[a-1][b] == word[k]){//���W�] 
					a--; k++;
				}
				if(k==len){
					cout << i << ' ' << j << endl; return;
				}
				a=i;b=j;k=1;
				while(a<m && f[a+1][b] == word[k]){//���U�] 
					a++; k++;
				}
				if(k==len){
					cout << i << ' ' << j << endl; return;
				
				}a=i;b=j;k=1;
				while(b>1 && f[a][b-1] == word[k]){//�����] 
					b--; k++;
				}
				if(k==len){
					cout << i << ' ' << j << endl; return;
				}
				a=i;b=j;k=1;
				while(b<n && f[a][b+1] == word[k]){//���k�] 
					b++; k++;
				}
				if(k==len){
					cout << i << ' ' << j << endl; return;
				}
			}
		}
	}
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a;
	cin >> a;
	for(int i=1;i<=a;i++){
		if(i!=1) cout<<endl;
		cin>>m>>n;
		for(int j=1;j<=m;j++){ //��Jm*n�Ӧr�� 
			for(int k=1;k<=n;k++){
				cin>>f[j][k];
			}
		}
		for(int j=1;j<=m;j++){ //�ܤj�g 
			for(int k=1;k<=n;k++){
				if(97<=f[j][k] && f[j][k]<=122)
					f[j][k]=f[j][k]-32;
			}
		}
		
		int b;
		cin>>b;
		for(int j=1;j<=b;j++){ 
			cin>>word;
			int len=0;
			for(int k=0;k<50;k++){ //�ܤj�g  
				if(97<=word[k] && word[k]<=122)
					word[k]=word[k]-32;
			}
			for(int k=0;k<50;k++){ //�D��r���� 
				if(word[k]!=0) len++;
				else break;
			}
			fun(len);	 
		}
	}
	return 0;
}
