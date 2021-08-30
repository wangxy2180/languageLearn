# https://blog.csdn.net/libizhide/article/details/112230933

from bs4 import BeautifulSoup
import pandas as pd
import urllib.request
import time
import sys
import re


class Douban():
    def __init__(self):
        self.__r_publisher = r'出版社:</span>(.*?)<br/>'
        self.__r_publish_date = r'出版年:</span>(.*?)<br/>'
        self.__r_pic_link=r'(http.*?jpg)'
        self.headers = {
            'User-Agent': 'Mozilla/5.0 (Windows NT 6.1; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/79.0.3945.88 Safari/537.36'}

    def get_book(self,isbn):
        book = {"isbn": isbn}
        html = self.__get_html(isbn=isbn)
        if html == -1:  # 无此书
            return -1
        soup = self.__get_soup(html=html)
        book["title"] = self.__getTitle(soup=soup)
        book["author"] = self.__getAuthor(soup=soup)
        # book["intro"] = self.__get_intro(soup=soup)
        book["publisher"] = self.__getpublisher(soup=soup)
        book["publish_date"] = self.__getpublish_date(soup=soup)
        self.__get_pic(soup,isbn)
        return book

    def __get_html(self,isbn=""):
        url = f"http://douban.com/isbn/{isbn}/"
        # 构造一个request请求
        request = urllib.request.Request(url, headers=self.headers)
        try:
            response = urllib.request.urlopen(request)
        except:
            return -1
        html = response.read().decode('utf-8')
        return html

    def __get_soup(self,html=""):
        soup = BeautifulSoup(html, features='html.parser', exclude_encodings="utf-8")
        return soup

    def __getTitle(self,soup):
        soupSelect = str(soup.select("body>div>h1>span")[0].get_text())     
        return soupSelect

    def __getAuthor(self,soup):
        pattern=re.compile("作者")
        author=soup.find('span',text=pattern).find_next_siblings()[0].get_text()
        return author 


    def __getpublisher(self,soup):
        # 我尝试用和作者一样的方式解，但是不会，只能用正则匹配了
        # pattern=re.compile("出版社")
        # ele=soup.find('span',text=pattern)
        # 最笨的方法
        # soupSelect = str(soup.select(
        #     "body>div>div>div>div>div>div>div>div"))
        soupSelect = str(soup.select(r'div[id="info"]'))
        ans = re.findall(self.__r_publisher, soupSelect)
        # if len(ans) == 0:
        #     return ""
        # else:
        #     return ans[0].strip(" \n\t")
        return "" if len(ans)==0 else ans[0].strip(" \n\t")
        

    def __getpublish_date(self,soup):
        soupSelect=str(soup.select(r'div[id="info"]'))
        ans = re.findall(self.__r_publish_date, soupSelect)
        return "" if len(ans)==0 else ans[0].strip(" \n\t")
        

    def __get_intro(self,soup):
        # 这个写的可太不对了
        soupSelect = soup.select(
            "body>div>div>div>div>div>div>span>div>div")[0].get_text()
        return soupSelect

    def __get_pic(self,soup,pic_name):
        pic_name=pic_name+'.jpg'
        # link=str(soup.select('img[rel="v:photo"]')[0])
        link=str(soup.select(r'img[title="点击看大图"]')[0])
        link = re.findall(self.__r_pic_link, link)[0]
        link = link.replace('subject/s/public','subject/l/public')

        req_img = urllib.request.Request(link,headers=self.headers)
        pic_data=urllib.request.urlopen(req_img)
        with open(pic_name,'wb') as f:
            f.write(pic_data.read())
        return 0


if __name__ == "__main__":
    base = Douban()
    print(base.get_book("9787508660752"))
    print(base.get_book("9787532178919"))

