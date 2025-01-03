#include<stdio.h>
int  gcd (int a , int b )
{
int r;
if (b==0) 
{
    return a;
}
else
{
    while(b!=0){
        r=a%b;
        a=b;
        b=r;

    }
    return a;
}

}
int main (){
    int a ,b;
    printf("Enter\n ");
    scanf("%d%d",&a,&b);
    printf("%d",gcd(a,b));
return 0;
}
