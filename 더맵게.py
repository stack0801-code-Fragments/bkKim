import heapq
def solution(scoville,k):
    heapq.heapify(scoville); cnt = 0
    while 1:
        if len(scoville) <= 1:
            break
        num1 = heapq.heappop(scoville)
        if num1 >= k:
            break
        num2 = heapq.heappop(scoville)
        scoville.append(num1 + num2 * 2)
        cnt += 1
    cnt = cnt if heapq.heappop(scoville) >= k else -1
    return cnt

#위가 python 아래가 C++
include<algorithm>
include<vector>
include<queue>

using namespace std;

int solution(vector<int> scoville, int k) {
    priority_queue<int, vector<int>, greater<int>>pq(scoville.begin(), scoville.end());
    int cnt = 0;
    while (true) {
        if (pq.size() <= 1)
            break;
        int num1 = pq.top(); pq.pop();
        if (num1 >= k)
            break;
        int num2 = pq.top(); pq.pop();
        pq.push(num1 + num2 * 2);
        cnt++;
    }
    cnt = pq.top() >= k ? cnt : -1;
    return cnt;
}