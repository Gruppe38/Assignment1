#include<stdio.h>
#include<pthread.h>

int i = 0;

void* thread1(){
    int j = 0;
    for(j;j<1000000;j++)
        i++;
}

void* thread2(){
    int j = 0;
    for(j;j<1000000;j++)
        i--;
}


int main(){
    pthread_t thr1;
    pthread_t thr2;
    pthread_create(&thr1, NULL, thread1, NULL);
    pthread_create(&thr2, NULL, thread2, NULL);
    
    pthread_join(thr1, NULL);
    pthread_join(thr1, NULL);

    printf("%d", i);
    printf("\n");
    return 0;
}
