#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;


struct Mon{
    int a;//a是第i个怪兽生命值
    int b;//b是第j个怪兽防御力
};//怪兽

struct Skill{
    int p;//第i个技能攻击力p
    int k;//第i个技能消耗的晶石数
};//技能

bool  cmp(Skill a, Skill b){

    return a.p < b.p ? 1 : 0;
}

int main()
{
    int m, n, i, j;
    int cnt = 0;//cnt为晶石的个数
    Mon *mon;
    Skill *skill;

    while(~scanf("%d %d", &n, &m)){
        mon= new Mon[n];
        skill= new Skill[m];

        for(i = 0; i < n; i++){
            cin >> mon[i].a >> mon[i].b;
        }

        for(i = 0; i < m; i++){
            cin >> skill[i].k >> skill[i].p;
        }

        //对攻击力和技能消耗进行排序
        sort(skill,skill + m, cmp);

        //开始打怪兽
        for (i = 0; i < n; i++){
            for(j = 0; j < m; j++){
                if(mon[i].a <= 0){
                    continue;
                }
                if(skill[j].p - mon[i].b < 0){
                    continue;
                }
                if(mon[i].a>0){
                    mon[i].a -= skill[j].p - mon[i].b;
                    cnt += skill[j].k;
                }
            }
        }

        for(i = 0; i < n; i++){
            if(mon[i].a > 0){
                cnt = -1;
                break;
            }
        }

        cout << cnt << endl;
        cnt = 0;
        delete mon;
        delete skill;
    }


    return 0;
}
