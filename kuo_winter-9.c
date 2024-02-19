#include<stdio.h>
#include<math.h>


//ab+a+b == 10^intlen(b)*a + b
// b+1 == 10^intlen(b)
int main()
{
    int T;
    long long int A, B;
    for(scanf("%d", &T);T--;)
    {
        scanf("%lld %lld", &A, &B);
        printf("%lld\n", (long long int)log10(B+1)*A);
    }
}

