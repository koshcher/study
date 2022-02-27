def sum(a, b):
    return a + b

def dif(a, b):
    return a - b

def mul(a, b):
    return a * b

def div(a, b):
    return a / b

isRun = True
while(isRun):
    a = input("first num: ")
    print("[1] +")
    print("[2] -")
    print("[3] *")
    print("[4] /")
    option = input()

    b = input("second num: ")
    if(option == 1):
        print(sum(a, b))
    elif(option == 2):
        print(dif(a, b))
    elif(option == 3):
        print(mul(a, b))
    elif(option == 4):
        print(div(a, b))
    else:
        print("option is incorrect")