语法
1.魔术方法 __get  __set
![image.png](https://upload-images.jianshu.io/upload_images/2636843-7bc97694f2eccfe1.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
__toString:(将对象转换为字符串)常用于输出网络或数据库连接或二进制对象等复杂对象
2.自动加载类库文件 
require_once('Captcha.class.php');//怎么用

模块
1.文件上传(注意:html里的form action是提交不了至php文件的,需要将后缀改为php)
php $_FILES["file"]["type"]
1024000 1m
与Vue合并开发方式
1.Vue上传图片到七牛云：https://blog.csdn.net/qq_38086247/article/details/82229979
https://blog.csdn.net/luckylqh/article/details/79072152
https://blog.csdn.net/kingrome2017/article/details/71994167
app上传方式:https://www.cnblogs.com/wangyuman26/p/5814411.html

开发工具:
商城开发思路:https://blog.csdn.net/hello2013zzy/article/details/79650167
https://github.com/ScrappyZhang/python_web_Crawler_DA_ML_DL/tree/master/web%E5%85%A8%E6%A0%88%E5%BC%80%E5%8F%91/Django%E7%94%B5%E5%95%86%E7%BD%91%E7%AB%99%E5%BC%80%E5%8F%91%E5%AE%9E%E4%BE%8B
composer(tp5包管理工具):https://blog.csdn.net/wengedexiaozao/article/details/79893672
在线格式化:http://tools.jb51.net/code/phpformat
许多在线工具:http://www.php.cn/xiazai/tool/4

NetBeans :https://netbeans.org/kb/docs/php/project-setup_zh_CN.html
Netbeans使用指南:https://netbeans.org/kb/docs/php/project-setup_zh_CN.html#localServer

Ecshop源码迁移注意:https://wenku.baidu.com/view/b61a18e0a216147916112813.html
EcShop使用了smarty模板:https://blog.csdn.net/haoyunyun888/article/details/82389295

1.PHP executable not found. Install PHP 7 and add it to your PATH or set the php.executablePath setting
未解决

php中文乱码:https://www.jb51.net/article/112507.htm

2.读写EXCEL教程:https://www.cnblogs.com/jianqingwang/p/6830892.html
https://www.cnblogs.com/jianqingwang/category/872872.html
3.python批量转换文件编码
4.chromewebdriver下载:https://npm.taobao.org/mirrors/chromedriver/
chromedriver与chrome各版本及下载地址:https://blog.csdn.net/yoyocat915/article/details/80580066
![image.png](https://upload-images.jianshu.io/upload_images/2636843-74f3a0a3515d6a70.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
5.收款二维码有两种做法：1.直接用你的收付款二维码打印出来  2.去申请成为微信商家，有收款二维码提供

wamp与tomcat环境整合:http://www.showerlee.com/archives/1077 《PHP最佳实践》，但是它主要谈的不是编程规则，而是PHP应用程序的合理架构。 它提供了一种逻辑和数据分离的架构模式，属于MVC模式的一种实践。我觉得，这是很有参考价值的学习资料，类似的文章网上并不多，所以一边学习，一边就把它翻译了出来。 根据自己的理解，我总结了它的MVC模式的实现方式（详细解释见译文）： 　　*?视图层（View）：前端网页； 　　*?逻辑层（Controller）：先是页逻辑（Page
Controller），负责处理页面请求；然后，调用业务逻辑（Business Controller），实现具体功能； 　　*?数据层（Model）：数据保存在数据库之中，上面有一个数据库抽象层，再上面则是一个"数据访问对象"（DAO），它生成"值对象"（Value Object）。业务逻辑通过DAO，操作值对象。 ======================================= PHP最佳实践 原载：http://www.odi.ch/prog/design/php/guide.php
译者：阮一峰 本文给出了PHP程序设计常见问题的解决方法，同时简单描述了PHP应用程序的架构。 1. php.ini设置 php.ini控制了解释器的行为，下面的一些设置保证了你的程序有最大的可移植性。 i. short_open_tag 设为0，即永远使用PHP的长标签形式：
<?php echo "hello world"; ?>，不用短标签形式
<?= "hello world" ?>。 ii. asp_tags 设为0，不使用ASP标签
    <% echo "hello world"; %>。 iii. magic_quotes_gpc 建议在脚本中包含一个全局文件，负责在读取$_GET、$_POST、$_COOKIE变量之前，首先检查这个设置是否打开，如果打开了，这对这些变量应用stripslashes函数。（注：该设置已经在PHP 5.3中被废除。） iv. register_globals 不要依赖这个设置，永远通过全局变量$_GET、$_POST、$_COOKIE去读取GET、POST和COOKIE的值。为了方便起见，建议声明$PHP_SELF = $_SERVER['PHP_SELF']。
        v. file_uploads 上传文件的最大大小，由下面的设置决定： 　　* file_uploads必须设为1（默认值），表示允许上传。 　　* memory_limit必须略大于post_max_size和upload_max_filesize。 　　* post_max_size和upload_max_filesize要足够大，能满足上传的需要。 2. 配置文件（configuration file） 你应该把与应用程序相关的所有配置，写在一个文件里。这样你就能很方便地适应开发环境的变化。配置文件通常包含以下信息：数据库参数、email地址、各类选项、debug和logging输出开关、应用程序常数。
        3. 名称空间（namespace） 选择类和函数名的时候，必须很小心，避免出现重名。尽可能不要在类以外，放置全局性函数，类对内部的属性和方法，相当于有一层名称空间保护。如果你确实有必要声明全局性函数，那么使用一个前缀，比如dao_factory()、 db_getConnection()、text_parseDate()等等。 4. 数据库抽象层 PHP不提供数据库操作的通用函数，每种数据库都有一套自己的函数。你不应该直接使用这些函数，否则一旦改用其他数据库（比如从MySQL 转为Oracle），你就有大麻烦了。而且，数据库抽象层通常比系统本身的数据库函数，更易用一些。
        5. "值对象"（Value Object, VO） 值对象（VO）在形式上，就像C语言的struct结构。它是一个只包含属性、不包含任何方法（或只包含很少方法）的类。一个值对象，就对应一个实体。它的属性，通常应该与数据库的字段名保持相同。此外，还应该有一个ID属性。 　　class Person { 　　　　var $id, $first_name, $last_name, $email; 　　} 6. 数据访问对象（Data Access Object, DAO） 数据访问对象（DAO）的作用，主要是将数据库访问与其他代码相隔离。DAO应该是可以叠加（stacked）的，这样就有利于将来你再添加数据库缓存。每一个值对象的类，都应该有自己的DAO。
        　　class PersonDAO { 　　　　var $conn; 　　　　function PersonDAO(&$conn) { 　　　　　　$this->conn =& $conn; 　　　　} 　　　　function save(&$vo) { 　　　　　　if ($v->id == 0) { 　　　　　　　　$this->insert($vo); 　　　　　　} else { 　　　　　　　　$this->update($vo); 　　　　　　} 　　　　} 　　　　function
        get($id) { 　　　　　　#execute select statement 　　　　　　#create new vo and call getFromResult 　　　　　　#return vo 　　　　} 　　　　function delete(&$vo) { 　　　　　　#execute delete statement 　　　　　　#set id on vo to 0 　　　　} 　　　　#-- private functions 　　　　function getFromResult(&vo,
        $result) { 　　　　　　#fill vo from the database result set 　　　　} 　　　　function update(&$vo) { 　　　　　　#execute update statement here 　　　　} 　　　　function insert(&$vo) { 　　　　　　#generate id (from Oracle sequence or automatically) 　　　　　　#insert record into
        db 　　　　　　#set id on vo 　　　　} 　　} DAO通常应该部署以下方法： 　　* save：插入或更新一条记录 　　* get：取出一条记录 　　* delete：删除一条记录 你可以根据自己的需要，添加其他DAO方法，常见的例子有isUsed()、getTop($n)、find($criteria)。 但是，所有的DAO方法都应该与数据库操作有关，不应该执行其他操作。DAO只应该对一张表进行基本的select / insert / update，不应该包含业务逻辑。举例来说，PersonDAO就不应该包含向某人发送Email的代码。
        你可以写一个工厂函数，根据不同的类名，返回相应的DAO。 　　function dao_getDAO($vo_class) { 　　　　$conn = db_conn('default'); #get a connection from the pool 　　　　switch ($vo_class) { 　　　　　　case "person": return new PersonDAO($conn); 　　　　　　case "newsletter": return new NewsletterDAO($conn);
        　　　　　　... 　　　　} 　　} 7. 自动生成代码 99%的值对象和DAO代码，可以根据数据库模式（schema）自动生成，前提是你的表和列使用约定的方式进行命名。如果你修改数据库模式，一个自动生成代码的脚本将大大节省你的时间。 8. 业务逻辑 业务逻辑直接反映使用者的需要。它们处理值对象，根据业务需要修改值对象的属性，使用DAO与数据库层交互。 　　class NewsletterLogic { 　　　　function NewsletterLogic() { 　　　　　　...
        　　　　} 　　　　function subscribePerson(&$person) { 　　　　　　... 　　　　} 　　　　function unsubscribePerson(&$person) { 　　　　　　... 　　　　} 　　　　function sendNewsletter(&$newsletter) { 　　　　　　... 　　　　} 　　} 9. 页逻辑（控制器） 当一个网页被请求时，页控制器（page controller）就会运行，然后产生输出。控制器的任务，就是将HTTP请求转化成业务对象（business
        object），然后调用相应的业务逻辑，最后生成一个"展示输出"的对象。 页逻辑依次执行以下步骤（请参照后面的PageController类的代码）： 　　i. 假定页面请求之中，包含一个cmd参数。 　　ii. 根据cmd参数的值，执行相应的动作。 　　iii. 验证页面返回的值，生成一个值对象。 　　iv. 针对值对象，执行业务逻辑。 　　v. 如果有必要，可以导向另一个页面。 　　vi. 收集必要的数据，输出结果。 注意：可以编写一个工具函数（utility function），处理GET或POST值，当有的变量没有赋值时，提供一个默认值。页逻辑不包含HTML代码。
        　　class PageController { 　　　　var $person; #$person is used by the HTML page 　　　　var $errs; 　　　　function PageController() { 　　　　　　$action = Form::getParameter('cmd'); 　　　　　　$this->person = new Person(); 　　　　　　$this->errs = array(); 　　　　　　if ($action
        == 'save') { 　　　　　　　　$this->parseForm(); 　　　　　　　　if (!this->validate()) return; 　　　　　　　　NewsletterLogic::subscribe($this->person); 　　　　　　　　header('Location: confirmation.php'); 　　　　　　　　exit; 　　　　　　} 　　　　} 　　　　function parseForm() { 　　　　　　$this->person->name
        = Form::getParameter('name'); 　　　　　　$this->person->birthdate = Util::parseDate(Form::getParameter('birthdate'); 　　　　　　... 　　　　} 　　　　function validate() { 　　　　　　if ($this->person->name == '') $this->errs['name'] = FORM_MISSING; 　　　　　　#FORM_MISSING
        is a constant 　　　　　　... 　　　　　　return (sizeof($this->errs) == 0); 　　　　} 　　} 10. 表现层（Presentation Layer） 最顶层的页面包含实际的HTML代码。这个页面需要的所有业务对象（business object），由页逻辑提供。 这个页面先读取业务对象的属性，然后将它们转换成HTML格式。
        <?php
　　　　require_once('control/ctl_person.inc.php'); #the page controller
　　　　$c =& new PageController();
　　?>

            <html>

            <body>

                <form action="<?php echo htmlspecialchars($PHP_SELF) ?>" method="POST">
                    <input type="hidden" name="cmd" value="save">
                    <input type="text" name="name" value="<?php echo htmlspecialchars($c->person->name); ?>">
                    <button type="submit">Subscribe</button>
                </form>
            </body>


            </html>
            11. 本地化（Localization） 本地化意味着要支持多种语言，这个比较麻烦，你无非有两种方法可以选择： 　　A) 准备多重页面。 　　B) HTML页面中去除特定语言相关的内容。 一般来说，A方法用得比较多，因为B方法会使得HTML页面的可读性很差。 所以，你可以先写完一种语言的页面，然后把它们进行拷贝，用某种命名法区别不同语言的版本，比如index_fr.php表示index.php的法语版。 为了保存用户的语言选择，你有几种方法： 　　A) 将语言设定保存在一个session变量或cookie之中；
            　　B) 从HTTP头中读取locale值； 　　C) 把语言设定作为一个参数，追加在每个URL后面。 看上去A方法比C方法容易得多（虽然session和cookie都有过期的问题），而B方法只能作为A或C的补充。 最后不要忘了，数据库中的字段也必须进行本地化。 12. 安装位置 有时候你需要知道程序的根目录在哪里，但是$_SERVER['DOCUMENT_ROOT']只是web服务器的根目录，如果你的程序安装在它的某个子目录之中，PHP没法自动知道。 你可以定义一个全局变量$ROOT，它的值就是程序的根目录，然后把它包含在每一个脚本文件中。那么，你要包含某个文件，就这样写require_once("$ROOT/lib/base.inc.php");。
            13. 目录结构 首先，每个类都应该有自己的独立文件，还必须有一套文件名的命名规则（naming convention）。 软件的目录结构可以采用如下形式： 　　/ 根目录。浏览器从这个页面开始访问。 　　/lib/ 包含全局变量（base.inc.php）和配置文件（config.inc.php）。 　　/lib/common/ 包含其他项目也可以共用的库，比如数据库抽象层。 　　/lib/model/ 包含值对象类。 　　/lib/dao/ 包含数据访问对象（DAO）类，以及DAO工厂函数。
            　　/lib/logic/ 包含业务逻辑类。 　　/parts/ 包含HTML模板文件。 　　/control/ 包含页逻辑。对于大型程序来说，这个目录下面可能还有子目录（比如admin/, /pub/）。 base.inc.php文件中，应该按照以下顺序添加包含文件： 　　* /lib/common之中经常使用的类（比如数据库层）。 　　* 配置文件； 　　* /lib/model之中所有类； 　　* /lib/dao的之中所有类。


            <h3>调试/开发准备</h3>
            1.Notice:Undefined varialbe:…… 这是一个比较常见的错误，解决方法：error_reporting调整错误级别，不会调整，那就百度下
            </br>
            </br>

            2.Fatal error: Call to undefined function…… 函数不存在，可能的原因： 1、系统不存在这个函数且你也没自定义 2、有人会问，我在别的机器上就不报错。那是因为环境不同，这个函数在本机没开，怎么开？你百度函数名字，就能查到这个函数属于哪个dll，去php.ini里开启
            </br>
            </br>

            <h3>常用函数</h3>
            一、写入文件</br>
            1.打开资源（文件）fopen($filename,$mode) 2.写文件fwrite($handle,$str) 3.关闭文件fclose($handle) 4.一步写入file_put_contents($filename,$str,$mode) FILE_APPEND LOCK_EX }
            </br>
            </br>

            二、读文件</br>
            1.读文件fread($handle,字节数) 2.读一行fgets($handle); 3.读一个字符fgetc($handle) 4.读成一个数组中file($filename) 5.一步读取file_get_contents($filename)
            </br>
            </br>
            三、 目录操作</br>
            1，建目录mkdir($dirname) 2，删除目录rmdir($dirname) 3，打开目录句柄opendir($dirname) 4，读取目录条数readdir($handle) 5，关闭目录资源closedir($handle) 6，重置目录资源rewinddir($dirname);
            </br>
            </br>
            四、目录和文件操作</br>
            1， 检查文件或目录是否存在file_exists($filename) 2，文件或者目录重命名rename($file)
            </br>
            </br>
            五、 文件操作</br>
            1拷贝文件copy('原文件','目标文件') 2删除文件unlink($filename) 3获取文件大小filesize($filename) 4取得文件的创建时间filectime($filename) 5取得文件的访问时间fileatime($filename) 6取得文件的修改时间filemtime($filename)
            </br>
            </br>
            六、路径操作</br>
            1获取路径dirname($path) 2获取文件名basename($path) 3获取路径信息pathinfo($path)
            </br>
            </br>
            七、数组函数（极其重要）</br>
            1.在数组的开头插入一个元素array_unshift($arr,$v) 2.在数组的尾部添加数组元素array_push($arr,$v,$v1...) 3.将数组的第一个元素移出，并返回此元素array_shift($arr) 4.在数组的尾部删除元素array_pop($arr) 5.将数组用$separator连接成一个字符串implode($a,$arr) 6.检测变量是否是数组is_array($arr) 7.获得数组的键名array_keys($arr) 8.获得数组的值array_values($arr)
            9.检索$value是否在$arr中，返回布尔值in_array($v,$arr) 10.检索数组$arr中，是否有$key这个键名array_key_exists($k,$arr) 11.检索$value是否在$arr中，若存在返回键名Array_search($value, $arr) 12.将一个数组逆向排序，如果第二个参数为true，则保持键名Array_reverse($arr, true) 13.交换数组的键和值 Array_flip($arr) 14.统计数组元素的个数
            Count($arr) 15.统计数组中所有值的出现次数 Array_count_values($arr) 16.移除数组中的重复值 Array_unique($arr) 17.值由小到大排序 Sort($arr) 18.值由大到小排序 Rsort($arr) 19.键由小到大排序 ksort($arr) 20.键由大到小排序 krsort($arr) 21.随机从数组中取得$num个元素 Array_rand($arr, $num) 22.对数组的所有元素求和Array_sum($arr)
            23.合并数组 array_merge($arr,$arr)
            </br>
            </br>
            八、字符串函数（极其重要）</br>
            1.输出字符串 echo($str) echo 2.原样输出（区分单引号和双引号） print($str) 3.输出字符串，结束脚本执行 Die($str):die($str) die; 4.输出字符串，结束脚本执行 exit($str) exit; 5.输出格式化字符串 printf($str,$p1,...) 6.不直接输出格式化的字符串，返回格式化的字符串，保存到变量中 sprintf($str,$p1,...) 7.打印变量的相关信息 var_dump($p) 8.字符串转换为小写 strtolower($str)
            9.字符串转换为大写 strtoupper($str) 10.将字符串的第一个字符转换为大写 ucfirst($str) 11.将字符串中每个单词转换为大写 ucwords($str) 12.去除字符串两端的空白字符。 Trim($str,' ,') 13.去除字符串左边空白字符。 Ltrim($str) 14.去除字符串右边空白字符。Rtrim($str) 空白字符：""，"\t"，"\n"，"\r"，”\0” 15取得字符串长度 strlen($str) 16统计包含的字符串个数
            substr_count($str,’子串’) 17返回字符串$string中由$start开始，长度为$length的子字符串 Substr($string ,$start[,$length]) 18返回字符串$string中，$search第一次出现到字符串结束的子字符串。 Strstr($string,$search) 19查找$search在$str中第一次位的置，从$offset开始。 Strpos($str,$search[,int $offset]) 20.查找$search在$str中最后一次的位置，从$offset开始
            Strrpos($str,$search[,int $offset]) 21.替换$str中的全部$search为 $replace。 Str_replace($search,$replace,$str) 22.重复输出指定的字符串 Str_repeat() 23.加密字符串 Md5() 24.字符串翻转 Strrev() 25.使用一个字符串分割另一个字符串,形成一个数组//把字符串变成数组 Explode(“分隔符”,$str);
            </br>
            </br>
            九、特殊函数</br>
            1、echo 'a';echo('a');都可以 2、exit输出后就会终止整个php的运行，exit;exit();exit('a');都合法，但要注意：exit 'a';是 不合法的： 3、die函数，当传递给exit和die函数的值为0时，意味着提前终止脚本的执行，通常用exit()这个名 字。 echo "1111"; exit(0); echo "2222"; //22222不会被输出，因为程序运行到exit(0)时，脚本已经被提前终止，“马上断气”。 当程序出错时，可以给它传递一个字符串，它会原样输出在系统终端上，通常使用die()这个名字。
            $fp=fopen("./readme.txt","r") or die("不能打开该文件"); //这种情况下，如果fopen函数被调用返回布尔值false时，die()将立即终止脚本，并马上打印 //传递给它的字符串，“死前还能说一两句话”。 4、include 'a.php'; include('a.php'); require使用方法和include一样，当引入其他php的时候推荐用require
            </br>
            </br>

            <h3>常见错误提示</h3>
            一、syntax error, unexpected T_STRING, expecting 。。。 严重语法错误，例如syntax error, unexpected T_STRING, expecting ',' or ';' in F:\phpnow\htdocs\index.php on line 4 后边标着行号，自己去检查那一行的标点就行 如果是 第三行 echo 1 后边没加;，报错会报 on line 4 ，on line 4，就是第四行</br>
            </br>

            二、Parse error: syntax error, unexpected T_VARIABLE in XXX.php on line XXX 这条语句是PHP常见的报错，一般是在XXX行的上一行，或者是XXX行，缺少分号。或者在双引号中使用双引号，且没有转义等等。 解决方法：找到XXX.php的XXX行，按照上面的分析，找到自己的错误，改正即可。 贴士：作为编程人员，要做到代码严谨，思维清晰，并且细心。人非圣贤孰能无过，但尽量避免这些因为粗心出现的错误，这样才能成为合格的程序员。
            </br>
            </br>

            三、Parse error: syntax error, unexpected 'X' in XXX.php on line XXX 这条语句依然是PHP常见的报错，报错原因是在XXX.php的XXX行，出现了PHP无法识别的字符。常常是因为function，if等需要‘{’、‘}’的地方没有闭合，或者在编程的时候，不小心在‘;’的后面误打了几个字符。 解决方法：找到XXX.php的XXX行，删除多出的字符，添加缺少的字符即可。
            </br>
            </br>

            四、syntax error, unexpected $end 逻辑忘了闭合 这个报错还有个特征，他会提示你最后一行代码报错，譬如你一共30行，他就告诉你 on line 30，这时候你别检查第三十行，你要把30行挨个，检查一遍，看看哪个标签没闭合。 一共3000行，他就告诉你 on line 3000，这时候你别检查这3000行了，如果你程序排版很乱，在3000行里找哪个括号是个很麻烦的事……我教你一招： ctrl+a ctrl+d alt+f4 好了，你现在可以重写了。
            </br>
            </br>

            ##代码设置防止乱码 第一类:文件乱码 没出指定编码, 但目前浏览器有的是默认gbk,有的却是默认是utf8，这就导致乱码！ 解决办法： 1、 入口文件的第一行 ,强制输出（常用）！header("Content-type: text/html; charset=utf-8")； 2、 html模版head部分（常用）！

            <head>
                <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
            </head>

            第二类 数据库乱码 1、数据库本身创建的时候指定编码（常用） create table cz_category( cat_id smallint unsigned not null auto_increment primary key comment '商品类别ID', cat_name varchar(30) not null default '' comment '商品类别名称', parent_id smallint unsigned not null default 0 comment '商品类别父ID',
            cat_desc varchar(255) not null default '' comment '商品类别描述', sort_order tinyint not null default 50 comment '排序依据', unit varchar(15) not null default '' comment '单位', is_show tinyint not null default 1 comment '是否显示，默认显示', index pid(parent_id)
            )engine=MyISAM charset=utf8; 如果是在phpmyadmin下创建的，那么就应该在“整理”中选取utf-8_unicode_ci 2、 php连接mysql这里 （常用）function getField($table_name) { $link = mysql_connect('localhost','root','1234abcd'); mysql_query('use daxue'); mysql_query('set names utf8');
            $result=mysql_query("desc {$table_name}"); 伪静态 比如文章详细页, 正常的调用是 bbs.itcast.cn/index.php?m=article&id=1， 这么不美观。我们要改成伪静态成为这种”bbs.itcast.cn/news/1.html“。 利用$article就是查询出来的数据是：
            <?php $article=array('id'=>1,'title'=>'发布i测试','content'=>'......'......); echo "<a href='/news/{$article['id']}.hml'>{$article['title']}</a>";

 提供两种方法！
nginx 规则:rewrite ^/news/([0-9]+)\.html$ /index.php?m=article&id=$1 last;

apache 的伪静态规则:RewriteRule ^news/([0-9]+)\.html$ index.php?m=article&id$1 [L]

apache的伪静态写法主要分成4部分，这里大概解释一下 为什么这样写 :
RewriteRule 固定这么写,不告诉你为啥
        ^news/([0-9]+)\.html$ 这部分是匹配当前的url地址, 也就是伪静态的地址
        [0-9]+ 表示至少有1个数字,可以是0也可以是无限大
        index.php?m=article&id=$1 这里是指向对应的真实地址
        $1 配对上面的第一个括号, $2匹配第二个以此类推
        [L] L意思是如果此规则匹配,则停止,不在匹配后面的,减少无必要查询 。
