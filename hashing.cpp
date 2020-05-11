#include <bits/stdc++.h>
using namespace std;
#include<cstring>

template<typename T>
class node{
    public:
        string key;
        T value;
        node <T>*next;
    node(string key, T value)
    {
        this->key=key;
        this->value=value;
    }
};
template<typename T>
class hashtable{
    int cs;
    int ts;
    node <T>**buckets;
    public:
        hashtable(int ds=7){
            cs=0;
            ts=ds;
            buckets=new node <T>*[ts];
            for(int i=0;i<ts;i++)
            {
                buckets[i]=NULL;
            }
        }
        int hashfn(string key){
            int l=key.length();
            int ans=0;
            int p=1;
            for(int i=0;i<l;i++)
            {
                ans=ans+key[l-i-1]*p;
                p=p*37;
                p=p%ts;
                ans=ans%ts;
            }
            return ans;
        }
void insert(string key, T value)
{
    int i=hashfn(key);
    node <T>*n=new node <T>(key,value);
    n->next=buckets[i];
    buckets[i]=n;
}
void print()
{
    for(int i=0;i<ts;i++)
    {
        node <T>*temp=buckets[i];
        cout << "Bucket" << i << "->";
        while(temp!=NULL)
        {
            cout <<temp->key << ",";
            temp=temp->next;
        }
        cout << endl;
    }
}
};

int main()
{
    hashtable <int> h(11);
    h.insert("mango",100);
    h.insert("banana",101);
    h.insert("orange",102);
    h.insert("grapes",103);
    h.print();
    return 0;
}