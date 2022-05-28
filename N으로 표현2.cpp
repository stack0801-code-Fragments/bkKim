#include <string>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

typedef long long ll;
int arr[288001];

void BFS(int n, int target) {
    queue<pair<int, int>>q; // 값 , 카운트
    for (int i = 0; i < 288001; i++) // 모든 값 9로 세팅
        arr[i] = 9;
    
    for (int i = n, cnt = 1; i <= n * target; i = i * 10 + n) { // 5, 55, 555
        q.push({ i,cnt });
        arr[i] = cnt++;
    }
    
    while (!q.empty()) {
        pair<int, int>temp = q.front();
        q.pop();

        if (temp.second > 8)
            return;

        if (temp.first >= 0 && temp.first <= 288001) 
            arr[temp.first] = min(arr[temp.first], temp.second);

        q.push({ temp.first + n,temp.second + 1 });
        q.push({ temp.first - n,temp.second + 1 });
        q.push({ temp.first / n,temp.second + 1 });
        q.push({ temp.first * n,temp.second + 1 });
    }
}

int solution(int n, int target) {
    BFS(n, target);
    int result = 0;
        
    for (int i = 1; i <= target; i++) {
        for (int j = 0; j <= i / 2; j++) {
            arr[i] = min(arr[i], arr[i - j] + arr[j]); // 덧셈          
            arr[i - j] = min(arr[i - j], arr[i] + arr[j]); // 뺄셈
            if (j > 0 && i % j == 0) {
                arr[i] = min(arr[i], arr[i / j] + arr[j]);  //곱하기
                arr[i / j] = min(arr[i / j], arr[i] + arr[j]); // 나누기
            }
        }
    }
    result = arr[target] > 8 ? -1 : arr[target];
    return result;
}
// 나중에 찬현이 방법으로 
