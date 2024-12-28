#include<iostream>
#include<string>
#include<fstream>
using namespace std;

void team() {
    string team_name[2];
    for (int i = 0; i < 2; i++) {
        cout << "Enter the name of the team " << (i + 1) << " : "; 
        cin >> team_name[i];
    }

    int team_size;
    cout << "Enter the amount of players per side: ";
    cin >> team_size;

    cout << "Team Players of " << team_name[0] << endl;
    string players_of_team_one[team_size];
    cin.ignore(); 
    for (int i = 0; i < team_size; i++) {
        cout << "Enter the name of the player " << (i + 1) << " : ";
        getline(cin, players_of_team_one[i]);
    }

    cout << "Team Players of " << team_name[1] << endl;
    string players_of_team_two[team_size];
    for (int i = 0; i < team_size; i++) {
        cout << "Enter the name of the player " << (i + 1) << " : "; 
        getline(cin, players_of_team_two[i]);
    }

    int toss;
    cout << "---------- IT'S TOSS TIME NOW ----------" << endl;
    cout << "Who won the toss?" << endl;
    cout << "1. " << team_name[0] << endl;
    cout << "2. " << team_name[1] << endl;
    cout << "Enter choice by number (Press 1 or 2): ";
    cin >> toss;

    int toss_choice;    
    cout << "What have they chosen to?" << endl;
    cout << "1. BAT" << endl;
    cout << "2. BOWL" << endl;
    cout << "Enter choice by number (Press 1 or 2): ";
    cin >> toss_choice;

    int opener, nonstriker, bowler;
    if (toss == 1) {
        cout << "----- " << team_name[0] << " won the toss & chose to";
        if (toss_choice == 1) { 
            cout << " Bat first -----" << endl;
            cout << "Select two batsmen from the following players:" << endl;
            for (int i = 0; i < team_size; i++) {
                cout << (i + 1) << ". " << players_of_team_one[i] << endl;
            }
            cout << "Select the Opening batsman of " << team_name[0] << " by number: ";
            cin >> opener;
            cout << "Select the Non-Striker batsman of " << team_name[0] << " by number: ";
            cin >> nonstriker;

            cout << "Select the bowler from the following players: " << endl;
            for (int i = 0; i < team_size; i++) {
                cout << (i + 1) << ". " << players_of_team_two[i] << endl;
            }
            cout << "Enter the number of the bowler: ";
            cin >> bowler;
        }
        else { 
            cout << " Bowl first -----" << endl;
            cout << "Select the bowler from the following players: " << endl;
            for (int i = 0; i < team_size; i++) {
                cout << (i + 1) << ". " << players_of_team_one[i] << endl;
            }
            cout << "Enter the number of the bowler: ";
            cin >> bowler;
            for (int i = 0; i < team_size; i++) {
                cout << (i + 1) << ". " << players_of_team_two[i] << endl;
            }
            cout << "Select the Opening batsman of " << team_name[1] << " by number: ";
            cin >> opener;
            cout << "Select the Non-Striker batsman of " << team_name[1] << " by number: ";
            cin >> nonstriker;
        }
    } else {
        cout << "----- " << team_name[1] << " won the toss & chose to";
        if (toss_choice == 1) {
            cout << " Bat first -----" << endl;
            cout << "Select two batsmen from the following players:" << endl;
            for (int i = 0; i < team_size; i++) {
                cout << (i + 1) << ". " << players_of_team_two[i] << endl;
            }
            cout << "Select the Opening batsman of " << team_name[1] << " by number: ";
            cin >> opener;
            cout << "Select the Non-Striker batsman of " << team_name[1] << " by number: ";
            cin >> nonstriker;
            cout << "Select the bowler from the following players: " << endl;
            for (int i = 0; i < team_size; i++) {
                cout << (i + 1) << ". " << players_of_team_one[i] << endl;
            }
            cout << "Enter the number of the bowler: ";
            cin >> bowler;
        }
        else { 
            cout << " Bowl first -----" << endl;
            cout << "Select the bowler from the following players: " << endl;
            for (int i = 0; i < team_size; i++) {
                cout << (i + 1) << ". " << players_of_team_two[i] << endl;
            }
            cout << "Enter the number of the bowler: ";
            cin >> bowler;

            for (int i = 0; i < team_size; i++) {
                cout << (i + 1) << ". " << players_of_team_one[i] << endl;
            }
            cout << "Select the Opening batsman of " << team_name[0] << " by number: ";
            cin >> opener;
            cout << "Select the Non-Striker batsman of " << team_name[0] << " by number: ";
            cin >> nonstriker;
        }
    }

    int score = 0, wickets = 0, extras = 0;
    int overs;
    cout << "Enter the number of overs you want to play (e.g., 5, 20, 50): ";
    cin >> overs;

    cout << "---------- It's a " << overs << " Overs Match -----------" << endl;

    int batsman_scores[team_size] = {0};
    int batsman_balls[team_size] = {0};
    int bowler_runs_conceded[team_size] = {0};
    int bowler_balls_bowled[team_size] = {0};
    int bowler_wickets_taken[team_size] = {0};  
    int bowler_maiden_overs[team_size] = {0}; 
    double run_rate;

    bool free_hit = false;
    int total_balls_bowled = 0;


    for (int over = 1; over <= overs; over++) {
        cout << "Over " << over << " begins:" << endl;
        int runs_in_over = 0;  
        int dot_balls_in_over = 0; 
         
        for (int ball = 1; ball <= 6; ball++) {
            if (wickets == (team_size - 1)) {
                cout << "All players are out! Innings over." << endl;
                break;
            }

            cout << "Ball " << ball << ": Enter what happened (0 = Dot ball, 1 = 1 run, 2 = 2 runs, 3 = 3 runs, 4 = Four, 6 = Six, 7 = Wicket, 8 = No Ball, 9 = Wide): ";
            int event;
            cin >> event;
            
            total_balls_bowled++;

            switch (event) {
                case 0:
                    cout << "Dot ball!" << endl;
                    batsman_balls[opener - 1]++;
                    dot_balls_in_over++;
                    bowler_balls_bowled[bowler - 1]++;
                    break;
                case 1:
                    score += 1;
                    batsman_scores[opener - 1]++;
                    batsman_balls[opener - 1]++;
                    bowler_runs_conceded[bowler - 1]++;
                    bowler_balls_bowled[bowler - 1]++;
                    runs_in_over++;
                    cout << "1 run scored." << endl;
                    swap(opener, nonstriker);
                    break;
                case 2:
                    score += 2;
                    batsman_scores[opener - 1] += 2;
                    batsman_balls[opener - 1]++;
                    bowler_runs_conceded[bowler - 1] += 2;
                    bowler_balls_bowled[bowler - 1]++;
                    runs_in_over += 2;
                    cout << "2 runs scored." << endl;
                    break;
                case 3:
                    score += 3;
                    batsman_scores[opener - 1] += 3;
                    batsman_balls[opener - 1]++;
                    bowler_runs_conceded[bowler - 1] += 3;
                    bowler_balls_bowled[bowler - 1]++;
                    runs_in_over += 3;
                    cout << "3 runs scored." << endl;
                    swap(opener, nonstriker);
                    break;
                case 4:
                    score += 4;
                    batsman_scores[opener - 1] += 4;
                    batsman_balls[opener - 1]++;
                    bowler_runs_conceded[bowler - 1] += 4;
                    bowler_balls_bowled[bowler - 1]++;
                    runs_in_over += 4;
                    cout << "It's a Four!" << endl;
                    break;
                case 6:
                    score += 6;
                    batsman_scores[opener - 1] += 6;
                    batsman_balls[opener - 1]++;
                    bowler_runs_conceded[bowler - 1] += 6;
                    bowler_balls_bowled[bowler - 1]++;
                    runs_in_over += 6;
                    cout << "It's a Six!" << endl;
                    break;
                case 7:
                    if (free_hit) {
                        cout << "It's a Free Hit! Wickets can't fall on a Free Hit." << endl;
                    } else {
                        wickets++;
                        bowler_wickets_taken[bowler - 1]++;
                        cout << "Wicket! " << wickets << " out." << endl;
                        bowler_balls_bowled[bowler - 1]++;
                        opener = nonstriker;
						 
                    }
                    break;
                case 8:
                    score += 1;
                    extras += 1;
                    bowler_runs_conceded[bowler - 1]++;
                    cout << "No Ball! 1 extra run awarded." << endl;
                    cout << "Next ball is a Free Hit!" << endl;
                    free_hit = true;
                    ball--;
                    break;
                case 9:
                    score += 1;
                    extras += 1;
                    bowler_runs_conceded[bowler - 1]++;
                    cout << "Wide ball! 1 extra run awarded." << endl;
                    ball--;
                    break;
                default:
                    cout << "Invalid input. Please enter a valid event." << endl;
                    ball--;
                    break;
            }
            
            double total_runs = score + extras;
            run_rate = total_runs / (total_balls_bowled / 6.0);  
            if (over != overs){
            cout << "Current Score: " << score << "/" << wickets << " (Extras: " << extras << ") (Run Rate: " << run_rate << ")" << endl;}
            if(toss == 1 && toss_choice == 1){
            cout << "Batsman " << players_of_team_one[opener - 1] << ": " << batsman_scores[opener - 1] << " (" << batsman_balls[opener - 1] << " balls)" << endl;
            cout << "Bowler " << players_of_team_two[bowler - 1] << ": " << bowler_runs_conceded[bowler - 1] << " runs conceded in " << bowler_balls_bowled[bowler - 1] << " balls." << endl;
        }
        else if(toss == 1 && toss_choice == 2){
            cout << "Batsman " << players_of_team_two[opener - 1] << ": " << batsman_scores[opener - 1] << " (" << batsman_balls[opener - 1] << " balls)" << endl;
            cout << "Bowler " << players_of_team_one[bowler - 1] << ": " << bowler_runs_conceded[bowler - 1] << " runs conceded in " << bowler_balls_bowled[bowler - 1] << " balls." << endl;
        }
        else if(toss == 2 && toss_choice == 1){
            cout << "Batsman " << players_of_team_two[opener - 1] << ": " << batsman_scores[opener - 1] << " (" << batsman_balls[opener - 1] << " balls)" << endl;
            cout << "Bowler " << players_of_team_one[bowler - 1] << ": " << bowler_runs_conceded[bowler - 1] << " runs conceded in " << bowler_balls_bowled[bowler - 1] << " balls." << endl;
        }
        else if(toss == 2 && toss_choice == 2){
            cout << "Batsman " << players_of_team_one[opener - 1] << ": " << batsman_scores[opener - 1] << " (" << batsman_balls[opener - 1] << " balls)" << endl;
            cout << "Bowler " << players_of_team_two[bowler - 1] << ": " << bowler_runs_conceded[bowler - 1] << " runs conceded in " << bowler_balls_bowled[bowler - 1] << " balls." << endl;
        }
            if (free_hit && event != 8 && event != 9) {
                free_hit = false;
            }

            if (wickets == (team_size - 1)) {
                cout << "All players are out! Innings over." << endl;
                break;
            }
        }
        
         if ( dot_balls_in_over == 6) {
        bowler_maiden_overs[bowler - 1]++;
    }

        cout << "Over " << over << " completed. Bowler stats:" << endl;
        for (int i = 0; i < team_size; i++) {
        	if(toss == 1 && toss_choice == 1){
            cout << players_of_team_two[i] << ": " << bowler_runs_conceded[i] << " runs conceded in " << bowler_balls_bowled[bowler - 1] << " balls, has taken " << bowler_wickets_taken[bowler - 1] << " wickets and" << " has " << bowler_maiden_overs[i] << " maiden overs." << endl;}
            else if(toss == 1 && toss_choice == 2){
            cout << players_of_team_one[i] << ": " << bowler_runs_conceded[i] << " runs conceded in " << bowler_balls_bowled[bowler - 1] << " balls, has taken " << bowler_wickets_taken[bowler - 1] << " wickets and" << " has " << bowler_maiden_overs[i] << " maiden overs." << endl;}
            else if(toss == 2 && toss_choice == 1){
            cout << players_of_team_one[i] << ": " << bowler_runs_conceded[i] << " runs conceded in " << bowler_balls_bowled[bowler - 1] << " balls, has taken " << bowler_wickets_taken[bowler - 1] << " wickets and" << " has " << bowler_maiden_overs[i] << " maiden overs." << endl;}
            else{
            cout << players_of_team_two[i] << ": " << bowler_runs_conceded[i] << " runs conceded in " << bowler_balls_bowled[bowler - 1] << " balls, has taken " << bowler_wickets_taken[bowler - 1] << " wickets and" << " has " << bowler_maiden_overs[i] << " maiden overs." << endl;}
        }

        if (over != overs) {
        	swap(opener, nonstriker);
            cout << "Select the next bowler from the following players: " << endl;
            
            for (int i = 0; i < team_size; i++) {
            	if(toss == 1 && toss_choice == 1){
                cout << (i + 1) << ". " << players_of_team_two[i] << endl;}
                else if(toss == 1 && toss_choice == 2){
                cout << (i + 1) << ". " << players_of_team_one[i] << endl;}
                else if(toss == 2 && toss_choice == 1){
                cout << (i + 1) << ". " << players_of_team_one[i] << endl;}
                else{
                cout << (i + 1) << ". " << players_of_team_two[i] << endl;}
            }

            while (true) {
                cout << "Enter the number of the next bowler: ";
                cin >> bowler;

                if (bowler >= 1 && bowler <= team_size) {
                    break;
                } else {
                    cout << "Invalid input. Please enter a number between 1 and " << team_size << "." << endl;
                }
            }
        }

        if (wickets == (team_size - 1)) 
            break;  
    }
    cout << "Innings over. Final Score: " << score << "/" << wickets << " (Extras: " << extras << ")" << "(Run Rate: " << run_rate << ")" << endl;
    cout << "\n---------- Batting Card ----------" << endl;
    for (int i = 0; i < team_size; i++) {
        double strike_rate = (batsman_balls[i] > 0) 
                             ? (static_cast<double>(batsman_scores[i]) / batsman_balls[i]) * 100 
                             : 0.0; 
        if(toss == 1 && toss_choice == 1){                  
        cout << players_of_team_one[i] << ": "
             << batsman_scores[i] << " (" << batsman_balls[i] << " balls)";}
        if(toss == 1 && toss_choice == 2){                  
        cout << players_of_team_two[i] << ": "
             << batsman_scores[i] << " (" << batsman_balls[i] << " balls)";}
        if(toss == 2 && toss_choice == 1){                  
        cout << players_of_team_two[i] << ": "
             << batsman_scores[i] << " (" << batsman_balls[i] << " balls)";}
        if(toss == 2 && toss_choice == 2){                  
        cout << players_of_team_one[i] << ": "
             << batsman_scores[i] << " (" << batsman_balls[i] << " balls)";}
        if (i == opener - 1 || i == nonstriker - 1) {
            cout << " *"; 
        }
        cout << " (Strike Rate: " << strike_rate << ")" << endl;
    }

    cout << "\n---------- Bowling Card ----------" << endl;

for (int i = 0; i < team_size; i++) {
    double economy = (bowler_balls_bowled[i] > 0) ? 
                     (static_cast<double>(bowler_runs_conceded[i]) / (bowler_balls_bowled[i] / 6.0)) : 0.0;

    int overs_bowled = bowler_balls_bowled[i] / 6;
    int balls_bowled = bowler_balls_bowled[i] % 6;

    if (toss == 1 && toss_choice == 1) {                  
        cout << players_of_team_two[i] << ": " 
             << bowler_runs_conceded[i] << " runs in " 
             << overs_bowled << "." << balls_bowled << " overs "
             << "(Economy: " << economy << ", Maiden overs: " << bowler_maiden_overs[i] 
             << ", Wickets: " << bowler_wickets_taken[i] << ")\n";
    }
    if (toss == 1 && toss_choice == 2) {                  
        cout << players_of_team_one[i] << ": " 
             << bowler_runs_conceded[i] << " runs in " 
             << overs_bowled << "." << balls_bowled << " overs "
             << "(Economy: " << economy << ", Maiden overs: " << bowler_maiden_overs[i] 
             << ", Wickets: " << bowler_wickets_taken[i] << ")\n";
    }
    if (toss == 2 && toss_choice == 1) {                  
        cout << players_of_team_one[i] << ": " 
             << bowler_runs_conceded[i] << " runs in " 
             << overs_bowled << "." << balls_bowled << " overs "
             << "(Economy: " << economy << ", Maiden overs: " << bowler_maiden_overs[i] 
             << ", Wickets: " << bowler_wickets_taken[i] << ")\n";
    }
    if (toss == 2 && toss_choice == 2) {                  
        cout << players_of_team_two[i] << ": " 
             << bowler_runs_conceded[i] << " runs in " 
             << overs_bowled << "." << balls_bowled << " overs "
             << "(Economy: " << economy << ", Maiden overs: " << bowler_maiden_overs[i] 
             << ", Wickets: " << bowler_wickets_taken[i] << ")\n";
    }
}
	
    
bool match_won = false;
int target = score + 1;
int chasing_team_score = 0, chasing_team_wickets = 0, chasing_team_extras = 0;
int chasing_batsman_scores[team_size] = {0};
int chasing_batsman_balls[team_size] = {0};
int chasing_bowler_runs_conceded[team_size] = {0};
int chasing_bowler_balls_bowled[team_size] = {0};
int chasing_bowler_wickets_taken[team_size] = {0};
int chasing_bowler_maiden_overs[team_size] = {0};
int runs_scored_in_over;

cout << endl << "---------- Second Innings: Target is " << target << " ----------" << endl;

total_balls_bowled = 0;
free_hit = false;

string* batting_team = (toss == 1 && toss_choice == 1) || (toss == 2 && toss_choice == 2) ? players_of_team_two : players_of_team_one;
string* bowling_team = (batting_team == players_of_team_two) ? players_of_team_one : players_of_team_two;
string batting_team_name = (batting_team == players_of_team_two) ? team_name[1] : team_name[0];
string bowling_team_name = (batting_team == players_of_team_two) ? team_name[0] : team_name[1];

cout << "Select two batsmen from the following players:" << endl;
for (int i = 0; i < team_size; i++) {
    cout << (i + 1) << ". " << batting_team[i] << endl;
}
cout << "Select the Opening batsman of " << batting_team_name << " by number: ";
cin >> opener;
cout << "Select the Non-Striker batsman of " << batting_team_name << " by number: ";
cin >> nonstriker;

cout << "Select the bowler from the following players: " << endl;
for (int i = 0; i < team_size; i++) {
    cout << (i + 1) << ". " << bowling_team[i] << endl;
}
cout << "Select the bowler from " << bowling_team_name << " by number: ";
cin >> bowler;

for (int over = 1; over <= overs; over++) {
    cout << "Over " << over << " begins:" << endl;

    for (int ball = 1; ball <= 6; ball++) {
        if (chasing_team_wickets == (team_size - 1)) {
            cout << "All players are out! Innings over." << endl;
            break;
        }

        int balls_left = (overs * 6) - total_balls_bowled;
        int runs_to_win = target - chasing_team_score;
        
        cout << "Target: " << target << ", Runs to Win: " << runs_to_win << ", Balls Left: " << balls_left << endl;

        cout << "Ball " << ball << ": Enter what happened (0 = Dot ball, 1 = 1 run, 2 = 2 runs, 3 = 3 runs, 4 = Four, 6 = Six, 7 = Wicket, 8 = No Ball, 9 = Wide): ";
        int event;
        cin >> event;

        total_balls_bowled++;
        switch (event) {
            case 0:
                cout << "Dot ball!" << endl;
                chasing_batsman_balls[opener - 1]++;
                chasing_bowler_balls_bowled[bowler - 1]++;
                break;
            case 1:
                chasing_team_score += 1;
                chasing_batsman_scores[opener - 1]++;
                chasing_batsman_balls[opener - 1]++;
                chasing_bowler_runs_conceded[bowler - 1]++;
                chasing_bowler_balls_bowled[bowler - 1]++;
                cout << "1 run scored." << endl;
                runs_scored_in_over += 1;
                swap(opener, nonstriker);
                break;
            case 2:
                chasing_team_score += 2;
                chasing_batsman_scores[opener - 1] += 2;
                chasing_batsman_balls[opener - 1]++;
                chasing_bowler_runs_conceded[bowler - 1] += 2;
                chasing_bowler_balls_bowled[bowler - 1]++;
                cout << "2 runs scored." << endl;
                runs_scored_in_over += 2;
                break;
            case 3:
                chasing_team_score += 3;
                chasing_batsman_scores[opener - 1] += 3;
                chasing_batsman_balls[opener - 1]++;
                chasing_bowler_runs_conceded[bowler - 1] += 3;
                chasing_bowler_balls_bowled[bowler - 1]++;
                cout << "3 runs scored." << endl;
                runs_scored_in_over += 3;
                swap(opener, nonstriker); 
                break;
            case 4:
                chasing_team_score += 4;
                chasing_batsman_scores[opener - 1] += 4;
                chasing_batsman_balls[opener - 1]++;
                chasing_bowler_runs_conceded[bowler - 1] += 4;
                chasing_bowler_balls_bowled[bowler - 1]++;
                runs_scored_in_over += 4;
                cout << "It's a Four!" << endl;
                break;
            case 6:
                chasing_team_score += 6;
                chasing_batsman_scores[opener - 1] += 6;
                chasing_batsman_balls[opener - 1]++;
                chasing_bowler_runs_conceded[bowler - 1] += 6;
                chasing_bowler_balls_bowled[bowler - 1]++;
                runs_scored_in_over += 6;
                cout << "It's a Six!" << endl;
                break;
            case 7:
                if (free_hit) {
                    cout << "It's a Free Hit! Wickets can't fall on a Free Hit." << endl;
                } else {
                    chasing_team_wickets++;
                    cout << "Wicket! " << chasing_team_wickets << " out." << endl;
                    chasing_bowler_balls_bowled[bowler - 1]++;
                    chasing_bowler_wickets_taken[bowler - 1]++; 
                    opener = nonstriker; 
                }
                break;
            case 8:
                chasing_team_score += 1;
                chasing_team_extras += 1;
                chasing_bowler_runs_conceded[bowler - 1]++;
                cout << "No Ball! 1 extra run awarded." << endl;
                cout << "Next ball is a Free Hit!" << endl;
                free_hit = true;
                runs_scored_in_over += 1;
                ball--;
                break;
            case 9:
                chasing_team_score += 1;
                chasing_team_extras += 1;
                chasing_bowler_runs_conceded[bowler - 1]++;
                runs_scored_in_over += 1;
                cout << "Wide ball! 1 extra run awarded." << endl;
                ball--;
                break;
            default:
                cout << "Invalid input. Please enter a valid event." << endl;
                ball--;
                break;
        }


        if (chasing_team_score >= target) {
            cout << "\n---------- " << batting_team_name << " has won the match! ----------" << endl;
            match_won = true;
            break;
        }

        if (free_hit && event != 8 && event != 9) {
            free_hit = false;
        }

        double total_runs = chasing_team_score + chasing_team_extras;
        double run_rate = total_runs / (total_balls_bowled / 6.0);

        cout << "Current Score: " << chasing_team_score << "/" << chasing_team_wickets << " (Extras: " << chasing_team_extras << ") (Run Rate: " << run_rate << ")" << endl;
        cout << "Batsman " << batting_team[opener - 1] << ": " << chasing_batsman_scores[opener - 1] << " (" << chasing_batsman_balls[opener - 1] << " balls)" << endl;
        cout << "Bowler " << bowling_team[bowler - 1] << ": " << chasing_bowler_runs_conceded[bowler - 1] << " runs conceded in " << chasing_bowler_balls_bowled[bowler - 1] << " balls." << endl;
    }

    if (match_won) break;
    
    if (runs_scored_in_over == 0){
    	chasing_bowler_maiden_overs[bowler - 1]++;
	}
    
    if (over != overs) {
    cout << "Over " << over << " completed. Bowler stats:" << endl;
    for (int i = 0; i < team_size; i++) {
        double economy = (chasing_bowler_balls_bowled[i] > 0) 
                         ? (static_cast<double>(chasing_bowler_runs_conceded[i]) / (chasing_bowler_balls_bowled[i] / 6.0)) 
                         : 0.0;

        int overs_bowled = chasing_bowler_balls_bowled[i] / 6;
        int balls_bowled = chasing_bowler_balls_bowled[i] % 6;

        cout << bowling_team[i] << ": " 
             << chasing_bowler_runs_conceded[i] << " runs in " 
             << overs_bowled << "." << balls_bowled << " overs "
             << "(Economy: " << economy << ", Maiden overs: " << chasing_bowler_maiden_overs[i] 
             << ", Wickets: " << chasing_bowler_wickets_taken[i] << ")" << endl;
    }

}
    if (chasing_team_score < target && over != overs) {
        swap(opener, nonstriker);
        cout << "Select the next bowler from the following players: " << endl;
        for (int i = 0; i < team_size; i++) {
            cout << (i + 1) << ". " << bowling_team[i] << endl;
        }
        while (true) {
            cout << "Enter the number of the next bowler: ";
            cin >> bowler;
            if (bowler >= 1 && bowler <= team_size) {
                break;
            } else {
                cout << "Invalid input. Please enter a number between 1 and " << team_size << "." << endl;
            }
        }
    }
}


if (!match_won && chasing_team_score == score) {
    cout << "\n---------- Scores are level and It's a tie ----------" << endl;
}
else if (!match_won && chasing_team_score < target) {
    cout << "\n---------- " << bowling_team_name << " has won the match! ----------" << endl;
}


cout << "\n---------- Batting Card ----------" << endl;
for (int i = 0; i < team_size; i++) {
    double strike_rate = (chasing_batsman_balls[i] > 0)
                         ? (static_cast<double>(chasing_batsman_scores[i]) / chasing_batsman_balls[i]) * 100
                         : 0.0;
    cout << batting_team[i] << ": "
         << chasing_batsman_scores[i] << " (" << chasing_batsman_balls[i] << " balls)";
    if (i == opener - 1 || i == nonstriker - 1) {
        cout << " *";
    }
    cout << " (Strike Rate: " << strike_rate << ")" << endl;
}

cout << "\n---------- Bowling Card ----------" << endl;
for (int i = 0; i < team_size; i++) {
    double economy = (chasing_bowler_balls_bowled[i] > 0)
                     ? (static_cast<double>(chasing_bowler_runs_conceded[i]) / (chasing_bowler_balls_bowled[i] / 6.0))
                     : 0.0;

    cout << bowling_team[i] << ": " 
         << chasing_bowler_runs_conceded[i] << " runs in "
         << (chasing_bowler_balls_bowled[i] / 6) << "." 
         << (chasing_bowler_balls_bowled[i] % 6) << " overs "
         << "(Economy: " << economy << ", Maiden overs: " << chasing_bowler_maiden_overs[i]
         << ", Wickets: " << chasing_bowler_wickets_taken[i] << ")" << endl;
}

cout << "\n---------- Match Summary ----------" << endl;

string* second_innings_batting_team = (toss == 1 && toss_choice == 1) || (toss == 2 && toss_choice == 2) ? players_of_team_two : players_of_team_one;
string* second_innings_bowling_team = (second_innings_batting_team == players_of_team_two) ? players_of_team_one : players_of_team_two;

int top_batsman_index = 0;
int top_batsman_score = chasing_batsman_scores[0]; 
for (int i = 1; i < team_size; i++) {
    if (chasing_batsman_scores[i] > top_batsman_score) {
        top_batsman_score = chasing_batsman_scores[i];
        top_batsman_index = i;
    }
}
cout << "Top Batsman: " << second_innings_batting_team[top_batsman_index]
     << " - " << top_batsman_score << " runs (" 
     << chasing_batsman_balls[top_batsman_index] << " balls)" << endl;

int top_bowler_index = -1;
double best_economy = -1.0;

for (int i = 0; i < team_size; i++) {
    double economy_second_innings = (chasing_bowler_balls_bowled[i] > 0) 
        ? (static_cast<double>(chasing_bowler_runs_conceded[i]) / (chasing_bowler_balls_bowled[i] / 6.0)) 
        : 0.0;

    if (top_bowler_index == -1 || economy_second_innings < best_economy) {
        best_economy = economy_second_innings;
        top_bowler_index = i;
    }
}

if (top_bowler_index != -1) {
    cout << "Top Bowler: " << second_innings_bowling_team[top_bowler_index] 
         << " - " << chasing_bowler_runs_conceded[top_bowler_index] << " runs in " 
         << (chasing_bowler_balls_bowled[top_bowler_index] / 6) << "." 
         << (chasing_bowler_balls_bowled[top_bowler_index] % 6) << " overs (Economy: "
         << best_economy << ")" << endl;
} else {
    cout << "No valid bowler performance to display!" << endl;
}

int man_of_the_match_index = -1;
double max_performance = -1.0;

for (int i = 0; i < team_size; i++) {
    int batsman_performance = batsman_scores[i];

    double bowler_performance = 0.0;
    if (bowler_balls_bowled[i] > 0) {
        bowler_performance += (static_cast<double>(bowler_runs_conceded[i]) / (bowler_balls_bowled[i] / 6.0));
    }

    double total_performance = batsman_performance - bowler_performance;
    if (total_performance > max_performance) {
        max_performance = total_performance;
        man_of_the_match_index = i;
    }
}

if (man_of_the_match_index != -1) {
    cout << "Man of the Match: " << second_innings_batting_team[man_of_the_match_index] 
         << " with " << (batsman_scores[man_of_the_match_index]) 
         << " runs and " 
         << (bowler_runs_conceded[man_of_the_match_index]) << " runs conceded in " 
         << (bowler_balls_bowled[man_of_the_match_index] / 6) << "." 
         << (bowler_balls_bowled[man_of_the_match_index] % 6) << " overs." << endl;
} else {
    cout << "Man of the Match not determined!" << endl;
}

cout << "\nFinal Scores:\n";
if(toss == 1 && toss_choice == 1){
cout << team_name[0] << ": " << score << "/" << wickets << endl;
cout << team_name[1] << ": " << chasing_team_score << "/" << chasing_team_wickets << endl;}
else if(toss == 1 && toss_choice == 2){
cout << team_name[1] << ": " << score << "/" << wickets << endl;
cout << team_name[0] << ": " << chasing_team_score << "/" << chasing_team_wickets << endl;}
else if(toss == 2 && toss_choice == 1){
cout << team_name[1] << ": " << score << "/" << wickets << endl;
cout << team_name[0] << ": " << chasing_team_score << "/" << chasing_team_wickets << endl;}
else if(toss == 2 && toss_choice == 2){
cout << team_name[0] << ": " << score << "/" << wickets << endl;
cout << team_name[1] << ": " << chasing_team_score << "/" << chasing_team_wickets << endl;}

if (chasing_team_score == score) {
    cout << "\nThe match is tied! Both teams scored " << score << " runs." << endl;
} else if (chasing_team_score >= target) {
    if(toss == 1 && toss_choice == 1) {
        cout << "\n" << team_name[1] << " won the match by " << (team_size - chasing_team_wickets - 1)
         << " wickets!" << endl;
    } else if(toss == 1 && toss_choice == 2) {
        cout << "\n" << team_name[0] << " won the match by " << (team_size - chasing_team_wickets - 1)
         << " wickets!" << endl;
    } else if(toss == 2 && toss_choice == 1) {
        cout << "\n" << team_name[0] << " won the match by " << (team_size - chasing_team_wickets - 1)
         << " wickets!" << endl;
    } else if(toss == 2 && toss_choice == 2) {
        cout << "\n" << team_name[1] << " won the match by " << (team_size - chasing_team_wickets - 1)
         << " wickets!" << endl;
    }
} else if (chasing_team_score < target) {
    if(toss == 1 && toss_choice == 1) {
        cout << "\n" << team_name[0] << " won the match by " << (target - chasing_team_score - 1)
         << " runs!" << endl;
    } else if(toss == 1 && toss_choice == 2) {
        cout << "\n" << team_name[1] << " won the match by " << (target - chasing_team_score - 1)
         << " runs!" << endl;
    } else if(toss == 2 && toss_choice == 1) {
        cout << "\n" << team_name[1] << " won the match by " << (target - chasing_team_score - 1)
         << " runs!" << endl;
    } else if(toss == 2 && toss_choice == 2) {
        cout << "\n" << team_name[0] << " won the match by " << (target - chasing_team_score - 1)
         << " runs!" << endl;
    }
}

ofstream match_summary("matchsummary.txt");
if (match_summary.is_open()) {

match_summary << "\n---------- Match Summary ----------" << endl;

string* second_innings_batting_team = (toss == 1 && toss_choice == 1) || (toss == 2 && toss_choice == 2) ? players_of_team_two : players_of_team_one;
string* second_innings_bowling_team = (second_innings_batting_team == players_of_team_two) ? players_of_team_one : players_of_team_two;

int top_batsman_index = 0;
int top_batsman_score = chasing_batsman_scores[0]; 
for (int i = 1; i < team_size; i++) {
    if (chasing_batsman_scores[i] > top_batsman_score) {
        top_batsman_score = chasing_batsman_scores[i];
        top_batsman_index = i;
    }
}
match_summary << "Top Batsman: " << second_innings_batting_team[top_batsman_index]
     << " - " << top_batsman_score << " runs (" 
     << chasing_batsman_balls[top_batsman_index] << " balls)" << endl;

int top_bowler_index = -1;
double best_economy = -1.0;

for (int i = 0; i < team_size; i++) {
    double economy_second_innings = (chasing_bowler_balls_bowled[i] > 0) 
        ? (static_cast<double>(chasing_bowler_runs_conceded[i]) / (chasing_bowler_balls_bowled[i] / 6.0)) 
        : 0.0;

    if (top_bowler_index == -1 || economy_second_innings < best_economy) {
        best_economy = economy_second_innings;
        top_bowler_index = i;
    }
}

if (top_bowler_index != -1) {
    match_summary << "Top Bowler: " << second_innings_bowling_team[top_bowler_index] 
         << " - " << chasing_bowler_runs_conceded[top_bowler_index] << " runs in " 
         << (chasing_bowler_balls_bowled[top_bowler_index] / 6) << "." 
         << (chasing_bowler_balls_bowled[top_bowler_index] % 6) << " overs (Economy: "
         << best_economy << ")" << endl;
} else {
    cout << "No valid bowler performance to display!" << endl;
}

int man_of_the_match_index = -1;
double max_performance = -1.0;

for (int i = 0; i < team_size; i++) {
    int batsman_performance = batsman_scores[i]; 

    double bowler_performance = 0.0;
    if (bowler_balls_bowled[i] > 0) {
        bowler_performance += (static_cast<double>(bowler_runs_conceded[i]) / (bowler_balls_bowled[i] / 6.0));
    }

    double total_performance = batsman_performance - bowler_performance;
    if (total_performance > max_performance) {
        max_performance = total_performance;
        man_of_the_match_index = i;
    }
}

if (man_of_the_match_index != -1) {
    match_summary << "Man of the Match: " << second_innings_batting_team[man_of_the_match_index] 
         << " with " << (batsman_scores[man_of_the_match_index]) 
         << " runs and " 
         << (bowler_runs_conceded[man_of_the_match_index]) << " runs conceded in " 
         << (bowler_balls_bowled[man_of_the_match_index] / 6) << "." 
         << (bowler_balls_bowled[man_of_the_match_index] % 6) << " overs." << endl;
} else {
    match_summary << "Man of the Match not determined!" << endl;
}


match_summary << "\nFinal Scores:\n";
if(toss == 1 && toss_choice == 1){
match_summary << team_name[0] << ": " << score << "/" << wickets << endl;
match_summary << team_name[1] << ": " << chasing_team_score << "/" << chasing_team_wickets << endl;}
else if(toss == 1 && toss_choice == 2){
match_summary << team_name[1] << ": " << score << "/" << wickets << endl;
match_summary << team_name[0] << ": " << chasing_team_score << "/" << chasing_team_wickets << endl;}
else if(toss == 2 && toss_choice == 1){
match_summary << team_name[1] << ": " << score << "/" << wickets << endl;
match_summary << team_name[0] << ": " << chasing_team_score << "/" << chasing_team_wickets << endl;}
else if(toss == 2 && toss_choice == 2){
match_summary << team_name[0] << ": " << score << "/" << wickets << endl;
match_summary << team_name[1] << ": " << chasing_team_score << "/" << chasing_team_wickets << endl;}
if (chasing_team_score == score) {
    match_summary << "\nThe match is tied! Both teams scored " << score << " runs." << endl;
} else if (chasing_team_score >= target) {
    if(toss == 1 && toss_choice == 1) {
        match_summary << "\n" << team_name[1] << " won the match by " << (team_size - chasing_team_wickets - 1)
         << " wickets!" << endl;
    } else if(toss == 1 && toss_choice == 2) {
        match_summary << "\n" << team_name[0] << " won the match by " << (team_size - chasing_team_wickets - 1)
         << " wickets!" << endl;
    } else if(toss == 2 && toss_choice == 1) {
        match_summary << "\n" << team_name[0] << " won the match by " << (team_size - chasing_team_wickets - 1)
         << " wickets!" << endl;
    } else if(toss == 2 && toss_choice == 2) {
        match_summary << "\n" << team_name[1] << " won the match by " << (team_size - chasing_team_wickets - 1)
         << " wickets!" << endl;
    }
} else if (chasing_team_score < target) {
    if(toss == 1 && toss_choice == 1) {
        match_summary << "\n" << team_name[0] << " won the match by " << (target - chasing_team_score - 1)
         << " runs!" << endl;
    } else if(toss == 1 && toss_choice == 2) {
        match_summary << "\n" << team_name[1] << " won the match by " << (target - chasing_team_score - 1)
         << " runs!" << endl;
    } else if(toss == 2 && toss_choice == 1) {
        match_summary << "\n" << team_name[1] << " won the match by " << (target - chasing_team_score - 1)
         << " runs!" << endl;
    } else if(toss == 2 && toss_choice == 2) {
        match_summary << "\n" << team_name[0] << " won the match by " << (target - chasing_team_score - 1)
         << " runs!" << endl;
    }
}

cout << "Match summary saved to matchsummary.txt";
match_summary.close();
}
    }


int main() {
    team(); 
    return 0;
}

