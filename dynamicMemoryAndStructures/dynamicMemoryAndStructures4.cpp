#include <iostream>

using namespace std;

typedef struct Label_s {
    char name[16]; //имя автора (заканчивается нулём)
    int age; //возраст автора (сколько лет)
} Label;

typedef struct NameStats_s {
    int cntTotal; //сколько всего подписей
    int cntLong; //сколько подписей с именами длиннее 10 букв
} NameStats;

typedef struct AgeStats_s {
    int cntTotal; //сколько всего подписей
    int cntAdults; //сколько подписей взрослых (хотя бы 18 лет)
    int cntKids; //сколько подписей детей (меньше 14 лет)
} AgeStats;

void calcStats(const Label* arr, int cnt, NameStats* oNames, AgeStats* oAges) {
    for (int i = 0; i < cnt; i++) {
        if (strlen(arr[i].name) > 10) {
            oNames->cntLong++;
        }
        if (arr[i].age >= 18) {
            oAges->cntAdults++;
        }
        else if (arr[i].age < 14) {
            oAges->cntKids++;
        }
    }
}

int main() {
    int cnt;
    cin >> cnt;
    NameStats oNames;
    oNames.cntLong = 0;
    oNames.cntTotal = cnt;
    AgeStats oAges;
    oAges.cntAdults = 0;
    oAges.cntKids = 0;
    oAges.cntTotal = cnt;
    Label* labels = new Label[cnt];
    for (int i = 0; i < cnt; i++) {
        cin >> labels[i].name >> labels[i].age;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    calcStats(labels, cnt, &oNames, &oAges);
    cout << "names: total = " << oNames.cntTotal << "\n" <<
        "names: long = " << oNames.cntLong << "\n" <<
        "ages: total = " << oAges.cntTotal << "\n" <<
        "ages: adult = " << oAges.cntAdults << "\n" <<
        "ages: kid = " << oAges.cntKids;
    delete[] labels;
    return 0;
}
