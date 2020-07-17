#include <stdio.h>

int Foo(int i){
    if(i<=0){
        return 0;
    }else if(i<=2){
        return 1;
    }else
    {
        return Foo(i-1)+Foo(i-2);
    } 
}

int main(void){
    int result=Foo(30);
    printf("兔子数列第30位：%d",result);
    return 0;
}