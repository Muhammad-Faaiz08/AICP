#include<iostream>
using namespace std;
class TicTacToe
{
private:
    char b[3][3];
    char cp;
public:
    TicTacToe():cp('X')
    {
        for(int i=0;i<3;++i)
        {
          for(int j=0;j<3;++j)
          {
           b[i][j]=' ';
          }
        }
    }
    void printBoard()
    {
        cout<<endl;
        cout<<" Current board: "<<endl;
        cout<<endl;
        cout<<"    0      1     2"<<endl;
        for(int i=0;i<3;i++)
            {
                cout<<" "<<i<<"   ";
            for(int j=0;j<3;j++)
            {
                cout<<b[i][j];
                if(j<2)
                {
                 cout<<"  |  ";
                }
            }
            cout<<endl;
            if(i<2)
            {
                cout<<"   -----------------"<<endl;
            }
        }
    }
    bool makeMove(int r,int c)
    {
        if(r>=0 && r<3 && c>=0 && c<3 && b[r][c]==' ')
        {
            cout<<"        ";
            b[r][c]=cp;
            return true;
        }
        return false;
    }
    bool checkWin()
    {
        for(int i=0;i<3;++i)
        {
            if(b[i][0]==cp && b[i][1]==cp && b[i][2]==cp)
            {
               return true;
            }
            if(b[0][i]==cp && b[1][i]==cp && b[2][i]==cp)
            {
               return true;
            }
        }
        if(b[0][0]==cp && b[1][1]==cp && b[2][2]==cp)
            {
               return true;
            }
        if(b[0][2]==cp && b[1][1]==cp && b[2][0]==cp)
            {
               return true;
            }
        return false;
    }
    bool checkDraw()
    {
        for(int i=0;i<3;++i)
            {
            for(int j=0;j<3;++j)
            {
                if(b[i][j]==' ')
                {
                    return false;
                }
            }
        }
        return true;
    }
    void switchPlayer()
    {
        cp=(cp=='X')?'O':'X';
    }
    bool validMove(bool gameWon,bool gameDraw)
    {
       if(!gameWon && !gameDraw)
        {
           switchPlayer();
        }
    }
    bool gameStatus(bool gameWon,bool gameDraw)
    {
      if(gameWon)
        {
            cout<<endl;
            cout<<"\t\t |-- Player "<<cp<<" wins! --|"<<endl;
            cout<<endl;
        }
        else if(gameDraw)
        {
            cout<<endl;
            cout<<"\t\t |-- The game is a draw. --|"<<endl;
            cout<<endl;
        }
    }
    void play()
    {
        int r,c;
        bool gameWon =false,gameDraw=false;
        cout<<endl;
        cout<<"\t\t\t\t |-- Tic-Tac-Toe --| "<<endl;
        cout<<endl;
        cout<<" Welcome to Tic-Tac-Toe! "<<endl;
        while(!gameWon && !gameDraw)
        {
            printBoard();
            cout<<endl;
            cout<<" |-- Player "<<cp<<" --|"<<endl;
            cout<<endl;
            cout<<" Enter your move (row and column): ";
            cin>>r>>c;
            system("cls");
            if(makeMove(r,c))
            {
                gameWon=checkWin();
                gameDraw=checkDraw();
                validMove(gameWon,gameDraw);
            }
        }
        printBoard();
        gameStatus(gameWon,gameDraw);
    }
};
int main()
{
    TicTacToe game;
    game.play();
    return 0;
}

