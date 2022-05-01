#include<iostream>
#include<algorithm>
#include <vector>
#include <cstring>

using namespace std;

char persons[] = { 'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
char tempStr[9];
bool visited[8];
int cnt;

void isValid(char tstr[], vector<string>data) {

    for (int i = 0; i < data.size(); i++) {
        int p1Indx, p2Indx, diff;

        for (int j = 0; j < 8; j++) {
            if (tstr[j] == data[i][0])
                p1Indx = j;
            else if (tstr[j] == data[i][2])
                p2Indx = j;
        }
        diff = abs(p1Indx - p2Indx) - 1;

        if (data[i][3] == '=' && diff != data[i][4] - '0')
            return;
        else if (data[i][3] == '<' && diff >= data[i][4] - '0')
            return;
        else if (data[i][3] == '>' && diff <= data[i][4] - '0')
            return;
    }
    cnt++;
}

void makeCombination(int idx, char tStr[],vector<string>data)
{
    if (idx == 8) {
        isValid(tStr,data);
        return;
    }

    for (int i = 0; i < 8; i++) {
        if (!visited[i]) {
            visited[i] = true;
            tStr[idx] = persons[i];
            makeCombination(idx + 1, tStr,data);
            visited[i] = false;
        }
    }
}

int solution(int n, vector<string> data) {
    cnt = 0;
    memset(visited, false, sizeof(visited));
    makeCombination(0,tempStr,data);
    return cnt;
}

//위 C++ 아래 python
from itertools import permutations

global cnt; cnt = 0

def isValid(strs,condition):
    global cnt
    for i in condition:
        p1Index = strs.index(i[0]);p2Index = strs.index(i[2]);diff = int(i[4]) + 1

        if(i[3] == '=' and abs(p1Index - p2Index) != diff):
            return
        elif(i[3] == '<' and abs(p1Index - p2Index) >= diff):
            return
        elif(i[3] == '>' and abs(p1Index - p2Index) <= diff):
            return
    cnt += 1
    return

def solution(lists):
    global cnt
    persons = ['A', 'C', 'F', 'J', 'M', 'N', 'R', 'T']
    arr = list(map(''.join,permutations(persons)))

    for i in arr:
        isValid(i,lists)
    print(cnt)
    return
solution(["N~F=0", "R~T>2"])