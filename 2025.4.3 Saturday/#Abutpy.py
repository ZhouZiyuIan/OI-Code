def main():
    data = input().split()
    if not data:
        return
    n = int(data[0])
    m = int(data[1])
    a = list(map(int, data[2:2+n]))
    
    # 由 a 构造的所有 “删去一个元素” 的序列（用 tuple 表示以便去重）
    deletions = set()
    for i in range(n):
        # 删除位置 i 后形成的序列
        seq = tuple(a[:i] + a[i+1:])
        deletions.add(seq)
    r = len(deletions)
    
    # 对于一个固定的删除序列 c（长度 n-1），
    # 有效的 b 为：存在某个位置 j (1 ≤ j ≤ n)，使得
    #    b 在删除第 j 个元素后等于 c；
    # 直接构造 b 的方法：对于每 j，
    #    b_1..b_{j-1} = c_1..c_{j-1}，b_j 可任取 [1, m]，
    #    b_{j+1}..b_n = c_j..c_{n-1}.
    # 注：对于相邻的 j，如果 b_j 恰好选定了 c_j，则会产生同一 b。
    # 整体证明可以证明：对每个 c 不重复的删除序列，一共有 n*m - (n-1) 个不同的 b。
    #
    # 因此答案即为：
    result = r * (n * m - (n - 1))
    
    print(result)

if __name__ == '__main__':
    main()
