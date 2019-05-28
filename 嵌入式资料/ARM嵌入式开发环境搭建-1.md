    之前写过一篇类似ARM开发环境搭建的文章，这篇做了个优化，为了对嵌入式开发做一个阶段性的总结与方便下次使用，也为了传播和学习。
    另外,结合  https://mp.weixin.qq.com/s/skMkkH9ktVkrwqJlVfTwPQ  性能优化做了部分参考。
2017.11.8     小雨      广州       我经过市民广场没有炸鸡
### 性能优化

系统IO分析工具之iotop  

手头上还有块:Cortex-A8(53)

需求及学习目标:拿到开发板需要快速搭建开发环境,准备:硬件(核心板 底板 电源 屏幕 串口线 网线 SD卡 U盘 等等)  软件(厂商提供的系统包  网上收集一些适合的  多多益善)  工具:热熔胶焊接好
移植 http://zhangjungang2000.blog.163.com/blog/static/144004663201132251036101/
配置文件执行顺序 http://www.cnblogs.com/xd502djj/archive/2013/02/25/2932544.html

远程控制开发板:编译openssh到开发板(teamviewer vnc ssh)
开发板->ssh(苏海龙 ssh)scp root@192.168.1.  ssh root@192.168.1.210
板上ftp工具 ftpflash

### 常用命令
#### 压缩
.tar.bz2
解压：tar jxvf FileName.tar.bz2
压缩：tar jcvf FileName.tar.bz2 DirName
tar.gz解压
tar -xzvf .tar.gz
#### cp 
-fv   强行复制文件或目录，不论目标文件或目录是否已存在,详细显示命令执行的操作
#### 管道
1xargs-由于很多命令不支持|管道来传递参数，而日常工作中有有这个必要，所以就有
### 一.常用软件 

#### 系统 Fedora deepin  limint
https://repo.fdzh.org/
####终端
①新建objcopy软连接:sudo ln -s arm-none-linux-gnueabi-objcopy(源) arm-linux-objcopy

####secureCRT 串口传输
①输入:1.rx 传输文件名;2.选择传输-》发送Xmodem->选择传输进来的文件;3.改变权限:chmod 777 文件名;4.运行：./文件名
②1.用yModem协议下载文件:rz -y    选择ymodern模式传输后 loady 0x40000000//下载到内存0x40000000;2然后选择yModem选择文件

####tftp
1.参数   不能传文件夹  拷贝目录 -r 《暗时间》
-g 表示下载文件 (get) -p 表示上传文件 (put) -l 表示本地文件名 (local file) -r 表示远程主机的文件名 (remote file)
开发板传文件到其它:tftp -l 文件名 -p 目标IP
下载:tftp -l 文件名 -g 目标IP

 TFTP基于UDP协议，如果环境中没有TCP协议，是比较合适的；
ü  TFTP执行和代码占用内存量比较小；
默认情况下，Linux内部是安装了tftp服务器包的。但是默认是不启动的
2.拓展  安装两法

①#### 1.PC机搭建一个TFTP服务器  -->共享目录(led.bin)
		1.1sudo vim /etc/inetd.conf 
				/srv/tftp
		1.2 sudo mkdir /srv/tftp
		    sudo chmod 777 /srv/tftp
		   cp led.bin /srv/tftp  // 把led.bin  放到/srv/tftp里面
		1.3启动tftp 服务器服务
			sudo /etc/init.d/openbsd-inetd reload


目前成熟系统设计中，都将FTP协议和传输定性为非安全(登录密码)传输协议。它和telnet登录方式，逐渐为SFTP和SSH协议所取代。在Linux流行版本中，SFTP已经成为默认配置项目。
在Linux发行版的光盘中，已经包括了vsftp服务器安装包，是需要手工安装
默认情况下，tftp服务器包是安装上的，而FTP服务器没有安装 rpm -qa | grep ftp

#### nfs
思考:开发板没有服务端可以反向挂载到PC或上面的虚拟机吗
开启服务  （出处:http://www.linuxidc.com/Linux/2013-08/89154.htm）
sudo /etc/init.d/portmap restart
sudo /etc/init.d/nfs-kernel-server restart 
挂载命令
mount -t nfs 192.168.1.202:/home(源) /nfs(目的) -o nolock

#### sourceInsight

#### 直接连电脑和开发板  开发板挂载u盘:fdisk -l查看U盘
mount -t ntfs(vfat) /dev/sda /mnt -o iocharset=utf8(gb2312)
mnt被挂坏了FAT bread     U盘:read-only file system

### 二.环境搭建
####刷系统（粤嵌）
usb线fastboot烧写:
1.跳出一个分区页表
2.问题驱动-fastboot下载驱动文件夹(或驱动精灵)
3.镜像文件夹，双击flash_bootloader.bat，烧写BootLoader(烧写时拔掉USB线断电会变砖)
4.重启再按下回车和u键进入fastboot烧写
5.双击flash_kernel.bat，烧写kernel
6.双击flash_system.bat，烧写system

#### 网络设置 虚拟机&开发板
ping通自己 不会是网卡得问题      destination host unreachable(网络出错等级-内核相关?)  interfaces文件详细说明    http://blog.csdn.net/mountzf/article/details/52035499
##### 0.网络不通 最下方有配置网络大全
①全部设置好却发现上不了网-先测试网关能不能ping通，114通不通(注意gateway不要写错)；
②无法识别网络可能跟网卡无线WiFi有关(后面加了sudo route add default gw 192.168.1.1   sudo /etc/init.d/networking restart可以了)
③桥接模式 nat模式 主机模式 区别http://jingyan.baidu.com/article/3f16e003cd0a0d2591c103b4.html

### 安装/更新软件
Some index files failed to download. They have been ignored...
解决:软件和更新里把独立软件源去掉，然后删除缓存，在刷新一下就可以了。 sudo rm -vfr /var/lib/apt/lists/* ，如果还是不行，那就更换软件源

1，虚拟机配置：
	player-》管理-》虚拟机设置-》网络适配器-》桥接模式
无论如何上不了网(ping网关不通):重置虚拟机网卡

2，获取root权限

3，更改网络配置文件
	vi /etc/network/interfaces
4，改成DNS
	vi /etc/resolvconf/resolv.conf.d/base
	
5，重启网卡（最快方式重新开机）
	reboot 直接重启
	
6，如果你的网络通过上面的配置不成，你可以检查一下地点
	ifconfig来查看你的IP地址设置有没有起效	

	vi /etc/resolv.conf
		查看有没有nameserver 202.96.128.33
		如果没有你就运行dhclient
	
	检查windows的网络适配器，看看VM的两个网卡有没有被禁用，需要启动这两个网卡

##### 1.安装源
1.source.list源 (etc/apt/下)http://www.360doc.com/content/14/0914/09/10072361_409316956.shtml#
163:http://mirrors.163.com/ubuntu
aliyun:http://mirrors.aliyun.com/ubuntu
2.安装时出现Depends: libbrasero-media3-dev (>= 3.0) but it is not going to be installed （apt-get install gnome-core-devel）System --> Administration --> Update Manager --> Settings --> Updates 中勾选    apt-get update
##### 2.配置文件
1.Unable to fetch some archives, maybe run apt-get update or try with --fix-missing?
解决：sudo vim /etc/resolv.conf  添加nameserver 8.8.8.8
2.etc/network/interfaces修改IP
##### 3.netstat测网
netstat判断UDP端口开启:netstat -nlp | grep udp

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
常用工具包安装
安装m4
wget [http://mirrors.kernel.org/gnu/m4/m4-1.4.13.tar.gz]
 tar -xzvf m4-1.4.13.tar.gz
cd m4-1.4.13 \
 ./configure --prefix=/usr/local
 make 
 make install

安装autoconf
wget [http://mirrors.kernel.org/gnu/autoconf/autoconf-2.65.tar.gz](http://mirrors.kernel.org/gnu/autoconf/autoconf-2.65.tar.gz) \ && tar -xzvf autoconf-2.65.tar.gz \ && cd autoconf-2.65 \ && ./configure --prefix=/usr/local make && make install
安装automake
wget [http://mirrors.kernel.org/gnu/automake/automake-1.11.tar.gz](http://mirrors.kernel.org/gnu/automake/automake-1.11.tar.gz) \ && tar xzvf automake-1.11.tar.gz \ && cd automake-1.11 \ && ./configure --prefix=/usr/local make && make install
安装libtool
wget [http://mirrors.kernel.org/gnu/libtool/libtool-2.2.6b.tar.gz](http://mirrors.kernel.org/gnu/libtool/libtool-2.2.6b.tar.gz) \ && tar xzvf libtool-2.2.6b.tar.gz \ && cd libtool-2.2.6b \ && ./configure --prefix=/usr/local make && make install
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#### 环境变量  自动运行etc/init.d/rcS   etc/profile  upiot.sh
区别:系统（谨慎操作）/etc/bash.bashrc;
进入用户目录下的.bashrc：sudo vim ~/.bashrc;/etc/profile   
***
问题：
①默认情况下看不得，.bashrc属于隐藏文件，用“ls -l -a”可以查看；
②头文件加入系统环境变量:/usr/include放头文件
http://blog.chinaunix.net/uid-27105712-id-3270102.html
两种方法：
①上面的bashrc文件里最后输入你想要声明的环境变量
例如：export PATH=/usr/local/arm/arm-2009q3/bin:$PATH（这是配置交叉工具链:之前还要tar xzvf arm-2009q3.tar.gz先->[-C  ~//解压到指定目录]）生效:每次修改.bashrc后，使用source ~/.bashrc（或者 . ~/.bashrc）就可以立刻加载修改后的设置，使之生效；系统的要重启，用户的要注销才能生效

#### 编译与调试
没有arm-linux-gcc工具解决方法：
1、切换为root用户 ;2、gedit /etc/bash.bashrc(这是系统环境变量,用户的~/.bashrc) 在最下面一行添加  export PATH=$PATH:/usr/local/arm/bin(使能工具链,又例:export PATH=/usr/local/arm/arm-2009q3/bin:$PATH) ; 3、source /etc/bash.bashrc
#####0.编译位数与结构体求长例子
![机器位数与编译位数是否对变量影响.png](http://upload-images.jianshu.io/upload_images/2636843-65973e2a6be3ff96.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

#####1.gcc编译
编译生成可执行代码总共分四个步骤：预处理--》编译--》汇编--》链接
gcc main.c add.c  -o main  //多文件
预处理：gcc hello.c -E -o yuchuli  //作用：处理预处理命令，将include define内容解释出来
编译：gcc hello.c -S -o bianyi //作用：检查语法错误，翻译成汇编语言
汇编：gcc hello.c -c -o huibian //作用：汇编语言变成机器指令
链接：gcc hello.c -o hello  //作用：把可重载的文件或者库文件链接，生成可以执行代码;可执行文件运行：./hello
*.c->.o->->->.elf
相关参数：-E;-Wall警告；
例:gcc hello.c -o hello;//-o：指定生成后面的文件（不可变）
***
库文件（动：运行时加载；静：编译时就叫进去->用四方图描述有缺点）

###### 修复软连接丢失
“arm-linux-objcopy: Command not found”，原因在于这个工具的软链接没有新建，解决办法：
在对应的交叉编译器目录当中新建该工具的软链接。

gec@ubuntu:/mnt/hgfs/share/led1$ which arm-linux-gcc
/usr/local/arm/bin/arm-linux-gcc

gec@ubuntu:/usr/local/arm/bin$ sudo ln -s arm-none-linux-gnueabi-objcopy arm-linux-objcopy

#####2.gdb调试
编译时要加上-g选项，生成的可执行文件才能用gdb进行源码级调试
gcc -g main.c -o main //退出GDB：quit或者Ctrl+d
①可以直接按下回车再次执行最近执行过的那条命令；
②分屏显示源代码：gdb -tui；generate-core-file
③bt显示栈信息 ；无法产生core:ulimit -a    自动生成core文件:ulimit -c unlimited
例子
1. 安装好gdb，然后使用命令 'gdb'。（假设需要调试的进程号为 21509）
2. 使用 ‘attach 21590’命令将gdb附加到进程21509上。
3. 使用‘gcore core_name’命令生成coredump文件core_name。
4. 使用‘detach’命令断开连接；使用‘q’命令退出gdb。

#####3.等级优化(主要-O0和-O2)
意义和区别:影响代码(看反汇编代码)
例:测试delay函数。
	void delay(void)
	{
		int i=0x100000;
		while(i--);
	}

#####4.静动态库的生成与使用
1，静态库生成：
	将需要生成的.c文件生成.o文件
		gcc -c *.c
	结合所有.o文件生成需要生成的静态库文件
		ar -r libprint.a(库名) *.o

2，动态库的生成：
	将需要生成的.c文件生成PIC格式的.o文件
		gcc -fPIC -c *.c

	结合所有的.o文件生成动态库
		使用链接器：
			ld *.o -Bshare -o libprint.so

		也可以直接使用
			gcc *.o -shared -o libprint.so 


3，库的使用(需要分开编译，注意源文件注释)
	库的名字要求：
		必须以lib开头，.so（动态库）或者.a（静态库）作为结尾
		libprint.so	动态库
		libprint.a	静态库

	动态库编译
		gcc C文件 -o 程序名字 -L 库的路径(/lib/) -l 库的名字（去掉lib及.so所剩下的内容）
			注意：
				此条编译命令会优先寻找动态库，如果找不到动态库则用静态库编译，如果都找不到就报错了

	静态库编译
		gcc C文件 -static -o 程序名字 -L 库的路径 -l 库的名字（去掉lib及.so所剩下的内容）
			注意：
				这里是将所有的库文件都使用静态编译

4.如何同时编译多个库，反编译 object

![9.jpg](http://upload-images.jianshu.io/upload_images/2636843-a83938a36061f6b3.jpg?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

#### 接上 网络配置大全
配置流程：
1.配置IP、子网掩码和网关（sudo vim /etc/network/interfaces）
auto lo
iface lo inet loopback

auto eth0 
iface eth0 inet static（dhcp）
address 192.168.1.191
gateway 192.168.1.1
netmask 255.255.255.0

2.DNS 设置文件(sudo vim /etc/resolv.conf文件重启不影响)
# Dynamic resolv.conf(5) file for glibc resolver(3) generated by resolvconf(8)
#     DO NOT EDIT THIS FILE BY HAND -- YOUR CHANGES WILL BE OVERWRITTEN
nameserver 202.96.134.33

*   /etc/resolvconf/resolv.conf.d/base(文件重启不影响)

*       domain localdomain
*	search localdomain
*	nameserver 202.96.134.33  (128.86)
*	nameserver 202.96.128.68
*	nameserver 8.8.8.8 
 
*	rolvconf -u

3.重新加载网络配置信息：sudo /etc/init.d/networking force-reload

*	sudo service networking restart
4.重新启动网络服务：sudo /etc/init.d/networking restart
5.如果还不行，手工添加你的默认网关地址：sudo route add default gw 192.168.1.1，然后重复第3/4步。
6.如果还不行，那么可以考虑更换一个虚拟网卡。

![image.png](https://upload-images.jianshu.io/upload_images/2636843-17ca32ee0f81f5a9.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
