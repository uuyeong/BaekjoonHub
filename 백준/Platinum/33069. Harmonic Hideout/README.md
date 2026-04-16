# [Platinum IV] Harmonic Hideout - 33069 

[문제 링크](https://www.acmicpc.net/problem/33069) 

### 성능 요약

메모리: 29396 KB, 시간: 164 ms

### 분류

자료 구조, 그리디 알고리즘, 브루트포스 알고리즘, 이분 탐색, 누적 합, 많은 조건 분기, 우선순위 큐, 매개 변수 탐색

### 제출 일자

2026년 04월 16일 11:18:22

### 문제 설명

<p>Hanbyeol and Eunha have finalized a real estate contract to create their secret hideout. They plan to shop for household appliances to make it both cozy for living and fun for spending time. They aim to fit exactly $N$ appliances into their limited hideout space.</p>

<p>They can choose from $K$ types of appliances at the appliance store, each with its own price. Hanbyeol and Eunha want to acquire $N$ appliances at the lowest possible cost.</p>

<p>However, they cannot simply choose any appliances. Hanbyeol prefers $A$ types of appliances, and Eunha prefers $B$ types. Their preferences may overlap. To reach a compromise, they have agreed that among the $N$ appliances, at least $M$ appliances must be from the types Hanbyeol prefers, and at least $M$ appliances must also be from the types Eunha prefers.</p>

<p>Please help Hanbyeol and Eunha decide which appliances to purchase under these conditions.</p>

### 입력 

 <p>The first line contains two space-separated integers: $N$, denoting the count of appliances that fit in the hideout, and $K$, denoting the count of the types of appliances that the appliance store has. ($1 \le N \le K \le 300\,000$)</p>

<p>The following line contains three space-separated integers: $M$, denoting the minimum count of bought appliances that must be from the types favored by each girl; $A$, denoting the number of types that Hanbyeol prefers; and $B$, denoting the number of types that Eunha prefers. ($1\le M \le A,B \le N$)</p>

<p>The following line contains $K$ space-separated integers: $c_1,c_2, \cdots c_K$​, where $c_i$ denotes the cost of the $i$-th type of appliance that the store has. ($1 \le c_i \le 10^9$)</p>

<p>The following line contains $A$ space-separated integers: $a_1,a_2,\cdots,a_A$​, denoting the index of appliances that Hanbyeol prefers. ($1 \le a_i \le K;$ $i \ne j \rightarrow a_i \ne a_j$​)</p>

<p>The following line contains $B$ space-separated integers: $b_1,b_2,\cdots,b_B$​, denoting the index of appliances that Eunha prefers. ($1 \le b_i \le K;$ $i\ne j \rightarrow b_i \ne b_j$​)</p>

### 출력 

 <p>Output the minimum cost to fulfill all constraints. If it is impossible, output <span style="color:#e74c3c;"><code spellcheck="false">-1</code></span> instead.</p>

