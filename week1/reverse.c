#include <stdio.h>

size_t my_strlen(const char *s) {
    size_t len = 0;
    while (*s){
        s++;
        len++;
    }
    return len;
}

void reverse(char *s) {
    size_t len = my_strlen(s);
    if (len < 2) {
        return;
    }
    char *left = s;
    char *right = s + len - 1;
    while(left < right) {
        char temp = *right;
        *right = *left;
        *left = temp;
        left++;
        right--;
    }
}

int main(void){
    char a[] = "hello";
    char b[] = "abcd";
    char c[] = "a";
    char d[] = "";
    reverse(a); reverse(b); reverse(c); reverse(d);
    printf("[%s] [%s] [%s] [%s]\n", a, b, c, d);

    reverse("hello");
    return 0;
}