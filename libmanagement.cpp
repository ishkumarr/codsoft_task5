// Library Management System | cpp project for CodSoft internship programme
//Task 3rd | Submitted by Ish Kumar(help.arinsharma@gmail.com)

#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<map>
// #include<algorithm>

using namespace std;

int main();

int library_mgmt()
{
    int key, choice, question, view_key, delete_key, edit_key,issue_key, borrow = 0, time_d;
    string val, edit_val;
    char ask, time_m;
    float fine_money = 0.00, fine_amount;
    
    map<int, string> book_database;
    
book_database.insert({1,"Introduction to Quantum Mechanics"});
book_database.insert({2,"Advanced Thermodynamics and Statistical Mechanics"});
book_database.insert({3,"Nuclear Physics and Reactor Theory"});
book_database.insert({4,"Electromagnetic Fields and Waves"});
book_database.insert({5,"Solid State Physics and Materials Science"});
book_database.insert({6,"Introduction to General Relativity"});
book_database.insert({7,"Astrophysics and Cosmology"});
book_database.insert({8,"Introduction to Robotics and Automation"});
book_database.insert({9,"Machine Learning and Pattern Recognition"});
book_database.insert({10,"Computer Vision and Image Processing"});
book_database.insert({11,"Natural Language Processing"});
book_database.insert({12,"Software Engineering Principles"});
book_database.insert({13,"Web Development and Design Patterns"});
book_database.insert({14,"Blockchain Technology and Cryptocurrencies"});
book_database.insert({15,"Cloud Computing and Virtualization"});
book_database.insert({16,"Cybersecurity and Network Defense"});
book_database.insert({17,"Big Data Analytics and NoSQL Databases"});
book_database.insert({18,"Probability and Stochastic Processes"});
book_database.insert({19,"Operations Research and Optimization Techniques"});
book_database.insert({20,"Financial Mathematics and Quantitative Analysis"});
book_database.insert({21,"Business Strategy and Competitive Analysis"});
book_database.insert({22,"Entrepreneurship and Innovation Management"});
book_database.insert({23,"Leadership and Organizational Behavior"});
book_database.insert({24,"Global Economics and Trade Policies"});
book_database.insert({25,"Environmental Chemistry and Sustainable Practices"});
book_database.insert({26,"Literary Classics and World Literature"});
book_database.insert({27,"Cultural Heritage and Indigenous Languages"});
book_database.insert({28,"Modern Philosophy and Political Ideologies"});
book_database.insert({29,"Renewable Energy Systems and Green Technologies"});
book_database.insert({30,"Smart Grids and Sustainable Power Generation"});
book_database.insert({31,"Electric Vehicles and Future Transportation"});
book_database.insert({32,"Climate Change Mitigation and Adaptation Strategies"});

    start:
    cout<<"\nLIBRARY MANAGEMENT SYSTEM [PROGRAMMED BY : ISH KUMAR]"<<endl;
    cout<<"[MENU] INSTRCUTIONS --->\n"<<endl;
    cout<<"1.>>> View a Book    >>>"<<endl;
    cout<<"2.>>> View all Books >>>"<<endl;
    cout<<"3.>>> Add a New Book >>>"<<endl;
    cout<<"4.>>> Edit a Book    >>>"<<endl;
    cout<<"5.>>> Delete a Book  >>>"<<endl;
    cout<<"6.>>> Book Checkout  >>>"<<endl;
    cout<<"7.>>> Book Return    >>>"<<endl;
    cout<<"8.>>> Fine Count     >>>"<<endl;
    cout<<"9.>>> Logout >>>"<<endl;
    cout<<"\nSelect your choice : ";
    cin>>choice;
    switch(choice)
    {
        case 1:
            cout<<"\nEnter the Book Number to view the Book Details : ";
            cin>>view_key;
            if(book_database.find(view_key) == book_database.end())
            {
                cout<<"\nError.!!! This Book Number is not found..."<<endl;
            }
            else
            {
                cout<<endl<<view_key<<" ---> "<<book_database.at(view_key)<<endl;
            }
            goto start;
            break;
        case 2:
            cout<<endl<<"All Books --->"<<endl<<endl;
            for (auto x : book_database) 
            {
                cout << x.first << " ---> " << x.second << endl;
            }
            goto start;
            break;
        case 3:
            do{
                error:
                cout<<"\nEnter the Book Number : ";
                cin>>key;
                if(key <= 0)
                {
                    cout<<"\nError.! You can't assign a Zero(0) or Negative Number as a Book Number..."<<endl;
                    goto error;
                }
                else if(book_database.count(key) == 0)
                {
                    cin.ignore();
                    cout<<"Enter Your Book Details : ";
                    getline(cin, val);
                    book_database.insert({key, val});
                }
                else
                {
                    cout<<"\nSorry.! This Book Number is already exist, not available... Please Try Again..."<<endl;
                    goto error;
                }
                cout<<"\nDo you want to add more Task? (1=Yes / 0=No) : ";
                cin>>question;
            }while(question);
            goto start;
            break;
        case 4:
            cout<<"\nEnter the Book Number which one you want to edit : ";
            cin>>edit_key;
            if(book_database.count(edit_key) == 0)
            {
                cout<<endl<<"Invalid Book Number...! Try Again..."<<endl;
            }
            else
            {
                cin.ignore();
                cout<<"Enter Your Edited Book Details : ";
                getline(cin, edit_val);
                book_database[edit_key] = edit_val;
                cout<<"\nBook No.-"<<edit_key<<" edited successfully...!"<<endl;
            }
            goto start;
            break;
        case 5:
            cout<<"\nEnter the Book Number which one you want to remove/delete : ";
            cin>>delete_key;
            if(book_database.count(delete_key) == 0)
            {
                cout<<endl<<"Invalid Book Number...! Try Again..."<<endl;
            }
            else
            {
                book_database.erase(delete_key);
                cout<<"\nBook No.-"<<delete_key<<" deleted/removed successfully...!"<<endl;
            }
            goto start;
            break;
        case 6:
            cout<<endl<<"Enter the Book Number which you want to borrow : ";
            cin>>issue_key;
            if(borrow == 0 && book_database.count(issue_key) != 0)
            {
                borrow = issue_key;
                cout<<endl<<"Book No.-"<<issue_key<<" ---> "<<book_database.at(issue_key)<<" borrowed Successfully...!"<<endl;
            }
            else if(borrow == 0 && book_database.count(issue_key) == 0)
            {
                cout<<endl<<"This Book is not Available..."<<endl;
            }
            else if(borrow != 0)
            {
                cout<<endl<<"You have already borrowed a book... Please return that to borrow anther book..."<<endl;
            }
            else
            {
                cout<<endl<<"Some Error Occured.! Try Again..."<<endl;
            }
            goto start;
            break;
        case 7:
            if(borrow != 0)
            {
                cout<<endl<<"Borrowed Book Details --->"<<endl;
                cout<<"Book No.-"<<borrow<<endl;
                cout<<"Book Details -- "<<book_database.at(borrow)<<endl;
                cout<<endl<<"Do you want to return that book? (y/n) : ";
                cin>>ask;
                if(ask == 'Y' || ask == 'y')
                {
                    cout<<endl<<"The Book-"<<borrow<<" is returned Successfully...!"<<endl;
                    borrow = 0;
                }
                else
                {
                    cout<<endl<<"The Book-"<<borrow<<" is not returned..."<<endl;
                }
            }
            else
            {
                cout<<endl<<"You haven't borrowed any book till now.!"<<endl;
            }
            goto start;
            break;
        case 8:
            cout<<endl<<"Fine will be imposed if book is not returned within 14 days of issue date."<<endl;
            cout<<"Late submissions would be fined with Rs.10.00 everyday as a penalty."<<endl;
            if(borrow != 0)
            {
                cout<<endl<<"Is one month over after borrowing this book? (y/n) : ";
                cin>>time_m;
                if(time_m == 'Y' || time_m == 'y')
                {
                    cout<<endl<<"How many days passed after one month free use? : ";
                    cin>>time_d;
                    fine_amount = 2.50*time_d;
                    cout<<endl<<"Total Fine Amount till now is Rs.-"<<fixed<<setprecision(2)<<fine_amount<<"/- Only."<<endl;
                }
                else
                {
                    cout<<endl<<"Total Fine Amount till now is Rs.-"<<fixed<<setprecision(2)<<fine_money<<"/- Only."<<endl;
                }
            }
            else
            {
                cout<<endl<<"You haven't borrowed any book yet.!"<<endl;
            }
            goto start;
            break;
        case 9:
            cout<<endl<<"Redirected to homepage..."<<endl;
            main();
            break;
        default:
            cout<<endl<<"Invalid choice...! Please try again..."<<endl;
            goto start;
            break;
    }
    
    return 0;
}

int main()
{
    int pass, option;
    string uid;
    map<string, int> login;
    
    login.insert({"ishkumar", 123123});
    login.insert({"ish", 050});
    
    cout<<endl;
    cout<<"-----------------------------------------------------------------------------"<<endl;
    cout<<"---------------- WELCOME TO LIBRARY MANAGEMENT SYSTEM (LOGIN) ---------------"<<endl;
    cout<<"-----------------------------------------------------------------------------"<<endl;
    cout<<"Select any choice --->"<<endl<<endl;
    cout<<"1.>>> Login >>>"<<endl;
    cout<<"2.>>> Exit  >>>"<<endl;
    cout<<endl<<"Enter your choice : ";
    cin>>option;
    switch(option)
    {
        case 1:
            cout<<endl;
            cin.ignore();
            cout<<"Enter Your User-ID : ";
            getline(cin, uid);
            cout<<"Enter Your Password : ";
            cin>>pass;
            if(login.count(uid) != 0 && pass == login.at(uid))
            {
                cout<<endl<<"Redirected to mainpage..."<<endl;
                library_mgmt();
            }
            else
            {
                cout<<endl<<"Invalid credicials...! Please Try Again..."<<endl;
                main();
            }
            break;
        case 2:
            cout<<"\nThank you for using My Library Management Application...!\n"<<endl;
            exit(0);
            break;
        default:
            cout<<endl<<"Invalid choice...! Please try again..."<<endl;
            main();
            break;
    }
    
    return 0;
}