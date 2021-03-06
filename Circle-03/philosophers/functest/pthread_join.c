#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// 쓰레드 함수
void *test(void *data)
{
    int i;
    int *status;
    int a = *(int *)data;

    status = malloc(sizeof(int) * 3);
    status[0] = 10;
    status[1] = 20;
    status[2] = 30;
    for (i = 0; i < 10; i++)
    {
        printf("%d\n", i*a);
        if (i == 3)
            exit(1);
    }
    return (void *)status;
}

int main()
{
    int a = 100;
    pthread_t thread_t;
    int *status;

    // 쓰레드를 생성한다.
    if (pthread_create(&thread_t, NULL, test, (void *)&a) < 0)
    {
        perror("thread create error:");
        exit(0);
    }

    // 쓰레드가 종료되기를 기다린후
    // 쓰레드의 리턴값을 출력한다.
    pthread_join(thread_t, &status);
    printf("Thread End %d\n", status[0]);
    printf("Thread End %d\n", status[1]);
    printf("Thread End %d\n", status[2]);
    return 1;
}
