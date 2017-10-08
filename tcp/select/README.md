# TCP Programe in C

参考：[http://www.cnblogs.com/Anker/archive/2013/08/14/3258674.html](http://www.cnblogs.com/Anker/archive/2013/08/14/3258674.html)

## IO multiplexing

IO多路复用是指内核一旦发现进程指定的一个或者多个IO条件准备读取，它就通知该进程。

## IO multiplexing之select


	#include <sys/select.h>
	#include <sys/time.h>
	
	int select(int maxfdp1,fd_set *readset,fd_set *writeset,fd_set *exceptset,const struct timeval *timeout)
	返回值：就绪描述符的数目，超时返回0，出错返回-1
	
函数参数介绍如下：

（1）第一个参数maxfdp1指定待测试的描述字个数，它的值是待测试的最大描述字加1（因此把该参数命名为maxfdp1），描述字0、1、2...maxfdp1-1均将被测试。

因为文件描述符是从0开始的。

（2）中间的三个参数readset、writeset和exceptset指定我们要让内核测试读、写和异常条件的描述字。如果对某一个的条件不感兴趣，就可以把它设为空指针。struct fd_set可以理解为一个集合，这个集合中存放的是文件描述符，可通过以下四个宏进行设置：

	  void FD_ZERO(fd_set *fdset);           //清空集合
	
	  void FD_SET(int fd, fd_set *fdset);   //将一个给定的文件描述符加入集合之中
	
	  void FD_CLR(int fd, fd_set *fdset);   //将一个给定的文件描述符从集合中删除
	
	  int FD_ISSET(int fd, fd_set *fdset);   // 检查集合中指定的文件描述符是否可以读写 

（3）timeout告知内核等待所指定描述字中的任何一个就绪可花多少时间。其timeval结构用于指定这段时间的秒数和微秒数。

     struct timeval{
           long tv_sec;   //seconds
           long tv_usec;  //microseconds
    };

这个参数有三种可能：

（1）永远等待下去：仅在有一个描述字准备好I/O时才返回。为此，把该参数设置为空指针NULL。

（2）等待一段固定时间：在有一个描述字准备好I/O时返回，但是不超过由该参数所指向的timeval结构中指定的秒数和微秒数。

（3）根本不等待：检查描述字后立即返回，这称为轮询。为此，该参数必须指向一个timeval结构，而且其中的定时器值必须为0。