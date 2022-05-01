#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

bool visited[101][101];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int areaCnt;
int biggestCnt;

void BFS(int startX, int startY,int m,int n,vector<vector<int>>picture) {
	queue<pair<int, int>>q;
	q.push({ startX,startY });
	visited[startX][startY] = true;
	int cnt = 1;

	while (!q.empty()) {
		pair<int,int>temp = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int calcX = temp.first + dx[i];
			int calcY = temp.second + dy[i];

			if (calcX < 0 || calcX >= m || calcY < 0 || calcY >= n)
				continue;
			if (picture[calcX][calcY] != picture[startX][startY] || picture[calcX][calcY] == 0)
				continue;
            		if(visited[calcX][calcY])
                		continue;
			visited[calcX][calcY] = true;
			q.push({ calcX,calcY });
			cnt++;
		}
	}
	biggestCnt = max(biggestCnt, cnt);
}

vector<int> solution(int m, int n, vector<vector<int>> picture) { 
	memset(visited, false, sizeof(visited));
    areaCnt = 0; biggestCnt = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (picture[i][j] != 0 && !visited[i][j]) {
				areaCnt++;
				BFS(i, j,m,n,picture);
			}
		}
	}
	return { areaCnt,biggestCnt };
}
