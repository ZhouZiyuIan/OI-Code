#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	freopen("picnic.in","r",stdin);
	freopen("picnic.out","w",stdout);
	int n,t;
	cin >> n >> t;
	int a = 0,c=0;
	vector <double>d(1000010,0);
	int m[n+1]={};
	
	for(int i = 1;i <= n;i++){
		cin >> m[i];
		
	}
	for(int i = 1;i <= n;i++){
		for(int j = i+1;j <= n;j++){
			double g = abs(m[i]-m[j])*t/2;
			if(g == 0){
				continue;
			}
			bool h=true; 
			for(int k = 1;k <= c;k++){
				if(d[k] == g){
					h = false;
					break;
				}
			}
			if(h){
				c++;
				d[c] = g;
				a++;
			}
		}
	}
	cout << a;
	
	return 0;
}
