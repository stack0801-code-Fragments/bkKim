#include<algorithm>
#include<vector>
#include<stack>

using namespace std;

int solution(string s)
{
	stack<char>st1;
	stack<char>st2;

	for (int i = 0; i < s.length(); i++)
		st1.push(s[i]);

	while (!st1.empty()) {
		char ch1 = st1.top(); st1.pop();
		if (st1.size() >= 1 && ch1 == st1.top())
			st1.pop();
		else if (!st2.empty() && ch1 == st2.top()) 
			st2.pop();		
		else
			st2.push(ch1);
	}
	
	if (st1.empty() && st2.empty())
		return 1;
	return 0;
}