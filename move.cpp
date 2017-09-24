void make_move(const int side,const int sq)
{
	board[sq]=side;
}

int has_empty()
{
	for(int i=0;i<9;i++)
	{
		if(board[convert_to_25[i]]==empty) 
		return 1;
	}
	return 0;
}

int get_num_for_dir(int dir,int start_sq,const int us)
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
			last_move_made=get_computer_move();
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
