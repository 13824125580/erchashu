#include <stdio.h>

struct node {
    struct node* left;
    unsigned int value;
    struct node* right;
};

static void init_node(struct node* n, unsigned int value)
{
    n->value = value;
    n->left = n->right = NULL;
}

static void init_node_lr(struct node* f, struct node* l, struct node* r)
{
	f->left = l;
	f->right = r;
}

static void parse_node(struct node *root)
{
    if(root->left)
	    parse_node(root->left);
    if(root->right)
	    parse_node(root->right);

    printf("value = %d.\n", root->value);
}

struct node node0, node1, node2, node3, node4, node5, node6;
int main(void)
{
   init_node(&node0, 0);
   init_node(&node1, 1);
   init_node(&node2, 2);
   init_node(&node3, 3);
   init_node(&node4, 4);
   init_node(&node5, 5);
   init_node(&node6, 6);

   init_node_lr(&node0, &node1, &node2);
   init_node_lr(&node1, &node3, &node4);
   init_node_lr(&node2, &node5, &node6);

   parse_node(&node0);
   printf("%s line %d.\n", __func__, __LINE__);
   return 0;
}
