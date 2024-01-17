# step1. create pascal triangle
# 1-1. fill with 1 
pascal = [[1 for _ in range(i)] for i in range(1, 31)]

# step2. fill the value (c[n][k] = c[n-1][k-1] + c[n-1][k])
for i in range(2, 30): # i = 2 to 29
  for j in range(1, i): # j = 1 to i
    pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j]

# step3. input n, k
n, k = map(int, input().split())

# step4. print result
print(pascal[n-1][k-1])

