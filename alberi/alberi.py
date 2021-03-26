#
# alberi in python

class Node:
    def __init__(self, data):
        self.left=None
        self.right=None
        self.data=data
    

    def insert(self,data):
        #confronta il nodo da aggiungere col nodo corrente
        if self.data:
            if self.data>data:
                if self.left is None:
                    self.left=Node(data)
                else:
                    self.left.insert(data)
            elif self.data<data:
                if self.right is None:
                    self.right=Node(data)
                else:
                    self.right.insert(data)
        else: 
            self.data=data
        
        




    def PrintTree(self):
        if self.left:
            self.left.PrintTree()
        print(self.data)
        if self.right:
            self.right.PrintTree()
        
    #metodo di inserimento x aggiungere i nodi

root=Node(12)
root.insert(6)
root.insert(14)
root.insert(3)
root.insert(11)
root.PrintTree()

    

