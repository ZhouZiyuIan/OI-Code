#include <bits/stdc++.h>

#define endl '\n'

const int MAX_ARRAY_SIZE = 1e5 + 7;

std :: pair <int, int> A[MAX_ARRAY_SIZE];

char S[MAX_ARRAY_SIZE];
bool Flag[MAX_ARRAY_SIZE];

int main (void) {
	
	freopen ("goof.in", "r", stdin);
	freopen ("goof.out", "w", stdout);

	std :: ios :: sync_with_stdio (false);
	std :: cin.tie (nullptr);
	std :: cout.tie (nullptr);
	
	int N, K;
	std :: cin >> S + 1 >> K;
	
	N = std :: strlen (S + 1);
	
	for (int i = 1; i <= N; ++ i) {
		
		++ A[S[i] - 'a' + 1].first;
	}
	
	for (int i = 1; i <= 26; ++ i) {
		
		A[i].second = i;
	}
	
	std :: sort (A + 1, A + 26);
	
	int Total = K, Sum = 0;
	
	for (int i = 1; i <= 26; ++ i) {
		
		if (Total >= A[i].first) {
			
			Total -= A[i].first;
			
			Flag[A[i].second] = true;
		} else {
			
			++ Sum;
		}
	}
	
	std :: cout << Sum << endl;
	
	for (int i = 1; i <= N; ++ i) {
		
		if (not Flag[S[i] - 'a' + 1]) {
			
			std :: cout << S[i];
		}
	}

	return 0;
}
