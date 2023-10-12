from abc import ABC, abstractmethod#Abstract Base Classes 

# Command 接口
class Command(ABC):
    @abstractmethod
    def execute(self):
        pass

# ConcreteCommand 具体命令 - 点餐
class OrderCommand(Command):
    def __init__(self, chef, dish_name):
        self.chef = chef
        self.dish_name = dish_name

    def execute(self):
        self.chef.cook(self.dish_name)

# Receiver 接收者 - 厨师
class Chef:
    def cook(self, dish_name):
        print(f"厨师正在炒菜: {dish_name}")

# Invoker 调用者 - 服务员
class Waiter:
    def __init__(self):
        self.order_list = []

    def take_order(self, command):
        self.order_list.append(command)

    def place_orders(self):
        for order in self.order_list:
            order.execute()
        self.order_list = []

# 客户端代码
if __name__ == "__main__":
    # 创建厨师
    chef = Chef()

    # 创建订单命令
    order1 = OrderCommand(chef, "宫保鸡丁")
    order2 = OrderCommand(chef, "鱼香肉丝")
    order3 = OrderCommand(chef, "回锅肉")

    # 创建服务员
    waiter = Waiter()

    # 客户下单
    waiter.take_order(order1)
    waiter.take_order(order2)
    waiter.take_order(order3)

    # 服务员将订单传递给厨师
    waiter.place_orders()
