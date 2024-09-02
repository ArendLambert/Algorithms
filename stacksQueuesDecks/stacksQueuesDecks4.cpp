#include <iostream>
#include <cstdlib>

using namespace std;

class CircularBuffer {
public:
    CircularBuffer(int size) : buffer(new int[size]), capacity(size), front(0), back(-1), count(0) {}

    ~CircularBuffer() {
        delete[] buffer;
    }

    bool isEmpty() const {
        return count == 0;
    }

    bool isFull() const {
        return count == capacity;
    }

    void pushFront(int value) {
        if (isFull()) {
            // Если буфер полон, перезаписываем самый старый элемент с передней стороны
            front = (front + 1) % capacity;
            if (front == 0) {
                back = capacity - 1;
            }
            else {
                back = front - 1;
            }
        }
        else {
            front = (front - 1 + capacity) % capacity;
            if (isEmpty()) {
                back = front;
            }
            count++;
        }
        buffer[front] = value;
    }

    void pushBack(int value) {
        if (isFull()) {
            // Если буфер полон, перезаписываем самый старый элемент с задней стороны
            back = (back - 1 + capacity) % capacity;
            front = (back + 1) % capacity;
        }
        else {
            back = (back + 1) % capacity;
            if (isEmpty()) {
                front = back;
            }
            count++;
        }
        buffer[back] = value;
    }

    int popFront() {
        int value = buffer[front];
        front = (front + 1) % capacity;
        count--;
        return value;
    }

    int popBack() {
        int value = buffer[back];
        back = (back - 1 + capacity) % capacity;
        count--;
        return value;
    }

    void printBuffer() const {
        int index = front;
        cout << count << " ";
        for (int i = 0; i < count; ++i) {
            cout << buffer[index] << ' ';
            index = (index + 1) % capacity;
        }
        cout << endl;
    }

private:
    int* buffer;
    int capacity;
    int front;
    int back;
    int count;
};

int main() {
    int N, M, op, card;
    char operation;
    bool takeFromRight, takeFromBottom, putInRight, putInBottom;
    cin >> N >> M;

    CircularBuffer leftDeck(2 * N + 1), rightDeck(2 * N + 1);

    for (int i = 1; i <= N; ++i) {
        leftDeck.pushBack(i);
        rightDeck.pushBack(-i);
    }

    for (int i = 0; i < M; ++i) {
        cin >> operation;
        op = operation >= 'A' ? operation - 'A' + 10 : operation - '0';

        takeFromRight = op & 8;
        takeFromBottom = op & 4;
        putInRight = op & 2;
        putInBottom = op & 1;

        CircularBuffer& takeFrom = takeFromRight ? rightDeck : leftDeck;
        CircularBuffer& putIn = putInRight ? rightDeck : leftDeck;

        if (!takeFrom.isEmpty()) {
            card = takeFromBottom ? takeFrom.popBack() : takeFrom.popFront();
            if (putInBottom) {
                putIn.pushBack(card);
            }
            else {
                putIn.pushFront(card);
            }
        }
    }
    leftDeck.printBuffer();
    rightDeck.printBuffer();

    return 0;
}