char PLAYER_STR[] = "�����ܦ���";
typedef struct Position
{
	int x, y;
}Position;

typedef struct
{
	Position position;
	Position center;// �߽� ��ǥ
	char* strPlayer;// = "�����ܦ���";//���ΰ� ĳ����
	int nLength; //���ΰ� ĳ���� ��ü ����
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
