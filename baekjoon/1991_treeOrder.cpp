#include <iostream>
#include <vector>
using namespace std;

int N;

struct Node
{
    char name;
    Node *cLeft;
    Node *cRight;
};

Node *find(Node *cur, char name)
{
    if(cur == NULL)
        return NULL;

    if (cur->name == name)
        return cur;

    Node *target = NULL;
    target = find(cur->cLeft, name);
    if (target == NULL)
        target = find(cur->cRight, name);
    return target;
}

void preOrder(Node *cur)
{
    if(cur == NULL)
        return;
    cout << cur->name;
    preOrder(cur->cLeft);
    preOrder(cur->cRight);
}

void inOrder(Node *cur)
{
    if(cur == NULL)
        return;
    inOrder(cur->cLeft);
    cout << cur->name;
    inOrder(cur->cRight);
}

void postOrder(Node *cur)
{
    if(cur == NULL)
        return;
    postOrder(cur->cLeft);
    postOrder(cur->cRight);
    cout << cur->name;
}

int solution()
{
    cin >> N;
    Node *root = new Node{'A', NULL, NULL};
    for (int i = 1; i <= N; i++)
    {
        char parent, cLeft, cRight;
        cin >> parent >> cLeft >> cRight;

        Node *node = find(root, parent);
        if (cLeft != '.')
            node->cLeft = new Node{cLeft, NULL, NULL};
        if (cRight != '.')
            node->cRight = new Node{cRight, NULL, NULL};
    }
    preOrder(root);
    cout << "\n";
    inOrder(root);
    cout << "\n";
    postOrder(root);
    cout << "\n";

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}