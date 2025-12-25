# [Gold III] 선분 교차 1 - 17386 

[문제 링크](https://www.acmicpc.net/problem/17386) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

기하학, 선분 교차 판정

### 제출 일자

2025년 12월 25일 20:13:24

### 문제 설명

<p>2차원 좌표 평면 위의 두 선분 L<sub>1</sub>, L<sub>2</sub>가 주어졌을 때, 두 선분이 교차하는지 아닌지 구해보자.</p>

<p>L<sub>1</sub>의 양 끝 점은 (x<sub>1</sub>, y<sub>1</sub>), (x<sub>2</sub>, y<sub>2</sub>), L<sub>2</sub>의 양 끝 점은 (x<sub>3</sub>, y<sub>3</sub>), (x<sub>4</sub>, y<sub>4</sub>)이다.</p>

### 입력 

 <p>첫째 줄에 L<sub>1</sub>의 양 끝 점 x<sub>1</sub>, y<sub>1</sub>, x<sub>2</sub>, y<sub>2</sub>가, 둘째 줄에 L<sub>2</sub>의 양 끝 점 x<sub>3</sub>, y<sub>3</sub>, x<sub>4</sub>, y<sub>4</sub>가 주어진다. 세 점이 일직선 위에 있는 경우는 없다.</p>

### 출력 

 <p>L<sub>1</sub>과 L<sub>2</sub>가 교차하면 1, 아니면 0을 출력한다.</p>

### 문제 풀이
 <p>이 문제는 선분 교차 문제로 CCW을 이용해서 문제를 풀면된다. 한 선분을 기준으로 각 점을 중간점으로 두어 CCW 알고리즘을 사용한 값의 두 부호가 다르고 다른 선분도 이를 적용했을 때 부호가 다르면 선분 교차한다는 의미이다. </p>
