#include <iostream> 
#include <vector> 

using namespace std;

const int MAXN = 500;

int n;
vector<vector<int>> r(MAXN, vector<int>(MAXN));

void transitive_closure() {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if ((r[i][k] == 1 && r[k][j] == 1) || i == j)
                    r[i][j] = 1;
            }
        }
    }
}

int main() {
    string input;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> input;
        for (int j = 0; j < n; j++)
            r[i][j] = input[j] - '0';
    }

    transitive_closure();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << r[i][j];
        }
        cout << endl;
    }
    return 0;
}
