import requests
import pytesseract
from PIL import Image
from collections import defaultdict

authcodes = ['kger',
             'nmnr',
             'eygg',
             'zsdr',
             'ktpo',
             'egcr',
             'mkfo',
             'uhvz',
             'mocg',
             'uqgr',
             'ohdd',
             'uhez',
             'afsm',
             'atqb',
             'vymv',
             'wqkb',
             'aggg',
             'fbnp',
             'qpny',
             'ggkg',
             'nnnf',
             'eegu',
             'pgvh',
             'bxhd',
             'krme',
             'tgrt',
             'qycz',
             'fuxm',
             'xgst',
             'fmoq',
             'vbhv',
             'qrhc',
             'gepc',
             'dsmy',
             'wxrg',
             'qrfu',
             'bwqr',
             'bfwy',
             'wpyf',
             'hgfq',
             'mvff',
             'gfhp',
             'btsr',
             'kkaq',
             'dxoo',
             'wgfo',
             'dseh',
             'wqyb',
             'yqtr',
             'mdeu'
             ]



success = 0
for i in range(50):
    path = "verifycode"+str(i)+".jpg"
    result = OCR_lmj(path,i)
    print(result + "  " + authcodes[i])
    if result == authcodes[i]:
        success += 1

print("result: " + str(success))

