#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

int calc(vector<int>numbers,int target)
{
    queue<pair<int, int>>q; // 값, 카운트
    q.push({ numbers[0],1});
    q.push({ -numbers[0],1});
    int cnt = 0;

    while (!q.empty())
    {
        pair<int, int>temp = q.front();
        q.pop();

        if (temp.second == numbers.size()) {
            if (temp.first == target) 
                cnt++;
            continue;                
        }

        q.push({ temp.first + numbers[temp.second],temp.second + 1 });
        q.push({ temp.first - numbers[temp.second],temp.second + 1 });        
    }
    return cnt;
}


int solution(vector<int> numbers, int target) {    
    return calc(numbers, target);
}

// 위가 BFS 아래가 DFS

#include<algorithm>
#include<vector>

using namespace std;
int cnt = 0;

void DFS(vector<int>numbers, int target, int idx, int currentValue)
{
	if (idx == numbers.size()) {
		if (currentValue == target)
			cnt++;		
		return;
	}	
	DFS(numbers, target, idx + 1, currentValue + numbers[idx]);
	DFS(numbers, target, idx + 1, currentValue - numbers[idx]);
}

int solution(vector<int> numbers, int target) {
	DFS(numbers, target, 0, 0);
	return cnt;
}