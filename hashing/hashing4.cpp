#include <iostream>
#include <unordered_map>

using namespace std;

const int MAX_N = 1000000;
const int MAX_B = 1000000;

int total_chars, block_size, num_blocks;
char input_string[MAX_N];
unsigned long long hash_values[MAX_N], power_values[MAX_B];
unordered_map<unsigned long long, int> color_map;

void calculate_power_values() {
    power_values[0] = 1;
    for (int i = 1; i <= block_size; i++) {
        power_values[i] = power_values[i - 1] * 31;
    }
}

void calculate_hash_values() {
    for (int i = 1; i <= total_chars; i++) {
        hash_values[i] = hash_values[i - 1] * 31 + input_string[i];
        if (i >= block_size) {
            unsigned long long current_hash = hash_values[i] - hash_values[i - block_size] * power_values[block_size];
            if (color_map.count(current_hash) == 0) {
                color_map[current_hash] = color_map.size();
            }
        }
    }
}

void print_color_map() {
    for (int i = 1; i <= num_blocks; i++) {
        unsigned long long current_hash = hash_values[i + block_size - 1] - hash_values[i - 1] * power_values[block_size];
        cout << color_map[current_hash] << " ";
    }
    cout << endl;
}

int main() {
    cin >> total_chars >> block_size >> input_string + 1;
    num_blocks = total_chars - block_size + 1;

    calculate_power_values();
    calculate_hash_values();
    print_color_map();

    return 0;
}
