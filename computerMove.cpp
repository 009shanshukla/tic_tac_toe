int get_computer_move(const int side)
{
	int numfree=0;        //calculate total free moves
	int available_move[9];   //store every free move
	int randmove=0;
	randmove=get_winning_move(side);  //selecting winning move
	if(randmove!= -1)
		return randmove;
	randmove=0;							           
	for(int i=0;i<9;i++)
	{
		if(board[convert_to_25[i]]==empty)
		{
			available_move[numfree++]=convert_to_25[i];          //checking if move is free, then stored
		}
	}
	randmove=rand()%numfree;                 // picking one of free move
	return available_move[randmove];	
}


int get_winning_move(const int side)
{
	int winmove=0;
	int ourmove=-1;
	for(int i=0;i<9;i++)
	{
		if(board[convert_to_25[i]]==empty)
		{
			ourmove=convert_to_25[i];
			board[ourmove]=side;
			if(find_three_in_a_row(ourmove,side)==3)
				winmove=1;

			board[ourmove]=empty;
			if(winmove==1)
				return ourmove;
			ourmove=-1;
		}
	}
	return ourmove;
	
}
