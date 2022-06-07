#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string name) {
    int idx = 0;
    int answer = 0;
    string tempStr;
    for (int i = 0; i < name.length(); i++) tempStr += 'A';

    while (true) {
        int fcnt = 0, bcnt = 0;
        for (int i = 0; i < name.length(); i++) {
            int front = (idx + 1 + fcnt) % name.length();
            int back = (idx - 1 - bcnt + name.length()) % name.length();

            if (name[front] != 'A')
                fcnt++;
            if (name[back] != 'A')
                bcnt++;
        }

        if (fcnt > bcnt) {
            for (int i = 0; i < fcnt + 1; i++) {
                int tempIdx = (idx + i) % name.length();
                answer += min(name[tempIdx] - 'A', 'Z' - name[tempIdx]);
                tempStr[tempIdx] = name[tempIdx];
                answer++;
            }
        }
        else {
            for (int i = 0; i < bcnt + 1; i++) {
                int tempIdx = (idx - i + name.length()) % name.length();
                answer += min(name[tempIdx] - 'A', 'Z' - name[tempIdx]);
                tempStr[tempIdx] = name[tempIdx];
                answer++;
            }
        }
        idx += max(fcnt, bcnt) + 1;
    }


    return 1;
}

//실패
int main()
{
    cout << solution("ABCDEABCD");

}