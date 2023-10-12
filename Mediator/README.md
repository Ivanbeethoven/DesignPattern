# Mediator 中介者
用一个中介对象封装一系列对象的交互，使得个对象不需要的互相，独立其交互过程。

Vlissides J M, Linton M A. Unidraw: A framework for building domain-specific graphical editors[J]. ACM Transactions on Information Systems (TOIS), 1990, 8(3): 237-268.

![论文](./vl.png)

以下是完整代码的逻辑说明，以Markdown格式返回：

### 中介者模式示例 - 飞机与塔台交互

这个示例演示了中介者模式的应用，通过一个塔台（`Tower`）作为中介者来协调飞机（`Aircraft`）和跑道（`Runway`）之间的交互。还包括一个特殊的军事飞机（`MilitaryAircraft`），它要求占用所有可用的跑道才能降落和起飞。

#### 中介者接口

```python
class AirTrafficControl:
    def request_land(self, aircraft):
        pass

    def request_takeoff(self, aircraft):
        pass
```

这是中介者接口，定义了飞机请求着陆和起飞的方法。

#### 具体中介者

```python
class Tower(AirTrafficControl):
    def __init__(self):
        self.aircrafts = []  # 存储已着陆的飞机
        self.runways = []   # 存储可用的跑道
        self.waiting_queue = []  # 等待着陆的飞机队列
        self.military_aircrafts = []  # 存储军事飞机

    def request_land(self, aircraft):
        # 处理飞机请求着陆的逻辑
        pass

    def request_takeoff(self, aircraft):
        # 处理飞机请求起飞的逻辑
        pass
```

`Tower` 类是具体的中介者，协调飞机和跑道之间的交互。它维护已着陆的飞机列表、可用的跑道列表、等待队列和军事飞机列表。它实现了飞机请求着陆和起飞的逻辑。

#### 飞机对象

```python
class Aircraft:
    def __init__(self, name):
        self.name = name
        self.current_runway = None  # 记录飞机当前所在的跑道

    def request_land(self):
        # 飞机请求着陆
        pass

    def request_takeoff(self):
        # 飞机请求起飞
        pass
```

`Aircraft` 类表示普通的民用飞机，具有名称和记录当前跑道的功能。它实现了飞机请求着陆和起飞的方法。

#### 跑道对象

```python
class Runway:
    def __init__(self, name):
        self.name = name
        self.is_occupied = False  # 跑道占用状态
        self.is_locked = False    # 跑道锁定状态

    def lock(self):
        # 锁定跑道
        pass

    def unlock(self):
        # 解锁跑道
        pass
```

`Runway` 类表示跑道，具有名称、占用状态和锁定状态。它可以被锁定和解锁。

#### 军事飞机类

```python
class MilitaryAircraft:
    def __init__(self, name):
        self.name = name
        self.current_runway = None  # 记录飞机当前所在的跑道

    def request_land(self):
        # 军事飞机请求着陆
        pass

    def request_takeoff(self):
        # 军事飞机请求起飞
        pass
```

`MilitaryAircraft` 类表示军事飞机，具有名称和记录当前跑道的功能。它要求占用所有可用的跑道才能降落和起飞。

#### 主函数

```python
def main():
    # 创建塔台
    tower = Tower()

    # 创建飞机、跑道和军事飞机
    plane1 = Aircraft("Flight 123")
    plane2 = Aircraft("Flight 456")
    plane3 = Aircraft("Flight 789")
    plane4 = Aircraft("Flight 101")
    runway1 = Runway("Runway 1")
    runway2 = Runway("Runway 2")
    runway3 = Runway("Runway 3")
    military_plane = MilitaryAircraft("Stealth Bomber")

    # 将跑道添加到塔台
    tower.runways.extend([runway1, runway2, runway3])

    # 模拟不同场景下的飞机操作
    # ...

if __name__ == "__main__":
    main()
```

主函数 `main` 创建了塔台和一些飞机、跑道以及军事飞机，然后模拟了不同场景下的飞机操作，包括请求着陆、请求起飞、跑道锁定和解锁等操作。

这个示例演示了中介者模式的应用，通过塔台作为中介者，协调飞机和跑道之间的通信和操作，确保飞机的着陆和起飞按照规定的逻辑进行。同时，军事飞机的特殊要求也得到了满足。