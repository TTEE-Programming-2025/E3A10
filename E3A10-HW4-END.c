#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10
// �w�q�ǥ͸�Ƶ��c
struct Student {
    char name[20];
    int id;
    int math;
    int physics;
    int english;
    float average;
};
// �ŧi�ǥͰ}�C�ΤH��
struct Student students[MAX];
int studentCount = 0;

void welcome();
void enterGrades();
void displayGrades();
void searchGrades();
void rankGrades();

// �w��e��
void welcome(){
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

int main() {
    char choice;
    int password, tries = 0, i;

	welcome();
	// �K�X��J���ҡA�̦h�T�����|
    while (tries < 3) {
        printf("�п�J4��ƱK�X�]�w�]��2025�^�G");
        if (scanf("%d", &password) != 1) {  // * ��i�G�B�z�D�Ʀr��J
            printf("�K�X�榡���~�I�п�J�Ʀr�C\n");
            while (getchar() != '\n'); // * �M����J�w�İ�
            tries++;
            continue;
        }
        if (password == 2025) {
            printf("�n�J���\�I�w��ϥΦ��Z�t�ΡI\n");
            break;
        } else {
            printf("�K�X���~�I\n");
            tries++;
        }
    }
    if (tries == 3) {
        printf("�K�X���~�T���A�t�ε����I\n");
        return 0;
    }
    // �D���ާ@
    while (1) {
        printf("------------[Grade System]------------\n");
        printf("|a.Enter student grades              |\n");
        printf("|b.Display student grades            |\n");
        printf("|c.Search for student grades         |\n");
        printf("|d.Grade ranking                     |\n");
        printf("|e.Exit system                       |\n");
        printf("--------------------------------------\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        switch (choice) {
            case 'a': enterGrades(); break;
            case 'b': displayGrades(); break;
            case 'c': searchGrades(); break;
            case 'd': rankGrades(); break;
            case 'e': {
                char confirm;
                do {
                    printf("�T�w���}�H(y/n)�G");
                    scanf(" %c", &confirm);
                    if (confirm == 'y') {
                        printf("�t�ε����A�T�T�I\n");
                        return 0;
                    }
                } while (confirm != 'y' && confirm != 'n');
                break;
            }
            default:
                printf("�L�Ŀﶵ�A�Э��s��J�C\n");
        }
    }
    return 0;
}
// ��J�ǥͦ��Z
void enterGrades() {
	int i;
    system("cls");
    do {
        printf("�п�J�ǥͤH�ơ]5~10�^�G");
        if (scanf("%d", &studentCount) != 1) {  // * �[�J���~�B�z�G�D�Ʀr��J
            printf("��J���~�A�п�J�@�Ӿ�ơI\n");
            while (getchar() != '\n');  // * �M���w�İ�
            studentCount = 0;
            continue;
        }
        if (studentCount < 5 || studentCount > 10) {
            printf("��J���~�A�п�J���� 5 �� 10 ���Ʀr�I\n");
        }
    } while (studentCount < 5 || studentCount > 10);
    
    for (i = 0; i < studentCount; i++) {
        printf("��%d��ǥ�\n", i + 1);
        printf("�m�W�G");
        scanf("%s", students[i].name);

        int valid = 0;
        while (!valid) {
            printf("�Ǹ��]6��ơ^�G");
            if (scanf("%d", &students[i].id) != 1) {  // * ���~�B�z�G�D�Ʀr��J
                printf("��J���~�A�п�J�Ʀr�Ǹ��C\n");
                while (getchar() != '\n');
                continue;
            }
            if (students[i].id >= 100000 && students[i].id <= 999999) {
                valid = 1;
            } else {
                printf("���~�G�Ǹ������O 6 ��Ʀr�C\n");
            }
        }

        do {
            printf("�ƾǦ��Z�]0~100�^�G");
            if (scanf("%d", &students[i].math) != 1) {  // * �D�Ʀr���Z�B�z
                printf("��J���~�A�п�J�Ʀr�I\n");
                while (getchar() != '\n');
                students[i].math = -1;
                continue;
            }
            if (students[i].math < 0 || students[i].math > 100)
                printf("���ƻݤ��� 0 �� 100�C\n");
        } while (students[i].math < 0 || students[i].math > 100);

        do {
            printf("���z���Z�]0~100�^�G");
            if (scanf("%d", &students[i].physics) != 1) {
                printf("��J���~�A�п�J�Ʀr�I\n");
                while (getchar() != '\n');
                students[i].physics = -1;
                continue;
            }
            if (students[i].physics < 0 || students[i].physics > 100)
                printf("���ƻݤ��� 0 �� 100�C\n");
        } while (students[i].physics < 0 || students[i].physics > 100);

        do {
            printf("�^�妨�Z�]0~100�^�G");
            if (scanf("%d", &students[i].english) != 1) {
                printf("��J���~�A�п�J�Ʀr�I\n");
                while (getchar() != '\n');
                students[i].english = -1;
                continue;
            }
            if (students[i].english < 0 || students[i].english > 100)
                printf("���ƻݤ��� 0 �� 100�C\n");
        } while (students[i].english < 0 || students[i].english > 100);

        students[i].average = (students[i].math + students[i].physics + students[i].english) / 3.0;
    }
    printf("��J�����A��^�D���...\n");
    system("pause");
    system("cls");
}
// ��ܩҦ��ǥͦ��Z
void displayGrades() {
	int i;
    system("cls");
    printf("�m�W\t�Ǹ�\t�ƾ�\t���z\t�^��\t����\n");
    for (i = 0; i < studentCount; i++) {
        printf("%s\t%d\t%d\t%d\t%d\t%.1f\n",
            students[i].name, students[i].id,
            students[i].math, students[i].physics,
            students[i].english, students[i].average);
    }
    system("pause");
    system("cls");
}
// �d�߫��w�ǥͦ��Z
void searchGrades() {
	int i;
    system("cls");
    char searchName[20];
    int found = 0;
    printf("�п�J���d�ߪ��m�W�G");
    scanf("%s", searchName);
    
    for (i = 0; i < studentCount; i++) {
        if (strcmp(students[i].name, searchName) == 0) {
            printf("�m�W\t�Ǹ�\t�ƾ�\t���z\t�^��\t����\n");
            printf("%s\t%d\t%d\t%d\t%d\t%.1f\n",
                students[i].name, students[i].id,
                students[i].math, students[i].physics,
                students[i].english, students[i].average);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("�d�L���ǥ͸�ơI\n");
    }
    system("pause");
    system("cls");
}
// ���Z�Ѱ��ܧC�Ƨ�
void rankGrades() {
	int i,j,k;
    system("cls");
    struct Student temp;
    for (i = 0; i < studentCount - 1; i++) {
        for (j = i + 1; j < studentCount; j++) {
            if (students[i].average < students[j].average) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
    printf("���Z���C�ƧǦp�U�G\n");
    printf("�m�W\t�Ǹ�\t����\n");
    for (k = 0; k < studentCount; k++) {
        printf("%s\t%d\t%.1f\n", students[k].name, students[k].id, students[k].average);
    }
    system("pause");
    system("cls");
}

//�߱o:\t �O�u����r���v�A�Ψӹ����X�����e�A�b�o���@�~���o�����n���@�ΡC
//�ݭn�S�O�`�N��J�K�X�B�Ǹ��Φ��Z���a��A�p�G�ϥΪ̤��p�߿�J�F�r���ζå��@�q�A�{���N�|�X���Ϊ̪������L�᭱��J�C
//scanf() �w��Ū��@�Ӿ�ơ]%d�^�A�ҥH�^�ǭ����� 1�F�Y��J���~�]�p��J�F abc�^�Ascanf() Ū����Ʀr �� �^�� 0 
//�Y�O��J���~��L�k�B�z�A�i��^�� EOF�]-1�^
