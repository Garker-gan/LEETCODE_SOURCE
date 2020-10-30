/* 
    稳定婚姻匹配算法（Gale-Shapely算法）
    Garker-gan
    2020-10-30
    算法原理：
    第一轮，每个男人都选择自己名单上排在首位的女人，并向她表白。这种时候会出现两种情况
    （1）该女士还没有被男生追求过，则该女士接受该男生的请求。
    （2）若该女生已经接受过其他男生的追求，那么该女生会将该男士与她的现任男友进行比较，
        若更喜欢她的男友，那么拒绝这个人的追求，
        否则，抛弃其男友第一轮结束后，有些男人已经有女朋友了，有些男人仍然是单身。
        在第二轮追女行动中，每个单身男都从所有还没拒绝过他的女孩中选出自己最中意的那一个，
        并向她表白，不管她现在是否是单身。这种时候还是会遇到上面所说的两种情况，
        还是同样的解决方案。直到所有人都不再是单身。
 */
#include<iostream>
#include<string>

using namespace std;

// 测试用例 3男3女 
#define n 3
string boy[n] = {"Mike","Peter","Teddy"};
string girl[n] = {"Andy","Nancy","Lucy"};

//各自心中的意向排名
int preferBoy[n][n] = {{0,1,2},{1,2,0},{2,0,1}};
int preferGirl[n][n] = {{0,1,2},{1,2,0},{2,0,1}};
int heartRank[n][n] = {0};     //女孩心中男孩的排名
// string preferBoy[3][3] = {{"Mike","Peter","Teddy"},{"Peter","Teddy","Mike"},{"Teddy","Mike","Peter"}};      //0.Andy 1.Nancy 2.Lucy对应的中意程度
// string prefergirl[3][3] = {{"Andy","Nancy","Lucy"},{"Nancy","Lucy","Andy"},{"Lucy","Andy","Nancy"}};        //0.Mike 1.Peter 2.Teddy对应的中意程度

bool singleGirl[n] = {true,true,true};        //女孩的单身状态，true为单身
bool singleBoy[n] = {true,true,true};        //男孩的单身状态，true为单身
int girlFriend[n];   //存放男孩找到的女朋友
int boyFriend[n];   //存放男孩找到的女朋友

//判断是否全部脱单
bool allNoSingle(bool single[],int num)
{
    int count = 0;
    for (int i = 0; i < num; i++)
    {
        if(single[i])
            count++;
    }
    if(count == 0)  return true;
    else    return false;  
}

//假设男追女
void Gale_Shapely(int num)
{
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            heartRank[i][preferBoy[i][j]] = j;       //男还j在女孩i心中的排名
        }
    }

    int loveGirl;       //男孩目前追求对象
    int coBoyFriend;    //女孩现男友
    while (!allNoSingle(singleBoy,num))
    {
        for(int i = 0;i < num;i++)
        {
            if(singleBoy[i])
            {
                //每个男孩像排在首位的女生表白
                loveGirl = preferGirl[i][0];
                //如果还没有男生像这个女生表白，则接受;如果有男朋友，则进行比较，选择最好的一个
                if(singleGirl[loveGirl])
                {
                    girlFriend[i] = loveGirl;   //女孩loveGirl为男孩i的女朋友
                    boyFriend[loveGirl] = i;    //男孩i为女孩loveGirl的男朋友
                    singleGirl[loveGirl] = false;
                    singleBoy[i] = false;
                }
                else
                {
                    coBoyFriend = boyFriend[loveGirl];
                    if(heartRank[loveGirl][coBoyFriend] > heartRank[loveGirl][i])   
                    {
                        boyFriend[loveGirl] = i;
                        singleBoy[i] = false;
                        singleBoy[coBoyFriend] = true;
                    }
                }
            }
        }
    }
    
}

int main()
{   
    system("cls");
    Gale_Shapely(n);
    cout<<"Match successfully!"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<boy[i]<<"'s girlfriend is:"<<girl[girlFriend[i]]<<endl;
    }
    
    return 0;
}

