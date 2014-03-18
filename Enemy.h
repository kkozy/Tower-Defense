//Nathan Kowaleski
//Enemy .h file
class Enemy
{
private:
	int x;//x position
	int y;//y position
	int xv;//x velocity
	int yv;//y velocity
	int maxhealth;
	int currenthealth;

public:
	Enemy();
	void direction();
	void move();
	void show();
	void damage(int);

};
