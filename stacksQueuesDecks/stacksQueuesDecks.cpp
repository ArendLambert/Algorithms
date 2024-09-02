#include <iostream> 
#include <fstream> 

using namespace std;

struct Node {
	char Data;
	Node* next;
};

void push(Node** top, char data) {
	Node* newNode;
	newNode = new Node();
	newNode->Data = data;
	if (*top == NULL) {
		*top = newNode;
	}
	else
	{
		newNode->next = *top;
		*top = newNode;
	}
}

void deleteComp(Node** top, char N) {
	Node* cur = *top;
	Node* prev = NULL;
	while (cur != NULL) {
		if (cur->Data == N) {
			if (cur == *top) {
				*top = cur->next;
				free(cur);
				cur->Data = NULL;
				cur->next = NULL;
			}
			else
			{
				prev->next = cur->next;
				free(cur);
				cur->Data = NULL;
				cur->next = NULL;
			}
		}
		prev = cur;
		cur = cur->next;
	}
}

void deleteTop(Node** top) {
	Node* cur = *top;
	if (cur == *top) {
		*top = cur->next;
		free(cur);
	}
}

char get(Node** top) {
	Node* cur = *top;
	if (cur != NULL) {
		return cur->Data;
	}
}

void printList(Node* head) {
	Node* curr = head;
	cout << "STACK: ";
	while (curr) {
		cout << curr->Data << " ";
		curr = curr->next;
	}
	cout << endl;
}

int main()
{
	ifstream inputFile("input.txt");
	ofstream outputFile("output.txt");
	Node* stack = new Node();
	char word;
	string resault = "";
	string input;

	cin >> input;
	for (int i = 0; i < input.size(); i++)
	{
		word = input[i];
		if (word == '(') {
			push(&stack, word);
		}
		else if (word == ')') {
			push(&stack, word);
			while (stack != NULL && get(&stack) != '(')
			{
				if ((get(&stack) > 96 + 'NUL' && get(&stack) < 123 + 'NUL') || get(&stack) == '+' || get(&stack) == '/' || get(&stack) == '-' || get(&stack) == '*') resault += get(&stack);
				deleteTop(&stack);
			}
			deleteTop(&stack);
		}
		else if (word == '=') {

		}
		else if (word == '+' || word == '-') {
			while (get(&stack) == '+' || get(&stack) == '-' || get(&stack) == '*' || get(&stack) == '/') {
				resault += get(&stack);
				deleteTop(&stack);
			}
			push(&stack, word);
		}
		else if (word == '*' || word == '/') {
			while (get(&stack) == '*' || get(&stack) == '/') {
				resault += get(&stack);
				deleteTop(&stack);
			}
			push(&stack, word);
		}
		else
		{
			resault += word;
		}
		printList(stack);
	}
	while (stack->next != nullptr)
	{
		resault += stack->Data;
		stack = stack->next;
	}
	outputFile << resault;
	outputFile.close();
	inputFile.close();
	return 0;
}