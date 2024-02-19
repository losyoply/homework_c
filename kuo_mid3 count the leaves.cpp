#include <cstdio> // C++ equivalent of stdio.h
#include <cstring> // C++ equivalent of string.h

using namespace std;

// It's possible to pack the two bool arrays into a bit field, taking only 1001 bytes.

int main()
{
    int N;
    bool is_leaf[1001];
    bool exists[1001];
    while (scanf("%d", &N)) {
        if (N == 0) break;
        memset(is_leaf, true, sizeof(is_leaf));
        memset(exists, false, sizeof(exists));
        int leaf_count = 0;
        int parent, child, root;
        while (N--) {
            scanf("%d %d", &parent, &child);
            is_leaf[parent] = false;
            //exists[parent] = true;
            exists[child] = true;
        }
        scanf("%d", &root);
        exists[root] = true;
        for (int i = 0; i < 1001; i++) if (exists[i] && is_leaf[i]) leaf_count++;
        printf("%d\n", leaf_count);
    }


    return 0;
}


// By IntSys
//不需要真的用edge list造出樹，只需要找出那些出現過的點不曾被作為parent出現在輸入裡就行了。
//////

#include<bits/stdc++.h>
using namespace std;



int main(){
    int n, a, b;

    while(cin >> n){
        if(n == 0) break;
        int count = 0, root;
        vector<int> node[1001];

        for(int i = 0 ; i < n ; i++){
            cin >> a >> b;
            node[a].push_back(b);
        }
        cin >> root;

        queue<int> Q;
        Q.push(root);

        while(!Q.empty()){
            int cur = Q.front();
            Q.pop();

            if(node[cur].empty()){
                count++;
                continue;
            }

            for(auto next : node[cur]){
                Q.push(next);
            }
        }

        cout << count << endl;
    }
}
