#include <iostream>
using namespace std;

int main() {
    int C, M, W, P, R;
    cin >> C >> M >> W >> P >> R;

    cout << (C * M - W * P >= R ? "YES" : "NO") << '\n';
    return 0;
}