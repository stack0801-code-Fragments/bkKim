#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int map[101][101];

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
	vector<int>answer;
	
	int num = 1;
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			map[i][j] = num++;
	
	for (int i = 0; i < queries.size(); i++) {
		int temp = map[queries[i][0] - 1][queries[i][1] - 1];
		int minValue = temp;

		for (int j = queries[i][0] - 1; j < queries[i][2] - 1; j++) {
			map[j][queries[i][1] - 1] = map[j + 1][queries[i][1] - 1];
			minValue = min(minValue, map[j][queries[i][1] - 1]);
		}
			
		for (int j = queries[i][1] - 1; j < queries[i][3] - 1; j++) {
			map[queries[i][2] - 1][j] = map[queries[i][2] - 1][j + 1];
			minValue = min(minValue, map[queries[i][2] - 1][j]);
		}			
		for (int j = queries[i][2] - 1; j > queries[i][0] - 1; j--) {
			map[j][queries[i][3] - 1] = map[j - 1][queries[i][3] - 1];
			minValue = min(minValue, map[j][queries[i][3] - 1]);
		}			
		for (int j = queries[i][3] - 1; j > queries[i][1]; j--) {
			map[queries[i][0] - 1][j] = map[queries[i][0] - 1][j - 1];
			minValue = min(minValue, map[queries[i][0] - 1][j]);
		}			
		map[queries[i][0] - 1][queries[i][1]] = temp;
		answer.push_back(minValue);
	}	
	return answer;
}