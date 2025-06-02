# [Gold IV] 가장 큰 정사각형 - 1915 

[문제 링크](https://www.acmicpc.net/problem/1915) 

### 성능 요약

메모리: 9732 KB, 시간: 8 ms

### 분류

다이나믹 프로그래밍

### 제출 일자

2025년 6월 2일 13:49:35

### 문제 설명

<p>n×m의 0, 1로 된 배열이 있다. 이 배열에서 1로 된 가장 큰 정사각형의 크기를 구하는 프로그램을 작성하시오.</p>

<table class="table table-bordered" style="width: 16%">
	<tbody>
		<tr>
			<td style="width: 4%; text-align: center;">0</td>
			<td style="width: 4%; text-align: center;">1</td>
			<td style="width: 4%; text-align: center;">0</td>
			<td style="width: 4%; text-align: center;">0</td>
		</tr>
		<tr>
			<td style="text-align: center;">0</td>
			<td style="text-align: center;">1</td>
			<td style="text-align: center;">1</td>
			<td style="text-align: center;">1</td>
		</tr>
		<tr>
			<td style="text-align: center;">1</td>
			<td style="text-align: center;">1</td>
			<td style="text-align: center;">1</td>
			<td style="text-align: center;">0</td>
		</tr>
		<tr>
			<td style="text-align: center;">0</td>
			<td style="text-align: center;">0</td>
			<td style="text-align: center;">1</td>
			<td style="text-align: center;">0</td>
		</tr>
	</tbody>
</table>

<p>위와 같은 예제에서는 가운데의 2×2 배열이 가장 큰 정사각형이다.</p>

### 입력 

 <p>첫째 줄에 n, m(1 ≤ n, m ≤ 1,000)이 주어진다. 다음 n개의 줄에는 m개의 숫자로 배열이 주어진다.</p>

### 출력 

 <p>첫째 줄에 가장 큰 정사각형의 넓이를 출력한다.</p>

### 문제 풀이
 <p>이 문제는 dp 문제로 먼저 자기 자신의 구역이 1인지 확인한다. 만약에 1이라면 자기 구역의 dp를 1로 두고 i-1,j-1,(i-1,j-1)의 map이 1인지 확인하고 그 중에 dp의 값 중 제일 작은 값에 1을 더해 dp를 구해준다. 왜냐하면 가장 작은 값을 골라야 나머지가 그 값들 이상의 정사각형의 변을을 가지는 것이기 때문이다. 그래서 가장 큰 dp의 값을 2번 곱해주면 답이 나온다.(가장 큰 정사각형을 구하는 것이기 때문이다.) </p>

