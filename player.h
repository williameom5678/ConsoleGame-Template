char PLAYER_STR[] = "�����ܦ���";
typedef struct Position
{
	int x, y;
}Position;

typedef struct
{
	Position position;
	char* strPlayer;// = "�����ܦ���";//���ΰ� ĳ����
	int nLength; //���ΰ� ĳ���� ��ü ����
}Player;

Player g_Player;
