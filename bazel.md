## bazel的使用

[bazel](https://bazel.build/)是google开源的构建工具，可以支持多种语言的构建。这里来尝试一下如何在C++项目中使用bazel构建。

安装就不介绍了，在官网很详细，输入bazel --help：

    Usage: bazel <command> <options> ...

    Available commands:
    analyze-profile     Analyzes build profile data.
    build               Builds the specified targets.
    canonicalize-flags  Canonicalizes a list of bazel options.
    clean               Removes output files and optionally stops the server.
    coverage            Generates code coverage report for specified test targets.
    dump                Dumps the internal state of the bazel server process.
    fetch               Fetches external repositories that are prerequisites to the targets.
    help                Prints help for commands, or the index.
    info                Displays runtime info about the bazel server.
    license             Prints the license of this software.
    mobile-install      Installs targets to mobile devices.
    query               Executes a dependency graph query.
    run                 Runs the specified target.
    shutdown            Stops the bazel server.
    test                Builds and runs the specified test targets.
    version             Prints version information for bazel.

看上去和maven差不太多，以一个实际项目来介绍一下基本命令的使用。

### bazel build

在目录下建立test文件夹和WORKSPACE，并在test下创建两个文件，分别如下：

    ├── test
    │   ├── BUILD
    │   └── test.cc
    └── WORKSPACE
 
 
内容如下：

BUILD:

    package(default_visibility = ["//visibility:public"])

    cc_binary(
        name = "test",
        srcs = [
            "test.cc",
        ],
    )
    
WORKSPACE为空

test.cc:

    #include <iostream>

    int main() 
    {
        std::cout<<"test"<<std::endl;

        return 0;
    }

其中：WORKSPACE和BUILD是bazel项目必须的文件，test.cc是我们自己定义的c++文件，.cc后缀是unix系统的后缀，.cpp是非unix系统。

### 构建项目

在test/目录下执行以下命令可以编译c++文件：

    bazel build [target]

本例中：

    bazel build test/...

**注意是３个点！**

编译成功的结果：

	INFO: Analysed target //test:test (0 packages loaded). 
	INFO: Found 1 target...
    Target //test:test up-to-date:
    bazel-bin/test/test
    INFO: Elapsed time: 0.219s, Critical Path: 0.01s
    INFO: Build completed successfully, 1 total action

目录结果变为：

    ├── bazel-bin -> /home/mobvoi/.cache/bazel/_bazel_mobvoi/74778f1ed6b087a47652b1c57f0f5d45/execroot/__main__/bazel-out/local-fastbuild/bin
	├── bazel-genfiles -> /home/mobvoi/.cache/bazel/_bazel_mobvoi/74778f1ed6b087a47652b1c57f0f5d45/execroot/__main__/bazel-out/local-fastbuild/genfiles
	├── bazel-out -> /home/mobvoi/.cache/bazel/_bazel_mobvoi/74778f1ed6b087a47652b1c57f0f5d45/execroot/__main__/bazel-out
	├── bazel-test -> /home/mobvoi/.cache/bazel/_bazel_mobvoi/74778f1ed6b087a47652b1c57f0f5d45/execroot/__main__
	├── bazel-testlogs -> /home/mobvoi/.cache/bazel/_bazel_mobvoi/74778f1ed6b087a47652b1c57f0f5d45/execroot/__main__/bazel-out/local-fastbuild/testlogs
	├── test
	│   ├── BUILD
	│   └── test.cc
	└── WORKSPACE

在bazel-bin/test/test.runfiles/__main__/test目录下有二进制文件，运行：

    $ ./test
    test

至此bazel编译成功！

### bazel run
	bazel build用来编译cpp为二进制文件，除此之外还可以直接运行cpp文件中的main函数。

### bazel query

	用来查看依赖树。

### bazel test

	类似mvn test，运行代码中的单测。

### bazel clean

	清除编译的结果，类似mvn clean。
