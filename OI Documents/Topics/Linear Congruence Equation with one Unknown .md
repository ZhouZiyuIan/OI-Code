# 一元线性同余方程组

## 一、一元线性同余方程

​		给定整数 $a,b,m$ 求解如下方程：
$$
ax \equiv b\ (mod\ m)
$$
​		等价于求解：
$$
ax+my=b
$$


## 二、中国剩余定理基本内容

​		中国剩余定理 $(Chinese\ Remainder\ Theorem)$，又称孙子定理，给出了一元线性同余方程组的有解判定条件，并用构造法给出了通解的具体形式。
$$
\begin{cases}
x&\equiv a_1\ (mod\ m_1)\\
x&\equiv a_2\ (mod\ m_2)\\
&\vdots  \\
x&\equiv a_n\ (mod\ m_n)\\
\end{cases}
$$
​		其中，$m_1,m_2...m_n$两两互质
$$
设\ M=\prod^n_{i=1}m_i\ 且\ M_i=M/m_i\\
w_i\equiv M_i^{-1}\ (mod\ m_i)\\
则方程的通解为：x=\sum^n_{i=1}a_iw_iM_i+kM\ \ \ (k\in Z)
$$

## 三、CRT推导过程

​		假设考虑如下 $n$ 条同余式方程:
$$
\begin{align}
y_1&\equiv a_1\ (mod\ m_1)\\
y_2&\equiv a_2\ (mod\ m_2)\\
&\vdots  \\
y_n&\equiv a_n\ (mod\ m_2)\\
\end{align}
$$
​		如果存在 $x_0=\sum^n_{i=1}y_i$ 为方程组的一个特解，考虑 $y_i$ 的条件。

​		现研究第 $t$ 项方程，根据假设有：
$$
y_t\equiv x \equiv \sum^n_{i=1}y_i\equiv a_t\ (mod\ m_t)①\\
\therefore\sum^n_{i=1}y_i[i\ne t]\equiv0\ (mod\ m_t)\\
不妨设\ \forall i\in\{1,2,...,n\}且\ i\ne t,y_i\equiv0\ (mod\ m_t)②\\
令M=\prod^n_{i=1}m_i，并令M_i=\frac{M}{m_i} \\
实际上，令y_t=M_t\cdot z_t可符合②式要求
$$
​		考虑 $z_t$ 的取值，使得①式 $y_t\equiv a_t\ (mod\ m_t)$成立。
$$
\because y_t=M_t\cdot z_t\equiv a_t (mod\ m_t)且\ gcd(M_t,m_t)=1\\
\therefore \exists w_t\ 使得\ w_t\cdot M_t\equiv 1\ (mod\ m_t)\\
\therefore z_t\equiv a_t\cdot w_t (mod\ m_t)不妨令z_t=a_t\cdot w_t\\
\therefore y_t=a_t\cdot M_t\cdot w_t\\
\therefore x_0=\sum^n_{i=1}y_i=\sum^n_{i=1}a_i\cdot M_i\cdot w_i可作为同余方程组的一个特解\\
\because \forall i\in\{1,2,...,n\}\ \ m_i|M\\
\therefore x=x_0+kM\ \ (k\in Z)\ 可作为同余方程组的通解\\
即\ \ x=kM+\sum^n_{i=1}a_i\cdot M_i\cdot w_i\ \ (k\in Z)
$$

## 四、扩展CRT基本内容

​		解决同余方程组 $m_1,m_2...m_n$ 可不互质的问题。

​		考虑合并两个方程组：
$$
\begin{cases}
x&\equiv a_1\ (mod\ m_1)\\
x&\equiv a_2\ (mod\ m_2)\\
\end{cases}
$$
​		化成等式方程组可改写成：
$$
\begin{cases}
x&= a_1+p \cdot m_1\\
x&= a_2+q \cdot m_2\\
\end{cases}
$$

$$
易得\ \ p\cdot m_1-q\cdot m_2=a_2-a_1
$$

​		显然 $p,q$ 有解的情况为 $gcd(m_1,m_2)|a_2-a_1$ 

​		用扩展 $GCD$ 求出 $p,q$ 的通解为：
$$
\begin{cases} 
\displaystyle p=p_0\ + \frac{m_2}{gcd(m_1,m_2)}\cdot k\\
\displaystyle q=q_0\ + \frac{m_1}{gcd(m_1,m_2)}\cdot k
\end{cases}\ \ \ \ \ 其中k\in Z
$$
​		因此 $x$ 的通解可表示为：
$$
\begin{align}
x&=a_1+p\cdot m_1\\
&=a_1+(p_0\ + \frac{m_2}{gcd(m_1,m_2)}\cdot k)\cdot m_1\\
&=a_1+p_0\cdot m_1\ + \frac{m_2}{gcd(m_1,m_2)}\cdot k\cdot m_1\\
&=x_0+ \frac{m_1\cdot m_2}{gcd(m_1,m_2)}\cdot k\\
&=x_0+k \cdot lcm(m_1,m_2)
\\
等价于\ x&\equiv x_0\ \ (mod\ lcm(m_1,m_2))
\end{align}
$$
```c++
ll Excrt(){
	ll	M = m[1], X = a[1], p, q, d, t, c;  
	for(int i = 2; i <= n; i++){//前i - 1个已合并方程与第i个方程合并    
		c = ((a[i] - X) % m[i] + m[i]) % m[i];//a2 - a1,这里是取正操作
		d = Exgcd(M, m[i], p, q);
		if (c % d) return -1;//无解
		t = m[i] / d;
		p = mul(p, c / d, t);//求 p 的最小正整数解
	//等价于x = x * c / d;
		//x = (x % t + t) % t;
	//如果爆ll就快速乘mul(x, c / d, t);            
		X += M * p;
		M *= t;//M=lcm(M,b) 
		X = (X % M + M) % M;
	}
	X = (X % M + M) % M;//特判n = 1的情况
	return X;
}
```

