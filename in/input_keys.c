#include <fcntl.h>
#include <errno.h>
#include <linux/input.h>


// 读取键盘输入事件
/* int get_key_board_from_input() */
struct input_event input_key(void)
{
    int fd = -1, ret =-1;
    struct input_event ev;

    fd = open(INPUT_KEYBOARD,O_RDONLY);
    if(fd<0)
    {
        printf("open failed, error:%d\n", errno);
    }
    while(1)
    {
        memset(&ev, 0, sizeof(struct input_event));

        ret = read(fd, &ev, sizeof(struct input_event));
        if(ret != sizeof(struct input_event)){
            printf("read error, ret: %d\n", ret);
        break;
        }

        /*
        if(ev.type == EV_KEY){
            printf("-------------------------\n");
            printf("type = %u.\n", ev.type); [>消息类型, EV_KEY是按键<]
            printf("code = %u.\n", ev.code); [>按键信息，/usr/include/linux/input-event-codes.h文件中有定义键值，例如KEY_ESC对应esc按键 <]
            printf("value = %u.\n", ev.value); [> 按键是按下还是释放，0释放、1按下、2长按 <]
        }
        */
    }
    close(fd);
    return ev;
}
