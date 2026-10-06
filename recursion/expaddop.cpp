#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<string> addOperators(string num, int target) {
        vector<string> ans;

        solve(0, num, target, "", ans, 0, 0);

        return ans;
    }

    void solve(int index, string num, int target, string curr,
               vector<string>& ans, long long prev, long long res) {

        // Base case
        if(index == num.length()) {
            if(res == target) {
                ans.push_back(curr);
            }
            return;
        }

        string st = "";
        long long currRes = 0;

        for(int i = index; i < num.length(); i++) {

            // Prevent leading zeros like 05, 012
            if(i > index && num[index] == '0')
                break;

            st += num[i];

            // Convert string into number
            currRes = currRes * 10 + (num[i] - '0');

            // First number
            if(index == 0) {

                solve(i + 1, num, target, st,
                      ans, currRes, currRes);
            }

            else {

                // Addition
                solve(i + 1, num, target,
                      curr + "+" + st,
                      ans,
                      currRes,
                      res + currRes);

                // Subtraction
                solve(i + 1, num, target,
                      curr + "-" + st,
                      ans,
                      -currRes,
                      res - currRes);

                // Multiplication
                solve(i + 1, num, target,
                      curr + "*" + st,
                      ans,
                      prev * currRes,
                      res - prev + (prev * currRes));
            }
        }
    }
};

int main() {

    string num = "123";
    int target = 6;

    Solution obj;

    vector<string> ans = obj.addOperators(num, target);

    cout << "Expressions that give " << target << ":\n";

    for(string expression : ans) {
        cout << expression << endl;
    }

    return 0;
}