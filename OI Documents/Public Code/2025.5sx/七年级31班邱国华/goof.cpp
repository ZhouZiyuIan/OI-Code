#include<bits/stdc++.h>
using namespace std;
char x[100000];
int a[2][50],d;
void dfs(){
	/*for(int i=0;i<26;i++){
		cout<<char(a[0][i]+'a')<<" ";
	}cout<<endl;*/
	bool a1=0;
	for(int i=0;i<25;i++){
		if((a[1][i]>a[1][i+1]&&a[1][i+1]!=0)||(a[1][i]==0&&a[1][i+1]!=0)){
			swap(a[1][i],a[1][i+1]);
			swap(a[0][i],a[0][i+1]);
			a1=1;
		}//else if(){
			//cout<<"x";
			//swap(a[1][i],a[1][i+1]);
			//swap(a[0][i],a[0][i+1]);
		//}
	}
	if(a1){
		dfs();
	}
}
void del(int a){
	for(int i=0;i<d;i++){
		if(x[i]==char(a)){
			//cout<<x[i]<<" ";
			x[i]=0;
		}
	}
}
int main(){
	freopen("goof.in","r",stdin);
	freopen("goof.out","w",stdout);
	int b,c;
	cin>>x>>b;
	d=strlen(x);
	for(int i='a';i<='z';i++){
		a[0][i-'a']=i-'a';
	}
	/*for(int i=0;i<26;i++){
		cout<<char(a[0][i]+'a')<<" ";
	}cout<<endl;*/
	for(int i=0;i<strlen(x);i++){
		a[1][x[i]-'a']++;
	}
	dfs();
	for(int i=0;i<26;i++){
		if(a[1][i]!=0){
			c++;
		}else{
			break;
		}
	}
	for(int i=0;i<26;i++){
		if(a[1][i]<b){
			b-=a[1][i];
			del(a[0][i]+'a');
			c--;
			if(c==0){
				cout<<"0";
				exit(0);
			}
			//cout<<x<<endl;
			//cout<<char(a[0][i]+'a')<<endl;
		}else{
			cout<<c<<endl;
			for(int i=0;i<d;i++){
				if(x[i]==0){
					continue;
				}
				cout<<x[i];
			}
			exit(0);
		}
	}
}
