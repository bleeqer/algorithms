#include <stdio.h>

int main() {
    int n;
    int t1 = 0, t2 = 1;
    int nextTerm = t1 + t2;

    printf("Enter the number of terms: ");
    scanf("%d", &n);
    
    printf("Fibonacci Series: %d, %d, ", t1, t2);

    for (int i = 3; i <= n; i++) {
        printf("%d, ", nextTerm); // print the sum of last two
        t1 = t2; // set t1 with t2(which is the next number)
        t2 = nextTerm; // set t2 is the sum 
        nextTerm = t1 + t2; // next term is the sum of t1 and t2
    }

    return 0;
}