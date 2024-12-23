#include<iostream>
#include"Project2-A05142548-connectFour.h"
#include<time.h>


using namespace std;

int nm = 0;
void procedure1(int ev1,int ev2,int d,Player p1){
   
	
	vector<pair<int,int>> p1Moves = p1.player1Moves;
	vector<pair<int,int>> p2Moves = p1.player2Moves;
	if(nm == 0){
		int frstMv = rand()%7;
		p1.b1[0][frstMv] = "X";
		p1Moves.push_back({0,frstMv});
		p1.printBoard();
		p1.b1[1][frstMv] = "O";
		p2Moves.push_back({1,frstMv});
		p1.printBoard();
	}
	bool result = false;
	
	while(!result){
		
		if(nm == 42){
			result == true;
			cout << "It's a Draw!!" << endl;
		}
		else if(nm%2 == 0){
			pair<int,int> temp = p1.getMinMaxAB(d,ev1,1,p1Moves.back());
			p1.b1[temp.first][temp.second] = "X";
			p1.printBoard();
			//int won = p1.checkWin(p1Moves,temp);
			int won = p1.checkWin("X");
			p1Moves.push_back(temp);
			result = p1.gameOver(won);
			if(result == true)
				cout << "Player 1 won the game." << endl;
		}
		else{
			pair<int,int> temp = p1.getAlphaBeta(d,2,ev2, p2Moves.back());
			p1.b1[temp.first][temp.second] = "O";
			p1.printBoard();
			//int won = p1.checkWin(p2Moves,temp);
			int won = p1.checkWin("O");
			p2Moves.push_back(temp);
			result = p1.gameOver(won);
			if(result == true)
				cout << "Player 2 won the game." << endl;
		}
		nm++;
		//cout << "Result: "<< result << endl;
	}
}

void procedure2(int ev1,int ev2,int d,Player p1){
   
	vector<pair<int,int>> p1Moves = p1.player1Moves;
	vector<pair<int,int>> p2Moves = p1.player2Moves;
	if(nm == 0){
		int frstMv = rand() % 7;
		p1.b1[0][frstMv] = "X";
		p1Moves.push_back({0,frstMv});
		p1.printBoard();
		p1.b1[1][frstMv] = "O";
		p2Moves.push_back({1,frstMv});
		p1.printBoard();
	}
	bool result = false;
	
	while(!result){
		if(nm == 42){
			result == true;
			cout << "It's a Draw!!" << endl;
		}
		if(nm%2 == 0){
			pair<int,int> temp = p1.getMinMaxAB(d,ev1,1,p2Moves.back());
			p1.b1[temp.first][temp.second] = "X";
			p1.printBoard();
			//int won = p1.checkWin(p1Moves,temp);
			int won = p1.checkWin("X");
			p1Moves.push_back(temp);
			result = p1.gameOver(won);
			if(result == true)
				cout << "Player 1 won the game." << endl;
		}
		else{
			pair<int,int> temp = p1.getMinMaxAB(d,ev2,2, p1Moves.back());
			p1.b1[temp.first][temp.second] = "O";
			p1.printBoard();
			//int won = p1.checkWin(p2Moves,temp);
			int won = p1.checkWin("O");
			p2Moves.push_back(temp);
			result = p1.gameOver(won);
			if(result == true)
				cout << "Player 2 won the game." << endl;
		}
		nm++;
	}
}

void procedure3(int ev1,int ev2,int d,Player p1){
   
	vector<pair<int,int>> p1Moves = p1.player1Moves;
	vector<pair<int,int>> p2Moves = p1.player2Moves;
	if(nm == 0){
		int frstMv = rand() % 7;
		p1.b1[0][frstMv] = "X";
		p1Moves.push_back({0,frstMv});
		p1.printBoard();
		p1.b1[1][frstMv] = "O";
		p2Moves.push_back({1,frstMv});
		p1.printBoard();
	}
	bool result = false;
	
	while(!result){
		if(nm == 42){
			result == true;
			cout << "It's a Draw!!" << endl;
		}
		if(nm%2 == 0){
			pair<int,int> temp = p1.getAlphaBeta(d,1,ev1,p1Moves.back());
			p1.b1[temp.first][temp.second] = "X";
			p1.printBoard();
			//int won = p1.checkWin(p1Moves,temp);
			int won = p1.checkWin("X");
			p1Moves.push_back(temp);
			result = p1.gameOver(won);
			if(result == true)
				cout << "Player 1 won the game." << endl;
		}
		else{
			pair<int,int> temp = p1.getAlphaBeta(d,2,ev2, p2Moves.back());
			p1.b1[temp.first][temp.second] = "O";
			p1.printBoard();
			//int won = p1.checkWin(p2Moves,temp);
			int won = p1.checkWin("O");
			p2Moves.push_back(temp);
			result = p1.gameOver(won);
			if(result == true)
				cout << "Player 2 won the game." << endl;
		}
		nm++;
	}
}


int main(){
	const clock_t begin_time = clock();
	srand(time(0));
	Player p1;
	int coordinates = 0;
	cout << "Let's Play the Game of Connect 4!" << endl;
	cout<<" ----------------------------------------------------------------\n";
    cout<<"| 1.Max(MinmaxAB) vs Min(AlphaBetaSearch) eval->1,1         |\n";
    cout<<"| 2.Max(MinmaxAB) vs Min(AlphaBetaSearch) eval->2,2         |\n";
    cout<<"| 3.Max(MinmaxAB) vs Min(AlphaBetaSearch) eval->3,3         |\n";
    cout<<"| 4.Max(MinmaxAB) vs Min(MinmaxAB) eval->1,2                |\n";
    cout<<"| 5.Max(MinmaxAB) vs Min(MinmaxAB) eval->1,3                |\n";
    cout<<"| 6.Max(MinmaxAB) vs Min(MinmaxAB) eval->2,3                |\n";
    cout<<"| 7.Max(AlphabetaSearch) vs Min(AlphaBetaSearch) eval->1,2  |\n";
    cout<<"| 8.Max(AlphabetaSearch) vs Min(AlphaBetaSearch) eval->1,3  |\n";
    cout<<"| 9.Max(AlphaBetaSearch) vs Min(AlphaBetaSearch) eval->2,3  |\n";
    cout<<" ----------------------------------------------------------------\n";
	int d,c;
	cout << "Enter Choice: ";
	cin >> c;
	cout << endl;
	cout << "Enter depth: ";
	cin >> d;
	cout << endl;
	
	
	if(c==1)
    {
		nm = 0;
        cout<<"******* Starting the Game: ******* \n"<<"PLAYER 1: Max(MinmaxAB) vs PLAYER 2: Min(AlphaBetaSearch)"<<endl; 
        cout<<"Player1 evaluation function: "<< 1 <<" and Player2 evaluation function: "<< 1 <<" and Depth: "<<d <<endl;
        cout<<"----------------------------------------------------------------------------------------------\n";
        //intial state of the board..
        cout<<"Initial state of the board"<<endl;
        p1.printBoard();   
        p1.maxDepth=d;
        p1.playerName=1; 
        p1.evalFunc1=1;
        p1.evalFunc2=1;
        procedure1(p1.evalFunc1, p1.evalFunc2, d, p1);
		
		cout<<"----------------------------------------------------------------------------------------------\n";
		cout << "STATISTICS" << endl;
		cout << "Total nodes generated for Player 1: " << p1.getTotalNodesGenerated(1) << endl;
		cout << "Total nodes expanded for Player 1: " << p1.getTotalNodesExpanded(1) << endl;
		cout << "Total nodes generated for Player 2: " << p1.getTotalNodesGenerated(2)<< endl;
		cout << "Total nodes expanded for Player 2: " << p1.getTotalNodesExpanded(2) << endl;
		cout << "Memory used by palyer 1: " << p1.memoryUsed(p1.getTotalNodesGenerated(1)) << " KBs" << endl;
		cout << "Memory used by palyer 2: " << p1.memoryUsed(p1.getTotalNodesGenerated(2)) << " KBs" << endl;
		cout << "Total game length: " << nm << endl;
		cout << "Total Time Taken: " << float( clock () - begin_time )<< " s" << endl;
        cout<<"----------------------------------------------------------------------------------------------\n";
		
    }
	else if (c==2){
		nm = 0;
		cout<<"******* Starting the Game: ******* \n"<<"PLAYER 1: Max(MinmaxAB) vs PLAYER 2: Min(AlphaBetaSearch)"<<endl; 
        cout<<"Player1 evaluation function: "<< 2 <<" and Player2 evaluation function: "<< 2 <<" and Depth: "<<d <<endl;
        cout<<"----------------------------------------------------------------------------------------------\n";
        //intial state of the board..
        cout<<"Initial state of the board"<<endl;
        p1.printBoard();   
        p1.maxDepth=d;
        p1.playerName=1; 
        p1.evalFunc1=2;
        p1.evalFunc2=2;
        procedure1(p1.evalFunc1, p1.evalFunc2, d, p1);

		cout<<"----------------------------------------------------------------------------------------------\n";
		cout << "STATISTICS" << endl;
		cout << "Total nodes generated for Player 1: " << p1.getTotalNodesGenerated(1) << endl;
		cout << "Total nodes expanded for Player 1: " << p1.getTotalNodesExpanded(1) << endl;
		cout << "Total nodes generated for Player 2: " << p1.getTotalNodesGenerated(2)<< endl;
		cout << "Total nodes expanded for Player 2: " << p1.getTotalNodesExpanded(2) << endl;
		cout << "Memory used by palyer 1: " << p1.memoryUsed(p1.getTotalNodesGenerated(1)) << " KBs" << endl;
		cout << "Memory used by palyer 2: " << p1.memoryUsed(p1.getTotalNodesGenerated(2)) << " KBs" << endl;
		cout << "Total game length: " << nm << endl;
		cout << "Total Time Taken: " << float( clock () - begin_time )<< " s" << endl;
        cout<<"----------------------------------------------------------------------------------------------\n";
	}
	else if (c==3){
		nm = 0;
		cout<<"******* Starting the Game: ******* \n"<<"PLAYER 1: Max(MinmaxAB) vs PLAYER 2: Min(AlphaBetaSearch)"<<endl; 
        cout<<"Player1 evaluation function: "<< 3 <<" and Player2 evaluation function: "<< 3 <<" and Depth: "<<d <<endl;
        cout<<"----------------------------------------------------------------------------------------------\n";
        //intial state of the board..
        cout<<"Initial state of the board"<<endl;
        p1.printBoard();   
        p1.maxDepth=d;
        p1.playerName=1; 
        p1.evalFunc1=3;
        p1.evalFunc2=3;
        procedure1(p1.evalFunc1, p1.evalFunc2, d, p1);


		cout<<"----------------------------------------------------------------------------------------------\n";
		cout << "STATISTICS" << endl;
		cout << "Total nodes generated for Player 1: " << p1.getTotalNodesGenerated(1) << endl;
		cout << "Total nodes expanded for Player 1: " << p1.getTotalNodesExpanded(1) << endl;
		cout << "Total nodes generated for Player 2: " << p1.getTotalNodesGenerated(2)<< endl;
		cout << "Total nodes expanded for Player 2: " << p1.getTotalNodesExpanded(2) << endl;
		cout << "Memory used by palyer 1: " << p1.memoryUsed(p1.getTotalNodesGenerated(1)) << " KBs" << endl;
		cout << "Memory used by palyer 2: " << p1.memoryUsed(p1.getTotalNodesGenerated(2)) << " KBs" << endl;
		cout << "Total game length: " << nm << endl;
		cout << "Total Time Taken: " << float( clock () - begin_time )<< " s" << endl;
        cout<<"----------------------------------------------------------------------------------------------\n";
	}
	else if (c==4){
		nm = 0;
		cout<<"******* Starting the Game: ******* \n"<<"PLAYER 1: Max(MinmaxAB) vs PLAYER 2: Min(MinmaxAB)"<<endl; 
        cout<<"Player1 evaluation function: "<< 1 <<" and Player2 evaluation function: "<< 2 <<" and Depth: "<<d <<endl;
        cout<<"----------------------------------------------------------------------------------------------\n";
        //intial state of the board..
        cout<<"Initial state of the board"<<endl;
        p1.printBoard();   
        p1.maxDepth=d;
        p1.playerName=1; 
        p1.evalFunc1=1;
        p1.evalFunc2=2;
        procedure2(p1.evalFunc1, p1.evalFunc2, d, p1);


		cout<<"----------------------------------------------------------------------------------------------\n";
		cout << "STATISTICS" << endl;
		cout << "Total nodes generated for Player 1: " << p1.getTotalNodesGenerated(1) << endl;
		cout << "Total nodes expanded for Player 1: " << p1.getTotalNodesExpanded(1) << endl;
		cout << "Total nodes generated for Player 2: " << p1.getTotalNodesGenerated(2)<< endl;
		cout << "Total nodes expanded for Player 2: " << p1.getTotalNodesExpanded(2) << endl;
		cout << "Memory used by palyer 1: " << p1.memoryUsed(p1.getTotalNodesGenerated(1)) << " KBs" << endl;
		cout << "Memory used by palyer 2: " << p1.memoryUsed(p1.getTotalNodesGenerated(2)) << " KBs" << endl;
		cout << "Total game length: " << nm << endl;
		cout << "Total Time Taken: " << float( clock () - begin_time )<< " s" << endl;
        cout<<"----------------------------------------------------------------------------------------------\n";
	}
	else if (c==5){
		nm = 0;
		cout<<"******* Starting the Game: ******* \n"<<"PLAYER 1: Max(MinmaxAB) vs PLAYER 2: Min(MinmaxAB)"<<endl; 
        cout<<"Player1 evaluation function: "<< 1 <<" and Player2 evaluation function: "<< 3 <<" and Depth: "<<d <<endl;
        cout<<"----------------------------------------------------------------------------------------------\n";
        //intial state of the board..
        cout<<"Initial state of the board"<<endl;
        p1.printBoard();   
        p1.maxDepth=d;
        p1.playerName=1; 
        p1.evalFunc1=1;
        p1.evalFunc2=3;
        procedure2(p1.evalFunc1, p1.evalFunc2, d, p1);

		cout<<"----------------------------------------------------------------------------------------------\n";
		cout << "STATISTICS" << endl;
		cout << "Total nodes generated for Player 1: " << p1.getTotalNodesGenerated(1) << endl;
		cout << "Total nodes expanded for Player 1: " << p1.getTotalNodesExpanded(1) << endl;
		cout << "Total nodes generated for Player 2: " << p1.getTotalNodesGenerated(2)<< endl;
		cout << "Total nodes expanded for Player 2: " << p1.getTotalNodesExpanded(2) << endl;
		cout << "Memory used by palyer 1: " << p1.memoryUsed(p1.getTotalNodesGenerated(1)) << " KBs" << endl;
		cout << "Memory used by palyer 2: " << p1.memoryUsed(p1.getTotalNodesGenerated(2)) << " KBs" << endl;
		cout << "Total game length: " << nm << endl;
		cout << "Total Time Taken: " << float( clock () - begin_time )<< " s" << endl;
        cout<<"----------------------------------------------------------------------------------------------\n";
	}
	else if (c==6){
		nm = 0;
		cout<<"******* Starting the Game: ******* \n"<<"PLAYER 1: Max(MinmaxAB) vs PLAYER 2: Min(MinmaxAB)"<<endl; 
        cout<<"Player1 evaluation function: "<< 2 <<" and Player2 evaluation function: "<< 3 <<" and Depth: "<<d <<endl;
        cout<<"----------------------------------------------------------------------------------------------\n";
        //intial state of the board..
        cout<<"Initial state of the board"<<endl;
        p1.printBoard();   
        p1.maxDepth=d;
        p1.playerName=1; 
        p1.evalFunc1=2;
        p1.evalFunc2=3;
        procedure2(p1.evalFunc1, p1.evalFunc2, d, p1);


		cout<<"----------------------------------------------------------------------------------------------\n";
		cout << "STATISTICS" << endl;
		cout << "Total nodes generated for Player 1: " << p1.getTotalNodesGenerated(1) << endl;
		cout << "Total nodes expanded for Player 1: " << p1.getTotalNodesExpanded(1) << endl;
		cout << "Total nodes generated for Player 2: " << p1.getTotalNodesGenerated(2)<< endl;
		cout << "Total nodes expanded for Player 2: " << p1.getTotalNodesExpanded(2) << endl;
		cout << "Memory used by palyer 1: " << p1.memoryUsed(p1.getTotalNodesGenerated(1)) << " KBs" << endl;
		cout << "Memory used by palyer 2: " << p1.memoryUsed(p1.getTotalNodesGenerated(2)) << " KBs" << endl;
		cout << "Total game length: " << nm << endl;
		cout << "Total Time Taken: " << float( clock () - begin_time )<< " s" << endl;
        cout<<"----------------------------------------------------------------------------------------------\n";
	}
	else if (c==7){
		nm = 0;
		cout<<"******* Starting the Game: ******* \n"<<"PLAYER 1: Max(MinmaxAB) vs PLAYER 2: Min(AlphaBetaSearch)"<<endl; 
        cout<<"Player1 evaluation function: "<< 1 <<" and Player2 evaluation function: "<< 2 <<" and Depth: "<<d <<endl;
        cout<<"----------------------------------------------------------------------------------------------\n";
        //intial state of the board..
        cout<<"Initial state of the board"<<endl;
        p1.printBoard();   
        p1.maxDepth=d;
        p1.playerName=1; 
        p1.evalFunc1=1;
        p1.evalFunc2=2;
        procedure3(p1.evalFunc1, p1.evalFunc2, d, p1);


		cout<<"----------------------------------------------------------------------------------------------\n";
		cout << "STATISTICS" << endl;
		cout << "Total nodes generated for Player 1: " << p1.getTotalNodesGenerated(1) << endl;
		cout << "Total nodes expanded for Player 1: " << p1.getTotalNodesExpanded(1) << endl;
		cout << "Total nodes generated for Player 2: " << p1.getTotalNodesGenerated(2)<< endl;
		cout << "Total nodes expanded for Player 2: " << p1.getTotalNodesExpanded(2) << endl;
		cout << "Memory used by palyer 1: " << p1.memoryUsed(p1.getTotalNodesGenerated(1)) << " KBs" << endl;
		cout << "Memory used by palyer 2: " << p1.memoryUsed(p1.getTotalNodesGenerated(2)) << " KBs" << endl;
		cout << "Total game length: " << nm << endl;
		cout << "Total Time Taken: " << float( clock () - begin_time )<< " s" << endl;
        cout<<"----------------------------------------------------------------------------------------------\n";
	}
	else if (c==8){
		nm = 0;
		cout<<"******* Starting the Game: ******* \n"<<"PLAYER 1: Max(MinmaxAB) vs PLAYER 2: Min(AlphaBetaSearch)"<<endl; 
        cout<<"Player1 evaluation function: "<< 1 <<" and Player2 evaluation function: "<< 3 <<" and Depth: "<<d <<endl;
        cout<<"----------------------------------------------------------------------------------------------\n";
        //intial state of the board..
        cout<<"Initial state of the board"<<endl;
        p1.printBoard();   
        p1.maxDepth=d;
        p1.playerName=1; 
        p1.evalFunc1=1;
        p1.evalFunc2=3;
        procedure3(p1.evalFunc1, p1.evalFunc2, d, p1);
		
		
		cout<<"----------------------------------------------------------------------------------------------\n";
		cout << "STATISTICS" << endl;
		cout << "Total nodes generated for Player 1: " << p1.getTotalNodesGenerated(1) << endl;
		cout << "Total nodes expanded for Player 1: " << p1.getTotalNodesExpanded(1) << endl;
		cout << "Total nodes generated for Player 2: " << p1.getTotalNodesGenerated(2)<< endl;
		cout << "Total nodes expanded for Player 2: " << p1.getTotalNodesExpanded(2) << endl;
		cout << "Memory used by palyer 1: " << p1.memoryUsed(p1.getTotalNodesGenerated(1)) << " KBs" << endl;
		cout << "Memory used by palyer 2: " << p1.memoryUsed(p1.getTotalNodesGenerated(2)) << " KBs" << endl;
		cout << "Total game length: " << nm << endl;
		cout << "Total Time Taken: " << float( clock () - begin_time )<< " s" << endl;
        cout<<"----------------------------------------------------------------------------------------------\n";

	}
	else if (c==9){
		nm = 0;
		cout<<"******* Starting the Game: ******* \n"<<"PLAYER 1: Max(MinmaxAB) vs PLAYER 2: Min(AlphaBetaSearch)"<<endl; 
        cout<<"Player1 evaluation function: "<< 2 <<" and Player2 evaluation function: "<< 3 <<" and Depth: "<< d <<endl;
        cout<<"----------------------------------------------------------------------------------------------\n";
        //intial state of the board..
        cout<<"Initial state of the board"<<endl;
        p1.printBoard();   
        p1.maxDepth=d;
        p1.playerName=1; 
        p1.evalFunc1=2;
        p1.evalFunc2=3;
        procedure3(p1.evalFunc1, p1.evalFunc2, d, p1);
		
		cout<<"----------------------------------------------------------------------------------------------\n";
		cout << "STATISTICS" << endl;
		cout << "Total nodes generated for Player 1: " << p1.getTotalNodesGenerated(1) << endl;
		cout << "Total nodes expanded for Player 1: " << p1.getTotalNodesExpanded(1) << endl;
		cout << "Total nodes generated for Player 2: " << p1.getTotalNodesGenerated(2)<< endl;
		cout << "Total nodes expanded for Player 2: " << p1.getTotalNodesExpanded(2) << endl;
		cout << "Memory used by palyer 1: " << p1.memoryUsed(p1.getTotalNodesGenerated(1)) << " KBs" << endl;
		cout << "Memory used by palyer 2: " << p1.memoryUsed(p1.getTotalNodesGenerated(2)) << " KBs" << endl;
		cout << "Total game length: " << nm << endl;
		cout << "Total Time Taken: " << float( clock () - begin_time )<< " s" << endl;
        cout<<"----------------------------------------------------------------------------------------------\n";

		
	}
	return 0;
}
