#include <iostream>

using namespace std;

typedef struct Label_s {
    char name[16]; //��� ������ (������������� ����)
    int age; //������� ������ (������� ���)
} Label;

typedef struct NameStats_s {
    int cntTotal; //������� ����� ��������
    int cntLong; //������� �������� � ������� ������� 10 ����
} NameStats;

typedef struct AgeStats_s {
    int cntTotal; //������� ����� ��������
    int cntAdults; //������� �������� �������� (���� �� 18 ���)
    int cntKids; //������� �������� ����� (������ 14 ���)
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
