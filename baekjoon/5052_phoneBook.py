success = "YES"

class TreeNode:
  def __init__(self, phoneNumber):
    self.next = [ 0 for _ in range(11)]
    if(len(phoneNumber) == 0):
        self.next[-1] = 1
        return
    number = int(phoneNumber[0])
    restNumbers = phoneNumber[1:]
    self.next[number] = TreeNode(restNumbers)

  def insert(self, phoneNumber):
    global success
    if(self.next[-1]):
        success = "NO"
        return
    if(len(phoneNumber) == 0):
        success = "NO"
        return
    number = int(phoneNumber[0])
    restNumbers = phoneNumber[1:]
    if(self.next[number]):
        self.next[number].insert(restNumbers)
    else:
        self.next[number] = TreeNode(restNumbers)
  
def solution():
    global success
    success = "YES"
    N = int(input())
    phoneNumberBook = []

    for _ in range(N):
        phoneNumber = input()
        phoneNumberBook.append(phoneNumber)
    
    root = TreeNode(phoneNumberBook[0])
    for phoneNumber in phoneNumberBook[1:]:
        root.insert(phoneNumber)

T = int(input())
for i in range(T):
    solution()
    print(success)