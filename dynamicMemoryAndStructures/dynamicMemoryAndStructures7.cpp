#define _CRT_SECURE_NO_WARNINGS
// для работы с памятью 

#include <iostream>
#include <sstream>

using namespace std;

typedef struct Tokens_s {
    int num; // количество слов в строке
    char** arr; // массив слов (каждый элемент – строка, т.е. char*)
} Tokens;
//tokens: структура, в которую нужно положить результаты
//str: строка, в которой нужно искать слова
//delims: все символы-разделители в виде строки

void tokensSplit(Tokens* tokens, const char* str, const char* delims) {
    if (tokens->arr == NULL) {
        char* temp = _strdup(str);
        char* token = strtok(temp, delims);
        while (token != NULL) {
            tokens->num++;
            token = strtok(NULL, delims);
        }
        free(temp);
    }
    else {
        tokens->arr = (char**)malloc(tokens->num * sizeof(char*));
        char* temp = _strdup(str);
        char* token = strtok(temp, delims);
        int i = 0;
        while (token != NULL) {
            tokens->arr[i] = _strdup(token);
            token = strtok(NULL, delims);
            i++;
        }
        free(temp);
    }

}

//удаляет все ресурсы внутри tokens
void tokensFree(Tokens* tokens) {
    for (int i = 0; i < tokens->num; ++i) {
        delete[] tokens->arr[i];
    }
    delete[] tokens->arr;
}

int main() {
    string str;
    getline(cin, str);
    const char* delims = ".,;:";
    Tokens tokens;
    tokens.num = 0;
    tokens.arr = NULL;

    tokensSplit(&tokens, str.c_str(), delims);
    tokens.arr = new char* [tokens.num];
    tokensSplit(&tokens, str.c_str(), delims);

    cout << tokens.num << endl;
    for (int i = 0; i < tokens.num; i++) {
        cout << tokens.arr[i] << std::endl;
    }
    tokensFree(&tokens);
    return 0;
}
