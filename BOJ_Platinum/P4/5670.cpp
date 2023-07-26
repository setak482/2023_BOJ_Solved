#include<bits/stdc++.h>
using namespace std;
struct Trie{
    bool finish;
    char now;
    unordered_map<char, Trie*> child;
    void insert(string &str, int index){
        if(index >= str.size()) return;
        if(!child.count(str[index]))
            child[str[index]] = new Trie();
        if(index == str.size()-1) child[str[index]]->finish = true;
        child[str[index]]->insert(str, index+1);    
    }
    int find(string& str){
        int num = 1;
        Trie* cur = this->child[str[0]];
        for(int i = 1; i < str.size(); i++){
            if(cur->child.size() > 1 || (cur->finish && cur->now != str.back())) num++;
            cur = cur->child[str[i]];
        }
        return num;
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while(true){
        Trie* root = new Trie();
        vector<string> vstr;
        int n; cin >> n;
        if(cin.eof()) break;
        for(int i = 0; i < n; i++){
            string str; cin >> str;
            vstr.push_back(str);
            root->insert(str, 0);
        }
        double sum = 0;
        for(auto& s : vstr){
            int temp = root->find(s);
            // cout << temp << ' ';
            sum += temp;
        }
        cout << fixed << setprecision(2) << sum/n << '\n';
    }
}