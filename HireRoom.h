#pragma once
#include "functions.h"
#include "InsertCustomerCheck.h"

namespace HotelManagementSystem {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace MySql::Data::MySqlClient;

    public ref class HireRoom : public System::Windows::Forms::Form
    {
    private:
        System::Windows::Forms::Form^ previousForm;

    public:
        HireRoom(void)
        {
            InitializeComponent();
            this->FormClosing += gcnew FormClosingEventHandler(this, &HireRoom::MyForm_FormClosing);
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            LoadRoomStatuses();
        }

        HireRoom(System::Windows::Forms::Form^ previousForm)
        {
            this->previousForm = previousForm;
            InitializeComponent();
            this->FormClosing += gcnew FormClosingEventHandler(this, &HireRoom::MyForm_FormClosing);
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            LoadRoomStatuses();
        }

    protected:
        ~HireRoom()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::Panel^ panelRooms;

    private: System::Windows::Forms::Button^ btnBack;

    private:
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->panelRooms = (gcnew System::Windows::Forms::Panel());
            this->btnBack = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
            // 
            // panelRooms
            // 
            this->panelRooms->Location = System::Drawing::Point(10, 10);
            this->panelRooms->Name = L"panelRooms";
            this->panelRooms->Size = System::Drawing::Size(1089, 500);
            this->panelRooms->TabIndex = 0;
            // 
            // btnBack
            // 
            this->btnBack->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(162)));
            this->btnBack->Location = System::Drawing::Point(1109, 566);
            this->btnBack->Name = L"btnBack";
            this->btnBack->Size = System::Drawing::Size(141, 47);
            this->btnBack->TabIndex = 2;
            this->btnBack->Text = L"Back";
            this->btnBack->UseVisualStyleBackColor = true;
            this->btnBack->Click += gcnew System::EventHandler(this, &HireRoom::btnBack_Click);
            // 
            // HireRoom
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1454, 650);
            this->Controls->Add(this->btnBack);
            this->Controls->Add(this->panelRooms);
            this->Name = L"HireRoom";
            this->Text = L"HireRoom";
            this->ResumeLayout(false);

        }
#pragma endregion

    public:
        void LoadRoomStatuses()
        {
            String^ connString = "Server=localhost;port=3306;database=hoteldb;uid=root;password=mehmetknc2720";
            MySqlConnection^ conn = gcnew MySqlConnection(connString);

            try
            {
                conn->Open();
                int zero = 0;
                String^ query = "SELECT id, status, price FROM Hotel where id!= " + zero.ToString();
                MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
                MySqlDataReader^ reader = cmd->ExecuteReader();

                int buttonWidth = 100;
                int buttonHeight = 50;
                int padding = 10;
                int x = 0;
                int y = 0;
                int i = 0;
                int count=0;

                while (reader->Read())
                {
                    int roomId = reader->GetInt32(0);
                    String^ status = reader->GetString(1);
                    String^ price = reader->GetString(2);

                    Button^ btnRoom = gcnew Button();
                    btnRoom->Size = System::Drawing::Size(buttonWidth, buttonHeight);
                    btnRoom->Location = System::Drawing::Point(x, y);
                    btnRoom->Text = "Room " + roomId + "\nPrice: " + price;
                    btnRoom->Tag = roomId.ToString(); // Oda numarasýný doðrudan Tag olarak kaydedin

                    UpdateRoomStatus(btnRoom, status);

                    this->panelRooms->Controls->Add(btnRoom);

                    i++;
                    x += buttonWidth + padding;
                    
                    // Bir sonraki satýra geçmek için
                    if (i % 10 == 0) {
                        count++;
                        Label^ lblFloor = gcnew Label();
                        lblFloor->Size = System::Drawing::Size(buttonWidth, buttonHeight);
                        lblFloor->Location = System::Drawing::Point(x+10, y+25);
                        lblFloor->Text = "Floor: " + count;
                        lblFloor -> Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                            static_cast<System::Byte>(162)));
                        x = 0;
                        y += buttonHeight + padding;
                        this->Controls->Add(lblFloor);
                    }
                }

                reader->Close();
            }
            catch (Exception^ e)
            {
                MessageBox::Show("Error: " + e->Message);
            }
            finally
            {
                if (conn->State == ConnectionState::Open)
                {
                    conn->Close();
                }
            }
        }

        void UpdateRoomStatus(Button^ button, String^ status)
        {
            if (status == "full")
            {
                button->BackColor = Color::Red;
                button->Click += gcnew EventHandler(this, &HireRoom::OnRoomButtonClick);
            }
            else if (status == "empty")
            {
                button->BackColor = Color::Green;
                button->Click += gcnew EventHandler(this, &HireRoom::OnHireRoomButtonClick);
            }
        }

    private:
        System::Void OnRoomButtonClick(Object^ sender, EventArgs^ e)
        {
            Button^ clickedButton = safe_cast<Button^>(sender);
            String^ roomIdStr = clickedButton->Tag->ToString();
            int roomNo;

            if (Int32::TryParse(roomIdStr, roomNo))
            {
                showFullRooms(roomNo);
            }
            else
            {
                MessageBox::Show("Invalid room number format: " + roomIdStr, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }

        System::Void OnHireRoomButtonClick(Object^ sender, EventArgs^ e)
        {
            Button^ clickedButton = safe_cast<Button^>(sender);
            String^ roomIdStr = clickedButton->Tag->ToString();
            int roomNo;

            if (Int32::TryParse(roomIdStr, roomNo))
            {
                this->Hide();
                InsertCustomerCheck^ insertCustomerCheck = gcnew InsertCustomerCheck(roomNo, this);
                insertCustomerCheck->Show();
            }
            else
            {
                MessageBox::Show("Invalid room number format: " + roomIdStr, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }

        System::Void MyForm_FormClosing(System::Object^ sender, FormClosingEventArgs^ e) {
            Application::Exit(); // Uygulamayý tamamen kapatýr
        }

        System::Void btnRefresh_Click(System::Object^ sender, System::EventArgs^ e) {
            this->panelRooms->Controls->Clear(); // Paneldeki mevcut kontrolleri temizleyin
            this->LoadRoomStatuses();
        }

        System::Void btnBack_Click(System::Object^ sender, System::EventArgs^ e) {
            this->Hide();
            previousForm->Show();
        }

    protected:
        virtual void OnActivated(EventArgs^ e) override
        {
            Form::OnActivated(e);
            this->panelRooms->Controls->Clear(); // Paneldeki mevcut kontrolleri temizleyin
            this->LoadRoomStatuses();            // Odalarý yeniden yükleyin
        }
    };
}
