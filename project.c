#include <stdio.h>
#include <stdlib.h>
typedef struct Adj{
	int id; //key蔼
	struct Adj* next;
} Adj;
struct Node{
	int id;
	struct Node *left;
	struct Node *right;
};// tree

struct Node *root;
void initTree(int id){
	struct Node *New;
	New = (struct Node*)(malloc(sizeof(struct Node)));
	root = New;
	root->id =id;
	New->left =NULL;
	New->right =NULL;
}
typedef struct word{

};
typedef struct{
	int id; //id number
	struct Adj* friend;


}friends;
typedef struct id{

};
#define id_size 20
#define word_size 100

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
		//self -> friend 楷搬 -> graph 积己
		count_friend++;
	}
	while(fp_word!=NULL){
		fscanf(fp_word,"%d %s %s %d %s %s %d %s");//id word 蔼 历厘
		//word vertex 积己 -> id adj 楷搬
	}
	while(fp_user!=NULL){
		fscanf(fp_user,"%s %s %s %s %s %s %s %s");//id nickname 历厘
		// id vertex 积己 -> id -> nickname历厘

	}
	fclose("friend.txt");
	fclose("user.txt");
	fclose("word.txt");


}
