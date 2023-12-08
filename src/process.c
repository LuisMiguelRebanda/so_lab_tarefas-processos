#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int g_value = 0;

void* g_func(void *p) {
    g_value = 1;
    return NULL;
}

int main() {
    pid_t pid;
    pid = fork();
    if (pid == 0) {
        g_func(NULL);
        printf("Child value = %d\n", g_value);
    } else {
        g_value = 2;
        printf("Parent value = %d\n", g_value);
    }
    return 0;
}