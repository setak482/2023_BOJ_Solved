#include <bits/stdc++.h>
#define nc(c) c-'0'
using namespace std;
class Trie{
private:
    int level;
    unordered_map<int, Trie*> child;
public:
    void insert(string str, int idx){
        if(str.size() <= idx) return;
        if(!this->child.count(nc(str[idx]))){
            this->child[nc(str[idx])] = new Trie();
            this->child[nc(str[idx])]->level = 29-idx;
        }
        this->child[nc(str[idx])]->insert(str, idx+1);
    }
    int search(string str){
        Trie* cur = this;
        int temp = 0;
        for(int i = 0; i < str.size(); i++){
            if(nc(str[i])){
                if(cur->child.count(0)){
                    temp += 1 << cur->child[0]->level;
                    cur = cur->child[0];
                }
                else cur = cur->child[1];
            }
            else{
                if(cur->child.count(1)){
                    temp += 1 << cur->child[1]->level;
                    cur = cur->child[1];
                }
                else cur = cur->child[0];
            }
        }
        return temp;
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    Trie* root = new Trie();
    vector<int> arr;
    int cnt; cin >> cnt;
    for(int i = 0; i < cnt; i++){
        int temp; cin >> temp;
        arr.push_back(temp);
    }
    for(auto i : arr)
        root->insert(bitset<30>(i).to_string(), 0);
    int ans = 0;
    for(auto i : arr)
        ans = max(ans, root->search(bitset<30>(i).to_string()));
    cout << ans;
}