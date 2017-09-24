void initialize()
{
  for(int i=0;i<25;i++)
		board[i]=border;

  for(int i=0;i<9;i++)
		board[convert_to_25[i]]=empty;

}

void print_board()
{
	printf("BOARD\n");
	char pcechar[]="OX|-";
 	for(int i=0;i<9;i++)
	{
		if(i%3==0 && i!=0)
			printf("\n\n");
		printf("%4c",pcechar[board[convert_to_25[i]]]);
	}
	printf("\n");
}


