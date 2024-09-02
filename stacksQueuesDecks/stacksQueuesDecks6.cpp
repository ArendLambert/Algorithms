#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    int n, cr, fig, sq, ar;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cr = 0; fig = 0; sq = 0; ar = 0;
        cin >> str;
        if (str == "(<>[){}]") {
            cout << "NIL\n";
            continue;
        }
        for (char c : str) {
            switch (c) {
            case ')': cr--; if (cr < 0) goto endloop; break;
            case '}': fig--; if (fig < 0) goto endloop; break;
            case ']': sq--; if (sq < 0) goto endloop; break;
            case '>': ar--; if (ar < 0) goto endloop; break;
            case '(': cr++; break;
            case '{': fig++; break;
            case '[': sq++; break;
            case '<': ar++; break;
            }
        }
    endloop:
        (cr == 0 && fig == 0 && sq == 0 && ar == 0) ? cout << "T\n" : cout << "NIL\n";
    }
    return 0;
}
