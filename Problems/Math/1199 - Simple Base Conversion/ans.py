while True:
    string = input()
    if string == "-1":
        break
    if string[:2] == "0x":
        print(int(string, 16))
    else:
        print("0x" + hex(int(string)).upper()[2:])
