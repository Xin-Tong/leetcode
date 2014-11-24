class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {

       
        for(int i=0; i<9; i++){
            vector<bool> maski(10,false);
            vector<bool> maskj(10,false); //need to use index 9
            for(int j=0; j<9; j++){
                if(board[i][j] != '.'){
                    if(maski[int(board[i][j] - '0')] == false){
                        maski[int(board[i][j] - '0')] = true;
                    }
                    else return false;
                }
                if(board[j][i] != '.'){
                    if(maskj[int(board[j][i] - '0')] == false){
                        maskj[int(board[j][i] - '0')] = true;
                    }
                    else return false;
                }
            }
            for(int i=0; i<9; i+=3){
                for(int j=0; j<9; j+=3){
                    vector<bool> mask(10, false);
                    for(int m=0; m<3; m++){
                        for(int n=0; n<3; n++){
                            if(board[i+m][j+n] != '.'){
                                if(mask[int(board[i+m][j+n] - '0')] == false){
                                    mask[int(board[i+m][j+n] - '0')] = true;
                                }
                                else return false;
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};