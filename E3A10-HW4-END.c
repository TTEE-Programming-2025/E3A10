#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10
// 定義學生資料結構
struct Student {
    char name[20];
    int id;
    int math;
    int physics;
    int english;
    float average;
};
// 宣告學生陣列及人數
struct Student students[MAX];
int studentCount = 0;

void welcome();
void enterGrades();
void displayGrades();
void searchGrades();
void rankGrades();

// 歡迎畫面
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
	system("cls");// 清除螢幕
}

int main() {
    char choice;
    int password, tries = 0, i;

	welcome();
	// 密碼輸入驗證，最多三次機會
    while (tries < 3) {
        printf("請輸入4位數密碼（預設為2025）：");
        if (scanf("%d", &password) != 1) {  // * 改進：處理非數字輸入
            printf("密碼格式錯誤！請輸入數字。\n");
            while (getchar() != '\n'); // * 清除輸入緩衝區
            tries++;
            continue;
        }
        if (password == 2025) {
            printf("登入成功！歡迎使用成績系統！\n");
            break;
        } else {
            printf("密碼錯誤！\n");
            tries++;
        }
    }
    if (tries == 3) {
        printf("密碼錯誤三次，系統結束！\n");
        return 0;
    }
    // 主選單操作
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
                    printf("確定離開？(y/n)：");
                    scanf(" %c", &confirm);
                    if (confirm == 'y') {
                        printf("系統結束，掰掰！\n");
                        return 0;
                    }
                } while (confirm != 'y' && confirm != 'n');
                break;
            }
            default:
                printf("無效選項，請重新輸入。\n");
        }
    }
    return 0;
}
// 輸入學生成績
void enterGrades() {
	int i;
    system("cls");
    do {
        printf("請輸入學生人數（5~10）：");
        if (scanf("%d", &studentCount) != 1) {  // * 加入錯誤處理：非數字輸入
            printf("輸入錯誤，請輸入一個整數！\n");
            while (getchar() != '\n');  // * 清除緩衝區
            studentCount = 0;
            continue;
        }
        if (studentCount < 5 || studentCount > 10) {
            printf("輸入錯誤，請輸入介於 5 到 10 的數字！\n");
        }
    } while (studentCount < 5 || studentCount > 10);
    
    for (i = 0; i < studentCount; i++) {
        printf("第%d位學生\n", i + 1);
        printf("姓名：");
        scanf("%s", students[i].name);

        int valid = 0;
        while (!valid) {
            printf("學號（6位數）：");
            if (scanf("%d", &students[i].id) != 1) {  // * 錯誤處理：非數字輸入
                printf("輸入錯誤，請輸入數字學號。\n");
                while (getchar() != '\n');
                continue;
            }
            if (students[i].id >= 100000 && students[i].id <= 999999) {
                valid = 1;
            } else {
                printf("錯誤：學號必須是 6 位數字。\n");
            }
        }

        do {
            printf("數學成績（0~100）：");
            if (scanf("%d", &students[i].math) != 1) {  // * 非數字成績處理
                printf("輸入錯誤，請輸入數字！\n");
                while (getchar() != '\n');
                students[i].math = -1;
                continue;
            }
            if (students[i].math < 0 || students[i].math > 100)
                printf("分數需介於 0 到 100。\n");
        } while (students[i].math < 0 || students[i].math > 100);

        do {
            printf("物理成績（0~100）：");
            if (scanf("%d", &students[i].physics) != 1) {
                printf("輸入錯誤，請輸入數字！\n");
                while (getchar() != '\n');
                students[i].physics = -1;
                continue;
            }
            if (students[i].physics < 0 || students[i].physics > 100)
                printf("分數需介於 0 到 100。\n");
        } while (students[i].physics < 0 || students[i].physics > 100);

        do {
            printf("英文成績（0~100）：");
            if (scanf("%d", &students[i].english) != 1) {
                printf("輸入錯誤，請輸入數字！\n");
                while (getchar() != '\n');
                students[i].english = -1;
                continue;
            }
            if (students[i].english < 0 || students[i].english > 100)
                printf("分數需介於 0 到 100。\n");
        } while (students[i].english < 0 || students[i].english > 100);

        students[i].average = (students[i].math + students[i].physics + students[i].english) / 3.0;
    }
    printf("輸入完成，返回主選單...\n");
    system("pause");
    system("cls");
}
// 顯示所有學生成績
void displayGrades() {
	int i;
    system("cls");
    printf("姓名\t學號\t數學\t物理\t英文\t平均\n");
    for (i = 0; i < studentCount; i++) {
        printf("%s\t%d\t%d\t%d\t%d\t%.1f\n",
            students[i].name, students[i].id,
            students[i].math, students[i].physics,
            students[i].english, students[i].average);
    }
    system("pause");
    system("cls");
}
// 查詢指定學生成績
void searchGrades() {
	int i;
    system("cls");
    char searchName[20];
    int found = 0;
    printf("請輸入欲查詢的姓名：");
    scanf("%s", searchName);
    
    for (i = 0; i < studentCount; i++) {
        if (strcmp(students[i].name, searchName) == 0) {
            printf("姓名\t學號\t數學\t物理\t英文\t平均\n");
            printf("%s\t%d\t%d\t%d\t%d\t%.1f\n",
                students[i].name, students[i].id,
                students[i].math, students[i].physics,
                students[i].english, students[i].average);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("查無此學生資料！\n");
    }
    system("pause");
    system("cls");
}
// 成績由高至低排序
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
    printf("成績高低排序如下：\n");
    printf("姓名\t學號\t平均\n");
    for (k = 0; k < studentCount; k++) {
        printf("%s\t%d\t%.1f\n", students[k].name, students[k].id, students[k].average);
    }
    system("pause");
    system("cls");
}

//心得:\t 是「跳位字元」，用來對齊輸出的內容，在這次作業中發揮重要的作用。
//需要特別注意輸入密碼、學號或成績的地方，如果使用者不小心輸入了字母或亂打一通，程式就會出錯或者直接跳過後面輸入。
//scanf() 預期讀到一個整數（%d），所以回傳值應為 1；若輸入錯誤（如輸入了 abc），scanf() 讀不到數字 → 回傳 0 
//若是輸入錯誤到無法處理，可能回傳 EOF（-1）
