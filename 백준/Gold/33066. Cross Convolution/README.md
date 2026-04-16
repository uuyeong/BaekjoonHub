# [Gold IV] Cross Convolution - 33066 

[문제 링크](https://www.acmicpc.net/problem/33066) 

### 성능 요약

메모리: 96192 KB, 시간: 860 ms

### 분류

누적 합

### 제출 일자

2026년 04월 16일 11:18:22

### 문제 설명

<p>You are given an $N \times M$ matrix $A$. You are also given a special kernel of size $K \times K$, and a stride $S$. Your task is to implement a convolution-like operation using a kernel with unique properties. The kernel must always remain completely within the matrix boundaries during its operation.</p>

<p>Specifically, the unique features of a kernel in this problem are:</p>

<ul>
	<li value="1">The kernel size $K$ is always an odd number.</li>
	<li value="2">The kernel is filled with $1$ along the horizontal and vertical axes passing through the center and $0$ elsewhere.</li>
</ul>

<p>For example, the following is the kernel when the size is $3$ and $5$, respectively.</p>

<p>\[\begin{bmatrix} 0 & 1 & 0 \\ 1 & 1 & 1 \\ 0 & 1 & 0 \end{bmatrix} \qquad \begin{bmatrix} 0 & 0 & 1 & 0 & 0 \\ 0 & 0 & 1 & 0 & 0 \\ 1 & 1 & 1 & 1 & 1 \\ 0 & 0 & 1 & 0 & 0 \\ 0 & 0 & 1 & 0 & 0 \end{bmatrix}\]</p>

<p>The stride determines the step size for moving the kernel across the matrix. The kernel moves across the matrix based on the given stride. At each valid position (where the kernel fits entirely within the matrix boundaries), the element-wise sum of the matrix elements covered by the kernel is calculated.</p>

<p>Calculate a new matrix $B$ containing the sums from all valid kernel positions. The size of $B$ should be $\left(\frac{N-K}{S}+1\right) \times \left(\frac{M-K}{S}+1\right)$.</p>

### 입력 

 <p>The first line contains four space-separated integers: $N$ and $M$, denoting the size of the image; $ K$, denoting the kernel size; and $S$, denoting the stride. ($1 \le N,M \le 2\,000;$ $1 \le K, S \le \min⁡\{N,M\};$ $K \equiv 1 \pmod 2;$ $S$ is a divisor of $\gcd(N-K,M-K)$)</p>

<p>The following $N$ lines of input contain $NM$ integers, where each line has $M$ space-separated integers, denoting the value of the matrix $A$. Here, the $j$-th integer of the $i$-th line denotes $A_{ij}$. ($-10^6 \le A_{ij} \le 10^6$)</p>

### 출력 

 <p>Output $\left(\frac{N-K}{S}+1\right)$ lines denoting the resulting matrix $B$ after applying the kernel with the given stride.</p>

<p>Each line should contain $\left(\frac{M-K}{S}+1\right)$ space-separated integers. The $j$-th integer of the $i$-th line should represent $B_{ij}$​.</p>

