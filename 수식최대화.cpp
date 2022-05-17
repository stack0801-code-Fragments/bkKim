#include<algorithm>
#include<vector>
#include<string>
#include<stack>

using namespace std;

typedef long long ll;
vector<ll>numbers;
vector<char>operations;
ll maxValue = -1e9;

void split(string str) {
	string temp;
	for (int i = 0; i <= str.length(); i++) {
		if (str[i] == '-' || str[i] == '+' || str[i] == '*' || str[i] == '\0') {
			if (str[i] != '\0')
				operations.push_back(str[i]);
			numbers.push_back(stoll(temp));
			temp = "";
		}
		else temp += str[i];
	}
}

ll calc(ll num1, ll num2,char op) {
	if (op == '-')
		return num1 - num2;
	else if (op == '+')
		return num1 + num2;
	return num1 * num2;
}

long long solution(string expression) {
	split(expression);
	vector<string>priority_op{ "-+*","-*+","+-*","+*-","*+-","*-+" };

	for (auto ops : priority_op) { // -+*
		vector<char>tempOperations = operations; // 기호 복사
		stack<ll>s1; stack<ll>s2;				 // 스택 생성

		for (int i = numbers.size() - 1; i >= 0; i--) // s1스택에 numbers값 넣고
			s1.push(numbers[i]);

		for (auto op : ops) { // -,  +,  *
			while (find(tempOperations.begin(), tempOperations.end(), op) != tempOperations.end()) {            // 현재 기호 벡터에서 op에 해당하는 기호가 있다면 반복
				int index = find(tempOperations.begin(), tempOperations.end(), op) - tempOperations.begin();    // 기호 index값 찾고

				for (int i = 0; i < index; i++) {																// 기호 index값 전까지 s1값 s2로 이전
					s2.push(s1.top()); s1.pop();
				}

				ll num1 = s1.top(); s1.pop();
				ll num2 = s1.top(); s1.pop();
				ll result = calc(num1, num2, op); // 계산
				s1.push(result);				  // 결과값 넣기
				while (!s2.empty()) {			  // s1에 넣었던값 다시 s2로
					s1.push(s2.top()); s2.pop();
				}
				tempOperations.erase(index + tempOperations.begin()); // 기호 삭제
			}
		}
		maxValue = max(maxValue, abs(s1.top()));
	}
	return maxValue;
}

int main()
{
	cout << solution("100-200*300-500+20");
}