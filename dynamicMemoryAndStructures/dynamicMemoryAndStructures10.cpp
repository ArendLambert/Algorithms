#include <stdio.h>

union Union {
    double real;
    unsigned long long int integer;
};

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; ++i) {
        int P, Q;
        unsigned long long int M;
        scanf("%d/%d xor %llx", &P, &Q, &M);

        double X = (double)P / Q;

        union Union data;

        data.real = X;
        data.integer ^= M;
        printf("%0.15g\n", data.real);
    }

    return 0;
}
