#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	freopen("sheep.in","r",stdin);
	freopen("sheep.out","w",stdout);
	int n;
	cin >> n;
	int max=-1e19,m=0;
	for(int i=1;i<=n;i++){
		int b;
		cin >> b;
		if(b==-1){
			m++;
			continue;
		}
		if(max < b){
			max = b;
		}
	}
	if(max == n)max++;
	cout << "nan";
	return 0;
}
