#include <stdio.h>
#include <string.h>

#define D 256

void search(char pat[], char txt[], int q) {
    int M = strlen(pat);
    int N = strlen(txt);
    int i, j;
    int p = 0;
    int t = 0;
    int h = 1;

    for (i = 0; i < M - 1; i++) {
        h = (h * D) % q;
    }

    for (i = 0; i < M; i++) {
        p = (D * p + pat[i]) % q;
        t = (D * t + txt[i]) % q;
    }

    for (i = 0; i <= N - M; i++) {

        // if the hash values are matched
        if (p == t) {

            // check if the pattern is matched
            for (j = 0; j < M; j++) {
                if (txt[i + j] != pat[j]) {
                    break;
                }
            }

            // if the pattern is matched
            if (j == M) { 
                printf("Pattern found at index %d\n", i);
            }
        }

        // if the pattern is not at the end
        if (i < N - M) {

            // calculate the hash value for the next window
            t = (D * (t - txt[i] * h) + txt[i + M]) % q;

            // if the hash value is negative, add q to it
            if (t < 0) {
                t = (t + q);
            }
        }
    }
    


}

int main() {
    char txt[] = "GEEKS FOR GEEKS";
    char pat[] = "GEEK";

    int q = 101;

    search(pat, txt, q);

    return 0;
}