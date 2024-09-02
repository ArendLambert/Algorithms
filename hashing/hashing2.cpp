#include <iostream>
#include <unordered_map>
#include <cstdint>

using namespace std;

uint64_t func(uint64_t s, uint64_t a, uint64_t b, uint64_t c, uint64_t M) {
    return (s * s * a + s * b + c) % M;
}

int main() {
    uint64_t M, a, b, c;
    cin >> M >> a >> b >> c;

    unordered_map<uint64_t, uint64_t> stateMap;
    uint64_t state = 1;
    uint64_t l = 0, r = 0;
    bool cycleFound = false;

    for (uint64_t i = 0; !cycleFound; i++) {
        if (stateMap.find(state) != stateMap.end()) {
            l = stateMap[state];
            r = i;
            cycleFound = true;
        }
        else {
            stateMap[state] = i;
            state = func(state, a, b, c, M);
        }
    }

    cout << l << " " << r << endl;
    return 0;
}
