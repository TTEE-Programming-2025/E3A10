#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 9
#define COLS 9
// 函式原型
void welcome();
int pw();


// --------------------------------------
// 顯示歡迎畫面
void welcome() {
    printf("                   .-                                                                               \n");
	printf("                   -===.                                                                            \n");
	printf("                   -+--=-                                                                           \n");
	printf("                   :+=---=:                                                                         \n");
	printf("                   :++=---==.                                                                       \n");
	printf("                   .*++=------+-                                                                    \n");
	printf("                    *+++=-------=:                                                                  \n"); 
	printf("                    *+++=--------==.    :.                   .--==                                  \n");
	printf("                    *++++=------===+-   +*-   ..        .-=+**++*.                                  \n"); 
	printf("                    ++++++====---=+==+: #***:.**:   :=+******++*.                                   \n"); 
	printf("                    +++++++=======+++++*#****#***-=***********#:                                    \n"); 
	printf("     ::             =+++++++=+++++++++++++++++++++++*********#-                                     \n"); 
	printf("     =-+=.          :*+++++++++++++++++=========+++++++++***#+:--===+                               \n"); 
	printf(" .--=+*++++=-       .*+++++++++++==--------------=====++++++********.                               \n"); 
	printf(" :===+++++=--==:     *++++++++=---------------------===+++++++++***..:::...:::::---=---------::..   \n"); 
	printf("   :++++++=-----=-.  +++++*+=-------------------------==++++++++++++==--======----------------+**.  \n");
	printf("   .+++++++=------==-*+**+++=--------------------------===+++++++++++=-------------------==++++:    \n");
	printf("  .++++++++++=----==+##*+++=---------------------------====+++++++++++=---------------==++++*-      \n");
	printf("    :=*+++++++=--=++*#+++==----------------------------====++++++++++++==--------===++++++*=        \n");
	printf("      .+++++++++===+++++++=-----------------------------===+=+++++++++====---==+++++++++*+.         \n");
	printf("       .*++++++++++++++++=----=-------------------------===++++++++++++====+++++++++++*+.           \n");
	printf("        :++++++++++++++++====-+-----------------------====++++++++++++++++++++++++++*+:             \n");
	printf("         =++++++++++++++++++++-+---------------------==+++++++++++++++++++++++++++++:               \n");
	printf("          =+++++++++++++++++=..==------------------==++++++++++++++++++++++++++++*:                 \n");
	printf("           =++*++++++++++++=...:+----------------===+++++++++++++++++++++++++++*-                   \n");
	printf("            **++++++++++++*.....-*=--===------==+++++++++++++++++++++++++++++*-                     \n");
	printf("            +++++++++++++++.....:*+++=+++=====++++++++++++++***+++++++++*++*=                       \n");
	printf("           :+++++++++++++++.....:%*++++++++++++++==++++++++=:*+++++++++++#=.                        \n");
	printf("           +=++++++++#++++*-....:+++++++++++++++===++++*=:::.#+++++++++++*:.                        \n");
	printf("          .+==+++++++**+++++=..::::*++++++++++++==++*+=::::::*+++++++++++#+***+++====---:.          \n");
	printf("          =-===++++++:.*+++++*=-:::=++++++++++++++*#:...::::+++++++++++++#++++++++++++=--==+=       \n");
	printf("          +--==+++++*: .=++++++++***+++++++++++++--=.....:::*++++++++++++*++++++++++++++++**:       \n");
	printf("          #====++++++-   -*++++++++++++++++++*#:........::-+++++++++++++++++++++++++++++++++-==     \n");
	printf("          *=====+++++=   :-=*+++++++++++++++++++-......:-=++++++++++++++++++++++++++++++++++=-      \n");
	printf("          *=====++***#.  =...-+*+++++++++++++++++*++=+++++++++++++++++++++++++++++++++++++*.        \n");
	printf("          *====+++****+ .-......=*+*++++++++++++++++++++++++**+++++++++++++++++++++++*+=-+*         \n");
	printf("          +=====******#=-.......-...-=+**++++++++++++++++**#*+++++++++++++++++++++*+=.              \n");
	printf("          ++++==+*******#.......=........:-=*+++***+**==-:-*++++++++*+**++++++**=-                  \n");
	printf("        =##%*++***############==...........=....   .- -**************#.                             \n");
	printf("       .#####***################*=-.......-:..     ==*###############-                              \n");
	printf("       =+**##***#####################*==--+...:-=+*#################+                               \n");
	printf("       *++**##**###################################################*                                \n");
	printf("       *++++**#####################################################.                                \n");
	printf("       ++++++**###################################################.                                 \n");
	printf("       .*+++++**###################################**+++++**#%%##.                                  \n");
	printf("        =*+++++*################################**+++++++++***##.                                   \n");
	printf("         =#*++**###############################*+++++++++++****#:                                   \n");
	printf("          .+##################################*++++++++++++*****+                                   \n");
	printf("            .-%########+#**##################**++++++++++++******                                   \n");
	printf("              +#######* .=#***##############****+++++++=++*******                                   \n");
	printf("               =#*##+=+    -+##*############****++**++++++++++++*                                   \n");
	printf("                . :+.        .-+%%##########***+++++++++++++++++=                                   \n");
	printf("                                -###%%%%%-:.+*+++++++++++++++++*.                                   \n");
	printf("                                 .*#####:    -*++++*%***#++++++=                                    \n");
	printf("                                   -*##*      =+++###%######++=                                     \n");
	printf("                                      :        ++*#########**-                                      \n");
	printf("                                               .**########*+.                                       \n");
	printf("                                                -**######+:                                         \n");
	printf("                                                 .-=+*+=.                                           \n");
	system("PAUSE");
	system("cls");// 清除螢幕
}

// --------------------------------------
// 密碼檢查，最多三次
int pw() {
    int pw = 2025;
    int input, a = 0;

    while (a < 3) {
        printf("\n請輸入 4 位數密碼 (提示：2025)：");
        scanf("%d", &input);

        if (input == pw) {
            printf("密碼正確，進入系統...\n");
            return 1;
        } else {
            printf("密碼錯誤！\n");
            a++;
        }
    }
    return 0;
}

void menu() {
    printf("-----------[Booking System]-----------\n");
    printf("|  a. Available seats                |\n");
    printf("|  b. Arrange for you                |\n");
    printf("|  c. Choose by yourself             |\n");
    printf("|  d. Exit                           |\n");
    printf("-------------------------------------\n");
}
char seats[ROWS][COLS]; // '-'空位，'*'已預約，'@'暫選

void initSeats() {
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            seats[i][j] = '-';

    // 固定設定10個已預約座位（模擬預約）
    int fixed[10][2] = {
        {0, 1}, {1, 8}, {3, 5}, {4, 3}, {4, 8},
        {6, 3}, {6, 4}, {7, 3}, {8, 1}, {8, 2}
    };

    for (int i = 0; i < 10; i++) {
        int r = fixed[i][0];
        int c = fixed[i][1];
        seats[r][c] = '*';
    }
}

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void showSeats(char temp[ROWS][COLS]) {
    printf("\\123456789\n");
    for (int i = 0; i < ROWS; i++) {
        printf("%d-", 9 - i);  // 從第9排數到第1排
        for (int j = 0; j < COLS; j++) {
            if (temp != NULL && temp[i][j] == '@')
                printf("@");
            else
                printf("%c", seats[i][j]);
        }
        printf("\n");
    }
}

void copySeats(char dest[ROWS][COLS], char src[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            dest[i][j] = src[i][j];
}

int findConsecutiveSeats(int need, int result[4][2]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j <= COLS - need; j++) {
            int ok = 1;
            for (int k = 0; k < need; k++) {
                if (seats[i][j + k] != '-') {
                    ok = 0;
                    break;
                }
            }
            if (ok) {
                for (int k = 0; k < need; k++) {
                    result[k][0] = i;
                    result[k][1] = j + k;
                }
                return 1;
            }
        }
    }
    return 0;
}


void autoArrange() {
    int n;
    printf("請問需要幾個座位？(1~4)：");
    scanf("%d", &n);
    if (n < 1 || n > 4) {
        printf("輸入錯誤。\n");
        return;
    }

    int result[4][2]; 

    if (!findConsecutiveSeats(n, result)) {
        printf("無法安排連續座位。\n");
        return;
    }

    char temp[ROWS][COLS];
    copySeats(temp, seats);
    for (int i = 0; i < n; i++)
        temp[result[i][0]][result[i][1]] = '@';

    showSeats(temp);

    char confirm;
    printf("是否滿意這些座位？(y/n)：");
    scanf(" %c", &confirm);
    if (confirm == 'y') {
        for (int i = 0; i < n; i++)
            seats[result[i][0]][result[i][1]] = '*';
        printf("預約成功！\n");
    } else {
        printf("已取消預約。\n");
    }
}


void chooseSeats() {
    int r, c;
    char input[100];
    char temp[ROWS][COLS];
    copySeats(temp, seats);

    printf("請輸入座位（如 1-2），多個請用空格隔開（Enter 結束）：\n");
    scanf(" %[^\n]", input);

    if (strlen(input) == 0)
        return;

    int valid = 1;
    char *token = strtok(input, " ");
    while (token != NULL) {
        if (sscanf(token, "%d-%d", &r, &c) != 2) {
            printf("格式錯誤：%s\n", token);
            valid = 0;
            break;
        }

        r = 9 - r;
        c = c - 1;

        if (r < 0 || r >= ROWS || c < 0 || c >= COLS || seats[r][c] == '*') {
            printf("座位無效或已被預約：%s\n", token);
            valid = 0;
            break;
        }

        if (temp[r][c] == '@') {
            printf("重複選擇座位：%s\n", token);
            valid = 0;
            break;
        }

        temp[r][c] = '@';
        token = strtok(NULL, " ");
    }

    if (valid) {
        showSeats(temp);
        char confirm;
        printf("是否確認選擇這些座位？(y/n)：");
        scanf(" %c", &confirm);
        if (confirm == 'y') {
            for (int i = 0; i < ROWS; i++)
                for (int j = 0; j < COLS; j++)
                    if (temp[i][j] == '@')
                        seats[i][j] = '*';
            printf("預約成功！\n");
        } else {
            printf("已取消預約。\n");
        }
    }
}


int main() {
	welcome();
	pw();
    char option;
    initSeats();

    while (1) {
        clearScreen();
        menu();
        printf("請輸入選項：");
        scanf(" %c", &option);

        switch (option) {
            case 'a':
                showSeats(NULL);
                system("pause");
                break;
            case 'b':
                autoArrange();
                system("pause");
                break;
            case 'c':
                chooseSeats();
                system("pause");
                break;
            case 'd': {
                char cont;
                printf("Continue? (y/n)：");
                scanf(" %c", &cont);
                if (cont == 'n') {
                    printf("感謝使用，再見！\n");
                    return 0;
                }
                break;
            }
            default:
                printf("無效選項，請重新輸入。\n");
                system("pause");
        }
    }
    return 0;
}

