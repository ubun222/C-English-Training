# C-English-Training
1. 这是一个用C重写的，依赖终端的，背单词程序。支持ish，termux等移动端，也支持macOS，Linux等桌面端。
2. 不支持windows的cmd和powershell。若要在win下编译运行，请安装WSL。
---

### 使用方法
* 安装gcc编译器
* ish需要额外的apk add build-base
```
gcc c1.c
./a.out
```

### 参数
1. -i 优化iOS下的ish，termux等可能也需要该参数
2. -r 错题集模式

### tips
1. 红黄绿指示亮起时，按y/v可分别获取txt文件中的详细释义和例句，按s跳过。
2. 组合键 ctrl+f 可查询词表单词。
3. TAB键自动补全。
---


