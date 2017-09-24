int get_human_move()
{
	int move_ok = 0;
	char user_input[4];  //valid input should be 2 char long ->num+enter=2
	int move = -1;
	while(move_ok == 0)
	{
		printf("enter a move from 1 to 9 : ");
		fgets(user_input, 3, stdin);//take input in max 3 at a time
		fflush(stdin); //flush 3 char at a time
		
		//checking if user is not breaking input system
		
		if(strlen(user_input) != 2)  // if not one input + enter that means more than one input before press enter
		{
			printf("invalid strlen()\n");
			continue;
		}
		if(sscanf(user_input,"%d",&move) != 1) //enter too much char without press enter so checking number that is last entered
		{
			move = -1;
			printf("invalid sscanf()\n");
			continue; 
		}
		if(move<1 || move>9)   //out of the board movement
		{
			move = -1;
			printf("invalid range\n");
			continue;
		}
		move--; //board starts from zero indexing  
		if(board[convert_to_25[move]]!=empty) //checking if that index is free
		{
			move = -1;
			printf("square not available\n");
			continue;
		}
		move_ok = 1;
	}
	printf("making move....%d\n",(move+1)); 
	return convert_to_25[move];
}
