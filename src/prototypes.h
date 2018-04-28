#define TABLE_Y 16

	void input_nubmers_test(int *numbers);

	int main_menu(void);

	void fill_gameboard(char gameboard_mass[TABLE_Y][TABLE_Y]);	

	void print_gameboard(char gameboard_mass[TABLE_Y][TABLE_Y]);

	void entering_coord(int vibor, int winExit, int *height, int *widht, char tableGame[TABLE_Y][TABLE_Y]);

	void game_settings(int *menu, int *settings, int *level, int *vibor, int *bot);
