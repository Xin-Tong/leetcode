#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > WordSearch(vector<vector<char> > &board, string word){
int len = word.size();
int row = board.size();
int col = board[0].size();
vector<vector<int> > res;
if(len < 1 || row < 1 || col < 1) return res;
vector<int>  temp(4);
for(int i = 0; i < row; i++){
    for(int j = 0; j< col; j++){
        int k;
        for(k=0; k<len&&(j+k)<col; k++){
            if (board[i][j+k] != word[k])
                break;
        }
        if(k==len)
        temp[0] = i, temp[1] = j, temp[2] = i, temp[3] = j+k, res.push_back(temp);
        for(k=0; k<len&&(i+k)<row; k++){
            if (board[i+k][j] != word[k])
                break;
        }
        if(k==len)
        temp[0] = i, temp[1] = j, temp[2] = i+k, temp[3] = j, res.push_back(temp);
    }
}
return res;
}

int main(){
    vector<vector<char> > board;
    char a1[] = {'a', 'b', 'b', 'c', 'a'}; vector<char> c1(a1, a1 + sizeof(a1)/sizeof(char));
    char a2[] = {'b', 'c', 'a', 'b', 'b'}; vector<char> c2(a2, a2 + sizeof(a2)/sizeof(char));
    char a3[] = {'b', 'a', 'b', 'b', 'b'}; vector<char> c3(a3, a3 + sizeof(a3)/sizeof(char));
    char a4[] = {'a', 'b', 'b', 'c', 'a'}; vector<char> c4(a4, a4 + sizeof(a4)/sizeof(char));
    board.push_back(c1);
    board.push_back(c2);
    board.push_back(c3);
    board.push_back(c4);

    vector<vector<int> > res = WordSearch(board, "abb");
    for(int i = 0; i < (int)(res.size()); i++)
        cout << res[i][0] << "," << res[i][1] <<" - " << res[i][2] << "," << res[i][3] << endl;

    cout << endl;
    res = WordSearch(board, "cab");
    for(int i = 0; i < (int)res.size(); i++)
        cout << res[i][0] << "," << res[i][1] <<" - " << res[i][2] << "," << res[i][3] << endl;
    return 0;
}
