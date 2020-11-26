import requests


def requestAndGetCookies():
    url = 'http://ywzl.hrss.henan.gov.cn/chaxun/toGetZhicheng.do'
    header = {'User-Agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_10_1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/41.0.2227.1 Safari/537.36',
              'Accept': '*/*',
              'Accept-Encoding': 'gzip, deflate',
              'Accept-Language':'zh-cn'}
    result = requests.get(url,headers=header)
    if result.status_code == 200:
        print(result.cookies)
        cookies = requests.utils.dict_from_cookiejar(result.cookies)
        return cookies
    else:
        print("false")


def getAuthCodeImage(cookies):
    url = 'http://ywzl.hrss.henan.gov.cn/cmsform/rand.jsp'
    header = {'Referer': 'http://ywzl.hrss.henan.gov.cn/chaxun/toGetZhicheng.do',
              'User-Agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_10_1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/41.0.2227.1 Safari/537.36',
              'Accept': 'image/png,image/svg+xml,image/*;q=0.8,video/*;q=0.8,*/*;q=0.5',
              'Accept-Encoding': 'gzip, deflate',
              'Accept-Language':'zh-cn'}
    result = requests.get(url,headers=header,cookies=cookies)
    if result.status_code == 200:
        open('verifycode.jpg','wb').write(result.content)
        return 'true'
    else:
        return "false"

def getCerticaitionInfo(cookies,authCode):
    url = 'http://ywzl.hrss.henan.gov.cn/chaxun/getZhicheng.do'
    header = {'Referer': 'http://ywzl.hrss.henan.gov.cn/chaxun/toGetZhicheng.do',
              'Origin': 'http://ywzl.hrss.henan.gov.cn',
              'User-Agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_10_1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/41.0.2227.1 Safari/537.36',
              'Accept': 'application/json, text/javascript, */*; q=0.01',
              'Accept-Encoding': 'gzip, deflate',
              'Accept-Language':'zh-cn',
              'X-Requested-With':'XMLHttpRequest',
              'Content-Type':'application/x-www-form-urlencoded; charset=UTF-8'}
    params = {'name':'杨拴柱',
              'idCar':'412929196711271913',
              'type': 1 ,
              'random':authCode}
    result = requests.post(url,params=params,headers=header,cookies=cookies,timeout=60)
    if result.status_code == 200:
        print(result.content)
        return 'true'
    else:
        return "false"

cookies = requestAndGetCookies()
getAuthCodeImage(cookies)

authCode = 'gpgg'
getCerticaitionInfo(cookies,authCode)
