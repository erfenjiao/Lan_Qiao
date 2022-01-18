#include<iostream>
using namespace std;
//剪开的边线关于（３，３）对称，于是从（３，３）开始搜索，直到边界为止
//需要注意的是要从（3，3）点开始向两个方向同时搜索，并且这里两个方向是相反的。
//最后得出的结果要除以4，因为旋转堆成的属于同一种分割法。
int dis[4][2] = {0,1,0,-1,1,0,-1,0};
int vis[10][10];
int ans = 0;

void dfs(int x , int y)
{
    if(x == 0 || y == 0 || x == 6 || y == 6)
    {
        ans++;
        return ;
    }
    for(int i = 0 ; i < 4 ; i++)
    {
        int x1 = x + dis[i][0];
        int y1 = y + dis[i][1];

        int x2 = 6 - x1;
        int y2 = 6 - y1;

        if(x1 >= 0 && x1 <= 6 && y1 >= 0 && y1 <= 6)
        {
            if(!vis[x1][y1])
            {
                vis[x1][y1] = vis[x2][y2] = 1;
                dfs(x1 , y1);
                vis[x1][y1] = vis[x2][y2] = 0;
            }
        }
    }
}

int main()
{
    vis[3][3] = 1;
    dfs(3 , 3);
    cout << "ans/4 = " << ans/4;

}