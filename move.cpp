void make_move(const int side,const int sq)
{
	board[sq]=side;                 
}

int has_empty()              //check if board has any available move
{
	for(int i=0;i<9;i++)
	{
		if(board[convert_to_25[i]]==empty) 
		return 1;
	}
	return 0;
}

int get_num_for_dir(int dir,int start_sq,const int us)     //finding total consecutive same move in one dir           
{
	int found=0;          //storing total same move in one dir
	while(board[start_sq]!=border)   //looping until border doesn't hit
	{
		if(board[start_sq]!=us)      //break untill different move is not found
		break;

		found++;            
		start_sq+=dir;	  
	}
	return found;
}

int find_three_in_a_row(const int ourindex,const int us)
{
	int dir=0;           //direction in which we have to check
	int three_count=1;    //find total count
	for(int i=0;i<4;i++)
	{
		dir=directions[i];    //first direction to check
		three_count+=get_num_for_dir(dir,ourindex+dir,us);   //direction in right or down side
		three_count+=get_num_for_dir(dir*-1,ourindex+dir*-1,us); //direction in left or up side
		if(three_count==3)
		break;

		three_count=1;
	}
	return three_count;
}

int find_three_in_a_row_allboard(const int us) //checking for three in a row in whole board
{
	int threefound=0; //variable to find three in a row
	for(int i=0;i<9;i++)
	{	
		if(board[convert_to_25[i]]==us)    //if a side is foung
		{
			if(find_three_in_a_row(convert_to_25[i],us)==3)  //send it to check three in a row
				{
					threefound=1;
					break;
				}
		}
	}
	return threefound;
}

int eval_for_win(const int us)  //evaluate who will win 
{
	if(find_three_in_a_row_allboard(us)!=0)  // if for given side three found then given side win
		return 1;
	if(find_three_in_a_row_allboard(us ^ 1)!=0) //if for opposite of given side three found then that side wins
		return -1;
	return 0;  //else draw
}

int min_max(int side)
{
	int movelist[9]; //total moves available
	int movecount= 0; //how many moves are used
	int bestscore= -2; //bestscore so far
	int score= -2; //current score
	int bestmove= -1;	   
	int move;
	if(play>maxplay)  
	{
	maxplay=play;
	positions++;	
	}	
	if(play>0)
	{
		score=eval_for_win(side);
		if(score!=0) //pos was not won
		return score;  //return that score
	}
	//if we reach win pos,then fill that move list
	for(int i=0;i<9;i++)
	{
		if(board[convert_to_25[i]]==empty)
		{
			movelist[movecount++]=convert_to_25[i]; //all possible moves on board
		}
	}
	for(int i=0;i<movecount;i++) //loop all moves
	{
		move=movelist[i];
		board[move]=side; 
		
		play++;  //when move cureent situation 
		score = -min_max(side^1);  //minimizing oponent
		if(score>bestscore)     //maximizing current move
		{
			bestscore=score;
			bestmove=move;          
		}
		board[move]=empty;
		play--;
	}
	if(movecount==0) //all moves are full means board is full
	{
		bestscore=find_three_in_a_row_allboard(side); 
	}
	if(play!=0)   //if not top of the tree
		return bestscore;
	else          //if top of the tree
		return bestmove;
	  
}









void run_game()
{
	int gameover=0;
	int side=noughts;
	int last_move_made=0;
	initialize();
	print_board();
	while(!gameover)
	{
		if(side==noughts)
		{
	//take input from human and move the side
			last_move_made=get_human_move();
			make_move(side,last_move_made);
			side=cross;

		}
		else
		{
	//	take input from computer and move the side
			last_move_made=get_computer_move(side);
			make_move(side,last_move_made);
			side=noughts;
			print_board();
		}
//if there is in a row exists game over
		if(find_three_in_a_row(last_move_made,side ^ 1)==3) //side ^ 1 -> just switches the side as side was change after move , see up
		{
			gameover=1;
			printf("GAME over\n");

			if(side==noughts)
			printf("COMPUTER wins\n");
			else
			printf("HUMAN wins\n");
		}

//if no more move ,game is draw
		if(!has_empty())
		{
			print_board();
			printf("GAME Over\n");
			gameover=1;
			printf("It is a Draw\n");	
		}


	}
}
