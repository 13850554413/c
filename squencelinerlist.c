#include <stdio.h>
#include <stdlib.h>

#define Size 5
typedef struct Table{
    int * head;//声明了一个名为head的长度不确定的数组，也叫“动态数组”
    int length;//记录当前顺序表的长度
    int size;//记录顺序表分配的存储容量
}table;

table initTable(){
    table t;
    t.head=(int*)malloc(Size*sizeof(int));//构造一个空的顺序表，动态申请存储空间
    if (!t.head)//如果申请失败，作出提示并直接退出程序
    {
        printf("初始化失败\n");
        exit(0);
    }
    t.length=0;//空表的长度初始化为0
    t.size=Size;//空表的初始存储空间为Size
    return t;
}

void shuru(table t)
{
    for (int i = 1; i<=Size; i++)
    {
        t.head[i-1] = rand() % 101;
        t.length++;
    }
    printf("\t数据已产生！\n");
}

void shuchu(table t)
{
    int i;
    if (t.size != -1)
        {
        printf("\t顺序表中的内容为\n");
        for (i = 0; i <= t.size; i++)//
        {
            printf("\t%d", t.head[i]);
        }
    }
    else
    {
        printf("\n\t\t顺序表为空！\n");
    }
}

/* void zhikong() */
    /* { */
	/* L.last = -1; */
	/* printf("\n\t\t已清空！\n"); */
/* } */

/* void changdu() */
/* { */
	/* if (L.last != -1) */
	/* { */
		/* printf("顺序表的长度为：\t%d\n", L.last + 1); */
	/* } */
	/* else */
	/* { */
		/* printf("\n\t顺序表为空！\n"); */
	/* } */
/* } */

//插入函数，其中，elem为插入的元素，add为插入到顺序表的位置
table addTable(table t,int elem,int add){
    //判断插入本身是否存在问题（如果插入元素位置比整张表的长度+1还大（如果相等，是尾随的情况），或者插入的位置本身不存在，程序作为提示并自动退出）
    if (add>t.length+1||add<1) {
        printf("插入位置有问题\n");
        return t;
    }
    //做插入操作时，首先需要看顺序表是否有多余的存储空间提供给插入的元素，如果没有，需要申请
    if (t.length==t.size) {
        t.head=(int *)realloc(t.head, (t.size+1)*sizeof(int));
        if (!t.head) {
            printf("存储分配失败\n");
            return t;
        }
        t.size+=1;
    }
    //插入操作，需要将从插入位置开始的后续元素，逐个后移
    for (int i=t.length-1; i>=add-1; i--) {
        t.head[i+1]=t.head[i];
    }
    //后移完成后，直接将所需插入元素，添加到顺序表的相应位置
    t.head[add-1]=elem;
    t.length++;
    return t;
}

table deltable(table t,int add){
    if (add>t.length || add<1) {
        printf("被删除元素的位置有误\n");
        return t;
    }
    //删除操作
    for (int i=add; i<t.length; i++) {
        t.head[i-1]=t.head[i];
    }
    t.length--;
    return t;
}

void main()
{
	int b = 1, k;
    int add, elem;  // add为插入表的位置，elem为插入的元素
    table L = initTable();
	while (b)
	{
		printf("\n\n\t顺序表上的基本运算\n");
		printf("\t ----------------------------\n");
		printf("\t|1.... 顺序表数据输入       |\n");
		printf("\t|2.... 顺序表数据输出       |\n");
		printf("\t|3.... 顺序表数据置空       |\n");
		printf("\t|4.... 顺序表数据长度       |\n");
		printf("\t|5.... 顺序表数据插入       |\n");
		printf("\t|6.... 顺序表数据删除       |\n");
		printf("\t|0.... 退出                 |\n");
		printf("\t ----------------------------\n");
		printf("\t请选择：");
		scanf("%d", &k);
		switch (k)
            {
			case 1:
                shuru(L);
                break;
			case 2:   shuchu(L);    break;
			case 3:
                /* zhikong();    */
                break;
			case 4:
                /* changdu() */
                break;
			case 5:
                printf("\n你想要在第几个数据处插入？\n");
                scanf("%d", &add);
                printf("输入待插入的数据\n");
                scanf("%d", &elem);
                L = addTable(L, elem, add);
                break;
			case 6:
                if (L.size != -1) {
                    int i = 0, j = 0;
                    shuchu(L);
                    printf("\n你想要删除的数据？\n");
                    /* printf("\n你想要删除第几个数据？\n"); */
                    scanf("%d", &i);
                    deltable(L, i);
                    /* if ((i<0) || (i>L.last + 1)) */
                    /* { */
                                /* printf("出现错误!"); */
                    /* } */
                    /* else */
                    /* { */
                        /* //移动元素位置（i为删除数据的位置） */
                        /* for (j = i; j <= L.last; j++) */
                        /* { */
                            /* L.data[j - 1] = L.data[j]; */
                        /* } */
                        /* //表的最后一个元素的指向减小（当前表中实际存放元素数量） */
                        /* L.last--; */
                        /* shuchu(); */
                    /* } */
                }
                else {
                    printf("\n\t\t顺序表为空！\n");
                }
                break;
			case 0:	  b = 0;       break;
			default:printf("\n\t\t请输入正确的选择!\n");
		}
		if (b != 0) { printf("\n\t"); /*system("pause");*/ }
	}
	printf("\n谢谢使用！qwq\n");
}
