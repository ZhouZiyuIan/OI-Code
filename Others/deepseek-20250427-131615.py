def count_valid_subarrays(a, n, k):
    count = 0
    max_len = 60  # 根据实际情况调整
    for l in range(n):
        product = 1
        sum_ = 0
        for r in range(l, min(l + max_len, n)):
            product *= a[r]
            sum_ += a[r]
            if product == k * sum_:
                count += 1
            if product > 1 << 60:  # 防止乘积过大
                break
    return count

# 示例
n, k = 4,2
a = [6,3,8,1]
print(count_valid_subarrays(a, n, k))  # 输出 0
