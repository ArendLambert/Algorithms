#include <iostream> 
#include <fstream>  
using namespace std;

int calcLetters(char* iStr, int* oLowerCnt, int* oUpperCnt, int* oDigitsCnt) {
    *oLowerCnt = 0, * oUpperCnt = 0, * oDigitsCnt = 0;
    int stringLength = strlen(iStr);
    for (int i = 0; i < stringLength; i++) {
        if ((iStr[i] + 0) < 91 && (iStr[i] + 0) > 64) {
            *oUpperCnt += 1;
        }
        else if ((iStr[i] + 0) < 123 && (iStr[i] + 0) > 96) {
            *oLowerCnt += 1;
        }
        else if ((iStr[i] + 0) < 58 && (iStr[i] + 0) > 47) {
            *oDigitsCnt += 1;
        }
    }
    return stringLength;
}

int main()
{
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");
    char iStr[101];
    int oLowerCnt = 0, oUpperCnt = 0, oDigitsCnt = 0;
    int lineCount = 1;
    while (inputFile.getline(iStr, 101)) {
        int calc = calcLetters(iStr, &oLowerCnt, &oUpperCnt, &oDigitsCnt);
        outputFile << "Line " << lineCount << " has " << calc << " chars: " << oLowerCnt + oUpperCnt <<
            " are letters (" << oLowerCnt << " lower, " << oUpperCnt << " upper), " << oDigitsCnt << " are digits." << endl;
        lineCount++;
    }
    inputFile.close();
    outputFile.close();
    return 0;
}