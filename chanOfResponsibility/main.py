# 定义一个处理器基类
class Handler:
    def __init__(self, successor=None):
        self.successor = successor
    # 传递
    def handle_request(self, request):
        if self.successor:
            self.successor.handle_request(request)
            
# 具体处理器类
class ConcreteHandler1(Handler):
    def handle_request(self, request):
        if request == "Request1":
            print("ConcreteHandler1 处理请求")
        else:
            super().handle_request(request)

class ConcreteHandler2(Handler):
    def handle_request(self, request):
        if request == "Request2":
            print("ConcreteHandler2 处理请求")
        else:
            super().handle_request(request)

class ConcreteHandler3(Handler):
    def handle_request(self, request):
        if request == "Request3":
            print("ConcreteHandler3 处理请求")
        else:
            print("无法处理请求")

# 客户端代码
if __name__ == "__main__":
    handler1 = ConcreteHandler1()
    handler2 = ConcreteHandler2()
    handler3 = ConcreteHandler3()

    handler1.successor = handler2
    handler2.successor = handler3

    requests = ["Request1", "Request2", "Request3", "Request4"]

    for request in requests:
        handler1.handle_request(request)
