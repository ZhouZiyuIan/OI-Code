#include<iostream>
#include<map>
#include<vector>
#include<utility>
using namespace std;
map<int,int>hsh;
map<pair<string,long long>,bool>vvv;
vector<string>aaa;
int q,t,cnt1,cnt2;
long long has;
string s;
void hs(string s,int t){
	long long tmp=0;
	for(long long j=0;j<s.size();j++){
		tmp*=13331;
		tmp+=s[j];
		tmp%=998244353;
		vvv[make_pair(s,tmp)]=1;
		if(hsh[tmp]&&t==2){
			cnt1++;
			has++;
			return;
		}
	}
	if(t%2)hsh[tmp]++,has=tmp;
}
main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>q;
	while(q--){
		cin>>t>>s;
		has=0;
		hs(s,t);
		if(t==2)cnt2++;
		if(!has&&t==2)aaa.push_back(s);
		if(t==1){
			for(int i=0;i<aaa.size();i++){
				if(vvv[make_pair(aaa[i],has)]==1){
					cnt1++;
					aaa.erase(aaa.begin()+i);
				}
			}
		}
		cout<<cnt2-cnt1<<'\n';
	}
}