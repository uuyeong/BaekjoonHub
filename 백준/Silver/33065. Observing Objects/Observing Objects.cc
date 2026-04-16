#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 픽셀의 RGB 정보를 저장할 구조체
struct Pixel {
    int r, g, b;
};

// 좌표 정보를 저장할 구조체
struct Point {
    int x, y;
};

int N, M;
// 최대 크기가 1000이므로 넉넉하게 선언 (전역 변수로 선언하여 스택 오버플로우 방지)
Pixel grid[1005][1005];
bool visited[1005][1005];

// 8방향 탐색을 위한 배열 (상, 하, 좌, 우, 대각선 4개)
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

// 두 픽셀의 색상이 같은지 비교하는 함수
bool isSameColor(const Pixel& p1, const Pixel& p2) {
    return (p1.r == p2.r && p1.g == p2.g && p1.b == p2.b);
}

void bfs(int startX, int startY) {
    queue<Point> q;
    q.push({startX, startY});
    visited[startX][startY] = true;
    
    // 현재 시작점의 색상 정보
    Pixel targetColor = grid[startX][startY];

    while (!q.empty()) {
        Point current = q.front();
        q.pop();

        // 8방향 탐색
        for (int i = 0; i < 8; i++) {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];

            // 1. 범위 체크
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            
            // 2. 이미 방문했는지 체크
            if (visited[nx][ny]) continue;

            // 3. 색상이 같은지 체크
            if (isSameColor(grid[nx][ny], targetColor)) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> N >> M)) return 0;

    // 입력 받기
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j].r >> grid[i][j].g >> grid[i][j].b;
            visited[i][j] = false; // 초기화
        }
    }

    int objectCount = 0;

    // 모든 픽셀을 순회
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            // 방문하지 않은 픽셀을 만나면 새로운 객체로 간주하고 탐색 시작
            if (!visited[i][j]) {
                objectCount++;
                bfs(i, j);
            }
        }
    }

    cout << objectCount << endl;

    return 0;
}
