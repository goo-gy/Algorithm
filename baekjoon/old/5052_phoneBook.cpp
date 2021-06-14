#include <iostream>
#include <vector>
#include <string>

using namespace std;

int test_case();
long long solution();
int T;

class TreeNode{
    TreeNode* next[10];
    bool isLeaf;
public:
    TreeNode(string &phoneNumber, int depth) {
        for (int i = 0; i < 10; i++) {
            next[i] = NULL;
        }
        if(phoneNumber.size() == depth) {
            isLeaf = true;
            return;
        }
        isLeaf = false;
        int number = phoneNumber[depth] - 0x30;
        next[number] = new TreeNode(phoneNumber, depth+1);
    }

    bool insert(string &phoneNumber, int depth){
        if(isLeaf || phoneNumber.size() == depth){
            return false;
        }
        int number = phoneNumber[depth] - 0x30;
        if(next[number]) {
            return next[number]->insert(phoneNumber, depth+1);
        }
        else {
            next[number] = new TreeNode(phoneNumber, depth+1);
            return true;
        }
    }
    // delete
};

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    test_case();
    return 0;
}

long long solution()
{
    // input
    int N;
    cin >> N;
    vector<string> phoneNumberBook;
    phoneNumberBook.resize(N);
    for(int i = 0; i < N; i++)
    {
        cin >> phoneNumberBook[i];
    }
    // solution
    TreeNode *root;
    root = new TreeNode(phoneNumberBook[0], 0);
    for(int i = 1; i < N; i++){
        bool success = root->insert(phoneNumberBook[i], 0);
        if(!success) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}

int test_case()
{
    cin >> T;
    for(int i = 0; i < T; i++)
    {
        solution();
    }
    return 0;
}
