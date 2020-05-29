/* 4.2范例，使用不同类别的字符创    */
#include <stdio.h>
#define PRAISE "what a super marvelous 名称！"

int main(){
    char name[40];

    printf("what's your name?\n");
    scanf("%s",name);
    printf("hello, %s, %s\n", name, PRAISE);
    return 0;
}
