
Vue导出Excel及与后台SSM通信例子:https://blog.csdn.net/BADAO_LIUMANG_QIZHI/article/details/83791140

坑及解决方案
搭建的后台:https://segmentfault.com/a/1190000008582706 elementUI不支持移动,可以用bootstrap
Vue对android支持情况
https://www.csdn.net/gather_20/OtTagg3sMDA1LWJsb2cO0O0O.html
用虚拟机在4.1.1/4.0.3/4.0用系统浏览器跑了官方单元测试
4.1.1/4.0.3全绿
就4.0上有4个用例没过
v-for with transition
v-for staggering transitions reorder while staggered
v-model support debounce
Util - Language Enhancement debounce
4.0占%2左右
如果一定要支持
使用的时候注意避开这4项

仿写实例:https://blog.csdn.net/qq_35585701/article/details/79382126
大部分主题:https://segmentfault.com/search?q=vue+android&page=5

1.第三种WebApp成熟方案;2.cordova vue打包；3.webView交互方案
0.技巧:https://blog.csdn.net/sinat_17775997/article/details/82491280
1.vue android无法显示router-link 
法1：https://segmentfault.com/search?q=vue+android
![image.png](https://upload-images.jianshu.io/upload_images/2636843-8c7182354e0131ad.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
法2：npm uninstall webpack-dev-server
npm install -D webpack-dev-server@2.7.1
2.vue-router懒加载解决首次加载时资源过多导致的速度缓慢
https://blog.csdn.net/fabulous1111/article/details/79389280#comments

环境搭建:部署编译(开发环境一套,生产环境一套)
真机联调chrome:https://blog.csdn.net/qq_16559905/article/details/60755174
vue开发环境和部署环境切换
0.Vue编译Apk
npm run build
cordova build android
![test环境切换未解决.png](https://upload-images.jianshu.io/upload_images/2636843-bf2f32ae93d77824.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

1.集成X5内核开发:https://x5.tencent.com/tbs/guide/sdkInit.html
借助cordova打包成apk:https://segmentfault.com/a/1190000016372789
![压缩打包.png](https://upload-images.jianshu.io/upload_images/2636843-78fd25288ff49213.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


实战（H5 Vue https://github.com/Paranoidyang）
订单页面:https://www.cnblogs.com/sobaby/p/6875112.html
购物车:http://www.cnblogs.com/sobaby/p/6875096.html
(设计注意事项,结合cookie和数据库,防止sql注入,与界面分离)
腾讯课堂(购物车):https://ke.qq.com/course/313770
参考:https://github.com/Paranoidyang/vue2.0-shoppingCart
cookie购物车:https://blog.csdn.net/ParanoidYang/article/details/72865477
https://www.baidu.com/s?ie=utf-8&f=8&rsv_bp=1&tn=baidu&wd=vue%20cookie%E8%8E%B7%E5%8F%96%E8%B4%AD%E7%89%A9%E8%BD%A6%E6%95%B0%E6%8D%AE&oq=vue%2520cookie&rsv_pq=a14b0a2f0002d344&rsv_t=b6f0X14Ts7bqrvgksNzviFYYFcn6SoONI3I4gvIt8PGOAVpDIu85GxPiFZs&rqlang=cn&rsv_enter=1&inputT=3436&rsv_sug3=25&rsv_sug1=14&rsv_sug7=100&rsv_sug2=0&rsv_sug4=6178
cookie与session详解:https://mp.weixin.qq.com/s/NXrH7R8y2Dqxs9Ekm0u33w
vue从后台获取数据:https://www.cnblogs.com/jasonwang2y60/p/6606822.html

组件间通信:https://www.cnblogs.com/jasonwang2y60/p/6606822.html

![image.png](https://upload-images.jianshu.io/upload_images/2636843-d5c0d2b626fef24e.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

跨平台编译(ios):https://www.jianshu.com/p/6e8d88ddb0b7

支付模块
阿里 微信 支付接口开发
http://www.apkbus.com/blog-822415-77933.html

转移到android:转到android:id:https://github.com/ljnjiannan/vue-demo
开发工具:VsCode
https://juejin.im/search?query=vue%E5%BC%80%E5%8F%91%E5%B7%A5%E5%85%B7

echartjs结合使用:https://www.jianshu.com/p/7994176fbcc4
# [ECMAScript 6 入门](http://es6.ruanyifeng.com/)
http://es6.ruanyifeng.com/#docs/destructuring

实例:https://www.jianshu.com/p/2129bc4d40e9
页面切换
https://www.jb51.net/article/150684.htm

# [Vue--vue中常用的ECMAScript6语法](https://www.cnblogs.com/mrszhou/p/7881964.html)


Javascript
1.严格模式 https://www.cnblogs.com/jiqing9006/p/5091491.html
![image.png](https://upload-images.jianshu.io/upload_images/2636843-a51674c35303c1db.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

2016京东前端改版总结https://aotu.io/notes/2016/12/26/jd-index-2016-summary/ 
