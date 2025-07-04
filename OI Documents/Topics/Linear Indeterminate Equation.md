# 一次不定方程

## 一、**不定方程的概念**

​		丢番图方程又名**不定方程**，其系数，指数，解集等仅在**整数范围内**研究的多项式等式，即形如下图的方程：
$$
a_1\cdot x_1^{b_1}+a_2\cdot x_2^{b_2}+\dots +a_n\cdot x_n^{b_n}=c
$$

## 二、解二元一次不定方程

### 1、齐次式 $ax+by=0$ 的通解

​		研究如下齐次式：
$$
ax+by=0\\
$$
​		显然，若可以求出 $x$ 的最小正整数解，设该特解为 $\{x',y'\}$，则该齐次方程通解即为
$$
\begin{cases} 
\displaystyle x=t\ \cdot x'\\
\displaystyle y=t\ \cdot y'
\end{cases}
\ \ \ \ \ 其中\ t\in Z
$$
​		接下来求解 $\{x',y'\}$
$$
\displaystyle ax+by=0\\
x=-\frac{by}{a}\\
x=-\frac{\frac{b}{gcd(a,b)}\cdot y}{\frac{a}{gcd(a,b)}}\\
\because \frac{b}{gcd(a,b)}与 \frac{a}{gcd(a,b)}互质\\
\therefore 必有\frac{a}{gcd(a,b)}|y,显然令y=-\frac{a}{gcd(a,b)} 可使得x为最小正整数解\\
解得\begin{cases} 
\displaystyle x'=\frac{b}{gcd(a,b)}\\
\displaystyle y'=-\frac{a}{gcd(a,b)}
\end{cases}\\
\therefore ax+by=0通解为\begin{cases} 
\displaystyle x=t\ \cdot \frac{b}{gcd(a,b)}\\
\displaystyle y=-t\ \cdot \frac{a}{gcd(a,b)}
\end{cases}
\ \ \ \ \ 其中\ t\in Z
$$

### 2、 $ax+by=gcd(a,b)$ 的特解

​		扩展欧几里得算法（$EXGCD$）是用于求 $ax+by=gcd(a,b)$ 一组**整数特解**的算法。

​		若 $a=0$，则 $by=b$，解得：
$$
\begin{cases} x\in Z\\ y=1\end{cases}
$$
​		同理若 $b=0$ ，解得：
$$
\begin{cases} x=1\\ y\in Z\end{cases}
$$
​		当 $a$，$b$ 都不为$0$时：
$$
设存在一组解x,y,使得:ax+by=gcd(a,b)\\
由\ gcd\ 性质得:gcd(a,b)=gcd(b,a\ mod\ b)\\
同时存在另一组解\ x',y',使得\ bx'+(a\ mod\ b)\ y'=gcd(b,a\ mod\ b)\\
\begin {align}
\therefore \ &ax+by\\
=&bx'+(a\ mod\ b)\ y'\\
=&bx'+(a-\lfloor \frac{a}{b} \rfloor \cdot b)\ y'\\
=&ay'+b(x'-\lfloor \frac{a}{b} \rfloor y')
\end{align}\\
通过变形，令系数相等，从而推出两组解的关系如下：\\
\begin{cases} x=y'\\ y=x'-\lfloor \frac{a}{b} \rfloor y'\end{cases}
$$

​		利用以上推导式可知，不定方程 $ax+by=gcd(a,b)$ **一定存在**一组特解 $x_0,y_0$ ，即 
$$
ax_0+by_0=gcd(a,b)
$$
**代码实现**

```c++
#define ll long long
ll Exgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1; y = 0;
        return a;
    }
    ll ans = Exgcd(b, a % b, y, x);
    y -= a / b * x;
    return ans;
}
```

### 3、 $ax+by=gcd(a,b)$ 的通解

​		通过扩展欧几里得算法，求解 $ax+by=gcd(a,b)$ 的一组特解 $x_0$ , $y_0$，通过与其次式 $ax+by=0$联立，可得 $ ax+by=gcd(a,b)$ 通解为：
$$
\begin{cases} 
\displaystyle x=x_0 +t\ \cdot \frac{b}{gcd(a,b)}\\
\displaystyle y=y_0 -t\ \cdot \frac{a}{gcd(a,b)}
\end{cases}
\ \ \ \ \ 其中\ t\in Z
$$

​		设 $k=\frac{b}{gcd(a,b)}$ ，则 $(x_0\ mod\ k+k)\ mod\ k\ $为方程关于 $x$ 的最小正整数解。

### 4、$ax+by=c$ 的通解

​		探究二元一次不定方程的通解形式：
$$
ax+by=c
$$
​		首先研究如下方程：
$$
ax’+by'=gcd(a,b)
$$
​		接下来讨论 $c$ 与 $gcd(a,b)$ 的整除情况：

​		① $gcd(a,b)|c$

​		若求出 $x',y'$ 的特解 $x_0,y_0$，若 $gcd(a,b)|c$ ，由乘法分配律可得，将其乘比例系数 $\frac{c}{gcd(a,b)}$ 即可满足原等式，即求得 $ax+by=c$ 的通解为：
$$
\begin{cases} 
\displaystyle x=x_0\cdot \frac{c}{gcd(a,b)} +t\ \cdot \frac{b}{gcd(a,b)}\\
\displaystyle y=y_0\cdot \frac{c}{gcd(a,b)} -t\ \cdot \frac{a}{gcd(a,b)}
\end{cases}
\ \ \ \ \ 其中\ t\in Z
$$
​		② $gcd(a,b)$ 不能整除 $c$

​		由于 $gcd(a,b)|a$ ，$gcd(a,b)|b$ ，则必有  $gcd(a,b)|ax+by$  因此这种情况下无解。 

**裴蜀定理**

​		裴蜀定理，又称贝祖定理（$Bezouts Identity$）、贝祖等式，是一个关于最大公约数的定理。

​		对于二元一次不定方程 $ax+by=c$，有整数解 $\Lrarr$ $gcd(a,b)|c$，且有解时必有无穷多个整数解。

​		**扩展：**对于 $n$ 元一次不定方程 ，$a_1x_1+a_2x_2+...+a_nx_n=c$，有整数解  $\Lrarr$ $gcd(a_1,a_2...a_n)|c$，且有解时必有无穷多个整数解。

## 三、解 $n$ 元一次不定方程
