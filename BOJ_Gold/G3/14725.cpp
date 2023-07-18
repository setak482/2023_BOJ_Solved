#include <bits/stdc++.h>
using namespace std;
struct Trie{
    string name;
    int height;
    map<string, Trie*> child;
    void insert(vector<string> &arr, int index){
        if(index >= arr.size()) return;
        if(!child.count(arr[index]))
            child[arr[index]] = new Trie();
        child[arr[index]]->name = arr[index];
        child[arr[index]]->height = index+1;
        child[arr[index]]->insert(arr, index+1);
    }
};
Trie* root;
void input(){
    int tc; cin >> tc;
    for(int i = 0; i < tc; i++){
        int j; cin >> j;
        vector<string> v;
        while(j--){
            string temp; cin >> temp;
            v.push_back(temp);
        }
        root->insert(v, 0);
    }
}
set<pair<int, string>> visited;
void output(Trie* node){
    if(node != root){
        for(int i = 0; i < node->height*2-2; i++) cout << '-';
        cout << node->name << '\n';
    }
    for(auto& i : node->child){
        if(!visited.count({node->height+1, i.first})){
            visited.insert({node->height+1, i.first});
            output(i.second);
            visited.erase({node->height+1, i.first});
        }
    }
}
int main(){
    root = new Trie();
    input();
    output(root);
}