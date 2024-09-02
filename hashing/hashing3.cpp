#include <iostream>
#include <vector>
#include <list>

using namespace std;

class HashMap {
    vector<list<pair<uint32_t, int>>> buckets;
    uint32_t capacity, size = 0;

public:
    HashMap(uint32_t capacity) : capacity(capacity) {
        buckets.resize(capacity);
    }

    uint32_t hashFunction(uint32_t key) const {
        return key % capacity;
    }

    bool add(uint32_t key, int value) {
        uint32_t index = hashFunction(key);
        for (auto& pair : buckets[index]) {
            if (pair.first == key) {
                return false; // Ключ уже существует
            }
        }
        buckets[index].emplace_back(key, value);
        size++;
        return true;
    }

    int get(uint32_t key) const {
        uint32_t index = hashFunction(key);
        for (const auto& pair : buckets[index]) {
            if (pair.first == key) {
                return pair.second;
            }
        }
        return -1;
    }
};

int main() {
    HashMap hashTable(50000);
    uint32_t i, inputKey;
    for (i = 1; i <= 20000000; i++) {
        cout << "eval " << i << endl;
        cin >> inputKey;
        if (!hashTable.add(inputKey, i)) {
            break;
        }
    }
    cout << "answer " << hashTable.get(inputKey) << " " << i << endl;
}
