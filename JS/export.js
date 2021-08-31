// 如果要自己写一些库，那么要把这个东西给暴露出来
const car = {
    brand: 'Ford',
    model: 'Fiesta'
}
module.exports = car
//在另一个文件中
const car = require('./car')



/////////////////////////////////////////////////
//   或者第二种
const car = {
    brand: 'Ford',
    model: 'Fiesta'
}
exports.car = car
//   第二种还可以写成

exports.car = {
    brand: 'Ford',
    model: 'Fiesta'
}

//   然后在另一个文件中
const items = require('./items')
items.car
// 或者
const car = require('./items').car