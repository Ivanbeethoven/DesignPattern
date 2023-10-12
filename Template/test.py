# 抽象测试用例类
class AbstractTestCase:
    def runTest(self):
        self.setUp()  # 执行测试前的准备工作
        self.test()   # 执行具体的测试逻辑
        self.tearDown()  # 执行测试后的清理工作

    def setUp(self):
        pass# 执行测试前的准备工作，例如初始化测试数据

    def test(self):
        pass# 具体的测试逻辑，由子类实现

    def tearDown(self):
        pass# 执行测试后的清理工作，例如释放资源

# 具体测试用例类
class AdditionTestCase(AbstractTestCase):
    def test(self):
        result = 2 + 2
        assert result == 4, "Addition failed"

class SubtractionTestCase(AbstractTestCase):
    def test(self):
        result = 5 - 3
        assert result == 2, "Subtraction failed"

# 测试执行器
class TestRunner:
    def run(self):
        test_cases = [AdditionTestCase(), SubtractionTestCase()]
        for test_case in test_cases:
            test_case.runTest()
            print("test class pass ",test_case.__class__)

if __name__ == "__main__":
    runner = TestRunner()
    runner.run()
