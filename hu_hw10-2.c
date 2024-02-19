#include<stdio.h>
#include<stdlib.h>
typedef struct
{
    int num;
    struct floor *d[4];
} floor;
int Q, T, dir, val;
const int rdir[]={2,3,0,1};
floor* floor_create(int dir, int val, floor* pre)
{
    floor* flr = malloc(sizeof(floor));
    flr->num = val;
    flr->d[dir] = pre;
    return flr;
}
int main(){
    floor *curr, *portal;
    portal = curr = floor_create(0, 0, NULL);
    for(scanf("%d", &Q);Q--;){
        scanf("%d", &T);
        if(T == 1) {
            scanf("%d %d", &dir, &val);
            curr->d[dir] = floor_create(rdir[dir], val, curr);
        } else if(T == 2) {
            scanf("%d", &dir);
            curr = curr->d[dir];
        } else if(T == 3) {
            scanf("%d", &val);
            curr -> num = val;
        } else if(T == 4) {
            printf("%d\n", curr->num);
        } else if(T == 5) {
            portal = curr;
        } else {
            curr = portal;
        }
    }
}

