//Kelompok LOBI LOBI PROYEK AKHIR PROGDAS FIX EA
//Raka Ahmad Aliya Aisya

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_USER 10 // Maksimal User
#define MAX_OPTION 50 //Maksimal huruf pada pertanyaan
#define MAX_QUESTION 5 //maksimal jumlah pertanyaan

// definisi struct untuk user
struct User {
    char name[50]; //nama user
    long long npm; //npm user
    char role[6]; //admin atau player
    char username[20]; //username user
    char password[20]; //password user
    int score; //menyimpan score player
};

// definisi struct untuk list user
struct UserList { 		//struct dipassing sebagai parameter
    struct User users[MAX_USER]; //list of user berisi arraynya
    int count; //panjang user list
};

// definisi struct untuk Pertanyaan
struct Question {
    int question_id; //untuk update question dicari berdasarkan id
    char question[100];
    char optionA[MAX_OPTION];
    char optionB[MAX_OPTION];
    char optionC[MAX_OPTION];
    char optionAnswer[2];
    int score; //nilai score dari pertanyaan
    char hint[50];
};

// definisi struct untuk list user
struct QuestionList { //dipasinh sebagai parameter sama seperti userlist
    struct Question questions[MAX_QUESTION]; //list of the questions
    int count; //panjang question list
};

void welcome(){
  int i; // Deklarasi variabel integer

  // Menampilkan welcome message
  printf("! ~ Please go fullscreen and then press ENTER to start the game ~ !");

  // Menunggu user menekan enter
  getchar();

  // Membersihkan layar
  system("CLS");

  // Menunda program selama 0.5 detik
  Sleep(500);
  // Menampilkan banner game
  printf("\n\n\n\n\n\n\n");
  char a[]= {
    "\t\t\t\t\t\t =====================================================\n"
    "\t\t\t\t\t\t |------------ Energy Smart, Energy Fun! ------------|\n"
    "\t\t\t\t\t\t |--------- A Quiz Game on 7th SDGs Version ---------|\n"
    "\t\t\t\t\t\t |---------------- Kelompok Lobi-Lobi ---------------|\n"
    "\t\t\t\t\t\t =====================================================\n\n"};
  for(i = 0; a[i] != '\0'; i++) {
    printf("%c", a[i]);
    Sleep(5);
  }

  // Menampilkan progress loading dan beep
  printf("\t\t\t\t\t\t\t\t   Loading Game...\n\n");
  Beep(659,400);

  // Menunda program selama 1 detik
  Sleep(1000);

  // Menampilkan loading bar
  for(i = 1; i <= 156; i++) {
    printf("%c", 223); // 223 adalah kode karakter beta di dalam ASCII2
    if (i == 60 || i == 100)
    	Sleep(500); // Menunda program selama 0.5 detik
    	Sleep(12);
  }

  // Menunda program selama 1.6 detik
  Sleep(1600);

  // Membersihkan layar
  system("pause");
  system("CLS");
}
//fungsi untuk menyimpan database admin dan player
void initializeUserList(struct UserList *UserDatabase) {
    strcpy(UserDatabase->users[0].name, "Aliya");
    UserDatabase->users[0].npm = 2306161813;
    strcpy(UserDatabase->users[0].role, "admin");
    strcpy(UserDatabase->users[0].username, "aliyars");
    strcpy(UserDatabase->users[0].password, "admin1");
    UserDatabase->users[0].score = 0;
    UserDatabase->count++; //update count
    
    strcpy(UserDatabase->users[1].name, "Aisya");
    UserDatabase->users[1].npm = 2306161864;
    strcpy(UserDatabase->users[1].role, "admin");
    strcpy(UserDatabase->users[1].username, "aisyara");
    strcpy(UserDatabase->users[1].password, "admin2");
    UserDatabase->users[1].score = 0;
    UserDatabase->count++;
    
    strcpy(UserDatabase->users[2].name, "Raka");
    UserDatabase->users[2].npm = 2306225520;
    strcpy(UserDatabase->users[2].role, "admin");
    strcpy(UserDatabase->users[2].username, "rakamf");
    strcpy(UserDatabase->users[2].password, "admin3");
    UserDatabase->users[2].score = 0;
    UserDatabase->count++;
    
    strcpy(UserDatabase->users[3].name, "Ahmad");
    UserDatabase->users[3].npm = 23061211370;
    strcpy(UserDatabase->users[3].role, "admin");
    strcpy(UserDatabase->users[3].username, "ahmadfk");
    strcpy(UserDatabase->users[3].password, "admin4");
    UserDatabase->users[3].score = 0;
    UserDatabase->count++;
    
    strcpy(UserDatabase->users[4].name, "Dr. Prima Dewi Purnamasari");
    UserDatabase->users[4].npm = 0;
    strcpy(UserDatabase->users[4].role, "admin");
    strcpy(UserDatabase->users[4].username, "BuPrima");
    strcpy(UserDatabase->users[4].password, "LobiLobi");
    UserDatabase->users[4].score = 0;
    UserDatabase->count++;
}

//fungsi untuk mengubah soal bagi admin
void updateQuestion(struct QuestionList *QuestionDatabase, int questionId) {
    char input_question[100];
    char input_optionA[MAX_OPTION];
    char input_optionB[MAX_OPTION];
    char input_optionC[MAX_OPTION];
    char input_optionAnswer[2];
    int input_score;
    char input_hint[50];
    int questionIndex = questionId - 1;
    int c_buffer;

    // clear buffer sebelum input fgets
    while ((c_buffer = getchar()) != '\n' && c_buffer != EOF);

    // ambil input user
    printf("Update Question\t: ");
    fgets(input_question, sizeof(input_question), stdin); //dipake untuk membaca spasi
    input_question[strcspn(input_question, "\n")] = '\0'; // Remove newline if present

    printf("Update Option A\t: ");
    fgets(input_optionA, sizeof(input_optionA), stdin);
    input_optionA[strcspn(input_optionA, "\n")] = '\0'; // Remove newline if present

    printf("Update Option B\t: ");
    fgets(input_optionB, sizeof(input_optionB), stdin);
    input_optionB[strcspn(input_optionB, "\n")] = '\0'; // Remove newline if present

    printf("Update Option C\t: ");
    fgets(input_optionC, sizeof(input_optionC), stdin);
    input_optionC[strcspn(input_optionC, "\n")] = '\0'; // Remove newline if present

    printf("Update Option Answer\t: ");
    fgets(input_optionAnswer, sizeof(input_optionAnswer), stdin);
    input_optionAnswer[strcspn(input_optionAnswer, "\n")] = '\0'; // Remove newline if present

    printf("Update Option Score\t: ");
    scanf("%d", &input_score);

    // Clear the input buffer
    while ((c_buffer = getchar()) != '\n' && c_buffer != EOF);

    printf("Update Option Hint: ");
    fgets(input_hint, sizeof(input_hint), stdin);
    input_hint[strcspn(input_hint, "\n")] = '\0'; // Remove newline if present

    // simpan perubahan
    strcpy(QuestionDatabase->questions[questionIndex].question, input_question);
    strcpy(QuestionDatabase->questions[questionIndex].optionA, input_optionA);
    strcpy(QuestionDatabase->questions[questionIndex].optionB, input_optionB);
    strcpy(QuestionDatabase->questions[questionIndex].optionC, input_optionC);
    strcpy(QuestionDatabase->questions[questionIndex].optionAnswer, input_optionAnswer);
    QuestionDatabase->questions[questionIndex].score = input_score;
    strcpy(QuestionDatabase->questions[questionIndex].hint, input_hint);

    printf("\n Update Success! \n");
    system("pause");
    system("cls");
}
//fungsi yang menyimpan pertanyaan yang akan ditanyakan dalam quiz
void initializeQuestionList(struct QuestionList *QuestionDatabase) {
    QuestionDatabase->questions[0].question_id = 1;
    strcpy(QuestionDatabase->questions[0].question, "Apa yang dimaksud dengan 7SDG: Affordable and Clean Energy?");
    strcpy(QuestionDatabase->questions[0].optionA, "Energi yang efisien");
    strcpy(QuestionDatabase->questions[0].optionB, "Energi yang terjangkau dan bersih");
    strcpy(QuestionDatabase->questions[0].optionC, "Energi yang selalu tersedia");
    strcpy(QuestionDatabase->questions[0].optionAnswer, "B");
    QuestionDatabase->questions[0].score = 20; //score dari soal
    strcpy(QuestionDatabase->questions[0].hint, "Soal"); //hint yang tersedia
    QuestionDatabase->count++;  //update count

    QuestionDatabase->questions[1].question_id = 2;
    strcpy(QuestionDatabase->questions[1].question, "Apa upaya yang dapat dilakukan untuk mencapai tujuan 7SDG?");
    strcpy(QuestionDatabase->questions[1].optionA, "Meningkatkan penggunaan energi terbarukan");
    strcpy(QuestionDatabase->questions[1].optionB, "Menurunkan subsidi energi");
    strcpy(QuestionDatabase->questions[1].optionC, "Meningkatkan efisiensi energi");
    strcpy(QuestionDatabase->questions[1].optionAnswer, "A");
    QuestionDatabase->questions[1].score = 20; 
    strcpy(QuestionDatabase->questions[1].hint, "Terbarukan");
    QuestionDatabase->count++;

    QuestionDatabase->questions[2].question_id = 3;
    strcpy(QuestionDatabase->questions[2].question, "Apa contoh energi terbarukan yang dapat digunakan untuk menghasilkan listrik?");
    strcpy(QuestionDatabase->questions[2].optionA, "Panas Bumi");
    strcpy(QuestionDatabase->questions[2].optionB, "Air");
    strcpy(QuestionDatabase->questions[2].optionC, "Biomassa");
    strcpy(QuestionDatabase->questions[2].optionAnswer, "B");
    QuestionDatabase->questions[2].score = 20; 
    strcpy(QuestionDatabase->questions[2].hint, "Turbin");
    QuestionDatabase->count++;

    QuestionDatabase->questions[3].question_id = 4;
    strcpy(QuestionDatabase->questions[3].question, "Apa upaya untuk meningkatkan efisiensi energi?");
    strcpy(QuestionDatabase->questions[3].optionA, "Melakukan konservasi energi");
    strcpy(QuestionDatabase->questions[3].optionB, "Meningkatkan penggunaan energi terbarukan");
    strcpy(QuestionDatabase->questions[3].optionC, "Menggunakan peralatan hemat energi");
    strcpy(QuestionDatabase->questions[3].optionAnswer, "C");
    QuestionDatabase->questions[3].score = 20; 
    strcpy(QuestionDatabase->questions[3].hint, "Hemat");
    QuestionDatabase->count++;

    QuestionDatabase->questions[4].question_id = 5;
    strcpy(QuestionDatabase->questions[4].question, "Bagaimana negara berkembang dapat berkontribusi pada pencapaian 7SDG?");
    strcpy(QuestionDatabase->questions[4].optionA, "Bergantung sepenuhnya pada bantuan luar negeri");
    strcpy(QuestionDatabase->questions[4].optionB, "Fokus pada pertumbuhan ekonomi");
    strcpy(QuestionDatabase->questions[4].optionC, "Mendorong teknologi energi bersih");
    strcpy(QuestionDatabase->questions[4].optionAnswer, "C");
    QuestionDatabase->questions[4].score = 20; 
    strcpy(QuestionDatabase->questions[4].hint, "Bersih");
    QuestionDatabase->count++;
}
//fungsi untuk meminta data user ketika register sebelum memainkan quiz
void userRegistration(struct UserList *UserDatabase){
    char input_name[50];
    long long input_npm;
    char input_username[10];
    char input_password[10];

    // ambil input user
    printf("\n\nYour Name: ");
    scanf("%50s", &input_name);
    printf("Your NPM: ");
    scanf("%d", &input_npm);
    printf("New Username: ");
    scanf("%10s", &input_username);
    printf("New Password: ");
    scanf("%10s", &input_password);

    // tambahkan data pada database user
    strcpy(UserDatabase->users[UserDatabase->count].name, input_name);
    UserDatabase->users[UserDatabase->count].npm = input_npm;
    strcpy(UserDatabase->users[UserDatabase->count].role, "user");
    UserDatabase->users[UserDatabase->count].score = 0;
    strcpy(UserDatabase->users[UserDatabase->count].username, input_username);
    strcpy(UserDatabase->users[UserDatabase->count].password, input_password);
    UserDatabase->count++;

    printf("\nregistration is success \n");
    system("pause");
    system("cls");

}
//fungsi menampilkan interface main menu
void showLoginPage(){
	printf("\n================================\n"
			"|~ ~ ~ ~ ~ Main Menu ~ ~ ~ ~ ~ |\n"
			"================================\n"
			"================================\n"
			"|                              |\n"
			"|  1. Login                    |\n"
			"|  2. Register                 |\n"
			"|  3. HelpDesk                 |\n"
			"|  4. About Us                 |\n"
			"|  5. Exit	               |\n"
			"|                              |\n"
			"================================\n");
}

// Fungsi untuk simulasi proses logina
bool login(const struct UserList *UserDatabase, struct User *ActiveUser) { //syntax pake const untuk yang list const (tidak ada perubahannya)
    char username[20];
    char password[20];

    // user input username dan password untuk login
    printf("\n\nEnter Username\t: ");
    scanf("%20s", username);
    printf("Enter Password\t: ");
    scanf("%20s", password);

    // loop find user
    int i;
    for (i = 0; i < UserDatabase->count; i++) {
        // cari berdasarkan username
        // melakukan string comparison, jika sama maka bernilai 0
        if (strcmp(UserDatabase->users[i].username, username) == 0) {
            // jika user di temukan maka cek password
            if (strcmp(UserDatabase->users[i].password, password) == 0){
                printf("Login successful!\n");
                system("cls");

                // simpan status user yang sedang aktif
                strcpy(ActiveUser->name, UserDatabase->users[i].name); //disimpan dari user database yang sudah ditemukan tadi
                ActiveUser->npm = UserDatabase->users[i].npm;
                strcpy(ActiveUser->role, UserDatabase->users[i].role);
                strcpy(ActiveUser->username, UserDatabase->users[i].username);
                strcpy(ActiveUser->password, UserDatabase->users[i].password);
                ActiveUser->score = UserDatabase->users[i].score;
                return true;
            }
            else{
                printf("Login failed!\n"); //jika data tidak ditemukan
                return false;
            }
        }
    }
    // data tidak di temukan
    printf("Login failed!\n");
    return false;
}
//fungsi untuk menampilkan pertanyaan quiz
void showAllQuestionDetail(const struct QuestionList *QuestionDatabase){
	int i;
    for (i = 0; i < QuestionDatabase->count; i++) {
    	printf("\n");
    	printf("============================================\n");
		printf("|           	Question ID %d        	  |\n" ,QuestionDatabase->questions[i].question_id);
		printf("============================================\n\n");
        printf("Question : %s\n\n",QuestionDatabase->questions[i].question);
        printf("Option A : %s\n",QuestionDatabase->questions[i].optionA);
        printf("Option B : %s\n",QuestionDatabase->questions[i].optionB);
        printf("Option C : %s\n",QuestionDatabase->questions[i].optionC);
        printf("Option Answer  : %s\n",QuestionDatabase->questions[i].optionAnswer);
        printf("Question Score : %i\n",QuestionDatabase->questions[i].score);
        printf("Option Hint    : %s\n",QuestionDatabase->questions[i].hint);
        system("pause");
        system("cls");
    }
}

//fungsi untuk menampilkan menu bagi admin dan player
int showApplicationMenu(const struct User *ActiveUser){
    int userAppSelect;
    if (strcmp(ActiveUser->role, "admin") == 0){  //sesuai role user
        printf("\n~ ~ Welcome Administrator! ~ ~\n");
        printf("Name : %s\n", ActiveUser->name);
        printf("NPM  : %lld\n", ActiveUser->npm);
        printf("\n================================\n"
				"| ~ ~ ~ ~ Admin's Menu ~ ~ ~ ~ |\n"
				"================================\n"
				"================================\n"
				"|                              |\n"
				"|  1. Show Question            |\n"
				"|  2. Update Question          |\n"
				"|  0. Logout	               |\n"
				"|                              |\n"
				"================================\n");
        printf("User selection (0-2): ");
        scanf("%d", &userAppSelect);
        system("cls");
        return userAppSelect;
    }
    else if (strcmp(ActiveUser->role, "user") == 0){
        printf("\n ~ ~ Welcome Player! ~ ~\n");
        printf("Name : %s\n", ActiveUser->name);
        printf("NPM  : %lld\n", ActiveUser->npm);
        printf("\n================================\n"
				"|~ ~ ~ ~ Player's Menu ~ ~ ~ ~ |\n"
				"================================\n"
				"================================\n"
				"|                              |\n"
				"|  1. Start Quiz	       |\n"
				"|  2. Show Result	       |\n"
				"|  0. Logout	               |\n"
				"|                              |\n"
				"================================\n");
        printf("User selection (0-2): ");
        scanf("%d", &userAppSelect);
        system("cls");
        return userAppSelect;
    }
}
//fungsi untuk memulai quiz
void startQuiz(struct User *ActiveUser, const struct QuestionList *QuestionDatabase) {
    int scoreAccumulation = 0;
    int maximumHint = 3; //hanya bisa memakai maksimal 3 hint dari 5 soal
    char userAnswer[2];
    char userRequestHint;
    int hintCount = 0; //Hitung jumlah hint yang sudah diberikan 

    int i;
    for (i = 0; i < QuestionDatabase->count; i++) { //menampilkan pertanyaan
        printf("\n<~~~~~~~~~~~~~ Question ID %d ~~~~~~~~~~~~~>\n", QuestionDatabase->questions[i].question_id);
        printf("Question: %s\n", QuestionDatabase->questions[i].question);
        printf("A) %s\n", QuestionDatabase->questions[i].optionA);
        printf("B) %s\n", QuestionDatabase->questions[i].optionB);
        printf("C) %s\n", QuestionDatabase->questions[i].optionC);

        // Tanya apakah user ingin hint jika belum melebihi maksimum hint
        if (hintCount < maximumHint) {
            printf("Do you want a hint? (Y/N): ");
            scanf(" %c", &userRequestHint);
			
            if (userRequestHint == 'Y' || userRequestHint == 'y') {
                printf("Hint: %s\n", QuestionDatabase->questions[i].hint);
                hintCount++; // Tambah hitungan hint
                printf("User answer (A-C): "); //lanjut menjawab jika sudah mendapat hint
        		scanf("%s", &userAnswer);
        		if (strcmp(QuestionDatabase->questions[i].optionAnswer, userAnswer) == 0) {
           			scoreAccumulation += QuestionDatabase->questions[i].score;
        			}
            }
            else if (userRequestHint == 'N' || userRequestHint == 'n'){ 
				printf("User answer (A-C): "); //jika tidak ingin hint maka lanjut menjawab soal
        		scanf("%s", &userAnswer);
        		if (strcmp(QuestionDatabase->questions[i].optionAnswer, userAnswer) == 0) {
            		scoreAccumulation += QuestionDatabase->questions[i].score;
        			}
			}
        }
        else{ //jika sudah mencapai maksimum hint maka hint tidak akan ditawarkan lagi
        	printf("User answer (A-C): ");  //langsung menjawab soal
        	scanf("%s", &userAnswer);
        	if (strcmp(QuestionDatabase->questions[i].optionAnswer, userAnswer) == 0) {
           		scoreAccumulation += QuestionDatabase->questions[i].score;
        }
		}
    }
    system("cls");

    // update data active user
    ActiveUser->score = scoreAccumulation; //update score
}

//fungsi untuk menampilkan score
void showUserScore(struct User *ActiveUser){
	printf(" \n\n =======================\n");
    printf(" || Your Score is: %d ||\n",ActiveUser->score);
    printf(" =======================\n");
}
//fungsi untuk menampilkan parameter seberapa teredukasinya user tentang materi
void showAppreciation(struct User *ActiveUser){
  	// Switch case
	switch (ActiveUser->score / 20) {
	    case 0:
	      // Range 0-20
	      printf(" Wah, pemahaman kamu masih kurang banget nih semangat terus yaa belajarnya!\n\n");
	      system("pause");
	      system("cls");
	      break;
	    case 1: 
	      // Range 21-40
	      printf(" Cukup bagus, tapi masih perlu ditingkatkan lagi.\n\n");
	      system("pause");
	      system("cls");
	      break;
	    case 2:
	      // Range 41-60
	      printf(" Sudah lumayan, tapi masih ada yang perlu dipelajari lagi.\n\n");
	      system("pause");
	      system("cls");
	      break;
	    case 3:
	      // Range 61-80
	      printf(" Wah, kamu sudah cukup baik. Terus semangat belajar ya!\n\n");
	      system("pause");
	      system("cls");
	      break;
	    default:
	      // Range 81-100
	      printf(" Wow kamu jenius, jangan lupa berkontribusi di masyarakat ya!\n\n");
	      system("pause");
	      system("cls");
	      break;
	  }
}

//fungsi untuk menyimpan user data yang aktif (setelah player register)
void saveActiveUserData(struct UserList *UserDatabase, struct User *ActiveUser){
	int i;
    for (i = 0; i < UserDatabase->count; i++) {
        if (strcmp(UserDatabase->users[i].username, ActiveUser->username) == 0) {
            UserDatabase->users[i].score = ActiveUser->score;
        }
    }
}
//fungsi menampilkan menu interface saat keluar aplikasi
void keluar(){
  system("CLS");//Membersihkan layar
  Sleep(500);//menjeda program selama 0.5 detik	
  printf("\n\n\n\n\n\n\n");
  printf("\t\t\t\t\t=======================================\n");
  printf("\t\t\t\t\t|* * * * * * * EXIT GAME * * * * * * *|\n");
  printf("\t\t\t\t\t=======================================\n\n");
  printf("\n\n\t\t\t\t\t     TERIMA KASIH SUDAH BERMAIN <3");
  Sleep(1600);//menjeda program selama 1.6 detik
  system("CLS");//Membersihkan layar

}
//fungsi untuk menampilkan helpdesk cara penggunaan aplikasi
void help() {
    int UserSelect;
    printf("\n======================================\n"
           "|~ ~ ~ ~ ~ ~ HELPDESK MENU ~ ~ ~ ~ ~ |\n"
           "======================================\n"
           "|  1. How To Login                   |\n"
           "|  2. How to Register                |\n"
           "|  3. How to View Questions (Admin)  |\n"
           "|  4. How to Edit Questions (Admin)  |\n"
           "|  5. How to Start A Quiz (Player)   |\n"
           "|  6. How to View Score (Player)     |\n"
           "|  0. Back To Main                   |\n"
           "======================================\n");

    do {
        printf("User Selection(0-6): ");
        scanf("%d", &UserSelect);

        if (UserSelect < 0 || UserSelect > 6) {
            printf("Invalid selection, please try again.\n");
            continue;
        }

        // Clearing the screen, note: system("cls") is platform-dependent
        system("cls");

        switch(UserSelect) {
            case 1:
			printf("==========================================\n"
				   "|              How To Login              |\n"
				   "==========================================\n\n"
				   " 1. Enter the number 1 on the main menu\n"
   				   " 2. You will be prompted to enter your username and password\n"
   				   " 3. For admin, enter the username and password as per the program's stored data\n"
    			   " 4. For players, enter the username and password registered during the registration process\n"
          		   " 5. The program will check if the username and password are registered\n"
    			   " 6. If login successful, your Name and Student ID (NPM) will be displayed, and you will be directed to the Admin/User menu\n"
   				   " 7. If the username and password are incorrect, it will display -Login failed- and exit the program\n\n"
   				   );
   			system ("pause");//menjeda program sampai ada input
			break;//keluar dari pengkondisian	   
   			case 2:
   			printf("==========================================\n"
				   "|             How To Register          	 |\n"
				   "==========================================\n\n"
				   " 1. Enter the number 2 on the main menu\n"
   				   " 2. You will be prompted to enter your Name, Student ID (NPM), and create a new account with a username and password\n"
   				   " 3. Registration is successful.\n"
   				   " 4. You will then return to the main menu to log in (follow guide 1)\n\n"	
   				   );
   			system ("pause");//menjeda program sampai ada input
			break;//keluar dari pengkondisian
			case 3:
			printf("===========================================\n"
				   "|            How To View Questions        |\n"
				   "===========================================\n\n"
				   " 1. Log in with the admin account (Follow guide 1).\n"
   				   " 2. Enter the number 1 to view all questions.\n"
   				   " 3. All provided questions will be displayed one by one.\n"
    			   " 4. Press enter after the last question to return to the admin menu.\n\n"
   				   );
   			system ("pause");//menjeda program sampai ada input
			break;//keluar dari pengkondisian
			case 4:
			printf("==========================================\n"
				   "|         How to Edit a Question         |\n"
				   "==========================================\n\n"
   					" 1. Log in with the admin account (Follow guide 1).\n"
   					" 2. Enter the number 2 on the admin menu to edit questions.\n"
   					" 3. Enter the question ID you want to edit.\n"
   					" 4. You can then modify the question and its answer options.\n"
   					" 5. You can also change the answer and the score for that question.\n"
   					" 6. Lastly, you will be prompted to enter the updated hint.\n"
   					" 7. The question is successfully updated.\n"
   					" 8. You will be returned to the admin menu.\n\n"
   				   );
   			system ("pause");//menjeda program sampai ada input
			break;//keluar dari pengkondisian
			case 5:
			printf("==========================================\n"
				   "|           How to Start a Quiz          |\n"
				   "==========================================\n\n"
 				   " 1. Log in with the user account. (If you don't have an account, follow guide 2 -How to Register-).\n"
    			   " 2. After logging in, you will see the -Player Menu-\n"
  				   " 3. Enter the number 1 -Start Quiz- to begin the quiz.\n"
 				   " 4. You can start working on the quiz.\n"
				   " 5. Pay close attention to the instructions while answering the quiz.\n\n"
   				   );
   			system ("pause");//menjeda program sampai ada input
			break;//keluar dari pengkondisian
			case 6:
			printf("============================================\n"
				   "|         How to View Quiz Results         |\n"
				   "============================================\n\n"
   				   " 1. Register and log in with the player account. (Follow guides 1 and 2).\n"
 				   " 2. Start the quiz first to earn points; otherwise, your score will be 0.\n"
  				   " 3. Choose the number 2 on the player menu.\n"
  				   " 4. The quiz result score will be displayed.\n"
   				   " 5. After that, you will be immediately returned to the player menu.\n\n"
   				   );
   			system ("pause");//menjeda program sampai ada input
			break;//keluar dari pengkondisian
			default:
				break;
			
				
                
        }

        getchar();
        system("cls");
    } while (UserSelect > 7 || UserSelect < 0); //akan ditampilkan terus sampai pilihan di input user
}
//menampilkan profil developer dan latar belakang program dibuat
void AboutUs(){
	printf("\n\n\n================================== Greetings! ==================================\n\n\nHello! We are from the group 4 <Lobi - Lobi>. Our group consists of 4  members:\n"
	       "Ahmad Fariz  Khairi, Aisya  Rivelia  Azzahra, Aliya  Rizqiningrum  Salamun, and\n"
		   "Maharaka Fadhilah. As game developers , we  designed  a  mini  quiz  to  assess\n"
		   "public  awareness  regarding  the  importance  of  affordable  and clean energy\n"
		   "access, as well as knowledge about the 7th Sustainable Development Goal (SDGs):\n"
		   "Affordable and Clean Energy. This application aims to help educate and  promote\n"
		   "understanding of the significance of the 7th SDG, encouraging  people  to  take\n"
		   "action to address the related challenges. Enjoy!\n\n\n");
		   system("pause");
		   system("cls");
}

int main() {
	//menghias terminal
	system("color D");
    system("color B5");
    // deklarasi variable user
    struct UserList UserDatabase; //ketika di logout bakal tersimpan di user database
    struct User ActiveUser; //active user saat dia login akan diisi dari data yang input
    UserDatabase.count = 0;

    // deklarasi variable question
    struct QuestionList QuestionDatabase;
    int loginUserSelect; // menu utama
    int appUserSelect; // player atau admin
    int questionIdToUpdate; //untuk update pertanyaan
    QuestionDatabase.count = 0;

    // Inisialisasi data user dan question
    initializeUserList(&UserDatabase); // dikirim alamat user database
    initializeQuestionList(&QuestionDatabase); // dikirim alamat dari question database
	welcome(); //menampilkan interface masuk ke game
    // show login page
    showLoginPage(); //panggil function menu utama
    printf("User selection (1-5): ");
    scanf("%d", &loginUserSelect); //meminta user memilih fitur yang ingin digunakan
    system("cls");

    while(loginUserSelect != 5){ //selama tidak memilih 5 menu akan terus tampil (loop)
        if (loginUserSelect == 1){ //kalau user memilih 1
            //akan diminta login
            if (!login(&UserDatabase, &ActiveUser)) { // lookup database
            	system("pause");
            	system("cls");
                continue; //jika login gagal maka akan diminta lagi username dan pass sampai benar
            }
            // tampilkan menu aplikasi
            appUserSelect = showApplicationMenu(&ActiveUser);

            while(appUserSelect != 0){ //selama tidak memilih 0 loop akan jalan
                // process pilihan user
                if (strcmp(ActiveUser.role, "admin") == 0){ //kondisi jika role adalah admin
                    if(appUserSelect == 1){
                        // tampilkan detail soal
                        showAllQuestionDetail(&QuestionDatabase);
                    }
                    else if (appUserSelect == 2){
                        // update soal
                        printf("Question ID to Update: ");
                        scanf("%d", &questionIdToUpdate);
                        updateQuestion(&QuestionDatabase, questionIdToUpdate);
                    }
                }
                else if (strcmp(ActiveUser.role, "user") == 0){ //kondisi jika role adalah user(player)
                    if(appUserSelect == 1){
                        // mulai quiz
                        startQuiz(&ActiveUser, &QuestionDatabase);
                    }
                    else if(appUserSelect == 2){
                        showUserScore(&ActiveUser); //tampilkan score
                        showAppreciation(&ActiveUser); //dan parameter
                    }
                }
                 
                saveActiveUserData(&UserDatabase, &ActiveUser); //simpan data player selama bermain
                appUserSelect = showApplicationMenu(&ActiveUser); //tampilkan terus application menu
            }

        }
        else if (loginUserSelect == 2){ 
            userRegistration(&UserDatabase); //kalau memilih 2 maka user akan diminta register data
        }
        else if (loginUserSelect == 3){
            help(); //jika memilih 3 user akan dibawa ke menu panduan menggunakan program
        }
        else if (loginUserSelect == 4){
        	AboutUs(); //jika memilih 4 akan muncul biodata developer
		}
        showLoginPage(); //akan muncul terus menu selam belum input 5 (exit)
        printf("User selection: ");
        scanf("%d", &loginUserSelect);
        system("cls");
    }
    keluar(); //jika sudah input 5 akan muncul interface exit
    return 0;
}    
