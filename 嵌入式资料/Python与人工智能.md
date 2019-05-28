爬虫
1.urllib2安装失败
#图片(视频)爬虫需求
#输入自定义网址(网址结构不一致-通用模板)
#下载参数(内容大小判断 页数 目录设置,下载后操作[压缩 传输等],分辨率/清晰度调整)
防盗链(去掉refer):https://blog.csdn.net/tjcyjd/article/details/74643521

接口设计规范(参数校验 权限校验 数据操作 结果返回)
![@的用法.png](https://upload-images.jianshu.io/upload_images/2636843-d38a0ecc8f487cb2.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
1.try...except使用时要指定异常类型
2.(百度)Python内置函数eval()用法及其安全问题

代码格式化
autopep8 --in-place --aggressive --aggressive test_autopep8.py
变量命名要能看出单复数

1.问题记录
super(TcpSocket, self).__init__(parent) 什么含义(主要是语法上的此类问题)

代码格式化工具 yapf -i file.py 

推荐系统surprise  https://blog.csdn.net/mycafe_/article/details/79146764
selenium窗口操作参考:https://www.cnblogs.com/wulisz/p/7640468.html
深度学习:关键是懂得概念及模型算法的建立(通过大量的数据进行训练以获得较为准确的测试模型)
python格式化工具-notepad++ yapf教程 循环运行
爬虫的思路与问题归类:python中httplib.IncompleteRead exception  https://blog.csdn.net/haoli001/article/details/40863433
TensorFlow安装win10下:https://blog.csdn.net/caldera/article/details/78154862?locationNum=6&fps=1
汽车油耗python:https://blog.csdn.net/xiaoql520/article/details/78059723
深度学习在电商商品推荐当中的应用:https://blog.csdn.net/loveatm911/article/details/77931320
python进行aes加密的时候，只能加密数字和字母，不能对中文进行加密，会报错-解决方方法是在cbc加密的模式下，在对字符串补齐为长度为16的倍数时，长度指标不能用中文，要先把他转为unicode编码的长度才可以。
吴恩达教程文字版:https://www.cnblogs.com/wangxin37/category/1149080.html
CNN详细分析:https://blog.csdn.net/lyc_yongcai/article/details/73237090

Scikit-Learn中的机器学习模型非常丰富，包括SVM，决策树， GBDT，KNN等等，可以根据问题的类型选择合适的模型
Scikit-Learn的安装需要numpy，scipy，matplotlib等模块
微博聚类：
数据集(微博数据)
算法使用(scikit-learn中的kmeans)
期望结果(相似微博聚到同一类)
额外支持模块(jieba中文分词库)
案例流程：
一行行读入原始微博
读的同时进行分词并存入语料库
使用sklearn包中feature_extraction的方法计算出每条微博每个词 中的tf-idf值
将计算出的微博向量矩阵带入到算法中去聚类
将聚类结果和原始微博数据进行整合存入一个结果文件

音乐分类：
数据集(音乐数据)
算法使用(scikit learn中的logistic regression(逻辑回归))
期望结果(输入一首歌，可以对输入的歌曲进行分类)
额外支持模块(安装dateutil-->six-->pyparsing-->pytz-->matplotlib)
案例流程：
["classical", "jazz", "country", "pop", "rock", "metal"]
通过傅里叶变换将以上6类里面所有原始wav格式音乐文件转换为 特征,并取前1000个特征,存入文件以便后续训练使用
读入以上6类特征向量数据作为训练集
使用sklearn包中LogisticRegression的fit方法计算出分类模型
读入黑豹乐队歌曲”无地自容”并进行傅里叶变换同样取前1000维 作为特征向量
调用模型的predict方法对音乐进行分类,结果分为rock即摇滚类

BeautifulSoup select()/select_one() 用法
https://blog.csdn.net/ggwxk1990/article/details/78928630
爬虫（解析简单标签）
https://blog.csdn.net/qq_29721419/article/details/54428923
page_source 解析
https://www.cnblogs.com/yoyoketang/p/6512604.html
![image.png](https://upload-images.jianshu.io/upload_images/2636843-bea80f234f99ce15.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

## Python
GIL：http://python.jobbole.com/87743/
win10 py2与py3共存https://www.cnblogs.com/thunderLL/p/6643022.html
操作mysql数据库:https://www.cnblogs.com/fatcat132006/p/4081576.html
python3安装beautifulsoup全过程:https://blog.csdn.net/weixin_36926779/article/details/79209618

###包管理
同时装了Python3和Python2，怎么用pip
py -2 -m pip install XXXX

fastpy https://gitee.com/feimat/fastpy
LearnOpenCV学习——平均脸  https://blog.csdn.net/GraceDD/article/details/51382952

python(开发语言)学习方法
1.主要看它里面用了哪些函数，怎么用，以后就可以加到自己代码里去了
2.代码怎么写的，思路和规范

pyqt控件http://blog.csdn.net/neverstop_2009/article/details/47378779

anaconda安装：https://www.cnblogs.com/bbn0111/p/6972692.html
if __name__ == '__main__': 的解析:http://blog.konghy.cn/2017/04/24/python-entry-program/
py2exe教程 http://www.pythoner.com/111.html
python大量精选非官方插件包 https://www.lfd.uci.edu/~gohlke/pythonlibs/#py2exe

notePad++中设置快速运行python程序命令 
cmd /k C:\Users\Administrator\AppData\Local\Programs\Python\Python36\python.exe "$(FULL_CURRENT_PATH)" & PAUSE & EXIT
#os.getcwd() 执行python程序的目录

pyqt5中文教程 http://code.py40.com/pyqt5/16.html
pyqt designer http://blog.csdn.net/u011021024/article/details/53005973?locationNum=4&fps=1
pyqt5表格绘制 http://code.py40.com/2482.html
字符串处理 https://www.cnblogs.com/printN/p/6924077.html
Python序列化和反序列化   https://www.cnblogs.com/sun-haiyu/p/7087088.html

dlib库安装解决:http://blog.csdn.net/jhw_xf/article/details/53321272
人脸识别:http://tumumu.cn/2017/05/02/deep-learning-face/
1.pip install xxx：unable to create process using''''
解决方法:pip是python2的，需要加python -m在前面

2.dlib安装教程

学习资料汇总 http://blog.csdn.net/lina_acm/article/details/54581721
### Python
一 OOP
__get__和__getattr__和__getattribute__的区别   http://www.jb51.net/article/86749.htm
描述符类  https://www.cnblogs.com/jessonluo/p/4758662.html

二 高级特性
切片 http://blog.csdn.net/eocee/article/details/45847483

三 数据结构 算法(必须掌握)
列表排序

python搞opencv教程 http://www.jb51.net/article/67392.htm  
Python3 基础语法 http://www.runoob.com/python3/python3-basic-syntax.html
Python 编码规范(Google) http://www.runoob.com/w3cnote/google-python-styleguide.html
官网API https://docs.python.org/3/tutorial/stdlib.html#file-wildcards
### 类C的学习方法还是另辟蹊径
结合商业项目(C++复习 招聘要求 试题)学习
作为一门自学的语言，除了兴趣还要有科学的训练方法(面向需求问题有目标地攻破难点)【以解决问题为主-语音/手势识别 数据抓取】
①online python tutor ②the python challenge
③learn python programming@Codecademy
#### 1.Python都有哪些重点难点
  ①所涉及的各种领域所涉及的算法等比较难,比如使用python相关的库，去解析图像，则不是python的库的用法难，而是本身图像算法难
  ②版本与库的兼容 2与3版本的差别

#### 2.Python的学习路径
温工教学特点:先复习一下旧知识和今天讲解预告,讲理论然后验证
  2.1快速看教程-学着做小项目-解决问题方案
  2.2 2.7与3.6版本区别 IDLE如何使用
2.3 关键字等记住

![Paste_Image.png](http://upload-images.jianshu.io/upload_images/2636843-99b80175597281c9.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
#### 3.项目的选择
  3.1爬虫抓取网页，分析网页内容，模拟登陆网站的逻辑/流程和注意事项
  3.2如何利用工具(IE9的F12)去分析模拟登陆网站(百度首页)的内部逻辑过程
  3.3抓取网并提取网页中所需要的信息 之 Python版
  3.4模拟登陆网站 之 Python版（内含两种版本的完整的可运行的代码）
爬虫-防盗链
如果想对自己的网站进行防盗链保护，则需要针对不同的情况进行区别对待。如果网站服务器用的是apache，那么使用apache自带的Url Rewrite功能可以很轻松地防止各种盗链，其原理是检查refer，如果refer的信息来自其他网站则重定向到指定图片或网页上。

如果服务器使用的是IIS的话，则需要通过第三方插件来实现防盗链功能了，现在比较常用的一款产品叫做ISAPI_Rewrite，可以实现类似于apache的防盗链功能。另外对于论坛来说还可以使用“登录验证”的方法进行防盗链
  3.5手势语音识别

#### 5.常用的库 urllib等库，是和网络相关
wechat_sender (https://pypi.python.org/pypi/wechat-sender/0.1.3)是基于 [wxpy][1] 和 [tornado][2] 实现的一个可以将你的网站、爬虫、脚本等其他应用中各种消息 （日志、报警、运行结果等） 发给你的个人微信的工具

#### 6.学习笔记
6.25 Python环境设置
①主题，叫IDLE Dark，很好看，配上fixedsys字体
②怎么通过运行后的shell中的提示去修改编辑器中的代码，也知道怎么打开debuger模式

6.21 ①ImportError: No module named web  模块的导入需要叫做“路径搜索”的过程
②Non-ASCII character '\xe5' in file code.py on line 8   --># -*- coding: utf-8 -*-
③注意缩进

python中，每个py文件被称之为模块，每个具有__init__.py文件的目录被称为包；

*爬虫思路
1.得到目标地址；分析内容结构【要规范 div  id&class】(可能会需要登录 反盗抢；注意编码等异常)
2.提取需要部分；循环遍历
爬虫思考
做爬虫引出的工具:数据分析 绘图 网络访问攻防 文件IO
动静态网站分析[PhantomJS https://cuiqingcai.com/2577.html]

Pygame  http://eyehere.net/2011/python-pygame-novice-professional-index/

python思索之夜，心理忐忑不安，想到了写文章来平复内心的焦躁与不安。
1.python基础可以从django项目源码中积累(如果不想一步步去看的话)；
做喜欢的事情一直坚持下去，用宁静来通关；
2.不要把东西(电商项目想得那么难),都是工具,工具就是人开发出来给人用的;
3.面对诱惑坚守底线,没有是做不出来的东西,;
4.vscode不逃避问题,其实现在的你比很多人都牛逼;
5.真正的王者永远是下一秒的自己;
6.不要从众,定义潮流的是你,即时自己一闪而过却未留下的印象也是独一无二的;
7.经历就是一种财富-高考过来人-本来无何物-就算现在失败也没什么介意
                                                                                                -- 2017.11.15  不惧的分神夜

python常用 http://blog.chinaunix.net/uid-25508301-id-3352833.html
__init__ self  https://www.crifan.com/summary_the_meaning_of_self_and___init___in_python_and_why_need_them/
python打印类对象  https://www.cnblogs.com/zh1164/p/6031464.html
__getattr__为内置方法，当使用点号获取实例属性时，如果属性不存在就自动调用__getattr__方法
__setattr__当设置类实例属性时自动调用，如j.name=5 就会调用__setattr__方法  self.[name]=5
因为这个类是从dict继承来的，是dict的超类
所以 self[attr]=value 相当于调用dict的下标方法
与 a={}   ; a[attr]=value意思一样

如何学编程:可以先定个小项目，然后根据你知道的去分析要做哪些模块，然后找对应的知识来解决(如何实现这个功能),然后一步步整合自己学到的知识用上去就可以了

人性与意愿
到门前:门识别到主人是否主动开启(会有个小声音提示主人，主人需要简单但明确的指令进行通过-手势或语音交互)

人工智能-Python 精通年薪40万 小米智能电视 智能音响ECHO
算法 链接：http://pan.baidu.com/s/1nvHmcZJ 密码：fwjg
常用库 链接：http://pan.baidu.com/s/1o8uPvPg 密码：yp3w
进阶-高级代码 链接：http://pan.baidu.com/s/1cEQ9jC 密码：z3ag
初级代码 链接：http://pan.baidu.com/s/1miBi0dE 密码：uak5
学习资料&PDF电子书 大合集 链接：http://pan.baidu.com/s/1bpcoM4J 密码：1fvb
入门必备 链接：http://pan.baidu.com/s/1kVkgfS7 密码：35oq
工具 链接：http://pan.baidu.com/s/1qX8clGg 密码：5j6o
视频教程（包括初级，进阶，细分领域） 链接：http://pan.baidu.com/s/1c2akUly 密码：188s
其他教程 链接：http://pan.baidu.com/s/1o8x7h8Y 密码：1ppq

数学分析：最要紧的观念   一个对象可以表达为无穷多个合理选择的对象的线性和
一个行列式的问题：矩阵M的行列式实际上是组成M的各个向量按照平行四边形法则搭成一个n维立方体的体积。
http://www.techug.com/post/10-algorithm-help-programmer-grow-up.html
行为树 http://www.aisharing.com/archives/90
