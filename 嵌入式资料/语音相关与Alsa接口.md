参考 http://blog.csdn.net/reille/article/details/5855859
http://www.360doc.com/content/11/0613/13/168576_126609790.shtml
si教程 https://jingyan.baidu.com/album/db55b609a8c6104ba30a2f88.html?picindex=2
http://www.cnblogs.com/cslunatic/p/3677729.html
###语音编程相关概念
样本长度(sample):记录音频数据最基本单位,8或16位;
通道数(channel):1单声道,2立体声;
桢(frame):记录一个声音单元,长度为样本长度与通道数乘积;
采样率(rate):每秒钟采样次数,针对桢而言;
周期(period):音频设备一次处理所需桢数,访问和存储音频设备数据单位;
交错模式(interleaved):记录音频数据一种方式-以连续桢的形式存放[首先记录完桢1的左声道样本和右声道样本（假设为立体声格式）,再开始桢2的记录]  非交错模式[首先记录的是一个周期内所有桢的左声道样本,再记录右声道样本,数据以连续通道方式存储(多数情况下用交错模式);

音质 MHz 128k 采样率44100Hz(bits)[11025 22050] 频率 音效 录音 语种

奈奎斯特(Nyquist)[香农采样定理:2F(F最高频率)足以完全包含模拟信号]理论中，只要离散系统的奈奎斯特频率高于采样信号的最高频率或带宽，就可以避免混叠现象。
####技术由来与44.1kHz
1.人类听觉限制-20-22000Hz 完全保真:音频采样前加一低通滤波器 奈奎斯特频率大于等于22000;采样率44000 避免混叠 44.1kHz 
2.PCM 脉冲编码调制
####音频格式与商业
前提:Wav:微软与IBM;Mp3有损高效冲击行业;AAC替代Mp3但被usb3和大存储击败  APE/FLAC无损 
封装:avi封装音视频

![Paste_Image.png](http://upload-images.jianshu.io/upload_images/2636843-8636d86f14f0dbb0.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
###语音库    FFmpeg综合处理音视频编解码
适用范围 优缺点 注意事项 其它:SDL,OpenAL以及那些桌面环境提供的工具集
ALSA
  1.完成低级的声音操作，以便能够最大化地控制声音并最大化地提高性能，或者如果您使用其它声音API没有的特性，那么ALSA是很好的选择;
  2.ALSA由许多声卡的声卡驱动程序组成，同时它也提供一个称为libasound的API库。应用程序开发者应该使用libasound而不是内核中的ALSA接口。因为libasound提供最高级并且编程方便的编程接口;
  3.ALSA提供内核模块来模拟OSS,这样之前的许多在OSS基础上开发的应用程序不需要任何改动就可以在ALSA上运行;另外,libaoss库也可以模拟OSS,而它不需要内核模块;ALSA包含插件功能,使用插件可以扩展新的声卡驱动,包括完全用软件实现的虚拟声卡;ALSA提供一系列基于命令行的工具集,比如混音器(mixer),音频文件播放器(aplay),以及控制特定声卡特定属性的工具

![Paste_Image.png](http://upload-images.jianshu.io/upload_images/2636843-d10dbb5ebef0fd61.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![Paste_Image.png](http://upload-images.jianshu.io/upload_images/2636843-012a53d99f5efacf.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
###语音识别
建立声音数据模型 导入语种数据 特征分析 相应处理
想做一款音频剪辑软件(拖曳选择 选择文件框 生成文件框 为声音添加标记-水印数据 变声)

###相关算法&产品
打碟器 CD刻录机

###问题解决
1.ALSA与Madplayer什么关系
2.交错模式下，我怎么分离左右通道的音频的数据分别存在不同的文件里面->伴奏制作

###总结
1.接口(驱动)与库是不同的
2.A/D转换:采样 量化 编码(采样:连续模拟信号时间上的离散化;量化:连续模拟信号幅度上离散化;)
3.效率:采集到的帧数据先放缓冲区 处理周期

![Paste_Image.png](http://upload-images.jianshu.io/upload_images/2636843-5c67106ee2b44d93.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

4.tar.bz2->jxvf 
环境变量设置:临时(export LD_LIBRARY_PATH=/usr/local/lib) 永久(①在 ~/.bashrc [每次修改.bashrc后，使用source ~/.bashrc  是修改立即生效]     ②或者 ~/.bash_profile 中加入 export 语句，前者在每次登陆和每次打开 shell 都读取一次，后者只在登陆时读取一次。我的习惯是加到 ~/.bashrc 中，在该文件的未尾，可采用如下语句来使设置生效:export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/lib
修改完后，记得关掉当前终端并重新打开一个新的终端，从而使上面的配置生效  ③/etc/environment      在PATH="...."的末尾处添加：
：/opt/EmbedSky/4.3.3/bin
其中/opt/EmbedSky/4.3.3/bin为你自己需要设置的环境变量路径     source /etc/environment)
5.不要在共享目录下解压(有可能找不到软连接) sudo 
>/dev/null 可输出解压错误信息
6.与音乐播放madplayer区别
