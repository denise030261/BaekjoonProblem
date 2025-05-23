# [Gold IV] 가장 긴 증가하는 부분 수열 4 - 14002 

[문제 링크](https://www.acmicpc.net/problem/14002) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

다이나믹 프로그래밍, 역추적

### 제출 일자

2025년 5월 18일 21:34:11

### 문제 설명

<p>수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.</p>

<p>예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 가장 긴 증가하는 부분 수열은 A = {<strong>10</strong>, <strong>20</strong>, 10, <strong>30</strong>, 20, <strong>50</strong>} 이고, 길이는 4이다.</p>

### 입력 

 <p>첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.</p>

<p>둘째 줄에는 수열 A를 이루고 있는 A<sub>i</sub>가 주어진다. (1 ≤ A<sub>i</sub> ≤ 1,000)</p>

### 출력 

 <p>첫째 줄에 수열 A의 가장 긴 증가하는 부분 수열의 길이를 출력한다.</p>

<p>둘째 줄에는 가장 긴 증가하는 부분 수열을 출력한다. 그러한 수열이 여러가지인 경우 아무거나 출력한다.</p>

### 문제 풀이
 <p> 수열의 수가 점점 증가를 해야하고 이를 나타내야 하는 문제이다. 그래서 dp를 통해서 입력받을 때마다 처음부터 현재 입력 받은 부분까지 증가하는 수열인지 확인하고 그 다음으로 역으로 가장 긴 부분수열의 끝부분의 dp를 따라서 처음부분까지 수열을 구하면된다.</p>

