left = 0
right = inf #верхняя граница + 1
while right - left > 1:
    middle = (right + left) // 2
    #if middle < ответа
        #left = middle
    #else
        #right = middle
ans = right
