#include<bits/stdc++.h>
using namespace std;

//spot //piece //Board //Move //Players //Game

class Board;
class Piece;
class Players;
class Move;
class Game;
class Spot;

class Spot{

private:
	Piece* piece;
	int row;
	int col;

public:
	Spot() : piece(nullptr), row(0), col(0) {} 
	Spot(Piece* piece, int row, int col):piece(piece)
	{
		this->row   = row;
		this->col   = col; 
	}
	Piece* getPiece()
	{
		return piece;
	}

	int getRow()
	{
		return row;
	}

	int getCol()
	{
		return col;
	}

	void setRow(int row)
	{
		this->row = row;
	}

	void setCol(int col)
	{
		this->col = col;
	}
};


class Board{

public:
   Spot boxes[8][8];
   Board()
   {
    resetBoard();
   }

   Spot getBox(int row,int col)
   {

   }

   void resetBoard()
   {

   }
};

class Piece{

private:
	bool killed = false;
	bool white  = false;
public :
    Piece(bool white)
    {
    	this->white = white;
    }

    bool isWhite()
    {
    	return white;
    }

    bool isKilled()
    {
    	return killed;
    }

    void setKilled(bool killed)
    {
    	this->killed = killed;
    }

    virtual void canMove(Board board, Spot start, Spot end) = 0;

};

class Players{

private:
	string player1;
	string player2;
	bool isWhiteSide;

public:
	Players(){}
	Players(string player1, string player2)
	{
         setPlayer1(player1);
         setPlayer2(player2);
	}

	string setPlayer1(string player1)
	{
       this->player1     = player1;
       this->isWhiteSide = true;
	}

	string setPlayer2(string player2)
	{
       this->player2     = player2;
       this->isWhiteSide = false;
	}

	string getPlayer1()
	{
		return player1;
	}

	string getPlayer2()
	{
		return player2;
	}

};

class Move
{
	private :

	 Players player;
	 Spot start;
	 Spot end;
	 Piece *pieceMoved;

	public:

	 Move(Players player, Spot start, Spot end, Piece* pieceMoved) : player( player), start(start), end(end), pieceMoved(pieceMoved)
	 { 
	 	/*
         this->player      = player;
         this->start       = start;
         this->end         = end;
         this->pieceMoved  = pieceMoved;
         */
	 }

};

class Game{
    
  public:
    Players players[2];
    Board board;
    Players currentTurn;
    vector<Move> moveList;
   
   Game(){

   }

   void playerMove(Players player, int startCol, int startRow, int startEnd, int endRow, int endCol, Piece* piece)
   {
   	Spot startBox(piece, startRow, startCol);
   	Spot endBox(piece, endRow, endCol);
   	Move move(player, startBox, endBox, piece);
   }

};


int main()
{
	cout<<"hello";
}



