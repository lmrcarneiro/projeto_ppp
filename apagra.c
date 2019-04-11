#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

int organizar(int a[]);

int main(){
int a[MAX], i;
for(i=0; i<MAX; i++){
    a[i]= (rand()%100);
    }
organizar(a);
return 0;
}

int organizar(int a[]){
int i;
int j;
int m;
    for (i=0; i<MAX; i++) {
        for (j=MAX-1;j>i;j--) {
            if (a[j-1]> a[j]) {
                m=a[j-1];
                a[j-1]=a[j];
                a[j]=m;
                }
            }
        }

for(i=0; i<MAX; i++){
    printf("%d\n", a[i]);
    }
return 0;
}
