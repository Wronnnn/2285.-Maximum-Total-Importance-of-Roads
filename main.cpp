#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static bool desc(vector<int> a, vector<int> b){
        return a.at(1) > b.at(1);
    }

    long long maximumImportance(int n, vector<vector<int>>& roads) {
        unsigned long long ret = 0;
        vector<vector<int>> cityConnections(n, vector<int>(2));
        for(int i=0;i<n;i++){
            cityConnections.at(i).at(0) = i;
        }
        for(int i=0;i<roads.size();i++){
            cityConnections.at(roads.at(i).at(0)).at(1)++;
            cityConnections.at(roads.at(i).at(1)).at(1)++;
        }
        sort(cityConnections.begin(), cityConnections.end(), desc);
        for(int i=0;i<cityConnections.size();i++){
            ret += (unsigned long long int)cityConnections.at(i).at(1) * (unsigned long long int)(n - i);
        }
        return ret;
    }
};

int main(){
    vector<vector<int>> roads = {{0, 3}, {2, 4}, {1, 3}};
    int n = 5;
    Solution temp;
    cout<<temp.maximumImportance(n, roads);
    return 0;
}