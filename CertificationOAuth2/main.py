#!/usr/bin/python3

import time
from html.parser import HTMLParser
import requests
import xlrd
import xlwt
import math
import pytesseract
from PIL import Image

userAgent = ["Mozilla/5.0 (Macintosh; Intel Mac OS X 10_10_1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/41.0.2227.1 Safari/537.36",
      "Mozilla/5.0 (Windows NT 6.1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/41.0.2228.0 Safari/537.36",
      "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/41.0.2227.0 Safari/537.36",
      "Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/41.0.2227.0 Safari/537.36",
      "Mozilla/5.0 (Windows NT 6.3; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/41.0.2226.0 Safari/537.36",
      "Mozilla/5.0 (Windows NT 6.4; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/41.0.2225.0 Safari/537.36",
      "Mozilla/5.0 (Windows NT 6.3; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/41.0.2225.0 Safari/537.36",
      "Mozilla/5.0 (Windows NT 5.1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/41.0.2224.3 Safari/537.36",
      "Mozilla/5.0 (Windows NT 10.0) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/40.0.2214.93 Safari/537.36",
      "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_10_1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/37.0.2062.124 Safari/537.36",
      "Mozilla/5.0 (Windows NT 6.3; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/37.0.2049.0 Safari/537.36",
      "Mozilla/5.0 (Windows NT 4.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/37.0.2049.0 Safari/537.36",
      "Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/36.0.1985.67 Safari/537.36",
      "Mozilla/5.0 (Windows NT 5.1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/36.0.1985.67 Safari/537.36",
      "Mozilla/5.0 (X11; OpenBSD i386) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/36.0.1985.125 Safari/537.36",
      "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_9_2) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/36.0.1944.0 Safari/537.36",
      "Mozilla/5.0 (Windows NT 5.1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/35.0.3319.102 Safari/537.36",
      "Mozilla/5.0 (Windows NT 5.1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/35.0.2309.372 Safari/537.36",
      "Mozilla/5.0 (Windows NT 5.1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/35.0.2117.157 Safari/537.36",
      "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_9_3) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/35.0.1916.47 Safari/537.36",
      "Mozilla/5.0 (Windows NT 5.1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/34.0.1866.237 Safari/537.36",
      "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/34.0.1847.137 Safari/4E423F",
      "Mozilla/5.0 (Windows NT 5.1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/34.0.1847.116 Safari/537.36 Mozilla/5.0 (iPad; U; CPU OS 3_2 like Mac OS X; en-us) AppleWebKit/531.21.10 (KHTML, like Gecko) Version/4.0.4 Mobile/7B334b Safari/531.21.10",
      "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/33.0.1750.517 Safari/537.36",
      "Mozilla/5.0 (Windows NT 6.2; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/32.0.1667.0 Safari/537.36",
      "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_9_0) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/32.0.1664.3 Safari/537.36",
      "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_8_0) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/32.0.1664.3 Safari/537.36",
      "Mozilla/5.0 (Windows NT 5.1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/31.0.1650.16 Safari/537.36",
      "Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/31.0.1623.0 Safari/537.36",
      "Mozilla/5.0 (Windows NT 6.2; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/30.0.1599.17 Safari/537.36",
      "Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/29.0.1547.62 Safari/537.36",
      "Mozilla/5.0 (X11; CrOS i686 4319.74.0) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/29.0.1547.57 Safari/537.36",
      "Mozilla/5.0 (Windows NT 6.2; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/29.0.1547.2 Safari/537.36",
      "Mozilla/5.0 (Windows NT 6.1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/28.0.1468.0 Safari/537.36",
      "Mozilla/5.0 (Windows NT 6.2) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/28.0.1467.0 Safari/537.36",
      "Mozilla/5.0 (Windows NT 6.2) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/28.0.1464.0 Safari/537.36",
      "Mozilla/5.0 (Windows NT 6.2; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/27.0.1500.55 Safari/537.36",
      "Mozilla/5.0 (Windows NT 6.2; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/27.0.1453.93 Safari/537.36",
      "Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/27.0.1453.93 Safari/537.36",
      "Mozilla/5.0 (Windows NT 6.1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/27.0.1453.93 Safari/537.36",
      "Mozilla/5.0 (Windows NT 5.1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/27.0.1453.93 Safari/537.36",
      "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_8_3) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/27.0.1453.93 Safari/537.36",
      "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_7_5) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/27.0.1453.93 Safari/537.36",
      "Mozilla/5.0 (Windows NT 6.1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/27.0.1453.90 Safari/537.36",
      "Mozilla/5.0 (X11; NetBSD) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/27.0.1453.116 Safari/537.36",
      "Mozilla/5.0 (X11; CrOS i686 3912.101.0) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/27.0.1453.116 Safari/537.36",
      "Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.17 (KHTML, like Gecko) Chrome/24.0.1312.60 Safari/537.17",
      "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_8_2) AppleWebKit/537.17 (KHTML, like Gecko) Chrome/24.0.1309.0 Safari/537.17",
      "Mozilla/5.0 (Windows NT 6.2; WOW64) AppleWebKit/537.15 (KHTML, like Gecko) Chrome/24.0.1295.0 Safari/537.15",
      "Mozilla/5.0 (Windows NT 6.2; WOW64) AppleWebKit/537.14 (KHTML, like Gecko) Chrome/24.0.1292.0 Safari/537.14",
             "Opera/9.80 (X11; Linux i686; Ubuntu/14.10) Presto/2.12.388 Version/12.16",
             "Opera/9.80 (Windows NT 6.0) Presto/2.12.388 Version/12.14",
             "Mozilla/5.0 (Windows NT 6.0; rv:2.0) Gecko/20100101 Firefox/4.0 Opera 12.14",
             "Mozilla/5.0 (compatible; MSIE 9.0; Windows NT 6.0) Opera 12.14",
             "Opera/12.80 (Windows NT 5.1; U; en) Presto/2.10.289 Version/12.02",
             "Opera/9.80 (Windows NT 6.1; U; es-ES) Presto/2.9.181 Version/12.00",
             "Opera/9.80 (Windows NT 5.1; U; zh-sg) Presto/2.9.181 Version/12.00",
             "Opera/12.0(Windows NT 5.2;U;en)Presto/22.9.168 Version/12.00",
             "Opera/12.0(Windows NT 5.1;U;en)Presto/22.9.168 Version/12.00",
             "Mozilla/5.0 (Windows NT 5.1) Gecko/20100101 Firefox/14.0 Opera/12.0",
             "Opera/9.80 (Windows NT 6.1; WOW64; U; pt) Presto/2.10.229 Version/11.62",
             "Opera/9.80 (Windows NT 6.0; U; pl) Presto/2.10.229 Version/11.62",
             "Opera/9.80 (Macintosh; Intel Mac OS X 10.6.8; U; fr) Presto/2.9.168 Version/11.52",
             "Opera/9.80 (Macintosh; Intel Mac OS X 10.6.8; U; de) Presto/2.9.168 Version/11.52",
             "Opera/9.80 (Windows NT 5.1; U; en) Presto/2.9.168 Version/11.51",
             "Mozilla/5.0 (compatible; MSIE 9.0; Windows NT 6.1; de) Opera 11.51",
             "Opera/9.80 (X11; Linux x86_64; U; fr) Presto/2.9.168 Version/11.50",
             "Opera/9.80 (X11; Linux i686; U; hu) Presto/2.9.168 Version/11.50",
             "Opera/9.80 (X11; Linux i686; U; ru) Presto/2.8.131 Version/11.11",
             "Opera/9.80 (X11; Linux i686; U; es-ES) Presto/2.8.131 Version/11.11",
             "Mozilla/5.0 (Windows NT 5.1; U; en; rv:1.8.1) Gecko/20061208 Firefox/5.0 Opera 11.11",
             "Opera/9.80 (X11; Linux x86_64; U; bg) Presto/2.8.131 Version/11.10",
             "Opera/9.80 (Windows NT 6.0; U; en) Presto/2.8.99 Version/11.10",
             "Opera/9.80 (Windows NT 5.1; U; zh-tw) Presto/2.8.131 Version/11.10",
             "Opera/9.80 (Windows NT 6.1; Opera Tablet/15165; U; en) Presto/2.8.149 Version/11.1",
             "Opera/9.80 (X11; Linux x86_64; U; Ubuntu/10.10 (maverick); pl) Presto/2.7.62 Version/11.01",
             "Opera/9.80 (X11; Linux i686; U; ja) Presto/2.7.62 Version/11.01",
             "Opera/9.80 (X11; Linux i686; U; fr) Presto/2.7.62 Version/11.01",
             "Opera/9.80 (Windows NT 6.1; U; zh-tw) Presto/2.7.62 Version/11.01",
             "Opera/9.80 (Windows NT 6.1; U; zh-cn) Presto/2.7.62 Version/11.01",
             "Opera/9.80 (Windows NT 6.1; U; sv) Presto/2.7.62 Version/11.01",
             "Opera/9.80 (Windows NT 6.1; U; en-US) Presto/2.7.62 Version/11.01",
             "Opera/9.80 (Windows NT 6.1; U; cs) Presto/2.7.62 Version/11.01",
             "Opera/9.80 (Windows NT 6.0; U; pl) Presto/2.7.62 Version/11.01",
             "Opera/9.80 (Windows NT 5.2; U; ru) Presto/2.7.62 Version/11.01",
             "Opera/9.80 (Windows NT 5.1; U;) Presto/2.7.62 Version/11.01",
             "Opera/9.80 (Windows NT 5.1; U; cs) Presto/2.7.62 Version/11.01",
             "Mozilla/5.0 (Windows; U; Windows NT 6.1; en-US; rv:1.9.2.13) Gecko/20101213 Opera/9.80 (Windows NT 6.1; U; zh-tw) Presto/2.7.62 Version/11.01",
             "Mozilla/5.0 (Windows NT 6.1; U; nl; rv:1.9.1.6) Gecko/20091201 Firefox/3.5.6 Opera 11.01",
             "Mozilla/5.0 (Windows NT 6.1; U; de; rv:1.9.1.6) Gecko/20091201 Firefox/3.5.6 Opera 11.01",
             "Mozilla/4.0 (compatible; MSIE 8.0; Windows NT 6.1; de) Opera 11.01",
             "Opera/9.80 (X11; Linux x86_64; U; pl) Presto/2.7.62 Version/11.00",
             "Opera/9.80 (X11; Linux i686; U; it) Presto/2.7.62 Version/11.00",
             "Opera/9.80 (Windows NT 6.1; U; zh-cn) Presto/2.6.37 Version/11.00",
             "Opera/9.80 (Windows NT 6.1; U; pl) Presto/2.7.62 Version/11.00",
             "Opera/9.80 (Windows NT 6.1; U; ko) Presto/2.7.62 Version/11.00",
             "Opera/9.80 (Windows NT 6.1; U; fi) Presto/2.7.62 Version/11.00",
             "Opera/9.80 (Windows NT 6.1; U; en-GB) Presto/2.7.62 Version/11.00",
             "Opera/9.80 (Windows NT 6.1 x64; U; en) Presto/2.7.62 Version/11.00",
             "Opera/9.80 (Windows NT 6.0; U; en) Presto/2.7.39 Version/11.00",
      "Mozilla/5.0 (Windows NT 6.1; WOW64; rv:40.0) Gecko/20100101 Firefox/40.1",
      "Mozilla/5.0 (Windows NT 6.3; rv:36.0) Gecko/20100101 Firefox/36.0",
      "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_10; rv:33.0) Gecko/20100101 Firefox/33.0",
      "Mozilla/5.0 (X11; Linux i586; rv:31.0) Gecko/20100101 Firefox/31.0",
      "Mozilla/5.0 (Windows NT 6.1; WOW64; rv:31.0) Gecko/20130401 Firefox/31.0",
      "Mozilla/5.0 (Windows NT 5.1; rv:31.0) Gecko/20100101 Firefox/31.0",
      "Mozilla/5.0 (Windows NT 6.1; WOW64; rv:29.0) Gecko/20120101 Firefox/29.0",
      "Mozilla/5.0 (Windows NT 6.1; Win64; x64; rv:25.0) Gecko/20100101 Firefox/29.0",
      "Mozilla/5.0 (X11; OpenBSD amd64; rv:28.0) Gecko/20100101 Firefox/28.0",
      "Mozilla/5.0 (X11; Linux x86_64; rv:28.0) Gecko/20100101  Firefox/28.0",
      "Mozilla/5.0 (Windows NT 6.1; rv:27.3) Gecko/20130101 Firefox/27.3",
      "Mozilla/5.0 (Windows NT 6.2; Win64; x64; rv:27.0) Gecko/20121011 Firefox/27.0",
      "Mozilla/5.0 (Windows NT 6.1; Win64; x64; rv:25.0) Gecko/20100101 Firefox/25.0",
      "Mozilla/5.0 (Macintosh; Intel Mac OS X 10.6; rv:25.0) Gecko/20100101 Firefox/25.0",
      "Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:24.0) Gecko/20100101 Firefox/24.0",
      "Mozilla/5.0 (Windows NT 6.0; WOW64; rv:24.0) Gecko/20100101 Firefox/24.0",
      "Mozilla/5.0 (Macintosh; Intel Mac OS X 10.8; rv:24.0) Gecko/20100101 Firefox/24.0",
      "Mozilla/5.0 (Windows NT 6.2; rv:22.0) Gecko/20130405 Firefox/23.0",
      "Mozilla/5.0 (Windows NT 6.1; WOW64; rv:23.0) Gecko/20130406 Firefox/23.0",
      "Mozilla/5.0 (Windows NT 6.1; Win64; x64; rv:23.0) Gecko/20131011 Firefox/23.0",
      "Mozilla/5.0 (Windows NT 6.2; rv:22.0) Gecko/20130405 Firefox/22.0",
      "Mozilla/5.0 (Windows NT 6.1; Win64; x64; rv:22.0) Gecko/20130328 Firefox/22.0",
      "Mozilla/5.0 (Windows NT 6.1; rv:22.0) Gecko/20130405 Firefox/22.0",
      "Mozilla/5.0 (Microsoft Windows NT 6.2.9200.0); rv:22.0) Gecko/20130405 Firefox/22.0",
      "Mozilla/5.0 (Windows NT 6.2; Win64; x64; rv:16.0.1) Gecko/20121011 Firefox/21.0.1",
      "Mozilla/5.0 (Windows NT 6.1; Win64; x64; rv:16.0.1) Gecko/20121011 Firefox/21.0.1",
      "Mozilla/5.0 (Windows NT 6.2; Win64; x64; rv:21.0.0) Gecko/20121011 Firefox/21.0.0",
      "Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:21.0) Gecko/20130331 Firefox/21.0",
      "Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:21.0) Gecko/20100101 Firefox/21.0",
      "Mozilla/5.0 (X11; Linux i686; rv:21.0) Gecko/20100101 Firefox/21.0",
      "Mozilla/5.0 (Windows NT 6.2; WOW64; rv:21.0) Gecko/20130514 Firefox/21.0",
      "Mozilla/5.0 (Windows NT 6.2; rv:21.0) Gecko/20130326 Firefox/21.0",
      "Mozilla/5.0 (Windows NT 6.1; WOW64; rv:21.0) Gecko/20130401 Firefox/21.0",
      "Mozilla/5.0 (Windows NT 6.1; WOW64; rv:21.0) Gecko/20130331 Firefox/21.0",
      "Mozilla/5.0 (Windows NT 6.1; WOW64; rv:21.0) Gecko/20130330 Firefox/21.0",
      "Mozilla/5.0 (Windows NT 6.1; WOW64; rv:21.0) Gecko/20100101 Firefox/21.0",
      "Mozilla/5.0 (Windows NT 6.1; rv:21.0) Gecko/20130401 Firefox/21.0",
      "Mozilla/5.0 (Windows NT 6.1; rv:21.0) Gecko/20130328 Firefox/21.0",
      "Mozilla/5.0 (Windows NT 6.1; rv:21.0) Gecko/20100101 Firefox/21.0",
      "Mozilla/5.0 (Windows NT 5.1; rv:21.0) Gecko/20130401 Firefox/21.0",
      "Mozilla/5.0 (Windows NT 5.1; rv:21.0) Gecko/20130331 Firefox/21.0",
      "Mozilla/5.0 (Windows NT 5.1; rv:21.0) Gecko/20100101 Firefox/21.0",
      "Mozilla/5.0 (Windows NT 5.0; rv:21.0) Gecko/20100101 Firefox/21.0",
      "Mozilla/5.0 (Macintosh; Intel Mac OS X 10.8; rv:21.0) Gecko/20100101 Firefox/21.0",
      "Mozilla/5.0 (Windows NT 6.2; Win64; x64;) Gecko/20100101 Firefox/20.0",
      "Mozilla/5.0 (Windows x86; rv:19.0) Gecko/20100101 Firefox/19.0",
      "Mozilla/5.0 (Windows NT 6.1; rv:6.0) Gecko/20100101 Firefox/19.0",
      "Mozilla/5.0 (Windows NT 6.1; rv:14.0) Gecko/20100101 Firefox/18.0.1",
      "Mozilla/5.0 (Windows NT 6.1; WOW64; rv:18.0)  Gecko/20100101 Firefox/18.0",
      "Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:17.0) Gecko/20100101 Firefox/17.0.6"
             ]



class MyHTMLParser(HTMLParser):

    def __init__(self):
        HTMLParser.__init__(self)
        self.certicationInfos = []
        self.tmpStr = ''
        self.enterCertificationInfo = False
        self.enterTBody = False
        self.enterTD = False

    def handle_starttag(self, tag, attrs):
        if tag == 'table':
            self.enterTBody = True
        elif self.enterCertificationInfo == True and tag == 'td' and len(attrs) == 0:
            self.enterTD = True

    def handle_data(self, data):
        if self.enterTBody == True and data == '证书信息':
            self.enterCertificationInfo = True
            self.tmpStr = ''
        elif self.enterTD == True:
            self.tmpStr += " "
            self.tmpStr += data

    def handle_endtag(self, tag):
        if tag == 'td':
            self.enterTD = False
        elif tag == 'table':
            self.enterTBody = False
            if self.enterCertificationInfo == True:
                self.enterCertificationInfo = False
                self.certicationInfos.append(self.tmpStr)
                self.tmpStr = ''

class MyHTMLParser1(HTMLParser):

    def __init__(self):
        HTMLParser.__init__(self)
        self.req = ''
        self.reqIP = ''

    def handle_starttag(self, tag, attrs):
        if tag == 'input':
            if ('name','req') in attrs:
                for tmp in attrs:
                    if tmp[0] == 'value':
                        self.req = tmp[1]
            elif ('name','reqIP') in attrs:
                for tmp in attrs:
                    if tmp[0] == 'value':
                        self.reqIP = tmp[1]



def requestAndAnalyseVerifyCode(cookies,index):
    print("解析验证码：")
    url = 'http://zscx.osta.org.cn/jiandingApp/verifycode'
    header = {'Referer': 'http://zscx.osta.org.cn/jiandingApp/command/buzhongxin/ecCertSearchAllq',
              'User-Agent': userAgent[index % len(userAgent)],
              'Accept': 'image/avif,image/webp,image/apng,image/*,*/*;q=0.8',
              'Accept-Encoding': 'gzip, deflate',
              'Accept-Language':'zh-CN,zh;q=0.9,en;q=0.8'}
    result = requests.get(url,headers=header,cookies=cookies)
    if result.status_code == 200:
        open('verifycode.jpg','wb').write(result.content)
        img = Image.open("verifycode.jpg")
        result = pytesseract.image_to_string(img)
        result = ''.join(result.split())
        return result
    else:
        return "false"



def sendRealRequest(cardId,name,index,hasVerifyCode,verfifyCode,cookies,req,reqIP):

    if hasVerifyCode:
        url = 'http://zscx.osta.org.cn/jiandingApp/command/buzhongxin/ecCertSearchAllq'
        header = {'Referer': 'http://zscx.osta.org.cn/',
                  'Origin': 'http://zscx.osta.org.cn',
                  'Content-Type': 'application/x-www-form-urlencoded',
                  'User-Agent': userAgent[index % len(userAgent)],
                  'Accept': '*/*',
                  'Cache_Control': 'no-cache'}
        params = {'req':req,
                  'reqIP':reqIP,
                  'templetId':'',
                  'async':False,
                  'PortID':'',
                  'tableName': 'CERT_T',
                  'tableName1': '000000',
                  'CertificateID': '',
                  'CID': cardId,
                  'Name': name,
                  'x': '137',
                  'y': '24',
                  'province': '-1',
                  'verifyCode':verfifyCode,
                  'imageField.x':33,
                  'imageField.y':12}

    else:
        url = 'http://zscx.osta.org.cn/jiandingApp/command/buzhongxin/ecCertSearchAll'
        header = {'Referer': 'http://zscx.osta.org.cn/',
                  'Origin': 'http://zscx.osta.org.cn',
                  'Content-Type': 'application/x-www-form-urlencoded',
                  'User-Agent': userAgent[index % len(userAgent)],
                  'Accept': '*/*',
                  'Cache_Control': 'no-cache'}
        params = {'tableName': 'CERT_T',
                  'tableName1': '000000',
                  'CertificateID': '',
                  'CID': cardId,
                  'Name': name,
                  'x': '137',
                  'y': '24',
                  'province': '-1'}

    try:
        if hasVerifyCode:
            result = requests.post(url, data=params, headers=header,cookies=cookies,timeout=60)
        else:
            result = requests.post(url, data=params, headers=header,timeout=60)
    except Exception:
        return (False,"")
    else:
        if result.status_code == 200:
            return (True, result)
        else:
            return (False, result)


def sendRequest(cardId,name,index):
    repeatCount = 0
    hasVerify = False
    verifyCode = ""
    cookies = {}
    req = ''
    reqIP = ''

    while(True):

        if repeatCount > 3:
            print("重试4次，仍然失败，结束重试")
            return (False,["查询失败"])

        print("\n")

        time.sleep(math.pow(3,repeatCount))

        print("查询：")

        resultTuple = sendRealRequest(cardId=cardId,name=name,index=index,hasVerifyCode=hasVerify,verfifyCode=verifyCode,cookies=cookies,req=req,reqIP=reqIP)

        if resultTuple[0] == True:
            result = resultTuple[1]
            if result.text.find("证书信息") != -1:
                parser = MyHTMLParser()
                parser.feed(data=result.text)
                print(parser.certicationInfos)
                return (True,parser.certicationInfos)
            elif result.text.find("对不起，没有查到相关信息") != -1:
                print("没有证书")
                return (True, ["没有证书"])
            elif result.text.find("请输入验证码") != -1:
                print("需要输入验证码")
                tmpcookies = requests.utils.dict_from_cookiejar(result.cookies)
                if len(tmpcookies) > 0:
                    cookies = tmpcookies
                parser = MyHTMLParser1()
                parser.feed(data=result.text)
                req = parser.req
                reqIP = parser.reqIP
                verifyCode = requestAndAnalyseVerifyCode(cookies,index)
                repeatCount += 1
                if "false" == verifyCode:
                    print("验证码解析失败，等待重试")
                else:
                    print("验证码解析成功:"+verifyCode)
                    hasVerify = True
                    verifyCode = verifyCode
            else:
                hasVerify = False
                print("查询失败，等待重试")
                repeatCount += 1
        else:
            hasVerify = False
            print("查询失败，等待重试")
            repeatCount += 1






if __name__ == "__main__":

    while (True):
        try:
            filePath = input("请输入Excel文件路径：")
            print("您输入的文件路径是：", filePath)
            workBook = xlrd.open_workbook(filePath)
        except FileNotFoundError:
            print("文件不存在，请重新输入\n")
        else:
            break

    worksheet = workBook.sheet_by_index(0)
    outWorkBook = xlwt.Workbook(encoding='utf-8')
    outWorksheet = outWorkBook.add_sheet('sheet1')

    timeStart = time.time()
    successCount = 0
    failedCount = 0

    print("当前共有" + str(worksheet.nrows) + "条数据待处理，请等待......")

    for index in range(worksheet.nrows):

        print("\n")
        cardId = str(worksheet.cell(index, 0).value)
        name = str(worksheet.cell(index, 1).value)
        print(cardId + " " + name)

        result = sendRequest(cardId,name,index)

        outWorksheet.write(index, 0, cardId)
        outWorksheet.write(index, 1, name)
        for cerIndex in range(len(result[1])):
            outWorksheet.write(index, 2 + cerIndex, result[1][cerIndex])

        if result[0] == True:
            successCount += 1
        else:
            failedCount += 1


    outWorkBook.save("result.xlsx")

    endTime = time.time()

    print("\n\n查询结束，共查询"+str(worksheet.nrows)+"条记录，成功"+str(successCount)+"条，失败"+str(failedCount)+"条，用时"+str(endTime - timeStart)+"秒" )
