0.这是什么？有什么用？
Linux大神将双向循环链表需要开发者对链表基本操作函数的封装，便于直接调用（复杂到用指针套了很多层指针，不过还有反转等功能哦）
使用：#include "kernel_list.h"

struct kernel_list{//宿主
	struct student std;
	struct list_head myList;//包含两个指针的（小）结构体
}

内核链表中封装好的这些宏函数以及普通函数绝大部分都是在对小结构体指针进行操作
***
1.先上来个式子热热身
((type *)((char *)(ptr)-(unsigned long)(&((type *)0)->member)))
含义:


2.大结构体（宿主）
小结构体
使用时要处理小结构体,操作小就能影响大

3.list_entry是什么

4.注意list_for_each的使用
list_for_each_entry:第一个参数不能传错
参数代表意思很重要
list_for_each_entry_safe
例子：
//重点：指定位置前插
int kernel_assign(struct kernel_list *head ,struct kernel_list *new ,char *name){
	struct kernel_list *pos; 
	/*list_for_each list_for_each_entry_safe*/
	list_for_each_entry(pos,&head->myList,myList){
		if(strcmp(pos->stu.name,name)==0)
			break;
	}
	//注意：这里的pos是大结构体的,不能直接用
	pos->myList.prev->next = &new->myList;
	new->myList.next = &pos->myList;
	new->myList.prev = pos->myList.prev;//与下面交换，连接会断，转换处理
	pos->myList.prev = &new->myList;//本来在第三，连接会断，所以放第四
	/*list_add()又有什么不同*/
	return 0；
	//什么时候会要pos.myList=pos.myList->next;
}

5.坑：static inline void __list_add(struct list_head *new,struct list_head *prev,struct list_head *next)里三参数的解析


6.涉及知识点：static inline(多次调用的且循环较少或无循环的函数，牺牲空间实现快速调用)   &   宏定义（带参数）

7.相关参考
http://blog.chinaunix.net/uid-27037833-id-3237153.html
http://blog.csdn.net/tigerjibo/article/details/8299599
http://blog.csdn.net/coding__madman/article/details/51325646

所有的内核链表的操作函数都是对小结构体进行操作的，不要错误理解成大结构体
      (3)内核链表的遍历：
             方法一：list_for_each()跟list_entry()相互配合实现遍历
             方法二：list_for_each_entry(pos, head, member) 将方法一的二个宏函数合并了
                       pos ---》大结构体指针
                       head ---》小结构体指针
                       member ---》小结构体在大结构体中的名字
                    注意：第一个参数一定不要传参错误，是大结构体
             方法三：list_for_each_entry_safe(pos, n, head, member)  往往在删除节点的时候使用
                       pos ---》大结构体指针
                       n ---》大结构体指针
                       head ---》小结构体指针
                       member ---》小结构体在大结构体中的名字
      （4）删除
             list_for_each_entry_safe(pos, n, head, member)
             list_del(struct list_head *entry)
                    entry ---》你想要删除的那个节点里面的小结构体指针 
      （5）list_move(struct list_head *list,
struct list_head *head)
             list_move（） ---》将指定的节点移动到head的下一个位置
             list_move_tail（）---》将指定的节点移动到最后面
      （6）container_of(ptr, type, member) 求ptr对应的大结构体 
虽然内核链表没有给我们封装指定位置插入的函数，但是你可以自己去写，注意使用的指针是小结构体里面的next和prev
       总结：(1)经过反复使用内核链表，加上分析了源码，我们发现内核链表跟前面学的双向循环链表的操作模式是类似的，只是要注意内核链表是操作的小结构体指针，所有在指针的写法上变得很啰嗦（自己体会，查看我写的最终代码）
             (2)内核链表中封装的那个小结构体一般都写成普通结构体，注意在使用的时候取地址
