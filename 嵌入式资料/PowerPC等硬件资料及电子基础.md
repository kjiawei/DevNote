MPC5748G
PowerPC架构相比于ARM的优势：https://blog.csdn.net/avatar1912/article/details/44999017
http://www.elecfans.com/soft/33/2014/20141016356469.html
小木虫汽车电子资料:http://muchong.com/t-8296402-1-authorid-2091928
自己动手改装“蓝牙和AUX”https://club.autohome.com.cn/bbs/thread/7ea8d3ca40293ab4/59616963-1.html
Protel 99SE教程:https://wenku.baidu.com/view/3b411e843b3567ec102d8ae1.html
看懂电路图 https://jingyan.baidu.com/article/86f4a73e8f914637d6526900.html
https://wenku.baidu.com/view/5f743368bb1aa8114431b90d6c85ec3a86c28b54.html
Hall effect Switch（霍尔开关），当一块通有电流的金属或半导体薄片垂直地放在磁场中时，薄片的两端就会产生电位差，这种现象就称为霍尔效应。
例如：就是手机外套上有个磁片，当我们手机外套合上时，屏幕就会熄灭，打开时，就是亮起

数据采集硬件：如何避免缺陷与误差
http://www.eefocus.com/analog-power/205932/
1.通过软件尽可能的逼近硬件性能(物理上的准确性)
2.采用算法(多次测量求平均值等方法-内部采用算法在更新间隔多次取值[性能])来求出可接受的值(市场 技术 售后)
3.行业做法

电子电路
元器件
阻抗匹配主要应对小信号(相对能量传送)传递的，
你需要先理解的第一个基本道理就是‘最大限度的获取’

一个通俗易懂的例子
比如一个10V的电源内部串了一个10R的电阻，如果你想在这个电源上获取最大的能量（功率），那么你的负载阻抗必定是10R
才能获取最大的能量--2.5W，想想看呢。

### WatchDog
看门狗使用(与中断有关)注意：
公式:t_watchdog = 1/(PCLK/(Prescaler value+1)/Division_factor) //频率值
与所需时间比对获得WTDAT的值 (Hz = 1/T)  第一分频值自己设定,二(4选1)
打开看门狗(分开处理) 记得喂狗
watchdog看门狗:看门狗就是定期的查看芯片内部的情况，一旦发生错误就向芯片发出重启信号的电路。看门狗命令在程序的中断中拥有最高的优先级
作用:嵌入式系统受干扰([偶然的]电源波动 电磁干扰 硬件异常)而跑飞/死机造成不能正常工作用来重启系统(从故障恢复)[提高系统稳定性(单片机没有)]


基本原理  16位  定时器(计数器位数)
看门狗，又叫 watchdog timer，是一个定时器电路，一般有一个输入，叫喂狗(kicking the dog or service the dog），一个输出到MCU的RST端，MCU正常工作的时候，每隔一段时间输出一个信号到喂狗端，给 WDT 清零，如果超过规定的时间不喂狗，（一般在程序跑飞时），WDT 定时超过，就会给出一个复位信号到MCU，使MCU复位. 防止MCU死机. 看门狗的作用就是防止程序发生死循环，或者说程序跑飞。
工作原理：在系统运行以后也就启动了看门狗的计数器，看门狗就开始自动计数，如果到了一定的时间还不去清看门狗，那么看门狗计数器就会溢出从而引起看门狗中断，造成系统复位，所以在使用有看门狗的芯片时要注意清看门狗。
硬件看门狗编辑
硬件看门狗是利用了一个定时器，来监控主程序的运行，也就是说在主程序的运行过程中，我们要在定时时间到之前对定时器进行复位。如果出现死循环，或者说PC指针不能回来，那么定时时间到后就会使单片机复位。常用的WDT芯片如MAX813,5045,IMP 813等，价格4~10元不等。
单片机32个IO口(51不带看门狗,52可能带) 51单片机(高)电平复位:51单片机是由reset引脚控制复位的，与高电平相接24个震荡周期后，芯片进入复位状态
51单片机是一类吗?各型号有什么异同点(哪些经典型号)
PCLK  高速
HCLK WDT(66M P域低速时钟)
### 仿真器
帮下载到开发板的软件调试(软硬情况不一样，普通不支持调试)
程序编译通过不代表没有逻辑错误   还可以查看当前的寄存器、变量、堆栈、等详细情况；
仿真器就是让芯片按照软件仿真的步骤，一步步执行还是一个个函数执行，还是执行到某个断点处

### Jlink  Jtag  调试器  下载器   仿真器   烧写器（烧录器,编程器）
Jlink是个仿真器，是一种工具，它带有Jtag接口。
他们之间的关系就像USB接口和手机一样的关系。
大多数手机都使用usb接口（Jlink一般都是用Jtag接口），但有的手机不用usb接口，如水果手机（但有新出的Jlink是用SWD接口）。

调试是嵌入式系统开发过程的重要环节。嵌入式系统开发调试和一般PC系统开发调试有较大差别。在一般PC机系统开发中，调试器和被调试程序是运行在相同的硬件和软件平台上的两个进程，调试器进程通过操作系统专门提供的调试接口控制和访问被调试进程。而在嵌入式系统中，调试器是运行在桌面操作系统上的应用程序，被调试程序是运行在基于特定硬件平台的操作系统，两个程序间需要实时通信。
 嵌入式系统调试时，主机上运行的集成开发调试工具（调试器）通过仿真器和目标机相连。仿真器处理宿主机和目标机之间所有的通信，这个通信口可以是串口、并行口或者高速以太网接口。仿真器通过JTAG口和目标机相连。

 嵌入式系统开发调试方法有快速原型仿真法和实时在线调试法。快速原型仿真法用于硬件设备尚未完成时，直接在宿主机上对应用程序运行进行仿真分析。在此过程中系统不直接和硬件打交道，由开发调试软件内部某一特定软件模块模拟硬件CPU系统执行过程，并可同时将仿真异常反馈给开发者进行错误定位和修改。实时在线调试法在具体的目标机平台上调试应用程序，系统在调试状态下的执行情况和实际运行模式完全一样，这种方式更有利于开发者实时对系统硬件和软件故障进行定位和修改，提高产品开发速度。

 选用的调试器是运行在主机上的集成开发环境，一般需要集编辑、汇编、编译、链接和调试环境于一体，支持低级汇编语言、C和C 语言，基于友好的图形用户界面（GUI），支持用户观察或修改嵌入式处理器的寄存器和存储器配置、数据变量的类型和数值，堆栈和寄存器的使用，支持程序断点设置，单步、断点或者全速运行等特性。

 应用需求的多样性导致市场上仿真器和调试器的提供商也较多，Windriver公司的Tornado是一个很好的开发调试工具。根据实践经验，一般配套选择规模较大、信誉较好公司的仿真器和调试器，虽然价格偏高，但是这些公司技术实力强，售后服务好，调试器和仿真器开发结合紧密。如果在开发调试过程遇到技术障碍，可以通过电话或者电子邮件方式及时获取技术支持。如选用ARM系列的嵌入式处理器时，可以购买Multi-ICE仿真器，并附加ARM250集成开发调试环境等。

### OTP与ROM
擦芯片工具是什么?
OTP（One Time Programable）是MCU的一种存储器类型，意思是一次性可编程，即程序烧入IC后，将不可再次更改和清除。这样导致当芯片烧写出现错误时，OTP芯片只能作废；芯片程序升级时，原来的OTP芯片只能作废。华澜科技可提供一次性芯片程序清空擦除服务，帮您解决芯片烧写出现错误及芯片程序升级时清空OTP一次性芯片中的资料，变废为宝。
芯片ROM按存储类型主要分为MASK(掩模)ROM、OTP(一次性可编程)ROM、FLASH ROM等类型。MASK ROM的MCU价格便宜，但程序在出厂环AC芯时已经固化，适合程序固定不变的应用场合；FALSH ROM的MCU程序可以反复擦写，灵活性很强，但价格较高，适合对价格不敏感的应用场合或做开发用途；OTP ROM的MCU价格介于前两者之间，同时又拥有一次性可编程能力，适合既要求一定灵活性，又要求低成本的应用场合，尤其是功能不断翻新、需要迅速量产的电子产品。
OTP芯片程序只能通过紫外线擦除。华澜科技紫外线擦除方法如下：
1．做芯片开封：在芯片上开个洞；
2. 将紫外线擦除器接上电源，在定时器上设置好紫外线照射时间；
3. 将待擦除的芯片放在紫外线擦除器的抽屉里；
4. 打开电源开关，擦除器内部的紫外线管灯点亮，这时可以看到明显的紫色光线。
5. 外线擦除器的定时器关断后，完成OTP芯片数据擦除工作。一次性芯片数据清空后就可在编程器中再次写入数据了。

rom的种类有很多 有一种叫做 eprom 这种是可以擦写的rom     硬盘与ROM是两种不同类型的存储器;ROM是只读存储器，相对的RAM是随机存储器，它们都是内存储器。而硬盘（HDD）是外存储器的一种。它们完全不是一个概念。内存和外存的最大区别有二：一，内存需要供电才能存储数据，一旦断电则会造成数据丢失，而外存存储数据则不需要供电；二，内存的读写速度要远高于外存。ROM之所以被称为只读存储器，是因为通过一般的方法是无法写入或修改数据的，只能读出；而RAM则可以实现随机存取。在个人计算机中，典型的ROM是用来存储基本输入输出系统（BIOS）数据的，控制机器的底层输入输出功能，而典型的RAM就是我们平时接触到也是最俗称的“内存”，用于实现外存和CPU之间数据互通，弥补外存和CPU之间处理数据的巨大速度差而存在。

### RTC PLL
外部[晶振]稳定 内部[晶振]的误差比较大，但如果对频率要求不高的话（比如不涉及[串口通信]和精确定时等的话），用内部[晶振]就行 。内部时钟，频率受温度等其它影响,但是能省下晶振的钱，还有2个I/O。如果对频率要求不高，一般是优先选用内部振荡。 如果你要省电，用了SLEEP，那你就不能用内部振荡了，内部振荡回停止！
也分有源(自己就可以提供频率)和无源(需要电路提供频率来激活) 
芯片需要独立的晶振   音频模块也需要独立的,之间可能不需要同步
有些芯片内部就集成了RTC时钟(也有独立出来的模块)
RTC需要与PLL锁相环结合使用

### PCLK  高速
HCLK WDT(66M P域低速时钟)
CPU位长  (字长)  时长
PWM 32位(计数值)  ADC

### PLL锁相回路或[锁相环]
  用来统一整合时脉讯号，使高频器件正常工作，如内存的存取资料等。PLL用于振荡器中的反馈技术。 许多电子设备要正常工作，通常需要外部的输入信号与内部的振荡信号同步。一般的晶振由于工艺与成本原因，做不到很高的频率，而在需要高频应用时，有相应的器件VCO，实现转成高频，但并不稳定，故利用锁相环路就可以实现稳定且高频的时脉冲讯号。

### 倍频器 VPLL APLL MPLL EPLL

### 内部总线 AMBA


### IROM是内部还是外部的
