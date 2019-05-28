UBIFS文件系统使用说明
介绍:https://blog.csdn.net/sdustliyang/article/details/7616202
一、UBIFS文件系统制作
1, ./mkfs.ubifs -r rootfs_path -e 129024 -m 2048 -c 80 -o ubifs.img
2, ./ubinize -o ubi.img -p 128KiB -m 2048 -s 512 ubinize.cfg

注：这两个命令在fedora linux中包含在mtd-utils软件包里，使用yum install mtd-utils即可。在其他的开发平台上可能需要使用mtd-utils源码包进行编译生成。

问题备注：
如果mkfs.ubifs和ubinize的参数有问题，会引起一系列错误，主要是-e, -m, -s要正确，另外，-c和vol_size注意要比mtd分区适当小一些。

参数说明：
Usage: mkfs.ubifs [OPTIONS]
Make a UBIFS file system image from an existing directory tree

Options:
-r, -d, --root=DIR       build file system from directory DIR
-m, --min-io-size=SIZE   minimum I/O unit size
-e, --leb-size=SIZE      logical erase block size
-c, --max-leb-cnt=COUNT  maximum logical erase block count
-o, --output=FILE        output to FILE
-j, --jrn-size=SIZE      journal size
-R, --reserved=SIZE      how much space should be reserved for the super-user
-x, --compr=TYPE         compression type - "lzo", "favor_lzo", "zlib" or
                         "none" (default: "lzo")
-X, --favor-percent      may only be used with favor LZO compression and defines
                         how many percent better zlib should compress to make
                         mkfs.ubifs use zlib instead of LZO (default 20%)
-f, --fanout=NUM         fanout NUM (default: 8)
-k, --keyhash=TYPE       key hash type - "r5" or "test" (default: "r5")
-p, --orph-lebs=COUNT    count of erase blocks for orphans (default: 1)
-D, --devtable=FILE      use device table FILE
-U, --squash-uids        squash owners making all files owned by root
-l, --log-lebs=COUNT     count of erase blocks for the log (used only for
                         debugging)
-v, --verbose            verbose operation
-V, --version            display version information
-g, --debug=LEVEL        display debug information (0 - none, 1 - statistics,
                         2 - files, 3 - more details)
-h, --help               display this help text

Note, SIZE is specified in bytes, but it may also be specified in Kilobytes,
Megabytes, and Gigabytes if a KiB, MiB, or GiB suffix is used.

If you specify "lzo" or "zlib" compressors, mkfs.ubifs will use this compressor
for all data. The "none" disables any data compression. The "favor_lzo" is not
really a separate compressor. It is just a method of combining "lzo" and "zlib"
compressors. Namely, mkfs.ubifs tries to compress data with both "lzo" and "zlib"
compressors, then it compares which compressor is better. If "zlib" compresses 20
or more percent better than "lzo", mkfs.ubifs chooses "lzo", otherwise it chooses
"zlib". The "--favor-percent" may specify arbitrary threshold instead of the
default 20%.

ubinize version 1.1 - a tool to generate UBI images. An UBI image may contain
one or more UBI volumes which have to be defined in the input configuration
ini-file. The ini file defines all the UBI volumes - their characteristics and
the and the contents, but it does not define the characteristics of the flash
the UBI image is generated for. Instead, the flash characteristics are defined
via the command-line options. Note, if not sure about some of the command-line
parameters, do not specify them and let the utility to use default values.

INI-file format.
The input configuration ini-file describes all the volumes which have to
be included to the output UBI image. Each volume is described in its own
section which may be named arbitrarily. The section consists on
"key=value" pairs, for example:

[jffs2-volume]
mode=ubi
image=../jffs2.img
vol_id=1
vol_size=30MiB
vol_type=dynamic
vol_name=jffs2_volume
vol_flags=autoresize
vol_alignment=1

This example configuration file tells the utility to create an UBI image
with one volume with ID 1, volume size 30MiB, the volume is dynamic, has
name "jffs2_volume", "autoresize" volume flag, and alignment 1. The
"image=../jffs2.img" line tells the utility to take the contents of the
volume from the "../jffs2.img" file. The size of the image file has to be
less or equivalent to the volume size (30MiB). The "mode=ubi" line is
mandatory and just tells that the section describes an UBI volume - other
section modes may be added in the future.
Notes:
  * size in vol_size might be specified kilobytes (KiB), megabytes (MiB),
    gigabytes (GiB) or bytes (no modifier);
  * if "vol_size" key is absent, the volume size is assumed to be
    equivalent to the size of the image file (defined by "image" key);
  * if the "image" is absent, the volume is assumed to be empty;
  * volume alignment must not be greater than the logical eraseblock size;
  * one ini file may contain arbitrary number of sections, the utility will
    put all the volumes which are described by these section to the output
    UBI image file.

Usage: ubinize [-o filename] [-h] [-V] [--output=<filename>] [--help]
                [--version] ini-file
Example: ubinize -o ubi.img -p 16KiB -m 512 -s 256 cfg.ini - create UBI image
         'ubi.img' as described by configuration file 'cfg.ini'
-o, --output=<file name>     output file name
-p, --peb-size=<bytes>       size of the physical eraseblock of the flash
                             this UBI image is created for in bytes,
                             kilobytes (KiB), or megabytes (MiB)
                             (mandatory parameter)
-m, --min-io-size=<bytes>    minimum input/output unit size of the flash
                             in bytes
-s, --sub-page-size=<bytes>  minimum input/output unit used for UBI
                             headers, e.g. sub-page size in case of NAND
                             flash (equivalent to the minimum input/output
                             unit size by default)
-O, --vid-hdr-offset=<num>   offset if the VID header from start of the
                             physical eraseblock (default is the next
                             minimum I/O unit or sub-page after the EC
                             header)
-e, --erase-counter=<num>    the erase counter value to put to EC headers
                             (default is 0)
-x, --ubi-ver=<num>          UBI version number to put to EC headers
                             (default is 1)
-v, --verbose                be verbose
-h, --help                   print help message
-V, --version                print program version

二、UBIFS文件系统烧写
可以在uboot里进行烧写或者通过sam-ba进行在线烧录，和烧写内核镜像是一样的。

三、UBIFS文件系统挂载
修改内核启动参数，即可挂载为根文件系统：
ubi.mtd=3 rootfstype=ubifs root=ubi0:rootfs
