#include <sl.h>
#include <iostream>

/// <summary>
/// init data
/// </summary>
int player[3][3] = {
	{0,0,0},
	{0,0,0},
	{0,0,0}
};

/// <summary>
/// cek apakah game telah mencapai akhir
/// </summary>
/// <returns></returns>
int isEnd() {

	/// Player 1 Win
	// vertical
	if (player[0][0] == 1 && player[0][1] == 1 && player[0][2] == 1) {
		return 1;
	}
	if (player[1][0] == 1 && player[1][1] == 1 && player[1][2] == 1) {
		return 1;
	}
	if (player[2][0] == 1 && player[2][1] == 1 && player[2][2] == 1) {
		return 1;
	}

	// diagonal
	if (player[0][0] == 1 && player[1][1] == 1 && player[2][2] == 1) {
		return 1;
	}
	if (player[2][0] == 1 && player[1][1] == 1 && player[0][2] == 1) {
		return 1;
	}

	// horizontal
	if (player[0][0] == 1 && player[1][0] == 1 && player[2][0] == 1) {
		return 1;
	}
	if (player[0][1] == 1 && player[1][1] == 1 && player[2][1] == 1) {
		return 1;
	}
	if (player[0][2] == 1 && player[1][2] == 1 && player[2][2] == 1) {
		return 1;
	}

	/// Player 2 Win
	// vertical
	if (player[0][0] == 2 && player[0][1] == 2 && player[0][2] == 2) {
		return 2;
	}
	if (player[1][0] == 2 && player[1][1] == 2 && player[1][2] == 2) {
		return 2;
	}
	if (player[2][0] == 2 && player[2][1] == 2 && player[2][2] == 2) {
		return 2;
	}

	// diagonal
	if (player[0][0] == 2 && player[1][1] == 2 && player[2][2] == 2) {
		return 2;
	}
	if (player[2][0] == 2 && player[1][1] == 2 && player[0][2] == 2) {
		return 2;
	}

	// horizontal
	if (player[0][0] == 2 && player[1][0] == 2 && player[2][0] == 2) {
		return 2;
	}
	if (player[0][1] == 2 && player[1][1] == 2 && player[2][1] == 2) {
		return 2;
	}
	if (player[0][2] == 2 && player[1][2] == 2 && player[2][2] == 2) {
		return 2;
	}

	int filled = 0;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++) {

			if (player[i][j] > 0) {
				filled += 1;
			}
		}
	}

	if (filled == 9) {
		return 3;
	}

	return 0;
}

/// <summary>
/// generate border tictactoe
/// </summary>
void border() {

	// set warna border
	slPush();

	if (isEnd() == 1) {
		slSetForeColor(0, 0, 0.5, 1);
	}
	else if (isEnd() == 2) {
		slSetForeColor(0, 0.5, 0.5, 1);
	}
	else if (isEnd() == 3) {
		slSetForeColor(0, 0, 0, 1);
	}
	else {
		slSetForeColor(1, 1, 1, 1);
	}

	slPop();

	// baris ke 1 
	slRectangleOutline(101, 499, 200, 200);
	slRectangleOutline(300, 499, 200, 200);
	slRectangleOutline(499, 499, 200, 200);

	// baris ke 2
	slRectangleOutline(101, 300, 200, 200);
	slRectangleOutline(300, 300, 200, 200);
	slRectangleOutline(499, 300, 200, 200);

	// baris ke 3
	slRectangleOutline(101, 100, 200, 200);
	slRectangleOutline(300, 100, 200, 200);
	slRectangleOutline(499, 100, 200, 200);
}

/// <summary>
/// membuat dan menset warna bentuk untuk tiap user
/// </summary>
/// <param name="X"> sumbu x bentuk </param>
/// <param name="Y"> sumbu y bentuk </param>
/// <param name="isPlayer1"> mengecek apakah ini player 1 </param>
void createShape(int X, int Y, bool isPlayer1) {

	if (isPlayer1) {
		slPush();

		if (isEnd() == 1) {
			slSetForeColor(0, 0, 0.5, 1);
		}
		else if (isEnd() == 2) {
			slSetForeColor(0, 0.5, 0.5, 1);
		}
		else if (isEnd() == 3) {
			slSetForeColor(0, 0, 0, 1);
		}
		else {
			slSetForeColor(0, 0, 1, 1);
		}

		slPop();

		slCircleFill(X, Y, 25, 25);
	}
	else {
		slPush();

		if (isEnd() == 1) {
			slSetForeColor(0, 0, 0.5, 1);
		}
		else if (isEnd() == 2) {
			slSetForeColor(0, 0.5, 0.5, 1);
		}
		else if (isEnd() == 3) {
			slSetForeColor(0, 0, 0, 1);
		}
		else {
			slSetForeColor(0, 0.5, 0.5, 1);
		}
		slPop();

		slRectangleFill(X, Y, 50, 50);
	}
}

/// <summary>
/// posisi mouse saat mengklik
/// </summary>
/// <param name="isPlayer1"> mengecek apakah ini player 1 </param>
void mousePos(bool isPlayer1) {
	int mouseX = slGetMouseX();
	int mouseY = slGetMouseY();
	int val;

	// set val 1 jika player 1
	// set val 2 jika player 2
	if (isPlayer1) {
		val = 1;
	}
	else {
		val = 2;
	}

	// sumbu X mouse baris ke 1
	if (mouseX <= 200 && mouseX > 0) {
		// sumbu Y mouse baris ke 1
		if (mouseY <= 200 && mouseY > 0) {
			player[0][0] = val;
		}
		// sumbu Y mouse baris ke 2
		else if (mouseY <= 400 && mouseY > 200) {
			player[0][1] = val;
		}
		// sumbu Y mouse baris ke 3
		else if (mouseY <= 600 && mouseY > 400) {
			player[0][2] = val;
		}
	}
	// sumbu X mouse baris ke 2
	else if (mouseX <= 400 && mouseX > 200) {
		// sumbu Y mouse baris ke 1
		if (mouseY <= 200 && mouseY > 0) {
			player[1][0] = val;
		}
		// sumbu Y mouse baris ke 2
		else if (mouseY <= 400 && mouseY > 200) {
			player[1][1] = val;
		}
		// sumbu Y mouse baris ke 3
		else if (mouseY <= 600 && mouseY > 400) {
			player[1][2] = val;
		}
	}
	// sumbu X mouse baris ke 3
	else if (mouseX <= 600 && mouseX > 400) {
		// sumbu Y mouse baris ke 1
		if (mouseY <= 200 && mouseY > 0) {
			player[2][0] = val;
		}
		// sumbu Y mouse baris ke 2
		else if (mouseY <= 400 && mouseY > 200) {
			player[2][1] = val;
		}
		// sumbu Y mouse baris ke 3
		else if (mouseY <= 600 && mouseY > 400) {
			player[2][2] = val;
		}
	}
}

/// <summary>
/// posisi berdasarkan nilai yang diberikan 
/// </summary>
/// <param name="val"> nilai i atau j </param>
/// <returns></returns>
int posVal(int val) {
	switch (val)
	{
		// val untuk kolom sebelah kiri
	case 0:
		return 100;
		break;
		// val untuk kolom tengah
	case 1:
		return 300;
		break;
		// val untuk kolom sebelah kanan
	default:
		return 500;
		break;
	}
}

/// <summary>
/// Menampilkan item berdasarkan nilai array player
/// </summary>
void item() {

	int posX, posY;
	int n = 0;

	for (int i = 0; i < 3; i++)
	{
		posX = posVal(i);

		for (int j = 0; j < 3; j++) {

			++n;
			posY = posVal(j);
			if (player[i][j] > 0) {
				if (player[i][j] % 2 == 0)
					createShape(posX, posY, false);
				else
					createShape(posX, posY, true);
			}

		}
	}
}

/// <summary>
/// menampilkan text pada window
/// </summary>
/// <param name="posX">posisi X</param>
/// <param name="posY">posisi Y</param>
/// <param name="align">menyelaraskan text</param>
/// <param name="text">isi text</param>
/// <param name="fontSize">ukuran font</param>
void setText(int posX, int posY, const char* align, const char* text, int fontSize = 35) {

	slSetForeColor(1, 1, 1, 1);

	slPush();
	slSetFont(slLoadFont("LEMONMILK-Regular.otf"), fontSize);
	slPop();

	if (align == "center")
	{
		slSetTextAlign(SL_ALIGN_CENTER);
	}
	else if (align == "right") {
		slSetTextAlign(SL_ALIGN_RIGHT);
	}
	else {
		slSetTextAlign(SL_ALIGN_LEFT);
	}

	slText(posX, posY, text);
}

int main() {

	slWindow(600, 600, "Getting Started", 0);

	while (!slGetKey(SL_KEY_ENTER))
	{
		setText(300, 500, "center", "Cara bermain TicTacToe");
		setText(300, 400, "center", "Player 1", 30);
		setText(300, 370, "center", "Klik kiri pada mouse", 30);
		setText(300, 300, "center", "Player 2", 30);
		setText(300, 270, "center", "Klik kanan pada mouse", 30);
		setText(550, 50, "right", "Klik Enter untuk ke Game", 16);

		slRender();
	}

	slClose();

	slWindow(600, 600, "TicTacToe", 0);

	// urutan main
	int n = 1;

	// GAME LOOP
	while (!slShouldClose()) {

		// force close game
		if (slGetKey(SL_KEY_ESCAPE)) {
			slClose();
		}

		// reset game
		if (slGetKey(SL_KEY_BACKSPACE)) {
			n = 1;

			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++) {
					player[i][j] *= 0;
				}
			}
		}

		// border game
		border();

		/// <summary>
		/// jika game belum berakhir, 
		/// klik kiri sebagai player 1 
		/// klik kanan sebagai pemain 2
		/// </summary>
		if (isEnd() == 0) {
			if (slGetMouseButton(SL_MOUSE_BUTTON_LEFT) && n % 2 != 0) {
				mousePos(true);
				n++;
			}

			if (slGetMouseButton(SL_MOUSE_BUTTON_RIGHT) && n % 2 == 0) {
				mousePos(false);
				n++;
			}
		}

		// menampilkan move yang dibuat player
		item();

		/// <summary>
		/// jika player menang maka set warna latar
		/// menjadi warna player yang menang
		/// </summary>
		if (isEnd() == 1) {
			slSetBackColor(0, 0, 0.5);
			setText(300, 300, "center", "Player 1 win", 45);
			setText(300, 100, "center", "Klik BACKSPACE untuk memulai ulang game", 16);
		}
		else if (isEnd() == 2) {
			slSetBackColor(0, 0.5, 0.5);
			setText(300, 300, "center", "Player 2 win", 45);
			setText(300, 100, "center", "Klik BACKSPACE untuk memulai ulang game", 16);
		}
		else if (isEnd() == 3) {
			slSetBackColor(0, 0, 0);
			setText(300, 300, "center", "Draw", 45);
			setText(300, 100, "center", "Klik BACKSPACE untuk memulai ulang game", 16);
		}
		else {
			slSetBackColor(0, 0, 0);
		}

		slRender();

	}

	slClose();

	return 0;
}