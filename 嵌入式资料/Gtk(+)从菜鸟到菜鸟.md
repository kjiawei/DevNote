####1.前情提要                                                    -----2017.3.26 半深夜 雨
***
#####发文原因：督促自己去学习，思考，交流，分享
#####为什么去研究这个东西？
同类μcgui qt
①gtk(+)是C下一个易用的图形库，优点：好用，缺点：函数名太长。（暂时发现）可以实现C下的UI；
②可能以后会用到，时间不是用来学习就是用来浪费；（这个有点假，哈哈）；
③好奇，为什么还会问这个问题，喜欢就去做！
④如果还有什么可以说的话，Gtk（+）->我所有的向往！（装逼好像都是用这个理由）
***
接下来第二篇可能会写到更多关于gtk(+)的坑，以及学习上面的一些方法和琐事，笔者一直相信：只有肯努力挖坑的人，才会不断填坑！
#####1.1环境搭建
  下面以Ubuntu12.04（终端输入以下命令）为例：
0.sudo -i #先切换到root用户，免去下面输入sudo（你懂的）
1.apt-get install build-essential #安装 基本编程工具（gcc/g++/gdb/make）
2.apt-get install gnome-core-devel #安装相关库文件（ libgtk2.0-dev libglib2.0-dev）
3.apt-get install pkg-config #编译GTK程序自动找出头文件及库文件位置
4.apt-get install devhelp #devhelp GTK文档查看程序
5.apt-get install libglib2.0-doc libgtk2.0-doc # gtk/glib 的API参考手册及文档
6.apt-get install glade libglade2-dev #glade是 GTK+ 图形用户界面产生器
7.apt-get install libgtk2.0*      #gtk+2.0所需文件都下载
***
下面问题来了
许多小伙伴可能最后输入应用程序编译命令：gcc -g yourcode.c -o yourcode \`pkg-config --cflags --libs gtk+-2.0\`会编译不通过,这是为啥子呢？
原因：安装没有完成！
解决办法：
1.更新软件源：将sources.list文件源改为163的，然后apt-get update;
163源的**sources.list**：<http://pan.baidu.com/s/1c2GdTJE>
会看是否安装成功的同学会发现失败的情况下会有类似apt-get -f install之类的命令，执行它，然后再输入安装命令，这时的返回结果与之前会有所区别，主要是少了错误信息，然后编译，就可以了！

2.再提一点
即使环境搭好，编译也通过，但是最后发现段错误了！！！（首先第一反应就是指针可能用错了）
Gtk（+）这些库本来就是封装一大堆的指针，结构体，所以比对代码的时候就要特别小心，推荐比对代码方法：带选中高亮文本编辑器选中正确函数名或变量名（一般都是这些部分打错代码），与官方例子进行比对（未添加自己逻辑代码前）；写代码测试原则：部分添加部分测试，增加的部分就测试。
#####1.2编译第一个例子
demo:<http://pan.baidu.com/s/1mibSafQ>
#####1.3渐进前行
学习进度：复选控件；
学习方法：看官方给的例子，然后自己试着修改部分样式，添加自己想要的逻辑；
之前研究这个是为了后期的项目（智能家居）以及对UI界面好奇（为什么C总是黑乎乎的一片~~扯多了），有了这个以后也可以往上层走。
#####1.4相关学习资料
https://developer.gnome.org/gtk-tutorial/stable/
http://blog.csdn.net/column/details/sjin-gtk.html
http://tieba.baidu.com/p/1928899283?see_lz=1
http://gtk.awaysoft.com/read-98-1.html
http://zetcode.com/gui/gtk2/
https://www.gtk.org/documentation.php
#####1.5学习技术心态
1.不要先入为主，有时候知道的少反而是件好事；
2.分清主次，有的放矢；
3.最少的代码反而最关键；
4.时刻保持清醒，放松心情，开拓思路。
***
欢迎转载，部分原创部分摘录，交流523090538@qq.com或直接评论！若看到会第一时间进行回复！
