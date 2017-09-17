#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;


struct Mon{
    int a;//a�ǵ�i����������ֵ
    int b;//b�ǵ�j�����޷�����
};//����

struct Skill{
    int p;//��i�����ܹ�����p
    int k;//��i���������ĵľ�ʯ��
};//����

bool  cmp(Skill a, Skill b){

    return a.p < b.p ? 1 : 0;
}

int main()
{
    int m, n, i, j;
    int cnt = 0;//cntΪ��ʯ�ĸ���
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

        //�Թ������ͼ������Ľ�������
        sort(skill,skill + m, cmp);

        //��ʼ�����
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
