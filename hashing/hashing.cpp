#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    ifstream input("input.bin", ios::binary);
    int n;
    input.read(reinterpret_cast<char*>(&n), sizeof(n));

    vector<int> A(n);
    unordered_map<int, bool> seen;
    vector<int> unique;

    for (int i = 0; i < n; i++) {
        input.read(reinterpret_cast<char*>(&A[i]), sizeof(A[i]));
        if (!seen[A[i]]) {
            unique.push_back(A[i]);
            seen[A[i]] = true;
        }
    }

    input.close();

    ofstream output("output.bin", ios::binary);

    int k = unique.size();
    output.write(reinterpret_cast<char*>(&k), sizeof(k));

    for (int num : unique) {
        output.write(reinterpret_cast<char*>(&num), sizeof(num));
    }

    output.close();

    return 0;
}
