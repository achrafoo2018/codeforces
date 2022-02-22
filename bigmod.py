while True:
    try:
        b = input()
        if b == "":
            b = int(input())
        else:
            b = int(b)
        p = int(input())
        m = int(input())
        print(pow(b, p, m))
    except EOFError:
        break
