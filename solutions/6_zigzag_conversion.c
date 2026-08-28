#include <stdlib.h>

// chars in between is numRows - 2
// next char = 2 * (numRows - 1)
char* convert(char* s, int numRows) {
    if (numRows == 1) return s;

    int len = 0;
    while (s[len] != '\0') len++;

    char* res = (char *)malloc(len + 1);
    int t = 0;

    for (int i = 0; i < numRows; ++i) {
        for (int j = i; j < len; j += 2*(numRows - 1)) {
            res[t++] = s[j];

            if (i > 0 && i < numRows - 1 && j + 2*(numRows-1) - 2*i < len)
                res[t++] = s[j + 2*(numRows-1) - 2*i];
        }
    }
    res[t] = '\0';

    return res;
}