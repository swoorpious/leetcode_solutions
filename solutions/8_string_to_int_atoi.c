#define INT_MAX 2147483647
#define INT_MIN -2147483648

static int clamp(long int val, int a, int b) {
    return (val >= a && val <= b) ? val : (val < a) ? a : b;
}

int myAtoi(char* s) {
    int hasCounted = 0;
    long int num = 0;
    int neg = 0;

    while (*s == ' ') ++s; // skip leading white space

    for (; *s && !(*s >= 'A' && *s <= 'z') && *s != '.' && *s != '\0'; s++) {
        if ((*s == '-' || *s == '+')) {
            if (hasCounted) break;
            if (*s == '-')
                neg = 1;
            
            hasCounted = 1;
        }
        else if (*s <= '9' && *s >= '0') {
            num = num * 10 + (*s - '0');
            if (num > 2147483648L) num = 2147483648L;
            hasCounted = 1;
        }
        else break;
    }

    if (neg) num *= -1;
    num = clamp(num, INT_MIN, INT_MAX);

    return (int)num;
}
