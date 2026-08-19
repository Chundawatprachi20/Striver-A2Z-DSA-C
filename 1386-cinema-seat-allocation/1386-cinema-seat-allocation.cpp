#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        
        unordered_map<int, unordered_set<int>> reserved;
        
        // Store reserved seats for each row
        for (auto &seat : reservedSeats) {
            reserved[seat[0]].insert(seat[1]);
        }
        
        // Initially assume every row can accommodate 2 families
        int answer = n * 2;
        
        // Check only rows that have reserved seats
        for (auto &row : reserved) {
            
            int r = row.first;
            auto &seats = row.second;
            
            bool left = true;
            bool middle = true;
            bool right = true;
            
            // Check seats 2,3,4,5
            for (int i = 2; i <= 5; i++) {
                if (seats.count(i)) {
                    left = false;
                }
            }
            
            // Check seats 4,5,6,7
            for (int i = 4; i <= 7; i++) {
                if (seats.count(i)) {
                    middle = false;
                }
            }
            
            // Check seats 6,7,8,9
            for (int i = 6; i <= 9; i++) {
                if (seats.count(i)) {
                    right = false;
                }
            }
            
            // Remove the assumed 2 groups for this row
            answer -= 2;
            
            if (left && right) {
                answer += 2;
            }
            else if (left || middle || right) {
                answer += 1;
            }
        }
        
        return answer;
    }
};