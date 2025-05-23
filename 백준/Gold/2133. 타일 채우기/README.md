# [Gold IV] 타일 채우기 - 2133 

[문제 링크](https://www.acmicpc.net/problem/2133) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

다이나믹 프로그래밍

### 제출 일자

2025년 5월 21일 16:17:48

### 문제 설명

<p>3×N 크기의 벽을 2×1, 1×2 크기의 타일로 채우는 경우의 수를 구해보자.</p>

### 입력 

 <p>첫째 줄에 N(1 ≤ N ≤ 30)이 주어진다.</p>

### 출력 

 <p>첫째 줄에 경우의 수를 출력한다.</p>

### 문제 풀이
 <p>이 문제는 dp로 사진과 같이 풀었다. N이 2인 경우에는 3가지의 경우가 나온다. N이 4일 때 dp[2]*dp[2] 방식과 특수한 모양 2가지의 경우가 합친다. dp[6]은 dp[6-2]*dp[2}로 푸는데 그 이후에는 맨 마지막을 특수한 모양으로 배치하고 그 나머지는 남은 만큼의 dp를 곱해준다. 이는 2*dp[i-4], 2*dp[i-6]와 같다. 또한 특수한 모양으로만 구성한 경우도 합쳐야 경우의 수를 구한다. N이 홀수 일 때는 홀수*홀수=홀수로 절대 2*1,1*2타일로는 구할 수 없기 때문에 N이 홀수면 0을 출력한다. ![image](https://github.com/user-attachments/assets/61b7239c-f4af-4ea8-85d8-a80c700dcd7d)
</p>
 

