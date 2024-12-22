#include <stdio.h>
#include <regex.h>

int main() {
    const char* text = "GeeksForGeeks";
    const char* pattern = "Geek";

    regex_t regex;
    
    int ret;

    ret = regcomp(&regex, pattern, REG_EXTENDED);

    if (ret) {
        fprintf(stderr, "Could not compile regex\n");
        return 1;
    }

    ret = regexec(&regex, text, 0, NULL, 0);

    if (!ret) {
        printf("Text: %s\n", text);
        printf("Pattern: %s\n", pattern);
        printf("Pattern matched!\n");
    } else if (ret == REG_NOMATCH) {
        printf("Pattern did not match\n");
    } else {
        char msgbuf[100];
        regerror(ret, &regex, msgbuf, sizeof(msgbuf));
        fprintf(stderr, "Regex match failed: %s\n", msgbuf);
        return 1;
    }

    regfree(&regex);

    return 0;
}