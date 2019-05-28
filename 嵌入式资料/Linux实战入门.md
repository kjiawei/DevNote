工作中用到的指令
修改文件权限sudo chmod 777 -R trunk/
killall -9 hemodialysis
umount -v /mnt/nfs/
挂载命令:mount -o nolock -t nfs 192.168.123.245:/work/nfs /mnt/nfs
拷贝:cp /mnt/nfs/hemodialysis/hemodialysis /usr/local/app/
cd /usr/local/app/
./hemodialysis -qws &

https://linux.cn/      软件安装目录：bin   卸载命令remove
http://man.linuxde.net/
美化 http://noogel.xyz/2017/06/17/1.html?nsukey=Qy4rBrkJQf5C7NfpCs789CZ2DEooJCGjyceW9rpv4z5NPwLKKXUFPxoaxSo32PxiHPkqXkhZWLO%2FH2SN%2BkKnnDjmHrAk%2BVyt%2BaoCof9b%2FEnbj1rnam5LxnGVWAEwP8pItuDkmtSoEdqTaHLZK%2BA0GMp%2FUWeaTpHaVDJmiWqpc%2BHuY4%2BtGwzbH%2B%2B9KN2ZjHrP
### 常用命令
0.linux查看所有修改文件的命令(去到CODE目录下)
find ./ -mtime 0：返回最近24小时内修改过的文件。
find ./ -mtime 1 ： 返回的是前48~24小时修改过的文件。而不是48小时以内修改过的文件
find ./ -mtime 0 -o -mtime 1 -o -mtime 2 ……返回10天内修改过的文件？find还可以支持表达式关系运算，所以可以把最近几天的数据一天天的加起来：


1.打包压缩  .tar只是将文件简单地打包,文件的大小没有变化,也就是说.tar文件只是一个包,没有被压缩
①tar cvf FileName.tar DirName(xvf是解包)
②gz:gzip -d FileName.gz(压缩gzip FileName.tar.gz[解压tar zxvf 后缀文件名,压缩tar zcvf 后缀目标文件名 DirName])
③bzip2 -d FileName.bz2(压缩bzip2 -z fileName)
④tar jxvf FileName.tar.bz2(压缩tar jcvf  FileName.tar.bz2  dirName)  开发板比较可行 感觉20M以下才可以
⑤rar a FileName.rar(压缩r ar e FileName.rar)
⑥unzip FileName.zip(压缩zip FileName.zip DirName)开发板不支持?

![Paste_Image.png](http://upload-images.jianshu.io/upload_images/2636843-7f06f56c36afaa14.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

2.文件搜索 find xxx|grep " "
find 查找文件命令：http://www.jb51.net/os/RedHat/1307.html
find -name madplay

3.编译器相关
查看交叉编译链路径which arm-linux-gcc
除法库-libgcc.a libgcc_eh.a
修改路径LIB 4.5.1

4.cp mv
移动当前目录下所有文件到指定文件夹:mv ./* /lib/
### 系统函数
![行缓存.png](http://upload-images.jianshu.io/upload_images/2636843-c10760f4c9527cb1.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
setvbuf修改缓存类型
![scanf行缓存，无缓存直接保存到buf.png](http://upload-images.jianshu.io/upload_images/2636843-cac0451aa5995aa6.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

5.快速查看
~：家目录（文件夹）
/：根目录
查看隐藏文件ls -al
查杀进程 kill -s 9 kid(-s 9 制定了传递给进程的信号是９，即强制、尽快终止进程)http://blog.csdn.net/andy572633/article/details/7211546

文件权限：
rwx：文件拥有者
rwx：文件拥有者所在组的其他成员
r-x：其他用户

查看文件属性 file hello.c
获取root权限 sudo -s 输入密码123456
关机 poweroff或shutdown -h now
