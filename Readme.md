# Project2-CourseSelectionSystem
项目2 学生选课管理系统 

1. 这是什么及如何使用
本软件实现了“学生选课系统”，协助用户进行相关信息的管理。
本软件支持“增加/删除课程”，“为课程添加/删除学生”，“为课程添加/删除教师”等操作，以及各种查询操作
	- Windows：
	直接运行`/bin/CourseSelectionSystem.exe` 即可打开系统，并根据提示进行操作
	- Linux:
	在`/src`并目录下输入`make`指令后输入`./CourseSelectionSystem.out`即可打开系统
	(或输入`make run`运行系统)
运行后输入`help`可查看帮助

2. 各个文件的包含关系：
	详情请见 `src/Makefile` 文件及文档

3. 各个文件的用途简介：
	- Object.* 
	定义了抽象基类，`Student`，`Teacher`，`Course`继承于此
	- Person.*
	定义了类`Person`，`Student`， `Teacher`。其中`Student`和`Teacher`由`Person`派生
	- Group.*
	对`std::set<T>`轻度封装
	- System.*
	定义类`System`，是系统核心
	- Course.*
	定义了类	`Course`代表课程。其中包含了`Group<Student>`, `Group<Teacher>`
	- IOHelper.*
	定义了`main`输入输出的一系列辅助函数
	
4. 注意事项：
	- 运行本系统需要C++14及以上
	- 请勿自行修改`bin/`内的文件

5. github: [YanB25](https://github.com/YanB25)

6. 更新日志：

	1. v1.0：项目完成




