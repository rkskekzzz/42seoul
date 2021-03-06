#include <pthread.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// 쓰레드 함수
void *test(void *data)
{
    int i;
    int a = *(int *)data;
    printf("data -> : %d\n", a);
    for (i = 0; i < 100000; i++)
    {
        printf("%d\n", i*a);
        if (i == 10)
            exit(1);
    }
    return (void *)(i * 100);
}

int main()
{
    int a = 42;
    pthread_t thread_t;
    int status = 42;

    // 쓰레드를 생성한다.
    if (pthread_create(&thread_t, NULL, test, (void ****)&a) < 0)
    {
        perror("thread create error:");
        exit(0);
    }

    // 쓰레드가 종료되기를 기다린후
    // 쓰레드의 리턴값을 출력한다.
    // pthread_join(thread_t, (void **)&status);
    usleep(1);
    printf("Thread End %d\n", status);
    return 1;
}

