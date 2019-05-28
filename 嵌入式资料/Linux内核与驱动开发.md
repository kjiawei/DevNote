Linux系统的使用与开发中，内核与驱动是比较重要的一块;而驱动开发类似系统编程,用到的是内核函数。驱动开发难点在于协议总线等概念的理解(Makefile等文件的处理),一般遵循设备驱动模型即可(套路)。
①内核主要作用:进程管理与通信（创建进程、fifo、pipe、共享内存...）、内存管理、文件系统（ext2/3/4、fat、yaffs）、网络通信（IPv4、IPv6、GPRS....）等等
②驱动是一种模块,可静(动)态编译进内核[增删内核功能],硬件操作接口,由目标代码组成

参考书籍:《深度实践嵌入式linux系统移植》看源码-不懂再看《Linux内核探秘》《Linux驱动开发入门与实战》（第2版）-USB驱动
《深入剖析Linux内核与设备驱动》
我理解的移植步骤:工具链设置(环境变量配置) 驱动移植 makefile等文件的修改 编译 内核配置选项
源码分析贯穿整个流程<->多线程设计/并发控制 互斥&同步
###一 学习目标与步骤   (2.6.18版本内核 ubuntu12.04编译环境为例)[邓建议内核学习方向(硬件角度)[看操作系统的书]:驱动->内存->->设备,文件入手的->计科]
0.了解(内核启动流程 u-boot移植与编译);
精通(内核修改 移植驱动);熟练(uboot设备驱动相关总线 设备 中断 积累深入->全面 新的重要特性 快速掌握重点->内核hacker)  
1.理解内核设计原理与目标
2.看懂数据结构与算法
3.学习方法:代码(流程)笔记->复习资料,实验问题->解决方案,总结复习
4.编写驱动注意事项
5.移植规律总结
6.面试要求:字符设备注册 用到函数 中断

###二 操作系统通常提供的服务:内存管理 进程管理 设备管理 文件系统
0.什么是一款好的操作系统 (深度学习 自主学习)
OS:多任务(中断+定时器) 软硬件分离 优秀的用户体验 快速存储(碎片管理算法) 
设备管理 驱动
1.内核分基础层(工作队列 tasklet 信号量 自旋锁)[突出内核API概念]和应用层(文件系统 设备 驱动 网络)[突出重点架构与典型例子加深理解]
2.内核架构(块/字符设备 总线 文件系统的VFS层)   
内核实现()
学习主线:文件系统概念和操作过程->具体设备到总线再到驱动->文件系统读写 内核通用块层 结合实际做一些小程序(自己实现内核的I/O路径 模拟的块设备系统)

###三 理解设备驱动框架与编写步骤和基础(大多雷同)
[为文件系统提供的VFS架构] 
驱动设计要求(区别逻辑的重要性,多用判断 位操作):稳定 高效 可靠 [Linux源码 硬件知识了解],复杂驱动要移植:USB(厂商提供) Nand LCD;
需要基础:①GNU C-结构体直接赋值(区别ANSI C,不能用C库,不要用浮点[缺乏用户层内存保护])②硬件基础(熟练芯片手册接口 常用设备SRAM Flash UART IIC USB等;最好能设计电路)③熟练内核源代码(数据结构和算法)④多任务程序设计 自旋锁 互斥锁和信号量等
驱动模板:1.头文件 init exit 作者信息(__init修饰初始化函数只执行一遍,初始完后释放,修饰代码存.init.text)
2.Makefile:参考linux-2.6.35.7-gec-v3.0-gt110\Documentation\kbuild\modules.c里50-100行的描述

###四 问题整理与驱动编写注意事项 
1.(驱动)一个寄存器的使用 设备链路状态如何检测 文件系统如何使用barrier I/O 同步和异步I/O区别
2.(内核)zImage导出到共享看不到
3.升级新驱动考虑内容:优化对内存 IO性能,可能带来问题:不稳定
6.18内核编程模块详解 小白(微信)

###五 内核启动流程与移植步骤
####启动流程
1.输出内核版本与CPU版本,重新初始化系统时钟
2.初始化串口，沿用了S3C2410/S3C2440(ARM9 2004年)串口初始化代码，可以知道软硬件也是可以迭代更新
3.发现u-boot传给内核的命令行参数
4.初始化内存系统(虚拟地址),(网络),实时时钟,LCD等驱动,Nand和SPI,其它设备驱动(很多都是USB设备相关)
5.挂载根文件系统及进入shell命令环境
####移植步骤
1.交叉编译Makefile修改,检查是否存在“.config”文件(make menuconfig命令配置与裁剪内核，退出会生成)make -j 4//四线程编译->成功标志:zImage is ready(arch/arm/boot/下)
2.下载并引导内核 tftp 0x30008000 zImage;bootm 0x30008000(打印内核zImage-uImage)
####书籍额外了解
内核 图灵系列  sylixOS操作系统(歼15)-vxworks
Linux必须运行在支持MMU(不同于ucos的纯物理地址) MPU都能跑(都带MMU,单片机不带)
STM32部分高端可以跑(m7 m4高端)-内存保护单元(也可以 mclinux)
MMU 地址转换 权限
编译出的程序入口地址都一样(虚拟地址) 不会覆盖->MMU找到没使用的物理内存

###六 内核模块
内核模块使用优点:紧凑灵活 不用重编 作用域&静态链接与目标代码等价
缺点:性能&内存利用缺失(符号表维护 模块间依赖性维护)-使用不当会崩溃
[第一点，就是源码树中有相应的头文件和函数的实现，没有源码树，你哪调用去呢？（pc上编译的时候内核有导出符号，系统中有头文件，这样就可以引用内核给你的接口了，但是只能编译你pc上版本的内核可加载的模块）。第二个，内核模块中会记录版本号的部分，需要记录版本号的原因是不同的[内核版本](https://www.baidu.com/s?wd=%E5%86%85%E6%A0%B8%E7%89%88%E6%9C%AC&tn=44039180_cpr&fenlei=mv6quAkxTZn0IZRqIHckPjm4nH00T1YYPyRzujD1nW7buHb4uAD0IAYqnWm3PW64rj0d0AP8IA3qPjfsn1bkrjKxmLKz0ZNzUjdCIZwsrBtEXh9GuA7EQhF9pywdQhPEUiqkIyN1IA-EUBtzPWf3PWn3nWDvnHRYPH6snjR)之间，那些接口和调用可能会有比较大的差异，因此必须要保证你的代码和某个特定的内核对应，这样编译出来的模块就可以（也是只能）在运行这个[内核版本](https://www.baidu.com/s?wd=%E5%86%85%E6%A0%B8%E7%89%88%E6%9C%AC&tn=44039180_cpr&fenlei=mv6quAkxTZn0IZRqIHckPjm4nH00T1YYPyRzujD1nW7buHb4uAD0IAYqnWm3PW64rj0d0AP8IA3qPjfsn1bkrjKxmLKz0ZNzUjdCIZwsrBtEXh9GuA7EQhF9pywdQhPEUiqkIyN1IA-EUBtzPWf3PWn3nWDvnHRYPH6snjR)的[Linux系统](https://www.baidu.com/s?wd=Linux%E7%B3%BB%E7%BB%9F&tn=44039180_cpr&fenlei=mv6quAkxTZn0IZRqIHckPjm4nH00T1YYPyRzujD1nW7buHb4uAD0IAYqnWm3PW64rj0d0AP8IA3qPjfsn1bkrjKxmLKz0ZNzUjdCIZwsrBtEXh9GuA7EQhF9pywdQhPEUiqkIyN1IA-EUBtzPWf3PWn3nWDvnHRYPH6snjR)中加载，否则一个很简单的异常就会导致内核崩溃，或者你的代码根本无法编译通过(接口名变了)。我上面说的是编译模块的情况，当然如果是把模块直接编译到内核当中去的话，那就不用说了，没有内核源码，你无法编译内核。]

#### 驱动编写与加载
1.修改源码 led_drv.c及makefile
2.进入驱动目录并make(前提:kernel是编译成功过的)
3.生成的.ko拷贝到开发板并加载insmod(lsmod查看当前模块)[remmod卸载原 rmmod led_drv]

4.设备文件创建
手动:mknod /dev/led_drv c 238 0
自动:

##### 驱动机制

#### 数据交换
copy_to_user 
copy_from_user

![Paste_Image.png](http://upload-images.jianshu.io/upload_images/2636843-8ffc16e1c4f33ad1.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

#### 字符设备 C开头(字节为单位)
设备驱动分类(dev目录)->开发板查看设备及权限ls -l;保证有设备文件(open能打开) 
*块设备(b开头-kb[块]为单位)-主要是存储设备(nand sd u盘 硬盘)
tty控制输入(台)  主/次设备号(类比进程ID)
重要:网络设备(有/无线网卡 socket编程 没有设备文件)

#### 输入子系统(设备)
usb-wifi 输入子设备
Linux 输入子系统原理理解（原创）:https://www.cnblogs.com/lihaiyan/p/4274456.html
详解:https://www.cnblogs.com/lifexy/p/7542989.html

##### 游戏移植用到的库 SDL
移植问题收集 修改架构为arm 交叉编译器 ./configure 使能共享 库的共享

##### 设计流程(工作重要)
0.定义字符设备结构体cdev  <linux/cdev.h>
1.申请(动.alloc_chrdev_region/静态.MKDEV  .register_chrdev_region)设备号 2.定义文件操作集file_operations<linux/fs.h>并且初始化(函数都是函数指针 重定向) [dev_t 无符号32位整型 设备号:主+次的组合;count申请次设备的数量(同一个主设备号下申请,串口例子)]2.1初始化cdev结构 .cdev_init 3.注册字符设备到内核.cdev_add 4.自动创建设备文件(4.1手动创建 /dev/下mknod命令创建 4.2自动)

###### 设备号
32位(31-20主(区分不同硬件类型:uart i2c spi)  19-0次(同硬件类型下不同硬件实体)[uart0 uart1...] 组成)
申请函数:MKDEV <linux/kdev_t.h>
注册:register_chrdev_region
*周立功编写流程

### GPIO使用


###七 U-Boot编译与移植  
(先理解原理 框架 官方SDK)
介绍 注意事项[汇编跑C前一定要初始化内存-函数栈]
uboot推荐工具链4.4.1 uboot移植文档对应的内存修改
先改网卡   ubuntu下声卡  MMU虚拟-物理转换
-----------------------------------------------------------------
不同阶段主要任务:BL0活起来 
BL1(与外界通信)中断 堆栈 内存 CPU -初始化  start.S   (smdk .h)    扩展类设置都在C;
BL2 串口 网卡   其余外设 初始化

[内存0x20000000映射到0x30000000对粤嵌意义
1.
2.内核以外 内存越出256M 空档期 连地址
start_armboot 扩展]

###八 文件系统
1.内核运行步骤可参照uboot运行步骤
2.文件系统-存储方面:图像算法 区别http://www.ntfsformac.cn/qita-nytqubie.html
视频服务器分区-64K(分配管理节点少了,提高服务器速度,节省了内存资源)
3.存储交换技术-虚拟内存(很久没用的数据搬到硬盘)
4.uboot主要改的地方:设备启动的地方 boot 怎么加driver

### 地址
1.内存范围(内核空间0xc0000000-ffffffff) 用户空间(用户态0-bf)
虚拟地址:隔离进程 提高内存安全性

### 频率与时钟
#### 如何超频
就是修改CPU的频率，来增加系统的运行速度。CPU的外频设置（CPU External Frequency）是超频的关键之一，CPU的主频（即我们平时所说的P4 3.0G等等之内的频率）是由外频和倍频相乘所得的值，比如一颗3.0G的CPU在外频为200的时候他的倍频就是15,(200MHz*15＝3000MHz)。 外频一般可以设定的范围为100MHz到400MHz，但是能真正上300的CPU都不多，所以不要盲目的设置高外频，一般设定的范围约为100－250左右，用户在设定中要有耐心的一点点加高，最好是以1MHz为步进，一点点加，以防一次性加到过高而导致系统无法正常使用甚至CPU损坏！(通过接口软件进行设置)

###相关术语
GDT：系统中唯一的存放段寄存器内容（段描述符）的数组，配合程序进行保护模式下的段寻址。
GDT是保护模式下管理段描述符的数据结构，对操作系统自身的运行以及管理、调度进程有重大意义

![Paste_Image.png](http://upload-images.jianshu.io/upload_images/2636843-4153592cd961dbba.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![Paste_Image.png](http://upload-images.jianshu.io/upload_images/2636843-f73c922c5f28529a.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
