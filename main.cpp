#include "Header.h"

int main() {
    // Setting Vietnamese, don't change
    SetConsoleOutputCP( CP_UTF8 );
    setvbuf( stdout, nullptr, _IONBF, 0 );
    MBuf buf;
    std::cout.rdbuf( &buf );
    // First Screen to Login
    system("cls");
    UITitle("Welcome to HCMUS Portal!");
    UIgrid_2_1_Long("1. Login", "2. Exit");    
    UILineLong();
    int input; UICin(input); // End Display
    system("cls"); LoginM* data = nullptr;
    if ((input == 1) && LoginMain(data)) // Check Login
    {
        system("cls");
        if (data->type=="staff") staffDbView(data); 
        else if (data->type=="student") 
        {
            // system("pause");
            studentDbView(data); }
        else return 0;
        // UILineLong();
        // UIgrid_3_1_Long("Username: " + data->LoginId,"id: " + data->id,"You are " + data->type);
        // cout << "id: " << data->id << endl;
        // cout << "You are " << data->type << endl;
    } else return 0;
    // End login, Id of user located in data variable, you can use it by data.LoginId
    // UILineLong();


    // for create subject.
    Node* head = NULL;
    // int input;
    char ch;
    CreateSubject(head);
    do
    {
        cout << "Enter your choice(1-2): ";
        cin >> input;
        maindashboard(input, head);
        cout << "Do u continue to change sth?(Y/N): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');

    ofstream Subject_file;
    ifstream score_file;
    score_file.open("Toan.txt", ios::in);
    Subject_file.open("Subject List.txt", ios::in);
    Display(head, Subject_file);

    Subject_file.close();



    system("pause");
    return 0;
}

void staffDbView(LoginM* data) {
    int input;
    Staff* CurS = new Staff;
    CurS->UserId = data->id;
    CurS->Username = data->LoginId;
    ifstream f;
    string temp;
    f.open("OverallData/staffData.txt");
    getline(f, temp, '\n');
    // f.ignore(256,'\n');
    while(getline(f, temp,',')) 
        if (temp == data->LoginId) 
        { getline(f, CurS->FullName, ','); break; }
        // cout << temp << flush << endl;
    f.close();
    DisplayNavStaff(CurS);
    UICin(input);
}

void studentDbView(LoginM* data) {
    int input;
    UICin(input);
}