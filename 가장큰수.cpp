#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string num1, string num2) {
    return num1 + num2 > num2 + num1 ? true : false;
}

string solution(vector<int> numbers) {
    vector<string>nums;
    string answer = "";

    for (auto number : numbers)
        nums.push_back(to_string(number));
    sort(nums.begin(), nums.end(), cmp);

    for (auto item : nums) 
        answer += item;
    
    if(atoi(answer.c_str()) == 0)
        return "0";
    return answer;
}