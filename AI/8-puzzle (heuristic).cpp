#include <bits/stdc++.h>

using namespace std;

const int ROW = 3;
const int COL = 3;
const int EMPTY_TILE = 0;
const int MAX_OP = 4;

struct State {
	int board[ROW][COL];
	int empty_row;
	int empty_col;
} *src_state, *dst_state;

struct Node {
	State state;
	Node *parent;
	int f, g, h;
};

struct node_cmp{
	bool operator () (Node *a, Node *b){
		return a->f < b->f;
	}
};

bool up(State s, State &out){
	int er = s.empty_row, ec = s.empty_col;
	if (er){
		out = s;
		out.empty_row = er - 1;
		out.empty_col = ec;
		
		out.board[er][ec] = s.board[er-1][ec];
		out.board[er-1][ec] = EMPTY_TILE;
		
		return true;
	}
	return false;
}

bool down(State s, State &out){
	int er = s.empty_row, ec = s.empty_col;
	if (er < ROW-1){
		out = s;
		out.empty_row = er + 1;
		out.empty_col = ec;
		
		out.board[er][ec] = s.board[er+1][ec];
		out.board[er+1][ec] = EMPTY_TILE;
		
		return true;
	}
	return false;
}

bool left(State s, State &out){
	int er = s.empty_row, ec = s.empty_col;
	if (ec){
		out = s;
		out.empty_row = er;
		out.empty_col = ec-1;
		
		out.board[er][ec] = s.board[er][ec-1];
		out.board[er][ec-1] = EMPTY_TILE;
		
		return true;
	}
	return false;
}

bool right(State s, State &out){
		int er = s.empty_row, ec = s.empty_col;
	if (ec < COL-1){
		out = s;
		out.empty_row = er;
		out.empty_col = ec+1;
		
		out.board[er][ec] = s.board[er][ec+1];
		out.board[er][ec+1] = EMPTY_TILE;
		
		return true;
	}
	return false;
}

bool operator == (State a, State b){
	if (a.empty_row != b.empty_row || a.empty_col != b.empty_row) return false;
	for (int i = 0; i < ROW; ++i){
		for (int j = 0; j < COL; ++j){
			if (a.board[i][j] != b.board[i][j]) return false;
		}
	}
	return true;
}
bool is_goal(State s, State goal){
	return s == goal;
}

bool call_op(State s, State &out, int op){
	switch (op){
		case 1:
			return up(s, out);
		case 2:
			return down(s, out);
		case 3:
			return left(s, out);
		case 4:
			return right(s, out);
		default:
			return false;
	}
}

void print_state(State s){
	for (int i = 0; i < ROW; ++i){
		for (int j = 0; j < COL; ++j){
			cout << s.board[i][j] << " ";
		}
		cout << endl;
	}
}

int h1(State s, State dst_state){
	int count = 0;
	for (int i = 0; i < ROW; ++i){
		for (int j = 0; j < COL; ++j){
			count += (s.board[i][j] != dst_state.board[i][j]);
		}
	}
	return count;
}

int h2(State s, State dst_state){
	int count = 0;
	for (int i = 0; i < ROW; ++i){
		for (int j = 0; j < COL; ++j){
			for (int _i = 0; _i < ROW; ++_i){
				for (int _j = 0; _j < COL; ++_j){
					if (dst_state.board[i][j] == s.board[_i][_j]){
						count += (abs(i-_i) + abs(j-_j));
					}
				}
			}
		}
	}
	return count;
}

Node *find_node(State s, multiset<Node *, node_cmp> list){
	for (Node *node : list){
		if (node->state == s) return node;
	}
	return NULL;
}

bool find_state(State s, vector<State> explored){
	for (State state : explored){
		if (s == state) return true;
	}
	return false;
}

Node *bfs(){
	vector<State> explored;
	Node *root = new Node();
	root->state = *src_state;
	root->parent = NULL;
	root->g = 0;
	root->h = h1(*src_state, *dst_state);
	root->f = root->g + root->h;
	
	multiset<Node*, node_cmp> frontiers;
	frontiers.insert(root);
	explored.push_back(*src_state);
	while (!frontiers.empty()){
		Node * node = *frontiers.begin();
		frontiers.erase(frontiers.begin());
		explored.push_back(node->state);
		if (is_goal(node->state, *dst_state)) return node;
//		cout << "Do sau cua cay la: " << node->g << endl;
		for (int op = 1; op <= MAX_OP; ++op){
			State newState;
			if (call_op(node->state, newState, op)){
				if (find_state(newState, explored)) continue;
				Node *newNode = find_node(newState, frontiers);
				if (newNode == NULL){
					newNode = new Node();
					newNode->parent = node;
					newNode->state = newState;
					newNode->h = h1(newState, *dst_state);
//					print_state(newState);
					newNode->g = node->g + 1;
					newNode->f = newNode->h + newNode->g;
//					cout << "===========" << newNode->g << "====" << newNode->h << endl;
					frontiers.insert(newNode);
				} else {
					newNode->g = node->g + 1;
					newNode->f = newNode->g + newNode->h;
				}
			}
		}
	}
}

void print_path(Node *r){
	int i = 0;
	stack<State> q;
	cout << "Duong di loi giai:\n";
	while (r->parent != NULL){
		q.push(r->state);
		r = r->parent;
	}
	while (!q.empty()){
		cout << "Trang thai thu " << ++i << endl;
		print_state(q.top());
		q.pop();
	}
}
int main(){
	freopen("input.txt", "r", stdin);
	dst_state = new State();
	for (int i = 0; i < ROW; ++i){
		for (int j = 0; j < COL; ++j){
			cin >> dst_state->board[i][j];
			if (dst_state->board[i][j] == 0){
				dst_state->empty_row = i;
				dst_state->empty_col = j;
			}
		}
	}
	src_state = new State();
	for (int i = 0; i < ROW; ++i){
		for (int j = 0; j < COL; ++j){
			cin >> src_state->board[i][j];
			if (src_state->board[i][j] == 0){
				src_state->empty_row = i;
				src_state->empty_col = j;
			}
		}
	}
	cout << "Trang thai ban dau:\n";
	print_state(*src_state);
	Node *node = bfs();
	print_path(node);
}
