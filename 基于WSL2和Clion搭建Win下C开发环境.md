# 系列文章目录
一、基于WSL2和Clion搭建Win下C开发环境
二、make、makeFile、CMake、CMakeLists的使用
三、全面、详细、通俗易懂的C语言语法和标准库

@[TOC](文章目录)

# 前言
Win下C语言开发环境千千万，但基于WSL2和Clion的环境是最好用且最易于后续发展的。关于Cygwin和MinGW的区别与联系可以看[这篇文章](https://www.zhihu.com/question/22137175/answer/90908473)。
# WSL2
## 安装
- 依据[官方文档](https://learn.microsoft.com/zh-cn/windows/wsl/install-manual)安装WSL2，建议手动安装，然后自助去商店下载Linux发行版。
- 我选用的Linux版本是Ubuntu，点击打开设置好用户和密码：

![在这里插入图片描述](https://img-blog.csdnimg.cn/2593369d19b94e2db11df8449165dae0.png)
## WSL常用命令

```bash
wsl [options]
	--help #查看帮助
	-l -v #查看已存在分支及状态
	--shutdown #关闭wsl
	-s <name> #设置默认分支
	-t <name> #终止指定分支
	--unregister <name> #注销分支并删除文件系统
```

## VSCode连接WSL
- 安装插件：

![在这里插入图片描述](https://img-blog.csdnimg.cn/69d5ba85dffb43fab09d176964411352.png)

- 在插件选择进行连接：

![在这里插入图片描述](https://img-blog.csdnimg.cn/01cd9ec43abf4e8b882aa685f8d90177.png)


![在这里插入图片描述](https://img-blog.csdnimg.cn/9aaefe897b204732aeb7f6d84d0e2449.png)
## root密码
通过以下命令设置root密码：
```bash
sudo passwd root
```
## 以systemd启动
在Ubuntu中打开或创建`/etc/wsl.conf`文件：

```bash
sudo vim /etc/wsl.conf
```
添加以下配置：
```go
[boot]
systemd=true
```
重启wsl：

```bash
wsl --shutdown
wsl
```
## 配置ssh
- Ubuntu自带openssh，如果没有可以先装一下。
- 打开`/etc/ssh/sshd_conf`文件并添加以下配置：

```bash
Port 300
PasswordAuthentication yes
```
- 重启sshd服务：

```bash
systemctl restart sshd
```
# Clion
- 打开Clion选择安装好的Ubuntu：

![在这里插入图片描述](https://img-blog.csdnimg.cn/ba038ea420e4491e878d664e08a2d62d.png)
- 连接ssh：

![在这里插入图片描述](https://img-blog.csdnimg.cn/884597e96d1a4c56b6de9964004a4d94.png)
- 在Ubuntu中安装开发工具：

```bash
sudo apt-get upgrade
sudo apt install cmake
sudo apt install make
sudo apt install g++
sudo apt install gdb
```
- 安装之后Clion会自动检测，通过之后就会变成下面的样子：

![在这里插入图片描述](https://img-blog.csdnimg.cn/09f30ea6f7ce4de0949fe2c440a56545.png)

- 接着配置一下项目：

![在这里插入图片描述](https://img-blog.csdnimg.cn/a5e0566914e44f078a2dd6607e208c49.png)
- 接下来就可以愉快的写代码了：

![在这里插入图片描述](https://img-blog.csdnimg.cn/f0c61982be5645a69238a3f8c0289444.png)

# 结语
在此过程中遇到问题可给我留言。