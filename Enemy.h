//Nathan Kowaleski
//Enemy .h file
class Enemy
{
private:
	int x;//x position
	int y;//y position
	int xv;//x velocity
	int yv;//y velocity
	int speed;
	int maxhealth;
	int currenthealth;

public:
	Enemy();
	void direction();
	void move();
	void show();
	void damage(int);
	void getx();
	void gety();
	void getxv();
	void getxy();
	void getSpeed();
	void getmaxhealth();
	void get currenthealth();
	void setx();
	void sety();
	void setxv();
	void setxy();
	void setSpeed();
	void setmaxhealth();
	void setcurrenthealth();

};
