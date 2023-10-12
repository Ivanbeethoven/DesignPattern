// 观察者接口
interface Observer<T> {
    next(value: T): void;
    error(error: Error): void;
    complete(): void;
}
  
// 可观察对象类
class Observable<T> {
    private observers: Observer<T>[] = [];

    subscribe(observer: Observer<T>): void {
    this.observers.push(observer);
    }

    unsubscribe(observer: Observer<T>): void {
    const index = this.observers.indexOf(observer);
    if (index !== -1) {
        this.observers.splice(index, 1);
    }
    }

    next(value: T): void {
    for (const observer of this.observers) {
        observer.next(value);
    }
    }

    error(error: Error): void {
    for (const observer of this.observers) {
        observer.error(error);
    }
    }

    complete(): void {
    for (const observer of this.observers) {
        observer.complete();
    }
    }
}
  
// 示例使用

// 创建一个可观察对象
const observable = new Observable<number>();

// 创建观察者
const observer1: Observer<number> = {
next(value) {
    console.log(`Observer 1: Received value ${value}`);
},
error(error) {
    console.error(`Observer 1: Received error ${error.message}`);
},
complete() {
    console.log("Observer 1: Completed");
},
};

const observer2: Observer<number> = {
next(value) {
    console.log(`Observer 2: Received value ${value}`);
},
error(error) {
    console.error(`Observer 2: Received error ${error.message}`);
},
complete() {
    console.log("Observer 2: Completed");
},
};

// 订阅观察者
observable.subscribe(observer1);
observable.subscribe(observer2);

// 发送值给观察者
observable.next(1);
observable.next(2);

// 取消订阅观察者
observable.unsubscribe(observer2);

// 再次发送值给观察者
observable.next(3);

// 完成观察
observable.complete();
