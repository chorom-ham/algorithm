#include <cstdio>
#include <fstream>
#define INF 9999
using namespace std;

//arr : 가중치 인접 행렬. arr[i][j]: 정점 i에서 정점 j까지의 가중치
//노드 개수의 최대가 100이므로 101*101짜리 행렬 선언
int arr[101][101];

int n, m; //n: 정점의 개수, m: 방향 에지의 개수

int main() {
	int i, j, k;

	//arr의 모든 원소를 9999(에지가 없는 상태)로 초기화. i=j일 때는 0.
	for (i = 0; i < 101; ++i) {
		for (j = 0; j < 101; ++j) {
			if (i == j) arr[i][j] = 0;
			else arr[i][j] = INF;
		}
	}

	//파일에서 입력받기
	FILE *fp;			//파일 포인터 선언
	fopen_s(&fp, "graph6.txt", "r"); //괄호안에 읽을 파일 경로를 입력한다
	printf("graph6.txt\n");

	if (fp == NULL)			// 파일이 없거나 찾지 못한 오류 발생 시 
	{
		printf("파일 오픈 불가\n");    //화면에 오류 표시
		fclose(fp);
	}

	fscanf_s(fp, "%d %d\n", &n, &m);

	//방향 에지의 개수만큼 입력받아 arr를 초기화한다
	int v1, v2, w;
	for (i = 0; i < m; ++i) {
		fscanf_s(fp, "%d %d %d\n", &v1, &v2, &w);
		arr[v1][v2] = w;
	}

	// 1. 가중치 방향 그래프를 파일로부터 입력 받아 가중치 인접 행렬로 나타내어 출력
	printf("Adjacency Matrix\n");

	//입력 받은 노드 개수 n*n만큼 행렬 사용 및 출력
	for (i = 1; i < n + 1; ++i) {
		for (j = 1; j < n + 1; ++j) {
			printf("%4d ", arr[i][j]);
		}
		printf("\n"); //줄바꿈
	}
	printf("\n"); //줄바꿈


	/*
	2. 인접 행렬을 이용하여 그래프의 각 정점을 출발 정점으로 하여
	나머지 모든 정점까지의 최단 경로(shortest path)를
	Dijkstra의 알고리즘을 이용하여 구하고 출력
	*/

	int vnear, min;

	//배열크기가 101인 이유는 정점 최대 개수가 100이기 때문.
	bool visited[101]; //이미 방문한 정점인지 확인용
	int length[101]; //length[k]: 시작 정점에서 vk로 가는 최단 경로 거리

	//각 정점을 출발 정점으로 하여(i가 출발 정점) 나머지 모든 정점까지의 최단 경로 출력
	for (i = 1; i < n + 1; ++i) {
		printf("Shortest path from v%d = (", i);

		//visited와 length배열을 초기화(시작 정점이 바뀔 때마다)
		for (j = 1; j < n + 1; ++j) {
			visited[j] = 0; //방문 여부 다 false로
			length[j] = arr[i][j];  //초기 경로 가중치 최소값은 입력 받은 값으로 초기화
		}
		visited[i] = 1; //시작 정점은 방문여부 = true

		//n-1번 반복
		for (j = 0; j < n; ++j) {
			min = INF;
			//아직 방문하지 않은 정점 중에 그 정점으로 가는 최소값을 min에, 그 정점의 인덱스를 vnear에 저장
			for (k = 1; k < n + 1; ++k) {
				if (!visited[k] && length[k] < min) {
					min = length[k];
					vnear = k; //거리가 가장 가까운 정점 인덱스
				}
			}
			//현재 거리가 가장 짧은 정점을 선택하고 방문 표시
			visited[vnear] = true;

			for (k = 1; k < n + 1; ++k) {
				//정점k를 방문하지 않았고 기존 k까지의 거리보다 vnear인덱스의 노드를 거쳐가는 거리(경로 가중치)가 더 작을 경우 거리 업데이트
				if (!visited[k] && length[vnear] + arr[vnear][k] < length[k]) {
					length[k] = length[vnear] + arr[vnear][k];
				}
			}
		}

		//각 정점에 대하여 나머지 모든 정점까지의 최단 경로(거리) 출력
		for (j = 1; j < n; ++j) {
			printf("%3d, ", length[j]);
		}
		printf("%3d)\n", length[n]);
	}
}
