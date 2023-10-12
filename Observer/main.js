// 观察者
function Observer(name) {
    this.name = name;
    this.update = function (message) {
      console.log(`${this.name} received message: ${message}`);
    };
}
  // 可观察对象
function Observable() {
    this.observers = [];
    this.subscribe = function (observer) {
        this.observers.push(observer);
    };
    this.notify = function (message) {
        this.observers.forEach(function (observer) {
            observer.update(message);
        });
    };
}
  
// 示例使用
const observer1 = new Observer("Observer 1");
const observer2 = new Observer("Observer 2");
const observable = new Observable();
observable.subscribe(observer1);
observable.subscribe(observer2);
observable.notify("Hello, Observers!");
observable.notify("Observers, are you there?");