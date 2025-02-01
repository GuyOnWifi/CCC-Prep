#include <stdio.h>

using namespace std;

int fast_pow(long long base, long long n, long long M)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return base;
    long long halfn = fast_pow(base, n / 2, M);
    if (n % 2 == 0)
        return (halfn * halfn) % M;
    else
        return (((halfn * halfn) % M) * base) % M;
}
int findMMI_fermat(int n, int M)
{
    return fast_pow(n, M - 2, M);
}

int main()
{
    long long fact[1000001];
    fact[0] = 1;
    int i = 1;
    int MOD = 1000000007;
    while (i <= 1000000)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
        i++;
    }

    int N;
    scanf("%d", &N);
    while (N--)
    {
        int start, stop;
        unsigned long long int prod = 1;
        scanf("%d%d", &start, &stop);
        prod = (fact[stop] * findMMI_fermat(fact[start-1], MOD)) % MOD;
        printf("%llu\n", prod);
    }
}