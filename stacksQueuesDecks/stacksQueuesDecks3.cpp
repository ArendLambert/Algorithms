#include <iostream>
#include <fstream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

class CircularBuffer {
public:
    CircularBuffer(int size) : size_(size), head_(nullptr), tail_(nullptr), count_(0) {}

    ~CircularBuffer() {
        Node* temp;
        while (count_ > 0) {
            temp = head_;
            head_ = head_->next;
            delete temp;
            count_--;
        }
        head_ = nullptr;
        tail_ = nullptr;
    }

    bool addData(int data, ofstream& outputFile, bool go) {
        Node* newNode = new Node(data);
        if (head_ == nullptr) {
            head_ = newNode;
            tail_ = newNode;
            newNode->next = head_;
            count_++;
        }
        else {
            if (count_ < size_) {
                tail_->next = newNode;
                tail_ = newNode;
                tail_->next = head_;
                count_++;
            }
            else {
                if (go) outputFile << "Memory overflow" << endl;
                return false; //сломалось
            }
        }
        return true; //норма
    }



    int removeData(ofstream& outputFile) {
        if (count_ > 0) {
            Node* temp = head_;
            int data = head_->data;
            if (head_ == tail_) {
                head_ = nullptr;
                tail_ = nullptr;
            }
            else {
                head_ = head_->next;
                tail_->next = head_;
            }
            delete temp;
            count_--;
            return data;
        }
        else {
            outputFile << "Empty queue" << endl;
            return 0;
        }
    }

    bool isEmpty() const {
        return count_ == 0;
    }

    int getCount() const {
        return count_;
    }

private:
    Node* head_;
    Node* tail_;
    int size_;
    int count_;
};

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    int N, M, command, data, K, sum, count, count2, average = 0;
    bool go = true;
    inputFile >> N >> M;

    CircularBuffer buffer(N);

    for (int i = 0; i < M; i++) {
        go = true;
        inputFile >> command;
        if (command > 0) {
            for (int j = 0; j < command; j++) {
                if (inputFile.eof()) break;
                inputFile >> data;
                i++;
                go = buffer.addData(data, outputFile, go);
            }
        }
        else {
            K = -command;
            sum = 0;
            count = 0;
            count2 = K;
            for (int j = 0; j < K; j++) {
                if (buffer.isEmpty()) {
                    break;
                }
                sum += buffer.removeData(outputFile);
                count++;
                count2--;
            }

            if (count > 0) {
                average = sum / count;
                outputFile << average << endl;
            }
            if (buffer.getCount() == 0 && count2 > 0) {
                outputFile << "Empty queue" << endl;
            }
        }
    }

    inputFile.close();
    outputFile.close();
    return 0;
}
