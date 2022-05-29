#include <string>
#include <vector>
#include <iostream>

using namespace std;


int d[501][501];

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    d[0][0] = triangle[0][0];

    for (int i = 0; i < triangle.size() - 1; i++) {
        for (int j = 0; j < i + 1; j++) {
            d[i + 1][j] = max(d[i + 1][j], d[i][j] + triangle[i + 1][j]);
            d[i + 1][j + 1] = max(d[i + 1][j + 1], d[i][j] + triangle[i + 1][j + 1]);
        }
    }
    for (int i = 0; i < triangle.size(); i++) 
        answer = max(answer, d[triangle.size() - 1][i]);    
    return answer;
}