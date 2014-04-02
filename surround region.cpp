    void solve(vector<vector<char>> &board) {
        for(int i=0;i<board.size();i++){
            if(board[i][0]=='O')
                flood(0,i,board);
            if(board[i][board[0].size()-1]=='O')
                flood(board[0].size()-1,i,board);
        }
        if(board.size()==0)
        return;
        for(int i=0;i<board[0].size();i++){
            if(board[0][i]=='O')
                flood(i,0,board);
            if(board[board.size()-1][i]=='O')
                flood(i,board.size()-1,board);
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='O')
                    board[i][j]='X';
            }
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='a')
                    board[i][j]='O';
            }
        }
        
    }
    
    void flood(int const& x,int const& y,vector<vector<char>> &board){
        board[y][x]='a';
        if(x-1>0 && board[y][x-1]=='O'){
            flood(x-1,y,board);
        }if(y-1>0 && board[y-1][x]=='O'){
            flood(x,y-1,board);
        }if(x+1<board[0].size() && board[y][x+1]=='O'){
            flood(x+1,y,board);
        }if(y+1<board.size() && board[y+1][x]=='O'){
            flood(x,y+1,board);
        }
        
        
    }