import math

def solution(w,h):
    gcd = math.gcd(w,h)    
    return w * h - gcd * ((w / gcd) + (h / gcd) + 1)

# 위가 Python 아래가 C++

include<vector>
using namespace std;

int getGcd(int num1, int num2) {
	if (num1 % num2 == 0)
		return num2;
	getGcd(num2, num1 % num2);
}

int solution(int w, int h) {
	int gcd = getGcd(h, w);	
	return w * h - gcd * (w / gcd + h / gcd - 1);
}