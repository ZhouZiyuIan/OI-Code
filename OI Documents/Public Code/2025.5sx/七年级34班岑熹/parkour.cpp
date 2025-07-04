#include <bits/stdc++.h>

#define endl '\n'

const int MAX_ARRAY_SIZE = 1e5 + 7;
const int ROW = 22;

struct Node {
	
	int X, Y;
};

char C[ROW][MAX_ARRAY_SIZE];
bool Flag[ROW][MAX_ARRAY_SIZE];

int N, M;

bool Check (Node This) {
	
	int X = This.X, Y = This.Y;
	
	if (X < 1 or Y < 1 or X > N or Y > M) {
		
		return false;
	}
	
	if (Flag[X][Y] or C[X][Y] == 'X') {
		
		return false;
	}
	
	return true;
}

void Solve (void) {
	
	std :: memset (Flag, false, sizeof Flag);

	int Start_X, Start_Y;
	
	std :: cin >> N >> M;
	
	std :: swap (N, M);
	
	for (int i = 1; i <= N; ++ i) {
		
		for (int j = 1; j <= M; ++ j) {
			
			std :: cin >> C[i][j];
			
			if (C[i][j] == 's') {
				
				Start_X = i;
				Start_Y = j;
			}
		}
	}
	
	std :: queue <Node> Queue;
	Queue.push ((Node) {Start_X, Start_Y});
	
	Flag[Start_X][Start_Y] = true;
	
	while (not Queue.empty ()) {
		
		Node This = Queue.front ();
		Queue.pop ();
		
		if (This.Y >= M) {
			
			std :: cout << "YES\n";
			
			return ;
		}
		
		++ This.Y;
		
		if (not Check (This)) {
			
			continue ;
		}
		
		Node First, Second, Third;
		
		First = Second = Third = This;
		
		First.X += 1;
		Second.X -= 1;
		
		First.Y = Second.Y = Third.Y = This.Y + 2;
		
		if (Check (First) and Check ((Node) {First.X, First.Y - 2})) {
			
			Queue.push (First);
			
			Flag[First.X][First.Y] = true;
		}
		
		if (Check (Second) and Check ((Node) {Second.X, Second.Y - 2})) {
			
			Queue.push (Second);
			
			Flag[Second.X][Second.Y] = true;
		}
		
		if (Check (Third) and Check ((Node) {Third.X, Third.Y - 2})) {
			
			Queue.push (Third);
			
			Flag[Third.X][Third.Y] = true;
		}
	}
	
	std :: cout << "NO\n";
	
	return ;
}

int main (void) {
	
	freopen ("parkour.in", "r", stdin);
	freopen ("parkour.out", "w", stdout);

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
