#include <pthread.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void *psps(void *d)
{
    int i = 0;
    while(1)
    {
        sleep(1);
        printf("%d\n", i);
        i++;
    }
    while(1);
}


int main()
{
    pthread_t       pth;
    // pth = malloc(sizeof(pthread_t));

    pthread_create(&pth, NULL, psps, NULL);
    printf("start\n");
    sleep(5);
    pthread_detach(pth);
    pthread_join(pth, NULL);
    // free(pth);
    sleep(2);
    system("ps -M");
    while(1);
}