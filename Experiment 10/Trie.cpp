#include<bits/stdc++.h>
using namespace std;

struct Node {
    Node* nxt[26];
    bool end;

    Node() {
        end = false;
        for (int i = 0; i < 26; i++) nxt[i] = NULL;
    }
};

class Trie {
public:
    Node* root;

    Trie() {
        root = new Node();
    }

    void insert(string s) {
        Node* cur = root;
        for (char c : s) {
            int i = c - 'a';
            if (cur->nxt[i] == NULL)
                cur->nxt[i] = new Node();
            cur = cur->nxt[i];
        }
        cur->end = true;
    }

    bool search(string s) {
        Node* cur = root;
        for (char c : s) {
            int i = c - 'a';
            if (cur->nxt[i] == NULL) return false;
            cur = cur->nxt[i];
        }
        return cur->end;
    }

    bool startsWith(string s) {
        Node* cur = root;
        for (char c : s) {
            int i = c - 'a';
            if (cur->nxt[i] == NULL) return false;
            cur = cur->nxt[i];
        }
        return true;
    }
};

int main() {
    Trie t;
    t.insert("apple");
    cout << t.search("apple") << endl;
    cout << t.search("app") << endl;
    cout << t.startsWith("app") << endl;
    return 0;
}