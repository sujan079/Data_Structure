#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct stack
{
    int top;
    char string[50];

};
int main()

{
    int n;
    struct stack s;
    s.top=-1;
    char ch;
        printf("Enter the expression you want to get postfix exp of  ");
        scanf("%s",s.string);
n=strlen(s.string);
for (int i=0;i<n;i++){
ch =s.string[i];
printf("%c",s.string[i]);

}
return 0;
}
//2395=2456

