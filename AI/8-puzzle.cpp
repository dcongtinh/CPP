/**
 * Author: Dao Cong Tinh dcongtinh@ferdon.io
 * Description: Solution for 8-puzzle problem. 
 * **/
#include <bits/stdc++.h>

using namespace std;

int size = 3;
int source[3][3] = {{7, 1, 3}, {2, 0, 4}, {6, 8, 5}};
// 7 1 3
// 2 0 4
// 6 8 5
int target[3][3] = {{1, 2, 3}, {8, 0, 4}, {7, 6, 5}};
// 1 2 3
// 8 0 4
// 7 6 5
string OP[] = {"Khoi tao", "Xuong", "Qua trai", "Len", "Qua phai"};
typedef struct State *pState;
struct State
{
    int puzzle[3][3];
    int i, j;
    pState parent;
    int op;
};

void debug(int (*a)[3])
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
            cout << a[i][j];
        cout << endl;
    }
}
void print(pState s, int index)
{
    if (s == NULL)
        cout << "NULL\n";
    else
    {
        printf("%2d. (%s)\n", index, OP[s->op].c_str());
        // debug(s->puzzle);
    }
}

bool goal_check(pState s)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            if (s->puzzle[i][j] != target[i][j])
                return false;
        }
    }
    return true;
}

void pass_puzzle(int (*_new)[3], int (*_old)[3])
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            _new[i][j] = _old[i][j];
        }
    }
}
//operator 1 (down)
pState Down(pState s)
{
    int i = s->i;
    int j = s->j;
    if (i)
    {
        pState newState = new State;
        pass_puzzle(newState->puzzle, s->puzzle);
        newState->puzzle[i][j] = s->puzzle[i - 1][j];
        newState->puzzle[i - 1][j] = 0;
        newState->i = i - 1;
        newState->j = j;
        newState->parent = s;
        newState->op = 1;
        return newState;
    }

    return NULL;
}

//operator 2 (left)
pState Left(pState s)
{
    int i = s->i;
    int j = s->j;
    if (j < size - 1)
    {
        pState newState = new State;
        pass_puzzle(newState->puzzle, s->puzzle);
        newState->puzzle[i][j] = s->puzzle[i][j + 1];
        newState->puzzle[i][j + 1] = 0;
        newState->parent = s;
        newState->i = i;
        newState->j = j + 1;
        newState->op = 2;
        return newState;
    }
    return NULL;
}

//operator 3 (up)
pState Up(pState s)
{
    int i = s->i;
    int j = s->j;
    if (i < size - 1)
    {
        pState newState = new State;
        pass_puzzle(newState->puzzle, s->puzzle);
        newState->puzzle[i][j] = s->puzzle[i + 1][j];
        newState->puzzle[i + 1][j] = 0;
        newState->parent = s;
        newState->i = i + 1;
        newState->j = j;
        newState->op = 3;
        return newState;
    }
    return NULL;
}

//operator 4 (right)
pState Right(pState s)
{
    int i = s->i;
    int j = s->j;
    if (j)
    {
        pState newState = new State;
        pass_puzzle(newState->puzzle, s->puzzle);
        newState->puzzle[i][j] = s->puzzle[i][j - 1];
        newState->puzzle[i][j - 1] = 0;
        newState->parent = s;
        newState->i = i;
        newState->j = j - 1;
        newState->op = 4;
        return newState;
    }
    return NULL;
}

pState call_op(pState s, int op)
{
    switch (op)
    {
    case 1:
        return Down(s);
    case 2:
        return Left(s);
    case 3:
        return Up(s);
    case 4:
        return Right(s);
    default:
        return NULL;
    }
}

bool found_state(pState s, vector<pState> open_list)
{
    for (int i = 0; i < open_list.size(); ++i)
    {
        pState tmp = open_list[i];
        int count = 0;
        for (int _i = 0; _i < size; ++_i)
        {
            for (int _j = 0; _j < size; ++_j)
            {
                count += s->puzzle[_i][_j] == tmp->puzzle[_i][_j];
            }
        }
        if (count == size * size)
            return true;
    }
    return false;
}

pState dfs()
{
    pState pStart = new State;
    pass_puzzle(pStart->puzzle, source);
    pStart->parent = NULL;
    pStart->i = 1;
    pStart->j = 1;
    pStart->op = 0;

    stack<pState> frontier;
    frontier.push(pStart);
    vector<pState> explored;
    while (!frontier.empty())
    {
        pState state = frontier.top();
        frontier.pop();
        if (goal_check(state))
            return state;
        explored.push_back(state);

        for (int op = 1; op <= 4; ++op)
        {
            pState newState = call_op(state, op);
            if (newState != NULL)
            {
                if (found_state(newState, explored))
                    continue;
                frontier.push(newState);
            }
        }
    }
    return NULL;
}

pState bfs()
{
    pState pStart = new State;
    pass_puzzle(pStart->puzzle, source);
    pStart->parent = NULL;
    pStart->i = 1;
    pStart->j = 1;
    pStart->op = 0;
    queue<pState>
        frontier;
    frontier.push(pStart);
    vector<pState> explored;
    while (!frontier.empty())
    {
        pState state = frontier.front();
        frontier.pop();
        if (goal_check(state))
            return state;
        explored.push_back(state);

        for (int op = 1; op <= 4; ++op)
        {
            pState newState = call_op(state, op);
            if (newState != NULL)
            {
                if (found_state(newState, explored))
                    continue;
                frontier.push(newState);
            }
        }
    }
    return NULL;
}

void trace(pState s, stack<pState> &ans)
{
    if (s == NULL)
        return;
    ans.push(s);
    trace(s->parent, ans);
}

void print_ans(stack<pState> &ans)
{
    int i = 0;
    while (ans.size())
    {
        print(ans.top(), i++), ans.pop(), 0;
    }
}
void process(string algo)
{
    stack<pState> ans;
    trace(algo == "BFS" ? bfs() : dfs(), ans);
    cout << "Steps for " << algo << " algorithm: " << ans.size() - 1 << endl;
    print_ans(ans);
}

int main()
{
    debug(source);
    process("BFS");
    cout << "----------------------\n";
    // process("DFS");
    return 0;
}
