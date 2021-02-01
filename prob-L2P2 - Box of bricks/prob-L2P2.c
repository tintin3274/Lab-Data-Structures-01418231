#include <stdio.h>

int main(){
    int i, n, high=0, count=0;
    scanf("%d", &n);    
    int stack[n];
    for(i=0; i<n; i++){
        scanf("%d", &stack[i]);
        high += stack[i];
    }
    high /= n;
    for(i=0; i<n; i++){
        if(stack[i]>high){
            count += stack[i]-high;
        }
    }
    printf("%d", count);
}