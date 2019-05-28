### FFMpeg学习笔记
win QT下MPlayer的问题:
1.pause fullScreen等命令不通用/无效

易学易用、例子多、前景好
https://blog.csdn.net/kaikai136412162/article/details/80746961
1.视频水印:
ffmpeg -i in.mp4 -i xxx.png -filter_complex "overlay=5:5"  out.mp4
in.mp4  视频源文件
xxx.png  要打水印的图片
overlay  设置水印图片的位置
out.mp4 水印后的视频输出
2.视频截取
ffmpeg -i test.mp4 -ss 60 -t 35 -codec copy cut1.mp4
-i : 视频source
-ss : start time 时间格式可以 为S  或  00:00:00
-t : duration  持续，持久，连续时间，切记这里不是结束时间
3.

### 天猫精灵
https://post.smzdm.com/p/702676/
![image.png](https://upload-images.jianshu.io/upload_images/2636843-3f3a5e466160c996.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
无需唤醒就可以直接执行的快捷指令： 
精灵暂停，精灵播放，精灵静音，精灵退出
下一首，上一首，声音大一点，声音小一点
小度(麦好，体验人性化，指令训练)
无唤醒识别算法
声纹，微提示（性格分析）;
### 智能家居使用场景&体验
https://post.smzdm.com/p/690365/

### 音频设备
消费类音频设备开发->FFMPEG 语音识别(科大讯飞 festival) 人工智能(音响相关算法及移植 开发工厂测试软件 alsa 蓝牙 WiFi协议)
CVTE面试准备:正装 笔试题 项目(①音乐播放器 裸机 驱动代码) ②QT项目 ③机顶盒&智能电视  打出一份研发计划(智能音响 智能家居入口 语音识别方案)  ECho技术 消费智能音响方案
广州睿耳声学科技有限公司
蓝牙音箱，WIFI音箱，DAB(数字信号广播)音箱，Soundbar

需求:降低系统成本  系统集成的便捷性  数字信号处理（DSP）  可下载升级的构想、新特性以及个性化都可增加方便易用属性的价值

行业热点
芯智汇科技近日在国内率先发布了专门针对人工智能热门应用的语音识别多阵列麦克风前端ADC芯片AC108       音乐播放器项目移植 

amazon echo技术剖析

http://ti.eetop.cn/viewnews-4560
目标:智能家居入口 wifi/蓝牙播放 语音输入识别
芯片比较 http://www.eeworld.com.cn/mcu/article_2017051134072.html

http://www.elecfans.com/video/audio/20121106296620_4.html

### 警报器
在线查看 .pcb文件 https://easyeda.com/
特性 https://zhidao.baidu.com/question/263809003119683445.html    
中文规格书 https://wenku.baidu.com/view/2c49736c80eb6294dc886c1f.html

功能:1.按键响正常一声
2.按键响正常(频率不同)一声
3.按键不同频率连续响
4.按键调频 暂停 重响 wiwu~~wiwu~wiwu~  wawa~wawa~wawa  消防 通缉 

产品思路:

汽车警报器视频 http://www.iqiyi.com/w_19rrw2pzhl.html

开发思路:①同类源码参考->官方文档  参考例子 
②警报器的需求设计 手头资源修改
③其它类似的修改过来 https://wenku.baidu.com/view/bd090ffa941ea76e58fa04f7.html
https://wenku.baidu.com/view/f2ff7977be1e650e53ea9930.html?re=view

红外报警 https://wenku.baidu.com/view/1ce643a4376baf1ffc4fadc2.html
https://wenku.baidu.com/view/1ce643a4376baf1ffc4fadc2.html
流水灯报警-51单片机案例
温度报警-ARM项目


### 安居宝   
http://hr.ofweek.com/jobs/?keytype=0&moreopt=false&district%5B%5D=&key=%B0%B2%BE%D3%B1%A6
薪酬福利:周末双休带薪年假五险一金年终双薪绩效奖金包吃包住节日福利提供班车定期体检员工旅游任职要求：
1、大学专科以上学历，三年以上工作经验，至少一年以上linux下开发经验；
2、熟练掌握c++，熟练使用stl, boost等库；
3、有音视频编解码开发经验，熟悉ffmpeg库；
4、精通音视频的采集、压缩、传输、存储、分发、播放的全过程；
5、精通流媒体相关技术；
6、有手机上音视频编解码实际开发经验者优先考虑；
7、有从事过视频会议及时通信、视频点播相关项目者优先考虑；
8、对工作充满激情，具有强烈的创新精神，富于责任心，能承受较大工作压力。

### 实时音视频传输
开发一个优秀的RTC系统需要具备的技术
1.语音编解码器，然后调整音频处理模块的算法(有噪声消除，回声抑制，自动增益。比较前沿的还有多麦克风降噪，盲扩增强等等)涉及语音信号处理、统计信号处理等方面的内容。有了算法还不够，还需要有好的实现。各个平台（Android，iOS，Windows，Mac）底层音频系统也需要深入了解。有时候算法挺好的，但有些机器先天不足，比较特别，需要特殊处理。这需要投入许多人力物力对各种型号的硬件做适配。优秀的系统可能需要适配几百上千个不同的设备
2.视频，我们需要对视频编解码器有深入的了解。这样才能用最低的码率展示清晰的视频画面。视频的前后处理，比如降噪，增强（包括流行的美颜）也少不了。这就需要图像与视频信号处理。视频数据量比较大，对底层视频设备也需要深入研究。适配也少不了。
3.网络抗丢包是必备选项  信道编码的理论也有网络对抗的实际经验
要实现可靠的云服务，遍布全球的服务器网络也必不可少。高可用性，负载均衡等等














