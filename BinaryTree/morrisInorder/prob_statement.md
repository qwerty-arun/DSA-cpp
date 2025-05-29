# Morris Inorder Traversal (Leetcode: 94)
- We use iterative approach here
- We use threads
```cpp
while(curr!=nullptr)
{
    if(curr->left == nullptr)
    {
        curr = curr->right;
    }
    else
    {
        if(IP->right == nullptr)
        {
            IP->right = curr;
            curr = curr->left;
        }
        else
        {
            IP->right = nullptr;
            curr = curr->right;
        }
    }
}
```
