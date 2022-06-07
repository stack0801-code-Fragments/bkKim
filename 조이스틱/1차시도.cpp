#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0, idx = 0;
    string tempStr;
    for (int i = 0; i < name.length(); i++) tempStr += 'A';
    
    while (true) {
        answer += min(name[idx] - 'A', 'Z' - name[idx] + 1);
        tempStr[idx] = name[idx];

        if (tempStr == name)
            break;

        int fcnt = 0, bcnt = 0;
        for (int i = 0; i < name.length(); i++) {
            int front = (idx + 1 + fcnt) % name.length();
            int back = (idx - 1 - bcnt + name.length()) % name.length();
            if (tempStr[front] == name[front])
                fcnt++;
            if (tempStr[back] == name[back])
                bcnt++;
        }
        if (fcnt == bcnt || fcnt < bcnt) {
            idx = (idx + 1 + fcnt) % name.length();            
            answer += fcnt + 1;
        }
        else {
            idx = (idx - 1 - bcnt + name.length()) % name.length();
            answer += bcnt + 1;
        }
                
    }
    return answer;
}