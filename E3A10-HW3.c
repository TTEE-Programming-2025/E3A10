#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 9
#define COLS 9
// �禡�쫬�ŧi
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
// ����w��e��
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
	system("cls");// �M���ù�
}

// --------------------------------------
// �K�X�ˬd�A�̦h�T��
int pw() {
    int pw = 2025;
    int input, a = 0;

    while (a < 3) {
        printf("\n�п�J 4 ��ƱK�X (���ܡG2025)�G");
        scanf("%d", &input);

        if (input == pw) {
            printf("�K�X���T�A�i�J�t��...\n");
            return 1;
        } else {
            printf("�K�X���~�I\n");
            a++;
        }
    }
    return 0;
}
// ���e��
void menu() {
    printf("-----------[Booking System]-----------\n");
    printf("|  a. Available seats                |\n");
    printf("|  b. Arrange for you                |\n");
    printf("|  c. Choose by yourself             |\n");
    printf("|  d. Exit                           |\n");
    printf("-------------------------------------\n");
}
char seats[ROWS][COLS]; // '-'�Ŧ�A'*'�w�w���A'@'�ȿ�

void initSeats() {
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            seats[i][j] = '-';

    // �T�w�]�w10�Ӥw�w���y��]�����w���^
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
// �M���ù����禡�]�̾ڧ@�~�t�Ρ^
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
// ��ܮy��ϡC�Y temp ���� NULL�A����{�ɮy���
void showSeats(char temp[ROWS][COLS]) {
    printf("\\123456789\n");
    for (int i = 0; i < ROWS; i++) {
        printf("%d-", 9 - i);  // �q��9�Ƽƨ��1��
        for (int j = 0; j < COLS; j++) {
            if (temp != NULL && temp[i][j] == '@')
                printf("@");
            else
                printf("%c", seats[i][j]);
        }
        printf("\n");
    }
}
// �ƻs�y��ϰ}�C
void copySeats(char dest[ROWS][COLS], char src[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            dest[i][j] = src[i][j];
}
// �M����w�ƶq�s��Ŧ�A���G�g�J result �}�C
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

// �۰ʦw�Ʈy��y�{
void autoArrange() {
    int n;
    printf("�аݻݭn�X�Ӯy��H(1~4)�G");
    scanf("%d", &n);
    if (n < 1 || n > 4) {
        printf("��J���~�C\n");
        return;
    }

    int result[4][2]; 

    if (!findConsecutiveSeats(n, result)) {
        printf("�L�k�w�Ƴs��y��C\n");
        return;
    }

    char temp[ROWS][COLS];
    copySeats(temp, seats);
    for (int i = 0; i < n; i++)
        temp[result[i][0]][result[i][1]] = '@';

    showSeats(temp);

    char confirm;
    printf("�O�_���N�o�Ǯy��H(y/n)�G");
    scanf(" %c", &confirm);
    if (confirm == 'y') {
        for (int i = 0; i < n; i++)
            seats[result[i][0]][result[i][1]] = '*';
        printf("�w�����\�I\n");
    } else {
        printf("�w�����w���C\n");
    }
}

// ��ʿ�ܮy��y�{
void chooseSeats() {
    int r, c;
    char input[100];
    char temp[ROWS][COLS];
    copySeats(temp, seats);

    printf("�п�J�y��]�p 1-2�^�A�h�ӽХΪŮ�j�}�]Enter �����^�G\n");
    scanf(" %[^\n]", input);

    if (strlen(input) == 0)
        return;

    int valid = 1;
    char *token = strtok(input, " ");
    while (token != NULL) {
        if (sscanf(token, "%d-%d", &r, &c) != 2) {
            printf("�榡���~�G%s\n", token);
            valid = 0;
            break;
        }

        r = 9 - r;
        c = c - 1;

        if (r < 0 || r >= ROWS || c < 0 || c >= COLS || seats[r][c] == '*') {
            printf("�y��L�ĩΤw�Q�w���G%s\n", token);
            valid = 0;
            break;
        }

        if (temp[r][c] == '@') {
            printf("���ƿ�ܮy��G%s\n", token);
            valid = 0;
            break;
        }

        temp[r][c] = '@';
        token = strtok(NULL, " ");
    }

    if (valid) {
        showSeats(temp);
        char confirm;
        printf("�O�_�T�{��ܳo�Ǯy��H(y/n)�G");
        scanf(" %c", &confirm);
        if (confirm == 'y') {
            for (int i = 0; i < ROWS; i++)
                for (int j = 0; j < COLS; j++)
                    if (temp[i][j] == '@')
                        seats[i][j] = '*';
            printf("�w�����\�I\n");
        } else {
            printf("�w�����w���C\n");
        }
    }
}

// �D�{���J�f
int main() {
	welcome();
	pw();// �i��K�X����
    char option;
    initSeats();// ��l�Ʈy��

    while (1) {
        clearScreen();
        menu(); // ��ܥD���
        printf("�п�J�ﶵ�G");
        scanf(" %c", &option);

        switch (option) {
            case 'a':
                showSeats(NULL);// ��ܥثe�y�챡�p
                system("pause");
                break;
            case 'b':
                autoArrange();// �۰ʦw�Ʈy��
                system("pause");
                break;
            case 'c':
                chooseSeats(); // ��ʿ�ܮy��
                system("pause");
                break;
            case 'd': {
                char cont;
                printf("Continue? (y/n)�G");
                scanf(" %c", &cont);
                if (cont == 'n') {
                    printf("�P�¨ϥΡA�A���I\n");
                    return 0;
                }
                break;
            }
            default:
                printf("�L�Ŀﶵ�A�Э��s��J�C\n");
                system("pause");
        }
    }
    return 0;
}
//���ϥΪ̥i�H�@����J�h�Ӯy��]�Ҧp�G1-2 1-3 1-4�^�A�o�̥Ψ� strtok �Ӥ��Ѧr��A
//�A�� sscanf �ѪR�C�@�աu�C-��v�A�@�}�l�`�`�ѪR���~�A���ɭ��ٷ|�z������ܿ���A
//��ӺC�C�Ƿ|�n�����~�P�_�]���榡���~�B���ƿ�B�w�Q�w�����^�~����í�w�C
