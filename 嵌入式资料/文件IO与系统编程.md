### 文件IO
1.stat是什么（可以做什么），怎么用，注意问题 
①stat获取文件的属性信息(usr/include/i386-linux-gnu/bits下查看)系统最重要的信息之一（模式位 大小 最后修改时间等）
②#include <sys/stat.h> 
原型int stat(const char *file_name, struct stat *buf);

通过文件名filename获取文件信息，并保存在buf所指的结构体stat中；返回值: 执行成功则返回0，失败返回-1，错误代码存于errno
//S_ISREG可判断是否为普通文件
2.dirent又是什么，怎么用，注意问题

3.open不能创建设备文件
创建驱动节点：mknod

4.fgetc:返回ASCII码值，int型

### 系统编程
select多路复用
消息队列优缺点:
