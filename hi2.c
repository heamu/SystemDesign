#include<stdio.h>

#define PrintLIneNum printf("Line number is %d , File name is %s\n",__LINE__,__FILE__);

// #ifdef PrintLIneNum 
// #pragma message("dengey ra puka")
// #endif


void __attribute__((constructor)) beforeMain() {
    printf("before main");
}
void __attribute__((destructor)) afterMain() {
    printf("after main");
}
int main(){
    int a = 20;
    PrintLIneNum
    #line 30 "bokka.h"
    PrintLIneNum
    PrintLIneNum
    printf("In main");
    return 0;
}