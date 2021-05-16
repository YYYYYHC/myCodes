import requests
from bs4 import BeautifulSoup
import bs4


def getHTMLText(url):
    try:
        r = requests.get(url, timeout=30)
        r.raise_for_status()
        r.encoding = r.apparent_encoding
        return r.text
    except:
        return ""


def fillUnivList(ulist, html):
    soup = BeautifulSoup(html, "html.parser")
    for tr in soup.find('tbody').children:
        if isinstance(tr, bs4.element.Tag):
            tds = tr('td')
            if not ulist.get(tds[2].string):
                ulist[tds[2].string] = []
            ulist[tds[2].string].append([tds[0].string, tds[1].string, tds[4].string])


def printUnivList(per_provinve_list, num):
    tplt = "{0:^10}\t{1:{3}^10}\t{2:^10}"
    print(tplt.format("排名", "学校名称", "总分", chr(12288)))
    if len(per_provinve_list) < num:
        num = len(per_provinve_list)
    for i in range(num):
        u = per_provinve_list[i]
        print(tplt.format(u[0], u[1], u[2], chr(12288)))


def printAllProvince(ulist, num):
    for key in ulist.keys():
        print("-------------------{}---------------------".format(key))
        per_provinve_list = ulist[key]
        printUnivList(per_provinve_list, num)
        print("")


def main():
    uinfo = {}
    url = 'https://www.shanghairanking.cn/rankings/bcur/2020'
    html = getHTMLText(url)
    fillUnivList(uinfo, html)
    printAllProvince(uinfo, 20)


