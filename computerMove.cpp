int get_computer_move()
{
	int numfree=0;        //calculate total free moves
	int available_move[9];   //store every free move
	int randmove=0;           //send one of random free move
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
