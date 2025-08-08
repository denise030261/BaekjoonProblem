#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    vector<int> main;
    vector<int> sub;
    for(int i=order.size();i>=1;i--)
    {
        main.push_back(i);
    }
    
    for(int i=0;i<order.size();i++)
    {
        bool done=false;
        
        while(!main.empty())
        {
            int cur = main.back();
            
            if(cur==order[i])
            {
                //cout << "메인에 " << cur <<" 넣기 : "<<order[i]<<'\n';
                answer++;
                main.pop_back();
                done=true;
                break;
            }
            else
            {   
                int curSub=sub.back();
                if(!sub.empty() && curSub == order[i])
                {
                    //cout << "서브에 " << curSub <<" 넣기 : "<<order[i]<<'\n';
                    sub.pop_back();
                    answer++;
                    done=true;
                    break;
                }
                else 
                {
                    //cout << "서브만 " << cur <<" 넣기 : "<<order[i]<<'\n';
                    sub.push_back(cur);
                    main.pop_back();
                }
            }
        }
        
        if(done)
            continue;
        
        if(!sub.empty() && sub.back() == order[i])
        {
            //cout << "메인 끝나고 서브에 " << sub.back() <<" 넣기 : "<<order[i]<<'\n';
            sub.pop_back();
            answer++;
        }
        else
        {
            break;
        }
    }
    
    
    return answer;
}