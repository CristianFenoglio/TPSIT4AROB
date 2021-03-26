def push_(stack, element):
    stack.append(element)

def pop_(stack):
    return stack.pop()

def main():
    pila=["a", "b", "c", "d"]
    push_(pila, "z")
    print(pila)
    print(pop_(pila))
    print(pila)


if __name__=="__main__":
    main()