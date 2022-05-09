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