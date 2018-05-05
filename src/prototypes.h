#define TABLE_Y 16

	void input_nubmers_test(int *numbers);

	int correct_entering();

	int main_menu(void);

	void fill_gameboard(char gameboard_mass[TABLE_Y][TABLE_Y]);	

	void print_gameboard(char gameboard_mass[TABLE_Y][TABLE_Y]);

	void entering_coord(int choice, int winExit, int *height, int *widht, char tableGame[TABLE_Y][TABLE_Y]);

	void check_to_win(char tableGame[TABLE_Y][TABLE_Y], int choice, int widht, int height, int winExit, int *winX, int *winO, int *gorizontSchet, int *vertikalSchet, int *leftDiagonalSchet, int *rightDiagonalSchet, int *gorizontSchetLeft, int *vertikalSchetLeft, int *leftDiagonalSchetLeft, int *rightDiagonalSchetLeft);

	void move_bot(int level, int gorizontSchet, int vertikalSchet, int leftDiagonalSchet, int rightDiagonalSchet, int gorizontSchetLeft, int vertikalSchetLeft, int leftDiagonalSchetLeft, int rightDiagonalSchetLeft, int hodBot);

	void control(int exit, int i, int choice, char tableGame[TABLE_Y][TABLE_Y], int coord, int *score, int *spaceFinder, int hightCoordLeft, int hightCoordRight, int weightCoordLeft, int weightCoordRight, int *check, int checkTwo);

	int checkWin(int score, int choice, int *winX, int *winO);

	void game_settings(int menu, int *settings, int *level, int *choice, int *bot);
