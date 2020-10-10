/* 2020-10-09 22:04:50 c语言守护进程 */
/* 2、创建守护进程的步骤
   (1)fork子进程，父进程退出（必须）
   (2)子进程创建新会话（必须，setsid()）
   (3)改变当前工作目录chdir（非必须，建议做）
     防止：插入了一个U盘，a.out，在U盘目录中启动，运行过程中，U盘拔掉了。
   (4)重设子进程掩码（非必须）
     增加子进程程序操作的灵活性（umask(0)）。
   (5)关闭文件描述符（非必须）
     为了释放资源。
   (6)执行核心工作（必须，非必须就没有意义了） */


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>

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
        int fd = open("/home/yihui/temp-deamon-log.txt", O_CREAT | O_WRONLY | O_APPEND, 0664);
        int i;
        for (i = 0; i < 100; i++) {
            sleep(3);
            time_t curtime;
            time(&curtime);
            char* pt = ctime(&curtime);
            write(fd, pt, strlen(pt) + 1);
        }
        close(fd);
    }

    return EXIT_SUCCESS;
}
