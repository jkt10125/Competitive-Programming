#include <stdio.h>
#include <stdlib.h>

typedef int dt1;
typedef int dt2;

struct node {
	dt1 key; dt2 value;
    int colour; // 1-red, 0-black
	struct node *parent, *right, *left;
};

typedef struct {
    struct node *root;
    int size;
} map;

int lt (dt1 a, dt1 b) { return a < b; }

void print_key (dt1 key) { printf("%d", key); }

void print_value (dt2 value) { printf("%d", value); }

void clear_tree (struct node *n) {
    if (n == NULL) { return ; }
    clear_tree (n->left);
    clear_tree (n->right);
    free (n);
}

void left_rotate (map *m, struct node *x) {
    struct node *y = x->right;
    x->right = y->left;
    if (y->left != NULL) { y->left->parent = x; }
    y->parent = x->parent;
    if (x->parent == NULL) { m->root = y; }
    else if (x == x->parent->left) { x->parent->left = y; }
    else { x->parent->right = y; }
    y->left = x;
    x->parent = y;
}

void right_rotate (map *m, struct node *x) {
    struct node *y = x->left;
    x->left = y->right;
    if (y->right != NULL) { y->right->parent = x; }
    y->parent = x->parent;
    if (x->parent == NULL) { m->root = y; }
    else if (x == x->parent->right) { x->parent->right = y; }
    else { x->parent->left = y; }
    y->right = x;
    x->parent = y;
}

void transplant (map *m, struct node *u, struct node *v) {
    if (u->parent == NULL) { m->root = v; }
    else if (u == u->parent->left) { u->parent->left = v; }
    else { u->parent->right = v; }
    if (v != NULL) { v->parent = u->parent; }
}

struct node *minimum(struct node *n) {
    while (n->left != NULL) { n = n->left; }
    return n;
}

map init () { map m; m.root = NULL; m.size = 0; return m; }

void clear (map *m) {
    clear_tree (m->root);
    m->root = NULL;
    m->size = 0;
}


struct node *new_node (dt1 k, dt2 v) {
    struct node *n = (struct node *) malloc (sizeof(struct node));
    n->key = k; n->value = v;
    n->colour = 1; n->parent = n->right = n->left = NULL;
    return n;
}

// inserts an element into the map
void insert (map *m, struct node *n) {
    
    struct node *curr = m->root;
    
    if (m->root == NULL) {
        m->root = n; m->root->colour = 0;
        m->size++;
        return ;
    }
    else {
        while (curr != NULL) {
            if (lt(n->key, curr->key)) {
                if (curr->left == NULL) {
                    curr->left = n; curr->left->parent = curr;
                    curr->left->colour = 1;
                    break;
                }
                else { curr = curr->left; }
            }
            else if (lt(curr->key, n->key)) {
                if (curr->right == NULL) {
                    curr->right = n; curr->right->parent = curr;
                    curr->right->colour = 1;
                    break;
                }
                else { curr = curr->right; }
            }
            else {
                curr->value = n->value;
                free (n);
                return ;
            }
        }
    }

    // fix the tree
    curr = n;
    while (curr->parent != NULL && curr->parent->colour == 1) {

        struct node *uncle = NULL;

        if (curr->parent == curr->parent->parent->left) {
            uncle = curr->parent->parent->right;
            if (uncle != NULL && uncle->colour == 1) {
                curr->parent->colour = 0;
                uncle->colour = 0;
                curr->parent->parent->colour = 1;
                curr = curr->parent->parent;
            }
            else {
                if (curr == curr->parent->right) {
                    curr = curr->parent;
                    // rotate left
                    left_rotate(m, curr);
                }
                curr->parent->colour = 0;
                curr->parent->parent->colour = 1;
                // rotate right
                right_rotate(m, curr->parent->parent);
            }
        }
        else {
            uncle = curr->parent->parent->left;
            if (uncle != NULL && uncle->colour == 1) {
                curr->parent->colour = 0;
                uncle->colour = 0;
                curr->parent->parent->colour = 1;
                curr = curr->parent->parent;
            }
            else {
                if (curr == curr->parent->left) {
                    curr = curr->parent;
                    // rotate right
                    right_rotate(m, curr);
                }
                curr->parent->colour = 0;
                curr->parent->parent->colour = 1;
                // rotate left
                left_rotate(m, curr->parent->parent);
            }
        }
    }

    m->root->colour = 0;
    m->size++;
}

void erase (map *m, struct node *n) {
    if (n == NULL) { return ; }
    m->size--;
    struct node *y = n, *x = NULL;
    int y_original_colour = y->colour;
    if (n->left == NULL) {
        x = n->right;
        transplant(m, n, n->right);
    }
    else if (n->right == NULL) {
        x = n->left;
        transplant(m, n, n->left);
    }
    else {
        y = minimum(n->right);
        y_original_colour = y->colour;
        x = y->right;
        if (y->parent != n) {
            transplant(m, y, y->right);
            y->right = n->right;
            y->right->parent = y;
        }
        transplant(m, n, y);
        y->left = n->left;
        y->left->parent = y;
        y->colour = n->colour;
    }
}

struct node *at (map *m, dt1 key) {
    struct node *curr = m->root;
    while (curr != NULL) {
        if (lt(key, curr->key)) { curr = curr->left; }
        else if (lt(curr->key, key)) { curr = curr->right; }
        else { return curr; }
    }
    return NULL;
}

// upper bound function for map
struct node *upper_bound (map *m, dt1 key) {
    struct node *curr = m->root, *ans = NULL;
    while (curr != NULL) {
        if (lt(key, curr->key)) {
            ans = curr;
            curr = curr->left;
        }
        else { curr = curr->right; }
    }
    return ans;
}

// lower bound function for map
struct node *lower_bound (map *m, dt1 key) {
    struct node *curr = m->root, *ans = NULL;
    while (curr != NULL) {
        if (lt(key, curr->key)) { curr = curr->left; }
        else {
            ans = curr;
            curr = curr->right;
        }
    }
    return ans;
}

void print_node (struct node *n) {
    if (n == NULL) { printf("NULL\n"); return ; }
    print_key(n->key); printf(" : "); print_value(n->value); 
    printf("\n");
}

// inorder traversal of map
void inorder (struct node *n) {
    if (n == NULL) { return ; }
    inorder(n->left);
    print_node(n);
    inorder(n->right);
}

// preorder traversal of map
void preorder (struct node *n) {
    if (n == NULL) { return ; }
    print_node(n);
    preorder(n->left);
    preorder(n->right);
}



int main() {
    map m = init();

    // insert random elements into the map
    dt1 k;
    for (int i = 0; i < 10; i++) {
        k = rand() % 100;
        struct node *n = new_node(k, rand() % 100);
        insert(&m, n);
    }

    insert(&m, new_node((dt1){ 50 }, 100));

    // print the map
    inorder(m.root);
    
    printf("\n");

    // erase a random element from the map
    struct node *n = at(&m, k);
    // erase(&m, n);

    dt1 k1;
    k1 = 4;
    n = lower_bound(&m, k1);
    print_node(n);

    clear(&m);

    printf("%d", m.size);

    return 0;
}

