#include <iostream>

using namespace std;

int main() {
    unsigned int N, R, W, H, D;
    int64_t result = 0, volume = 1;
    cin >> N >> R;
    for (unsigned int i = 0; i < N; i++)
    {
        cin >> W >> H >> D;
        volume = volume * W * H * D * R;
        result += volume;
        volume = 1;
    }
    cout << result << endl;
    return 0;
}
