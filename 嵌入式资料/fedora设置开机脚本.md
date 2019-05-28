sudo touch /etc/rc.d/rc.local
sudo vim /etc/rc.d/rc.local

在/etc/rc.d/rc.local文件中写入, 然后使用:wq命令 保存并退出.

#!/bin/bash
# 在这个文件中写入开机启动需要执行的命令

赋予可执行权限:
sudo chmod+x /etc/rc.d/rc.local

设置开机启动:
sudo systemctl enable rc-local.service


如果出现以下错误提示:
[root@abc ~]# systemctl enable rc-local.service
The unit files have no [Install] section. They are not meant to be enabled
using systemctl.
Possible reasons for having this kind of units are:
1) A unit may be statically enabled by being symlinked from another unit's
  .wants/ or .requires/ directory.
2) A unit's purpose may be to act as a helper for some other unit which has
  a requirement dependency on it.
3) A unit may be started when needed via activation (socket, path, timer,
  D-Bus, udev, scripted systemctl call, ...).



sudo vim /usr/lib/systemd/system/rc-local.service

在rc-local.service文件末尾加入:
[Install]
WantedBy=multi-user.target

并重新设置开机启动:
sudo systemctl enable rc-local.service

查看状态, 如果出现以下提示, 设置成功!
