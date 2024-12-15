#include<iostream>
#include<istream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<conio.h>
#include<fstream>
#include<windows.h>
using namespace std;
int main();
int AI = 0;
int cartp[10]={0,0,0,0,0,0,0,0,0,0};
string carti[10] = { "NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL" };
int WA[10],WAA;
int c1,bilc,cuorder;
int countcook;
int cho,rac,foo;

class login_register;
class customer;
class cook;

class admin
{
protected:
    /*int choice;*/
    string myText;
    string cook;
    string user;
public:

    void menu_selection()
    {
        ifstream MyReadFile("filename.txt");
        while (getline(MyReadFile, myText))
        {
            cout << myText << endl;
        }
        MyReadFile.close();

    }
    void deletecook()
    {
        string codl;
        cout << "ENTER COOK NAME TO DELETE:";
        cin >> cook;
        ofstream readcodl(cook + ".txt", ios::trunc);
        cout << "COOK DELETED!!!" << endl << endl;
            Sleep(2000);
            system("cls");
    }
        
    
    void deleteuser()
    {
        cout << "ENTER USER NAME TO DELETE:";
        cin >> user;
        ofstream readcudl(user + ".txt", ios::trunc);
        cout << "USER DELETED!!!" << endl << endl;
        Sleep(2000);
        system("cls");
    }
};
class login_register : public admin 
{
protected:  
public:

};
class customer : public login_register
{
protected:
    int countcu,wa;
    string usercu, passcu, ucu, pcu;
    string regusercu, regpasscu,wall_am;
public:
    friend class login_register;
   void registrcu();
   void logincu();
}; 
void customer::registrcu()
{
    
    system("cls");
    cout << "TO REGISTER AS COOK ENTER THE FOLLOWING DETAILS : " << endl << endl;;
    cout << "Enter the username :";
    cin >> regusercu;
    cout << "\nEnter the password :";
    cin >> regpasscu;
    cout << "\nEnter the wallet amount :";
    cin >> wall_am;
    string ea = ".txt";
    string va = regusercu + ea;
    ofstream reg(va, ios::app);
    reg << regusercu << ' ' << regpasscu << ' ' << wall_am << endl;
    system("cls");
    cout << "\nRegistration Sucessful\n";
    Sleep(1500);
    system("cls");
    main();
}
void customer::logincu()
{
    system("cls");
    cout << "PLEASE ENTER THE FOLLOWING DETAILS TO LOGIN AS A COOK :" << endl << endl;
    cout << "USERNAME :";
    cin >> usercu;
    cout << "PASSWORD :";
    char asc, as[10];
    int ascin = 0,c;
    string fpass;
    while(true)
    {
        ea:
        asc = _getch();
       
        cout << "*";
        as[ascin] = asc;
        if ((int)asc==13)
            break;
        fpass = as[ascin];
        for (int x = 0; x <= ascin; x++)
        {
            passcu += as[ascin];
            break;
        }
        ascin++;
    }
    string ee = ".txt";
    string vv = usercu + ee;
    ifstream input(vv);
    int a = 0;
    while (input >> ucu >> pcu >> wa)
    {
        if (ucu == usercu && pcu == passcu)
        {
            countcu = 1;
            WA[a] = wa;
            WAA=WA[a];
            system("cls");
        }
        a++;
    }
    input.close();
    if (countcu == 1)
    {
        cout <<"Success full login !!!"<<endl;
        cout << "Hello  " << usercu << endl;
        cout << "Total amount in your wallet is : "<<endl;
        cout << WAA;
    }
    else
    {
        cout << "\n\nLOGIN ERROR\n\nPlease check your username and password\n\n\n";
    }
    Sleep(3500);
    system("cls");
    main();
}
class cook : public login_register
{
protected:
    int countco;
    string userco, passco, uco, pco;
    string reguserco, regpassco;
    
public:
    friend class login_register;
    void registrco();
    void loginco();
    int fp = 1353;
    int ch;
    void del_res_menu(int x)
    {
        int ch;
        int yy;
        ch = x;
        
        while (ch < 21)
        {
            string s;
            ifstream dels("resli.txt");
            int lb = 0;
            dels.seekg((fp * ch), ios::beg);
            while (getline(dels, s))
            {
                cout << s << endl;
                lb++;
                if (lb == 12)
                    break;
            }
            dels.close();
            cout << endl << endl;
            break;
        }
    }
};
void cook::registrco()
{
    system("cls");
    cout << "TO REGISTER AS COOK ENTER THE FOLLOWING DETAILS : " << endl << endl;
    cout << "Enter the username :";
    cin >> reguserco;
    cout << "\nEnter the password :";
    cin >> regpassco;
    string ee = ".txt";
    string vv = reguserco + ee;
    ofstream reg(vv, ios::app);
    reg << reguserco << ' ' << regpassco << endl;
    system("cls");
    cout << "\nRegistration Sucessful\n";
    Sleep(1500);
    system("cls");
    main();
}
void cook::loginco()
{
    system("cls");
    cout << "PLEASE ENTER THE FOLLOWING DETAILS TO LOGIN AS A COOK :" <<endl <<endl;
    cout << "USERNAME :";
    cin >> userco;
    cout << "PASSWORD :";
    char asc, as[10];
    int ascin = 0, c;
    string fpass;
    while (true)
    {
    ea:
        asc = _getch();

        cout << "*";
        as[ascin] = asc;
        if ((int)asc == 13)
            break;
        fpass = as[ascin];
        for (int x = 0; x <= ascin; x++)
        {
            passco += as[ascin];
            break;
        }
        ascin++;
    }
    string ee = ".txt";
    string vv = userco + ee;
    ifstream input(vv);
    while (input >> uco >> pco)
    {
        if (uco == userco && pco == passco)
        {
            countco = 1;
            system("cls");
        }
    }
    input.close();
    if (countco == 1)
    {
        cout << "Success full login !!!" << endl;
        cout << "Hello  " << userco << endl;
    }
    else
    {
        cout << "\n\nLOGIN ERROR\n\nPlease check your username and password\n\n\n";
    }
    Sleep(3500);
    system("cls");
    main();
}

class food_resturant : public cook, public customer
{
protected:
    string lor,food_text;
   
public:
    int f_choice;
    void Resturants()
    {
        ifstream resturant("resli_2.txt");
        int nnn = 0;
        while (getline(resturant, lor))
        {
            cout << lor << endl;
            nnn++;
            if (nnn == 14)
                break;
        }
        resturant.close();
    }
    void Resturant_1()
    {
        ifstream resturant("resli_2.txt");
        int nnn = 0;
        while (getline(resturant, lor))
        {
            cout << lor << endl;
            nnn++;
            if (nnn == 11)
                break;
        }
        resturant.close();
    }
    //file handeled resturants menus 
    void pizzahut()  //1
    {
        string pizzaa;
        ifstream pizz("pizza.txt");
        int a = 0;
        while(getline(pizz,pizzaa))
        {
            a++;
            cout << pizzaa << endl;
            if (a == 23)
                break;
        }
        pizz.close();
    }
    void pizzahut_1()
    {
        string pizzaa;
        ifstream pizz("pizza.txt");
        int a = 1;
        pizz.seekg(1180, ios::beg);
        while (getline(pizz, pizzaa))
        {
            a++;
            cout << pizzaa << endl;
            if (a == 7)
                break;
        }
        pizz.close();
    }
    void Broadway()  //2
    {
        string broadwaya;
        ifstream broadw("BROADWAY.txt");
        int a = 0;
        while (getline(broadw, broadwaya))
        {
            a++;
            cout << broadwaya << endl;
            if (a == 23)
                break;
        }
        broadw.close();
    }
    void Broadway_1()
    {
        string broadwaya;
        ifstream broadw("BROADWAY.txt");
        int a = 1;
        broadw.seekg(1158, ios::beg);
        while (getline(broadw, broadwaya))
        {
            a++;
            cout << broadwaya << endl;
            if (a == 10)
                break;
        }
        broadw.close();
    }
    void cp5star() //3
    {
        string cpfstara;
        ifstream cpf("CP5STAR.txt");
        int a = 0;
        while (getline(cpf, cpfstara))
        {
            a++;
            cout << cpfstara << endl;
            if (a == 23)
                break;
        }
        cpf.close();
    }
    void Gjeans() //4
    {
        string gloriaj;
        ifstream gloriajeans("GLORIAJEANS.txt");
        int a = 0;
        while (getline(gloriajeans, gloriaj))
        {
            a++;
            cout << gloriaj << endl;
            if (a == 23)
                break;
        }
        gloriajeans.close();
    }
    void Gjeans_1() //4
    {
        string gloriaj;
        ifstream gloriajeans("GLORIAJEANS.txt");
        int a = 0;
        gloriajeans.seekg(1240, ios::beg);
        while (getline(gloriajeans, gloriaj))
        {
            a++;
            cout << gloriaj << endl;
            if (a == 10)
                break;
        }
        gloriajeans.close();
    }
    void Domenos() //5
    {
        string dom;
        ifstream domeno("DOMINO.txt");
        int a = 0;
        while (getline(domeno, dom))
        {
            a++;
            cout << dom << endl;
            if (a == 23)
                break;
        }
        domeno.close();
    }
    void jaybees() //6
    {
        string jaybe;
        ifstream jayb("JAYBEES.txt");
        int a = 0;
        while (getline(jayb, jaybe))
        {
            a++;
            cout << jaybe << endl;
            if (a == 23)
                break;
        }
        jayb.close();
    }
    void mc_donalds() //7
    {
        string mcdon;
        ifstream mcd("MC_DONALDS.txt");
        int a = 0;
        while (getline(mcd, mcdon))
        {
            a++;
            cout << mcdon << endl;
            if (a == 23)
                break;
        }
        mcd.close();
    }
    void Karachi_naseeb_baryani() //8
    {
        string knb;
        ifstream knB("KARACHI_NASEEB_BIRYANI.txt");
        int a = 0;
        while (getline(knB, knb))
        {
            a++;
            cout << knb << endl;
            if (a == 23)
                break;
        }
        knB.close();
    }
    void cocknbull()  //9
    {
        string cnb;
        ifstream CNB("COCK'N'BULL.txt");
        int a = 0;
        while (getline(CNB, cnb))
        {
            a++;
            cout << cnb << endl;
            if (a == 23)
                break;
        }
        CNB.close();
    }
    void karachi_red_rock()  //10
    {
        string Krr;
        ifstream kRR("KARACHI_RED_ROCK.txt");
        int a = 0;
        while (getline(kRR, Krr))
        {
            a++;
            cout << Krr << endl;
            if (a == 23)
                break;
        }
        kRR.close();
    }
    void Frichicks()  //11
    {
        string FC;
        ifstream fc("FRI_CHICKS.txt");
        int a = 0;
        while (getline(fc, FC))
        {
            a++;
            cout << FC << endl;
            if (a == 23)
                break;
        }
        fc.close();
    }
    void subway()  //12
    {
        string SUBW;
        ifstream subwa("SUBWAY.txt");
        int a = 0;
        while (getline(subwa, SUBW))
        {
            a++;
            cout << SUBW << endl;
            if (a == 23)
                break;
        }
        subwa.close();
    }
    void goga_naqeeba()  //13
    {
        string GONA;
        ifstream gona("GOGA_NAQEEBEA.txt");
        int a = 0;
        while (getline(gona, GONA))
        {
            a++;
            cout << GONA << endl;
            if (a == 23)
                break;
        }
        gona.close();
    }
    void master_baryani()  //14
    {
        string MB;
        ifstream mb("MASTER_BIRYANI.txt");
        int a = 0;
        while (getline(mb, MB))
        {
            a++;
            cout << MB << endl;
            if (a == 23)
                break;
        }
        mb.close();
    }
    void timmys()  //15
    {
        string TIM;
        ifstream tim("TIMMY'S.txt");
        int a = 0;
        while (getline(tim, TIM))
        {
            a++;
            cout << TIM << endl;
            if (a == 23)
                break;
        }
        tim.close();
    }
    void jhonny_cafe()  //16
    {
        string JC;
        ifstream jc("JHONNY'S_CAFE.txt");
        int a = 0;
        while (getline(jc, JC))
        {
            a++;
            cout << JC << endl;
            if (a == 23)
                break;
        }
        jc.close();
    }
    void sweeto()  //17
    {
        string sweto;
        ifstream SWETO("SWEETO.txt");
        int a = 0;
        while (getline(SWETO, sweto))
        {
            a++;
            cout << sweto << endl;
            if (a == 23)
                break;
        }
        SWETO.close();
    }
    void kims_family_resturant()  //18
    {
        string KFR;
        ifstream kfr("KIMS _FAMILY_RESTAURANT.txt");
        int a = 0;
        while (getline(kfr, KFR))
        {
            a++;
            cout << KFR << endl;
            if (a == 23)
                break;
        }
        kfr.close();
    }
    void chai_qawali()  //19
    {
        string CQ;
        ifstream cq("CHAI_QAWALI.txt");
        int a = 0;
        while (getline(cq, CQ))
        {
            a++;
            cout << CQ << endl;
            if (a == 23)
                break;
        }
        cq.close();
    }
    void burger_lab()  //20
    {
        string BL;
        ifstream bl("BURGER_LAB.txt");
        int a = 0;
        while (getline(bl, BL))
        {
            a++;
            cout << BL << endl;
            if (a == 23)
                break;
        }
        bl.close();
    }

    void food()  
    {   
    enter:
        cin >> f_choice;
        system("cls");
        if (f_choice == 1)
        {
           { pizzahut(); }
        }
        else if (f_choice == 2)
        {
           { Broadway(); }
        }
        else if (f_choice == 3)
        {
            { cp5star(); }
        }
        else if (f_choice == 4)
        {
            { Gjeans(); }
        }
        else if (f_choice == 5)
        {
           { Domenos(); }
        }
        else if (f_choice == 6)
        {
            { jaybees(); }
        }
        else if (f_choice == 7)
        {
            { mc_donalds(); }
        }
        else if (f_choice == 8)
        {
            { Karachi_naseeb_baryani(); }
        }
        else if (f_choice == 9)
        {
            { cocknbull(); }
        }
        else if (f_choice == 10)
        {
           { karachi_red_rock(); }
        }
        else if (f_choice == 11)
        {
            { Frichicks(); }
        }
        else if (f_choice == 12)
        {
            { subway(); }
        }
        else if (f_choice == 13)
        {
            { goga_naqeeba(); }
        }
        else if (f_choice == 14)
        {
        { master_baryani(); }
        }
        else if (f_choice == 15)
        {
          { timmys(); }
        }
        else if (f_choice == 16)
        {
            { jhonny_cafe(); }
        }
        else if (f_choice == 17)
        {
        { sweeto(); }
        }
        else if (f_choice == 18)
        {
            kims_family_resturant(); 
        }
        else if (f_choice == 19)
        {
            chai_qawali(); 
        }
        else if (f_choice == 20)
        {
           burger_lab(); 
        }
        else if (f_choice == 0)
        {
            system("cls");
            main();
        }
        else
        {
            system("cls");
            Resturants();
            goto enter;
        }      
    }   
};

class order:public food_resturant
{
protected:
    int o_chioce;
public:
    char xa;
    void order_food()
    {
        //f_choice means resturant selection
        //o_choice means you are seelecting otions in resturant menu ie' pizza hut has 8 options o_choice select one 
        nowa:
       food_resturant::food();
       a1:
       cin >> o_chioce;
       //pizza hut menu order selection *
       if (f_choice == 1)
       {
           if (o_chioce == 1)
           {
               if (foo == f_choice)
               {
                   cout << "Resturant has been deleted by the cook press 0 to go back in previous menu" << endl << endl;
               }
               else {
                   pizzahut_1();
                   int s;
               a:
                   cin >> s;
                   if (s == 1)
                   {
                       cartp[AI] = 300;
                       carti[AI] = "small chicken tikka";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else if (s == 2)
                   {
                       cartp[AI] = 600;
                       carti[AI] = "medium chicken tikka";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else if (s == 3)
                   {
                       cartp[AI] = 900;
                       carti[AI] = "large chicken tikka";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else
                   {
                       cout << "!!!!! INVALID OPTION ENETERED!!!!!" << endl;
                       cout << "ENTER THE SIZE : ";
                       goto a;
                   }
               }

           }
           else if (o_chioce == 2)
           {
               if (foo == f_choice)
               {
                   cout << "Resturant has been deleted by the cook press 0 to go back in previous menu " << endl << endl;
               }
               else {
                   pizzahut_1();
                   int s;
               b:
                   cin >> s;
                   if (s == 1)
                   {
                       cartp[AI] = 320;
                       carti[AI] = "small chicken fajita";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else if (s == 2)
                   {
                       cartp[AI] = 650;
                       carti[AI] = "medium chicken fajita";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else if (s == 3)
                   {
                       cartp[AI] = 980;
                       carti[AI] = "large chicken fajita";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else
                   {
                       cout << "!!!!! INVALID OPTION ENETERED!!!!!" << endl;
                       cout << "ENTER THE SIZE : ";
                       goto b;
                   }
               }
           }
           else if (o_chioce == 3)
           {
               if (foo == f_choice)
               {
                   cout << "Resturant has been deleted by the cook press 0 to go back in previous menu" << endl << endl;
               }
               else {
                   pizzahut_1();
                   int s;
               c:
                   cin >> s;
                   if (s == 1)
                   {
                       cartp[AI] = 400;
                       carti[AI] = "small chicken manchurian";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else if (s == 2)
                   {
                       cartp[AI] = 700;
                       carti[AI] = "medium chicken manchurian";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else if (s == 3)
                   {
                       cartp[AI] = 1050;
                       carti[AI] = "large chicken manchurian";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else
                   {
                       cout << "!!!!! INVALID OPTION ENETERED!!!!!" << endl;
                       cout << "ENTER THE SIZE : ";
                       goto c;
                   }
               }
           }
           else if (o_chioce == 4)
           {
               if (foo == f_choice)
               {
                   cout << "Resturant has been deleted by the cook press 0 to go back in previous menu" << endl << endl;
               }
               else {
                   pizzahut_1();
                   int s;
               d:
                   cin >> s;
                   if (s == 1)
                   {
                       cartp[AI] = 380;
                       carti[AI] = "small chicken mix";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else if (s == 2)
                   {
                       cartp[AI] = 670;
                       carti[AI] = "medium chicken mix";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else if (s == 3)
                   {
                       cartp[AI] = 965;
                       carti[AI] = "large chicken mix";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else
                   {
                       cout << "!!!!! INVALID OPTION ENETERED!!!!!" << endl;
                       cout << "ENTER THE SIZE : ";
                       goto d;
                   }
               }
           }
           else if (o_chioce == 5)
           {
               if (foo == f_choice)
               {
                   cout << "Resturant has been deleted by the cook press 0 to go back in previous menu" << endl << endl;
               }
               else {
                   pizzahut_1();
                   int s;
               e:
                   cin >> s;
                   if (s == 1)
                   {
                       cartp[AI] = 290;
                       carti[AI] = "small vegitable mix";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else if (s == 2)
                   {
                       cartp[AI] = 590;
                       carti[AI] = "medium vegitable mix";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else if (s == 3)
                   {
                       cartp[AI] = 890;
                       carti[AI] = "large vegitable mix";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else
                   {
                       cout << "!!!!! INVALID OPTION ENETERED!!!!!" << endl;
                       cout << "ENTER THE SIZE : ";
                       goto e;
                   }
               }
           }
           else if (o_chioce == 6)
           {
               if (foo == f_choice)
               {
                   cout << "Resturant has been deleted by the cook press 0 to go back in previous menu" << endl << endl;
               }
               else {
                   pizzahut_1();
                   int s;
               f:
                   cin >> s;
                   if (s == 1)
                   {
                       cartp[AI] = 330;
                       carti[AI] = "small cheese filled";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else if (s == 2)
                   {
                       cartp[AI] = 640;
                       carti[AI] = "medium cheese filled";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else if (s == 3)
                   {
                       cartp[AI] = 940;
                       carti[AI] = "large cheese filled";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else
                   {
                       cout << "!!!!! INVALID OPTION ENETERED!!!!!" << endl;
                       cout << "ENTER THE SIZE : ";
                       goto f;
                   }
               }
           }
           else if (o_chioce == 7)
           {
               if (foo == f_choice)
               {
                   cout << "Resturant has been deleted by the cook press 0 to go back in previous menu" << endl << endl;
               }
               else {
                   pizzahut_1();
                   int s;
               g:
                   cin >> s;
                   if (s == 1)
                   {
                       cartp[AI] = 365;
                       carti[AI] = "small creamy melt";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else if (s == 2)
                   {
                       cartp[AI] = 680;
                       carti[AI] = "medium creamy melt";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else if (s == 3)
                   {
                       cartp[AI] = 975;
                       carti[AI] = "large creamy melt";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else
                   {
                       cout << "!!!!! INVALID OPTION ENETERED!!!!!" << endl;
                       cout << "ENTER THE SIZE : ";
                       goto g;
                   }
               }
           }
           else if (o_chioce == 0)
           {
               system("cls");
               if (rac == 1)
               {
                   del_res_menu(cho);
                   goto nowa;
               }
               Resturants();
               goto nowa;
           }
           else
           {
               system("cls");
               pizzahut();
               goto a1;
           }


       }
       //Broadway menu order selection *
       else if (f_choice == 2)
       {
           if (o_chioce == 1)
           {
               if (foo == f_choice)
               {
                   cout << "Resturant has been deleted by the cook press 0 to go back in previous menu" << endl << endl;
               }
               else {
                   Broadway_1();
                   int s;
               aa:
                   cin >> s;
                   if (s == 1)
                   {
                       cartp[AI] = 550;
                       carti[AI] = "small flatbread";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else if (s == 2)
                   {
                       cartp[AI] = 850;
                       carti[AI] = "medium flatbread";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else if (s == 3)
                   {
                       cartp[AI] = 1050;
                       carti[AI] = "large flatbread";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else
                   {
                       cout << "!!!!! INVALID OPTION ENETERED!!!!!" << endl;
                       cout << "ENTER THE SIZE : ";
                       goto aa;
                   }
               }
           }
           else if (o_chioce == 2)
           {
               if (foo == f_choice)
               {
                   cout << "Resturant has been deleted by the cook press 0 to go back in previous menu" << endl << endl;
               }
               else {
                   Broadway_1();
                   int s;
               ba:
                   cin >> s;
                   if (s == 1)
                   {
                       cartp[AI] = 450;
                       carti[AI] = "small appetizer";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else if (s == 2)
                   {
                       cartp[AI] = 650;
                       carti[AI] = "medium appetizer";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else if (s == 3)
                   {
                       cartp[AI] = 850;
                       carti[AI] = "large appetizer";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else
                   {
                       cout << "!!!!! INVALID OPTION ENETERED!!!!!" << endl;
                       cout << "ENTER THE SIZE : ";
                       goto ba;
                   }
               }
           }
           else if (o_chioce == 3)
           {
               if (foo == f_choice)
               {
                   cout << "Resturant has been deleted by the cook press 0 to go back in previous menu" << endl << endl;
               }
               else {
                   Broadway_1();
                   int s;
               ca:
                   cin >> s;
                   if (s == 1)
                   {
                       cartp[AI] = 450;
                       carti[AI] = "small bucati";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else if (s == 2)
                   {
                       cartp[AI] = 650;
                       carti[AI] = "medium bucati";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else if (s == 3)
                   {
                       cartp[AI] = 850;
                       carti[AI] = "large bucati";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else
                   {
                       cout << "!!!!! INVALID OPTION ENETERED!!!!!" << endl;
                       cout << "ENTER THE SIZE : ";
                       goto ca;
                   }
               }
           }
           else if (o_chioce == 4)
           {
               if (foo == f_choice)
               {
                   cout << "Resturant has been deleted by the cook press 0 to go back in previous menu" << endl << endl;
               }
               else {
                   Broadway_1();
                   int s;
               da:
                   cin >> s;
                   if (s == 1)
                   {
                       cartp[AI] = 500;
                       carti[AI] = "small fajita";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else if (s == 2)
                   {
                       cartp[AI] = 600;
                       carti[AI] = "medium fajita";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else if (s == 3)
                   {
                       cartp[AI] = 700;
                       carti[AI] = "large fajita";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else
                   {
                       cout << "!!!!! INVALID OPTION ENETERED!!!!!" << endl;
                       cout << "ENTER THE SIZE : ";
                       goto da;
                   }
               }
           }
           else if (o_chioce == 5)
           {
               if (foo == f_choice)
               {
                   cout << "Resturant has been deleted by the cook press 0 to go back in previous menu" << endl << endl;
               }
               else {
                   Broadway_1();
                   int s;
               ea:
                   cin >> s;
                   if (s == 1)
                   {
                       cartp[AI] = 450;
                       carti[AI] = "small tikka";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else if (s == 2)
                   {
                       cartp[AI] = 600;
                       carti[AI] = "medium tikka";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else if (s == 3)
                   {
                       cartp[AI] = 750;
                       carti[AI] = "large tikka";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else
                   {
                       cout << "!!!!! INVALID OPTION ENETERED!!!!!" << endl;
                       cout << "ENTER THE SIZE : ";
                       goto ea;
                   }
               }
           }
           else if (o_chioce == 6)
           {
               if (foo == f_choice)
               {
                   cout << "Resturant has been deleted by the cook press 0 to go back in previous menu" << endl << endl;
               }
               else {
                   Broadway_1();
                   int s;
               fa:
                   cin >> s;
                   if (s == 1)
                   {
                       cartp[AI] = 650;
                       carti[AI] = "small broadway special";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else if (s == 2)
                   {
                       cartp[AI] = 850;
                       carti[AI] = "medium broadway special";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else if (s == 3)
                   {
                       cartp[AI] = 1150;
                       carti[AI] = "large broadway special";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else
                   {
                       cout << "!!!!! INVALID OPTION ENETERED!!!!!" << endl;
                       cout << "ENTER THE SIZE : ";
                       goto fa;
                   }
               }
           }
           else if (o_chioce == 7)
           {
               if (foo == f_choice)
               {
                   cout << "Resturant has been deleted by the cook press 0 to go back in previous menu" << endl << endl;
               }
               else {
                   Broadway_1();
                   int s;
               ga:
                   cin >> s;
                   if (s == 1)
                   {
                       cartp[AI] = 450;
                       carti[AI] = "small sicilian";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else if (s == 2)
                   {
                       cartp[AI] = 550;
                       carti[AI] = "medium sicilian";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else if (s == 3)
                   {
                       cartp[AI] = 750;
                       carti[AI] = "large sicilian";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else
                   {
                       cout << "!!!!! INVALID OPTION ENETERED!!!!!" << endl;
                       cout << "ENTER THE SIZE : ";
                       goto ga;

                   }
               }
           }
           else if (o_chioce == 8)
           {
               if (foo == f_choice)
               {
                   cout << "Resturant has been deleted by the cook press 0 to go back in previous menu" << endl << endl;
               }
               else {
                   Broadway_1();
                   int s;
               ha:
                   cin >> s;
                   if (s == 1)
                   {
                       cartp[AI] = 600;
                       carti[AI] = "small taco pizza";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else if (s == 2)
                   {
                       cartp[AI] = 700;
                       carti[AI] = "medium taco pizza";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else if (s == 3)
                   {
                       cartp[AI] = 800;
                       carti[AI] = "large taco pizza";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else
                   {
                       cout << "!!!!! INVALID OPTION ENETERED!!!!!" << endl;
                       cout << "ENTER THE SIZE : ";
                       goto ha;
                   }
               }
           }
           else if (o_chioce == 0)
           {
               system("cls");
               Resturants();
               goto nowa;
           }
           else
           {
               system("cls");
               pizzahut();
               goto a1;
           }
       }
       //CP 5 Star menu order selection *
       else if (f_choice == 3)
       {
           if (foo == f_choice)
           {
               cout << "Resturant has been deleted by the cook press 0 to go back in previous menu" << endl << endl;
           }
           else {
           ab:
               if (o_chioce == 1)
               {
                   cartp[AI] = 950;
                   carti[AI] = "MUSTARD FISH";
                   cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
               }
               else if (o_chioce == 2)
               {
                   cartp[AI] = 800;
                   carti[AI] = "GRILLED CHICKEN";
                   cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
               }
               else if (o_chioce == 3)
               {
                   cartp[AI] = 800;
                   carti[AI] = "AVOCADO";
                   cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
               }
               else if (o_chioce == 4)
               {
                   cartp[AI] = 1000;
                   carti[AI] = "BOCCONCINI BRUSCHETTA";
                   cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
               }
               else if (o_chioce == 5)
               {
                   cartp[AI] = 650;
                   carti[AI] = "FALAFEL";
                   cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
               }
               else if (o_chioce == 6)
               {
                   cartp[AI] = 500;
                   carti[AI] = "CORN SOUP";
                   cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
               }
               else if (o_chioce == 7)
               {
                   cartp[AI] = 550;
                   carti[AI] = "MANCHOW SOUP";
                   cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
               }
               else if (o_chioce == 8)
               {
                   cartp[AI] = 750;
                   carti[AI] = "VEG PEEKING";
                   cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
               }
               else if (o_chioce == 0)
               {
                   system("cls");
                   Resturants();
                   goto nowa;
               }
               else
               {
                   cout << "!!!!! INVALID OPTION ENETERED!!!!!" << endl;
                   cout << "ENTER THE SIZE : ";
                   goto ab;
               }
           }
       }
       //Gloria jeans menu order selection *
       else if (f_choice == 4)
       {
           if (o_chioce == 1)
           {
               if (foo == f_choice)
               {
                   cout << "Resturant has been deleted by the cook press 0 to go back in previous menu" << endl << endl;
               }
               else {
                   Gjeans_1();
                   int s;
               ac:
                   cin >> s;
                   if (s == 1)
                   {
                       cartp[AI] = 475;
                       carti[AI] = "SMALL CUP OF CAPPUCCINO ";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else if (s == 2)
                   {
                       cartp[AI] = 550;
                       carti[AI] = "MEDIUM CUP OF  CAPPUCCINO ";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else if (s == 3)
                   {
                       cartp[AI] = 645;
                       carti[AI] = "LARGE CUP OF CAPPUCCINO ";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else
                   {
                       cout << "!!!!! INVALID OPTION ENETERED!!!!!" << endl;
                       cout << "ENTER THE SIZE : ";
                       goto ac;
                   }
               }
           }
           else if (o_chioce == 2)
           {
               if (foo == f_choice)
               {
                   cout << "Resturant has been deleted by the cook press 0 to go back in previous menu" << endl << endl;
               }
               else {
                   Gjeans_1();
                   int s;
               bc:
                   cin >> s;
                   if (s == 1)
                   {
                       cartp[AI] = 475;
                       carti[AI] = "SMALL CUP OF CAFFE AMRECANO ";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else if (s == 2)
                   {
                       cartp[AI] = 550;
                       carti[AI] = "MEDIUM CUP OF CAFFE AMRECANO ";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else if (s == 3)
                   {
                       cartp[AI] = 645;
                       carti[AI] = "LARGE CUP OF CAFFE AMRECANO ";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else
                   {
                       cout << "!!!!! INVALID OPTION ENETERED!!!!!" << endl;
                       cout << "ENTER THE SIZE : ";
                       goto ba;
                   }
               }
           }
           else if (o_chioce == 3)
           {
               if (foo == f_choice)
               {
                   cout << "Resturant has been deleted by the cook press 0 to go back in previous menu" << endl << endl;
               }
               else {
                   Gjeans_1();
                   int s;
               cc:
                   cin >> s;
                   if (s == 1)
                   {
                       cartp[AI] = 475;
                       carti[AI] = "SMALL CUP OF CAFFE MOCHA ";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else if (s == 2)
                   {
                       cartp[AI] = 550;
                       carti[AI] = "MEDIUM CUP OF CAFFE MOCHA ";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else if (s == 3)
                   {
                       cartp[AI] = 645;
                       carti[AI] = "LARGE CUP OF CAFFE MOCHA ";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else
                   {
                       cout << "!!!!! INVALID OPTION ENETERED!!!!!" << endl;
                       cout << "ENTER THE SIZE : ";
                       goto cc;
                   }
               }
           }
           else if (o_chioce == 4)
           {
               if (foo == f_choice)
               {
                   cout << "Resturant has been deleted by the cook press 0 to go back in previous menu" << endl << endl;
               }
               else {
                   Gjeans_1();
                   int s;
               dc:
                   cin >> s;
                   if (s == 1)
                   {
                       cartp[AI] = 475;
                       carti[AI] = "SMALL CUP OF  CARAMELATTE";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else if (s == 2)
                   {
                       cartp[AI] = 550;
                       carti[AI] = "MEDIUM CUP OF  CARAMELATTE";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else if (s == 3)
                   {
                       cartp[AI] = 645;
                       carti[AI] = "LARGE CUP OF CARAMELATTE";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else
                   {
                       cout << "!!!!! INVALID OPTION ENETERED!!!!!" << endl;
                       cout << "ENTER THE SIZE : ";
                       goto dc;
                   }
               }
           }
           else if (o_chioce == 5)
           {
               if (foo == f_choice)
               {
                   cout << "Resturant has been deleted by the cook press 0 to go back in previous menu" << endl << endl;
               }
               else {
                   Gjeans_1();
                   int s;
               ec:
                   cin >> s;
                   if (s == 1)
                   {
                       cartp[AI] = 475;
                       carti[AI] = "SMALL CUP OF WHITE CHOCOLATE MOCHA";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else if (s == 2)
                   {
                       cartp[AI] = 550;
                       carti[AI] = "MEDIUM CUP OF WHITE CHOCOLATE MOCHA";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else if (s == 3)
                   {
                       cartp[AI] = 645;
                       carti[AI] = "LARGE CUP OF WHITE CHOCOLATE MOCHA";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else
                   {
                       cout << "!!!!! INVALID OPTION ENETERED!!!!!" << endl;
                       cout << "ENTER THE SIZE : ";
                       goto ec;
                   }
               }
           }
           else if (o_chioce == 6)
           {
               if (foo == f_choice)
               {
                   cout << "Resturant has been deleted by the cook press 0 to go back in previous menu" << endl << endl;
               }
               else {
                   Gjeans_1();
                   int s;
               fc:
                   cin >> s;
                   if (s == 1)
                   {
                       cartp[AI] = 475;
                       carti[AI] = "SMALL CUP OF BABYCINO";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else if (s == 2)
                   {
                       cartp[AI] = 550;
                       carti[AI] = "MEDIUM CUP OF BABYCINO";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else if (s == 3)
                   {
                       cartp[AI] = 645;
                       carti[AI] = "LARGE CUP OF BABYCINO";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else
                   {
                       cout << "!!!!! INVALID OPTION ENETERED!!!!!" << endl;
                       cout << "ENTER THE SIZE : ";
                       goto fc;
                   }
               }
           }
           else if (o_chioce == 7)
           {
               if (foo == f_choice)
               {
                   cout << "Resturant has been deleted by the cook press 0 to go back in previous menu" << endl << endl;
               }
               else {
                   Gjeans_1();
                   int s;
               gc:
                   cin >> s;
                   if (s == 1)
                   {
                       cartp[AI] = 475;
                       carti[AI] = "SMALL CUP OF HOT TEA";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else if (s == 2)
                   {
                       cartp[AI] = 550;
                       carti[AI] = "MEDIUM CUP OF HOT TEA";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else if (s == 3)
                   {
                       cartp[AI] = 650;
                       carti[AI] = "LARGE CUP OF HOT TEA";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else
                   {
                       cout << "!!!!! INVALID OPTION ENETERED!!!!!" << endl;
                       cout << "ENTER THE SIZE : ";
                       goto gc;
                   }
               }
           }
           else if (o_chioce == 8)
           {
               if (foo == f_choice)
               {
                   cout << "Resturant has been deleted by the cook press 0 to go back in previous menu" << endl << endl;
               }
               else {
                   Gjeans_1();
                   int s;
               hc:
                   cin >> s;
                   if (s == 1)
                   {
                       cartp[AI] = 475;
                       carti[AI] = "SMALL CUP OF CHAI TEA LATTE";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else if (s == 2)
                   {
                       cartp[AI] = 550;
                       carti[AI] = "MEDIUM CUP OF CHAI TEA LATTE";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else if (s == 3)
                   {
                       cartp[AI] = 650;
                       carti[AI] = "LARGE CUP OF CHAI TEA LATTE";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else
                   {
                       cout << "!!!!! INVALID OPTION ENETERED!!!!!" << endl;
                       cout << "ENTER THE SIZE : ";
                       goto hc;
                   }
               }
           }
           else if (o_chioce == 0)
           {
               system("cls");
               Resturants();
               goto nowa;
           }
           else
           {
               system("cls");
               pizzahut();
               goto a1;
           }
       }
       //Domeno menu order selection
       else if (f_choice == 5)
       {
           if (o_chioce == 1)
           {
               if (foo == f_choice)
               {
                   cout << "Resturant has been deleted by the cook press 0 to go back in previous menu" << endl << endl;
               }
               else {
                   pizzahut_1();
                   int s;
               aca:
                   cin >> s;
                   if (s == 1)
                   {
                       cartp[AI] = 499;
                       carti[AI] = "SMALL 6 Inch";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else if (s == 2)
                   {
                       cartp[AI] = 1299;
                       carti[AI] = "MEDIUM 9 Inch ";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else if (s == 3)
                   {
                       cartp[AI] = 1799;
                       carti[AI] = "LARGE 12 Inch ";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else
                   {
                       cout << "!!!!! INVALID OPTION ENETERED!!!!!" << endl;
                       cout << "ENTER THE SIZE : ";
                       goto aca;
                   }
               }
           }
           else if (o_chioce == 2)
           {
               if (foo == f_choice)
               {
                   cout << "Resturant has been deleted by the cook press 0 to go back in previous menu" << endl << endl;
               }
               else {
                   pizzahut_1();
                   int s;
               bca:
                   cin >> s;
                   if (s == 1)
                   {
                       cartp[AI] = 499;
                       carti[AI] = "SMALL 6 Inch";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else if (s == 2)
                   {
                       cartp[AI] = 1299;
                       carti[AI] = "MEDIUM 9 Inch";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else if (s == 3)
                   {
                       cartp[AI] = 1799;
                       carti[AI] = "LARGE 12 Inch";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else
                   {
                       cout << "!!!!! INVALID OPTION ENETERED!!!!!" << endl;
                       cout << "ENTER THE SIZE : ";
                       goto bca;
                   }
               }
           }
           else if (o_chioce == 3)
           {
               if (foo == f_choice)
               {
                   cout << "Resturant has been deleted by the cook press 0 to go back in previous menu" << endl << endl;
               }
               else {
                   pizzahut_1();
                   int s;
               cca:
                   cin >> s;
                   if (s == 1)
                   {
                       cartp[AI] = 499;
                       carti[AI] = "SMALL 6 Inch ";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else if (s == 2)
                   {
                       cartp[AI] = 1299;
                       carti[AI] = "MEDIUM 9 Inch ";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else if (s == 3)
                   {
                       cartp[AI] = 1799;
                       carti[AI] = "LARGE 12 Inch ";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else
                   {
                       cout << "!!!!! INVALID OPTION ENETERED!!!!!" << endl;
                       cout << "ENTER THE SIZE : ";
                       goto cca;
                   }
               }
           }
           else if (o_chioce == 4)
           {
               if (foo == f_choice)
               {
                   cout << "Resturant has been deleted by the cook press 0 to go back in previous menu" << endl << endl;
               }
               else {
                   pizzahut_1();
                   int s;
               dca:
                   cin >> s;
                   if (s == 1)
                   {
                       cartp[AI] = 499;
                       carti[AI] = "SMALL 6 Inch";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else if (s == 2)
                   {
                       cartp[AI] = 1299;
                       carti[AI] = "MEDIUM 9 Inch";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else if (s == 3)
                   {
                       cartp[AI] = 1799;
                       carti[AI] = "LARGE 12 Inch";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else
                   {
                       cout << "!!!!! INVALID OPTION ENETERED!!!!!" << endl;
                       cout << "ENTER THE SIZE : ";
                       goto dca;
                   }
               }
           }
           else if (o_chioce == 5)
           {
               if (foo == f_choice)
               {
                   cout << "Resturant has been deleted by the cook press 0 to go back in previous menu" << endl << endl;
               }
               else {
                   pizzahut_1();
                   int s;
               eca:
                   cin >> s;
                   if (s == 1)
                   {
                       cartp[AI] = 499;
                       carti[AI] = "SMALL 6 Inch";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else if (s == 2)
                   {
                       cartp[AI] = 1299;
                       carti[AI] = "MEDIUM 9 Inch";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else if (s == 3)
                   {
                       cartp[AI] = 1799;
                       carti[AI] = "LARGE 12 Inch";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else
                   {
                       cout << "!!!!! INVALID OPTION ENETERED!!!!!" << endl;
                       cout << "ENTER THE SIZE : ";
                       goto eca;
                   }
               }
           }
           else if (o_chioce == 6)
           {
               if (foo == f_choice)
               {
                   cout << "Resturant has been deleted by the cook press 0 to go back in previous menu" << endl << endl;
               }
               else {
                   pizzahut_1();
                   int s;
               fca:
                   cin >> s;
                   if (s == 1)
                   {
                       cartp[AI] = 499;
                       carti[AI] = "SMALL 6 Inch";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else if (s == 2)
                   {
                       cartp[AI] = 1000;
                       carti[AI] = "MEDIUM 9 Inch";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else if (s == 3)
                   {
                       cartp[AI] = 1300;
                       carti[AI] = "LARGE 12 Inch";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else
                   {
                       cout << "!!!!! INVALID OPTION ENETERED!!!!!" << endl;
                       cout << "ENTER THE SIZE : ";
                       goto fca;
                   }
               }
           }
           else if (o_chioce == 7)
           {
               if (foo == f_choice)
               {
                   cout << "Resturant has been deleted by the cook press 0 to go back in previous menu" << endl << endl;
               }
               else {
                   pizzahut_1();
                   int s;
               gca:
                   cin >> s;
                   if (s == 1)
                   {
                       cartp[AI] = 475;
                       carti[AI] = "2 chicken wings";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else if (s == 2)
                   {
                       cartp[AI] = 550;
                       carti[AI] = "4 chicken wings";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else if (s == 3)
                   {
                       cartp[AI] = 645;
                       carti[AI] = "6 chicken wings";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else
                   {
                       cout << "!!!!! INVALID OPTION ENETERED!!!!!" << endl;
                       cout << "ENTER THE SIZE : ";
                       goto gca;
                   }
               }
           }
           else if (o_chioce == 8)
           {
               if (foo == f_choice)
               {
                   cout << "Resturant has been deleted by the cook press 0 to go back in previous menu" << endl << endl;
               }
               else {
                   pizzahut_1();
                   int s;
               hca:
                   cin >> s;
                   if (s == 1)
                   {
                       cartp[AI] = 300;
                       carti[AI] = "2 grilled pieces";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else if (s == 2)
                   {
                       cartp[AI] = 400;
                       carti[AI] = "4 grilled pieces";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else if (s == 3)
                   {
                       cartp[AI] = 500;
                       carti[AI] = "6 grilled pieces";
                       cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
                   }
                   else
                   {
                       cout << "!!!!! INVALID OPTION ENETERED!!!!!" << endl;
                       cout << "ENTER THE SIZE : ";
                       goto hca;
                   }
               }
           }
           else if (o_chioce == 0)
           {
               system("cls");
               Resturants();
               goto nowa;
           }
           else
           {
               system("cls");
               Domenos();
               goto a1;
           }
       }
       //Jaybees menu order selection
       else if (f_choice == 6)
       {
           if (foo == f_choice)
           {
               cout << "Resturant has been deleted by the cook press 0 to go back in previous menu" << endl << endl;
           }
           else {
           abaa:
               if (o_chioce == 1)
               {
                   cartp[AI] = 70;
                   carti[AI] = "SIMPLE CUP";
                   cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
               }
               else if (o_chioce == 2)
               {
                   cartp[AI] = 130;
                   carti[AI] = "SPECIAL CUP";
                   cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
               }
               else if (o_chioce == 3)
               {
                   cartp[AI] = 100;
                   carti[AI] = "WAFFLE CONE";
                   cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
               }
               else if (o_chioce == 4)
               {
                   cartp[AI] = 130;
                   carti[AI] = "SPECIAL WAFFLE CONE";
                   cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
               }
               else if (o_chioce == 5)
               {
                   cartp[AI] = 350;
                   carti[AI] = "MOLTEN LAVA";
                   cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
               }
               else if (o_chioce == 6)
               {
                   cartp[AI] = 140;
                   carti[AI] = "TUTTI FRUTTI";
                   cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
               }
               else if (o_chioce == 7)
               {
                   cartp[AI] = 200;
                   carti[AI] = "OREO SHAKE";
                   cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
               }
               else if (o_chioce == 8)
               {
                   cartp[AI] = 220;
                   carti[AI] = "MOCHA SHAKE";
                   cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
               }
               else if (o_chioce == 0)
               {
                   system("cls");
                   Resturants();
                   goto nowa;
               }
               else
               {
                   cout << "!!!!! INVALID OPTION ENETERED!!!!!" << endl;
                   cout << "ENTER THE SIZE : ";
                   goto abaa;
               }
           }

       }
       //Mcdoanalds menu order selection
       else if (f_choice == 7)
       {
           if (foo == f_choice)
           {
               cout << "Resturant has been deleted by the cook press 0 to go back in previous menu" << endl << endl;
           }
           else {
           abam:
               if (o_chioce == 1)
               {
                   cartp[AI] = 145;
                   carti[AI] = "Beef Burger";
                   cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
               }
               else if (o_chioce == 2)
               {
                   cartp[AI] = 145;
                   carti[AI] = "Chees Burger";
                   cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
               }
               else if (o_chioce == 3)
               {
                   cartp[AI] = 160;
                   carti[AI] = "Spicy Chicken Burger";
                   cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
               }
               else if (o_chioce == 4)
               {
                   cartp[AI] = 220;
                   carti[AI] = "Zinger Burger";
                   cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
               }
               else if (o_chioce == 5)
               {
                   cartp[AI] = 350;
                   carti[AI] = "MC Chicken";
                   cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
               }
               else if (o_chioce == 6)
               {
                   cartp[AI] = 100;
                   carti[AI] = "Coke,FAnta,Sprite";
                   cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
               }
               else if (o_chioce == 7)
               {
                   cartp[AI] = 200;
                   carti[AI] = "Mocha";
                   cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
               }
               else if (o_chioce == 8)
               {
                   cartp[AI] = 220;
                   carti[AI] = "Hote Chocolate";
                   cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
               }
               else if (o_chioce == 0)
               {
                   system("cls");
                   Resturants();
                   goto nowa;
               }
               else
               {
                   cout << "!!!!! INVALID OPTION ENETERED!!!!!" << endl;
                   cout << "ENTER THE SIZE : ";
                   goto abam;
               }
           }
       }
       //Karachi Naseeb Baryani menu order selection
       else if (f_choice == 8)
       {
           if (foo == f_choice)
           {
               cout << "Resturant has been deleted by the cook press 0 to go back in previous menu" << endl << endl;
           }
           else {
           abamk:
               if (o_chioce == 1)
               {
                   cartp[AI] = 150;
                   carti[AI] = "CHIKEN BIRYANI FULL";
                   cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
               }
               else if (o_chioce == 2)
               {
                   cartp[AI] = 95;
                   carti[AI] = "CHIKEN BIRYANI HALF";
                   cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
               }
               else if (o_chioce == 3)
               {
                   cartp[AI] = 140;
                   carti[AI] = "CHIKEN PULAO FULL";
                   cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
               }
               else if (o_chioce == 4)
               {
                   cartp[AI] = 90;
                   carti[AI] = "CHIKEN PULAO HALF";
                   cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
               }
               else if (o_chioce == 5)
               {
                   cartp[AI] = 45;
                   carti[AI] = "SHAMI KABAB";
                   cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
               }
               else if (o_chioce == 6)
               {
                   cartp[AI] = 30;
                   carti[AI] = "RAITA";
                   cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
               }
               else if (o_chioce == 7)
               {
                   cartp[AI] = 30;
                   carti[AI] = "SALAD";
                   cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
               }
               else if (o_chioce == 8)
               {
                   cartp[AI] = 30;
                   carti[AI] = "COLD DRINK";
                   cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
               }
               else if (o_chioce == 0)
               {
                   system("cls");
                   Resturants();
                   goto nowa;
               }
               else
               {
                   cout << "!!!!! INVALID OPTION ENETERED!!!!!" << endl;
                   cout << "ENTER THE SIZE : ";
                   goto abamk;
               }
           }

       }
       //CoockNBull menu order selection
       else if (f_choice == 9)
       {
           cocknbull();
       }
       //Karachi redrock menu order selection
       else if (f_choice == 10)
       {
           karachi_red_rock();
       }
       //FRICHICKS menu order selection
       else if (f_choice == 11)
       {
       if (foo == f_choice)
       {
           cout << "Resturant has been deleted by the cook press 0 to go back in previous menu" << endl << endl;
       }
       else {
       ab:
           if (o_chioce == 1)
           {
               pizzahut_1();
               int s;
           gcba:
               cin >> s;
               if (s == 1)
               {
                   cartp[AI] = 350;
                   carti[AI] = "CHICKEN TIKKA PIZZA";
                   cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
               }
               else if (s == 2)
               {
                   cartp[AI] = 450;
                   carti[AI] = "CHICKEN TIKKA PIZZA";
                   cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
               }
               else if (s == 3)
               {
                   cartp[AI] = 660;
                   carti[AI] = "CHICKEN TIKKA PIZZA";
                   cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
               }
               else
               {
                   cout << "!!!!! INVALID OPTION ENETERED!!!!!" << endl;
                   cout << "ENTER THE SIZE : ";
                   goto gcba;
               }
           }
       else if (o_chioce == 2)
           {
           pizzahut_1();
           int s;
       gcba:
           cin >> s;
           if (s == 1)
           {
               cartp[AI] = 350;
               carti[AI] = "CHICKEN FAJITA PIZZA";
               cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
           }
           else if (s == 2)
           {
               cartp[AI] = 450;
               carti[AI] = "CHICKEN FAJITA PIZZA";
               cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
           }
           else if (s == 3)
           {
               cartp[AI] = 660;
               carti[AI] = "CHICKEN FAJITA PIZZA";
               cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
           }
           else
           {
               cout << "!!!!! INVALID OPTION ENETERED!!!!!" << endl;
               cout << "ENTER THE SIZE : ";
               goto gcba;
           }
           }

           else if (o_chioce == 3)
           {
               pizzahut_1();
               int s;
           gcba:
               cin >> s;
               if (s == 1)
               {
                   cartp[AI] = 350;
                   carti[AI] = "VEGETABLE FAJITA PIZZA";
                   cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
               }
               else if (s == 2)
               {
                   cartp[AI] = 450;
                   carti[AI] = "VEGETABLE FAJITA PIZZA";
                   cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
               }
               else if (s == 3)
               {
                   cartp[AI] = 660;
                   carti[AI] = "VEGETABLE FAJITA PIZZA";
                   cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
               }
               else
               {
                   cout << "!!!!! INVALID OPTION ENETERED!!!!!" << endl;
                   cout << "ENTER THE SIZE : ";
                   goto gcba;
               }
           }
           else if (o_chioce == 4)
           {
               cartp[AI] = 270;
               carti[AI] = "ZINGER BURGER";
               cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
           }
           else if (o_chioce == 5)
           {
               cartp[AI] = 300;
               carti[AI] = "CHAPPLI KABAB BURGER";
               cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
           }
           else if (o_chioce == 6)
           {
               cartp[AI] = 290;
               carti[AI] = "ZINGER CHESE BURGER";
               cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
           }
           else if (o_chioce == 7)
           {
               cartp[AI] = 320;
               carti[AI] = "CHAPLI KABAB CHESE BURGER";
               cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
           }
           else if (o_chioce == 8)
           {
               cartp[AI] = 270;
               carti[AI] = "ZINGER TIKKA BURGER";
               cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
           }
           else if (o_chioce == 0)
           {
               system("cls");
               Resturants();
               goto nowa;
           }
           else
           {
               cout << "!!!!! INVALID OPTION ENETERED!!!!!" << endl;
               cout << "ENTER THE SIZE : ";
               goto ab;
           }
       }
       }
       //SUBWAY menu order selection
       else if (f_choice == 12)
       {
       if (foo == f_choice)
       {
           cout << "Resturant has been deleted by the cook press 0 to go back in previous menu" << endl << endl;
       }
       else {
       ab:
           if (o_chioce == 1)
           {
               cartp[AI] = 600;
               carti[AI] = "TIKKA SANDWICH";
               cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
           }
           else if (o_chioce == 2)
           {
               cartp[AI] = 600;
               carti[AI] = "FAJITA SANDWICH";
               cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
           }
           else if (o_chioce == 3)
           {
               cartp[AI] = 550;
               carti[AI] = "PERI PERI";
               cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
           }
           else if (o_chioce == 4)
           {
               cartp[AI] = 450;
               carti[AI] = "ZINGER BURGER";
               cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
           }
           else if (o_chioce == 5)
           {
               cartp[AI] = 450;
               carti[AI] = "ITALLIAN BMT";
               cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
           }
           else if (o_chioce == 6)
           {
               cartp[AI] = 400;
               carti[AI] = "OVEN ROASTED CHICKEN";
               cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
           }
           else if (o_chioce == 7)
           {
               cartp[AI] = 650;
               carti[AI] = "STEAK AND CHEESE";
               cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
           }
           else if (o_chioce == 8)
           {
               cartp[AI] = 600;
               carti[AI] = "ROASTED BEEF";
               cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
           }
           else if (o_chioce == 0)
           {
               system("cls");
               Resturants();
               goto nowa;
           }
           else
           {
               cout << "!!!!! INVALID OPTION ENETERED!!!!!" << endl;
               cout << "ENTER THE SIZE : ";
               goto ab;
           }
       }
       }
       //GOGA NAQEEBA menu order selection
       else if (f_choice == 13)
       {
       if (foo == f_choice)
       {
           cout << "Resturant has been deleted by the cook press 0 to go back in previous menu" << endl << endl;
       }
       else {
       ab:
           if (o_chioce == 1)
           {
               cartp[AI] = 200;
               carti[AI] = "CHANNAY (FULL)";
               cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
           }
           else if (o_chioce == 2)
           {
               cartp[AI] = 100;
               carti[AI] = "CHANNAY (HALF)";
               cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
           }
           else if (o_chioce == 3)
           {
               cartp[AI] = 110;
               carti[AI] = "DOUBLE ANDA PLATE";
               cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
           }
           else if (o_chioce == 4)
           {
               cartp[AI] = 130;
               carti[AI] = "ANDA KOFTA";
               cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
           }
           else if (o_chioce == 5)
           {
               cartp[AI] = 120;
               carti[AI] = "SINGLE KOFTA CHANAY";
               cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
           }
           else if (o_chioce == 6)
           {
               cartp[AI] = 30;
               carti[AI] = "RAITA";
               cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
           }
           else if (o_chioce == 7)
           {
               cartp[AI] = 30;
               carti[AI] = "SALAD";
               cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
           }
           else if (o_chioce == 8)
           {
               cartp[AI] = 30;
               carti[AI] = "BOTTLE";
               cout << "Item : " << carti[AI] << " of price : " << cartp[AI] << " added to cart successfully " << endl;
           }
           else if (o_chioce == 0)
           {
               system("cls");
               Resturants();
               goto nowa;
           }
           else
           {
               cout << "!!!!! INVALID OPTION ENETERED!!!!!" << endl;
               cout << "ENTER THE SIZE : ";
               goto ab;
           }
       }
       }
       //Master Baryaani menu order selection
       else if (f_choice == 14)
       {
           master_baryani();
       }
       //Timmy's menu order selection
       else if (f_choice == 15)
       {
           timmys();
       }
       //Jhonny's Cafe menu order selection
       else if (f_choice == 16)
       {
           jhonny_cafe();
       }
       //Sweeto menu order selection
       else if (f_choice == 17)
       {
           sweeto();
       }
       //KIMS family resturant menu order selection
       else if (f_choice == 18)
       {
           kims_family_resturant();
       }
       //Chai Qawali menu order selection
       else if (f_choice == 19)
       {
           chai_qawali();
       }
       //Burger Lab menu order selection
       else if (f_choice == 20)
       {
           burger_lab();
       }
    }
    void more_order()
    {
        
        do
        {
        aaa:
            order_food();
            cout << endl << endl;
            cout << "To order more press 'Y' to Print Bill press 'P' " << endl;
            cin >> xa;
            if (xa == 'y' || xa == 'Y')
            {
                AI++;
                system("cls");
                if(rac==1)
                {
                    del_res_menu(cho);
                    goto aaa;
                }
                Resturants();
                goto aaa;
            }
        else if (xa == 'p' || xa == 'P')
            break;
        } while (xa !=true);

    }
};
class delivery:public order{
protected:
	char deliv;
public:
	void F_delivery(){
		cout << "What type of delivery do You want? " << endl;
		cout << "Type P for pickup and D for Delivery: ";
		cin >> deliv;
		if (deliv == 'P' || deliv == 'p'){
			cout << "Your Order will get ready in 30 minutes" << endl;
		}
		else if (deliv == 'D' || deliv == 'd'){
			cout << "Your Rider in on the way, be Patient" << endl;
		}
	}
};
class payment : public order,public delivery
{
protected:
    int bill_total=0;
public:
    int bill_calculation()
    {
        for(int i=0;i<=10;i++)
        {
            if (cartp[i] == 0)
                break;
            bill_total += cartp[i];
        }
        bilc=bill_total;
        return bill_total;
    }
    void bill_display()
    {
        cout << "Items you bought are : " << endl;
        for(int j=0;j<=10;j++)
        {
            if (cartp[j] == 0 && carti[j] == "NULL")
                break;
            cout << " Item : " << carti[j] << " of price : Rs" << cartp[j] << endl;
        }
        cout <<endl<<endl <<"Your total bill for the above items are : " << endl;
        cout << bill_calculation() << endl;;
    }
    void paybill()
    {
        cout << "THE TOTAL AMOUNT OF YOUR BILL IS : " << bilc<<endl;
        WAA -= bilc;
        cout << "REMAINING AMOUNT IN WALLET IS : " << WAA << endl;        
        Sleep(15000);
        cuorder = 1;
        system("cls");
        main();
    }
};
class delivery:public payment
{
protected:
    char deliv;
public:
    void F_delivery() {
        cout << "What type of delivery do You want? " << endl;
        cout << "Type P for pickup and D for Delivery: ";
        cin >> deliv;
        if (deliv == 'P' || deliv == 'p') {
            cout << "Your Order will get ready in 30 minutes" << endl;
        }
        else if (deliv == 'D' || deliv == 'd') {
            cout << "Your Rider in on the way, be Patient" << endl;
        }
    }
};

/// <summary>
/// cart function this function prints out the cart items 
/// </summary>
void cart()
{
    cout << endl;
    cout << "The Itmes In your cart is as follows : " << endl << endl;
    if (cartp[0] != 0)
    {
        for (int i = 0; i <= 10; i++)
        {
            if (cartp[i] == 0)
                break;
            cout << i + 1 << " Item " << carti[i] << " of price Rs" << cartp[i] << endl << endl;;
        } 
    }
    else
        cout << "OOPPSS THERE IS NO ITEM IN YOUR CART" << endl << endl;
        
}
/// <summary>
/// Wallet function dealing with the amount user have 
/// </summary>
void wallet()
{
    int aa;
    ff:
    system("cls");
    cout << "TOTAL AMOUNT IN WALLET IS : Rs"<<WAA<<endl<<endl;
    cout << "TO ENTER MORE AMOUNT IN WALLET PRESS 1 AND TO GO BACK IN PREVOIUS MENU PRESS 0 "<<endl;
    cin >> aa;
    if (aa == 1)
    {
        int f;
        cout << "Enter the amount in Rs : ";
        cin >> f;
        WAA += f;
        goto ff;
    }
    else if(aa==0)
    {
        system("cls");
        main();
        
    }
    else
        goto ff;
}
//DELETING RESTURANTS



int main()
{
    
    char inp;
    int rdc=0;
	admin x;
    customer cu;
    cook co;
    food_resturant g;
    delivery w;
    order n;
    payment d;
    long int choice;
    do
    {
    c:
       
        x.menu_selection();
        coco:
        cin >> choice;
        if(rdc==1)
        {
            if (choice == 5 || choice == 6 || choice == 7)
            {
                cout << "YOU CAN NOT PERFORM THESE TASKS AS THESE ARE ONLY FOR BUYER MENU\n ";
                Sleep(4000);
                system("cls");
                goto c;

            }
            rac = rdc;
        }
        if (choice == 1)
        {
            if (rdc == 1) {
                cout << "YOU HAVE BEEN LOGGED OUT\n";
                Sleep(4000);
                system("cls");
                rdc = 0;
            }
            //cook register  
            co.registrco();
        }
        else if (choice == 2)
        {
            if (rdc == 1) {
                cout << "YOU HAVE BEEN LOGGED OUT\n";
                Sleep(4000);
                system("cls");
                rdc = 0;
            }
            //customer register
            cu.registrcu();
        }
        else if (choice == 3)
        {
            if (rdc == 1) {
                cout << "YOU HAVE BEEN LOGGED OUT\n";
                Sleep(4000);
                system("cls");
            }
            rdc = 0;
            //customer login  
            c1 = 1;
            cu.logincu();
            
        }
        else if (choice == 4)
        {
            if (rdc == 1) {
                cout << "YOU HAVE BEEN LOGGED OUT\n";
                Sleep(4000);
                system("cls");
                rdc = 0;
            }
            //cook login
            countcook = 1;
            co.loginco();
        }
        else if (choice == 5)
        {
            ch5:
            system("cls");
            if(rac==1)
                goto relis;
            g.Resturants();
        relis:
            if (rac == 1)
            {
                co.del_res_menu(cho);
                string e_o;
                ifstream enter("resli_2.txt");
                enter.seekg(1354, ios::beg);
                int eo = 0;
                while (getline(enter, e_o))
                {
                    cout << e_o << endl;
                    eo++;
                    if (eo == 2)
                        break;
                }
            }
            co.ch;
            n.more_order();
            if (c1 == 1)
            {
                goto p_b;
            }
            else if (n.xa == 'p' || n.xa == 'P')
            {
                cout << endl << endl;
                cout << "YOU HAVEN'T LOGGED IN KINDLY LOGG IN OR SIGNUP TO BUY THE FOOD " << endl;
                Sleep(4500);
                system("cls");
                main();
            }
            p_b:
            cout<<endl<< endl << endl;
            d.bill_display();
            cout << endl << endl;
            gxx:
            cout << "TO PAY BILL PRESS Y OR TO ADD MORE ITEMS PRESS N " << endl;
            cin >>inp;
            if (inp == 'y' || inp == 'Y')
            {
                if (WAA >= bilc)
                {
                    d.paybill();
                    w.F_delivery();
                }
            }
            else if (inp == 'N' || inp == 'n')
            {
                goto ch5;
            }
            else
                goto gxx;
            
        }
        else if (choice == 6)
        {
            int x;
            system("cls");
            cart();
            cout << "Your total bill is : " << endl;
            cout << d.bill_calculation();
            cout << endl;
        gxxa:
            cout << "TO PAY BILL PRESS Y OR TO ADD MORE ITEMS PRESS N " << endl;
            cin >> inp;
            if (inp == 'y' || inp == 'Y')
            {
                if (WAA >= bilc)
                {
                    d.paybill();
                    w.F_delivery();
                }
            }
            else if (inp == 'N' || inp == 'n')
            {
                goto ch5;
            }
            else
                goto gxxa;
            cout << "PRESS 0 TO GO BACK IN PREVIOUS MENU " << endl;
            abj:
            cin >> x;
            if (x == 0)
            {
                system("cls");
                main();
            }
            else
                cout << "Invalid option entered enter 0 to go back " << endl;
            goto abj;
        }
        else if (choice == 7)
        {
            wallet();
        }
        else if (choice == 8)
        {
            if (countcook == 1)
            {
                system("cls");
                g.Resturant_1();
                cout << endl;
                cout << "ENTER THE RESTURANT OPTION YOU WANT TO DELETE" << endl;
                cin >> cho;
                foo = cho;
                cho = cho - 1;
                cout << endl;
                int z = 1;

                co.del_res_menu(cho);
                Sleep(5000);
                system("cls");
                rdc = 1;
                goto c;
            }
            else
                cout << "KINDLY LOGIN AS A COOK FIRST TO DELETE A RESTURANT" << endl;
            Sleep(3000);
            system("cls");
            main();
        }
        else if (choice == 10)
        {
            yyy:
            cout << "ENTER 1 TO DELETE COOK OR ENTER 2 TO DELETE USER:" << endl << endl;
            int y;
            cin >> y;
            if (y == 1)
            {
                x.deletecook();
            }
            else if (y == 2)
            {
                x.deleteuser();
            }
            else
            {
                cout << "INVALID OPTION ENTERD!!!" << endl;
                goto yyy;
            }
            
       
        }
        else if (choice > 11)
        {
            cout << " !!!!!!!!! invalid option eneterd !!!!!!!!! " << endl;
            Sleep(1750);
            system("cls");
            goto c;
        }
        else if (choice == 9)
            break;
    } while (choice != 11);
    
        
}

	/*system("CLS");*/

