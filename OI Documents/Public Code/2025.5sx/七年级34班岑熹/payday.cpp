#include <bits/stdc++.h>

#define endl '\n'
#define int long long

const int MAX_ARRAY_SIZE = 2e5 + 7;

struct Node {
	
	int L, R;
} A[MAX_ARRAY_SIZE];

int N, S, Answer;

void Dfs (int This_Node, int Value, std :: vector <int> & F) {
	
	if (This_Node == N + 1) {
		
		std :: sort (F.begin (), F.end ());
		
		Answer = std :: max (Answer, F[N >> 1]);
		
		return ;
	}
	
	for (int i = A[This_Node].L; i <= A[This_Node].R; ++ i) {
		
		std :: vector <int> Temp = F;
		Temp.push_back (i);
		
		if (Value < i) {
			
			break ;
		}
		
		Dfs (This_Node + 1, Value - i, Temp);
	}
	
	return ;
}

void Solve (void) {
	
	Answer = 0;
	
	std :: vector <int> Temp;
	
	std :: cin >> N >> S;
	
	for (int i = 1; i <= N; ++ i) {
		
		std :: cin >> A[i].L >> A[i].R;
		
		A[i].R = std :: min (A[i].R, S);
	}
	
	Dfs (1, S, Temp);
	
	std :: cout << Answer << endl;
	
	return ;
}

signed main (void) {
	
	freopen ("payday.in", "r", stdin);
	freopen ("payday.out", "w", stdout);

	std :: ios :: sync_with_stdio (false);
	std :: cin.tie (nullptr);
	std :: cout.tie (nullptr);
	
	int T;
	std :: cin >> T;
	
	for (int Case = 1; Case <= T; ++ Case) {
		
		Solve ();
	}
	
	return 0;
}
