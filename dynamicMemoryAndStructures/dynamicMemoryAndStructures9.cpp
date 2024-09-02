#include <iostream>
#include <cstring>

using namespace std;

void create_str(const char* str, int length, char** strings, int idx)
{
    strings[idx] = new char[length + 1];
    strcpy(strings[idx], str);
    strings[idx][length] = '\0';
}

void delete_str(int idx, char** strings)
{
    delete[] strings[idx];
    strings[idx] = nullptr;
}

char* print_str(int idx, char** strings)
{
    return strings[idx];
}

int search_str(int idx, char sym, char** strings)
{
    int num = 0;
    int length = strlen(strings[idx]);
    for (int i = 0; i < length; i++)
    {
        if (strings[idx][i] == sym)
        {
            num++;
        }
    }
    return num;
}

void free_all(char** strings, int length)
{
    for (int i = 0; i < length; i++)
    {
        if (strings[i] != nullptr) {
            delete[] strings[i];
            strings[i] = nullptr;
        }
    }
    delete[] strings;
}

int main()
{
    int N;
    cin >> N;
    char** strings = new char* [N] {};

    int id = 0;

    for (int i = 0; i < N; i++)
    {
        int t;
        cin >> t;

        if (t == 0)
        {
            int length;
            cin >> length;
            char* str = new char[length + 1];
            cin >> str;
            create_str(str, length, strings, id);
            id++;
            delete[] str;
        }
        else if (t == 1)
        {
            int idx;
            cin >> idx;
            delete_str(idx, strings);
        }
        else if (t == 2)
        {
            int idx;
            cin >> idx;
            cout << print_str(idx, strings) << endl;
        }
        else if (t == 3)
        {
            int idx;
            cin >> idx;
            char sym;
            cin >> sym;
            cout << search_str(idx, sym, strings) << endl;
        }
    }

    free_all(strings, N);

    return 0;
}
