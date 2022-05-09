#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;

bool isValid(string str) {
    int value = 0;
    for (int i = 0; i < str.length(); i++) {
        if (value < 0)
            return false;

        if (str[i] == '(')
            value++;
        else
            value--;
    }
    return true;
}


string solution(string str) {

    if (str == "")
        return "";


    int cnt = 0;
    stack<char>s;
    
    for (int i = 0; i < str.length(); i++) {

        if (s.empty() && i != 0) {
            cnt = i;
            break;
        }            
        else if (s.empty() || s.top() == str[i])
            s.push(str[i]);
        else if (i == str.length() - 1 && s.top() != str[i] && s.size() == 1) {
            cnt = str.length();
        }
        else if (s.top() != str[i])
            s.pop();
    }
    if (str.length() == cnt && isValid(str.substr(0, cnt)))
        return str;
    else if (isValid(str.substr(0, cnt))) 
        return solution(str.substr(0, cnt)) + solution(str.substr(cnt));
    

    string tempStr = "(";
    tempStr += solution(str.substr(cnt));
    tempStr += ")";

    for (int i = 1; i < cnt - 1; i++) {
        if (str[i] == '(')
            tempStr += ')';
        else tempStr += '(';
    }
    return tempStr;        
}
