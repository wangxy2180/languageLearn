from bs4 import BeautifulSoup
import bs4

# https://cuiqingcai.com/1319.html

html = """
<html><head><title>The Dormouse's story</title></head>
<body>
<p class="title" name="dromouse"><b>The Dormouse's story</b></p>
<p class="story">Once upon a time there were three little sisters; and their names were
<a href="http://example.com/elsie" class="sister" id="link1"><!-- Elsie --></a>,
<a href="http://example.com/lacie" class="sister" id="link2">Lacie</a> and
<a href="http://example.com/tillie" class="sister" id="link3">Tillie</a>;
and they lived at the bottom of a well.</p>
<p class="story">...</p>
"""

# 如果没有这个features来显式指定，他自己选择html解析器并会有警告，
soup = BeautifulSoup(html,features="html.parser")
# 或者可以通过打开文件的形式
# soup=BeautifulSoup(open('test.html'))
# 单纯的打印soup就是字符串信息，这个是格式化后的,soup这个对象本身就是document
print(soup.prettify())
print('1-----------------------')


# Beautiful Soup 将复杂 HTML 文档转换成一个复杂的树形结构，每个节点都是 Python 对象，所有对象可以归纳为 4 种:

# soup包含四种类类型，NavigableString，BeautifulSoup，Comment，tag。
# 1.Tag，只会查找第一个标签
print('title tag:',soup.title)
print('a tag    :',soup.a)
# 输出数据的类型看一下
print('type is  :',type(soup.a))
# 打印其内部的属性，字典格式
print('attrs is :',soup.a.attrs)
print('href attr:',soup.a.attrs['href'])
print('get attr :',soup.p.get('name'))
# 也可以对名称进行修改，甚至删除
soup.p['name']='testchange'
print('get attr :',soup.p.get('name'))
print('2-----------------------')

# 2.想要获取标签内部的文字呢，这就是NavigableString
print('navi str :',soup.title.string)
print('3-----------------------')

# 3.BeautifulSoup
# 就是指该文档的全部内容，上边已经说过了

# 4.comment
# Comment 对象是一个特殊类型的 NavigableString 对象，其实输出的内容仍然不包括注释符号，
# 但是如果不好好处理它，可能会对我们的文本处理造成意想不到的麻烦。 我们找一个带注释的标签
print('navi str :',soup.a.string)
# 最好先做一个判断
if type(soup.a.string)==bs4.element.Comment:
    print('comment  :',soup.a.string)
print('4-----------------------')

# 5.contents与children属性
# contents：将tag的子节点以列表方式输出
print('contents:',soup.body.contents)
print()
# children直接打印是没有内容的，需要循环遍历
print('children:',soup.body.children)
for child in soup.body.children:
    print('child:',child)
print('5-----------------------')

# 6.获取多个标签中的内容
# 如果只是单纯的 .strings 会输出很多空格回车啥的，改成这个就没有了
for string in soup.stripped_strings:
    print('stripped_strings:',string)

print('6-----------------------')
# 搜索文档树,可以使用正则表达式，list
print('find_all:',soup.find_all('b'))
# 使用id搜索
print('find_all:',soup.find_all(id='link2'))
# class过滤，要加一个下划线哦
print('find_all:',soup.find_all(class_='sister'))
# 通过text进行查找
print('find_all:',soup.find_all(text='Tillie'))

# 7. css选择器
print('7-----------------------')
# 通过类名，标签名，id名
print('select1 :',soup.select('a'))
print('select2 :',soup.select('.sister'))
print('select3 :',soup.select('#link1'))
# 组合查找
print('select4 :',soup.select('p #link1'))
# 直接查找子标签
print('select5 :',soup.select('head>title'))
# 属性查找
print('select6 :',soup.select('a[class="sister"]'))
# 组合+属性查找
print('select7 :',soup.select('p a[class="sister"]'))
# 通过text内容查找

# 获取标签中的内容
print('select8 :',soup.select('p a[class="sister"]')[1].get_text())
# 通过遍历输出select内容
for title in soup.select('p a[class="sister"]'):
    print(title.get_text())
