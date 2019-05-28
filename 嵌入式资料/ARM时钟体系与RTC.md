S5PV210
![image.png](https://upload-images.jianshu.io/upload_images/2636843-790f075cf09b4911.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
原理图上时钟源
![image.png](https://upload-images.jianshu.io/upload_images/2636843-144f65a68de407d6.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
时钟域
![image.png](https://upload-images.jianshu.io/upload_images/2636843-a99a496e15ea40de.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
四、不同的外设使用的时钟源
![image.png](https://upload-images.jianshu.io/upload_images/2636843-dc89ba1e6d4e87cc.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
210的时钟倍频器
![image.png](https://upload-images.jianshu.io/upload_images/2636843-223b84d6c4d56f81.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
![image.png](https://upload-images.jianshu.io/upload_images/2636843-3309b2029b29e9bb.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
![image.png](https://upload-images.jianshu.io/upload_images/2636843-7edbb49f21fbb929.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
![image.png](https://upload-images.jianshu.io/upload_images/2636843-8a91b4cb1ddb7f69.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
![image.png](https://upload-images.jianshu.io/upload_images/2636843-10382a1a49feaf23.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
![image.png](https://upload-images.jianshu.io/upload_images/2636843-e9df27852cced5a6.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

一、什么是RTC
RTC ----  REAL Time Clock----->实时时钟(年、月、日、星期、时、分、秒)
RTC的使用：

1）设置当前的时间

2）RTC可以自动的工作（嵌入式平台中，RTC也会不准）--->获取网络时间校正

                                                   --->GPS和北斗校时

3）可以设置闹钟时间，产生闹钟中断。

1、ARM中的RTC模块
![image.png](https://upload-images.jianshu.io/upload_images/2636843-87f5ba52705cc015.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
二、ARM的电源原理图
![image.png](https://upload-images.jianshu.io/upload_images/2636843-77b0954bd886522b.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
三、S5PV210中RTC的特点

1、Supports BCD Number, that is Second, Minute, Hour, Day of the week, Day, Month, and Year. 

BCD码（压缩型的BCD码）---> 32秒 --->second寄存器的内容 0x32

压缩型的BCD码是8位的，高4位是十位，第4位是各位。

2、Supports Leap Year Generator

3、Supports Alarm Function, that is ,Alarm-Interrupt or Wake-up from power down modes (idle, deep idle, stop,deep stop, and sleep) 

4、Supports Tick Counter Function, that is Tick-Interrupt or Wake-up from power down modes (idle, deep idle,stop, deep stop, and sleep) 

5、Supports Independent Power Pin (RTCVDD) 

6、Supports millisecond tick time interrupt for RTOS kernel time tick . 

RTC的TICK时钟，可以提供给实时操作系统的内核，作为实时操作系统内核时钟。
![image.png](https://upload-images.jianshu.io/upload_images/2636843-52c724a91f48131c.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
四、RTC的寄存器

配置寄存器
![image.png](https://upload-images.jianshu.io/upload_images/2636843-05ca22feb6e700eb.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
![image.png](https://upload-images.jianshu.io/upload_images/2636843-ac401ee03fddd804.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

闹钟的设置寄存器
![image.png](https://upload-images.jianshu.io/upload_images/2636843-0930a4aebfed72c7.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
RTC时间设置和读取的寄存器
![image.png](https://upload-images.jianshu.io/upload_images/2636843-7e1e8823d91259a0.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

1、中断判断寄存器---INTP
![image.png](https://upload-images.jianshu.io/upload_images/2636843-96b489f7323d06b8.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

2、RTC的控制寄存器----RTCCON
![image.png](https://upload-images.jianshu.io/upload_images/2636843-91cc00e37e940225.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
![image.png](https://upload-images.jianshu.io/upload_images/2636843-ab1d4f890d619280.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

3、滴答时钟计数器寄存器----TICCNT
![image.png](https://upload-images.jianshu.io/upload_images/2636843-909954abc98c3a11.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
例：设置tick timer的周期是500ms，则频率2Hz。
1）设置tick timer的clock频率：
RTCCON &= ~(0xf<<4);  //tick timer的基准频率32768Hz
2）设置tick timer的计数值

TICNT = 32768/2;  //tick timer的工作频率2Hz

基准频率/计数值 = 工作频率

基准频率/工作频率=计数值

4、RTC的闹钟寄存器---RTCALM
![image.png](https://upload-images.jianshu.io/upload_images/2636843-ab4733b0038fd3e1.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
设置闹钟的比较时间。
五、RTC的程序
要求：
1、设置当前的时间
2、Tick timer的周期是800ms，每次tick中断的时候就读取当前时间，通过串口输出当前时间：printf()

3、设置闹钟时间

4、在那种中断中，beep响10s。

RTC的中断源和中断号：
![image.png](https://upload-images.jianshu.io/upload_images/2636843-71516c4cf04cad56.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

扩展:定时器 按键与延时设计
1.按键处理事件的逻辑中谨慎加延时
消毒快速终止会发现继续或者起不来
单片机按键定时器设计:http://m.elecfans.com/article/617142.html
日志调试:https://blog.csdn.net/u013955308/article/details/20712937
