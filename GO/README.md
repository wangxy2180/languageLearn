# GO

go的三种运行方式
1. 使用源码直接运行
```go
go run hello.go
```
2. 构建成可执行文件，再运行
```go
go build hello.go
./hello
```

~~需要设置一个`GOPATH`，只要把它放在`src`文件夹下就行~~

这两个文件都是在`package main`中

运行方法
```go
go run hello.go basic_grammar.go
```

构造方法
```go
go build hello.go basic_grammar.go
```