#include <bits/stdc++.h>
#define debug(a) cout << #a << ": " << a << endl
#define fto(i,x,y) for (int i = (x); i <= (y); ++i)
#define fdto(i,x,y) for (int i = (x); i >= (y); --i)
#define forit(it, var) for (__typeof(var.begin()) it = var.begin(); it != var.end(); ++it)
#define forrit(rit, var) for (__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); ++rit)
#define vi vector<int>
#define ms(a, x) memset(a, x, sizeof a)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define ll long long
#define ull unsigned long long
#define db double
#define EPS 1e-9
#define oo 1000000007
#define maxN 105

using namespace std;

int iT,x,y,X,Y;
char a[maxN][maxN];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
string s;
string p;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
    bool firstline = true;
    while (1){
    	fto(i,1,5){
    		getline(cin, s);
    		if (s=="Z") {
	    		return 0;
			}
    		if (s.length() == 4) s+=' ';
    		fto(j,1,5) {
    			a[i][j] = s[j-1];
    			if (a[i][j] == ' '){
    				x = i;
    				y = j;
    			}
    		}
    	}
    	p = "";
    	while (getline(cin, s) ){
    		p+=s;
    		if (s[s.length()-1] == '0') break;
    	}
    
    	bool ok = true;
    	if (p.length()==1) {
    		if (iT!=0) printf("\n");
    		printf("Puzzle #%d:\n", ++iT);	
    		fto(i,1,5){
	    		fto(j,1,5) {
	    			printf("%c", a[i][j]);
	    			if (j != 5) printf(" ");
	    		}
	    		puts("");
	    	}
	    	continue;
    	}
    	fto(k,0,p.length()-2){
    		//cout << p[k];
    		if (p[k] == 'A'){
    			X = x - 1;
    			Y = y;
    		} else
    		if (p[k] == 'B'){
    			X = x + 1;
    			Y = y;
    		} else
    		if (p[k] == 'R'){
    			X = x;
    			Y = y+1;
    		} else
    		if (p[k] == 'L'){
    			X = x;
    			Y = y-1;
    		} else{
    			ok = false;
    			break;
    		}
    		if (X < 1 || X > 5 || Y < 1 || Y > 5) {
    			ok = false;
    			break;
    		}
    		a[x][y] = a[X][Y];
    		x = X; y = Y;
    		a[x][y] = ' ';
    	}
    	if (iT!=0) printf("\n");
    	printf("Puzzle #%d:\n", ++iT);
    	if (!ok) puts("This puzzle has no final configuration.");
    	else 
    	fto(i,1,5){
    		fto(j,1,5) {
    			printf("%c", a[i][j]);
    			if (j != 5) printf(" ");
    		}
    		puts("");
    	}
    	
    }
    return 0;
}

