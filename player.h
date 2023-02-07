char PLAYER_STR[] = "└─●─┘";
typedef struct Position
{
	int x, y;
}Position;

typedef struct
{
	Position position;
	char* strPlayer;// = "└─●─┘";//주인공 캐릭터
	int nLength; //주인공 캐릭터 전체 길이
}Player;

Player g_Player;
