#include <stdlib.h>

char* intToStr(int n) {
    char* str = (char*)malloc(5 * sizeof(char));
    char* c = str + 4;
    *c-- = 0;
    while (n > 0) {
        *c-- = n%10 + '0';
        n /= 10;
    }
    return ++c;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** fizzBuzz(int n, int* returnSize) {
    *returnSize = n;
    char* fb = "FizzBuzz";
    char*  f = "Fizz";
    char*  b = "Buzz";
    char** ans = (char**)malloc(n * sizeof (char*));

    int i = 1;
    while (i <= n) {
        if (i % 3 == 0 && i % 5 == 0)
            ans[i-1] = fb;
        else if (i % 3 == 0)
            ans[i-1] = f;
        else if (i % 5 == 0)
            ans[i-1] = b;
        else
            ans[i-1] = intToStr(i);
        i++;
    }
    return ans;
}
