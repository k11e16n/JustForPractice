#include <stdio.h>
#include <vector>

struct my_stru{
    int a;
    char b;
    long ab;
};

int main(){
    struct my_stru test_my_stru = {0};
    struct my_stru *s_test_my_stru = NULL;
    printf("size:%ld\n", sizeof test_my_stru);
    printf("size:%ld\n", sizeof s_test_my_stru);

    return 0;
}
