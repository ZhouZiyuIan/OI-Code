import sys
sys.setrecursionlimit(1 << 25)

N, M = map(int, input().split())
G = [[] for _ in range(N)]

for _ in range(M):
    a, b = map(int, input().split())
    G[a-1].append(b-1)
    G[b-1].append(a-1)

color = [0] * N  # 0 表示白色，1 表示黑色
ans = 0

def dfs(u, parent):
    global ans
    for v in G[u]:
        if v != parent:
            dfs(v, u)

    if parent != -1 and color[u] == 0 and color[parent] == 0:
        color[u] = 1
        color[parent] = 1
        ans += 1

dfs(0, -1)

# 检查是否全部变黑
if all(c == 1 for c in color):
    print(ans)
else:
    print(-1)
