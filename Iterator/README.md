

**Java：**

Java的标准库中有`java.util.Iterator`接口，它通常用于迭代集合类（例如`ArrayList`、`HashSet`等）中的元素。此接口定义了`hasNext()`和`next()`方法。

```java
import java.util.Iterator;

public interface Iterator<E> {
    boolean hasNext();
    E next();
    void remove(); // 可选
}
```

**Python：**

在Python中，没有显式的迭代器接口，但有一些内置方法和魔法方法，用于迭代对象，例如`__iter__()`和`__next__()`方法。

```python
class MyIterator:
    def __iter__(self):
        # return self
        pass

    def __next__(self):
        # return the next item.
        pass
my_iterator = MyIterator()
it = iter(Iterator)
next(it)
next(it)
next(it)
next(it)
next(it)
```

**Rust：**

Rust标准库中的迭代器通常使用`std::iter::Iterator` trait。

```rust
pub trait Iterator {
    type Item;
    fn next(&mut self) -> Option<Self::Item>;
    // 其他方法...
}
```

**Golang：**

Go语言中的迭代通常使用`for`循环，而不是显式的迭代器接口。然而，有一些库和第三方包提供了迭代器模式的实现。

**C++：**

C++标准库中有`std::iterator`类和相关的迭代器类，例如`std::vector::iterator`。但C++的迭代器是使用迭代器范围而不是接口来实现的。
```c++
#include <iostream>
#include <vector>

int main() {
    // 创建一个整数向量
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    // 使用迭代器遍历向量并打印元素
    std::cout << "Vector elements using iterator: ";
    for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    return 0;
}

```