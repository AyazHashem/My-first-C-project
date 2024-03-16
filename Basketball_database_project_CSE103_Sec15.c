#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[100];
    char team[100];
    char position[2];
    int jersey_num;
    int height;
    int age;
    int salary;
} Player;

typedef struct {
    char name[100];
    char city[100];
    char coach[100];
    int players_num;
} Team;

void fn_initializeGarbageTeam(Team *garbage_team){
    strcpy(garbage_team->name, "Unassigned");
    strcpy(garbage_team->city, "Unassigned");
    strcpy(garbage_team->coach, "Unassigned");
    garbage_team->players_num = 0;
}

void fn_initializeGarbagePlayer(Player *garbage_player) {
    strcpy(garbage_player->name, "Unassigned");
    strcpy(garbage_player->team, "Unassigned");
    strcpy(garbage_player->position, "Unassigned");
    garbage_player->jersey_num = 0;
    garbage_player->height = 0;
    garbage_player->age = 0;
    garbage_player->salary = 0;
}

void fn_initializeEmptyTeams(Team teams[4]) {
    Team garbage_team;
    fn_initializeGarbageTeam(&garbage_team);

    for (int i = 0; i < 4; i++) {
        strcpy(teams[i].name, garbage_team.name);
        strcpy(teams[i].city, garbage_team.city);
        strcpy(teams[i].coach, garbage_team.coach);
        teams[i].players_num = garbage_team.players_num;
    }
}

void fn_initializeEmptyPlayers(Player players[20]) {
    Player garbage_player;
    fn_initializeGarbagePlayer(&garbage_player);

    for (int j = 0; j < 20; j++) {
        strcpy(players[j].name, garbage_player.name);
        strcpy(players[j].team, garbage_player.team);
        strcpy(players[j].position, garbage_player.position);
        players[j].jersey_num = garbage_player.jersey_num;
        players[j].height = garbage_player.height;
        players[j].age = garbage_player.age;
        players[j].salary = garbage_player.salary;
    }
}

void fn_addteam(Team teams[], int counter) {
    Team garbage_team;
    fn_initializeGarbageTeam(&garbage_team);

    system("cls");
    displaymenu();
    printf("\n\n<><><><><><><><><><><><><><><>\n");
    printf("<><>       ADD TEAM       <><>\n");
    printf("<><><><><><><><><><><><><><><>\n");
    while (counter < 4) {
        if (strcmp(teams[counter].name, garbage_team.name) == 0) {
            printf("\nEnter the team's name: ",counter);
            scanf(" %[^\n]", teams[counter].name);

            printf("\nEnter the team's city: ");
            scanf(" %[^\n]", teams[counter].city);

            printf("\nEnter the team coach's name: ");
            scanf(" %[^\n]", teams[counter].coach);

            do {
                printf("\nEnter the team's squad size: ");
                scanf(" %d", &teams[counter].players_num);
                if (teams[counter].players_num < 3 || teams[counter].players_num > 5) {
                    printf("\nA team cannot have less than 3 players or more than 5, please enter an appropriate squad size.");
                }
            } while (teams[counter].players_num < 3 || teams[counter].players_num > 5);

            break;
        } else {
            counter++;
            if (counter == 4) {
                printf("\nThere aren't any empty slots left for you to add teams! Sorry.");
            }
        }
    }
}

void fn_addplayer(Player players[20], int counter, Team teams[4]) {
    Player garbage_player;
    fn_initializeGarbagePlayer(&garbage_player);

    system("cls");
    displaymenu();
    printf("\n\n<><><><><><><><><><><><><><><>\n");
    printf("<><>      ADD PLAYER      <><>\n");
    printf("<><><><><><><><><><><><><><><>\n");
    int teamIndex;

    printf("\nEnter the team index (1 to 4) to add the player: ");
    scanf("%d", &teamIndex);

    if (teamIndex < 1 || teamIndex > 4) {
        printf("\nInvalid team index. Please enter a valid index between 1 and 4.\n");
        return;
    }

    counter = 0;
    while (counter < 20) {
        if (strcmp(players[counter].name, garbage_player.name) == 0) {
            printf("\nEnter the player's name: ");
            scanf(" %[^\n]", players[counter].name);
            strcpy(players[counter].team, teams[teamIndex - 1].name);  // Assign the team name
            do {
                printf("\nEnter the player's position (PG SG SF PF C): ");
                scanf("%s", players[counter].position);
                if(strcmp(players[counter].position, "PG") != 0 &&
                   strcmp(players[counter].position, "SG") != 0 &&
                   strcmp(players[counter].position, "SF") != 0 &&
                   strcmp(players[counter].position, "PF") != 0 &&
                   strcmp(players[counter].position, "C") != 0) {
                    printf("\nYou have entered an incorrect position, please enter PG, SG, SF, PF, or C.");
                }
            } while (strcmp(players[counter].position, "PG") != 0 &&
                     strcmp(players[counter].position, "SG") != 0 &&
                     strcmp(players[counter].position, "SF") != 0 &&
                     strcmp(players[counter].position, "PF") != 0 &&
                     strcmp(players[counter].position, "C") != 0);

            printf("\nEnter the player's height in centimeters: ");
            scanf(" %d", &players[counter].height);
            printf("\nEnter the player's age: ");
            scanf(" %d", &players[counter].age);
            printf("\nEnter the player's salary: $");
            scanf(" %d", &players[counter].salary);
            printf("\nEnter the player's jersey no: ");
            scanf(" %d", &players[counter].jersey_num);
            printf("\nPlayer added to the team %s.\n", teams[teamIndex - 1].name);
            break;
        } else {
            counter++;
            if (counter == 19) {
                printf("\nThere aren't any empty slots left for you to add players! Sorry.\n");
                return;
            }
        }
    }
}
void fn_removeteam(Team teams[4], int list_num, char choice) {
    Team garbage_team;
    fn_initializeGarbageTeam(&garbage_team);

    system("cls");
    displaymenu();
    printf("\n\n<><><><><><><><><><><><><><><>\n");
    printf("<><>     REMOVE TEAM      <><>\n");
    printf("<><><><><><><><><><><><><><><>\n");
    printf("\nIs there any team you would like to remove? Enter a lowercase 'y' for yes or a lowercase 'n' for no. ");
    do {
        scanf(" %c", &choice);
        switch (choice) {
            case 'n':
                break;
            case 'y':
                printf("\nEnter the list number of the team you would like to delete: ");
                do {
                    scanf(" %d", &list_num);
                    if (list_num < 1 || list_num > 4) {
                        printf("\nThe list number you've entered is invalid, please enter an appropriate list number");
                    } else {
                        strcpy(teams[list_num - 1].name, garbage_team.name);
                        strcpy(teams[list_num - 1].city, garbage_team.city);
                        strcpy(teams[list_num - 1].coach, garbage_team.coach);
                        teams[list_num - 1].players_num = garbage_team.players_num;
                        printf("\n=======================================\n");
                        printf("==      Team Removed Successfully    ==");
                        printf("\n=======================================\n");
                        break;
                    }
                } while (1);
                break;
            default:
                printf("\nPlease enter an appropriate keyword!");
                break;
        }
    } while (choice != 'y' && choice != 'n');
}


void fn_removeplayer(Player players[20], int list_num, char choice) {
    Player garbage_player;
    fn_initializeGarbagePlayer(&garbage_player);

    system("cls");
    displaymenu();
    printf("\n\n<><><><><><><><><><><><><><><>\n");
    printf("<><>    REMOVE PLAYER     <><>\n");
    printf("<><><><><><><><><><><><><><><>\n");
    printf("\nIs there any player you would like to remove? Enter a lowercase 'y' for yes or a lowercase 'n' for no. ");

    do {
        scanf(" %c", &choice);
        switch (choice) {
            case 'n':
                break;
            case 'y':
                printf("\nEnter the list number of the player you would like to delete: ");
                do {
                    scanf(" %d", &list_num);
                    if (list_num < 1 || list_num > 20) {
                        printf("\nThe list number you've entered is invalid, please enter an appropriate list number: ");
                        while(getchar() != '\n'); // Clear the input buffer
                    } else {
                        strcpy(players[list_num - 1].name, garbage_player.name);
                        strcpy(players[list_num - 1].team, garbage_player.team);
                        strcpy(players[list_num - 1].position, garbage_player.position);
                        players[list_num - 1].jersey_num = 0;
                        players[list_num - 1].height = 0;
                        players[list_num - 1].age = 0;
                        players[list_num - 1].salary = 0;
                        printf("\n=======================================\n");
                        printf("==    Player Removed Successfully    ==");
                        printf("\n=======================================\n");
                        break;
                    }
                } while (1);
                break;
            default:
                printf("\nPlease enter an appropriate keyword!");
                while(getchar() != '\n'); // Clear the input buffer
                break;
        }
    } while (choice != 'y' && choice != 'n');
}


void fn_editteam(Team teams[4]) {
    char choice;
    int list_num;

    system("cls");
    displaymenu();
    printf("\n\n<><><><><><><><><><><><><><><>\n");
    printf("<><>      EDIT TEAM       <><>\n");
    printf("<><><><><><><><><><><><><><><>\n");
    printf("\nIs there any team whose information you would like to edit? Enter 'y' for yes or 'n' for no: ");
    scanf(" %c", &choice);

    if (choice == 'n'){
        return; // No team to edit, exit the function
    }
    else if(choice=='y') {
        printf("\nEnter the list number of the team whose information you would like to edit(1-4): ");
        scanf(" %d", &list_num);

        printf("\nWould you like to change their name? Enter 'y' for yes or 'n' for no: ");
        scanf(" %c", &choice);
        if (choice == 'y') {
            printf("\n=============================================\n");
            printf("\nEnter their new name: ");
            scanf(" %[^\n]", teams[list_num - 1].name);
            printf("\n=============================================\n");
        }

        printf("\nWould you like to change the city they are located in? Enter 'y' for yes or 'n' for no: ");
        scanf(" %c", &choice);
        if (choice == 'y') {
            printf("\n=============================================\n");
            printf("\nEnter their new city: ");
            scanf(" %[^\n]", teams[list_num - 1].city);
            printf("\n=============================================\n");
        }

        printf("\nWould you like to change their current coach? Enter 'y' for yes or 'n' for no: ");
        scanf(" %c", &choice);
        if (choice == 'y') {
            printf("\n=============================================\n");
            printf("\nEnter the name of the new coach: ");
            scanf(" %[^\n]", teams[list_num - 1].coach);
            printf("\n=============================================\n");
        }

        printf("\nWould you like to change the number of players on the team? Enter 'y' for yes or 'n' for no: ");
        scanf(" %c", &choice);
        if (choice == 'y') {
            printf("\n=============================================\n");
            printf("\nEnter the new number of players (between 3 and 5): ");
            do {
                scanf(" %d", &teams[list_num - 1].players_num);
                if (teams[list_num - 1].players_num < 3 || teams[list_num - 1].players_num > 5) {
                printf("\nInvalid squad size. Please enter a number between 3 and 5.\n");
                }
            } while (teams[list_num - 1].players_num < 3 || teams[list_num - 1].players_num > 5);
        }

    } else {
        printf("\nEnter the appropriate keyword!\n");
    }



    printf("\n=======================================\n");
    printf("==         Updated Information       ==");
    printf("\n=======================================\n");
    printf("Name: %s\n", teams[list_num - 1].name);
    printf("City: %s\n", teams[list_num - 1].city);
    printf("Coach: %s\n", teams[list_num - 1].coach);
    printf("Squad Size: %d Players\n", teams[list_num - 1].players_num);
}


void fn_editplayer(Player players[20], int list_num, char choice) {
    system("cls");
    displaymenu();
    printf("\n\n<><><><><><><><><><><><><><><>\n");
    printf("<><>     EDIT PLAYER      <><>\n");
    printf("<><><><><><><><><><><><><><><>\n");
    printf("\nIs there any player whose information you would like to edit? Enter a lowercase 'y' for yes or a lowercase 'n' for no. ");

    do {
        scanf(" %c", &choice);
        switch (choice) {
            case 'n':
                break;
            case 'y':
                printf("\nEnter the list number of the player whose information you would like to edit(1-4): ");
                scanf(" %d", &list_num);
                printf("\nWould you like to change their team? Enter a lowercase 'y' for yes or a lowercase 'n' for no. ");
                do {
                    scanf(" %c", &choice);
                    switch (choice) {
                        case 'y':
                            printf("\n=============================================\n");
                            printf("\nEnter their new team: ");
                            scanf(" %[^\n]", players[list_num - 1].team);
                            break;
                        case 'n':
                            break;
                        default:
                            printf("\nEnter the appropriate keyword!\n");
                            break;
                    }
                } while (choice != 'y' && choice != 'n');
            while(choice != 'y' && choice != 'n');
            printf("\nWould you like to change their position? Enter a lowercase 'y' for yes or a lowercase 'n' for no. ");
            do{
                scanf(" %c", &choice);
                switch(choice){
                    case 'y':
                        printf("\n=============================================\n");
                        printf("\nEnter their new position (PG SG SF PF C): ");
                        scanf(" %s", players[list_num - 1].position);
                        break;
                    case 'n':
                        break;
                    default:
                        printf("\nEnter the appropriate keyword!\n");
                        break;
                }
            }
            while(choice != 'y' && choice != 'n');
            printf("\nWould you like to change their jersey number? Enter a lowercase 'y' for yes or a lowercase 'n' for no. ");
            do{
                scanf(" %c", &choice);
                switch(choice){
                    case 'y':
                        printf("\n=============================================\n");
                        printf("\nEnter their new jersey number: ");
                        scanf(" %d", &players[list_num - 1].jersey_num);
                        break;
                    case 'n':
                        break;
                    default:
                        printf("\nEnter the appropriate keyword!\n");
                        break;
                }
            }
            while(choice != 'y' && choice != 'n');
            printf("\nHas the player grown taller since the last time? Enter a lowercase 'y' for yes or a lowercase 'n' for no. ");
            do{
                scanf(" %c", &choice);
                switch(choice){
                    case 'y':
                        printf("\n=============================================\n");
                        printf("\nEnter their new height: ");
                        scanf(" %d", &players[list_num - 1].height);
                        break;
                    case 'n':
                        break;
                    default:
                        printf("\nEnter the appropriate keyword!\n");
                        break;
                }
            }
            while(choice != 'y' && choice != 'n');
            printf("\nWould you like to edit the player's salary? Enter a lowercase 'y' for yes or a lowercase 'n' for no. ");
            do{
                scanf(" %c", &choice);
                switch(choice){
                    case 'y':
                    printf("\n=============================================\n");
                    printf("\nEnter their new salary: ");
                    scanf(" %d", &players[list_num - 1].salary);
                    break;
                    case 'n':
                    break;
                    default:
                     printf("\nEnter the appropriate keyword!\n");
                     break;
            }
            }
            while(choice != 'y' && choice != 'n');
            printf("\nHas the player grown older? Enter a lowercase 'y' for yes or a lowercase 'n' for no. ");
            do{
                scanf(" %c", &choice);
                switch(choice){
                    case 'y':
                        printf("\n=============================================\n");
                        printf("\nEnter their current age: ");
                        scanf(" %d", &players[list_num - 1].age);
                        break;
                    case 'n':
                        break;
                    default:
                        printf("\nEnter the appropriate keyword!\n");
            }
            }
            while(choice != 'y' && choice != 'n');
            printf("\n=======================================\n");
            printf("==        Updated Information        ==");
            printf("\n=======================================\n");
            printf("\nName: %s", players[list_num - 1].name);
            printf("\nTeam: %s", players[list_num - 1].team);
            printf("\nPosition: %s", players[list_num - 1].position);
            printf("\nJersey number: %d", players[list_num - 1].jersey_num);
            printf("\nSalary: $%d", players[list_num - 1].salary);
            printf("\nAge: %d Years\n", players[list_num - 1].age);
            break;
            default:
            printf("\nEnter the appropriate keyword!");
            break;
        }
    }
    while(choice != 'y' && choice != 'n');
}

void displaymenu()
{
    printf("********************************************************************************************************************\n");
    printf("********************************************************************************************************************\n");
    printf("***                                                                                                              ***\n");
    printf("***                                   BASKETBALL TEAM MANAGEMENT SYSTEM                                          ***\n");
    printf("***                                                                                                  CSE PROJECT ***\n");
    printf("********************************************************************************************************************\n");
    printf("********************************************************************************************************************\n");
}

int main(void){

    Team teams[4];
    Team garbage_team;
    Player players[20];
    Player garbage_player;
    int choice, choice_team, choice_player;
    int list_num;
    int counter = 0;

    fn_initializeGarbageTeam(&garbage_team);
    fn_initializeEmptyTeams(teams);
    fn_initializeGarbagePlayer(&garbage_player);
    fn_initializeEmptyPlayers(players);

    do {
        displaymenu();
        printf("\n\n<><><><><><><><><><><><><><><><>\n");
        printf("<><>       MAIN MENU        <><>\n");
        printf("<><><><><><><><><><><><><><><><>\n");
        printf("\nPlease enter one of the following numbers to carry out their respective functions: ");
        printf("\n\n===========TEAMS PAGE===========");
        printf("\n1) View teams");
        printf("\n2) Add teams");
        printf("\n3) Remove teams");
        printf("\n4) Edit teams");
        printf("\n\n========PLAYERS PAGE============");
        printf("\n5) View players");
        printf("\n6) Add players");
        printf("\n7) Remove players");
        printf("\n8) Edit players");
        printf("\n================================");
        printf("\n9) Exit\n");
        printf("\nEnter choice:");
        scanf("%d", &choice);
        switch(choice){
        case 1:
                system("cls");
                displaymenu();
                printf("\n\n<><><><><><><><><><><><><><><>\n");
                printf("<><>      VIEW TEAM       <><>\n");
                printf("<><><><><><><><><><><><><><><>\n");
                for (int i = 0; i < 4; i++) {
                    printf("\n%d) Team: %s", i + 1, teams[i].name);
                    printf("\nCity: %s", teams[i].city);
                    printf("\nTeam: %s", teams[i].coach);
                    printf("\nSquad size: %d", teams[i].players_num);
                    printf("\n\n========================\n");
                }
                printf("\n\nEnter any key to exit: ");
                getch();
                system("cls");
                break;
        case 2:
                system("cls"); //clears the screen
                fn_addteam(teams, counter);
                printf("\n\nEnter any key to exit: ");
                getch();
                system("cls");
                break;
        case 3:
                system("cls");
                fn_removeteam(teams, list_num, choice_team);
                printf("\n\nEnter any key to exit: ");
                getch();
                system("cls");
                break;
        case 4:
                system("cls");
                fn_editteam(teams);
                printf("\n\nEnter any key to exit: ");
                getch();
                system("cls");
                break;
        case 5:
                system("cls");
                displaymenu();
                printf("\n\n<><><><><><><><><><><><><><><>\n");
                printf("<><>     VIEW PLAYERS     <><>\n");
                printf("<><><><><><><><><><><><><><><>\n");
                for (int j = 0; j < 20; j++) {
                    printf("\n%d) Player name: %s", j + 1, players[j].name);
                    printf("\nPlayer's team: %s", players[j].team);
                    printf("\nPlayer's position: %s", players[j].position);
                    printf("\nPlayer's jersey number: %d", players[j].jersey_num);
                    printf("\nPlayer's height %d CM", players[j].height);
                    printf("\nPlayer's age: %d years", players[j].age);
                    printf("\nPlayer's salary: $ %d", players[j].salary);
                    printf("\n\n========================\n");
                }
                printf("\n\nEnter any key to exit: ");
                getch();
                system("cls");
                break;
        case 6:
                system("cls");
                fn_addplayer(players, counter, teams);
                printf("\nEnter any key to exit: ");
                getch();
                system("cls");
                break;
        case 7:
                system("cls");
                fn_removeplayer(players, list_num, choice_player);
                printf("\nEnter any key to exit: ");
                getch();
                system("cls");
                break;
        case 8:
                system("cls");
                fn_editplayer(players, list_num, choice_player);
                printf("\nEnter any key to exit: ");
                getch();
                system("cls");
                break;
        case 9:
                exit(0);
                break;
        }
    } while (1);

    return 0;

}
