# C-English-Training
1. 这是一个用C重写的，依赖终端的，背单词程序。支持ish，termux等移动端，也支持macOS，Linux等桌面端。
2. 不支持windows。若要在win下编译运行，请安装WSL。
---

### 使用方法
* 安装gcc编译器
* ish需要额外的apk add build-base
```
gcc c2.c
./a.out
```

### 参数
1. -i 优化iOS下的ish
2. -r 错题集模式
3. -R 剔除模式(直接在已加载的词表上删改)
4. -p 通关模式
5. -t 自定义txt文件夹路径

### tips
1. 红黄绿指示亮起时，按y/v可分别获取txt文件中的详细释义和例句，按s跳过。
2. 组合键 ctrl+f 可查询词表单词。
3. TAB键自动智能补全。
4. 中文输入时，只需输入()<>以外的中文即可，答案将自动补全。
---


