# [Silver II] 타일링 - 1793 

[문제 링크](https://www.acmicpc.net/problem/1793) 

### 성능 요약

메모리: 2156 KB, 시간: 0 ms

### 분류

임의 정밀도 / 큰 수 연산, 다이나믹 프로그래밍

### 제출 일자

2024년 12월 28일 19:00:17

### 문제 설명

<p>2×n 직사각형을 2×1과 2×2 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.</p>

<p>아래 그림은 2×17 직사각형을 채운 한가지 예이다.</p>

<p style="text-align: center;"><img alt="" src="https://www.acmicpc.net/upload/images/t2n2122.gif" style="height:59px; width:380px"></p>

### 입력 

 <p>입력은 여러 개의 테스트 케이스로 이루어져 있다. 각 테스트 케이스는 한 줄로 이루어져 있으며, 정수 n이 주어진다.</p>

### 출력 

 <p>입력으로 주어지는 각각의 n마다, 2×n 직사각형을 채우는 방법의 수를 출력한다.</p>

### 문제 풀이
 <p> 이 문제는 dp문제로 일단 아래의 그림처럼 먼저 n을 늘리면서 생기는 타일 그림과 갯수를 세어보았다. 타일을 그리면서 규칙을 발견할 수 있게 되는데 타일을 세울 때 이전의 타일에서 2x1 타일을 사용하던가 그 이전의 타일에서 2x2타일을 사용하여 타일을 구하면 되는데 이 때 2x2타일에서 2x1타일을 나란히 세우면 2x1 타일을 세우는 방식과 중복되기 때문에 그 방식은 빼야한다. 즉, dp[i]=dp[i-1]+2*dp[i-2]의 방식으로 답을 구하면 된다. </p>
  <p>또 다른 문제점이 있는데 그것은 큰 연산을 해야한다는 문제점이 있다. 이러한 큰 연산은 long long 방식보다 큰 범위이기 때문에 문자열을 사용하면서 문제를 풀어야한다. </p>

![KakaoTalk_20241228_210157954](https://github.com/user-attachments/assets/d89e0c29-e84e-4e4d-9cbb-3b47cce54dea)
