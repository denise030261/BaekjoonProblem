# [Gold IV] 뱀 - 3190 

[문제 링크](https://www.acmicpc.net/problem/3190) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

자료 구조, 덱, 구현, 큐, 시뮬레이션

### 제출 일자

2024년 7월 2일 18:05:34

### 문제 설명

<p> 'Dummy' 라는 도스게임이 있다. 이 게임에는 뱀이 나와서 기어다니는데, 사과를 먹으면 뱀 길이가 늘어난다. 뱀이 이리저리 기어다니다가 벽 또는 자기자신의 몸과 부딪히면 게임이 끝난다.</p>

<p>게임은 NxN 정사각 보드위에서 진행되고, 몇몇 칸에는 사과가 놓여져 있다. 보드의 상하좌우 끝에 벽이 있다. 게임이 시작할때 뱀은 맨위 맨좌측에 위치하고 뱀의 길이는 1 이다. 뱀은 처음에 오른쪽을 향한다.</p>

<p>뱀은 매 초마다 이동을 하는데 다음과 같은 규칙을 따른다.</p>

<ul>
	<li>먼저 뱀은 몸길이를 늘려 머리를 다음칸에 위치시킨다.</li>
	<li>만약 벽이나 자기자신의 몸과 부딪히면 게임이 끝난다.</li>
	<li>만약 이동한 칸에 사과가 있다면, 그 칸에 있던 사과가 없어지고 꼬리는 움직이지 않는다.</li>
	<li>만약 이동한 칸에 사과가 없다면, 몸길이를 줄여서 꼬리가 위치한 칸을 비워준다. 즉, 몸길이는 변하지 않는다.</li>
</ul>

<p>사과의 위치와 뱀의 이동경로가 주어질 때 이 게임이 몇 초에 끝나는지 계산하라.</p>

### 입력 

 <p>첫째 줄에 보드의 크기 N이 주어진다. (2 ≤ N ≤ 100) 다음 줄에 사과의 개수 K가 주어진다. (0 ≤ K ≤ 100)</p>

<p>다음 K개의 줄에는 사과의 위치가 주어지는데, 첫 번째 정수는 행, 두 번째 정수는 열 위치를 의미한다. 사과의 위치는 모두 다르며, 맨 위 맨 좌측 (1행 1열) 에는 사과가 없다.</p>

<p>다음 줄에는 뱀의 방향 변환 횟수 L 이 주어진다. (1 ≤ L ≤ 100)</p>

<p>다음 L개의 줄에는 뱀의 방향 변환 정보가 주어지는데,  정수 X와 문자 C로 이루어져 있으며. 게임 시작 시간으로부터 X초가 끝난 뒤에 왼쪽(C가 'L') 또는 오른쪽(C가 'D')로 90도 방향을 회전시킨다는 뜻이다. X는 10,000 이하의 양의 정수이며, 방향 전환 정보는 X가 증가하는 순으로 주어진다.</p>

### 출력 

 <p>첫째 줄에 게임이 몇 초에 끝나는지 출력한다.</p>

### 문제 풀이

<p> 이 문제는 벡터와 덱을 사용하여 구현한다. 뱀의 역할은 덱에 맡기고 벡터는 방향이 전환될 시간과 문자가 저장되어 있다. 그래서 덱을 사용하여 각 벡터의 시간의 흐름에 따라 뱀이 움직이고 시간이 끝나면 방향을 전환하고 다시 다음 벡터의 시간을 흐르게 만든다. 움직일 때는 움직일 방향의 위치를 덱에 푸시하고 back은 pop을 한다. 이 때 배열에 저장한 사과의 위치를 만나면 다음 위치만 푸시한다. 만약 벽에 부딪히거나 뱀 자신을 부딪히면 거기서 끝나고 지금까지의 시간을 출력한다.  </p>

