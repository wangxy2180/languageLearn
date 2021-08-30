# https://blog.csdn.net/libizhide/article/details/112230933
# 毫无扩展性，毫无美感可言！

from bs4 import BeautifulSoup
# import time
# import random
import pandas as pd
import urllib.request
# import pymongo
import sys
import re


class Douban():
    def __init__(self):
        self.__r_publisher = r'出版社:</span>(.*?)<br/>'
        self.__r_publish_date = r'出版年:</span>(.*?)<br/>'
        self.headers = {
            'User-Agent': 'Mozilla/5.0 (Windows NT 6.1; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/79.0.3945.88 Safari/537.36'}

    def get_book(self, isbn=""):
        book = {"isbn": isbn}
        html = self.__get_html(isbn=isbn)
        if html == -1:  # 无此书
            return -1
        soup = self.__get_soup(html=html)
        book["name"] = self.__getTitle(soup=soup)
        book["author"] = self.__getAuthor(soup=soup)
        book["intro"] = self.__get_intro(soup=soup)
        book["publisher"] = self.__getpublisher(soup=soup)
        book["publish_date"] = self.__getpublish_date(soup=soup)
        return book

    def __get_html(self, isbn=""):
        url = f"http://douban.com/isbn/{isbn}/"
        request = urllib.request.Request(url, headers=self.headers)
        try:
            response = urllib.request.urlopen(request)
        except:
            return -1
        html = response.read().decode('utf-8')
        return html

    def __get_soup(self, html=""):
        # soup = BeautifulSoup(html, 'lxml', exclude_encodings="utf-8")
        soup = BeautifulSoup(html, 'html.parser', exclude_encodings="utf-8")
        return soup

    def __getTitle(self, soup):
        soupSelect = str(soup.select("body>div>h1>span"))
        # soupTemp = BeautifulSoup(str(soupSelect), 'lxml',
        #                          exclude_encodings="utf-8")       
        soupTemp = BeautifulSoup(str(soupSelect), 'html.parser',
                                 exclude_encodings="utf-8")
        return str(soupTemp.text).strip('[] \n\t')

    def __getAuthor(self, soup):
        soupSelect = str(soup.select(
            "body>div>div>div>div>div>div>div>div>span>a")[0])
        # soupTemp = BeautifulSoup(str(soupSelect), 'lxml',
        #                          exclude_encodings="utf-8")        
        soupTemp = BeautifulSoup(str(soupSelect), 'html.parser',
                                 exclude_encodings="utf-8")
        return str(soupTemp.text).strip()

    def __getpublisher(self, soup):
        soupSelect = str(soup.select(
            "body>div>div>div>div>div>div>div>div"))
        ans = re.findall(self.__r_publisher, soupSelect)
        if len(ans) == 0:
            return ""
        else:
            return str(ans[0]).strip("[] \n\t")

    def __getpublish_date(self, soup):
        soupSelect = str(soup.select(
            "body>div>div>div>div>div>div>div>div"))
        ans = re.findall(self.__r_publish_date, soupSelect)
        if len(ans) == 0:
            return ""
        else:
            return str(ans[0]).strip("[] \n\t")

    def __get_intro(self, soup):
        soupSelect = soup.select(
            "body>div>div>div>div>div>div>span>div>div")
        # soupTemp = BeautifulSoup(str(soupSelect), 'lxml',
                                #  exclude_encodings="utf-8")
        soupTemp = BeautifulSoup(str(soupSelect), 'html.parser',
                                 exclude_encodings="utf-8")
        return str(soupTemp.text).strip("[] \n\t")


if __name__ == "__main__":
    base = Douban()
    print(base.get_book("9787508660752"))

