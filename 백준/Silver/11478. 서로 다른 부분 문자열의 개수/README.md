# [Silver III] 서로 다른 부분 문자열의 개수 - 11478 

[문제 링크](https://www.acmicpc.net/problem/11478) 

### 성능 요약

메모리: 212172 KB, 시간: 520 ms

### 분류

자료 구조, 해시를 사용한 집합과 맵, 문자열, 트리를 사용한 집합과 맵

### 제출 일자

2025년 2월 11일 17:34:19

### 문제 설명

<p>문자열 S가 주어졌을 때, S의 서로 다른 부분 문자열의 개수를 구하는 프로그램을 작성하시오.</p>

<p>부분 문자열은 S에서 연속된 일부분을 말하며, 길이가 1보다 크거나 같아야 한다.</p>

<p>예를 들어, ababc의 부분 문자열은 a, b, a, b, c, ab, ba, ab, bc, aba, bab, abc, abab, babc, ababc가 있고, 서로 다른것의 개수는 12개이다.</p>

### 입력 

 <p>첫째 줄에 문자열 S가 주어진다. S는 알파벳 소문자로만 이루어져 있고, 길이는 1,000 이하이다.</p>

### 출력 

 <p>첫째 줄에 S의 서로 다른 부분 문자열의 개수를 출력한다.</p>

### 문제 풀이

 <p>이 문제는 이중 for문을 통해서 문자열을 늘리면서 개수를 세면 되는데 이 때 서로 다른 문자열이어야 된다. 그래서 데이터를 저장할 때 중복되는 경우에는 저장하지 않은 set이나 map에 저장하면된다. 본인의 경우에는 map을 사용하여 구했지만 set으로 구해야 메모리와 시간을 아낄 수 있다.</p>

