#define min(i,j) (i<j?i:j)

int maxArea(int* height, int heightSize) {
    int cap = 0; 
    int l = 0, r = heightSize - 1;
    while (l<r) {
        int cur = min(height[l], height[r]) * (r - l);
        if (cur > cap) cap = cur;

        if (height[l] < height[r]) ++l;
        else --r;
    }
    return cap;
}
