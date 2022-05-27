#include <vector>
#include <algorithm>
#include <iostream>
#include<map>
using namespace std;

bool solution(vector<string>arr) {
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size() - 1; i++) 
        if (arr[i] == arr[i + 1].substr(0, arr[i].length()))
            return false;    
    return true;
}

// bool cmp(string str1, string str2) {
//     return str1.length() < str2.length();
// }
// 
//bool solution(vector<string> arr) {
//
//    sort(arr.begin(), arr.end(), cmp);
//
//    for (int i = 0; i < arr.size() - 1; i++) {
//        for (int j = i + 1; j < arr.size(); j++) {
//            if (arr.size() - j >= 2) {
//                if (arr[j].substr(0, arr[i].length()) == arr[i] || arr[j + 1].substr(0, arr[i].length()) == arr[i])
//                    return false;
//                j++;
//            }
//            else 
//                if (arr[j].substr(0, arr[i].length()) == arr[i])
//                    return false;            
//        }
//    }
//    return true;
//}

int main() {

    vector<string>v{ "123", "456", "789" };
    solution(v);
}