def solution(progresses, speeds):
    ans = []; 
    while len(progresses) > 0:
        cnt = 0
        for i in range(len(progresses)):    
            progresses[i] += speeds[i]
        curlen = len(progresses)
        for i in range(curlen):
            if progresses[0] >= 100:
                cnt += 1
                del progresses[0]; del speeds[0]
                continue
            break
            
        if cnt > 0:
            ans.append(cnt)
    return ans
solution([95, 90, 99, 99, 80, 99],[1, 1, 1, 1, 1, 1])
#  위가 python 아래가 C++
include <string>
include <vector>
include <cstring>

using namespace std;

bool visited[100];

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    memset(visited, false, sizeof(visited));
    vector<int>ans;
    int changeCnt = 0;
    while (1)
    {        
        for (int i = 0; i < progresses.size(); i++)
            progresses[i] += speeds[i];
        int cnt = 0;
        for (int i = 0; i < progresses.size(); i++) {
            if ( progresses[i] >= 100) {
                if (!visited[i]) {
                    cnt++;
                    changeCnt++;
                    visited[i] = true;
                }
                continue;
            }
            else break;
        }
        if (cnt > 0) {
            ans.push_back(cnt);
            if (changeCnt == progresses.size())
                break;
        }          
    }
    return ans;
}