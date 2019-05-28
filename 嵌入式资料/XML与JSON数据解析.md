powershell(百度云上有叶工两个文件)
在powershell中执行
Set-ExecutionPolicy Unrestricted  [解决无法运行ps问题]
![image.png](https://upload-images.jianshu.io/upload_images/2636843-bc74e0b7d2930f7d.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


数据解析一般与网络通信联系在一块,QT 提供了 QNetworkAccessManager()，做项目要写使用说明文档(测试IP修改 文件位置)
三大数据格式的优缺点:https://blog.csdn.net/hongse_zxl/article/details/40049045
### XML
XML 的优势:可以经常在不中断应用程序的情况进行扩展
自定义标签
1.http://blog.csdn.net/psujtfc/article/details/38066343
QDomDocument代表整个文档
QDomElement根节点
QDomNode来遍历整个文档


### JSON
1.

1.Excel表格里的数据需求
2.将Excel表格里的数据转储为数据源

数据源预处理-分类处理
1.数据列的修改
2.中文的分割与特殊字符的处理(Excel:数据->分列[拷贝源数据到新列后添加逗号作为分割符])
3.空行的移除

数据库
1.新建数据表(理顺数据需求的前提-预留多5个字段-分类[消毒单独一个表])
转换工具-SQLite_Expert实现Excel表转SqLite数据库:https://blog.csdn.net/qq_28775437/article/details/79520709
中文的支持
2.导入注意:单位 字符长度 问题  

文件IO的几种方式
1.CSV(QT读取和写入的方式) 
1.1数据源预处理(结合软件需求)-Excel宏(保证全部转换为英文字符,)
QFileDialog* fd = new QFileDialog(this)；//创建打开文件对话框
QString fileName = fd->getOpenFileName(this,tr("Open File"),"/home",tr("Excel(*.csv)"));
if(fileName == "")
      return;
QDir dir = QDir::current();
QFile file(dir.filePath(fileName));
if(!file.open(QIODevice::ReadOnly))
     qDebug()<<"OPEN FILE FAILED";
QTextStream * out = new QTextStream(&file);//文本流
QStringList tempOption = out->readAll().split("\n");//每行以\n区分
for(int i = 0 ; i < tempOption.count() ; i++)
{
     QStringList tempbar = tempOption.at(i).split(",");//一行中的单元格以，区分
     ...//省略具体对数据的操作
}
file.close();//操作完成后记得关闭文件

2.XML(处理比较麻烦-从数据源到应用到软件)
2.1 数据源->分析结构
2.2 导入并读取
2.3 预处理并创建结构体
2.4 引用和保存
2.5 导出和修改等其它操作

3.Json
