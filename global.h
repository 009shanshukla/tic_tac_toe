/*
	*,*,*,*,*,
	*,1,2,3,*,
	*,4,5,6,*,
	*,7,8,9,*,
	*,*,*,*,*,

	0 ,1 ,2 ,3 ,4 ,
	5 ,6 ,7 ,8 ,9 ,
	10,11,12,13,14,
	15,16,17,18,19,
	20,21,22,23,24,


	   
*/
int board[25];
/*const int noughts=1;
const int cross=2;
const int border=3;
const int empty=0;
*/
enum {noughts,cross,border,empty};
enum {humanwin,compwin,draw};
const int directions[4]={1,5,4,6};

const int convert_to_25[9]=
{
	6,7,8,
	11,12,13,
	16,17,18
};

const int inmiddle= 4;
const int incorner[4]={0,2,6,8};

void initialize(void);
void print_board(void);
void run_game(void);
void make_move(const int side,const int sq);
int has_empty(void);
int get_human_move(void);
int get_computer_move(const int side);
int find_three_in_a_row(const int ourindex,const int us);
int get_num_for_dir(int dir,int start_sq,const int us);
int get_winning_move(const int side);
int get_best_move(void);
