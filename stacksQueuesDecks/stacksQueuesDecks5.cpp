#define _CRT_SECURE_NO_WARNINGS
// для использования strtok()

#include <iostream>
#include <string>
#include<iomanip>
#include <cmath>

using namespace std;

struct Node {
    double value;
    Node* prev;
    Node* next;
};

struct List {
    Node* head;
    Node* tail;

    List() : head(nullptr), tail(nullptr) {}

    bool empty() const {
        return head == nullptr;
    }

    void push_back(double val) {
        Node* new_node = new Node{ val, tail, nullptr };
        if (empty()) {
            head = tail = new_node;
        }
        else {
            tail->next = new_node;
            tail = new_node;
        }
    }

    double pop_back() {
        double val = tail->value;
        Node* to_delete = tail;
        tail = tail->prev;
        if (tail) {
            tail->next = nullptr;
        }
        else {
            head = nullptr;
        }
        delete to_delete;
        return val;
    }

    double& back() {
        return tail->value;
    }
};

bool operation(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int prioritet(char op) {
    if (op < 0) return 3;
    else {
        if (op == '+' || op == '-')
            return 1;
        else if (op == '*' || op == '/')
            return 2;
        else if (op == '^')
            return 4;
        else return -1;
    }
}

void action(List& value, char op) {
    if (op < 0) {
        double unitar = value.back();
        value.pop_back();
        if (-op == '-') value.push_back(-unitar);
    }
    else {
        double right = value.back();
        value.pop_back();
        double left = value.back();
        value.pop_back();
        switch (op) {
        case '+': value.push_back(left + right); break;
        case '-': value.push_back(left - right); break;
        case '*': value.push_back(left * right); break;
        case '/': value.push_back(left / right); break;
        case '^': value.push_back(pow(left, right)); break;
        }
    }
}

double calculus(string& formula) {
    bool unary = true;
    List value;
    List op;
    for (int i = 0; i < formula.size(); ++i) {
        if (formula[i] == '(') {
            op.push_back('(');
            unary = true;
        }
        else if (formula[i] == ')') {
            while (op.back() != '(') {
                action(value, op.back());
                op.pop_back();
            }
            op.pop_back();
            unary = false;
        }
        else if (operation(formula[i])) {
            char zn = formula[i];
            if (unary) zn = -zn;
            while (!op.empty() && prioritet(op.back()) >= prioritet(zn)) {
                action(value, op.back());
                op.pop_back();
            }
            op.push_back(zn);
            unary = true;
        }
        else {
            string number;
            while (i < formula.size() && isdigit(formula[i])) number += formula[i++];
            --i;
            value.push_back(atol(number.c_str()));
            unary = false;
        }
    }
    while (!op.empty()) {
        action(value, op.back());
        op.pop_back();
    }
    return value.back();
}

int main() {
    string formula = "";
    char* line = new char[501];
    char* temp = new char[501];
    string tempStr;
    getline(cin, tempStr);
    line = (char*)tempStr.c_str();
    temp = strtok(line, " ");
    formula += temp;
    while (temp != NULL)
    {
        temp = strtok(NULL, " ");
        if (temp != NULL)
            formula += temp;
    }
    cout << fixed << setprecision(20);
    cout << setw(20) << calculus(formula) << endl;
    return 0;
}
