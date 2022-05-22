#include<algorithm>
#include<vector>
#include<deque>

using namespace std;

int solution(vector<int> priorities, int location) {
    deque<pair<int, int>>dq;
    vector<int>prior;
    int idx = 0;

    for (int i = 0; i < priorities.size(); i++) {
        dq.push_back({ priorities[i],i });
        prior.push_back(priorities[i]);
    }
    
    sort(prior.begin(), prior.end(), greater<int>());

    while (!dq.empty()) {
        pair<int, int>temp = dq.front();
        dq.pop_front();

        if (temp.first == prior[idx]) {
            if (temp.second == location)
                return idx + 1;
            idx++;
            continue;
        }
        dq.push_back(temp);
    }
    return 0;
}