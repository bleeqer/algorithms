#include <stdio.h>
#include <string.h>

// find longest prefix and suffix and then fill lps with the lengths
void computeLPSArray(char* pat, int M, int* lps) {
    int len = 0;
    lps[0] = 0; // lps[0] is always 0

    // "ABABCABAB";

    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            printf("pat[%d] %c == pat[%d] %c ", i, pat[i], len, pat[len]);
            len++;
            lps[i] = len;
            printf("lps[%d] = %d, len++, i++\n", i, len);
            i++;
        } else {
            printf("pat[%d] %c != pat[%d] %c\n", i, pat[i], len, pat[len]);
            if (len != 0) {
                printf("len is not 0, setting len with lps[%d](%d)\n", len - 1, lps[len - 1]);
                len = lps[len - 1];
            } else {
                printf("len is 0, setting lps[%d] with 0, i++\n", i);
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(char* pat, char* txt) {
    int M = strlen(pat);
    int N = strlen(txt);

    // longest prefix suffix
    int lps[M];

    // preprocess lps to fill it with occurences
    computeLPSArray(pat, M, lps);

    int i = 0;
    int j = 0;

    while (i < N) {

        // move forward if the characters matched
        if (pat[j] == txt[i]) {
            i++;
            j++;
        }

        // if j is at the end we know we've found the pattern
        if (j == M) {
            printf("Found pattern at index %d", i - j);
            j = lps[j - 1];

        // we are satisfy this condition at index 4
        } else if (pat[j] != txt[i]) { // if not matched
            if (j != 0) { // if pattern is not at start
                j = lps[j - 1]; // set pattern index with lps[j - 1] which is 2
            } else { // if pattern index is at start
                i = i + 1; // move forward with txt
            }
        }
    }
}

int main() {
    char txt[] = "ABABDABACDABABCABAB";
    char pat[] = "ABABCABAB";
    KMPSearch(pat, txt);

    return 0;
}