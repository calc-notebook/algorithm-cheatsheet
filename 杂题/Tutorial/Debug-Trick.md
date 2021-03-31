### Debug Trick

**为循坏`i=999`设置断点**

```c++
for(int i = 0; i< 9867; i++) {
    if( i=999 )
        i=i; //设置断点处
    //处理程序
}
```

**堆栈溢出报错**

[VS2010未处理的异常: 0xC00000FD: Stack overflow](http://blog.sciencenet.cn/blog-464042-545322.html)

