#include<algorithm>
#include<vector>

using namespace std;

pair<int, int> isValid(string p) {
	int value = 0;
	int idx = 0;

	for (int i = 0; i < p.length(); i++) {
		if (i != 0 && value == 0) 
			break;
		p[i] == '(' ? value++ : value--;
		idx++;
	}

	if (p[0] == '(' && idx == p.length()) //즉 올바른 문자열
		return { idx,2 };
	else if (p[0] == '(') // 올바른인데 전부가 아닌경우
		return { idx,1 };
	return { idx,0 }; // 올바른 문자 아닌경우
}

string solution(string p) {
	if (p == "")
		return "";

	pair<int,int> result = isValid(p);

	if (result.second == 2) //전부 올바른 문자열일때
		return p;
	else if (result.second == 1) //앞부분이 올바른 문자열일 경우
		return solution(p.substr(0, result.first)) + solution(p.substr(result.first));
		 
	string tempStr = "(" + solution(p.substr(result.first)) + ")";
	for (int i = 1; i < result.first - 1; i++) 
		p[i] == '(' ? tempStr += ')' : tempStr += '(';

	return tempStr;
}

int main()
{
	cout << solution("()))((()");
}