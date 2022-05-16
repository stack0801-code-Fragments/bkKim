#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

bool visited[5][5][26];
int dx[] = { 1,0,-1,0 }; //하 우 상 좌
int dy[] = { 0,1,0,-1 };

class oper {
public:
	int x, y, personNumber, cnt;
};

int BFS(vector<string>place)
{
	memset(visited, false, sizeof(visited));
	queue<oper>q;
	int personCnt = 1;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (place[i][j] == 'P') {
				visited[i][j][personCnt] = true;
				q.push({ i,j,personCnt++,2 });
			}
		}
	}

	while (!q.empty()) {
		oper temp = q.front();
		q.pop();

		if (!temp.cnt) {
			if (place[temp.x][temp.y] == 'P')
				return 0;
			continue;
		}

		for (int i = 0; i < 4; i++) {
			int calcX = temp.x + dx[i];
			int calcY = temp.y + dy[i];
			
			if (calcX < 0 || calcX >= 5 || calcY < 0 || calcY >= 5)
				continue;
			if (visited[calcX][calcY][temp.personNumber])
				continue;
			if (place[calcX][calcY] == 'X')
				continue;
			if (place[calcX][calcY] == 'P')
				return 0;

			q.push({ calcX,calcY,temp.personNumber,temp.cnt - 1 });
			visited[calcX][calcY][temp.personNumber] = true;
		}
	}
	return 1;
}

vector<int> solution(vector<vector<string>> places) {
	vector<int>answer;
	for (auto place : places)  // 한줄
		answer.push_back(BFS(place));
	return answer;
}

int main()
{
	vector<vector<string>>v{ {"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"},
							 {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"},
							 {"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"},
							 {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"},
							 {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"} };
	solution(v);
}