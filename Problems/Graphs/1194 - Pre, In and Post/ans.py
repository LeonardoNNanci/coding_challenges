def make_postorder(low, high):
    global root, postorder
    i = inorder.find(preorder[root])
    root += 1
    if i > low:
        make_postorder(low, i - 1)
    if i < high:
        make_postorder(i + 1, high)
    postorder += inorder[i]


C = int(input())
for _ in range(C):
    root = 0
    postorder = ""
    n, preorder, inorder = input().split()
    make_postorder(0, int(n) - 1)
    print(postorder)
