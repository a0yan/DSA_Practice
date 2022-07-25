def left(root,ans):
    if root==None:
        return
    if root.left==None and root.right==None:
        # ans.append(root.data)
        return
    ans.append(root.data)
    if root.left:
        left(root.left,ans)
    elif root.right:
        left(root.right,ans)
def leaves(root,ans):
    if root==None:
        return
    if root.left==None and root.right==None:
        ans.append(root.data)
    leaves(root.left,ans)
    leaves(root.right,ans)
def right(root,ans):
    if root==None:
        return 
    if root.left==None and root.right==None:
        # ans.append(root.data)
        return
    if root.right:
        right(root.right,ans)
    elif root.left:
        right(root.left,ans)
    ans.append(root.data)
