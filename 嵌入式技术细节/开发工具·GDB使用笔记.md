=============GDB调试程序===========
1.调试代码初级方法
     加打印语句：在关键语句的前后，打印关键性的变量
2.使用GDB这个软件工具来帮助你调试
     安装gdb  sudo apt-get install gdb
     如果你想要使用gdb来调试你的程序，编译的时候必须加上-g这个选项
             gcc hello.c -o hello -g 
                                  -std=c99
                                  -Wall
                                  -E
                                  -S
                                  -c
     gdb调试代码常用的命令
       （1）打印代码
              l          默认只打印前面10行
              l  1，20   打印1到20行
       （2）设置断点
              b  行号    b  10
       （3）程序运行
              r  
       （4）程序单步运行
              n或者s
              n不进入调用的函数内部
              s进入调用的函数内部
       （5）打印变量的值
              p 变量名字
       （6）查看当前断点信息
              info b
            删除断点
              d 
       （7）追踪变量的值
            display 变量的名字
       （8）继续运行程序
              c   继续运行程序，直到遇到下一个断点或者程序结束                         
3.段错误的调试(需要用到core文件，core文件中包含了产生段错误的信息)
        core文件也被称作核心转储文件
        产生段错误的根本原因是你写的代码中访问了非法内存
        步骤：
              （1）先查看系统中core文件，ulimit -a
                    得到结果是：core file size          (blocks, -c) 0  表示无法生成core文件
              （2）让系统能够自动生成core文件
                    ulimit -c unlimited
              （3）使用gdb来查找段错误
                    gdb ./程序名  core文件的名字
                    gdb ./test  core
       使用经验：使用core来寻找段错误并不是万能的，有时候找到的信息看不懂，那就只能使用传统的方法，重点查找指针，取地址的那些变量是否操作有误


==================生成库文件==================
1.库文件分为两类：
     动态库文件   .so结尾的文件
     静态库文件   .a结尾的文件
  库文件的名字：
     libxxxxxxx.so
     libxxxxxx.a
2.动态库
     步骤：（1）先将.c文件编译成.o    gcc test.c -o test.o -c
           （2）将上一步得到的.o文件进一步编译得到动态库文件
                  gcc -fPIC -shared test.o -o libxxxx.so
           （3）以前的.c可以不要了，只使用动态库就可以生成程序了
                  方法一：gcc  main.c libxxxx.so -o main  当运行程序的时候需要加载动态库文件，需要将libxxx.so拷贝到系统专门用于存放动态库的文件夹里面
                          不能写反了gcc libxxxx.so main.c -o main(错误的)
                  方法二：gcc main.c -o main  -L库文件所在的路径   -l库文件的名字
                                -L  指明库文件的路径
                                -l  指明库的名字(去掉lib，去掉后缀)
                  如果你不想将动态库文件放置到系统默认的路径中，你可以选择自己设置新的路径
                     export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH   此例子是将当前路径.设置成环境变量
3.静态库
    步骤：（1）先将.c文件编译成.o    gcc test.c -o test.o -c
          （2）将上一步得到的.o文件进一步编译得到静态库文件
                  ar -rcv libxxxx.a test.o   （没有-o，顺序别搞反了）
          （3）以前的.c可以不要了，只使用静态库就可以生成程序了
                  方法一：gcc  main.c libxxxx.a -o main     由于使用的是静态库，所以不需要将库文件拷贝到环境变量中
                          不能写反了gcc libxxxx.so main.c -o main(错误的)
                  方法二：gcc main.c -o main  -L库文件所在的路径   -l库文件的名字
                                -L  指明库文件的路径
                                -l  指明库的名字(去掉lib，去掉后缀)
4.动态库和静态库的区别
     动态库是在程序运行的时候加载到程序中去的，所以你在运行动态库编译的程序的时候需要依赖你的库文件
     但是静态库是程序编译的时候就已经自动编译进去了，所以运行的时候不需要依赖静态库文件

2017-02-09
==============Makefile的使用============
1.Makefile的作用：理清复杂的大型工程项目代码之间的联系
                  管理大型工程项目源码

2.Makefile的使用
目标：依赖
     执行
版本一：
     main:main.c
     	gcc main.c -o main
     注意gcc前面是用tab键缩进的，不能使用空格   

版本二：（引入变量）
TARGET=main
SRCS=main.c 
CC=gcc
$(TARGET):$(SRCS)
	$(CC) $(SRCS) -o $(TARGET)
    
版本三：（自动搜索所有的.c）
TARGET=main
SRCS=$(wildcard *.c) 
CC=gcc
$(TARGET):$(SRCS)
	$(CC) $(SRCS) -o $(TARGET)
wildcard *.c使用wildcard这个函数匹配所有的.c结尾的文件

版本四：（生成.o文件）
TARGET=main
SRCS=$(wildcard *.c) 
OBJ=$(patsubst %.c,%.o,$(wildcard *.c))
CC=gcc
$(TARGET):$(OBJ)
	$(CC) $(OBJ) -o $(TARGET)
patsubst这个函数替换.c为.o

版本五：（保存.o文件）
TARGET=main
SRCS=$(wildcard *.c) 
OBJ=$(patsubst %.c,%.o,$(wildcard *.c))
CC=gcc
$(TARGET):$(OBJ)
	$(CC) $^ -o $@
%.o:%.c
	$(CC) $< -o $@ -c
生成中间文件.o ？？？
  写法一 %.o:%.c有问题
  写法二 $(OBJ):$(SRCS)有问题
  写法三 $(CC) $(SRCS) -o $(OBJ) -c  有问题
         $(CC) $(OBJ) -o $(TARGET)
初级依赖$<   终级依赖$^     目标$@

版本六：（添加了删除操作）
TARGET=test
SRCS=$(wildcard *.c)
OBJ=$(patsubst %.c, %.o, $(wildcard *.c))
CC=gcc
$(TARGET):$(OBJ)
	$(CC)  $^ -o $@  
%.o:%.c
	$(CC) -o $@ -c $< 

clean:
	rm *.o $(TARGET)

======================开发板的使用=================
1.官方名称：s5pv210   (我们这块开发板cpu芯片的名字)
            gec210    粤嵌取的名字
            该芯片采用的是ARM架构，三星公司出产，属于ARM   Cortex-A8系列
            传统的PC里面的cpu是X86架构的
            ARM是一家英国公司，专门设计CPU的架构，三星，高通，TI德州仪器，联发科，华为等等都是按照ARM公司的设计生产属于自己公司的cpu芯片
2.进入开发板操作系统
    （1）使用secure CRT这个软件辅助我们查看开发板操作系统里面的内容
           配置secure CRT
              一：安装usb转串口的驱动
              二：打开secure CRT这个软件，删除别人旧的配置
                  协议：serial
                  端口：实事求是，去设备管理器查看究竟是端口几
                  波特率：115200
                  右边的勾取消
                  点击连接
              三：开发板上电
    （2）开发板启动的过程
          先启动uboot---》启动内核kernel---》最后进入根文件系统rootfs
              uboot：板级初始化，初始化cpu，内存等等
              kernel：配置网络，内存管理，其他一些系统服务
              rootfs：管理存放文件
    （3）开发板根文件系统中的目录
IOT                 driver_test         lost+found          sys
etc                 mnt                 tmp
bin                 opt                 tslib
home                proc                upiot.sh
data                lib                 root                usr
dev                 linuxrc             sbin                var
    （4）文件如何下载到开发板
           方法一：使用串口下载
                    rz 回车----》自动弹出对话框---》手动选择你要下载的文件---》双击，自动下载
                    rx 你要下载的文件名字  回车---》点击传输---》选择发送xmdem---》会弹出对话框---》手动选择你要下载的文件---》双击，自动下载
                    rz无法覆盖同名文件，rx可以覆盖同名文件
           设置默认下载，上传的路径：点击选项---》选择会话选项---》点击xmodem/zmodem
                  使用串口上传
                    sz 文件名 回车
           串口下载文件速度很慢，你可以将文件压缩一下再下载
  
          方法二：tftp下载
                  情况一：windows和开发板之间tftp
                  第一步：修改开发板的ip地址ifconfig eth0 正确的ip（一次性的，开发板重启之后就没有了）
                          永久修改开发板的ip地址   打开/etc/init.d/rcS这个文件，修改ifconfig eth0 你先要的ip地址
                  第二步：分别用ping命令去ping电脑和开发板
                  第三步：打开tftpboot这个软件
                          配置好电脑的ip，选择好你要下载的文件的目录
                  第四步：
                          下载：在开发板中输入tftp -r 要下载的文件名  -g 电脑的ip
                          上传：在开发板中输入tftp -r 要下载的文件名  -p 电脑的ip
                  情况二：ubuntu和开发板之间tftp
                          跟情况一差不多，不太稳定（开发板和电脑之间用网线直接连效果很好）
          方法三：nfs挂载
                  
2017-02-10 
=================烧写系统=================
1.烧写系统：你原来的系统崩溃了，更新新的系统，更换新类型的操作系统
2.uboot烧写系统
   注意的问题：
   1.千万别用快捷键去粘贴以下命令，会出错
   2.先配置好开发板和电脑的ip，使得二者能够tftp下载
   3.在使用uboot下载的使用本地连接有时候是断开网线的（这个没有关系，关键是要配置好开发板，电脑，uboot的ip地址）
   4.以下的第一步注意别完全复制
如何通过uboot来更新系统（u-boot.bin,zImage,rootfs.img）

1)修改uboot的网络配置
重启开发板，倒数三秒之前按下任意键，选择e进入到uboot
GEC210 # setenv serverip 192.168.1.100   // 电脑的ip
GEC210 # setenv ipaddr 192.168.1.5  //只要不跟电脑和开发板冲突就行
GEC210 # setenv gatewayip 192.168.1.1
GEC210 # save

2)更新uboot
GEC210 # tftp 0x40000000 uboot-gec210.bin
GEC210 # nand erase 0x0 0x100000 -->擦除nand中uboot的分区
GEC210 # nand write 0x40000000 0x0 0x100000

3）更新zImage
GEC210 # tftp 0x40008000 zImage
GEC210 # nand erase 0x600000 0x500000
GEC210 # nand write 0x40008000 0x600000 0x500000

4）更新rootfs
GEC210 # tftp 0x40000000 game_fs.img
GEC210 # nand erase 0xe00000 0x1F200000
GEC210 # nand write.yaffs 0x40000000 0xe00000 0x*******
xxx--->Bytes transferred = 4011628 (0x3d366c) --->实际下载文件的大小

遇到的问题：
    问题一：ip配置都对，但是无法ping通
             原因一：网线坏了
             原因二：关闭掉电脑的防火墙
    问题二：ip配置都对，tftp下载总是重启
             关闭防火墙
    

========================交叉工具链的安装和使用============================
1.引入概念
    交叉编译：程序的编写，编译在pc上面进行，但是程序的运行在开发板上运行，这个过程被称作交叉编译（分工协作）
2.工具链的安装
    （1）将源码包拷贝纯粹的linux环境中(不要在共享中直接解压，会出错，原因是windows不支持linux中的链接文件)
    （2）解压源码包
    （3）设置环境变量
         export PATH=/usr/arm-2009q3/bin:$PATH  把路径/usr/arm-2009q3/bin设置成环境变量，原因是我刚才解压工具包的时候就放在这个路径里面了

以下工具是属于ARM架构下编译程序用到的
 arm-linux-as        binutils    编译ARM 汇编程序 
 arm-linux-ar        binutils    把多个.o 合并成一个.o 或静态库(.a) 
 arm-linux-ranlib    binutils    为库文件建立索引，相当于arm-linux-ar -s 
 arm-linux-ld        binutils    连接器(Linker), 把多个.o 或库文件连接成一个可执行文件 
                                            
 arm-linux-objdump     binutils     查看目标文件(.o)和库(.a)的信息 
 arm-linux-objcopy     binutils     转换可执行文件的格式 
 arm-linux-strip       binutils     去掉elf 可执行文件的信息. 使可执行文件变小 
 arm-linux-readelf     binutils     读elf 可执行文件的信息 
 arm-linux-gcc         gcc          编译.c 或.S 开头的C 程序或汇编程序 
 arm-linux-g++         gcc          编译c++程序 
3.小项目
 交叉编译tftp，默认情况下我们下载tftp源码包是使用gcc编译的，属于x86架构下面的tftp，但是我们开发板上需要ARM架构的tftp
   步骤：
        （1）在家目录下新建一个文件夹用于存放tftp的源码（例如：tftpcode）
        （2）进入到tftpcode目录中，执行sudo apt-get source tftp
        （3）进入到下载的netkit-tftp-0.17/tftp目录中，打开Makefile文件，进行修改
all: tftp
CC=arm-linux-gcc    // 添加这一句，把编译器改变成ARM架构下
#include ../MCONFIG  // 用#将这两句注释
#include ../MRULES

OBJS = tftp.o main.o tftpsubs.o

tftp: $(OBJS)
	$(CC) $(LDFLAGS) $^ $(LIBS) -o $@

$(OBJS): tftpsubs.h
tftp.o: ../version.h

install: tftp
	install -m$(BINMODE) tftp $(INSTALLROOT)$(BINDIR)
	install -m$(MANMODE) tftp.1 $(INSTALLROOT)$(MANDIR)/man1

clean:
	rm -f *.o tftp
          （4）保存退出Makefile，在netkit-tftp-0.17/tftp目录中执行make命令，就可以得到ARM架构下tftp程序
          （5）编译好的tftp就可以在开发板上使用了

============开发板实用小技巧===============
1.将u盘挂载到你的开发板
     步骤：
        （1）将u盘插上开发板的usb口，会自动识别出你的u盘，并且会分配一个驱动名字（比如：sda4）
        （2）使用mount命令去挂载u盘
               mount  /dev/xxx   /2017     将u盘xxx挂载到根目录下面的2017
        （3）删除u盘
               umount /2017
2.开机自动运行程序
     修改/etc/profile这个文件，在最后面加上你要自动运行的那个程序的绝对路径，然后保存退出，重启开发板
