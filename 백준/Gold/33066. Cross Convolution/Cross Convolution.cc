#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, K, S;
    if (!(cin >> N >> M >> K >> S)) return 0;

    // 1-based indexing을 사용하여 패딩을 줌 (인덱스 계산 실수 방지)
    // 값의 범위와 합을 고려하여 long long 사용
    vector<vector<long long>> A(N + 1, vector<long long>(M + 1));
    
    // 입력 받기
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            cin >> A[i][j];
        }
    }

    // 누적 합 배열 선언
    // r_psum[i][j]: i번째 행의 1열부터 j열까지의 합
    // c_psum[i][j]: j번째 열의 1행부터 i행까지의 합
    vector<vector<long long>> r_psum(N + 1, vector<long long>(M + 1, 0));
    vector<vector<long long>> c_psum(N + 1, vector<long long>(M + 1, 0));

    // 누적 합 미리 계산 (Preprocessing)
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            r_psum[i][j] = r_psum[i][j-1] + A[i][j];
            c_psum[i][j] = c_psum[i-1][j] + A[i][j];
        }
    }

    int mid = K / 2; // 커널 중심까지의 거리 (반지름)

    // 커널 이동 (Stride S)
    // i, j는 커널의 좌상단(Left-Top) 좌표
    for (int i = 1; i <= N - K + 1; i += S) {
        for (int j = 1; j <= M - K + 1; j += S) {
            
            // 커널의 정중앙 좌표 계산
            int ci = i + mid; 
            int cj = j + mid; 

            // 1. 가로 성분 합 (Row Sum)
            // 중심 행(ci)에서, 커널의 좌측 끝(j)부터 우측 끝(j+K-1)까지의 합
            long long h_sum = r_psum[ci][j + K - 1] - r_psum[ci][j - 1];

            // 2. 세로 성분 합 (Column Sum)
            // 중심 열(cj)에서, 커널의 상단 끝(i)부터 하단 끝(i+K-1)까지의 합
            long long v_sum = c_psum[i + K - 1][cj] - c_psum[i - 1][cj];

            // 3. 최종 합 계산
            // 중심값이 가로 합과 세로 합에 모두 포함되었으므로 한 번 빼줌
            long long total = h_sum + v_sum - A[ci][cj];

            cout << total << (j + S <= M - K + 1 ? " " : "");
        }
        cout << "\n";
    }

    return 0;
}
