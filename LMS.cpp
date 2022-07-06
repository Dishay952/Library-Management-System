#include <bits/stdc++.h>
#include <ctime>
using namespace std;
struct date
{
    int day, month, year;
    void set_date(int day, int month, int year)
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }
} typedef Date;
class User
{
protected:
    string Name;
    string ID;
    string Password;

public:
    User(string name, string id, string pass)
    {
        this->Name = name;
        this->ID = id;
        this->Password = pass;
    }
    string getName()
    {
        return this->Name;
    }
    string getID()
    {
        return this->ID;
    }
    string getPassword()
    {
        return this->Password;
    }
};
class Book
{
private:
    string Title;
    string ISBN;
    string Author;
    string Publication;
    int available;

public:
    Date i_date;
    Book(string title, string isbn, string author, string publication, int available, Date i_date)
    {
        this->Title = title;
        this->ISBN = isbn;
        this->Author = author;
        this->Publication = publication;
        this->available = available;
        this->i_date = i_date;
    }
    string getTitle()
    {
        return this->Title;
    }
    string getISBN()
    {
        return this->ISBN;
    }
    string getAuthor()
    {
        return this->Author;
    }
    string getPublication()
    {
        return this->Publication;
    }
    int getAvailable()
    {
        return this->available;
    }
    void setAvailable(int available)
    {
        this->available = available;
    }
    void setTitle(string title)
    {
        this->Title = title;
    }
    void setISBN(string isbn)
    {
        this->ISBN = isbn;
    }
    void setAuthor(string author)
    {
        this->Author = author;
    }
    void setPublication(string publication)
    {
        this->Publication = publication;
    }
    Date show_duedate(int i);
};
class Professor : public User
{
private:
    int fine_amount;
    int num_issued_books;
    vector<Book> issued_books;

public:
    Professor(string name, string id, string pass, int fine, int num) : User(name, id, pass)
    {
        this->fine_amount = fine;
        this->num_issued_books = num;
    }
    int getNumIssuedBooks()
    {
        return this->num_issued_books;
    }
    void setNumIssuedBooks(int num)
    {
        this->num_issued_books = num;
    }
    void setName(string name)
    {
        this->Name = name;
    }
    void setID(string id)
    {
        this->ID = id;
    }
    void setPassword(string pass)
    {
        this->Password = pass;
    }
    void ADDBP(Book b)
    {
        this->issued_books.push_back(b);
        this->num_issued_books++;
    }
    void REMOVEBP(Book b)
    {
        for (int i = 0; i < this->issued_books.size(); i++)
        {
            if (this->issued_books[i].getISBN() == b.getISBN())
            {
                this->issued_books.erase(this->issued_books.begin() + i);
                this->num_issued_books--;
                break;
            }
        }
    }
    string getBookTitle(int i)
    {
        return this->issued_books[i].getTitle();
    }
    Date getBookIssueDate(int i)
    {
        return this->issued_books[i].i_date;
    }
    Book get_ib(int i)
    {
        return this->issued_books[i];
    }
    void set_fine(int fine)
    {
        this->fine_amount = fine;
    }
    int get_fine()
    {
        return this->fine_amount;
    }
    int calculate_fine(int i)
    {
        time_t rawtime;
        struct tm *timeinfo;
        time(&rawtime);
        timeinfo = localtime(&rawtime);
        int d = issued_books[i].show_duedate(1).day; // 1 for prof
        int m = issued_books[i].show_duedate(1).month;
        int y = issued_books[i].show_duedate(1).year;
        int dd = timeinfo->tm_mday;
        int mm = timeinfo->tm_mon + 1;
        int yy = timeinfo->tm_year + 1900;
        cout << "Due Date: " << d << "/" << m << "/" << y << endl;
        cout << "Current Date: " << dd << "/" << mm << "/" << yy << endl;
        long int n1, n2;
        int years, l, j;
        const int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        n1 = y * 365 + d;
        for (j = 0; j < m - 1; j++)
            n1 += monthDays[j];
        years = y;
        if (m <= 2)
            years--;
        l = years / 4 - years / 100 + years / 400;
        n1 += l;
        n2 = yy * 365 + dd;
        for (j = 0; j < mm - 1; j++)
            n2 += monthDays[j];
        years = yy;
        if (m <= 2)
            years--;
        l = years / 4 - years / 100 + years / 400;
        n2 += l;
        n1 = 5 * (n2 - n1);
        fine_amount = n1;
        if (n1 > 0)
            return n1;
        else
            return 0;
    }
    void clearfine()
    {
        this->fine_amount = 0;
    }
};
class Student : public User
{
private:
    int fine_amount;
    int num_issued_books;
    vector<Book> issued_books;

public:
    Student(string name, string id, string pass, int fine, int num) : User(name, id, pass)
    {
        this->fine_amount = fine;
        this->num_issued_books = num;
    }
    int getNumIssuedBooks()
    {
        return this->num_issued_books;
    }
    void setNumIssuedBooks(int num)
    {
        this->num_issued_books = num;
    }
    void ADDBS(Book b)
    {
        this->issued_books.push_back(b);
        this->num_issued_books++;
    }
    void setName(string name)
    {
        this->Name = name;
    }
    void setID(string id)
    {
        this->ID = id;
    }
    void setPassword(string pass)
    {
        this->Password = pass;
    }
    void REMOVEBS(Book b)
    {
        for (int i = 0; i < this->issued_books.size(); i++)
        {
            if (this->issued_books[i].getISBN() == b.getISBN())
            {
                this->issued_books.erase(this->issued_books.begin() + i);
                this->num_issued_books--;
                break;
            }
        }
    }
    string getBookTitle(int i)
    {
        return this->issued_books[i].getTitle();
    }
    Date getBookIssueDate(int i)
    {
        return this->issued_books[i].i_date;
    }
    Book get_ib(int i)
    {
        return this->issued_books[i];
    }
    void set_fine(int fine)
    {
        this->fine_amount = fine;
    }
    int get_fine()
    {
        return this->fine_amount;
    }
    int calculate_fine(int i)
    {
        time_t rawtime;
        struct tm *timeinfo;
        time(&rawtime);
        timeinfo = localtime(&rawtime);
        int d = issued_books[i].show_duedate(2).day; // 2 for student
        int m = issued_books[i].show_duedate(2).month;
        int y = issued_books[i].show_duedate(2).year;
        int dd = timeinfo->tm_mday;
        int mm = timeinfo->tm_mon + 1;
        int yy = timeinfo->tm_year + 1900;
        cout << "Due Date: " << d << "/" << m << "/" << y << endl;
        cout << "Current Date: " << dd << "/" << mm << "/" << yy << endl;
        long int n1, n2;
        int years, l, j;
        const int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        n1 = y * 365 + d;
        for (j = 0; j < m - 1; j++)
            n1 += monthDays[j];
        years = y;
        if (m <= 2)
            years--;
        l = years / 4 - years / 100 + years / 400;
        n1 += l;
        n2 = yy * 365 + dd;
        for (j = 0; j < mm - 1; j++)
            n2 += monthDays[j];
        years = yy;
        if (m <= 2)
            years--;
        l = years / 4 - years / 100 + years / 400;
        n2 += l;
        n1 = 2 * (n2 - n1);
        fine_amount = n1;
        if (n1 > 0)
            return n1;
        else
            return 0;
    }
    void clearfine()
    {
        this->fine_amount = 0;
    }
};
class Librarian : public User
{
public:
    Librarian(string name, string id, string pass) : User(name, id, pass)
    {
    }
    void setName(string name)
    {
        this->Name = name;
    }
    void setID(string id)
    {
        this->ID = id;
    }
    void setPassword(string pass)
    {
        this->Password = pass;
    }
};
Date Book::show_duedate(int j)
{

    int ne;
    Date duedate;
    if (j == 1) // Professor
        ne = 60;
    if (j == 2) // Student
        ne = 30;
    int m2[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int i, k = 0, p, a;
    for (i = 0; i < i_date.month; i++)
    {
        k = k + m2[i];
    }
    k = k + i_date.day + ne;
    if (k <= 365)
    {
        for (i = 0; i < 13; i++)
        {
            p = k - m2[i];
            if (p <= m2[i + 1])
            {
                a = i + 1;
                break;
            }
            else
            {
                k = p;
            }
        }
        duedate.day = p;
        duedate.month = a;
        duedate.year = i_date.year;
    }
    else
    {
        for (i = 0; i < 13; i++)
        {
            p = k - m2[i];
            if (p <= m2[i + 1])
            {
                a = i + 1;
                break;
            }
            else
            {
                k = p;
            }
        }
        duedate.day = p;
        duedate.month = a;
        duedate.year = i_date.year + 1;
    }
    return duedate;
}
class User_Database
{
private:
    vector<Professor> Professor_list;
    vector<Student> Student_list;
    vector<Librarian> Librarian_list;

public:
    void ADDP(Professor data)
    {
        this->Professor_list.push_back(data);
    }
    void ADDS(Student data)
    {
        this->Student_list.push_back(data);
    }
    void ADDL(Librarian data)
    {
        this->Librarian_list.push_back(data);
    }
    int psize()
    {
        return this->Professor_list.size();
    }
    int ssize()
    {
        return this->Student_list.size();
    }
    int lsize()
    {
        return this->Librarian_list.size();
    }
    Professor get_p(int i)
    {
        return this->Professor_list[i];
    }
    void set_p(int i, Professor p)
    {
        this->Professor_list[i] = p;
    }
    Student get_s(int i)
    {
        return this->Student_list[i];
    }
    void set_s(int i, Student s)
    {
        this->Student_list[i] = s;
    }
    Librarian get_l(int i)
    {
        return this->Librarian_list[i];
    }
    void set_l(int i, Librarian l)
    {
        this->Librarian_list[i] = l;
    }
    void REMOVEP(int i)
    {
        this->Professor_list.erase(this->Professor_list.begin() + i);
    }
    void REMOVES(int i)
    {
        this->Student_list.erase(this->Student_list.begin() + i);
    }
    void REMOVEL(int i)
    {
        this->Librarian_list.erase(this->Librarian_list.begin() + i);
    }
    void DisplayAll()
    {
        for (int i = 0; i < this->Professor_list.size(); i++)
        {
            cout << "Professor " << i + 1 << "-" << Professor_list[i].getName() << endl;
        }
        for (int i = 0; i < this->Student_list.size(); i++)
        {
            cout << "Student " << i + 1 << "-" << Student_list[i].getName() << endl;
        }
        for (int i = 0; i < this->Librarian_list.size(); i++)
        {
            cout << "Librarian " << i + 1 << "-" << Librarian_list[i].getName() << endl;
        }
    }
};
class Book_Database
{
private:
    vector<Book> Book_list;

public:
    void ADDB(Book data)
    {
        this->Book_list.push_back(data);
    }
    void REMOVEB(int i)
    {
        this->Book_list.erase(this->Book_list.begin() + i);
    }
    int bsize()
    {
        return this->Book_list.size();
    }
    Book get_b(int i)
    {
        return this->Book_list[i];
    }
    void set_b(int i, int available, Date date)
    {
        this->Book_list[i].setAvailable(available);
        this->Book_list[i].i_date = date;
    }
    void Display();
};
User_Database ud;
Book_Database bd;
void Book_Database ::Display()
{
    for (int i = 0; i < bd.bsize(); i++)
    {
        cout << i + 1 << ". " << bd.get_b(i).getTitle() << endl;
    }
}
void login(int n);
void lms_menu()
{
    int i;
    cout << "\n\t*********** LIBRARY MANAGEMENT SYSTEM ***********\n";
    cout << "\n\t\t>>Please Choose Any Option To Login \n";
    cout << "\n\t\t1.Professor\n\n\t\t2.Student\n\n\t\t3.Librarian\n\n\t\t4.Close System\n";
    cout << "\n\t\tEnter your choice : ";
    cin >> i;
    getchar();
    if (i == 1 || i == 2 || i == 3)
    {
        system("cls");
        login(i);
    }
    else if (i == 4)
        exit(0);
    else
    {
        cout << "\n\t\tInvalid Choice\n";
        lms_menu();
    }
}
Professor issue_book_p(int index, Professor P, int b_index, string title, string isbn, string author, string publication, int available);
Student issue_book_s(int index, Student P, int b_index, string title, string isbn, string author, string publication, int available);
Professor return_book_p(int index, Professor P, int b_index, int available);
Student return_book_s(int index, Student S, int b_index, int available);
void prof(int index)
{
    static int j = 0;
    if (j == 0)
    {
        cout << "Welcome " << ud.get_p(index).getName() << endl;
    }
    j++;
    int i, flag = 0, sum = 0, a = 0;
    string title;
    string tITLE, iSBN, aUTHOR, pUBLICATION;
    cout << "\n1. View Book List\n\n2. My Books\n\n3. Check Book Availability\n\n4. Issue Book\n\n5. Return Book\n\n6. Check Due Dates\n\n7. Calculate Fine\n\n8. Logout\n";
    cout << "\nEnter your choice : ";
    cin >> i;

    switch (i)
    {
    case 1:
        system("cls");
        cout << "Book List\n";
        bd.Display();
        break;
    case 2:
        system("cls");
        cout << "My Books\n";
        if (ud.get_p(index).getNumIssuedBooks() == 0)
            cout << "No Books Issued\n";
        else
        {
            for (int i = 0; i < ud.get_p(index).getNumIssuedBooks(); i++)
            {
                cout << i + 1 << ". " << ud.get_p(index).getBookTitle(i) << " Date of Issue- " << ud.get_p(index).getBookIssueDate(i).day << "/" << ud.get_p(index).getBookIssueDate(i).month << "/" << ud.get_p(index).getBookIssueDate(i).year << endl;
            }
        }
        break;
    case 3:
        getchar();
        system("cls");
        cout << "Book Availability\n";
        for (int i = 0; i < bd.bsize(); i++)
        {
            if (bd.get_b(i).getAvailable() == 1)
            {
                cout << bd.get_b(i).getTitle() << "- Available\n";
                flag = 1;
            }
            else if (bd.get_b(i).getAvailable() == 0)
            {
                cout << bd.get_b(i).getTitle() << "- Not Available\n";
                flag = 1;
            }
        }
        if (bd.bsize() == 0)
            cout << "Book Not Found\n";
        break;
    case 4:
        getchar();
        system("cls");
        cout << "Issue Book\n";
        {
            cout << "Enter Book Title : ";
            getline(cin, title);
            for (int i = 0; i < bd.bsize(); i++)
            {
                if (bd.get_b(i).getTitle() == title && bd.get_b(i).getAvailable() == 1)
                {
                    tITLE = bd.get_b(i).getTitle();
                    iSBN = bd.get_b(i).getISBN();
                    aUTHOR = bd.get_b(i).getAuthor();
                    pUBLICATION = bd.get_b(i).getPublication();
                    ud.set_p(index, issue_book_p(index, ud.get_p(index), i, tITLE, iSBN, aUTHOR, pUBLICATION, 0));
                    // cout << "Book Issued Successfully\n";
                    flag = 1;
                    break;
                }
                else if (bd.get_b(i).getTitle() == title && bd.get_b(i).getAvailable() == 0)
                {
                    cout << "Book Already Issued\n";
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
                cout << "Book Not Found\n";
        }
        break;
    case 5:
        getchar();
        system("cls");
        cout << "Return Book\n";
        {
            cout << "Enter Book Title : ";
            getline(cin, title);
            for (int i = 0; i < bd.bsize(); i++)
            {
                if (bd.get_b(i).getTitle() == title && bd.get_b(i).getAvailable() == 0)
                {
                    ud.set_p(index, return_book_p(index, ud.get_p(index), i, 1));
                    // cout << "Book Returned Successfully\n";
                    flag = 1;
                    break;
                }
                else if (bd.get_b(i).getTitle() == title && bd.get_b(i).getAvailable() == 1)
                {
                    cout << "Book Already Returned\n";
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
                cout << "Book Not Found\n";
        }
        break;
    case 6:
        getchar();
        system("cls");
        cout << "Due Dates:\n";
        {
            if (ud.get_p(index).getNumIssuedBooks() == 0)
                cout << "No Books Issued\n";
            else
            {
                for (int i = 0; i < ud.get_p(index).getNumIssuedBooks(); i++)
                {
                    cout << i + 1 << ". " << ud.get_p(index).getBookTitle(i) << " Due Date - " << ud.get_p(index).get_ib(i).show_duedate(1).day << "/" << ud.get_p(index).get_ib(i).show_duedate(1).month << "/" << ud.get_p(index).get_ib(i).show_duedate(1).year << endl;
                }
            }
            break;
        }
        break;
    case 7:
        getchar();
        system("cls");
        cout << "Fine:\n";
        {
            if (ud.get_p(index).getNumIssuedBooks() == 0)
                cout << "No Books Issued\n";
            else
            {
                for (int i = 0; i < ud.get_p(index).getNumIssuedBooks(); i++)
                {
                    cout << i + 1 << ". " << ud.get_p(index).getBookTitle(i) << endl;
                    a = ud.get_p(index).calculate_fine(i);
                    sum += a;
                    cout << "Fine - " << a << endl;
                }
                cout << "The Total Fine is: " << sum << endl;
            }
            break;
        }
        break;
    case 8:
        system("cls");
        lms_menu();
        break;
    default:
        cout << "\n\t\tInvalid Choice\n";
        prof(index);
    }
    if (i >= 1 && i < 8)
        prof(index);
}
void stud(int index)
{
    static int j = 0;
    if (j == 0)
    {
        cout << "Welcome " << ud.get_s(index).getName() << endl;
    }
    j++;
    int i, flag = 0, sum = 0, a = 0;
    string title;
    string tITLE, iSBN, aUTHOR, pUBLICATION;
    cout << "\n1. View Book List\n\n2. My Books\n\n3. Check Book Availability\n\n4. Issue Book\n\n5. Return Book\n\n6. Check Due Dates\n\n7. Calculate Fine\n\n8. Logout\n";
    cout << "\nEnter your choice : ";
    cin >> i;
    switch (i)
    {
    case 1:
        system("cls");
        cout << "Book List\n";
        bd.Display();
        break;
    case 2:
        system("cls");
        cout << "My Books\n";
        if (ud.get_s(index).getNumIssuedBooks() == 0)
            cout << "No Books Issued\n";
        else if (ud.get_s(index).getNumIssuedBooks() <= 5)
        {
            for (int i = 0; i < ud.get_s(index).getNumIssuedBooks(); i++)
            {
                cout << i + 1 << ". " << ud.get_s(index).getBookTitle(i) << " Date of Issue- " << ud.get_s(index).getBookIssueDate(i).day << "/" << ud.get_s(index).getBookIssueDate(i).month << "/" << ud.get_s(index).getBookIssueDate(i).year << endl;
            }
        }
        break;
    case 3:
        getchar();
        system("cls");
        cout << "Book Availability\n";
        for (int i = 0; i < bd.bsize(); i++)
        {
            if (bd.get_b(i).getAvailable() == 1)
            {
                cout << bd.get_b(i).getTitle() << "- Available\n";
                flag = 1;
            }
            else if (bd.get_b(i).getAvailable() == 0)
            {
                cout << bd.get_b(i).getTitle() << "- Not Available\n";
                flag = 1;
            }
        }
        if (bd.bsize() == 0)
            cout << "Book Not Found\n";
        break;
    case 4:
        getchar();
        system("cls");
        cout << "Issue Book\n";
        {
            cout << "Enter Book Title : ";
            getline(cin, title);
            if (ud.get_s(index).getNumIssuedBooks() < 5)
            {
                for (int i = 0; i < bd.bsize(); i++)
                {
                    if (bd.get_b(i).getTitle() == title && bd.get_b(i).getAvailable() == 1)
                    {
                        tITLE = bd.get_b(i).getTitle();
                        iSBN = bd.get_b(i).getISBN();
                        aUTHOR = bd.get_b(i).getAuthor();
                        pUBLICATION = bd.get_b(i).getPublication();
                        ud.set_s(index, issue_book_s(index, ud.get_s(index), i, tITLE, iSBN, aUTHOR, pUBLICATION, 0));
                        flag = 1;
                        break;
                    }
                    else if (bd.get_b(i).getTitle() == title && bd.get_b(i).getAvailable() == 0)
                    {
                        cout << "Book Already Issued\n";
                        flag = 1;
                        break;
                    }
                }
            }
            else
                cout << "You have already issued 5 books\n";
            if (flag == 0 && ud.get_s(index).getNumIssuedBooks() < 5)
                cout << "Book Not Found\n";
        }
        break;
    case 5:
        getchar();
        system("cls");
        cout << "Return Book\n";
        {
            cout << "Enter Book Title : ";
            getline(cin, title);
            for (int i = 0; i < bd.bsize(); i++)
            {
                if (bd.get_b(i).getTitle() == title && bd.get_b(i).getAvailable() == 0)
                {
                    ud.set_s(index, return_book_s(index, ud.get_s(index), i, 1));
                    // cout << "Book Returned Successfully\n";
                    flag = 1;
                    break;
                }
                else if (bd.get_b(i).getTitle() == title && bd.get_b(i).getAvailable() == 1)
                {
                    cout << "Book Already Returned\n";
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
                cout << "Book Not Found\n";
        }
        break;
    case 6:
        getchar();
        system("cls");
        cout << "Due Dates:\n";
        {
            if (ud.get_s(index).getNumIssuedBooks() == 0)
                cout << "No Books Issued\n";
            else
            {
                for (int i = 0; i < ud.get_s(index).getNumIssuedBooks(); i++)
                {
                    cout << i + 1 << ". " << ud.get_s(index).getBookTitle(i) << " Due Date - " << ud.get_s(index).get_ib(i).show_duedate(2).day << "/" << ud.get_s(index).get_ib(i).show_duedate(2).month << "/" << ud.get_s(index).get_ib(i).show_duedate(2).year << endl;
                }
            }
            break;
        }
        break;
    case 7:
        getchar();
        system("cls");
        cout << "Fine:\n";
        {
            if (ud.get_s(index).getNumIssuedBooks() == 0)
                cout << "No Books Issued\n";
            else
            {
                for (int i = 0; i < ud.get_s(index).getNumIssuedBooks(); i++)
                {
                    cout << i + 1 << ". " << ud.get_s(index).getBookTitle(i) << endl;
                    a = ud.get_s(index).calculate_fine(i);
                    sum += a;
                    cout << "Fine - " << a << endl;
                }
                cout << "The Total Fine is: " << sum << endl;
            }
            break;
        }
        break;
    case 8:
        system("cls");
        lms_menu();
        break;
    default:
        cout << "\n\t\tInvalid Choice\n";
        stud(index);
    }
    if (i >= 1 && i < 8)
        stud(index);
}
void add_books();
void admin(int index)
{
    static int j = 0;
    if (j == 0)
    {
        cout << "Welcome " << ud.get_l(index).getName() << endl;
    }
    j++;
    string username, id, password, title, author, publication, isbn;
    int i = 0, n = 0, y = 0, flag = 0;
    cout << "\n1. Add User\n\n2. Delete User\n\n3. Update User\n\n4. Add Book\n\n5. Delete Book\n\n6. Update Book\n\n7. List all Users \n\n8. List all Books\n\n9. Check which Book is issued to which User \n\n10. Check List of Books issued to User\n\n11. Logout\n";
    cout << "\nEnter your choice : ";
    cin >> i;
    switch (i)
    {
    case 1:
        system("cls");
        cout << "Add User\n";
        {
            cout << "1 to Add Professor\n";
            cout << "2 to Add Student\n";
            cout << "3 to Add Librarian\n";
            cout << "Enter your choice :";
            cin >> y;
            getchar();
            cout << "Enter Username :";
            getline(cin, username);
            cout << "Enter ID:";
            getline(cin, id);
            cout << "Enter Password :";
            getline(cin, password);
            if (y == 1)
            {
                Professor d9(username, id, password, 0, 0);
                ud.ADDP(d9);
            }
            else if (y == 2)
            {
                Student d10(username, id, password, 0, 0);
                ud.ADDS(d10);
            }
            else if (y == 3)
            {
                Librarian d11(username, id, password);
                ud.ADDL(d11);
            }
            else
            {
                cout << "Invalid Choice\n";
                break;
            }

            cout << "User Added Successfully\n";
            break;
        }
    case 2:
        system("cls");
        cout << "Delete User\n";
        {
            cout << "1 to Delete Professor\n";
            cout << "2 to Delete Student\n";
            cout << "3 to Delete Librarian\n";
            cout << "Enter your choice :";
            cin >> y;
            getchar();
            cout << "Enter Username : ";
            getline(cin, username);
            if (y == 1)
            {
                for (int i = 0; i < ud.psize(); i++)
                {
                    if (ud.get_p(i).getName() == username)
                    {
                        ud.REMOVEP(i);
                        cout << "Professor Deleted Successfully\n";
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                    cout << "Professor Not Found\n";
            }
            else if (y == 2)
            {
                for (int i = 0; i < ud.ssize(); i++)
                {
                    if (ud.get_s(i).getName() == username)
                    {
                        ud.REMOVES(i);
                        cout << "Student Deleted Successfully\n";
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                    cout << "Student Not Found\n";
            }
            else if (y == 3)
            {
                for (int i = 0; i < ud.lsize(); i++)
                {
                    if (ud.get_l(i).getName() == username)
                    {
                        ud.REMOVEL(i);
                        cout << "Librarian Deleted Successfully\n";
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                    cout << "Librarian Not Found\n";
            }
            else
            {
                cout << "Invalid Choice\n";
                break;
            }
            break;
        }
    case 3:
        getchar();
        system("cls");
        cout << "Update User\n";
        {
            cout << "1 to Update Professor\n";
            cout << "2 to Update Student\n";
            cout << "3 to Update Librarian\n";
            cout << "Enter your choice :";
            cin >> y;
            getchar();
            cout << "Enter Username : \n";
            getline(cin, username);
            if (y == 1)
            {
                for (int i = 0; i < ud.psize(); i++)
                {
                    if (ud.get_p(i).getName() == username)
                    {
                        ud.REMOVEP(i);
                        cout << "Enter New Username : \n";
                        getline(cin, username);
                        ud.get_p(i).setName(username);
                        cout << "Enter New ID : \n";
                        getline(cin, id);
                        ud.get_p(i).setID(id);
                        cout << "Enter New Password : \n";
                        getline(cin, password);
                        ud.get_p(i).setPassword(password);
                        cout << "Professor Updated Successfully\n";
                        Professor d9(username, id, password, 0, 0);
                        ud.ADDP(d9);
                        break;
                    }
                }
            }
            else if (y == 2)
            {
                for (int i = 0; i < ud.ssize(); i++)
                {
                    if (ud.get_s(i).getName() == username)
                    {
                        ud.REMOVES(i);
                        cout << "Enter New Username : \n";
                        getline(cin, username);
                        ud.get_s(i).setName(username);
                        cout << "Enter New ID : \n";
                        getline(cin, id);
                        ud.get_s(i).setID(id);
                        cout << "Enter New Password : \n";
                        getline(cin, password);
                        ud.get_s(i).setPassword(password);
                        cout << "Student Updated Successfully\n";
                        Student d10(username, id, password, 0, 0);
                        ud.ADDS(d10);
                        break;
                    }
                }
            }
            else if (y == 3)
            {
                for (int i = 0; i < ud.lsize(); i++)
                {
                    if (ud.get_l(i).getName() == username)
                    {
                        ud.REMOVEL(i);
                        cout << "Enter New Username : \n";
                        getline(cin, username);
                        ud.get_l(i).setName(username);
                        cout << "Enter New ID : \n";
                        getline(cin, id);
                        ud.get_l(i).setID(id);
                        cout << "Enter New Password : \n";
                        getline(cin, password);
                        ud.get_l(i).setPassword(password);
                        cout << "Librarian Updated Successfully\n";
                        Librarian d11(username, id, password);
                        ud.ADDL(d11);
                        break;
                    }
                }
            }
            else
            {
                cout << "Invalid Choice\n";
                break;
            }
            break;
        }

    case 4:
        getchar();
        system("cls");
        cout << "Add Book\n";
        {
            add_books();
        }
        break;
    case 5:
        getchar();
        system("cls");
        cout << "Delete Book\n";
        {
            cout << "Enter Book Title : \n";
            getline(cin, title);
            for (int i = 0; i < bd.bsize(); i++)
            {
                if (bd.get_b(i).getTitle() == title)
                {
                    bd.REMOVEB(i);
                    cout << "Book Deleted Successfully\n";
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                cout << "Book Not Found\n";
            }
        }
        break;
    case 6:
        getchar();
        system("cls");
        cout << "Update Book\n";
        {
            cout << "Enter Book Title : \n";
            getline(cin, title);
            for (int i = 0; i < bd.bsize(); i++)
            {
                if (bd.get_b(i).getTitle() == title)
                {
                    bd.REMOVEB(i);
                    cout << "Enter New Title : \n";
                    getline(cin, title);
                    bd.get_b(i).setTitle(title);
                    cout << "Enter New ISBN : \n";
                    getline(cin, isbn);
                    bd.get_b(i).setISBN(isbn);
                    cout << "Enter New Author : \n";
                    getline(cin, author);
                    bd.get_b(i).setAuthor(author);
                    cout << "Enter New Publication : \n";
                    getline(cin, publication);
                    bd.get_b(i).setPublication(publication);
                    cout << "Book Updated Successfully\n";
                    Date init_date;
                    init_date.set_date(0, 0, 0);
                    Book d12(title, isbn, author, publication, 1, init_date);
                    bd.ADDB(d12);
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                cout << "Book Not Found\n";
            }
        }
        break;
    case 7:
        getchar();
        system("cls");
        cout << "User List\n";
        {
            ud.DisplayAll();
        }
        break;
    case 8:
        getchar();
        system("cls");
        cout << "Book List\n";
        {
            bd.Display();
        }
        break;
    case 9:
        getchar();
        system("cls");
        cout << "Enter Book Title : \n";
        getline(cin, title);
        for (int i = 0; i < ud.psize(); i++)
        {
            for (int u = 0; u < ud.get_p(i).getNumIssuedBooks(); u++)
            {
                if (ud.get_p(i).getBookTitle(u) == title)
                {
                    cout << ud.get_p(i).getName() << "\n";
                    flag = 1;
                    break;
                }
            }
            if (flag == 1)
                break;
        }
        for (int i = 0; i < ud.ssize(); i++)
        {
            for (int u = 0; u < ud.get_s(i).getNumIssuedBooks(); u++)
            {
                if (ud.get_s(i).getBookTitle(u) == title)
                {
                    cout << ud.get_s(i).getName() << "\n";
                    flag = 1;
                    break;
                }
            }
            if (flag == 1)
                break;
        }
        if (flag == 0)
            cout << "No User has this Book\n";
        break;
    case 10:
        getchar();
        system("cls");
        cout << "Enter Username : \n";
        getline(cin, username);
        for (int i = 0; i < ud.psize(); i++)
        {
            if (ud.get_p(i).getName() == username)
            {

                if (ud.get_p(i).getNumIssuedBooks() == 0)
                    cout << "No Books Issued\n";
                else
                {
                    for (int j = 0; j < ud.get_p(i).getNumIssuedBooks(); j++)
                    {
                        cout << j + 1 << ". " << ud.get_p(i).getBookTitle(j) << endl;
                    }
                }
                flag = 1;
            }
            if (flag == 1)
                break;
        }
        if (flag == 1)
            break;
        for (int i = 0; i < ud.ssize(); i++)
        {
            if (ud.get_s(i).getName() == username)
            {
                if (ud.get_s(i).getNumIssuedBooks() == 0)
                    cout << "No Books Issued\n";
                else
                {
                    for (int j = 0; j < ud.get_s(i).getNumIssuedBooks(); j++)
                    {
                        cout << j + 1 << ". " << ud.get_s(i).getBookTitle(j) << endl;
                    }
                }
                flag = 1;
            }
            if (flag == 1)
                break;
        }
        if (flag == 1)
            break;
        cout << "Invalid Username\n";
        break;
    case 11:
        system("cls");
        lms_menu();
        break;
    default:
        cout << "\n\t\tInvalid Choice\n";
        admin(index);
        break;
    }
    if (i >= 0 && i < 11)
    {
        admin(index);
    }
}
Professor issue_book_p(int index, Professor P, int b_index, string title, string isbn, string author, string publication, int available)
{
    Date d;
    cout << "Enter the day when issued (1-31)-";
    cin >> d.day;
    cout << "Enter the month when issued (1-12)-";
    cin >> d.month;
    cout << "Enter the year when issued (1900 onwards)-";
    cin >> d.year;
    bd.set_b(b_index, 0, d);
    P.ADDBP(bd.get_b(b_index));
    Date d1 = P.getBookIssueDate(P.getNumIssuedBooks() - 1);
    cout << "\n\t\tBook Issued Successfully\n";
    cout << "\n\t\tBook Title : " << title << endl;
    cout << "\n\t\tBook ISBN : " << isbn << endl;
    cout << "\n\t\tBook Author : " << author << endl;
    cout << "\n\t\tBook Publication : " << publication << endl;
    // cout << "\n\t\tFine Amount : " << P.getFineAmount() << endl;
    cout << "\n\t\tNumber of Issued Books : " << P.getNumIssuedBooks() << endl;
    cout << "\n\t\tDate of Issue : " << d1.day << '/' << d1.month << '/' << d1.year << endl;
    cout << "\n\t\tPress any key to continue\n";
    getchar();
    return P;
}
Student issue_book_s(int index, Student S, int b_index, string title, string isbn, string author, string publication, int available)
{
    Date d;
    cout << "Enter the day when issued (1-31)-";
    cin >> d.day;
    cout << "Enter the month when issued (1-12)-";
    cin >> d.month;
    cout << "Enter the year when issued (1900 onwards) -";
    cin >> d.year;
    bd.set_b(b_index, 0, d);
    S.ADDBS(bd.get_b(b_index));
    Date d1 = S.getBookIssueDate(S.getNumIssuedBooks() - 1);
    cout << "\n\t\tBook Issued Successfully\n";
    cout << "\n\t\tBook Title : " << title << endl;
    cout << "\n\t\tBook ISBN : " << isbn << endl;
    cout << "\n\t\tBook Author : " << author << endl;
    cout << "\n\t\tBook Publication : " << publication << endl;
    // cout << "\n\t\tFine Amount : " << P.getFineAmount() << endl;
    cout << "\n\t\tNumber of Issued Books : " << S.getNumIssuedBooks() << endl;
    cout << "\n\t\tDate of Issue : " << d1.day << '/' << d1.month << '/' << d1.year << endl;
    cout << "\n\t\tPress any key to continue\n";
    getchar();
    return S;
}
Professor return_book_p(int index, Professor P, int b_index, int available)
{
    Date d;
    d.set_date(0, 0, 0);
    bd.set_b(b_index, 1, d);
    P.REMOVEBP(bd.get_b(b_index));
    // P.getBookIssueDate(P.getNumIssuedBooks()-1).set_date(0,0,0);
    cout << "\n\t\tBook Returned Successfully\n";
    cout << "\n\t\tNumber of Issued Books : " << P.getNumIssuedBooks() << endl;
    cout << "\n\t\tPress any key to continue\n";
    getchar();
    return P;
}
Student return_book_s(int index, Student S, int b_index, int available)
{
    Date d;
    d.set_date(0, 0, 0);
    bd.set_b(b_index, 1, d);
    S.REMOVEBS(bd.get_b(b_index));
    // S.getBookIssueDate(S.getNumIssuedBooks()-1).set_date(0,0,0);
    cout << "\n\t\tBook Returned Successfully\n";
    cout << "\n\t\tNumber of Issued Books : " << S.getNumIssuedBooks() << endl;
    cout << "\n\t\tPress any key to continue\n";
    getchar();
    return S;
}
void login(int n)
{
    string name, pass;
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Enter your password: ";
    getline(cin, pass);
    int flag = 0, index = -1;
    if (n == 1)
    {
        for (int i = 0; i < ud.psize(); i++)
        {
            if (ud.get_p(i).getName() == name && ud.get_p(i).getPassword() == pass)
            {
                cout << "Login Successful" << endl;
                flag = 1;
                index = i;
                break;
            }
        }
        if (flag == 1 && index >= 0)
        {
            system("cls");
            prof(index);
        }
        else
        {
            cout << "Login Failed" << endl;
            lms_menu();
        }
    }
    else if (n == 2)
    {
        for (int i = 0; i < ud.ssize(); i++)
        {
            if (ud.get_s(i).getName() == name && ud.get_s(i).getPassword() == pass)
            {
                cout << "Login Successful" << endl;
                flag = 1;
                index = i;
                break;
            }
        }
        if (flag == 1 && index >= 0)
        {
            system("cls");
            stud(index);
        }
        else
        {
            cout << "Login Failed" << endl;
            lms_menu();
        }
    }
    else if (n == 3)
    {
        for (int i = 0; i < ud.lsize(); i++)
        {
            if (ud.get_l(i).getName() == name && ud.get_l(i).getPassword() == pass)
            {
                cout << "Login Successful" << endl;
                flag = 1;
                index = i;
                break;
            }
        }
        if (flag == 1 && index >= 0)
        {
            system("cls");
            admin(index);
        }
        else
        {
            cout << "Login Failed" << endl;
            lms_menu();
        }
    }
}
void add_books()
{
    Date init_date;
    init_date.set_date(0, 0, 0);
    string title, isbn, author, publication;
    int available;
    cout << "Enter the title of the book: ";
    getline(cin, title);
    cout << "Enter the ISBN of the book: ";
    getline(cin, isbn);
    cout << "Enter the author of the book: ";
    getline(cin, author);
    cout << "Enter the publication of the book: ";
    getline(cin, publication);
    cout << "Enter the availability of the book: ";
    cin >> available;
    Book d1(title, isbn, author, publication, available, init_date);
    bd.ADDB(d1);
    cout << "Book Added Successfully" << endl;
    cout << "Press any key to continue" << endl;
    getchar();
}
void init_books()
{
    Date init_date;
    init_date.set_date(0, 0, 0);
    Book d1("C Programming", "99921-58-10-7", "Tejas Ramakrishnan", "IITK", 1, init_date); // available=1 means the book is available to issue
    bd.ADDB(d1);
    Book d2("C++ Programming", "9971-5-0210-0", "Dishay Mehta", "IITK", 1, init_date);
    bd.ADDB(d2);
    Book d3("Java Programming", "960-425-059-0", "Juee Chandrachud", "IITK", 1, init_date);
    bd.ADDB(d3);
    Book d4("Python Programming", "80-902734-1-6", "Aryan Vora", "IITK", 1, init_date);
    bd.ADDB(d4);
    Book d5("Bash Programming", "85-359-0277-5", "Samarth Arora", "IITK", 1, init_date);
    bd.ADDB(d5);
    Book d6("JS Programming", "1-84356-028-3", "Sarthak Kohli", "IITK", 1, init_date);
    bd.ADDB(d6);
    Book d7("Django Programming", "0-684-84328-5", "Dishay Mehta", "IITK", 1, init_date);
    bd.ADDB(d7);
}
void init_users()
{
    Professor d1("Indranil Saha", "1", "1", 0, 0);
    ud.ADDP(d1);
    Professor d2("Rajat Mittal", "2", "2", 0, 0);
    ud.ADDP(d2);
    Professor d3("Subhajit Roy", "3", "3", 0, 0);
    ud.ADDP(d3);
    Student d4("Dishay Mehta", "1", "1", 0, 0);
    ud.ADDS(d4);
    Student d5("Tejas Ramakrishnan", "2", "2", 0, 0);
    ud.ADDS(d5);
    Student d6("Juee Chandrachud", "3", "3", 0, 0);
    ud.ADDS(d6);
    Librarian d7("Librarian1", "1", "1");
    ud.ADDL(d7);
    Librarian d8("Librarian2", "2", "2");
    ud.ADDL(d8);
}
int main()
{
    init_books();
    init_users();
    lms_menu();
}