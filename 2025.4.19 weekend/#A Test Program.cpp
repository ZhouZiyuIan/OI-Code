#include<iostream>
using namespace std;
int n,L,R;
int main(){
	ios::sync_with_stdio(0);
	cout.tie(0);
//	n=1;
	for(n=1;n<=25;n++){
		string a="0",b="1",c;
		for(int i=2;i<=n;i++){
			c=a+b;
			a=b;
			b=c;
		}
		cout<<a<<endl;
	}
}
