#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

string s;

int n, k;

int p[1000];

int vis[1000];

struct node
{
	char id;
	
	int num;
} a[N];

int cmp(const node &x, const node &y)
{
	return x.num < y.num;
}

signed main()
{
	freopen("goof.in", "r", stdin);
	freopen("goof.out", "w", stdout);
	
	cin.tie(0) -> sync_with_stdio(0);
	
	cin >> s >> k;
	
	n = s.length();
	
	for (int i=0; i<n; i++)
	{
		++p[s[i]];
	}
	
	for (int i='a'; i<='z'; i++)
	{
		a[i - 'a' + 1].num = p[i];
		
		a[i - 'a' + 1].id = i;
	}
	
	sort (a+1, a+27, cmp);
	
	int cnt = 26;
	
	for (int i=1; i<=26; i++)
	{
		if (k >= a[i].num)
		{
			k -= a[i].num;
			
			vis[a[i].id] = 1;
			
			--cnt;
		}
		else
			break;
	}
	
	cout << cnt << '\n';
	
	for (int i=0; i<n; i++)
	{
		if (vis[s[i]])
			continue;
		
		cout << s[i];
	}
	
	return 0;
}
