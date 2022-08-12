#include <iostream>
#include <vector>
using namespace std;

vector<int> dp;

int fibonacci(int n) {
    if (n == 0) return 0;   //0일때
    if (n == 1) return 1;   //1일떄
    if (dp[n] != -1) return dp[n];
    //이미 구했다면 바로 리턴
    dp[n] = fibonacci(n - 2) + fibonacci(n - 1);
    return dp[n];
}

int main() {
    int N;
    cin >> N;
    dp.resize(N + 1, -1); // 초기값 -1은 절대 나올 수 없는 값
    cout << fibonacci(N) << endl;
}
