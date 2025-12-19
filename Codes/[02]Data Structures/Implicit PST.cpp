class PST{
    struct node{
        int left = 0, right = 0, val = 0;
    };
    vector<node> tree;

    int N, LG, time = 0, I = 0;

    node create(int l, int r){
        return {l, r, merge(tree[l].val, tree[r].val)};
    }

    int update(int id, int le, int ri, int pos, int val){
        int nid = ++time;
        if(le == ri) return tree.push_back({0, 0, (tree[id].val ^ val)}), nid;
        int m = (le + ri) / 2;
        tree.push_back(node());
        if(pos <= m){
            tree[nid] = create(update(tree[id].left, le, m, pos, val), tree[id].right);
        }else{
            tree[nid] = create(tree[id].left, update(tree[id].right, m + 1, ri, pos, val));
        }
        return nid;
    }
    int query(int id, int di, int le, int ri){
        if(tree[id].val == tree[di].val) return -1;
        if(le == ri) return le;
        int m = (le + ri) >> 1;
        
        if(tree[tree[id].right].val != tree[tree[di].right].val) 
            return query(tree[id].right, tree[di].right, m + 1, ri);
        return query(tree[id].left, tree[di].left, le, m);
    }
    int merge(LL a, LL b){ 
        return a ^ b;
    }
public:
    PST(int N){
        this->N = N;   
        tree.push_back(node());     
    }
    int update(int id, int pos, int val){
        return update(id, 1, N, pos, val);
    }
    int query(int id, int di){
        return query(id, di, 1, N);
    }
    ~PST(){
    }
};