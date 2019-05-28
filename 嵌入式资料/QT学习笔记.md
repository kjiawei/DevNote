designer拖放设计生成QT界面代码
①用qt style sheet设计新的界面(不通过UIC):定好尺寸 按照代码基础里的变量命名标准 
1.把UIC.exe和你要转换的xxx.ui文件拷贝到同一目录。 
开始菜单，运行CMD 
进入uic.exe和xxx.ui的目录，运行以下命令： 
uic xxx.ui -o xxx.h 生成.h文件
2.有了这个ui_***.h文件就足够了.里面已经包含了所有的布局信息.要用这个布局文件.你就要新建另一个 ***.h和***.cpp.然后在 ***.h中添加 ui_***.h.并利用ui_***.h 定义一个变量叫ui.在***.cpp中.使用 ui->setupUI();这就完成了添加布局信息的过程了.要注意的是[新建]的类必须和ui中的基础类一致. 比如ui中的布局基于QDialog 你就不可以一个继承于QMainWindow的类来添加ui中的布局信息
使用总结和注意:如使用的是VS开发工具，需要添QtUiToolsd.lib/QtUiTools.lib 库;若使用的.pro文件生成，需要在.pro文件中需要加上SOURCES +=uiloader.cpp;
这样生成的窗口中 ， 要想访问窗口的界面元素 （就是窗口中的子窗口部件） ，就要通过一下手段

QComboBox *  primaryColumnCombo  =   dlg->findChild<QComboBox *>( "primaryColumnCombox");
if(primaryColumnCombo == NULL){
　　//..........................错误处理....................
}
但是在  VC6  中 ， 由于受编译器的限制 ，QObject::findChild<T>   这个函数不能使用   ,   为了解决这个问题

可以调用   qFindChild <T>  这个全局函数  ，  用法和  QOBject::findChild<T>  相同

(Qt5 的文档中找不到 qFindChild 这个函数  只能找到一个  qFindChildren  函数  可以尝试用这个函数替换)

 Designer: An error has occurred while reading the UI file at line 1, column
解决办法：将.ui文件拷贝到debug目录下

注意 ：  在编译程序前   在 *.pro  文件中 加入   CONFIG += uitools   这一句
这是因为 QUiLoader 是放在Qt的一个独立库中的 ， 要是用这个库就要加上这一句
但是 在  Qt5 中 ，  已经不赞成   添加  CONFIG += uitools 了
推荐的做法是  添加  Qt   +=  uitools
②在原来基础上添加界面代码
总结:法①使用优劣:快速 方便 适合大工程;设计使用前必须知道目标平台的屏幕尺寸和明确位置，后期变量修改麻烦-必须牢牢统一

### 快捷键
QT Creator格式化代码:CTRL + I

## 大型项目复杂度管理
守护进程，达到常驻内存
1.qt 信号与槽原理:
PyQt5教程(详细):http://www.xdbcb8.com/archives/764.html
时间处理:https://blog.csdn.net/liang19890820/article/details/52387275
QT源码分析
参考网友分析 https://blog.csdn.net/liuqz2009/article/details/6978113
C++相关知识点
前向声明 [<u>https://www.cnblogs.com/baochun968/archive/2012/05/03/2480137.html</u>](https://www.cnblogs.com/baochun968/archive/2012/05/03/2480137.html)
进程线程:https://blog.csdn.net/an505479313/article/details/48494901
https://blog.csdn.net/olinxi1234567/article/details/25558837
QT源码分析
网友学习之路:https://www.devbean.net/2012/08/qt-study-road-2-intro/
1.程序的构造顺序：

QObjectData->QObjectPrivate->QCoreApplicationPrivate->QApplicationPrivate->QObjectPrivate->QObject->QCoreApplication->QApplication
[参考网友分析 https://blog.csdn.net/liuqz2009/article/details/6978113

C++相关知识点

前向声明 [https://www.cnblogs.com/baochun968/archive/2012/05/03/2480137.html](https://www.cnblogs.com/baochun968/archive/2012/05/03/2480137.html)

QT源码分析

1.程序的构造顺序：

QObjectData->QObjectPrivate->QCoreApplicationPrivate->QApplicationPrivate->QObjectPrivate->QObject->QCoreApplication->QApplication
]

qmake：根据实际环境创建项目文件.pro   并且运行qmake生成适当的Makefile
构建：构建是增量编译，只编译有变化部分
重新构建：是把所有部分都重新编译
运行: 有改动则根据已有的Makefile进行编译，执行构建和重新构建时如果没有Makefile，会根据.pro文件等生成Makefile后再编译

所以运行顺序应该是：qmake-构建-运行

QT信号说明:https://blog.csdn.net/prike/article/details/73649331

Qt中对文件的拷贝删除重命名等操作：https://blog.csdn.net/qq_37233607/article/details/78905824
获取文件名:backupFile.right(backupFile.size()-backupFile.lastIndexOf("/")-1)

QT结合gdb远程调试:https://blog.csdn.net/u014213012/article/details/76719095 

[QTableWidget的用法总结](https://www.cnblogs.com/findumars/p/5553367.html)
Qt事件机制https://blog.csdn.net/yansmile1/article/details/52289166

PyQt Eric6安装配置教
程:https://www.cnblogs.com/archisama/p/5454762.html
cxfreeze打包教程:https://www.jianshu.com/p/e47d9be6fa96
PyQt5 Pyinstaller打包:https://blog.csdn.net/damnivictory/article/details/73527160 打包可以但是运行出错[可能是谷歌浏览器驱动,打包命令pyinstaller --hidden-import=pkg_resources -F -w --paths=C:\Users\keji01\AppData\Local\Programs\Python\Python36-32\Lib\site-packages\PyQt5\Qt\bin --paths=C:\Users\keji01\AppData\Local\Programs\Python\Python36-32\Lib\site-packages\PyQt5\Qt\plugins login.py]
[cxfreeze login.py --target-dir="E:\python\PyQt\music_download" --target-name="music.exe"]
打包命令（pyinstaller.exe --hidden-import=queue -F -w D:\Projects\environment\eric_workspace\6068pc_controller\main.py）
图文配置教程:https://blog.csdn.net/weixin_41656968/article/details/80253012
使用教程:https://www.cnblogs.com/hhh5460/p/4232086.html
汉化教程:https://jingyan.baidu.com/article/08b6a591adcd9314a9092244.html
后台处理线程:线程:http://blog.chinaunix.net/uid-23500957-id-3875253.html

### QT API：http://www.kuqin.com/qtdocument/qtimer.html#start
### UI
QPaint使用:https://www.cnblogs.com/lifexy/p/9203929.html
QTableWidget详细使用:https://blog.csdn.net/u010780613/article/details/50442639/
将整型转换为字符串类型有两种方法：
1.QString QString::number ( long n, int base = 10 )   [static]
long a = 10;
QString s = QString::number(a, 10);             // s = "10"
QString t = QString::number(a, 16).toUpper();     // t = "A"
2.QString s = QString("%1").arg(a);           //也就是上面提到的方法

6.14 no such slot但能编译通过
解决:子类同样加上Q_OBJECT宏
![执行一下QMake即可解决问题.png](https://upload-images.jianshu.io/upload_images/2636843-0c8c4b035b112644.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


win10下搭建QT开发环境 https://blog.csdn.net/lell3538/article/details/52463744
http://blog.sina.com.cn/s/blog_8f9cdbbd01017gun.html
Bash搭建qt开发环境:https://blog.csdn.net/westlor/article/details/52252408
qml教程 https://blog.csdn.net/cloud_castle/article/details/28412867

10.12整理
<h2>编译套件</h2>
包含：qt creator：SDK：
qt项目在平台间差异:编译工具链
qt源码与qt sdk和qt creator之间差异:项目源码需要更改 creator可以包含不同版本的SDK</br>
<h3>QT编译的可行参数</h3>
./configure -prefix /usr/local/Qt4.8.5 -opensource -embedded arm -xplatform qws/linux-arm-gnueabi-g++ -no-webkit -qt-libtiff -qt-libmng  -qt-libjpeg -qt-libpng -no-qt3support -nomake demos -nomake docs -nomake examples -little-endian -host-little-endian -qt-mouse-tslib -I/usr/local/tslib/include -L/usr/local/tslib/lib -fast -lrt</br>

ts库安装后需要将lib目录下的文件拷贝到usr/lib/：sudo cp -a libts* /usr/lib/

(出错 ../../include/QtCore/../../src/corelib/arch/qatomic_armv5.h:232:35: error: output number 1 not directly addressable
../../include/QtCore/../../src/corelib/arch/qatomic_armv5.h: In member function 'void QMutexPrivate::wakeUp()':
../../include/QtCore/../../src/corelib/arch/qatomic_armv5.h:232:35: error: output number 1 not directly addressable
make[1]: *** [.obj/release-shared-emb-arm/qmutex_unix.o] Error 1
make[1]: *** Waiting for unfinished jobs....
make[1]: Leaving directory `/mnt/hgfs/Share/qt/qt-everywhere-opensource-src-4.8.0/src/corelib'
make: *** [sub-corelib-make_default-ordered] Error 2)
<h2>qmake</h2>
<h2>翻译与QT语言家</h2>
1.打开已有的ts文件,添加需要翻译内容</br>
2.更新和发布   </br> 问题:type="obsolate"与"unfinished"区别-有些加location有什么作用

<h2>action与事件机制</h2>
<h2>Qt的容器类</h2>
1.使用ListWidget时，最好用Model/View方法而不是项的基本方法。</br>
<h2>非图形化Qt类：QFile、QPixmap、QSettings</h2>
所有的Qt数据都使用了隐含共享。
最普遍的Qt编程错误(坑)
为程序提供图标，并用Doxygen把你的代码整理成文档

<h2>最佳实践</h2>
1.编程时：在堆上用new创建QObjects并为他指定父类;不要对QObject或它的子类使用多继承。（qt不支持）;QDialog()::exec() 模态 和QWidget()::show()需要设置setModel（true）才是模态</br>
2.在编写一个自定义的Widget时，要确保它没有被创建过;最好使程序的位置和项的布局一致;当使用Qt-Designer创建Library时,最好在构造函数里用setupUi(),而不是继承</br>
3.判定你的GUI类如何拥有与事件相关的接口;最好使用QString而不是char*，并且对所有的字符串都使用tr()。</br>

---------------
4到5需要修改什么文件
http://wiki.qt.io/Transition_from_Qt_4.x_to_Qt5
QtWidgets作为一个独立的模块
例如编译时错误
error: QMainWindow: No such file or directory
error : QToolButton : No such file or directory
error : QWidget: No such file or directory
解决办法：
在*.pro文件里添加：
QT += widgets
更改
#include <QtGui>
为
#include <QtWidgets>
程序现在应该就可以运行了，但是有时可能需要更加明确的包含
#include <QtWidgets/QToolButton>

QtWebKitWidgets也是一个独立的模块：
例如编译时错误
error: invalid use of incomplete type 'class QWebFrame'
error : forward declaration of 'class QWebFrame'
解决办法：
在*.pro文件里添加：
QT += webkitwidgets
注意：当有QT += webkitwidgets的时候，就不再需要QT += widgets
此外，更改
#inclue <QtWebKit>
为
#include <QtWebKitWidgets>

打印机不工作
如果你的代码有以下几行：
#include <QPrinter>
#include <QPrintDialog>
将以下内容添加到项目文件中：
Qt += printsupport
同样，有时可能仍无法正常工作，需要指定：
#include <QtPrintSupport/ QPrinter >
#include <QtPrintSupport/ QPrintDialog>

toAscii()和fromAscii()已被弃用
替换
fromAscii()
toAscii()
为
fromLatin1()
toLatin1()
例如，给定的Qt4代码
QByteArry configfileti = TMP_Config. toAscii() ;
变为
QByteArry configfileti = TMP_Config. toLatin1() ;

QCoreApplication::UnicodeUTF8已被弃用
此枚举类型用于定义8位编码的字符串参数translate()。此枚举现在已经过时，所有的情况将使用UTF-8。所以删除了QCoreApplication::UnicodeUTF8的所有实例。例如：
Href_Gui -> setWindowTitle ( QApplication :: translate ( "Href_Gui" , "Url / www" , 0 , QApplication :: UnicodeUTF8 ) ) ;
label -> setText ( QApplication :: translate ( "Href_Gui" , "Text:" , 0 , QApplication :: UnicodeUTF8 ) ) ;
label_2 -> setText ( QApplication :: translate ( "Href_Gui" , "Url:" , 0 , QApplication :: UnicodeUTF8 ) ) ;
label_3 -> setText ( QApplication :: translate ( "Href_Gui" , "Target / Name:" , 0 , QApplication :: UnicodeUTF8 ) ) ;
变为
Href_Gui -> setWindowTitle ( QApplication :: translate ( "Href_Gui" , "Url / www" , 0 ) ) ;
label -> setText ( QApplication :: translate ( "Href_Gui" , "Text:" , 0 ) ) ;
label_2 -> setText ( QApplication :: translate ( "Href_Gui" , "Url:" , 0 ) ) ;
label_3 -> setText ( QApplication :: translate ( "Href_Gui" , "Target / Name:" , 0 ) ) ;

QWorkspace已被弃用
这个类已经过时，在Qt4.3中被替换为QMdiArea。在Qt5中QWorkspace已被删除。新的类与QWorkspace有类似的API，移植只涉及改变几个方法、信号和槽的名字。
更换
#include <QWorkspace>
为
＃include <QMdiAre>

QDrag问题
拖动功能的应用程序将需要一些调整。如：
QDrag *drag = new QDrag(event->widget());
在Qt5中将产生错误
error : no matching function for call to 'QDrag::QDrag(QWidget*)'
要解决这个附加组件，其中包括：
#include <QWidget>

qFindChildren已被弃用
这种方式会弹出一个错误：
error : 'qFindChildren' was not declared in this scope
为了解决这个问题，将qFindChildren替换为findChildren,例如
toString ( const QObject * obj , int indentLevel ) const {
[... ]

if (m_children ) {
QList <</span>QObject*> childlist = qFindChildren<</span>QObject*>(obj, QString());
[... ]
替换
QList <</span>QObject*> childlist = qFindChildren<</span>QObject*>(obj, QString());
为
QList <</span>QObject*> childlist = obj->findChildren<</span>QObject*>(QString());


qVariantValue已被弃用
编译器会出现
error : 'qVariantValue' was not declared in this scope
此功能相当于的QVariant::value(value)。因此，如果指定QVariant val应改写
QTime t = qVariantValue <</span>QTime>(val);
为
QTime t = val. value <</span>QTime>();
QTime用尖括号括起来，则告知编译器QVariant将返回。但是，如果变量不是一个QVariable，则类型用尖括号括起来就不应该被使用（这样做将导致一个模糊的编译时错误）。所以指定的m_color（QColor类型），应改写
s. setValue ( "color/favorite" , qVariantValue <</span>QColor>(m_color));
为
s. setValue ( "color/favorite" , m_color. value ( ) ) ;


qVariantCanConvert已被弃用
替换
Q_ASSERT (qVariantCanConvert <</span>QString>(variant));
Q_ASSERT (qVariantCanConvert <</span>QSize>(variant));
Q_ASSERT (qVariantCanConvert <</span>QFont>(fontVariant));
为
Q_ASSERT (variant. canConvert ( QMetaType :: QString ) ) ;
Q_ASSERT (variant. canConvert ( QMetaType :: QSize ) ) ;
Q_ASSERT (fontVariant. canConvert ( QMetaType :: QFont ) ) ;

Qt::escape已被弃用
error : 'escape' is not a member of 'Qt'
所以应该更改下面代码:
if (result == QString ( ) )
result = Qt :: escape (val. toString ( ) ) ;
else
result = Qt :: escape (result ) ;
return result ;
为
if (result == QString ( ) )
result = QString (val. toString ( ) ). toHtmlEscaped ( ) ;
else
result = QString (result ). toHtmlEscaped ( ) ;
return result ;

QDesktopServices::storageLocation已被弃用
error : 'storageLocation' is not a member of 'QDesktopServices'
error : 'DataLocation' is not a member of 'QDesktopServices'
使用QStandardPaths::StandardLocation，替换
QString path = s. value ( "db.path" , QDesktopServices :: storageLocation ( QDesktopServices :: DataLocation ) ). toString ( ) ;
为
QString path = s. value ( "db.path" ,QStandardPaths :: standardLocations (QStandardPaths :: DataLocation ) ). toString ( ) ;


QtMutimedia替换了Phonon音频、视频已不再使用 phonon， 如果你还在研究phonon，那么你已经out了！好好研究一下 QMediaPlayer、QMediaMetaData ...吧！
CONFIG += qtestlib已被弃用
如果在项目文件中使用，则编译器会发出警告，尽管如此代码将照常运行：
Project WARNING : CONFIG +=qtestlib is deprecated. Use QT +=testlib instead.

QWeakPointer怪异
如下代码
quint64 decodedPointer = line. toULongLong ( ) ;
MetaData *md = reinterpret_cast <</span>MetaData*>(decodedPointer);
QWeakPointer <</span>MetaData> wp(md);
结果
error : no matching function for call to 'QWeakPointer::QWeakPointer(MetaData*&)'
为了解决这个问题，将下面代码添加到项目文件：
DEFINES += QT_DISABLE_DEPRECATED_BEFORE = 0


QtConcurrent库的失踪了？
C:\Qt\Qt5.0.2\5.0.2\mingw47_32\include\QtConcurrent\qtconcurrentthreadengine.h:133: error: undefined reference to `_imp___ZN12QtConcurrent16ThreadEngineBaseD2Ev'
在Qt4中，QtConcurrent是QtCore的一部分，所以，没有必要包括特定的头。这已不再是用Qt5的情况下。如果源代码如下
m_current = QtConcurrent :: blockingMappedReduced (slices , functor , stitchReduce ,QtConcurrent :: UnorderedReduce ) ;
则将需要包含头：
#include <QtConcurrent/ QtConcurrent >
到项目文件，并添加下面一行：
LIBS += - lQt5Concurrent

固定的＃include <>头
在qtbase/bin/中存在一个“fixqt4headers.pl”这样的Perl脚本。运行于Qt源代码运行，为Qt组件纠正#include <>指令还要考虑模块名称。
------------------------------

Linux下安装
到http://qt-project.org/downloads这里下载东东,我的是ubuntu 10.04,下载了这两个:
Qt libraries 4.8.4 for Linux/X11 (225 MB)    -->库
Qt Creator 2.6.0 for Linux/X11 32-bit (63 MB) -->IDE

1.库下载下来以后是qt-everywhere-opensource-src-4.8.4.tar.gz，解压一下，到其目录下，执行configure脚本，等执行完了，再执行make，这是一个耗时很长的过程，耐心等待完了以后再执行make install,它会在/usr/local/Trolltech目录下安装好文件...
之后的qt-everywhere-opensource-src-4.8.4源文件就可以删除了(我是删除掉的发现没影响，给个指点呗，还有什么用？)

2.安装IDE,执行qt-creator-linux-x86-opensource-2.6.0.bin，此文件需要加上X可执行权限方可执行，执行完了以后IDE就安装好了，这步最简单。

运行Qt creator,创建新项目，会让你配置Kit,在"Qt version"一栏，点击右边的"manager"，选择qmake路径为:/usr/local/Trolltech/Qt-4.8.4/bin/qmake,就好了。

下面就可以创建一个Qt Gui application写一个Hello world了
-------------------------------
QT在各平台下区别
1.菜单栏，Windows是附在程序窗口里，Mac是附在显示屏的顶层位置；
2.Mac中和触摸板相关的，Windows没有，如果需要做Mac优化，这块需要单独开发；
3.Quick开发的程序，Mac下效果很好，Linux也很好，貌似在我开发过的平台里，就Windows效果不好,动画跑起来还偏快（也许是我的错觉？），这个需要注意一下。Widgets的程序无明显差别；
4.发布程序，修改程序图标方法不一样，这个应该不是问题（ps：发布程序Mac下会方便很多）；
5.widgets+R屏时，绘制图片等元素时默认不是R屏的，很难看，要设置一下（代码上，iOS也是这样

9.1记录
问题:如何跨平台(看书 开发web应用 混合)  quick项目创建步骤 看个比较完善的案例代码和指导书籍

1.需要接触到一些平台相关的东西，比如文字符编码等---尽可能使用 Qt 提供的标准函数进行编程，这

样就不必写一大堆 if 判断  [条件编译方案]
#if defined(Q_OS_WIN32)  
        QTextCodec* gbkCodec = QTextCodec::codecForName("GBK");  
        QString result = gbkCodec->toUnicode(p->readAll());  
#elif defined(Q_OS_LINUX)  
        QTextCodec* utfCodec = QTextCodec::codecForName("UTF-8");  
        QString result = utfCodec->toUnicode(p->readAll());  
#endif

  
接手QT项目
1.熟悉原项目的需求和版本特点
2.转移到新版本的难点与必要性
3.交叉开发(新旧版本应对方案 跨平台与个人项目的择中)

1.看英文文档  进度:《快速入门》看到事件
http://www.cnblogs.com/findumars/p/5529526.html
### 零 QT版本与最新特性
qtcreator:三种平台的集成开发环境(win:qt-creator-opensource-windows-x86-4.2.1.exe)
源码包(qt-everywhere-opensource-src-5.5.0)    qt-opensource-linux-x86-5.5.0.run(下载地址 http://download.qt.io/archive/qt/5.5/5.5.0/)
qt与creator版本 https://zhidao.baidu.com/question/392155567.html
#### 信号槽机制与回调函数
1.回调是一个指向函数的指针，所以如果你希望一个处理函数通知你某些事件发生了，你可以传递一个指向其他函数的指针（回调）给它;缺点:不是类型安全，我们永远都不能确定调用者是否将通过正确的参数来调用“回调函数”；第二，回调函数与处理函数是紧耦合（strongly coupled）的，因为调用者必须知道应该在什么时候调用哪个回调函数
2.一个特定的事件发生时，信号会被发送出去  ,槽，则是对一个特定的信号进行的反馈,一个信号的参数必须和接收槽的参数匹配[参数匹配机制,槽参数可比信号参数短],松耦合（loosely coupled）的：一个发出信号的类既不知道也不关心哪一个槽接收到这个信号;Qt的信号和槽机制保证了如果你将一个信号连接到一个槽上，槽会在正确的时间以号的参数被调用。信号与槽可以携带任意个、任意类型的参数。他们是完全的类型安全。
3.QT信号与槽机制内部实现:消息队列
4.槽函数和普通函数区别:所有从QObject或者它的一个子类（比如：QWidget）继承的类都可以使用号与槽。对象中以这种方式通信：一个对象的状态发生了改变并发送信号，关心这个改变的另一对像接收到这个信号。发送信号的对象并不知道也不感兴趣什么对象接收它所发出的信号，这是真正的信息封装，保证了对象能被当作软件组件来使用。
槽能被用来接收信号，除此之外它们也是普通的成员函数。槽不知道是否有信号与它连接起来，正如对象不知道它发出信号是否会被接收一样。这样的机制确保了可以使用Qt创建一个个完全独立的组件。槽其实就是普通的C++函数,并且可以像普通函数一样调用.它们唯一的特点就是可以与信号相连。
### 一 使用问题与开发注意事项
![图片(资源)添加.png](http://upload-images.jianshu.io/upload_images/2636843-9155b3deb7b9a5f2.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

0.进程"C:\Qt\Qt5.5.0\5.5\mingw492_32\bin\qmake.exe"退出，退出代码 2  原因:路径有中文;

1.system tray icon在unity里显示位置不正常;
用explicit可以抑制隐式转换-编译时如有发现会报错;
2.QT5的版本，有C2001报错，可以通过设置UTF-8 BOM为“如果编码是UTF-8则添加”来解决;

3.RtlWerpReportException failed with status code :-1073741823. Will try to launch the process directly  指针段错误;

4.qml用以Android等开发;

5.QT错误：collect2:ld returned 1 exit status

5.1.编译成功的例子在后台执行，有时一闪而过，如果再次build ，则会提示上述错误。
解决方法：打开任务管理器，找到相应的exe进程，关闭即可；  或者直接关闭QtCreator。

5.2.没有编译成功的情况下，最常见情况是程序本身需要include的头文件被遗漏了
解决方法：细心查找基类所用的头文件，include之后即可。

5.3.  .h文件中相关的槽函数在cpp文件中没有定义
解决方法：查找遗漏的槽函数，根据需要，具体的定义。

5.4 Qt错误：Error - RtlWerpReportException failed with status code :-1073741823. Will try to launch the process directly
RtlWerpReportException failed with status code :-1073741823. Will try to launch the process directly
我是在做图像处理的时候出现这个错误的，原因是没有图的初始数据。个人觉得出现这个错误多半是因为某个变量没有进行初始化，引用不明确造成的。

5.5 Qt错误:Starting D:\e\qt\13-4-19-picture\picture-build-desktop\debug\picture.exe...
D:\e\qt\13-4-19-picture\picture-build-desktop\debug\picture.exe exited with code -1073741571
在用qt进行图像开发的时候，出现了这种问题。经过网上查阅资料，发现这个错误是由于：栈溢出，系统默认的栈的空间大小是1MB。
解决方法是将需要申请栈内存的局部变量更改为其他类型的变量，以减少对栈的压力。下面推荐三种解决方法：
1、要分配的大量局部动态变量或数组，改成用new分配，不过一定要记得delete哦。
2、如果类的定义中有大数组，不要用该类定义局部变量，改成用new构造对象。
3、直接将大容量局部变量数组移到函数外，使其作为全局变量数组存在，不过全局变量要慎用。

5.6 Qt错误:Error -RtlWerpReportException failed with status code :-1073741823. Will try to launch the process directly
C:\Users\Administrator\Desktop\picture-build-desktop\debug\picture.exe 退出， 代码: -1073741819 
这个问题可困扰了我整整一天，通过单步调试也没看出来程序有什么错误，貌似该获取的值都取到了，逻辑上也完全正确。后来还请教了工作室的大神，折腾了很久才发现，又是内存管理的问题，程序里面申请的堆区的空间太多，把用new申请的空间转变为申请栈区的局部变量，问题就得到解决了。不过说实话对于堆、栈它们各自到底占用多少内存，怎样的分配才算合理，怎样避免这方面的问题，自己目前还是不清楚。

5.7 Invalid parameter passed to C runtime function.
5.8qt.network.ssl: QSslSocket: cannot resolve TLSv1_1_client_method
5.9 Qt5Cored.dll丢失
6.0
FTH: (7156): *** Fault tolerant heap shim applied to current process. This is usually due to previous crashes. ***的问题，清除掉所有的文件，重新qmake和构建都不能解决这个问题。
有人说修改注册表中HKEY_LOCAL_MACHINE\Software\Microsoft\FTH\Enabled的值为0，然而并没有什么用处。无意在stack overflow中找到了解决办法，原链接为http://stackoverflow.com/questions/5020418/how-do-i-turn-off-the-fault-tolerant-heap 。
在注册表中删除 Software\Microsoft\Windows  NT\CurrentVersion\AppCompatFlags\Layers\your_application.exe，再次运行程序就不会报这个错误了。
总结
KDE 整个是用他开发，证明了他的稳定性和强大功能。缺点是如果你用他开发非 GPL 开放程序代码的软件，必须以极昂贵的金额，购买商业版本。 而他的图形接口并不完全是 "Native GUI"，只是透过 theme 去仿真系统上的标准 GUI，所以看起来很像，却会有些地方可以明显看出破绽。 执行速度缓慢还有过于庞大则是另一个问题。 虽然封装得很良好文件也齐全，并不代表他就很容易学,还有一个严重问题是，他写的不是标准 C++，他使用的 signal/slot 机制必须透过 Qt提供的 preprocessor 处理过才可以转送给编译器，这部份可能被限定用 qmake，算是一个可惜的地方，不过瑕不掩瑜，还是很推荐。忘了说，他内部也是unicode，多国语言没问题
6.1.no such file 
QApplication  QInput 
解决:greaterThan(QT_MAJOR_VERSION,4):QT += widgets   //.pro文件
6.2../version.sh:-1: error: line 8: svn: command not found
![无法编译运行.png](http://upload-images.jianshu.io/upload_images/2636843-3255ffb6b73e4052.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
解决:手工创建目录
6.3.权限不够或路径错误-选错编译链

### 二 网络编程
![qt网络编程tcp通信步骤.png](http://upload-images.jianshu.io/upload_images/2636843-ace4589a6c4ee220.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

### 三 优化布局管理&UI设计
宏函数同一样式风格
#define SCENE_KTV_UNIT(p,x,y)            \
        do {                                    \
            (p).setGeometry(QRect(x,       \
                        SCENE_KTV_LABEL_Y_##y,                \
                        SCENE_SETUP_COL_WIDTH_UNIT,         \
                        SCENE_SETUP_WIDGET_HIGH));          \
            (p).setAlignment( Qt::AlignVCenter | Qt::AlignLeft); \
            (p).setFont(QFont(QString(CONFIG_FONT_STYLE),     \
                        CFG_FONT_SIZE_THIRD, CONFIG_FONT_NORMAL)); \
            (p).setStyleSheet(CONFIG_COLOR_LABEL);    \
        } while(0)

控件学习笔记
以开发笔记应用(MAC下也可以用)UI目的学习QT控件
1.设计UI初稿

知识点与问题:
0.布局管理 不同布局使用相同函数参数个数也不同
1.底层是如果实现的(继承关系 用了什么机制)  
2.自定义控件(如何扩展)
3.在特定平台下坑->比较好的解决方案
4.搞清楚QT 控件的区别(WithButton和withoutButton有什么区别)
5.QDialog QWidget QMainWindow区别与联系
QWidget所有窗口部件基类
QDialog各种对话框基类
QMainWindow带菜单栏和工具栏主窗口类

窗口是没有父部件的部件
如果是顶级对话框，那就基于QDialog创建，如果是主窗体，那就基于QMainWindow，如果不确定，或者有可能作为顶级窗体，或有可能嵌入到其他窗体中，则基于QWidget创建。当然了，实际中，你还可以基于任何其他部件类来派生。看实际需求了，比如QFrame、QStackedWidget等等。

6.QVariant qtopia是什么
7.包含尽可能少的头文件
8.qt quick http://www.cnblogs.com/senior-engineer/p/5576684.html
http://www.cnblogs.com/csulennon/p/4483711.html

------------功能收集--------------
自动补全QComplete
----------------------------------

方法：
经常使用(常用的要自然地使用出来)
回忆以前学Android Html控件的经历
看UI文档

掌握程度
1.能根据设计人员给出的文档用代码实现UI效果
2.调试法1 F5调试 F10单步跳过 F11单步退出
  调试法2 qDebug
3.理解底层函数实现原理->控件方面的(设计封装思路)

0.命令行编译  
0.1 command prompt下cd到项目目录下
0.2 qmake-project 命令生成makefile文件
0.3 make生成.exe程序(debug目录下)

1.开发流程与规范化
头文件管理:界面类 Qt自带类(按首字排列) <->布局 控件 所需功能
类定义:对象划分 界面 UI:按钮 标签 下拉框

*UI控件实现逻辑：类声明(头文件include private定义控件对象) 源文件实现:new新对象 setGeometry设置位置属性 其它属性设置 connect事件(SIGNAL SLOT) 用到的函数实现(QString重载方便使用   没有this重载 减法)

### 常见问题
如何做单元测试
中文乱码:解决方法
资源添加方法(图片)
子窗口退出整个程序
性能调试
槽和信号,速度相应问题,creator性能问题,debug和自动补全都慢

笔记应用项目
功能增加:打开保存的笔记文件-P55 文件浏览示例 -第5章 文件操作
读取笔记文件动效果-进度条
P85-94 图片移动效果
上传文件：tcp socket  多线程P165 
将制定的笔记文件发送到邮箱:SMTP发送邮件
笔记 用户密码加密P171
4.音乐播放器项目
多媒体框架Phonon QTableWidget做播放列表 QMap和正则表达式做LRC歌词解析
Qt qtableview 多行选中，获取行号

QList <int> GetRowId::requestRowId()
{
    QItemSelectionModel *selections =  ui->tableView_showExecuteInfo->selectionModel();
    QModelIndexList selected = selections->selectedIndexes();
    QMap <int, int> rowMap;
 
    foreach (QModelIndex index, selected)
    {
 
        rowMap.insert(index.row(), 0);
    }
////    qDebug() << "print : " <<rowMap;
////    qDebug() << "acount : " <<rowMap.count() ;
////    qDebug() <<"i = 0 : "<<rowMap.keys();
   return rowMap.keys();
}
