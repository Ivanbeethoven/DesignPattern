# Template
## intention
定义一个操作中的算法股价，将一些步骤延迟到子类。
不改变一个算法结构即可重定义算法的某些步骤。

## 适用性
- 一次性实现一个算法的不变部分，将可变的行为留给子类。
- 将子类的公共行为提取出来，以避免代码重复。
- 控制子类扩展



## Run the code
```bash
javac Main.java && java Main
```