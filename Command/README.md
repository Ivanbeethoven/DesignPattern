# Command pattern
将一个请求封装成一个对象，从而让你使用不同的请求把客户端参数化，对请 求排队或者记录请求日志，可以提供命令的撤销和恢复功能

#### 优点

- 类间解耦：调用者角色与接收者角色之间没有任何依赖关系，调用者实现功能时只需调用Command 抽象类的execute方法就可以，不需要了解到底是哪个接收者执行。
- 可扩展性：Command的子类可以非常容易地扩展，而调用者Invoker和高层次的模块Client不产生严 重的代码耦合。
- 结合其他模式：命令模式可以结合责任链模式，实现命令族解析任务；结合模板方法模式，则可以减少 Command子类的膨胀问题。
#### 缺点

　　命令模式也是有缺点的，请看Command的子类：如果有N个命令，问题就出来 了，Command的子类就可不是几个，而是N个，这个类膨胀得非常大，这个就需要读者在项 目中慎重考虑使用。

## 场景
支持命令的撤销(Undo)操作和恢复(Redo)操作


Lieberman H. There's more to menu systems than meets the screen[C]//Proceedings of the 12th annual conference on Computer graphics and interactive techniques. 1985: 181-189