#include <stdio.h>
void hanoi(int n, char src, char dst, char temp) {
   if(n == 1){
      printf("Move disk 1 from %c to %c\n", src, dst);
   }
   else{
      hanoi(n-1, src, temp, dst);
      printf("Move disk %d from %c to %c\n", n, src, dst);
      hanoi(n-1, temp, dst, src);
   }
}
int main() {
   int n;
   printf("Enter the no of the disc:");
 scanf("%d",&n);
 printf("\n");
   char src = 'A';
   char dst = 'B';
   char temp = 'C';
   //calling hanoi() method
   hanoi(n, src ,temp, dst);
}
