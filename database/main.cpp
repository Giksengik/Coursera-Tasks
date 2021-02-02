#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstdlib>
#include <algorithm>
using namespace std;
string dateCheck(const string & Date){
    /*Проверка: подходит ли введённая дата под формат Year-Month-Day(DDDDDD(сколько угодно)-MM-DD),где
     * Year-год,задаётся любой комбинацией символов 0-9 и -
     * Month-месяц, 1<=Month<=12
     * Day-день, 1<=Day<=31
     * Если дата введена в верном формате, то она же и возвращается
     * Если же дата введена в неверном формате, то возврщается '-'и пишется где допущена ошибка в вводе
    */
    string curentString; //строка в которую записывается комбинация символов для day/month/year
    string month;
    string year;
    string day;
    int count=0; /*если count==0,то идёт обработка curentString для года
                * если count==1,то идёт обработка curentString для месяца
                * если count==2,то идёт обработка curentString для дня
                * Если после цикла count!=2,то введёная дата считается неверной
                */
    int count2=0; // счётчик для проверки, что '-' используется верно
    int prev =2; //индикатор для обозначения предыдущего символа, если prev=0, то это цифра,если prev=1 , то это '-'
    int count3 = 0; //счётчик обработанных символов
    for (const char &c:Date) {
        count3++;
        if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' ||
            c == '9' || c == '-') {
            if (count == 0) {
                if (prev == 0 && c == '-') {
                    prev = 1;
                    year = curentString;
                    count++;
                    curentString = "";
                } else if (c == '-') {
                    prev = 1;
                    curentString += c;
                } else {
                    curentString += c;
                    prev = 0;
                }
            } else if (count == 1) {
                if (c == '-' && prev == 1) {
                    count2++;
                    curentString += c;
                    if (count2 > 1) {
                        cout << "Wrong date format: " << Date << endl;
                        return "-";
                    }
                } else if (c == '-' && prev == 0) {
                    month = curentString;
                    prev = 1;
                    curentString = "";
                    count++;
                    if (count2 == 1 || atoi(month.c_str()) > 12 || atoi(month.c_str()) < 1) {
                        cout << "Month value is invalid: " << month << endl;
                        return "-";
                    }
                } else {
                    curentString += c;
                    prev = 0;
                }
            } else if (count == 2) {
                if (c == '-' && prev == 1) {
                    count2++;
                    curentString += c;
                    if (count2 > 1) {
                        cout << "Wrong date format: " << Date << endl;
                        return "-";
                    }
                } else if (c == '-') {
                    cout << "Wrong date format: " << Date << endl;
                    return "-";
                } else if (count3 == Date.length()) {
                    curentString += c;
                    day = curentString;
                    prev = 5;
                    curentString = "";
                    if (count2 == 1 || atoi(day.c_str()) > 31 || atoi(day.c_str()) < 1) {
                        cout << "Day value is invalid: " << day << endl;
                        return "-";
                    }
                } else {
                    prev = 0;
                    curentString += c;
                }

            }
        }
        else {
            cout << "Wrong date format: " << Date << endl;
            return"-";
        }
    }
    if(count==2) {
        if(month.length()==1){
            string a=month;
            month="0"+a;
        }
        if(day.length()==1){
            string a=day;
            day="0"+a;
        }
        if(year.length()==1){
            char a=year[0];
            year="000";
            year+=a;
        }
        if(year.length()==2){
            char a=year[0];
            char b=year[1];
            year="00";
            year+=a;
            year+=b;
        }
        if(year.length()==3){
            char a=year[0];
            char b=year[1];
            char c=year[2];
            year="0";
            year+=a;
            year+=b;
            year+=c;
        }
        return year+"-"+month+"-"+day;
    }else
        return"-";
}
bool CheckEventByData(map<string,vector<string>> & database,const string&date,const string &event){
    vector<string> DateToCheck=database[date];
    int count=0;
    for(const auto & c:DateToCheck){
        if(c==event){
            count++;
        }
    }
    if(count==0) return true;
    else return false;
}
int NumOfEvent(map<string,vector<string>> database,const string&date,const string & event ){
    int count=0;
    vector<string> curentEvents=database[date];
    for(const string & c:curentEvents){
        if(c==event){
            break;
        }
        count++;
    }
    return count;
}
int NumOfEvents(map<string,vector<string>> events,const string &date){
    vector<string> eventList=events[date];
    int count=0;
    for(auto c:eventList){
        count++;
    }
    return count;
}
class Database{
public:
    void Add(const string & Date,const string & newEvent){
        string CheckedDate=dateCheck(Date);
        if(CheckedDate!="-"){
            if(CheckEventByData(Events,CheckedDate,newEvent)){
                Events[CheckedDate].push_back(newEvent);
            }
        }
        sort(Events[CheckedDate].begin(),Events[CheckedDate].end());
    }
    void Del(const string & date,const string &event){
        string CheckedDate=dateCheck(date);
        if(CheckedDate!="-"&&!CheckEventByData(Events,CheckedDate,event)){
            int num=NumOfEvent(Events,CheckedDate,event);
            Events[CheckedDate].erase(Events[CheckedDate].begin()+num);
            sort(Events[CheckedDate].begin(),Events[CheckedDate].end());
            cout<<"Deleted successfully"<<endl;
        }
        else{
            cout<<"Event not found"<<endl;
        }
    }
    void Del(const string&date){
        string CheckedDate=dateCheck(date);
        if(CheckedDate!="-"){
            cout<<"Deleted "<<NumOfEvents(Events,CheckedDate)<<" events"<<endl;
            Events.erase(CheckedDate);
        }
    }
    void Print(){
        for(const auto & item:Events){
            for(const auto & item2:item.second){
                cout<<item.first<<" "<<item2<<endl;
            }
        }
    }
    void Find(const string&date){
        string CheckedDate=dateCheck(date);
        if(CheckedDate!="-"){
            for(const auto & c:Events[CheckedDate]){
                cout<<c<<endl;
            }
        }
    }
private:
    map<string,vector<string>> Events;
};
int main() {
    Database db;
    string next;
    string next2;
    string command;
    string com;
    string com2;
    string com3;
    string cur;
    int count=0;
    int count2=0;
    while (getline(cin, command)) {
        for(auto c:command){
            count2++;
            if(c==' '&& count==0 ){
                count++;
                com=cur;
                cur="";
            }
            else if(command.length()==count2&&com.empty()){
                cur+=c;
                com=cur;
                cur="";
                if(com=="Print"){
                    db.Print();

                }
            }
            else if(c==' '&&count==1){
                count++;
                com2=cur;
                cur="";
            }
            else if(command.length()==count2&&com2.empty()){
                cur+=c;
                com2=cur;
                cur="";
                if(com=="Find"){
                    db.Find(com2);

                }else if(com=="Del"){
                    db.Del(com2);
                }
            }
            else if(count==2&&command.length()==count2){
                cur+=c;
                com3=cur;
                cur="";
                if(com=="Del"){
                    db.Del(com2,com3);
                }else if(com=="Add"){
                    db.Add(com2,com3);
                }
            }
            else if(c!=' '){
                cur+=c;
            }
        }
        count2=0;
        com="";
        com2="";
        com3="";
        count=0;
    }

    return 0;
}
