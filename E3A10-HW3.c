#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 9
#define COLS 9
// 函式原型宣告
void welcome();
int pw();
void menu();
void initSeats();
void clearScreen();
void showSeats(char temp[ROWS][COLS]);
void copySeats(char dest[ROWS][COLS], char src[ROWS][COLS]);
int findConsecutiveSeats(int need, int result[4][2]);
void autoArrange();
void chooseSeats();


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
// 選單畫面
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
// 清除螢幕的函式（依據作業系統）
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
// 顯示座位圖。若 temp 不為 NULL，顯示臨時座位圖
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
// 複製座位圖陣列
void copySeats(char dest[ROWS][COLS], char src[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            dest[i][j] = src[i][j];
}
// 尋找指定數量連續空位，結果寫入 result 陣列
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

// 自動安排座位流程
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

// 手動選擇座位流程
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

// 主程式入口
int main() {
	welcome();
	pw();// 進行密碼驗證
    char option;
    initSeats();// 初始化座位

    while (1) {
        clearScreen();
        menu(); // 顯示主選單
        printf("請輸入選項：");
        scanf(" %c", &option);

        switch (option) {
            case 'a':
                showSeats(NULL);// 顯示目前座位情況
                system("pause");
                break;
            case 'b':
                autoArrange();// 自動安排座位
                system("pause");
                break;
            case 'c':
                chooseSeats(); // 手動選擇座位
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
//讓使用者可以一次輸入多個座位（例如：1-2 1-3 1-4），這裡用到 strtok 來分解字串，
//再用 sscanf 解析每一組「列-欄」，一開始常常解析錯誤，有時候還會爆掉或顯示錯位，
//後來慢慢學會要做錯誤判斷（像格式錯誤、重複選、已被預約等）才能比較穩定。
