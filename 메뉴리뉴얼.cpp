#include <algorithm>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

bool visited[11];
int maxSize[11];
map<string, int>m;

void DFS(string order, int course, int idx, int accu) {

    if (accu == course) {
        string key;
        for (int i = 0; i < order.length(); i++) {
            if (key.length() == idx)
                break;
            if (visited[i])
                key += order[i];
        }
        sort(key.begin(), key.end());
        m[key]++;
        maxSize[course] = max(maxSize[course], m[key]);
        return;
    }

    for (int i = idx; i < order.length(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            DFS(order, course, i + 1, accu + 1);
            visited[i] = false;
        }
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string>answer;
    for (auto order : orders) {
        for (auto cnt : course) {
            memset(visited, false, sizeof(visited));
            DFS(order, cnt, 0, 0);
        }
    }

    for (auto map : m) {
        for (auto cours : course) {
            if (map.second != 1 && map.first.length() == cours && map.second == maxSize[cours])
                answer.push_back(map.first);
        }
            
    }
            
    sort(answer.begin(), answer.end());
    return answer;
}