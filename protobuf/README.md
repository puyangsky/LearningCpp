# mac上安装及使用C++版本的Protobuf

Protobuf是谷歌开源的一个跨平台的二进制序列化工具，通过配置文件的形式生成不同语言的代码，压缩效率非常高效。

主要介绍下如何在mac os和C++环境下安装Protobuf工具，及一个简单的使用实例。


## 安装

安装文档参考的是Protobuf的[github上的readme](https://github.com/google/protobuf/blob/master/src/README.md)，首先下载最新版的C++版本的源码，[下载地址](https://github.com/google/protobuf/releases)，解压后进入目录，执行以下命令：

	$ ./configure
	$ make
	$ make check
	$ sudo make install
	
	执行命令：protoc --version
	如果输出：libprotoc 3.4.0 则代表安装成功
	
如果是其他语言的话，可以直接在[https://github.com/google/protobuf/releases](https://github.com/google/protobuf/releases)上下载对应的zip包：protoc-$VERSION-$PLATFORM.zip就可以获取protobuf的二进制工具了。

## 使用

该实例参考的是官方教程：[https://developers.google.com/protocol-buffers/docs/cpptutorial](https://developers.google.com/protocol-buffers/docs/cpptutorial)

### Defining Your Protocol Format
第一步，定义对象的proto文件：

创建addressbook.proto：

	syntax = "proto2";
	
	package tutorial;
	
	message Person {
	  required string name = 1;
	  required int32 id = 2;
	  optional string email = 3;
	
	  enum PhoneType {
	    MOBILE = 0;
	    HOME = 1;
	    WORK = 2;
	  }
	
	  message PhoneNumber {
	    required string number = 1;
	    optional PhoneType type = 2 [default = HOME];
	  }
	
	  repeated PhoneNumber phones = 4;
	}
	
	message AddressBook {
	  repeated Person people = 1;
	}
	
### Compiling Your Protocol Buffers
执行

	protoc -I=$SRC_DIR --cpp_out=$DST_DIR $SRC_DIR/addressbook.proto
	
	
	$ protoc -I=./ --cpp_out=./ ./addressbook.proto
	$ ls
	addressbook.pb.cc addressbook.pb.h  addressbook.proto
	


### Writing A Message


### Reading A Message


