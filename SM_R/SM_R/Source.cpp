#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

class My_Class {
public :
	int user_from, user_to, user_chag,ar_geo,data, year, month,vivod;
	My_Class () { user_from = 0, user_to =0, user_chag=0, ar_geo=0, data =0, year =0, month =0, vivod =0;} };


void error();
void Ask_answer(int *user_from, int *user_chag);
void Ar_G (int user_from, int user_to, int user_chag,int ar_geo,int vivod);
void Ask_answer(int *user_from, int *user_to, int *user_chag); void Ask_answer(int *ar_geo);
void Ask_data(int *data);
void data_workday(int *user_from, int *user_to, int *user_chag,int *year,int *month,int vivod);
void manth_year (int *year, int *month);
void data_month(int *year, int *month,int *user_from,int *user_chag);
void vivodf(int *vivod);
void yearf( int *year, int *month, int *user_from, int *user_to, int *user_chag);

void main() {   system("chcp 1251");   system("cls");
My_Class user; Ask_answer(&user.ar_geo); // выбор типа

	if (user.ar_geo == 3) Ask_data(&user.data);
		if (user.data == 4) { yearf(&user.year, &user.month, &user.user_from, &user.user_to, &user.user_chag); }
	if (user.data != 4) Ask_answer(&user.user_from,&user.user_to,&user.user_chag); // заполнения прогрессии	
		if (user.ar_geo == 1 || user.ar_geo == 2)Ar_G(user.user_from, user.user_to, user.user_chag,user.ar_geo,user.vivod); // заполнение прогрессии ( до 2х )
	if(user.data == 2) { data_workday(&user.user_from, &user.user_to, &user.user_chag,&user.year,&user.month,user.vivod) ;} // Рабочие дни
		if(user.data == 3) { data_month(&user.user_from,&user.month,&user.year,&user.user_chag) ; } }


void vivodf(int *vivod) {cout << "Выводить в строку [0] или в столбец [1] : "; cin >> *vivod; while (*vivod < 0 || *vivod > 1); }

void Ask_answer(int *ar_geo) { do { system("cls"); cout << "Арифметическая [1] | Геометрическая [2] | Даты [3] \n\nВыберите тип прогрессии : ";  cin >> *ar_geo; } while (*ar_geo < 1 || *ar_geo > 4); }

void Ask_answer(int *user_from, int *user_chag) {
do{ cout << "Укажите шаг прогресии : "; cin >> *user_chag; } while(*user_chag == 0 );
	cout << "Введите число от которого начать прогрессию  : "; cin >> *user_from;}

void Ask_answer(int *user_from, int *user_to, int *user_chag) {

do{ cout << "Укажите шаг прогресии : "; cin >> *user_chag; } while(*user_chag == 0 );
	cout << "Введите число от которого начать прогрессию  : "; cin >> *user_from;
	cout << "Введите по какое число : "; cin >> *user_to;}


void Ar_G(int user_from, int user_to, int user_chag,int ar_geo,int vivod) { vivodf(&vivod);
if (ar_geo != 2 ) for(user_from; user_from < user_to + 1; user_from += user_chag) if (vivod == 0)cout << user_from << " "; else cout << user_from << endl;
	else if (user_chag == 1 ) {error();} 
		else for (user_from; user_from < user_to + 1; user_from *= user_chag) if (vivod == 0)cout << user_from << " "; else cout << user_from << endl;}

void Ask_data(int *data) { cout << "Выберите еденицы : "; cin >> *data;}

void manth_year(int *year, int *month) {cout << "Введите месяц "; cin >> *month; cout << "Введите год : "; cin >> *year;}


void data_workday(int *user_from, int *user_to, int *user_chag,int *year,int *month,int vivod) { 
int  a, vsp_year, vsp_month, Result, sum, vsp = 1; manth_year(year, month); vivodf(&vivod);
a = (14 - *month) / 12;
vsp_year = *year - a;
vsp_month = *month + 12 * a - 2;
Result = 7000 + (*user_from + vsp_year + vsp_year / 4 - vsp_year / 100 + vsp_year / 400 + (31 * vsp_month) / 12);
Result = (Result % 7);

sum = 28 + ((*month + (*month / 8)) % 2) + 2 % *month + ((1 + (1 - (*year % 4 + 2) % (*year % 4 + 1)) * ((*year % 100 + 2) % (*year % 100 + 1)) + (1 - (*year % 400 + 2) % (*year % 400 + 1))) / *month) + (1 / *month) - (((1 - (*year % 4 + 2) % (*year % 4 + 1)) * ((*year % 100 + 2) % (*year % 100 + 1)) + (1 - (*year % 400 + 2) % (*year % 400 + 1))) / *month);
for (vsp = *user_from; vsp < *user_to; ) if (Result % 7 != 0 && Result % 7 != 6) { if(vivod == 0) cout << vsp << " "; else { cout << vsp << endl; } vsp+= *user_chag,Result+= *user_chag;} else { vsp ++, Result ++;} }


void data_month(int *user_from,int *year, int *month,int *user_chag) { manth_year(year, month);
 int To_year, To_month,data = *user_from, sum, vsp_month = *month,arg_month = 13,vsp_year = *year; cout << "Введите по какой год : "; cin >> To_year; cout << "По какой месяц : "; cin >> To_month;
	sum = 28 + ((*month + (*month / 8)) % 2) + 2 % *month + ((1 + (1 - (*year % 4 + 2) % (*year % 4 + 1)) * ((*year % 100 + 2) % (*year % 100 + 1)) + (1 - (*year % 400 + 2) % (*year % 400 + 1))) / *month) + (1 / *month) - (((1 - (*year % 4 + 2) % (*year % 4 + 1)) * ((*year % 100 + 2) % (*year % 100 + 1)) + (1 - (*year % 400 + 2) % (*year % 400 + 1))) / *month);
	if (data > sum) { system("cls"); cout << "Ошибка!, Выход за диапазон.\n В " << *month << " месяце " << *year << " года " << sum << " день(ей) \nПерезапустите программу, и попробуйте еще раз...\n" << endl;}
		else {
			while (vsp_year < To_year) {
		if(*user_from == sum) data = 28 + ((vsp_month + (vsp_month / 8)) % 2) + 2 % vsp_month + ((1 + (1 - (vsp_year % 4 + 2) % (vsp_year % 4 + 1)) * ((vsp_year % 100 + 2) % (vsp_year % 100 + 1)) + (1 - (vsp_year % 400 + 2) % (vsp_year % 400 + 1))) / vsp_month) + (1 / vsp_month) - (((1 - (vsp_year % 4 + 2) % (vsp_year % 4 + 1)) * ((vsp_year % 100 + 2) % (vsp_year % 100 + 1)) + (1 - (vsp_year % 400 + 2) % (vsp_year % 400 + 1))) / vsp_month);
			if (vsp_month < arg_month) { cout << data <<" "<< vsp_month <<" "<< vsp_year << endl;vsp_month+= *user_chag;}
				else { vsp_year++; vsp_month -= arg_month - 1; if (*user_from == sum) { data = 28 + ((vsp_month + (vsp_month / 8)) % 2) + 2 % vsp_month + ((1 + (1 - (vsp_year % 4 + 2) % (vsp_year % 4 + 1)) * ((vsp_year % 100 + 2) % (vsp_year % 100 + 1)) + (1 - (vsp_year % 400 + 2) % (vsp_year % 400 + 1))) / vsp_month) + (1 / vsp_month) - (((1 - (vsp_year % 4 + 2) % (vsp_year % 4 + 1)) * ((vsp_year % 100 + 2) % (vsp_year % 100 + 1)) + (1 - (vsp_year % 400 + 2) % (vsp_year % 400 + 1))) / vsp_month);}
				cout << data <<" "<< vsp_month <<" "<< vsp_year << endl;}}

			while (vsp_month < To_month) { 
				vsp_month += *user_chag;
				if (vsp_month > To_month) {break;}
				if (*user_from == sum) data = 28 + ((vsp_month + (vsp_month / 8)) % 2) + 2 % vsp_month + ((1 + (1 - (vsp_year % 4 + 2) % (vsp_year % 4 + 1)) * ((vsp_year % 100 + 2) % (vsp_year % 100 + 1)) + (1 - (vsp_year % 400 + 2) % (vsp_year % 400 + 1))) / vsp_month) + (1 / vsp_month) - (((1 - (vsp_year % 4 + 2) % (vsp_year % 4 + 1)) * ((vsp_year % 100 + 2) % (vsp_year % 100 + 1)) + (1 - (vsp_year % 400 + 2) % (vsp_year % 400 + 1))) / vsp_month);
				cout << data << " " << vsp_month << " " << vsp_year << endl; } } }

void yearf(int *year, int *month, int *user_from, int *user_to, int *user_chag) {Ask_answer(user_from,user_chag); manth_year(year, month); 
int To_year; cout << "Введите по какой год : "; cin >> To_year; int vsp_year = *year; To_year ++;
if (*year < To_year)  while (vsp_year < To_year) { cout << *user_from << " " << *month << " " << vsp_year << endl; vsp_year+= *user_chag;}
	else while (vsp_year > (To_year -2) ) { cout << *user_from << " " << *month << " " << vsp_year << endl; vsp_year -= *user_chag; }}

void error() {system("cls"); cout << "Ошибка!, умножение на 0 или 1 не дадут прогрессию \nПерезапустите программу, и попробуйте еще раз...\n" << endl;}