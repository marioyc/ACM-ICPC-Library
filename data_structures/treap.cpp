long long seed = 47;

long long rand(){
    seed = (seed * 279470273) % 4294967291LL;
    return seed;
}

typedef int treap_type;

class treap{
    public:
    
    treap_type value;
    long long priority;
    treap *left, *right;
    int sons;
    
    treap(treap_type value) : left(NULL), right(NULL), value(value), sons(0){
        priority = rand();
    }
    
    ~treap(){
        if(left) delete left;
        if(right) delete right;
    }
};

treap* find(treap* t, treap_type val){
    if(!t) return NULL;
    if(val == t->value) return t;

    if(val < t->value) return find(t->left, val);
    if(val > t->value) return find(t->right, val);
}

inline void rotate_to_right(treap* &t){
    treap* n = t->left;
    t->left = n->right;
    n->right = t;
    t = n;
}

inline void rotate_to_left(treap* &t){
    treap* n = t->right;
    t->right = n->left;
    n->left = t;
    t = n;
}

void fix_augment(treap* t){
    if(!t) return;
    t->sons = (t->left ? t->left->sons + 1 : 0) +
        (t->right ? t->right->sons + 1 : 0);
}

void insert(treap* &t, treap_type val){
    if(!t) t = new treap(val);
    else insert(val <= t->value ? t->left : t->right, val);
    
    if(t->left && t->left->priority > t->priority)
        rotate_to_right(t);
    else if(t->right && t->right->priority > t->priority)
        rotate_to_left(t);
    
    fix_augment(t->left);
    fix_augment(t->right);
    fix_augment(t);
}

inline long long get_priority(treap* t){
    return t ? t->priority : -1;
}

void erase(treap* &t, treap_type val){
    if(!t) return;

    if(t->value != val) erase(val < t->value ? t->left : t->right, val);
    else{
        if(!t->left && !t->right){
            delete t;
            t = NULL;
        }else{
            if(get_priority(t->left) < get_priority(t->right))
                rotate_to_left(t);
            else
                rotate_to_right(t);
            
            erase(t, val);
        }
    }
    
    if(t){
        fix_augment(t->left);
        fix_augment(t->right);
        fix_augment(t);
    }
}

int getKth(treap* &t, int K){
    int left = (t->left == NULL? 0 : 1 + t->left->sons);
    int right = (t->right == NULL? 0 : 1 + t->right->sons);
    
    if(1+left == K) return t->value;
    else if(left < K) return getKth(t->right,K - 1 - left);
    return getKth(t->left,K);
}
