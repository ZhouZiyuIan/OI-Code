#include <bits/stdc++.h>

#define endl '\n'

const int MAX_ARRAY_SIZE = 2e3 + 7;
const int Mod = 1e9 + 7;

int A[MAX_ARRAY_SIZE];
int F[MAX_ARRAY_SIZE];

int main (void) {
	
	freopen ("sheep.in", "r", stdin);
	freopen ("sheep.out", "w", stdout);

	std :: ios :: sync_with_stdio (false);
	std :: cin.tie (nullptr);
	std :: cout.tie (nullptr);
	
	int N, Start = -1, Sum = 0;
	std :: cin >> N;
	
	for (int i = 1; i <= N; ++ i) {
		
		std :: cin >> A[i];
		
		if (A[i] == -1) {
			
			++ Sum;
		}
	}
	
	F[2] = 1;
	
	for (int i = 3; i <= Sum; ++ i) {
		
		F[i] = F[i - 1] * (i - 2) % Mod;
	}
	
	std :: cout << F[Sum] + 1 << endl;

	return 0;
}
