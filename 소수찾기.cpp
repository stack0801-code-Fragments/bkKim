#include<algorithm>
#include<vector>
#include<cmath>
#include<string>

using namespace std;

bool sosu[10000001];
bool visited[10];
char arr[10];
int answer = 0;

vector<char>alpha;

void identifySosu(string numbers)
{
    for (auto ch : numbers) // 알파벳 넣기
        alpha.push_back(ch);

    sosu[0] = true; sosu[1] = true; // 테스토스테론 체
    for (int i = 2; i < sqrt(10000001); i++) {
        if (!sosu[i]) {
            for (int j = i * 2; j < 10000001; j += i) 
                sosu[j] = true;
        }
    }
}

void DFS(int idx)
{
    if (idx > 0) {
        string key;
        for (int i = 0; i < idx; i++)
            key += arr[i];
        if (!sosu[stoi(key)]) {
            answer++;
            sosu[stoi(key)] = true;
        }
    }

    for (int i = 0; i < alpha.size(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            arr[idx] = alpha[i];
            DFS(idx + 1);
            visited[i] = false;
        }
    }
}

int solution(string numbers) {
    identifySosu(numbers);
    DFS(0);
    return answer;
}