#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
    unordered_map<string, int> memo;

    string reduceBoard(string board) {
        int n = board.size();
        for (int i = 0, j = 0; i < n; ++i) {
            if (i == n - 1 || board[i] != board[i + 1]) {
                if (i - j + 1 >= 3) {
                    return reduceBoard(board.substr(0, j) + board.substr(i + 1));
                }
                j = i + 1;
            }
        }
        return board;
    }

    int dfs(string board, string hand) {
        board = reduceBoard(board);
        if (board.empty()) return 0;
        if (hand.empty()) return -1;

        string key = board + "|" + hand;
        if (memo.count(key)) return memo[key];

        int res = INT_MAX;

        for (int i = 0; i < hand.size(); ++i) {
            for (int j = 0; j <= board.size(); ++j) {
                string newBoard = board.substr(0, j) + hand[i] + board.substr(j);
                string newHand = hand.substr(0, i) + hand.substr(i + 1);

                int next = dfs(newBoard, newHand);
                if (next != -1) {
                    res = min(res, next + 1);
                }
            }
        }

        return memo[key] = (res == INT_MAX ? -1 : res);
    }

public:
    int findMinStep(string board, string hand) {
        return dfs(board, hand);
    }
};

int main() {
    string board, hand;
    cout << "Enter the board: ";
    cin >> board;
    cout << "Enter the hand: ";
    cin >> hand;

    Solution solution;
    int result = solution.findMinStep(board, hand);
    cout << "Minimum number of balls to clear the board: " << result << endl;

    return 0;
}
