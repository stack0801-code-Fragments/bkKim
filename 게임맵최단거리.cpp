#include <vector>
#include <queue>

using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
bool visited[101][101];

class oper {
public:
    int x, y, cnt;
};

int solution(vector<vector<int> > maps)
{
    queue<oper>q;
    q.push({ 0,0,0 });
    visited[0][0] = true;

    while (!q.empty()) {
        oper temp = q.front();
        q.pop();

        if (temp.x == maps.size() - 1 && temp.y == maps[0].size() - 1)
            return temp.cnt + 1;

        for (int i = 0; i < 4; i++) {
            int calcX = temp.x + dx[i];
            int calcY = temp.y + dy[i];

            if (calcX < 0 || calcX >= maps.size() || calcY < 0 || calcY >= maps[0].size())
                continue;
            if (visited[calcX][calcY] || maps[calcX][calcY] == 0)
                continue;

            q.push({ calcX,calcY,temp.cnt + 1 });
            visited[calcX][calcY] = true;
        }
    }
    return -1;
}