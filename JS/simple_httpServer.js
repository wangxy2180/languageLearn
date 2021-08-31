const http = require('http')

const hostname = '127.0.0.1'
const port = 3000

const server = http.createServer((req, res) => {
    res.statusCode = 200
    res.setHeader('Content-Type', 'text/plain')
    // 打开浏览器会收到下边这句话
    res.end('hello world\n')
})

server.listen(port, hostname, () => {
    console.log(`服务器运行在 http://${hostname}:${port}/`)
})

// process 不需要require，自动可用
// 加上信号响应，让他正常退出
process.on('SIGINT', () => {
    server.close(() => {
      console.log('进程已终止')
    })
  })
// 发送信号的程序如下
//   process.kill(process.pid, 'SIGTERM')