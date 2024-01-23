# calculate z
def calc_rate(x, y):
  return (100 * y) // x


# input x, y
x, y = map(int, input().split())
z = calc_rate(x, y)

# if z >= 99 then print "-1"
if z >= 99:
  print(-1)

# else find value with binary search
else:
  left = 0
  right = 1000000000
  
  while (left <= right):
    mid = (left + right) // 2
    newz = calc_rate(x+mid, y+mid)
  
    # if z < newz then reduce the number of rounds
    if (z < newz):
      right = mid - 1
  
    # else increase the number of rounds
    else:
      left = mid + 1
  
  print(left)

