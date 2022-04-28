#include<iostream>
#include <string>
#include <vector>
#include<algorithm>

using namespace std;

int solution(string s) {

    int minLength = s.length();

    for (int i = 1; i <= s.length() / 2; i++) { 
        string tempStr = s;
        for (int j = 0; j < tempStr.length() - i; j += i) {
            string temp = tempStr.substr(j, i);
            int cnt = 0;
            int startIndex = j;

            while (true)
            {
                if (tempStr.find(temp, startIndex) != startIndex)
                    break;
                cnt++;
                startIndex += i;
            }

            if (cnt > 1)
            {
                tempStr = tempStr.substr(0, j) + to_string(cnt) + temp + tempStr.substr(startIndex);
                j += (to_string(cnt) + temp).length() - i;                
            }
        }
        minLength = min(minLength, (int)tempStr.length());
    }
    
    return minLength;
}