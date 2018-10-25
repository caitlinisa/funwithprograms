#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int a, b, n, x, cnt=0, i=0, j=0, k=0;
    
    scanf("%d %d %d", &a, &b, &n);
    
    for(x=a; x<=b; x++){
        if(x%5==0 || x%3==0 || x%2==0){
            
            while(x%2==0){
                x=x/2;
                i++;
                printf("%d\n", x);
            }
            while(x%3==0){
                x=x/3;
                j++;
                printf("%d\n", x);
            }
            while(x%5==0){
                x=x/5;
                k++;
                printf("%d\n", x);
            }
            
            if(x==0 && n==i+j+k){
                cnt++;
                printf("%d\n", cnt);
            }
            
        }else{
            break;
        }
    }
    
    printf("%d\n", cnt);
    
    return 0;
}


