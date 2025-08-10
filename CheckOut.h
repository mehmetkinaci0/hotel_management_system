#pragma once
#include "functions.h"
namespace HotelManagementSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
    using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Summary for CheckOut
	/// </summary>
	public ref class CheckOut : public System::Windows::Forms::Form
	{
    private:
        int roomNo;
        System::Windows::Forms::Form^ previousForm;
	public:
     
		CheckOut(System::Windows::Forms::Form^ previousForm)
		{
            this->previousForm = previousForm;
			InitializeComponent();
            LoadRoomStatuses();
            this->FormClosing += gcnew FormClosingEventHandler(this, &CheckOut::MyForm_FormClosing);
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            
			//
			//TODO: Add the constructor code here
			//
		}
    private: System::Windows::Forms::Label^ lblCustomerTc;
    public:
    private: System::Windows::Forms::TextBox^ txtTc;
    private: System::Windows::Forms::Button^ btnCheckOut;
    private: System::Windows::Forms::Panel^ pnlCheckOut;
    private: System::Windows::Forms::Button^ btnBack;

	protected:

	private:
		System::Windows::Forms::Panel^ panelRooms;
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~CheckOut()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
            this->panelRooms = (gcnew System::Windows::Forms::Panel());
            this->lblCustomerTc = (gcnew System::Windows::Forms::Label());
            this->txtTc = (gcnew System::Windows::Forms::TextBox());
            this->btnCheckOut = (gcnew System::Windows::Forms::Button());
            this->pnlCheckOut = (gcnew System::Windows::Forms::Panel());
            this->btnBack = (gcnew System::Windows::Forms::Button());
            this->pnlCheckOut->SuspendLayout();
            this->SuspendLayout();
            // 
            // panelRooms
            // 
            this->panelRooms->Location = System::Drawing::Point(10, 10);
            this->panelRooms->Name = L"panelRooms";
            this->panelRooms->Size = System::Drawing::Size(1338, 500);
            this->panelRooms->TabIndex = 0;
            // 
            // lblCustomerTc
            // 
            this->lblCustomerTc->AutoSize = true;
            this->lblCustomerTc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(162)));
            this->lblCustomerTc->Location = System::Drawing::Point(3, 33);
            this->lblCustomerTc->Name = L"lblCustomerTc";
            this->lblCustomerTc->Size = System::Drawing::Size(118, 20);
            this->lblCustomerTc->TabIndex = 1;
            this->lblCustomerTc->Text = L"Customer TC:";
            // 
            // txtTc
            // 
            this->txtTc->Location = System::Drawing::Point(127, 33);
            this->txtTc->Name = L"txtTc";
            this->txtTc->Size = System::Drawing::Size(288, 20);
            this->txtTc->TabIndex = 2;
            // 
            // btnCheckOut
            // 
            this->btnCheckOut->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(162)));
            this->btnCheckOut->Location = System::Drawing::Point(438, 25);
            this->btnCheckOut->Name = L"btnCheckOut";
            this->btnCheckOut->Size = System::Drawing::Size(183, 28);
            this->btnCheckOut->TabIndex = 3;
            this->btnCheckOut->Text = L"Check Out";
            this->btnCheckOut->UseVisualStyleBackColor = true;
            this->btnCheckOut->Click += gcnew System::EventHandler(this, &CheckOut::btnCheckOut_Click);
            // 
            // pnlCheckOut
            // 
            this->pnlCheckOut->Controls->Add(this->lblCustomerTc);
            this->pnlCheckOut->Controls->Add(this->btnCheckOut);
            this->pnlCheckOut->Controls->Add(this->txtTc);
            this->pnlCheckOut->Location = System::Drawing::Point(10, 540);
            this->pnlCheckOut->Name = L"pnlCheckOut";
            this->pnlCheckOut->Size = System::Drawing::Size(645, 100);
            this->pnlCheckOut->TabIndex = 4;
            // 
            // btnBack
            // 
            this->btnBack->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(162)));
            this->btnBack->Location = System::Drawing::Point(1221, 540);
            this->btnBack->Name = L"btnBack";
            this->btnBack->Size = System::Drawing::Size(127, 38);
            this->btnBack->TabIndex = 5;
            this->btnBack->Text = L"Back";
            this->btnBack->UseVisualStyleBackColor = true;
            this->btnBack->Click += gcnew System::EventHandler(this, &CheckOut::btnBack_Click);
            // 
            // CheckOut
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1559, 652);
            this->Controls->Add(this->btnBack);
            this->Controls->Add(this->pnlCheckOut);
            this->Controls->Add(this->panelRooms);
            this->Name = L"CheckOut";
            this->Text = L"CheckOut";
            this->Load += gcnew System::EventHandler(this, &CheckOut::CheckOut_Load);
            this->pnlCheckOut->ResumeLayout(false);
            this->pnlCheckOut->PerformLayout();
            this->ResumeLayout(false);

        }
#pragma endregion

        void LoadRoomStatuses()
        {
            String^ connString = "Server=localhost;port=3306;database=hoteldb;uid=root;password=mehmetknc2720";
            MySqlConnection^ conn = gcnew MySqlConnection(connString);

            try
            {
                conn->Open();
                int zero = 0;
                String^ query = "SELECT id, status FROM Hotel where id!= " + zero.ToString();
                MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
                MySqlDataReader^ reader = cmd->ExecuteReader();

                int buttonWidth = 100;
                int buttonHeight = 50;
                int padding = 10;
                int x = 0;
                int y = 0;
                int i = 0;

                while (reader->Read())
                {
                    int roomId = reader->GetInt32(0);
                    String^ status = reader->GetString(1);

                    if (status == "full") {
                        Button^ btnRoom = gcnew Button();
                        btnRoom->Size = System::Drawing::Size(buttonWidth, buttonHeight);
                        btnRoom->Location = System::Drawing::Point(x, y);
                        btnRoom->Text = "Room " + roomId;
                        btnRoom->Tag = roomId.ToString(); // Oda numarasýný doðrudan Tag olarak kaydedin


                        UpdateRoomStatus(btnRoom, status);

                        this->panelRooms->Controls->Add(btnRoom);

                        i++;
                        x += buttonWidth + padding;

                        // Bir sonraki satýra geçmek için
                        if (i % 10 == 0) {
                            x = 0;
                            y += buttonHeight + padding;
                        }
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
                // Butona týklama olayý ekleyin
                button->Click += gcnew EventHandler(this, &CheckOut::OnRoomButtonClick);
                // Butonun oda numarasýný Tag olarak kaydedin
            }
            
        }

    private: System::Void OnRoomButtonClick(Object^ sender, EventArgs^ e)
    {
        Button^ clickedButton = safe_cast<Button^>(sender);
        String^ roomIdStr = clickedButton->Tag->ToString();

        if (Int32::TryParse(roomIdStr, roomNo))
        {
            this->pnlCheckOut->Show();
        }
        else
        {
            MessageBox::Show("Invalid room number format: " + roomIdStr, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }




    private: System::Void btnCheckOut_Click(System::Object^ sender, System::EventArgs^ e) {
        if (String::IsNullOrEmpty(txtTc->Text)) {
            MessageBox::Show("Please enter customer TC!");
        }
        else {
            String^ tc = txtTc->Text;
            if (emptyRoom(roomNo, tc)) {
                this->panelRooms->Controls->Clear(); // Paneldeki mevcut kontrolleri temizleyin
                this->LoadRoomStatuses();
                this->pnlCheckOut->Hide();
            }
            else {
                this->pnlCheckOut->Hide();
            }
            
        }
    }
private: System::Void CheckOut_Load(System::Object^ sender, System::EventArgs^ e) {
    this->pnlCheckOut->Hide();
}



private: System::Void MyForm_FormClosing(System::Object^ sender, FormClosingEventArgs^ e) {
    Application::Exit(); // Uygulamayý tamamen kapatýr
}
private: System::Void btnBack_Click(System::Object^ sender, System::EventArgs^ e) {
    this->Hide();
    previousForm->Show();
}
};
}
