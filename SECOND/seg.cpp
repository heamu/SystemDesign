#include<bits/stdc++.h>
using namespace std;

//126 dimen -> so maiy

//N*126
// 

class segTree{
    vector<int>arr;
    vector<int>seg;
    int n;
    int build(int id , int l , int r ){
        if(l==r){
            seg[id] = arr[l];
            return seg[id];
        }

        int mid = (l+r)/2;

        return seg[id] = build(2*id+1,l,mid)+build(2*id+2,mid+1,r);
    }
    public:
    segTree(vector<int>arr){
        this->arr = arr;
        this->n = arr.size();
        seg.resize(4*n+1);
        build(0,0,n-1);
    }
    void update(int id , int value ,int cur, int l , int r){
        if(l==r){
            arr[id] = value;
            seg[cur] = value;
            return ;
        }

        int mid = (l+r)/2;

        if(id<=mid){
            update(id,value,2*cur+1,l,mid);
        }
        else{
            update(id,value,2*cur+2,mid+1,r);
        }

        seg[cur] = seg[2*cur+1] + seg[2*cur+2];
        
    }

    int query(int start , int end , int cur , int l , int r){
        if(end<l||r<start){
            return 0;
        }

        if(start<=l&&r<=end){//if(start <= l && r <= end)
            return seg[cur];
        }
        int mid = (l+r)/2;
        int left = query(start,end,2*cur+1,l,mid);
        int right = query(start,end,2*cur+2,mid+1,r);
        return left+right;
    }
};

int main(){

    vector<int>arr = {};
    int n = arr.size();
    vector<int>seg(4*n);

    
    return 0;
}