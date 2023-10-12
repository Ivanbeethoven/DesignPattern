Smalltalk 的MVC的结构
Model担任目标的角色，View是观察者。

Krasner G E. A cookbook for using model-view-controller user interface paradigmin smalltalk-80[J]. J. Object Oriented Programming, 1988, 1(3): 26-49.

- Observer 对象通过其 update(message) 方法向 Observable 对象注册自己。
- Observable 对象维护一个观察者列表，用于存储已注册的观察者。
当 Observable 对象的状态发生变化，它会遍历观察者列表，依次调用每个观察者的 update 方法，将消息传递给它们。
各个观察者接收到通知后，执行自己的操作。