#include<bits/stdc++.h>
using namespace std;
int q;
int cnt,de;
string t;
vector<char>del;
struct td{
	int cnt;
	char id;
}sum[26];
bool cmp(td x,td y)
{
	return x.cnt<y.cnt;
}
int main()
{
	freopen("goof.in","r",stdin);
	freopen("goof.out","w",stdout);
	cin>>t;
	cin>>q;
	int siz=t.size();
	for(int i=0;i<siz;i++)
	{
		sum[t[i]-'a'].cnt++;
	 } 
	 for(int i=0;i<26;i++)
	 {
	 	sum[i].id=(i+'a');
	 }
	 sort(sum,sum+25,cmp);
	 for(int i=0;i<26;i++)
	 {
	 	if(sum[i].cnt)
	 	{
	 		cnt++;
		 }
	 }
	 for(int i=0;i<26;i++)
	 {
	 	if(sum[i].cnt!=0)
	 	{
//	 		cout<<q<<" "<<sum[i].cnt<<endl;
	 		if(q>=sum[i].cnt)
	 		{
	 			del.push_back(sum[i].id);
	 			q-=sum[i].cnt;
	 			de++;
//	 			cout<<sum[i].id<<endl;
			 }
			 else
			 {
			 	break;
			 }
		 }
	 }
	 cout<<cnt-de<<endl;
	 for(int i=0;i<siz;i++)
	 {
	 	int out=0;
	 	for(int j=0;j<del.size();j++)
	 	{
//	 		cout<<del[j]<<endl;
	 		if(t[i]==del[j])
	 		{
	 			out=1;
	 			break;
			 }
		 }
		 if(!out)
		 {
		 	cout<<t[i];
		 }
	 }
}
