ALPHA = "QWERTYUIOPASDFGHJKLZXCVBNM"
alpha = "qwertyuiopasdgfhjklzxcvbnm"

def Caesar(n):
    text = ""
    for i in x:
        if i in alpha:
            i = chr((ord(i) - ord('a') + 26 - n) % 26 + ord('a'))
        elif i in ALPHA:
            i = chr((ord(i) - ord('A') + 26 - n) % 26 + ord('A'))
        text = text + i
    return text


while(True):
    x = input("请输入加密后文本:")
    print()
    for i in range(0,26):
        print(Caesar(i))
    print()
