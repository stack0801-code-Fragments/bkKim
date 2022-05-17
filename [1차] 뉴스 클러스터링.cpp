#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

pair<bool, string> isValid(string str,int it) { // 문자열에 알파벳만 있는지 확인
	string value;
	for (int i = it; i < it + 2; i++) {
		str[i] = tolower(str[i]);
		if (str[i] >= 97 && str[i] <= 122)
			value += str[i];
		else return {false,""};
	}
	return { true,value };
}

vector<string> calc(string str) { // 문자열을 잘라서 원소를 리턴하는 함수
	vector<string>v;
	for (int i = 0; i < str.length() - 1; i++) {
		pair<bool, string>result = isValid(str, i);
		if (result.first)
			v.push_back(result.second);
	}
	return v;
}

bool isNotNull(string str) { // 빈 문자열 아닌것만 true
	if (str != "") return true;
	return false;
}

int solution(string str1, string str2) {
	vector<string>v1 = calc(str1);
	vector<string>v2 = calc(str2);
	vector<string>v3(v1.size() + v2.size());
	vector<string>v4(v1.size() + v2.size());
    
    	if (v1.size() == 0 && v2.size() == 0) return 65536;
        
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());          // 합집합
	set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v4.begin());   // 교집합
    
	int bunmo = count_if(v3.begin(), v3.end(), isNotNull);                      // 분모
	int bunja = count_if(v4.begin(), v4.end(), isNotNull);                      // 분자

	return trunc(((double)bunja / bunmo) * 65536);;
}

int main()
{
	solution("=M*C^2", "e=m*c^2");
	return 0;
}
