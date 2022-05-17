#include<regex>
#include<algorithm>
#include<map>

using namespace std;

bool cmp(pair<string, int>p1, pair<string, int>p2) {
	return p1.second > p2.second;
}

vector<int> solution(string s) {
	vector<int>answer;
    map<string, int>m;
	regex re("\\d+");
    
	auto begin = sregex_iterator(s.begin(), s.end(), re);
	auto end = sregex_iterator();

	for (auto it = begin; it != end; it++) {
		smatch match = *it;
		m[match.str()]++;
	}

	vector<pair<string, int>>tempM(m.begin(), m.end());
	sort(tempM.begin(), tempM.end(), cmp);
	for (auto item : tempM)
		answer.push_back(stoi(item.first));

	return answer;
}

int main()
{
	solution("{{20,111},{111}}");
}