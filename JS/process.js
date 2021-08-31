// process不需要require，他是自动可用的

// process设置环境变量，如这个，可以在之前设置为“production”，告知这个是生产环境
process.env.NODE_ENV='production'
console.log(process.env.NODE_ENV)

// 获取命令行参数
process.argv.forEach((val, index) => {
    console.log(`${index}: ${val}`)
  })