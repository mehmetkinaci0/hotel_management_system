#pragma once



using namespace System;
using namespace System::Windows::Forms;
using namespace System::Data;

// connectDB ve insertCustomerCheck fonksiyonlarýnýn bildirimi
void connectDB();
int insertCustomerCheck(String^ tc);
void insertCustomer(String^ tc, String^ name, String^ surname, int age);
void showRooms(DataGridView^ dataGridView);
int hireRoom(String^ tc, int roomNo, String^ entryDate, String^ lastDate);
void totalCost(String^ tc, int roomNo);
void showFullRooms(int roomNo);
bool emptyRoom(int roomNo, String^ tc);
void showHotelActivities(DataGridView^ dataGridView);
void joinActivity(String^ tc, int activity_id, String^ name, String^ activityDate, int participants);
bool showCustomerActivities(String^ tc, DataGridView^ dataGridView);
void deleteCustomerActivity(String^ tc, String^ activity_name);
void callHouserKeeper(int roomNo, int floor);
void showHotelMoney(DataGridView^ dataGridView);
void showWorkers(DataGridView^ dataGridView);