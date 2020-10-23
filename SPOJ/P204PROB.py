n = int(input())
odd_sum = ((n+1)//2)**2
sum = n * (n + 1) // 2
even_sum = sum - odd_sum
print(even_sum - odd_sum)
