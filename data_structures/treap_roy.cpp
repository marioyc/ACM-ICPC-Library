typedef long long ptype;

ptype seed = 47;

ptype my_rand(){
    seed = (seed * 279470273) % 4294967291LL;
    return seed;
}

typedef struct node * pnode;

struct node{
  int x, y, cnt;
  pnode L, R;
  node() {}
  node(int x, int y): x(x), y(y), cnt(1), L(NULL), R(NULL) {}
};

pnode T;

inline int cnt(pnode &it){
  return it ? it->cnt : 0;
}

inline void upd_cnt(pnode &it){
  if (it){
    it->cnt = cnt(it->L) + cnt(it->R) + 1;
  }
}

// Split Treap
void split(pnode t, int x, pnode &L, pnode &R){
  if (!t) L = R = NULL;
  else{
    if (x < t->x)
      split (t->L, x, L, t->L), R = t;
    else
      split (t->R, x, t->R, R), L = t;
    upd_cnt(t);
  }
}

// Split Implicit Treap
void split(pnode t, pnode &L, pnode &R, int key){
  if (!t) L = R = NULL;
  else{
    int cntL = cnt(t->L);
    if (key <= cntL)
      split (t->L, L, t->L, key), R = t;
    else
      split (t->R, t->R, R, key - cntL - 1), L = t;
    upd_cnt(t);
  }
}

// For Treap & Implicit Treap
void merge(pnode &t, pnode L, pnode R){
  if (!L) t = R;
  else if(!R) t = L;
  else if (L->y > R->y)
    merge (L->R, L->R, R), t = L;
  else
    merge (R->L, L, R->L), t = R;
  upd_cnt(t);
}

// Combines 2 treaps
pnode unite (pnode l, pnode r) {
  if (!l || !r) return l? l: r;
  if (l->y > r->y) swap (l, r);
  pnode lt, rt;
  split (r, l->x, lt, rt);
  l->L = unite(l->L, lt);
  l->R = unite(l->R, rt);
  return l;
}

// Find in Treap
bool find (pnode &t, int x) {
  if(!t) return 0;
  else if (t->x == x) return 1;
  else return find (x < t->x ? t->L: t->R, x);
}

// Erase from Treap
void erase (pnode &t, int x) {
  if (t-> x == x)
    merge (t, t->L, t->R);
  else
    erase (x < t->x ? t->L: t->R, x);
}

// Insert into Treap
void insert(pnode &t, pnode it) {
  if (!t) t = it;
  else if (it->y > t->y)
    split (t, it->x, it->L, it->R), t = it;
  else insert (it->x < t->x ? t->L: t->R, it);
}

// Insert into Treap and return the # of greater elements
int insert(pnode &t, pnode it){
  int ret = 0;
  if (!t) t = it;
  else if (it->y > t->y)
    split (t, it->x, it->L, it->R), t = it, ret = cnt(t->R);
  else if(it->x < t->x)
    ret = 1 + cnt(t->R) + insert(t->L, it);
  else
    ret = insert(t->R, it);
  upd_cnt(t);
  return ret;
}

// Safely insert into Treap
void insert(int x)
{
  if(!find(T, x))
    insert(T, new node(x, rand()));
}
