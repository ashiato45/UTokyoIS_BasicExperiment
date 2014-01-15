#include <stdio.h>

int det(int** a)
{
    int val = 0;
    int i,j;
    int tmp;

    for (i = 0; i < 3; i++) {
        tmp = a[0][i];
        for (j = 1; j < 3; j++) {
            tmp *= a[j][(i + j) % 3];
        }
        val += tmp;
        tmp = a[0][i];
        for (j = 1; j < 3; j++) {
            tmp *= a[j][(3 + i - j) % 3];
        }
        val -= tmp;
    }

    return val;
}

int main()
{
    int a[3][3] = {};
    int i,j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d",&a[i][j]);
        }
    }

    printf("%d\n", det(&*a));

    return 0;

}
