# -*- coding:utf-8 -*-
## 线性搜索算法 最小可用 ID
sets = [18, 4, 8, 9, 16, 1, 14, 7, 19, 3, 0, 5, 2, 11, 6]

def linearSearch(sets):
    '''
    for i in range(len(sets)):
        if i not in sets:
            return i
    '''
    i = 1
    while True:
        if i not in sets:
            return i
        i = i + 1

if __name__ == "__main__":
    print(linearSearch(sets))
