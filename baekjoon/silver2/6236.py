# input n, m
# n is # of day, m is # of withdraw
n, m = map(int, input().split())

# list of money to spend
money = []
total = 0
for i in range(n):
  a = int(input())
  money.append(a)
  total += a

# binary search
left = 1
right = total
min_k = 0 # minimum k

while (left <= right):
  mid = (left + right) // 2
  current_money = mid # available money
  check = True # check ( today_money < current_money )
  cnt = 1 # # of withdraw

  for value in money:
    # check1. is it possible? (today_money < current_money ?)
    if(value > mid):
      check = False
      break

    # check2. have enough money?
    if(value > current_money):
      current_money = mid
      cnt += 1

    current_money -= value

  # update left and right
  # case1. (today_money > withdraw_money) or (count > M) ?
  if (not check) or (cnt > m):
    left = mid+1

  # otherwise
  else:
    min_k = mid
    right = mid-1

# finish binary search ( = get minimum k )
print(min_k)

