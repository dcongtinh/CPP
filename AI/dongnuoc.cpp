/**
 * Author: Dao Cong Tinh dcongtinh@ferdon.io
 * Description: Solution for water problem. 
 * **/
#include <bits/stdc++.h>

using namespace std;

int X = 9, Y = 4, Z = 6;
string OP[] = {"Khoi tao", "Do y sang x", "Do x sang y", "Lam day x", "Lam day y", "Lam rong x", "Lam rong y"};
typedef struct State *pState;
struct State
{
    int x, y;
    pState parent;
    int op;
};

void print(pState s, int index)
{
    if (s == NULL)
        cout << "NULL\n";
    else
        printf("%2d. %d, %d (%s)\n", index, s->x, s->y, OP[s->op].c_str());
}

bool goal_check(pState s)
{
    return (s->x == Z || s->y == Z);
}

//operator 1
pState Cyx(pState s)
{
    if (s->y > 0 && s->x < X)
    {
        pState newState = new State;
        newState->x = min(s->x + s->y, X);
        newState->y = max(s->x + s->y - X, 0);
        newState->parent = s;
        newState->op = 1;
        return newState;
    }
    return NULL;
}

//operator 2
pState Cxy(pState s)
{
    if (s->x > 0 && s->y < Y)
    {
        pState newState = new State;
        newState->y = min(s->x + s->y, Y);
        newState->x = max(s->x + s->y - Y, 0);
        newState->parent = s;
        newState->op = 2;
        return newState;
    }
    return NULL;
}

//operator 3
pState LamdayX(pState s)
{
    if (s->x < X)
    {
        pState newState = new State;
        newState->x = X;
        newState->y = s->y;
        newState->parent = s;
        newState->op = 3;
        return newState;
    }
    return NULL;
}

//operator 4
pState LamdayY(pState s)
{
    if (s->y < Y)
    {
        pState newState = new State;
        newState->x = s->x;
        newState->y = Y;
        newState->parent = s;
        newState->op = 4;
        return newState;
    }
    return NULL;
}

//operator 5
pState LamrongX(pState s)
{
    if (s->x)
    {
        pState newState = new State;
        newState->x = 0;
        newState->y = s->y;
        newState->parent = s;
        newState->op = 5;
        return newState;
    }
    return NULL;
}

//operator 6
pState LamrongY(pState s)
{
    if (s->y)
    {
        pState newState = new State;
        newState->x = s->x;
        newState->y = 0;
        newState->parent = s;
        newState->op = 6;
        return newState;
    }
    return NULL;
}

pState call_op(pState s, int op)
{
    switch (op)
    {
    case 1:
        return Cyx(s);
    case 2:
        return Cxy(s);
    case 3:
        return LamdayX(s);
    case 4:
        return LamdayY(s);
    case 5:
        return LamrongX(s);
    case 6:
        return LamrongY(s);
    default:
        return NULL;
    }
}

bool found_state(pState s, vector<pState> open_list)
{
    for (int i = 0; i < open_list.size(); ++i)
    {
        pState tmp = open_list[i];
        if (s->x == tmp->x && s->y == tmp->y)
            return true;
    }
    return false;
}

pState dfs()
{
    pState pStart = new State;
    pStart->x = pStart->y = 0;
    pStart->parent = NULL;
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

        for (int op = 1; op <= 6; ++op)
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
    pStart->x = pStart->y = 0;
    pStart->parent = NULL;
    pStart->op = 0;

    queue<pState> frontier;
    frontier.push(pStart);
    vector<pState> explored;
    while (!frontier.empty())
    {
        pState state = frontier.front();
        frontier.pop();
        if (goal_check(state))
            return state;
        explored.push_back(state);

        for (int op = 1; op <= 6; ++op)
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
    process("BFS");
    cout << "----------------------\n";
    process("DFS");
    return 0;
}
