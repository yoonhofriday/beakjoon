#include <iostream>
#include <vector>
using namespace std;

int answer = 0; // 합이 나오는 개수
int main() {
    int N, M;

    cin >> N >> M;
    vector<int> arr(N);
    for (int i = 0; i < N; ++i)
        cin >> arr[i];

    int start = 0;
    int end = 0;
    int sum = arr[0];
    while (end < N) {
        if (sum < M) { // sum 이 더 커져야 하는 상황. 즉 end 포인터가 더 오른쪽으로 가야 한다.
            end++;
            if (end < N)
                sum += arr[end];
        }
        else if (sum > M) { // sum 이 더 작아져야 하는 상황. 즉 start 포인터가 더 오른쪽으로 가야 한다.
            sum -= arr[start];
            start++;
        }
        else if (sum == M) { // sum 이 M 과 같아졌으므로 현재의 star, end 로는 이 다음부터는 [start, end + 1] 도, [start + 1, end] 도 답이 될 수 없다. 두 포인터 다 더 오른쪽으로 한 칸씩 이동시킨다. 
            sum -= arr[start];
            start++;
            end++;
            if (end < N)
                sum += arr[end];
            answer++;
        }
    }

    cout << answer;
}
