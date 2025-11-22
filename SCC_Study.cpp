#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#define MAX 10000
using namespace std;

int id = 1, P[MAX]; //id: 정점번호, P: 
bool finished[MAX]; //SCC에 속한 정점 체크
vector<int> A[MAX]; //정점x와 인접한 정점들을 가지는 리스트
stack<int> S; //DFS에 사용될 스택
vector<vector<int>> SCC; //찾은 SCC들을 저장


int findSCCusingDFS(int x) {
	P[x] = id++;
	S.push(x);

	int parent = P[x];
	for (int i = 0; i < A[x].size(); i++) {
		int y = A[x][i]; //다음 요소
		if (P[y] == 0)
			parent = min(parent, findSCCusingDFS(y)); 
		else if (!finished[y])
			parent = std::min(parent, P[y]); 
	}
    
	if (parent == P[x]) {  //부모정점에서만 SCC를 추출하는 2번과정을 실행시킨다.
		vector<int> scc;
		while (x) {
			int y = S.top(); 
			S.pop(); //스택에서 하나씩 POP
			scc.push_back(y); //뽑은 정점을 하나의 scc로 추가
			finished[y] = true; //POP한 정점이 SCC에 속해있음을 체크
			if (y == x) break; //자기자신이 나오면 멈춤
		}
		std::sort(scc.begin(), scc.end()); //찾은 scc내 원소들 정렬
		SCC.push_back(scc); //찾은 scc를 저장
	}
	return parent;
}

int main(void) {
	A[1].push_back(2); //현재 그래프 상태대로 A를 작성해줍니다.
	A[2].push_back(3);
	A[3].push_back(1);
	A[4].push_back(5);
	A[5].push_back(3);
	A[5].push_back(4);
	A[5].push_back(6);
	A[5].push_back(10);
	A[6].push_back(7);
	A[7].push_back(8);
	A[8].push_back(9);
	A[9].push_back(6);
	A[10].push_back(11);
	for (int i = 1; i <= 11; i++) {
		//방문하지않은 모든 정점(P[x] == 0)에 대해 DFS를 수행
		if (P[i] == 0) findSCCusingDFS(i);
	}
	//SCC의 상태를 출력해봅시다.
	printf("SCC의 갯수 : %d\n", SCC.size());
	for (int i = 0; i < SCC.size(); i++) {
		printf("[%d]번 SCC 요소들 :  {", i + 1);
		for (int j = 0; j < SCC[i].size(); j++) {
			if(j != SCC[i].size() - 1)
				printf("%d , ", SCC[i][j]);
			else
				printf("%d", SCC[i][j]);
		}  
		printf("}\n"); 
	}

	return 0;
}