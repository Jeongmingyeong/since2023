# input n (execute times)
n = int(input())

# execute n times
for _ in range(n):
  leftside = [] # left of cursor
  rightside = [] # right of cursor

  password = input()
  for c in password:
    # backspace : pop from left stack
    if c == '-': 
      # check cursor is at the beginning
      if(leftside):
        leftside.pop()

    # left arrow : move char left stack to right stack
    elif c == '<': 
      if(leftside): # check leftside is empty
        rightside.append(leftside.pop())

    # right arrow : move char right stack to left stack
    elif c == '>':
      if(rightside): # check rightside is empty
        leftside.append(rightside.pop())

    # number or letter : add left stack 
    else:
      leftside.append(c)

  leftside.extend(reversed(rightside))
  print(''.join(leftside))

