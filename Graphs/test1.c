#include<stdio.h>
void sum1(int x){
    int y=3;
    printf("%p\n",&y);
    //printf("%d\n",x);
}
void sum2(int x){
    static int y=3;
    printf("%p\n",y);
    //printf("%d\n",x);
}
int main(){
    //sum1(5);
    sum2(8);
    sum1(5);
    //sum2(7);
}
