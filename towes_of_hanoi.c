#include <stdio.h>
void hanoi(int n, char fr, char tr, char ar) // fr=from rod,tr =to rod, ar=aux rod
{
    if (n == 1)
    {
        printf("\n Move disk 1 from rod %c to rod %c", fr, tr);
        return;
    }
    hanoi(n - 1, fr, ar, tr);
    printf("\n Move disk %d from rod %c to rod %c", n, fr, tr);
    hanoi(n - 1, ar, tr, fr);
}

int main()
{
    int n;
    printf("Enter the number of discs:\t");
    scanf("%d", &n);
    hanoi(n, 'A', 'C', 'B'); // A, B and C are the name of rod
    return 0;
}