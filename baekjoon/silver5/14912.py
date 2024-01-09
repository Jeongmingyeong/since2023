# input n, digit
n, digit = map(int, input().split())

count = 0 # frequency of digit

# iterator 1 to n
for i in range(1, n+1):

  # convert int to string
  for a in str(i):
    if int(a) == digit:
      count += 1

# print result
print(count)

