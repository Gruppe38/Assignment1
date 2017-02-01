#include<stdio.h>
#include<pthread.h>

int i = 0;
pthread_mutex_t lock;

void* thread1(){
    int j = 0;
    for(j;j<1000000;j++){
        pthread_mutex_lock(&lock);
        i++;
        pthread_mutex_unlock(&lock);
    }
}

void* thread2(){
    int j = 0;
    for(j;j<1000001;j++){
        pthread_mutex_lock(&lock);
        i--;
        pthread_mutex_unlock(&lock);
    }
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
