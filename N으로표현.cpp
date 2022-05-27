#include<cmath>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;
typedef long long ll;

ll arr[288001];

void input(int N, int number) {
    for (int i = 0; i <= N * number; i++)
        arr[i] = 9;
}

int solution(int N, int number) {
    ll minValue = 0;
    int result;
    input(N,number);    
    

    // 5 55 555 카운터 등록
    for (int i = N, cnt = 1; i <= N * number; i = i * 10 + i) {
        arr[i] = cnt++;
    }
    int tencnt = 0;
    bool tenswit = false;
    int totalc = 0;
    while (true) {
        int cnt = 0;
        tencnt = 0;
        tenswit = false;
        for (int i = 0; i <= N * number; i++) {

            if (tenswit) tencnt++;
            else if (i == N) {
                tencnt = 10;
                tenswit = true;
            }            

            if (tencnt == 10) {
                if (arr[i/10] < 9 && arr[i] > arr[i / 10] + 1) {
                    arr[i] = arr[i / 10] + 1;
                    cnt++;                    
                }
                tencnt = 0;
            }                             
            if (i - N >= 0 && arr[i - N] < 9) { // + 
                if (arr[i] > arr[i - N] + 1) {
                    arr[i] = arr[i - N] + 1;
                    cnt++;
                }                
            }
            if (i + N <= N * number && arr[i + N] < 9) { // - 
                if (arr[i] > arr[i + N] + 1) {
                    arr[i] = arr[i + N] + 1;
                    cnt++;
                }
            }
            if (i % N == 0 && arr[i / N] < 9) { // *
                if (arr[i] > arr[i / N] + 1) {
                    arr[i] = arr[i / N] + 1;
                    cnt++;
                }
            }
            if (i * N <= N * number && arr[i * N] < 9) { //  /
                if (arr[i] > arr[i * N] + 1) {
                    arr[i] = arr[i * N] + 1;
                    cnt++;
                }
            }
        }        
        if (cnt == 0)
            break;
    }
    
    tencnt = 0;
    tenswit = false;
    for (int i = 1; i <= number * N; i++) {
        if (tenswit) tencnt++;
        else if (i == N) {
            tencnt = 10;
            tenswit = true;
        }
        if (tencnt == 10) {
            arr[i] = min(arr[i], arr[i / 10] + arr[i - (i / 10) * 10]);
            tencnt = 0;
        }
        for (int j = 0; j <= i / 2; j++) {
            arr[i] = min(arr[i], arr[i - j] + arr[j]); // 덧셈          
            arr[i - j] = min(arr[i - j], arr[i] + arr[j]); // 뺄셈
            if (j > 0 && i % j == 0) {
                arr[i] = min(arr[i], arr[i / j] + arr[j]);  //곱하기
                arr[i / j] = min(arr[i / j], arr[i] + arr[j]); // 나누기
            }

        }
    }

    result = arr[number] > 8 ? -1 : arr[number];
    return result;
}