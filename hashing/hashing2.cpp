#include <iostream>
#include <unordered_map>
#include <cstdint>

using namespace std;

uint64_t func(uint64_t state, uint64_t firstParameter, uint64_t secondParameter, uint64_t thirdParameter, uint64_t generatorModulus) {
    return (state * state * firstParameter + state * secondParameter + thirdParameter) % generatorModulus;
}

int main() {
    uint64_t generatorModulus, firstParameter, secondParameter, thirdParameter;
    cin >> generatorModulus >> firstParameter >> secondParameter >> thirdParameter;

    unordered_map<uint64_t, uint64_t> stateMap;
    uint64_t state = 1;
    uint64_t left = 0, right = 0;
    bool cycleFound = false;

    for (uint64_t i = 0; !cycleFound; i++) {
        if (stateMap.find(state) != stateMap.end()) {
            left = stateMap[state];
            right = i;
            cycleFound = true;
        }
        else {
            stateMap[state] = i;
            state = func(state, firstParameter, secondParameter, thirdParameter, generatorModulus);
        }
    }

    cout << left << " " << right << endl;
    return 0;
}
