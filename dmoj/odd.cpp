#include <stdio.h>

using namespace std;
int a = 0;

int main() {
    int N;
    scanf("%d", &N);
    while(N--) {
        int num;
        scanf("%d", &num);
        a ^= num;
    }
    printf("%d\n", a);
}