#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	freopen("goof.in","r",stdin);
	freopen("goof.out","w",stdout);
	string a;
	cin >> a;
	int n,sy=0;
	cin >> n;
	if(n >= (int)a.size()){
		cout << "0\n";
		return 0;
	}
	int m[26]={},m1[26]={},mm[26]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
	for(int i = 0;i < a.size();i++){
		if(m[a[i]-'a']==0){
			sy++;
		}
		m[a[i]-'a']++;
	}
	//sort(a,a+26);
	
	while(true){bool o=true;
		
		for(int i = 1;i <= 25;i++){
			if(m[i-1] > m[i]){
				swap(m[i-1],m[i]);
				swap(mm[i-1],mm[i]);
				o = false;
				break;
			}
		}
		if(o)break;
		
	}
	int c = 0,ys=0;
	for(int i = 0;i <= 25;i++){
		if(c + m[i] > n){
			break;
		}
		else if(m[i]!=0)ys++;
		c += m[i];
		m1[mm[i]]=1;
	}
	cout << sy-ys<<endl;
	for(int i = 0;i < a.size();i++){
		if(m1[a[i]-'a']==0){
			cout << a[i];
			continue;
		}
	}
	return 0;
}
