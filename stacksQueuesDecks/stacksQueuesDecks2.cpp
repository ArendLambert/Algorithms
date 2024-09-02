#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;
public:
    Stack() {
        top = NULL;
    }

    void push(int x) {
        Node* temp = new Node;
        temp->data = x;
        temp->next = top;
        top = temp;
    }

    int pop() {
        if (top == NULL) {
            return -1;
        }
        int x = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return x;
    }

    bool isEmpty() {
        return (top == NULL);
    }
};

int evaluate(string result) {
    Stack stack;
    int n = result.length();
    int num = 0;
    for (int i = 0; i < n; i++) {
        if (result[i] == ' ') continue;
        else if (isdigit(result[i])) {
            num = 0;
            while (i < n && isdigit(result[i])) {
                num = num * 10 + (result[i] - '0');
                i++;
            }
            i--;
            stack.push(num);
        }
        else {
            int val1 = stack.pop();
            int val2 = stack.pop();
            switch (result[i]) {
            case '+':
                stack.push(val2 + val1);
                break;
            case '-':
                stack.push(val2 - val1);
                break;
            case '*':
                stack.push(val2 * val1);
                break;
            case '/':
                stack.push(val2 / val1);
                break;
            }
        }
    }
    return stack.pop();
}

int main() {
    ifstream fileInput("input.txt");
    ofstream fileOutput("output.txt");
    string result;
    getline(fileInput, result);
    int ans = evaluate(result);
    fileOutput << ans << endl;
    fileInput.close();
    fileOutput.close();
    return 0;
}
