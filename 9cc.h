#include <ctype.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// トークンの型を表す値
enum {
  TK_NUM = 256, // 整数トークン
  TK_EOF,       // 入力の終わりを表すトークン
};

// トークンの型
typedef struct {
  int ty;       // トークンの型
  int val;      // tyがTK_NUMの場合,その数値
  char *input;  // トークン文字列(エラーメッセージ用)
} Token;

enum {
  ND_NUM = 256, // 整数のノードの型
};

typedef struct Node {
  int ty;            // 演算子かND_NUM
  struct Node *lhs;  // 左辺
  struct Node *rhs;  // 右辺
  int val;           // tyがND_NUMの場合のみ使う
} Node;

typedef struct {
  void **data;
  int capacity;
  int len;
} Vector;

// 入力プログラム
extern char *user_input;

// トークナイズした結果のトークン列はこの配列に保存する
// 100個以上のトークンは来ないものとする
extern Token tokens[100];
extern int pos;

extern void tokenize();
extern Node *new_node(int ty, Node *lhs, Node *rhs);
extern Node *new_node_num(int val);
extern Vector *new_vector();
extern void vec_push(Vector *vec, void *elem);
extern int consume(int ty);
extern Node *expr();
extern Node *equality();
extern Node *relational();
extern Node *add();
extern Node *mul();
extern Node *unary();
extern Node *term();
extern void gen(Node *node);
extern void expect(int line, int expected, int actual);
extern void runtest();
extern void error(char *fmt, ...);
extern void error_at(char *loc, char *msg);
//int main(int argc, char **argv);


