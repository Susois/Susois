#include <stdio.h>
#include <stdlib.h>

#define MAX_N 10001

// Fenwick Tree (BIT) declaration
long long BIT[MAX_N][MAX_N];
long long n, k;

// 2D BIT Update Function
void update(long long x, long long y, long long value) {
    for (long long i = x; i <= n; i += i & -i) {
        for (long long j = y; j <= n; j += j & -j) {
            BIT[i][j] += value;
        }
    }
}

// 2D BIT Query Function
long long query(long long x, long long y) {
    long long sum = 0;
    for (long long i = x; i > 0; i -= i & -i) {
        for (long long j = y; j > 0; j -= j & -j) {
            sum += BIT[i][j];
        }
    }
    return sum;
}

// Function to get the sum in a subrectangle
long long range_query(long long x1, long long y1, long long x2, long long y2) {
    return query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) + query(x1 - 1, y1 - 1);
}
int main() {
    // #define long long long long
    scanf("%lld %lld", &n, &k);

    char op;
    long long x, y, x1, y1, x2, y2, m;

    for (long long i = 0; i < k; i++) {
        scanf(" %c", &op);

        if (op == 'A') {
            // Add mana to a specific tower
            scanf("%lld %lld %lld", &x, &y, &m);
            update(x, y, m);

        } else if (op == 'C') {
            // Calculate total mana in a rectangle
            scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
            if(x1>x2){
                long long tmp = x1;x1=x2;x2=tmp;
            }           
            if(y1>y2){
                long long tmp = y1;y1=y2;y2=tmp;
            }
            printf("%lld\n", range_query(x1, y1, x2, y2));
        }
    }

    return 0;
}
