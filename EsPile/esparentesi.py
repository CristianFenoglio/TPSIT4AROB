def push_(stack, element):
    stack.append(element)

def pop_(stack):
    return stack.pop()


def controllo(stringaControllo):
    pilaContr=[]
    dizioPar={")":"(", "]":"[", "}":"{"}
    for p in stringaControllo:
        if p=="(" or p=="[" or p=="{":
            push_(pilaContr, p)
        if p==")" or p=="]" or p=="}":
            
            if pop_(pilaContr)!=dizioPar[p] or len(pilaContr)==0:
                return False
    return True


def main():
    stringaConparentesi=input()
    if controllo(list(stringaConparentesi)):
        print("ok")
    else:
        print("errore nell inserimento delle parentesi")
    



if __name__=="__main__":
    main()