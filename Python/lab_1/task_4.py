W = int(input("Enter capacity: "))
weights = list(map(int, input("Enter weights: ").split()))

knapsack = [1] + [0] * W
temp_knapsack = knapsack[:]

for w in weights:
    for i in range(w, W + 1):
        if knapsack[i - w] == 1:
            temp_knapsack[i] = 1
    knapsack = temp_knapsack[:]

max_weight = W
while not knapsack[max_weight]:
    max_weight -= 1

print("Maximum weight of gold:", max_weight)
