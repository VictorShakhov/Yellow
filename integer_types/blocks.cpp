#include <iostream>

using namespace std;

int main() {
    uint N, R, W, H, D;
    uint64_t result = 0, volume = 1;
    cin >> N >> R;
    for (unsigned int i = 0; i < N; i++)
    {
        cin >> W >> H >> D;
        volume = volume * W * H * D;
        result += volume * R;
        volume = 1;
    }
    cout << result << endl;
    return 0;
}
