ptype seed = 47;

ptype my_rand(){
    seed = (seed * 279470273) % 4294967291LL;
    return seed;
}

struct item{
    int key;
    ptype prior;
    item *l,*r;
    int sons;
    
    item(){}
    
    item(int key) : key(key), l(NULL), r(NULL){
        prior = my_rand();
    }
};

void split(item* t, int key, item* &l, item* &r){
    if(!t)
        l = r = NULL;
    else if(key < t->key)
        split(t->l,key,l,t->l), r = t;
    else
        split(t->r,key,t->r,r), l = t;
}

void insert(item* &t, item* it){
    if(!t)
        t = it;
    else if(it->prior > t->prior)
        split(t, it->key, it->l, it->r), t = it;
    else
        insert(it->key < t->key ? t->l : t->r, it);
}

void merge(item* &t, item* l, item* r){
    if(!l || !r)
        t = l ? l : r;
    else if(l->prior > r->prior)
        merge(l->r, l->r, r), t = l;
    else
        merge(r->l, l, r->l), t = r;
}

void erase(item* &t, int key){
    if(t->key == key)
        merge(t, t->l, t->r);
    else
        erase(key < t->key ? t->l : t->r, key);
}

item* unite(item* l, item* r){
    if(!l || !r) return l ? l : r;
    if(l->prior < r->prior) swap (l, r);
    
    item *lt,*rt;
    
    split(r, l->key, lt, rt);
    l->l = unite(l->l, lt);
    l->r = unite(l->r, rt);
    
    return l;
}