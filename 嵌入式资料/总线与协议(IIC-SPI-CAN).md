### 总线
总线应用场景:http://www.dzsc.com/data/2017-6-29/112533.html
又分数据 地址 控制
#### Can协议
重点:https://wenku.baidu.com/view/486647f47c1cfad6195fa794.html
can->canFestival->canOpen
canopen入门(6068使用) https://wenku.baidu.com/view/ee8af2eb7fd5360cba1adbc3.html
(协议详解) http://www.doc88.com/p-7905821781629.html
canFestival（canOpen的开源实现）移植笔记 https://www.cnblogs.com/ChYQ/p/5719469.html

CAN协议一般发送八字节长度的短帧数据达到对节点的控制，你买的驱动器应该有厂家自己的协议，对照着相应指令，你去填充这八个字节（包含节点号、指令类型、指令类型对应的数据，比如电机期望位置、速度数据）发送下去，就能控制了。而CANopen协议，是一个通用的跟驱动器相关联的标准化协议，跟上面CAN协议不同之处在于你给驱动器发送的是SDO、PDO等指令，而不是具体的CAN报文
实时性:SYNC同步信号在总线上发出后是需要在同步周期内收到返回报文的，这就是对硬实时的要求。另外用PC电脑通过U转C进行控制，确实一般情况下是看似能用的。如果不相信我说的，请按我的指示操作一下，控制运行中你打开windows系统自带的计算器，是不是伺服通讯出现故障了？这就是因为win系统不是实时的。
每个厂商实现的DS402协议都有细微差异，但总体框架是一样的。初始化最重要的是驱动器里状态机的转换，你的控制端应该和此状态同步，即在哪个状态就只能发哪个状态可以接收的命令。另外，控制端应时刻监听或查询statusword，如果有错误异常，这里最先反映出来。具体错误可能通过Emergency Message推给控制端。控制端也可以主动去读错误历史记录。个人建议你用结构体映射control word和status word以便于编程


红外通信:智能家居远程控制方式之一（方案）  优势:成本 抗干扰  历史  普及
问题:1.小米手机红外如何实现(应用层软件-安卓)  2.如何与语音识别结合(灵犀语音 如何做到系统级(与智能家居软件结合 语音就能开空调))   3.遥控精灵能否远程关闭家电（与WiFi等结合实现多种方式的遥控组合）  4.红外编码(分析并了解如何进行复杂指令控制)
5.硬件改造:普通家电集成加非红外遥控加装
(参考:DIY红外风扇 http://bbs.elecfans.com/jishu_458130_1_1.html
http://www.51hei.com/bbs/dpj-20601-1.html)
6.遥控方式与安全性思考(红外与WiFi哪个被控制 哪些不怕被破解)

使用及指导
Arduino从入门到精通:20讲   如何控制其它器件-获得的遥控信号转化为其它器件的逻辑控制命令

#### OBD
相关资料https://blog.csdn.net/xqhrs232/article/details/79388482

#### 一 IIC  时序、驱动
![iic原理图.png](https://upload-images.jianshu.io/upload_images/2636843-e160ce6a98e87bcf.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
![image.png](https://upload-images.jianshu.io/upload_images/2636843-ce528e9fbcb63eb9.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
![时序图1.png](https://upload-images.jianshu.io/upload_images/2636843-67122901be7c7fb5.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
![时序图2.png](https://upload-images.jianshu.io/upload_images/2636843-8c8b01697186ad92.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
![时序图3.png](https://upload-images.jianshu.io/upload_images/2636843-7b6e4f41098307ff.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


是什么:https://baike.baidu.com/item/I2C%E6%80%BB%E7%BA%BF/918424?fr=aladdin
原理、特性 https://www.cnblogs.com/zhangjiansheng/p/7738390.html
适用场合
一句话总结:IIC的使用就是拉高降低时钟线(中间有延时设置)来接收和发送数据
IIC对应有总线和设备 发送接收一个字节信息的例子 多个数据呢？ 主从  适用场景(MPU6050)
数据合成  大体使用流程和例子代码(代表性的具体项目)
怎么做:

1.时钟SCL/数据SDA引脚定义;
2.I^C时序中延时设置(起始信号)
SDA = 1;//拉高数据线
SCL = 1;//拉高时钟线
//Delay2us();
SDA = 0;//产生下降沿
//Delay2us(); 
SCL = 0;//拉低时钟线

void Delay2us()	
{
	unsigned char i;
	i = 2;
	while (--i);
}

3.发送数据
void I2C_SendByte(unsigned char dat)
{
    unsigned char i;
    for (i=0; i<8; i++)         //8位计数器
    {
        dat <<= 1;              //移出数据的最高位
        SDA = CY;               //送数据口
        SCL = 1;                //拉高时钟线
        Delay2us();
		SCL = 0;                //拉低时钟线
        Delay2us();
    }
    I2C_RecvACK();
}

4.接收应答信号(数据)
bit I2C_RecvACK(void)
{
    SCL = 1;                    //拉高时钟线?
    Delay2us();
	CY = SDA;                   //读应答信号
    SCL = 0;                    //拉低时钟线
    Delay2us();
	return CY;
}

#### 二 SPI 时序、驱动
##### SPI(串行外设接口Serial Peripheral Interface)
Motorola公司出品
特点:高速的，1主N从全双工非差分，不需要寻址(点对点),同步的通信总线  只占用四根线(单向时只用3根):
①SCLK（主器件产生的时钟信号,最大为fPCLK/2，从模式频率最大为fCPU/2）
②NSS(从器件必须的使能信号,低电平有效,由主器件控制,有的IC会标注为CS)
③SDO（数据输出,MOSI – 主器件[数据输出]，从器件数据输入
）
④SDI（数据输入,MISO主入从出）;某一时刻可以出现多个从机，但只能存在一个主机，主机通过片选线来确定要通信的从机（也就是任何时刻只能有一对主从机在通信）。这就要求从机的MISO口具有三态特性，使得该口线在器件未被选通时表现为高阻抗
![image.png](https://upload-images.jianshu.io/upload_images/2636843-c8057d841661a257.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
![image.png](https://upload-images.jianshu.io/upload_images/2636843-ff9df379efc9c947.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

用途:EEPROM,Flash,实时时钟,AD转换器,数字信号处理器和数字信号解码器之间,集成的芯片有:STM32 AT91RM9200
通信原理:SCLK信号线只由主设备控制，从设备不能控制信号线。同样，在一个基于SPI的设备中，至少有一个主控设备。这样传输的特点：这样的传输方式有一个优点，与普通的串行通讯不同，普通的串行通讯一次连续传送至少8位数据，而SPI允许数据一位一位的传送，甚至允许暂停，因为SCLK时钟线由主控设备控制，当没有时钟跳变时，从设备不采集或传送数据。也就是说，主设备通过对SCLK时钟线的控制可以完成对通讯的控制。SPI还是一个数据交换协议：因为SPI的数据输入和输出线独立，所以允许同时完成数据的输入和输出。不同的SPI设备的实现方式不尽相同，主要是数据改变和采集的时间不同，在时钟信号上沿或下沿采集有不同定义，具体请参考相关器件的文档。传输过程由主机初始化,内部硬件实际上是两个简单的移位寄存器，传输的数据为8位，在主器件产生的从器件使能信号和移位脉冲下，按位传输，高位在前，低位在后
SCLK的上升沿上数据改变，同时一位数据被存入移位寄存器;
![image.png](https://upload-images.jianshu.io/upload_images/2636843-5bda8178022c83b7.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
如图： 
1.MISO引脚相连接，MOSI引脚相互连接。这样，主从设备之间串行地传输且通信总是由主设备发起。 
2.主设备通过MOSI脚把数据发给从设备的同时，从设备通过MISO脚传回数据给主设备。这个全双工的过程是由时钟信号SCK控制同步的。 
3.时钟信号由主设备通过SCK脚提供。
![image.png](https://upload-images.jianshu.io/upload_images/2636843-39a68523446c2776.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
简析： 
1. 从图中可以具体的看出SCK信号，由波特率发生器产生，传给从机和自己的通信控制寄存器中。 
2. 波特率的大小由SPL_CR1寄存器的BR2,BR1,BR0三个位决定。 
3. 通信控制由SPL_CR1寄存器的MSTR,SSM,SSI三个位和NSS控制，通信控制控制通信过程中的错误如CRC校验错误，模式错误，溢出。 
4. 主控制电路控制，输入输出的逻辑门电路打开与关闭
![image.png](https://upload-images.jianshu.io/upload_images/2636843-0b42eaf599b92c2c.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

缺点：没有指定的流控制，没有应答机制确认是否接收到数据
https://baike.baidu.com/item/SPI%E6%8E%A5%E5%8F%A3/2527392?fr=aladdin

##### 使用说明
![主从选择.png](https://upload-images.jianshu.io/upload_images/2636843-a5eaeae6c764d2a8.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
![时钟信号的相位与极性.png](https://upload-images.jianshu.io/upload_images/2636843-91d46c3d4181426c.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
![时钟信号的相位与极性.png](https://upload-images.jianshu.io/upload_images/2636843-8aa5188f209e380f.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
![工作模式设置.png](https://upload-images.jianshu.io/upload_images/2636843-7d9a5bba00b275a2.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

仿真例子:
/*    SPI写数据/命令 
 *    Mode :O:写命令   1：写数据 
 *    data :数据/命令 
*/  
void SPI_Write(char data, int Mode)  
{      
    int i = 0; 
    
    if(Mode)  
    {  
        OLED_DC(1);        //DC引脚输入高，表示写数据  
    }  
    else  
    {  
        OLED_DC(0);        //DC引脚输入低，表示写命令  
    }  
    OLED_CS(0);            //CS引脚输入低，片选使能  
    for(i = 0; i < 8; i++)  
    {  
        OLED_D0(0);        //D0引脚输入低  
        if(data&0x80)    //判断传输的数据最高位为1还是0  
        {  
            OLED_D1(1);    //D1引脚输入高  
        }  
        else  
        {  
            OLED_D1(0);    //D1引脚输入低  
        }  
        OLED_D0(1);        //D1引脚输入高  
        data<<=1;        //将数据左移一位  
    }  
    OLED_DC(0);            //DC引脚输入低  
    OLED_CS(1);            //CS引脚输入高，片选失能  
}

![数据帧格式.png](https://upload-images.jianshu.io/upload_images/2636843-b49339a3388d9371.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
![中断与配置过程.png](https://upload-images.jianshu.io/upload_images/2636843-93aa2553bbbbeae7.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
![数据传输过程.png](https://upload-images.jianshu.io/upload_images/2636843-0e450ebd4c925278.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

通信原理及编程步骤:https://wenku.baidu.com/view/fc7be59a0912a216147929c6.html

参考:
读写Flash例子:https://blog.csdn.net/ybhuangfugui/article/details/51355999
SD读写实例:https://wenku.baidu.com/view/bccdaa5c804d2b160b4ec0ec.html?sxts=1550044187300
总线协议及时序图详解含实例:https://wenku.baidu.com/view/1d162f7187c24028915fc3da.html
https://blog.csdn.net/fly__chen/article/details/52724109
重点:协议心得 https://baike.baidu.com/item/SPI/4429726?fr=aladdin#2_2
#### IIC  SPI区别与联系
https://www.cnblogs.com/zhangjiansheng/p/7738390.html
http://m.elecfans.com/article/574049.html

#### UART 
![image.png](https://upload-images.jianshu.io/upload_images/2636843-a245dfac8cf70b0c.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

是什么:https://baike.baidu.com/item/UART/4429746
怎么做
UART：通用异步接收/发送装置。
串口：含义比 UART 广，它包括了 UART。

一、UART：通用异步收发传输器，通常称作UART，是一种异步收发传输器，是电脑硬件的一部分。它将要传输的资料在串行通信与并行通信之间加以转换。作为把并行输入信号转成串行输出信号的芯片，UART通常被集成于其他通讯接口的连结上。

二、UART：是一种通用串行数据总线，用于异步通信。该总线双向通信，可以实现全双工传输和接收。在嵌入式设计中，UART用于主机与辅助设备通信，如汽车音响与外接AP之间的通信，与PC机通信包括与监控调试器和其它器件，如EEPROM通信。

三、串口：也称串行通信接口或串行通讯接口，是采用串行通信方式的扩展接口。串行接口是指数据一位一位地顺序传送，其特点是通信线路简单，只要一对传输线就可以实现双向通信，从而大大降低了成本，特别适用于远距离通信，但传送速度较慢。

### 通信协议
智能家居通信协议 http://theme.eccn.com/theme/2016/Smarthome/tecShow/2016090614111795.html
类似安全加解密 传输标准 基于TCP/IP 
http://blog.csdn.net/phunxm/article/details/5086080
### 相关术语
数据报 









