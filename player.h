char PLAYER_STR[] = "└─●─┘";
typedef struct Position
{
	int x, y;
}Position;

typedef struct
{
	Position position;
	Position center;// 중심 좌표
	char* strPlayer;// = "└─●─┘";//주인공 캐릭터
	int nLength; //주인공 캐릭터 전체 길이
}Player;

Player g_Player;

typedef struct Ball
{
	int isReady;
	Position position;
	clock_t moveTime;
	clock_t oldTime;
}Ball;

Ball g_Ball;
