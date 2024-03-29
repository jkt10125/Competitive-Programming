#include <stdio.h>
#include <stdlib.h>

typedef char dt;

typedef struct {
    dt *data;
    int size, capacity;
} vector;

int lt (dt a, dt b) { return a < b; }

int less (vector *a, vector *b) {
    int i = 0;
    while (i < a->size && i < b->size) {
        if (lt(a->data[i], b->data[i])) { return 1; }
        else if (lt(b->data[i], a->data[i])) { return 0; }
        i++;
    }
    return a->size < b->size;
}

vector init () {
    vector v;
    v.data = (dt *) malloc (sizeof(dt));
    v.size = 0; v.capacity = 1;
    return v;
}

void clear (vector *v) {
    free (v->data);
    *v = init();
}

void resize (vector *v, int n) {
    v->capacity = (1 << (32 - __builtin_clz(n)));
    v->data = (dt *) realloc (v->data, sizeof(dt) * v->capacity);
    v->size = n;
}

void assign (vector *v, vector *a) {
    v->capacity = a->capacity;
    v->data = (dt *) malloc (sizeof(dt) * v->capacity);
    v->size = a->size;
    for (int i = 0; i < v->size; i++) { v->data[i] = a->data[i]; }
}

void insert (vector *v, int val, int idx) {
    if (v->size == v->capacity) {
        v->capacity <<= 1;
        v->data = (dt *) realloc (v->data, sizeof(dt) * v->capacity);
    }
    int i = v->size;
    while (i > idx) { v->data[i] = v->data[i - 1], i--; }
    v->data[idx] = val;
    v->size++;
}

void erase (vector *v, int idx) {
    int i = idx;
    while (i < v->size - 1) { v->data[i] = v->data[i + 1], i++; }
    v->size--;
}

dt *at (vector *v, int idx) {
    if (idx < 0 || idx >= v->size) {
        // error
        printf ("%d, out of range\n", idx);
        return NULL;
    }
    return &(v->data[idx]);
}

dt *upper_bound (vector *v, dt val) {
    int ans = v->size;
    int l = 0, r = v->size - 1;
    while (l <= r) {
        int m = (l + r) >> 1;
        if (lt(val, v->data[m])) { ans = m; r = m - 1; }
        else { l = m + 1; }
    }
    return at(v, ans);
}

dt *lower_bound (vector *v, dt val) {
    int ans = -1;
    int l = 0, r = v->size - 1;
    while (l <= r) {
        int m = (l + r) >> 1;
        if (lt(v->data[m], val)) { l = m + 1; }
        else { ans = m; r = m - 1; }
    }
    return at(v, ans);
}

// mergesort
void sort (vector *v, dt *s, dt *e, int (*cmp)(dt, dt)) {
    int start = s - v->data, end = e - v->data;
    if (start >= end) { return ; }

    int m = (start + end) >> 1;

    sort (v, at(v, start), at(v, m), cmp);
    sort (v, at(v, m + 1), at(v, end), cmp);

    int *temp = (int *) malloc (sizeof(int) * (end - start + 1));

    int i = start, j = m + 1, k = 0;
    
    while (i <= m && j <= end) {
        if (cmp(v->data[i], v->data[j])) { temp[k++] = v->data[i++]; }
        else { temp[k++] = v->data[j++]; }
    }
    while (i <= m) { temp[k++] = v->data[i++]; }

    while (j <= end) { temp[k++] = v->data[j++]; }

    for (int i = start; i <= end; i++) { v->data[i] = temp[i - start]; }
}

void input (vector *v) {
    clear(v); char c;
    scanf("%c", &c);
    while (c == ' ' || c == '\n') { scanf("%c", &c); }
    while (c != ' ' && c != '\n') {
        insert(v, c, v->size);
        scanf("%c", &c);
    }
}

void output (vector *v) {
    for (int i = 0; i < v->size; i++) {
        printf("%c", v->data[i]);
    }
}

int main() {
    vector v = init();
    input(&v);

    output(&v);   

    return 0;
}
