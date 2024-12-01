#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer =0;
    for(int i=0;i<skill_trees.size();i++)
    {
        int sill_index=0;
        bool enable=true;
        for(int j=0;j<skill_trees[i].length();j++)
        {
            if(!enable)
                break;
            
            for(int k=0;k<skill.length();k++)
            {
                if(sill_index<k && skill_trees[i][j]==skill[k])
                {
                    enable=false;
                    break;
                }
            }
            
            if(skill[sill_index] ==skill_trees[i][j])
            {
                sill_index++;
            }
        }
        
        if(enable)
            answer++;
    }
    return answer;
}