#include <stdio.h>
#include <stdlib.h>
#define id_size 20
#define word_size 100
typedef struct Adj{
	int id; //key값
	struct Adj* next;
} Adj;
typedef struct {
	int id;
	struct Tree *left;
	struct Tree *right;
	struct Tree *parent;
}Tree;// tree

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
	Tree* stand = (Tree*)(malloc(Tree));
	stand = root;
	while(stand){
		tree_buf = stand;
		if(tree->id<stand->id){
			stand=stand->left;
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


}
typedef struct{
	char word[word_size];
	Tree super;
	int count;
}word_tree;
void word_tree_init(word_tree* self){
	Tree_init(&self->super);
	self->count = 0;
	self->word ="\0";
}
void initword(){

}// 초기화
struct word add_word(){

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
	friend_buf = (int*)malloc(sizeof(int));
	friend_vertices =(friends*)malloc(sizeof(friends));
	fp_friend = fopen("friend.txt","r");
	fp_user = fopen("user.txt","r");
	fp_word = fopen("word.txt","r");
	while(fp_friend!=NULL){
		fscanf(fp_friend,"%d %d",&self,&friend);
		//self -> friend 연결 -> graph 생성
		count_friend++;
	}
	while(fp_word!=NULL){
		fscanf(fp_word,"%d %s %s %d %s %s %d %s");//id word 값 저장
		//word vertex 생성 -> id adj 연결
	}
	while(fp_user!=NULL){
		fscanf(fp_user,"%s %s %s %s %s %s %s %s");//id nickname 저장
		// id vertex 생성 -> id -> nickname저장

	}
	fclose("friend.txt");
	fclose("user.txt");
	fclose("word.txt");


}
