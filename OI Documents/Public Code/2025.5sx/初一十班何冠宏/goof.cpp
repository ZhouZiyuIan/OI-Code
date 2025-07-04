#include<bits/stdc++.h>
using namespace std;
struct node{
	int sum, i;
}vis[26];
bool cmp(node x, node y)
{
	return x.sum < y.sum;
}
int main()
{
	freopen("goof.in", "r", stdin);
	freopen("goof.out", "w", stdout);
	string s;
	int k, v[26] = {};
	for(int i = 0;i < 26; i++)
	{
		vis[i].i = i;
		vis[i].sum = 0;
	}
	cin >> s;
	scanf("%d", &k);
	for(int i = 0; i < s.size(); i++)
		vis[s[i] - 'a'].sum++;
	sort(vis, vis + 26, cmp);
	bool l = 1;
	for(int i = 0; i < 26; i++)
	{
		v[vis[i].i] = i;
		if(k > vis[i].sum)
		{
			k -= vis[i].sum;
			vis[i].sum = 0;
		}
		else
		{
			printf("%d\n", 26 - i);
			vis[i].sum -= k;
			l = 0;
			break;
		}
	}
	if(l)
	{
		printf("0\n");
		exit(0);
	}
	for(int i = 0; i < s.size(); i++)
	{
		if(vis[v[s[i] - 'a']].sum > 0)
		{
			vis[v[s[i] - 'a']].sum--;
			cout << s[i];
		}
	}
	return 0;
} 
