# 高斯消元

## 一、简介

解决 $N$ 行 $M$ 列的线性方程组解的问题。

求解如下方程组:
$$
\begin{cases}

a_{11}x_1 +a_{12}x_2+\cdots+a_{1m}x_m=b_1\\
a_{21}x_1 +a_{22}x_2+\cdots+a_{2m}x_m=b_2\\
\vdots\\
a_{n1}x_1  +a_{n2}x_2+\cdots+a_{nm}x_m=b_n\\

\end{cases}
$$

## 二、预备知识

### 1、系数矩阵和增广矩阵

$$
系数矩阵A=\begin{bmatrix}
a_{11} & a_{12} & \cdots & a_{1m}\\
a_{21} & a_{22} & \cdots & a_{2m}\\
\vdots & \vdots & \ddots & \vdots\\
a_{n1}& a_{n2}& \cdots & a_{nm}\\
\end{bmatrix}
$$

$$
增广矩阵A|b=\begin{bmatrix}
a_{11} & a_{12} & \cdots & a_{1m} & b_1\\
a_{21} & a_{22} & \cdots & a_{2m} & b_2\\
\vdots & \vdots & \ddots & \vdots & \vdots\\
a_{n1}& a_{n2}& \cdots & a_{nm} & b_n\\
\end{bmatrix}
$$



### 2、矩阵的行初等变换

矩阵的行初等变换主要包括以下三种基本操作：

**1.对换变换**：交换矩阵的两行位置。

**2.倍乘变换**：以一个非零数 $k$ 乘以矩阵的某一行所有元素。

**3.倍加变换**：把矩阵的某一行所有元素乘以一个数 $k$ 后加到另一行对应的元素上。

**推论1：如果其中一个矩阵可以通过初等行变换变成另一个矩阵，则称这两个矩阵是行等价的**

**推论2：若两个线性方程组的增广矩阵是行等价的，则它们有相同的解集。**

## 三、行阶梯型矩阵（RREF）

**行阶梯型矩阵是形如：**
$$
\begin{bmatrix}
0 & \blacksquare & * & * & * & * & * & * & * & *\\
0 & 0 & 0 & \blacksquare & * & * & * & * & * & *\\
0 & 0 & 0 & 0 & \blacksquare & * & * & * & * & *\\
0 & 0 & 0 & 0 & 0 &\blacksquare & * & * & * & *\\
0 & 0 & 0 & 0 & 0 &0 &0 &0 &\blacksquare & *\\
0 & 0 & 0 & 0 & 0 &0 &0 &0 &0 &0
\end{bmatrix}
$$
矩阵里的 $\blacksquare$ 是不为零的任意一个数，$*$为任意数。

非零行的主元是指这一行中最左边的非零元素，即图上的$\blacksquare$。

**1.** 每一个非零行都在每一个零行之上。

**2.** 某一行的主元所在的列在上一行主元的右边

**3.** 某一行的主元所在的列下方元素都是 $0$。

**简化行阶梯型矩阵是形如：**
$$
\begin{bmatrix}
0 & 1 & * & 0 & 0 & 0 & * & * & 0 & *\\
0 & 0 & 0 & 1 & 0 & 0 & * & * & 0 & *\\
0 & 0 & 0 & 0 & 1 & 0 & * & * & 0 & *\\
0 & 0 & 0 & 0 & 0 & 1 & * & * & 0 & *\\
0 & 0 & 0 & 0 & 0 & 0 & 0 & 0 & 1 & *\\
0 & 0 & 0 & 0 & 0 & 0 & 0 & 0 & 0 & 0
\end{bmatrix}
$$
**4.** 每一非零行的主元是 $1$。

**5.** 每一个主元 $1$ 是该元素所在列的唯一非零元素。

**定理  每个矩阵行等价于唯一的简化阶梯型矩阵**

记矩阵 $A$ 的秩为 $r(A)$，则 $r(A)$ 等于**行阶梯型矩阵的非零行数**。

## 四、线性方程组解的情况

考查系数矩阵 $r(A)$，增广矩阵$r(A|b)$，以及方程组未知数个数 $n$。

线性方程组有解 $\Leftrightarrow r(A)=r(A|b)$ 。

线性方程组有无穷多个解 $\Leftrightarrow r(A)=r(A|b)<n$ $\Leftrightarrow$ 有 $n-r(A)$ 个解系
线性方程组有唯一解$\ \Leftrightarrow r(A)=r(A|b)=n$。

**唯一解的情况：**

其中前 $m-1$ 列每一列都存在主元。
$$
\begin{bmatrix}
1 & 0 & 0 & 0 & 0 & 0 & b_1 \\
0 & 1 & 0 & 0 & 0 & 0 & b_2 \\
0 & 0 & 1 & 0 & 0 & 0 & b_3 \\
0 & 0 & 0 & 1 & 0 & 0 & b_4 \\
0 & 0 & 0 & 0 & 1 & 0 & b_5 \\
0 & 0 & 0 & 0 & 0 & 1 & b_6 
\end{bmatrix}
$$
**无解的情况：**

其中最后非零行只有最后一列的值非零。
$$
\begin{bmatrix}
1 & 0 & 0 & 0 & 0 & 0 & b_1 \\
0 & 1 & 0 & 0 & 0 & 0 & b_2 \\
0 & 0 & 1 & 0 & 0 & 0 & b_3 \\
0 & 0 & 0 & 1 & 0 & 0 & b_4 \\
0 & 0 & 0 & 0 & 1 & 0 & b_5 \\
0 & 0 & 0 & 0 & 0 & 0 & b_6 
\end{bmatrix}
$$
**无穷解的情况：**

其中某几列不存在主元。
$$
\begin{bmatrix}
 1 & * & 0 & 0 & 0 & * & * & 0 & b_1\\
 0 & 0 & 1 & 0 & 0 & * & * & 0 & b_2\\
 0 & 0 & 0 & 1 & 0 & * & * & 0 & b_3\\
 0 & 0 & 0 & 0 & 1 & * & * & 0 & b_4\\
 0 & 0 & 0 & 0 & 0 & 0 & 0 & 1 & b_5\\

\end{bmatrix}
$$


## 五、高斯消元的算法过程

高斯消元的算法过程其实就是将**增广矩阵**转换成**简化行阶梯型矩阵**，并判断**唯一解，无穷解，无解**的过程。

**算法过程：**

**1.** 将含有 $m-1$ 个未知数，$n$ 条方程的线性方程组转化为 $n \times m$ 的增广矩阵。

**2.** 确定主元。枚举列，假设当前为第 $c$ 列，前 $c-1$ 列已找到 $w-1$ 个主元，则第 $c$ 列应从第 $w$ 行至第 $n$ 行寻找。

**3.** 交换主元行位置。找到**绝对值最大**的主元所在行（尽量减少误差），与第 $w$ 行交换位置。若绝对值最大为 $0$，说明没有主元，可能为无穷解，跳过该列。

**4.** 主元单位化，将第 $w$ 行主元变换为 $1$。具体来说，将第 $w$ 行所有元素除以 $\Large a_{wc}$。

**5.** 消元，将第 $c$ 列除第 $w$ 行外所有元素变换为 $0$。具体来说，假设要变换行为第 $i$ 行，则该行的第 $j$ 列元素应减去 $a_{ic}\times a_{wj}$。

**6.** 重复以上步骤，直至将矩阵转换为**简化行阶梯型矩阵**，判断解的情况。

   判断最后一行非零行是否只有最后一列非零，若是，则说明无解；

   若不是，则判断主元数与未知数个数的大小关系，若主元数 $<$ 未知数个数，说明有无穷解；若主元数 $=$ 未知数个数，说明有唯一解。

**7.**若有唯一解，则解集为矩阵最后一列向量。

   



 **例1：**
$$
\begin{cases}
5x-3y&=-1\\
2x+y&=4
\end{cases}
$$

$$
A|b=\begin{bmatrix}
5 & -3 & -1\\
2 & 1 & 4
\end{bmatrix} \xRightarrow{r_1单位化}
\begin{bmatrix}
1 & -\frac{3}{5} & -\frac{1}{5}\\
2 &  1 & 4  
\end{bmatrix}\xRightarrow{r_2-2r_1}
\begin{bmatrix}
1 & -\frac{3}{5} & -\frac{1}{5}\\
0 &  \frac{11}{5} &  \frac{22}{5}
\end{bmatrix}
\\\xRightarrow{r_2单位化}
\begin{bmatrix}
1 & -\frac{3}{5} & -\frac{1}{5}\\
0 &  1 & 2  
\end{bmatrix}
\xRightarrow{消元}
\begin{bmatrix}
1 & 0 & 1\\
0 &  1 & 2  
\end{bmatrix}
$$

$$
\because r(A)=r(A|b)=n\ \therefore 方程有唯一解\begin{cases}
x=1\\
y=2
\end{cases}
$$

**例2：**
$$
\begin{cases}
6x-3y&=-1\\
2x-y&=4
\end{cases}
$$

$$
A|b=\begin{bmatrix}
6 & -3 & -1\\
2 & -1 & 4
\end{bmatrix} \xRightarrow{r_1单位化}
\begin{bmatrix}
1 & -\frac{1}{2} & -\frac{1}{6}\\
2 & -1 & 4
\end{bmatrix}
\xRightarrow{r_2-2r_1}
\begin{bmatrix}
1 & -\frac{1}{2} & -\frac{1}{6}\\
0 &  0 & \frac{13}{3}
\end{bmatrix}\\\xRightarrow{r_2单位化}
\begin{bmatrix}
1 & -\frac{1}{2} & -\frac{1}{6}\\
0 &  0 & 1  
\end{bmatrix}\xRightarrow{r_1+\frac{1}{6}r_2}
\begin{bmatrix}
1 & -\frac{1}{2} & 0\\
0 &  0 & 1  
\end{bmatrix}
$$

$$
\because r(A)<r(A|b)\ \therefore 方程无解
$$

**例3：**
$$
\begin{cases}
6x-3y&=3\\
2x-y&=1
\end{cases}
$$

$$
A|b=\begin{bmatrix}
6 & -3 & 3\\
2 & -1 & 1
\end{bmatrix} \xRightarrow{r_1单位化}
\begin{bmatrix}
1 & -\frac{1}{2} & \frac{1}{2}\\
2 & -1 & 1
\end{bmatrix}
\xRightarrow{r_2-2r_1}
\begin{bmatrix}
1 & -\frac{1}{2} & \frac{1}{2}\\
0 &  0 & 0
\end{bmatrix}\
$$

$$
\because r(A)=r(A|b)<n\ \therefore 方程有无穷解
\\通解为\begin{cases}
x=\frac{k}{2}+\frac{1}{2}\\
y=k
\end{cases}\ \ 其中k\in R
$$



## 六、模版

```c++
double a[200][200];  
const double eps = 1e-8;
int Gauss(int n, int m){//高斯消元，n行，m列，其中第m列为增广列。  
	int w = 1;//记录主元数，第c列应该从第w行开始  
	for (int c = 1; c <= m; c++){//枚举列。  
		int temp = w;
		for (int i = w + 1; i <= n; i++)
			if (abs(a[i][c]) > fabs(a[temp][c])) temp = i;
		if (abs(a[temp][c]) <= eps) continue;//不存在主元
		for (int j = c; j <= m; j++) swap(a[temp][j], a[w][j]);//交换行。
		for (int j = m; j >= c; j--) a[w][j] /= a[w][c];//将a[w][c]单位化
		for (int i = 1; i <= n; i++) if (i != w)//消元
			for (int j = m; j >= c; j--) a[i][j] -= a[i][c] * a[w][j];
		w++;
	}	
	if (abs(a[w - 1][m - 1]) <= eps) return -1;//最后一行非零行增广列前一列非零，无解
	return m - w;//若自由元大于0，则无穷解,否则有唯一解，且 xi = a[i][m]。
}
```

## 七、例题

模版高斯消元法
