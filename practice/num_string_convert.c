#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    int num[3] = {1,22,333};

    char* retChr = NULL;

    for(int i=0; i<3; i++){
        char tmp[16];
        sprintf(tmp, "%d,", num[i]);
        printf ("tmp len:%lu, sizeof(char):%d\n", strlen(tmp), sizeof(char));
        retChr = realloc(retChr, strlen(tmp) * sizeof(char));
        strcat(retChr, tmp);
        printf("%d=[%s]\n", i, retChr);
    }
    printf("%c\n", retChr[strlen(retChr)-1]);    

    return 1;
}
