def build(low, high):
    global root, postorder
    i = inorder.index(preorder[root])
    root += 1
    if low < i:
        build(low, i - 1)
    if i < high:
        build(i + 1, high)
    postorder += inorder[i]


while True:
    try:
        postorder = ""
        preorder, inorder = input().split()
        root = 0
        build(0, len(preorder) - 1)
        print(postorder)
    except:
        break
