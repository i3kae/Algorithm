#include <stdio.h>

int main() {
    double totalMin = -1;
    double K, P, X, i = 1;
    scanf("%lf%lf%lf", &K,&P,&X);
    while (1) {
        double next = (K / i) * P + i * X;
        if (totalMin == -1 || next < totalMin)
            totalMin = next;
        else
            break;
        i++;
    }
    printf("%.3lf", totalMin);
}