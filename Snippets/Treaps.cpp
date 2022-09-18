struct item
{
    int key, cnt, priority;
    item *l, *r;
    item() {}
    item(int key) : key(key), priority(rand()), cnt(1), l(NULL), r(NULL) {}
    item(int key, int prior) : key(key), priority(prior), cnt(1), l(NULL), r(NULL) {}
};

typedef item* pitem;

int cnt(pitem t) { return t ? t->cnt : 0; }
void upd_cnt (pitem t) { if(t) t->cnt = 1 + cnt(t->l) + cnt(t->r); }

void split(pitem t, int key, pitem &l, pitem &r) {
    if(!t) l = r = nullptr;
    else if (t->key <= key) split (t->r, key, t->r, r),  l = t;
    else split (t->l, key, l, t->l),  r = t;
    upd_cnt(t);
}

void merge (pitem &t, pitem l, pitem r) {
	if (!l || !r) t = l ? l : r;
	else if (l->priority > r->priority) merge (l->r, l->r, r),  t = l;
	else merge (r->l, l, r->l),  t = r;
    upd_cnt(t);
}

void insert (pitem &t, pitem it) {
    if (!t) t = it;
    else if (it->priority > t->priority) split (t, it->key, it->l, it->r),  t = it;
    else insert (t->key <= it->key ? t->r : t->l, it);
    upd_cnt(t);
}

void erase (pitem &t, int key) {
    if (t->key == key) { pitem th = t; merge(t, t->l, t->r); delete th; }
    else erase (key < t->key ? t->l : t->r, key);
    upd_cnt(t);
}

pitem unite (pitem l, pitem r) {
    if (!l || !r)  return l ? l : r;
    if (l->priority < r->priority) swap(l, r);
    pitem lt, rt;
    split(r, l->key, lt, rt);
    l->l = unite(l->l, lt);
    l->r = unite(l->r, rt);
    return l;
}

pitem united(pitem l, pitem r) {
    if(!l || !r) return l ? l : r;
    if(l->priority < r->priority) united(r, l);
    // else    
}