#include<algorithm>
#include<vector>

using namespace std;

bool visited[501][501][4];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
vector<int>answer;

pair<int, int> calcNext(int x, int y, int direction,vector<string>grid) {
    int calcX = x + dx[direction];
    int calcY = y + dy[direction];

    if (calcX < 0)
        calcX = grid.size() - 1;
    else if (calcX >= grid.size())
        calcX = 0;

    if (calcY < 0)
        calcY = grid[0].size() - 1;
    else if (calcY >= grid[0].size())
        calcY = 0;
    return { calcX,calcY };
}

void DFS(int curX, int curY, int direction, vector<string>grid, int deep) {

    while (!visited[curX][curY][direction]) {
        visited[curX][curY][direction] = true;
        
        curX = (curX + dx[direction] + grid.size()) % grid.size();
        curY = (curY + dy[direction] + grid[0].size()) % grid[0].size();
        char nextNode = grid[curX][curY];        

        if (direction == 0) {
            if (nextNode == 'R') direction = 3;
            else if (nextNode == 'S') direction = 0;
            else direction = 1;
        }
        else if (direction == 1) {
            if (nextNode == 'R') direction = 0;
            else if (nextNode == 'S') direction = 1;
            else direction = 2;
        }
        else if (direction == 2) {
            if (nextNode == 'R') direction = 1;
            else if (nextNode == 'S')direction = 2;
            else direction = 3;
        }
        else {
            if (nextNode == 'R') direction = 2;
            else if (nextNode == 'S') direction = 3;
            else direction = 0;
        }
        deep++;
    }    
    answer.push_back(deep);
    return;    
}

vector<int> solution(vector<string> grid) {
    
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            for (int k = 0; k < 4; k++) {
                if (!visited[i][j][k]) {
                    DFS(i, j, k, grid,0);
                }
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}