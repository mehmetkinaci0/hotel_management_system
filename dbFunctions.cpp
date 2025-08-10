using namespace System;
using namespace System::Drawing;
using namespace MySql::Data::MySqlClient;
using namespace System::Windows::Forms;
using namespace System::Data;

void connectDB() {
    String^ connString = "Server=localhost;port=3306;database=hoteldb;uid=root;password=mehmetknc2720";
    MySqlConnection^ conn = gcnew MySqlConnection(connString);

    try {
        conn->Open();
        Console::WriteLine("Connected to the database successfully.");
    }
    catch (Exception^ e) {
        Console::WriteLine("Failed to connect to the database: " + e->Message);
    }
}

int insertCustomerCheck(String^ tc) {
    bool exists = false;
    String^ query1 = "SELECT tc, hotel_id FROM CUSTOMER";

    MySqlConnection^ conn = gcnew MySqlConnection("Server=localhost;port=3306;database=hoteldb;uid=root;password=mehmetknc2720");
    MySqlCommand^ cmd = gcnew MySqlCommand(query1, conn);

    try {
        conn->Open();
        MySqlDataReader^ reader = cmd->ExecuteReader();

        while (reader->Read()) {
            String^ dbTc = reader["tc"]->ToString();
            int hotelId = Convert::ToInt32(reader["hotel_id"]);

            if (dbTc == tc) {
                Console::WriteLine("Customer " + tc + " already exists!");

                if (hotelId == 0) {
                    return 0;
                }
                else {
                    return hotelId;
                }
            }
        }
        reader->Close();
    }
    catch (Exception^ e) {
        Console::WriteLine("Query failed: " + e->Message);
    }

    return -1;
}

void insertCustomer(String^ tc, String^ name, String^ surname, int age) {
    String^ query = "INSERT INTO Customer (tc, name, surname, age, hotel_id) VALUES ('" +
        tc + "', '" +
        name + "', '" +
        surname + "', " +
        age + ", 0)";

    MySqlConnection^ conn = gcnew MySqlConnection("Server=localhost;port=3306;database=hoteldb;uid=root;password=mehmetknc2720");
    MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);

    try {
        conn->Open();
        cmd->ExecuteNonQuery(); // Sorguyu çalýþtýr
        Console::WriteLine("Customer " + name + " " + surname + " is our customer now!");
    }
    catch (Exception^ e) {
        Console::WriteLine("Query failed: " + e->Message);
    }
}

void showRooms(DataGridView^ dataGridView) {
    int zero = 0;
    String^ query1 = "SELECT Hotel.id, Hotel.status, Hotel.price FROM Hotel WHERE Hotel.status!= 'full' AND Hotel.id!=" + zero.ToString();

    MySqlConnection^ conn = gcnew MySqlConnection("Server=localhost;port=3306;database=hoteldb;uid=root;password=mehmetknc2720");
    MySqlCommand^ cmd = gcnew MySqlCommand(query1, conn);
    MySqlDataAdapter^ adapter = gcnew MySqlDataAdapter(cmd);
    DataTable^ dataTable = gcnew DataTable();

    try {
        conn->Open();
        adapter->Fill(dataTable); // Verileri DataTable'a doldur

        // DataGridView'e verileri yükleyin
        dataGridView->DataSource = dataTable;

        // DataGridView sütun baþlýklarýný ayarlayýn
        dataGridView->Columns[0]->HeaderText = "Room No";
        dataGridView->Columns[1]->HeaderText = "Status";
        dataGridView->Columns[2]->HeaderText = "Price";
    }
    catch (Exception^ e) {
        MessageBox::Show("Query failed: " + e->Message);
    }
    finally {
        if (conn->State == ConnectionState::Open) {
            conn->Close(); // Baðlantýyý kapatmayý unutmayýn
        }
    }
}

int hireRoom(String^ tc, int roomNo, String^ entryDate, String^ lastDate) {
    bool hired = false, exists = false;
    String^ status = "full";
    String^ name, ^ surname;
    String^ query = "SELECT hotel_id, name, surname FROM Customer WHERE tc = '" + tc + "'";
    String^ query1 = "SELECT status FROM Hotel WHERE id = " + roomNo;
    String^ query2 = "UPDATE Customer SET hotel_id = " + roomNo +
        ", entry_date = '" + entryDate +
        "', last_date = '" + lastDate +
        "' WHERE tc = '" + tc + "'";
    String^ query3 = "UPDATE Hotel SET status = '" + status + "' WHERE id = " + roomNo;
    String^ query4 = "SELECT id FROM Hotel";

    MySqlConnection^ conn = gcnew MySqlConnection("Server=localhost;port=3306;database=hoteldb;uid=root;password=mehmetknc2720");

    try {
        conn->Open();

        // Room existence check
        MySqlCommand^ cmd4 = gcnew MySqlCommand(query4, conn);
        MySqlDataReader^ reader4 = cmd4->ExecuteReader();

        while (reader4->Read()) {
            if (Convert::ToInt32(reader4["id"]) == roomNo) {
                exists = true;
                reader4->Close();

                // Check if the customer has an assigned room
                MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
                MySqlDataReader^ reader = cmd->ExecuteReader();
                if (reader->Read()) {
                    int hotelId = Convert::ToInt32(reader["hotel_id"]);
                    name = reader["name"]->ToString();
                    surname = reader["surname"]->ToString();
                    reader->Close();

                    if (hotelId == 0) {
                        // Check room status
                        MySqlCommand^ cmd1 = gcnew MySqlCommand(query1, conn);
                        MySqlDataReader^ reader1 = cmd1->ExecuteReader();
                        if (reader1->Read()) {
                            if (reader1["status"]->ToString() == "empty") {
                                reader1->Close();

                                // Update Customer table
                                MySqlCommand^ cmd2 = gcnew MySqlCommand(query2, conn);
                                cmd2->ExecuteNonQuery();

                                // Update Hotel table
                                MySqlCommand^ cmd3 = gcnew MySqlCommand(query3, conn);
                                cmd3->ExecuteNonQuery();

                                MessageBox::Show("Room " + roomNo + " is hired to " + name + " " + surname, "Room Hired", MessageBoxButtons::OK, MessageBoxIcon::Information);
                                hired = true;
                                // totalCost(tc, roomNo); // totalCost fonksiyonunu da burada çaðýrabilirsiniz.
                                return 0; // Success
                            }
                            else {
                                MessageBox::Show("Room " + roomNo + " is full!", "Room Full", MessageBoxButtons::OK, MessageBoxIcon::Warning);
                                hired = false;
                            }
                        }
                        else {
                            MessageBox::Show("Hire customer failed: ", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                        }
                    }
                    else {
                        MessageBox::Show("You already have room number " + hotelId, "Already Assigned", MessageBoxButtons::OK, MessageBoxIcon::Warning);
                        return 3;
                    }
                }
                else {
                    MessageBox::Show("No customer found with TC: " + tc, "Customer Not Found", MessageBoxButtons::OK, MessageBoxIcon::Warning);
                    reader->Close();
                }
            }
        }
        if (!exists) {
            MessageBox::Show("There is no room with number " + roomNo, "Room Not Found", MessageBoxButtons::OK, MessageBoxIcon::Warning);
            return 1;  // Room does not exist
        }
    }
    catch (Exception^ e) {
        MessageBox::Show("Query failed: " + e->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
    finally {
        if (conn->State == ConnectionState::Open) {
            conn->Close(); // Close the connection
        }
    }

    return 2; // Operation failed
}

void totalCost(String^ tc, int roomNo) {
    double total = 0, dateDiff, price;
    // Ayýn ilk gününü ekleyerek tarih oluþtur
    String^ todayDate = DateTime::Now.ToString("yyyy-MM") + "-01";

    String^ query = "SELECT DATEDIFF(last_date, entry_date) AS day_difference FROM Customer WHERE tc = '" + tc + "'";
    String^ query1 = "SELECT price FROM Hotel WHERE id = " + roomNo;
    String^ query2 = "SELECT budget FROM mainHotel WHERE date = '" + todayDate + "'";
    String^ query4 = "INSERT INTO mainHotel (date, budget) VALUES ('" + todayDate + "', 0)";

    MySqlConnection^ conn = gcnew MySqlConnection("Server=localhost;port=3306;database=hoteldb;uid=root;password=mehmetknc2720");

    try {
        conn->Open();

        // Müþteri konaklama gün sayýsýný al
        MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
        MySqlDataReader^ reader = cmd->ExecuteReader();
        if (reader->Read()) {
            dateDiff = Convert::ToDouble(reader["day_difference"]);
        }
        else {
            MessageBox::Show("No data found for the given TC.", "Information", MessageBoxButtons::OK, MessageBoxIcon::Information);
            reader->Close();
            return;
        }
        reader->Close();

        // Günlük fiyatý al
        cmd = gcnew MySqlCommand(query1, conn);
        reader = cmd->ExecuteReader();
        if (reader->Read()) {
            price = Convert::ToDouble(reader["price"]);
        }
        reader->Close();

        // Mevcut bütçeyi al
        cmd = gcnew MySqlCommand(query2, conn);
        reader = cmd->ExecuteReader();
        if (reader->Read()) {
            total = Convert::ToDouble(reader["budget"]);
        }
        reader->Close();

        // Eðer bütçe kaydý yoksa yeni bir kayýt ekle
        if (total == 0) {
            cmd = gcnew MySqlCommand(query4, conn);
            cmd->ExecuteNonQuery();
            total = 0; // Sýfýrdan baþlat
        }

        // Bütçeyi güncelle
        total += price * dateDiff;
        String^ query3 = "UPDATE mainHotel SET budget = " + total + " WHERE date = '" + todayDate + "'";
        cmd = gcnew MySqlCommand(query3, conn);
        cmd->ExecuteNonQuery();

        MessageBox::Show("New budget for " + todayDate + ": " + total.ToString(), "Budget Updated", MessageBoxButtons::OK, MessageBoxIcon::Information);
    }
    catch (Exception^ e) {
        MessageBox::Show("Query failed: " + e->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
    finally {
        if (conn->State == ConnectionState::Open) {
            conn->Close(); // Baðlantýyý kapat
        }
    }
}

void showFullRooms(int roomNo) {
    String^ status;
    String^ price;
    String^ customerTc;
    String^ customerName;
    String^ customerSurname;
    String^ customerLastDate;
    
    String^ query1 = "SELECT Hotel.id, Hotel.status, Hotel.price, Customer.tc, Customer.name, Customer.surname, DATE_FORMAT(Customer.last_date, '%d-%m-%Y') AS last_date "
        "FROM Hotel LEFT JOIN Customer ON Hotel.id = Customer.hotel_id WHERE Hotel.id ="+roomNo.ToString();

    MySqlConnection^ conn = gcnew MySqlConnection("Server=localhost;port=3306;database=hoteldb;uid=root;password=mehmetknc2720");
    MySqlCommand^ cmd = gcnew MySqlCommand(query1, conn);

    try {
        conn->Open();
        MySqlDataReader^ reader = cmd->ExecuteReader();

        while (reader->Read()) {
            String^ roomNo = reader["id"]->ToString();
            status = reader["status"]->ToString();
            price= reader["price"]->ToString();
            customerTc = reader["tc"]->ToString();
            customerName = reader["name"]->ToString();
            customerSurname = reader["surname"]->ToString();
            customerLastDate = reader["last_date"]->ToString();
        }
        int floor;
        if (Convert::ToInt32(roomNo) % 10 == 0) {
            floor = Convert::ToInt32(roomNo) / 10;
        }
        else {
            floor = Convert::ToInt32(roomNo) / 10 + 1;
        }

        MessageBox::Show("Room No: " + roomNo + "\nStatus: " + status + "\nPrice: " + price + "\nFloor: " + floor + "\nCustomer Tc : " + customerTc + "\nCustomer Name : " +
            customerName + "\nCustomer Surname: " + customerSurname + "\nLast Date: " + customerLastDate);
    }
    catch (Exception^ e) {
        MessageBox::Show("Query failed: " + e->Message);
    }
    finally {
        if (conn->State == ConnectionState::Open) {
            conn->Close(); // Baðlantýyý kapatmayý unutmayýn
        }
    }
}

bool emptyRoom(int roomNo, String^ tc) {
    bool exists = false, existRoom = false, empty = false;
    String^ status = "empty";
    String^ query3 = "SELECT tc FROM Customer";
    String^ query = "SELECT hotel_id FROM Customer WHERE tc= '" + tc + "'";

    MySqlConnection^ conn = gcnew MySqlConnection("Server=localhost;port=3306;database=hoteldb;uid=root;password=mehmetknc2720");
    MySqlCommand^ cmd3 = gcnew MySqlCommand(query3, conn);
    MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);

    try {
        conn->Open();
        MySqlDataReader^ reader3 = cmd3->ExecuteReader();

        while (reader3->Read()) {
            if (reader3["tc"]->ToString() == tc) {
                exists = true;
                reader3->Close();

                MySqlDataReader^ reader = cmd->ExecuteReader();
                if (reader->Read()) {
                    int hotelId = Convert::ToInt32(reader["hotel_id"]);
                    if (hotelId == roomNo) {
                        existRoom = true;
                        reader->Close();

                        String^ query1 = "UPDATE Customer SET hotel_id = 0, entry_date = NULL, last_date = NULL WHERE tc = '" + tc + "'";
                        String^ query2 = "UPDATE Hotel SET status = '" + status + "' WHERE id = " + roomNo;

                        MySqlCommand^ cmd1 = gcnew MySqlCommand(query1, conn);
                        MySqlCommand^ cmd2 = gcnew MySqlCommand(query2, conn);

                        int qstate1 = cmd1->ExecuteNonQuery();
                        int qstate2 = cmd2->ExecuteNonQuery();

                        if (qstate1 > 0 && qstate2 > 0) {
                            MessageBox::Show("Room " + roomNo + " is empty now!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
                            empty = true;
                        }
                        else {
                            MessageBox::Show("Query update customer hotel id failed.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                        }
                    }
                }
                break;
            }
        }
        if (!exists) {
            MessageBox::Show(tc + " does not exist!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            empty = false;
        }
        if (!existRoom) {
            MessageBox::Show("Room " + roomNo + " is wrong", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            empty = false;
        }
    }
    catch (Exception^ e) {
        MessageBox::Show("Query failed: " + e->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
    finally {
        if (conn->State == ConnectionState::Open) {
            conn->Close();
        }
    }

    return empty;
}

void showHotelActivities(DataGridView^ dataGridView) {
    String^ query = "SELECT id,activity_name,description,DATE_FORMAT(activity_date, '%d-%m-%Y') AS activity_date, participants FROM activity WHERE participants!='0'";
    MySqlConnection^ conn = gcnew MySqlConnection("Server=localhost;port=3306;database=hoteldb;uid=root;password=mehmetknc2720");
    MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);

    try {
        conn->Open();
        MySqlDataReader^ reader = cmd->ExecuteReader();

        DataTable^ dt = gcnew DataTable();
        dt->Load(reader);

        // DataGridView'e veri baðlama
        dataGridView->DataSource = dt;

        dataGridView->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::AllCells;
        dataGridView->AutoResizeColumns();

        dataGridView->Columns["id"]->HeaderText = "ID";
        dataGridView->Columns["activity_name"]->HeaderText = "Activity Name";
        dataGridView->Columns["description"]->HeaderText = "Description";
        dataGridView->Columns["activity_date"]->HeaderText = "Date";
        dataGridView->Columns["participants"]->HeaderText = "Last Participants";

        reader->Close();
    }
    catch (Exception^ e) {
        MessageBox::Show("Query failed: " + e->Message);
    }
    finally {
        if (conn->State == ConnectionState::Open) {
            conn->Close();
        }
    }
}

void joinActivity(String^ tc, int activity_id,String^ name,String^ activityDate,int participants) {
    String^ lastDate;
    String^ existDate;
    int roomNo;
    String^ query = "SELECT DATE_FORMAT(last_date, '%d-%m-%Y') AS last_date,hotel_id FROM Customer WHERE tc='" + tc + "'";
    String^ query2 = "SELECT DATE_FORMAT(a.activity_date, '%d-%m-%Y') AS last_date FROM activity a,customer_activity ca WHERE ca.activity_id=a.id AND ca.customer_tc='" + tc + "'";


    MySqlConnection^ conn = gcnew MySqlConnection("Server=localhost;port=3306;database=hoteldb;uid=root;password=mehmetknc2720");

    try {
        conn->Open();

        MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
        MySqlDataReader^ reader = cmd->ExecuteReader();
        if (reader->Read()) {
            lastDate = reader[0]->ToString();
            roomNo = Convert::ToInt32(reader[1]->ToString());
        }
        else {
            MessageBox::Show("No data found for the given TC.", "Information", MessageBoxButtons::OK, MessageBoxIcon::Information);
            reader->Close();
            return;
        }
        reader->Close();



        DateTime date1 = DateTime::ParseExact(lastDate, "dd-MM-yyyy", nullptr);
        DateTime date2 = DateTime::ParseExact(activityDate, "dd-MM-yyyy", nullptr);

        if (date2 > date1) {
            MessageBox::Show("You won't be at the hotel at this time! Please choose another activity.");
            return;
        }
        else {
            cmd = gcnew MySqlCommand(query2, conn);
            reader = cmd->ExecuteReader();
            while (reader->Read()) {
                existDate = reader[0]->ToString();
                DateTime date3 = DateTime::ParseExact(existDate, "dd-MM-yyyy", nullptr);

                if (date3 == date2) {
                    MessageBox::Show("You have an activity in the same time!Please choose another activity.");
                    return;
                }
            }
            reader->Close();

            participants--;
            String^ query3 = "INSERT INTO customer_activity (customer_tc, activity_id) VALUES ('" + tc + "', " + activity_id.ToString() + ")";
            String^ query4 = "UPDATE activity SET participants =" + participants.ToString() + " WHERE id=" + activity_id.ToString();
            
            cmd = gcnew MySqlCommand(query3, conn);
            cmd->ExecuteNonQuery();

            cmd = gcnew MySqlCommand(query4, conn);
            cmd->ExecuteNonQuery();

            MessageBox::Show("You joined activity in " + activityDate + " which is named " + name);
        } 

    }
    catch (Exception^ e) {
        MessageBox::Show("Query failed: " + e->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
    finally {
        if (conn->State == ConnectionState::Open) {
            conn->Close(); // Baðlantýyý kapat
        }
    }

}

bool showCustomerActivities(String^ tc,DataGridView^ dataGridView) {
    String^ query = "SELECT a.activity_name,a.description,a.activity_date FROM customer_activity ca,activity a WHERE ca.activity_id=a.id AND ca.customer_tc='" + tc + "'";
    String^ query1 = "SELECT COUNT(*) FROM customer_activity WHERE customer_tc='" + tc + "'";

    MySqlConnection^ conn = gcnew MySqlConnection("Server=localhost;port=3306;database=hoteldb;uid=root;password=mehmetknc2720");
    MySqlCommand^ cmd = gcnew MySqlCommand(query1, conn);

    try {
        conn->Open();
        MySqlDataReader^ reader = cmd->ExecuteReader();

        if (reader->Read() && reader->GetInt32(0) == 0) {
            MessageBox::Show("You don't have any activities!");
            return false;
        }
        else {
            reader->Close();
            cmd = gcnew MySqlCommand(query, conn);
            reader = cmd->ExecuteReader();

            DataTable^ dt = gcnew DataTable();
            dt->Load(reader);

            // DataGridView'e veri baðlama
            dataGridView->DataSource = dt;

            dataGridView->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::AllCells;
            dataGridView->AutoResizeColumns();

            dataGridView->Columns["activity_name"]->HeaderText = "Activity Name";
            dataGridView->Columns["description"]->HeaderText = "Description";
            dataGridView->Columns["activity_date"]->HeaderText = "Date";

            reader->Close();
        }


        
    }
    catch (Exception^ e) {
        MessageBox::Show("Query failed: " + e->Message);
    }
    finally {
        if (conn->State == ConnectionState::Open) {
            conn->Close();
        }
    }

    return true;
}

void deleteCustomerActivity(String^ tc, String^ activity_name) {
    String^ query = "DELETE FROM customer_activity WHERE customer_tc='" +
        tc + "' AND activity_id IN(SELECT id FROM activity WHERE activity_name='" + activity_name + "')";

    MySqlConnection^ conn = gcnew MySqlConnection("Server=localhost;port=3306;database=hoteldb;uid=root;password=mehmetknc2720");

    try {
        conn->Open();

        MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
        cmd->ExecuteNonQuery();

        String^ query2 = "UPDATE activity SET participants = participants + 1 WHERE activity_name ='" + activity_name + "'";
        cmd = gcnew MySqlCommand(query2, conn);
        cmd->ExecuteNonQuery();

        MessageBox::Show("Deleted successfully!");
 
    }
    catch (Exception^ e) {
        MessageBox::Show("Query failed: " + e->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
    finally {
        if (conn->State == ConnectionState::Open) {
            conn->Close(); // Baðlantýyý kapat
        }
    }

}

void callHouserKeeper(int roomNo, int floor) {
    String^ query = "UPDATE workers SET work='Cleaning', room_no=" + roomNo.ToString() + " WHERE floor=" + floor.ToString() + " AND work='Empty' LIMIT 1";
    MySqlConnection^ conn = gcnew MySqlConnection("Server=localhost;port=3306;database=hoteldb;uid=root;password=mehmetknc2720");

    try {
        conn->Open();

        MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);

        cmd->ExecuteNonQuery();

        MessageBox::Show("Housekeeper will come!");
    }
    catch (Exception^ e) {
        MessageBox::Show("Query failed: " + e->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
    finally{
        if (conn->State == ConnectionState::Open) {
            conn->Close(); // Baðlantýyý kapat
        }
    }
}

void showHotelMoney(DataGridView^ dataGridView) {
    // YYYY-MM formatýnda tarihleri gruplayarak ve her ay için bütçe toplamlarýný hesaplayarak sorgu yapýlýyor
    String^ query = "SELECT DATE_FORMAT(date, '%Y-%m') AS Month, SUM(budget) AS MonthlyBudget FROM mainhotel GROUP BY Month";
    String^ query1 = "SELECT SUM(salary) AS total FROM workers";
    MySqlConnection^ conn = gcnew MySqlConnection("Server=localhost;port=3306;database=hoteldb;uid=root;password=mehmetknc2720");
    MySqlCommand^ cmd = gcnew MySqlCommand(query1, conn);
    int total;
    try {
        conn->Open();
        MySqlDataReader^ reader = cmd->ExecuteReader();

        if (reader->Read()) {
            total = Convert::ToInt32(reader[0]->ToString());
        }
        reader->Close();
        cmd = gcnew MySqlCommand(query, conn);
        reader = cmd->ExecuteReader();

        DataTable^ dt = gcnew DataTable();
        dt->Load(reader);

        // DataTable'ý DataGridView'e baðlama
        dataGridView->DataSource = dt;

        dataGridView->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::AllCells;
        dataGridView->AutoResizeColumns();
        // DataGridView kolon baþlýklarýný ve görünüm ayarlarýný yapýlandýrma
        dataGridView->Columns["Month"]->HeaderText = "Month";
        dataGridView->Columns["MonthlyBudget"]->HeaderText = "Monthly Budget";
        dataGridView->Columns->Add("total", "Workers Salary");
        dataGridView->Columns->Add("net", "Net Money");
        for (int i = 0; i < dataGridView->Rows->Count; i++) {
            dataGridView->Rows[i]->Cells["total"]->Value = total;
            dataGridView->Rows[i]->Cells["net"]->Value = Convert::ToInt32(dataGridView->Rows[i]->Cells["MonthlyBudget"]->Value) - total;
            if (Convert::ToInt32(dataGridView->Rows[i]->Cells["net"]->Value) < 0) {
                dataGridView->Rows[i]->DefaultCellStyle->BackColor = Color::Red;
            }
            else if (Convert::ToInt32(dataGridView->Rows[i]->Cells["net"]->Value) > 0) {
                dataGridView->Rows[i]->DefaultCellStyle->BackColor = Color::Green;
            }
            else {
                dataGridView->Rows[i]->DefaultCellStyle->BackColor = Color::Yellow;
            }
            
        }
        
        reader->Close();
        
        
    }
    catch (Exception^ e) {
        MessageBox::Show("Query failed: " + e->Message);
    }
    finally {
        if (conn->State == ConnectionState::Open) {
            conn->Close();
        }
    }
}

void showWorkers(DataGridView^ dataGridView) {
    String^ query = "SELECT * FROM workers";

    MySqlConnection^ conn = gcnew MySqlConnection("Server=localhost;port=3306;database=hoteldb;uid=root;password=mehmetknc2720");
    MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);

    try {
        conn->Open();
        MySqlDataReader^ reader = cmd->ExecuteReader();

        DataTable^ dt = gcnew DataTable();
        dt->Load(reader);

        // DataGridView'e veri baðlama
        dataGridView->DataSource = dt;

        dataGridView->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::AllCells;
        dataGridView->AutoResizeColumns();


        dataGridView->Columns["id"]->HeaderText = "ID";
        dataGridView->Columns["name"]->HeaderText = "Name";
        dataGridView->Columns["surname"]->HeaderText = "Surname";
        dataGridView->Columns["age"]->HeaderText = "Age";
        dataGridView->Columns["work"]->HeaderText = "Work";
        dataGridView->Columns["salary"]->HeaderText = "Salary";
        dataGridView->Columns["floor"]->HeaderText = "Floor";
        dataGridView->Columns["room_no"]->HeaderText = "Room No";
        //dataGridView->Columns->Add("roomNo", "Room No");
        /*dataGridView->Columns->Add("name", "Name");
        dataGridView->Columns->Add("surname", "Surname");
        dataGridView->Columns->Add("age", "Age");
        dataGridView->Columns->Add("work", "Work");
        dataGridView->Columns->Add("salary", "Salary");
        dataGridView->Columns->Add("floor", "Floor");
        dataGridView->Columns->Add("roomNo", "Room No");*/


        for (int i = 0; i < dataGridView->Rows->Count; i++) {
            if (dataGridView->Rows[i]->IsNewRow) continue;

            Object^ workValue = dataGridView->Rows[i]->Cells["work"]->Value;

            if (workValue != nullptr && workValue->ToString() == "Cleaning") {
                dataGridView->Rows[i]->DefaultCellStyle->BackColor = Color::Red;
            }
        }

        reader->Close();
    }
    catch (Exception^ e) {
        MessageBox::Show("Query failed: " + e->Message);
    }
    finally {
        if (conn->State == ConnectionState::Open) {
            conn->Close();
        }
    }
}



