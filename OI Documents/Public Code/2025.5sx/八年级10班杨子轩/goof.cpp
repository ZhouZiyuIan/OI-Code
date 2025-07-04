#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e05 + 7;

int n, k;

char s[MAXN];

int ned[MAXN]; 

struct Some {
	int ct, chang;
	char ch;
} a[MAXN];

bool cmp(Some a, Some b)
{
	return a.ct < b.ct;
}

signed main()
{
	freopen("goof.in", "r", stdin);
	freopen("goof.out", "w", stdout);
	
	scanf("%s", s + 1), n = strlen(s + 1);
	
	scanf("%d", &k);
	
	for(int i = 1; i <= n; i++)
	{
		a[s[i] - 'a' + 1].ct++;
		a[s[i] - 'a' + 1].ch = s[i];
	}
	
	sort(a + 1, a + 26 + 1, cmp);
	
	for(int i = 1; i <= 26; i++)
		a[i].chang = a[i].ct;
	
	for(int i = 1; i <= 26; i++)
	{
		if(!a[i].ct)
			continue;
		if(k > a[i].ct)
		{
			k -= a[i].ct;
			a[i].chang = 0;
		}
		else if(k == a[i].ct)
		{
			a[i].chang = 0;
			break;
		}
		else if(k < a[i].ct)
			break;
	}
	
	int ans = 0;
	
	for(int i = 1; i <= 26; i++)
	{
		if(a[i].ch >= 'a' and a[i].ch <= 'z')
		{
			if(a[i].chang > 0)
				++ans;
			ned[a[i].ch - 'a' + 1] = a[i].chang;
		}
	}
	
	printf("%d\n", ans);
	
	for(int i = 1; i <= n; i++)
	{
		if(!ned[s[i] - 'a' + 1])
			continue;
		cout << s[i];
	}

	return 0;
}


