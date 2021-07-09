#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>


#define INPUT_KEYBOARD "/dev/input/event3"

#include "input_keys.c"

int main(int argc, char *argv[])
{
    pid_t pid = fork();
    if (pid > 0) {
        exit(1); // 1.父进程退出
    } else if (pid == 0) {
        // 2.变为会长，脱离了控制终端
        setsid();
        // 3.改变进程的工作目录
        chdir("/~");
        // 4. 重置文件掩码
        umask(0);
        // 5. 关闭文件描述符
        close(STDIN_FILENO);
        close(STDOUT_FILENO);
        close(STDERR_FILENO);
        // 6. 执行核心操作
        int fd = open("./temp-deamon-log.txt", O_CREAT | O_WRONLY | O_APPEND, 0664);
        struct input_event ev = input_key(); // 读取键盘输入事件函数，未完成
        int i;
        for (i = 0; i < 50; i++) {
            sleep(3);
            time_t curtime;
            time(&curtime);
            char* pt = ctime(&curtime);
            write(fd, pt, strlen(pt) + 1);
            printf("%u\n", ev.code);
        }
        close(fd);
    }

    return EXIT_SUCCESS;
}
