#include <iostream>
#include <vector>
#include <algorithm> 
#include <climits>   

using namespace std;

int bottom_height_count[500001] = { 0, }; 
int top_stop_pos_count[500001] = { 0, };   

int bottom_hits[500001] = { 0, };
int top_hits[500001] = { 0, };   

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, H;
    cin >> N >> H;

    for (int i = 0; i < N / 2; i++)
    {
        int a, b; 
        cin >> a >> b;

        bottom_height_count[a]++;    
        top_stop_pos_count[H - b + 1]++; 
    }

    bottom_hits[H] = bottom_height_count[H];
    for (int i = H - 1; i >= 1; i--)
    {
        bottom_hits[i] = bottom_hits[i + 1] + bottom_height_count[i];
    }

    top_hits[1] = top_stop_pos_count[1];
    for (int i = 2; i <= H; i++)
    {
        top_hits[i] = top_hits[i - 1] + top_stop_pos_count[i];
    }

    int min_val = INT_MAX;
    int count = 0;

    for (int i = 1; i <= H; i++)
    {
        int total_hits = bottom_hits[i] + top_hits[i];
        if (total_hits < min_val) 
        {
            min_val = total_hits;
            count = 1; 
        }
        else if (total_hits == min_val)
        {
            count++; 
        }
    }

    cout << min_val << ' ' << count;
}