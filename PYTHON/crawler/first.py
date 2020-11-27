import requests
url = 'http://www.baidu.com'

response=requests.get(url)

# text返回的是str类型，content是bytes类型
# print(response.text)

content=response.content
html = content.decode('utf-8')
# print(html)

# 对于cookie的操作
# 返回的是一个RequestCookieJar对象
cookies = response.cookies
# 将那个对象转为dict
cookies_dict=requests.utils.dict_from_cookiejar(cookies)
# 将dict转为那个对象
print(cookies_dict)
# requests.utils.cookiejar_from_dict()
# 对cookie进行操作，把字典添加到cookiejar
# requests.utils.add_dict_to_cookiejar()

headers = response.headers
print(headers)
