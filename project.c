#include <stdio.h>
#include <stdlib.h>
#define id_size 20
#define word_size 100
#define word_num 100000
typedef struct Adj{
	int id;
	struct Adj* next;
} Adj;
typedef struct {
	int id;
	struct Tree *left;
	struct Tree *right;
	struct Tree *parent;
}Tree;// tree
typedef struct{

	int id;
	int parent;
	Adj* first;

}Vertex;
void Vertex_init(Vertex* self){
	self->parent=-1;
	self->id=0;
	self->first=NULL;
}
void Vertex_add(Vertex* self,Vertex* friend){
	Adj* a=(Adj*)malloc(sizeof(Adj));
	a->id=friend->id;
	a->next=self->first;
	self->first = a;
}
Tree *root;
void Tree_init(Tree* self){
	self->id =0;
	root=self;
	root->left = NULL;
	root->right = NULL;
	root->parent =NULL;
}
void Tree_add(Tree* self, Tree* tree){
	Tree* tree_buf;
	Tree* stand;
	stand = (Tree*)(malloc(sizeof(Tree)));
	stand = root;
	while(stand){
		tree_buf = stand;
		if(tree->id<stand->id){
			stand = stand->left;
		}
		else	stand = stand->right;

	}
	tree->parent = tree_buf;
	if(tree_buf->parent==NULL){
		root = tree;
	}
	else if(tree->id<tree_buf->id){
		tree_buf->left = tree;
	}
	else tree_buf->right = tree;
	}



typedef struct{
	char word[word_size];
	Tree super;
	int count;
}word_tree;
void word_tree_init(word_tree* self,char* word){
	Tree_init(&self->super);
	self->count = 0;
	int i=0;
	while(*(word) != NULL){
		self->word[i] = *(word +i);
		}
}

void word_tree_add(word_tree* self, int id){
	Tree* tree;
	tree = (Tree*)malloc(sizeof(Tree));
	Tree_init(tree);
	tree->id = id;
	Tree_add(&self->super,tree);
	self->count = self->count+1;

}

typedef struct{
	int id; //id number
	struct Adj* friend;


}friends;
typedef struct id{

};


int main(){
	FILE* fp_user = NULL;
	FILE* fp_friend = NULL;
	FILE* fp_word = NULL;
	int self,friend,count_friend;
	friends *friend_vertices = NULL;
	int * friend_buf = NULL;
	Vertex vertices_friend[1000000000];
	friend_buf = (int*)malloc(sizeof(int));
	friend_vertices =(friends*)malloc(sizeof(friends));
	fp_friend = fopen("friend.txt","r");
	fp_user = fopen("user.txt","r");
	fp_word = fopen("word.txt","r");
	while(fp_friend!=NULL){
		fscanf(fp_friend,"%d %d",&self,&friend);
		if(vertices_friend[self]==NULL){
			Vertex_init(vertices_friend[self]);
			vertices_friend[self]->id = self;
		}
		if(vertices_friend[friend]==NULL){
			Vertex_init(vertices_friend[friend]);
			vertices_friend[friend]->id = friend;
		}

		vertices_friend[self]->id =self;
		vertices_friend[friend]->id=friend;
		Vertex_add(vertices_friend[self],vertices_friend[friend]);
		count_friend++;
	}
	int word_id;
	int i=0;
	char* word;
	word = (char*)malloc(sizeof(char));

	word_tree* vertices_word;
	vertices_word = (word_tree*)malloc(sizeof(word_tree));
	while(fp_word!=NULL){

		fscanf(fp_word,"%d",&word_id);//id word 蔼 历厘
		fseek(fp_word,32,1);
		fscanf(fp_word,"%s",word);
		word_tree_init(vertices_word+(int)word,word);
		word_tree_add(vertices_word+(int)word,word_id);

		//word vertex 积己 -> id tree 楷搬
	}
	while(fp_user!=NULL){
		fscanf(fp_user,"%s %s %s %s %s %s %s %s");//id nickname 历厘
		// id vertex 积己 -> id -> nickname历厘

	}
	fclose(fp_user);
	fclose(fp_friend);
	fclose(fp_word);

	return 0;
}
