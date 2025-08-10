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
	/// Summary for CustomerRoomInfo
	/// </summary>
	public ref class CustomerRoomInfo : public System::Windows::Forms::Form
	{
	public:
		Form^ previousForm;
		String^ status;
		String^ roomNo;
		String^ tc;
		int floor;
		CustomerRoomInfo(Form^previousForm)
		{
			this->previousForm = previousForm;
			InitializeComponent();
			this->panel1->Hide();
			this->FormClosing += gcnew FormClosingEventHandler(this, &CustomerRoomInfo::MyForm_FormClosing);
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~CustomerRoomInfo()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lblRoomNo;
	protected:
	private: System::Windows::Forms::Label^ lblFloor;
	private: System::Windows::Forms::Label^ lblRoomStatus;
	private: System::Windows::Forms::Label^ lblName;
	private: System::Windows::Forms::Label^ lblSurname;
	private: System::Windows::Forms::Label^ lblEntryDate;
	private: System::Windows::Forms::Label^ lblLastDate;
	private: System::Windows::Forms::Label^ lblTc;
	private: System::Windows::Forms::TextBox^ txtTc;
	private: System::Windows::Forms::Button^ btnOk;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ btnBack;
	private: System::Windows::Forms::Button^ btnHouseKeeper;

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
			this->lblRoomNo = (gcnew System::Windows::Forms::Label());
			this->lblFloor = (gcnew System::Windows::Forms::Label());
			this->lblRoomStatus = (gcnew System::Windows::Forms::Label());
			this->lblName = (gcnew System::Windows::Forms::Label());
			this->lblSurname = (gcnew System::Windows::Forms::Label());
			this->lblEntryDate = (gcnew System::Windows::Forms::Label());
			this->lblLastDate = (gcnew System::Windows::Forms::Label());
			this->lblTc = (gcnew System::Windows::Forms::Label());
			this->txtTc = (gcnew System::Windows::Forms::TextBox());
			this->btnOk = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->btnHouseKeeper = (gcnew System::Windows::Forms::Button());
			this->btnBack = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// lblRoomNo
			// 
			this->lblRoomNo->AutoSize = true;
			this->lblRoomNo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->lblRoomNo->Location = System::Drawing::Point(52, 39);
			this->lblRoomNo->Name = L"lblRoomNo";
			this->lblRoomNo->Size = System::Drawing::Size(66, 24);
			this->lblRoomNo->TabIndex = 0;
			this->lblRoomNo->Text = L"label1";
			// 
			// lblFloor
			// 
			this->lblFloor->AutoSize = true;
			this->lblFloor->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->lblFloor->Location = System::Drawing::Point(52, 76);
			this->lblFloor->Name = L"lblFloor";
			this->lblFloor->Size = System::Drawing::Size(66, 24);
			this->lblFloor->TabIndex = 1;
			this->lblFloor->Text = L"label2";
			// 
			// lblRoomStatus
			// 
			this->lblRoomStatus->AutoSize = true;
			this->lblRoomStatus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->lblRoomStatus->Location = System::Drawing::Point(52, 121);
			this->lblRoomStatus->Name = L"lblRoomStatus";
			this->lblRoomStatus->Size = System::Drawing::Size(66, 24);
			this->lblRoomStatus->TabIndex = 2;
			this->lblRoomStatus->Text = L"label3";
			// 
			// lblName
			// 
			this->lblName->AutoSize = true;
			this->lblName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->lblName->Location = System::Drawing::Point(52, 161);
			this->lblName->Name = L"lblName";
			this->lblName->Size = System::Drawing::Size(66, 24);
			this->lblName->TabIndex = 3;
			this->lblName->Text = L"label4";
			// 
			// lblSurname
			// 
			this->lblSurname->AutoSize = true;
			this->lblSurname->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->lblSurname->Location = System::Drawing::Point(52, 202);
			this->lblSurname->Name = L"lblSurname";
			this->lblSurname->Size = System::Drawing::Size(66, 24);
			this->lblSurname->TabIndex = 4;
			this->lblSurname->Text = L"label5";
			// 
			// lblEntryDate
			// 
			this->lblEntryDate->AutoSize = true;
			this->lblEntryDate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->lblEntryDate->Location = System::Drawing::Point(52, 249);
			this->lblEntryDate->Name = L"lblEntryDate";
			this->lblEntryDate->Size = System::Drawing::Size(66, 24);
			this->lblEntryDate->TabIndex = 5;
			this->lblEntryDate->Text = L"label6";
			// 
			// lblLastDate
			// 
			this->lblLastDate->AutoSize = true;
			this->lblLastDate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->lblLastDate->Location = System::Drawing::Point(52, 296);
			this->lblLastDate->Name = L"lblLastDate";
			this->lblLastDate->Size = System::Drawing::Size(66, 24);
			this->lblLastDate->TabIndex = 6;
			this->lblLastDate->Text = L"label7";
			// 
			// lblTc
			// 
			this->lblTc->AutoSize = true;
			this->lblTc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->lblTc->Location = System::Drawing::Point(165, 27);
			this->lblTc->Name = L"lblTc";
			this->lblTc->Size = System::Drawing::Size(181, 20);
			this->lblTc->TabIndex = 7;
			this->lblTc->Text = L"Please enter your TC:";
			// 
			// txtTc
			// 
			this->txtTc->Location = System::Drawing::Point(353, 26);
			this->txtTc->Name = L"txtTc";
			this->txtTc->Size = System::Drawing::Size(406, 20);
			this->txtTc->TabIndex = 8;
			// 
			// btnOk
			// 
			this->btnOk->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->btnOk->Location = System::Drawing::Point(787, 21);
			this->btnOk->Name = L"btnOk";
			this->btnOk->Size = System::Drawing::Size(117, 33);
			this->btnOk->TabIndex = 9;
			this->btnOk->Text = L"OK";
			this->btnOk->UseVisualStyleBackColor = true;
			this->btnOk->Click += gcnew System::EventHandler(this, &CustomerRoomInfo::btnOk_Click);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->btnHouseKeeper);
			this->panel1->Controls->Add(this->lblRoomNo);
			this->panel1->Controls->Add(this->lblFloor);
			this->panel1->Controls->Add(this->lblRoomStatus);
			this->panel1->Controls->Add(this->lblName);
			this->panel1->Controls->Add(this->lblLastDate);
			this->panel1->Controls->Add(this->lblSurname);
			this->panel1->Controls->Add(this->lblEntryDate);
			this->panel1->Location = System::Drawing::Point(169, 104);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(472, 423);
			this->panel1->TabIndex = 10;
			// 
			// btnHouseKeeper
			// 
			this->btnHouseKeeper->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->btnHouseKeeper->Location = System::Drawing::Point(101, 364);
			this->btnHouseKeeper->Name = L"btnHouseKeeper";
			this->btnHouseKeeper->Size = System::Drawing::Size(270, 39);
			this->btnHouseKeeper->TabIndex = 7;
			this->btnHouseKeeper->Text = L"Call HouseKeeper";
			this->btnHouseKeeper->UseVisualStyleBackColor = true;
			this->btnHouseKeeper->Click += gcnew System::EventHandler(this, &CustomerRoomInfo::btnHouseKeeper_Click);
			// 
			// btnBack
			// 
			this->btnBack->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->btnBack->Location = System::Drawing::Point(787, 93);
			this->btnBack->Name = L"btnBack";
			this->btnBack->Size = System::Drawing::Size(117, 33);
			this->btnBack->TabIndex = 11;
			this->btnBack->Text = L"Back";
			this->btnBack->UseVisualStyleBackColor = true;
			this->btnBack->Click += gcnew System::EventHandler(this, &CustomerRoomInfo::btnBack_Click);
			// 
			// CustomerRoomInfo
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1366, 665);
			this->Controls->Add(this->btnBack);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->btnOk);
			this->Controls->Add(this->txtTc);
			this->Controls->Add(this->lblTc);
			this->Name = L"CustomerRoomInfo";
			this->Text = L"CustomerRoomInfo";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		void getInfos(String^ tc) {
			String^ query1 = "SELECT hotel_id,name,surname,DATE_FORMAT(entry_date, '%d-%m-%Y') AS entry_date, DATE_FORMAT(last_date, '%d-%m-%Y') AS last_date FROM Customer WHERE tc='" + tc + "'";
			String^ customerName;
			String^ customerSurname;
			String^ customerEntryDate;
			String^ customerLastDate;

			MySqlConnection^ conn = gcnew MySqlConnection("Server=localhost;port=3306;database=hoteldb;uid=root;password=mehmetknc2720");
			MySqlCommand^ cmd = gcnew MySqlCommand(query1, conn);

			try {
				conn->Open();
				MySqlDataReader^ reader = cmd->ExecuteReader();

				while (reader->Read()) {
					roomNo = reader[0]->ToString();
					customerName = reader[1]->ToString();
					customerSurname = reader[2]->ToString();
					customerEntryDate = reader[3]->ToString();
					customerLastDate = reader[4]->ToString();
				}
				reader->Close();
				String^ query2 = "SELECT work FROM workers WHERE room_no='" + roomNo + "'";
				cmd = gcnew MySqlCommand(query2, conn);
				reader = cmd->ExecuteReader();

				if (reader->Read()) {
					status = reader[0]->ToString();
				}
				else {
					status = "Empty";
				}
				if (Convert::ToInt32(roomNo) % 10 == 0) {
					floor = Convert::ToInt32(roomNo) / 10;
				}
				else {
					floor = Convert::ToInt32(roomNo) / 10 + 1;
				}

				lblRoomNo->AutoSize = true;
				lblRoomNo->Text = "Room No: " + roomNo;

				lblFloor->AutoSize = true;
				lblFloor->Text = "Floor: " + floor;

				lblRoomStatus->AutoSize = true;
				lblRoomStatus->Text = "Room Status: " + status;

				lblName->AutoSize = true;
				lblName->Text = "Name: " + customerName;

				lblSurname->AutoSize = true;
				lblSurname->Text = "Surname: " + customerSurname;

				lblEntryDate->AutoSize = true;
				lblEntryDate->Text = "Entry Date: " + customerEntryDate;

				lblLastDate->AutoSize = true;
				lblLastDate->Text = "Last Date: " + customerLastDate;


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
	private: System::Void btnOk_Click(System::Object^ sender, System::EventArgs^ e) {
		if (String::IsNullOrEmpty(txtTc->Text)) {
			MessageBox::Show("Please enter customer TC!");
		}
		else {
			tc = txtTc->Text;
			int result = insertCustomerCheck(tc);
			if (result != 0 && result != -1) {
				this->panel1->Show();
				txtTc->ResetText();
				getInfos(tc);
				if (status == "Cleaning") {
					btnHouseKeeper->Enabled = false;
				}
				else {
					btnHouseKeeper->Enabled = true;
				}
			}
			else if (result == 0) {
				MessageBox::Show("You don't have a room!");
			}
			else {
				MessageBox::Show("You are not our customer!");
			}
			
		}
	}
	private: System::Void MyForm_FormClosing(System::Object^ sender, FormClosingEventArgs^ e) {
		Application::Exit(); // Uygulamayý tamamen kapatýr
    }
private: System::Void btnBack_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	previousForm->Show();
}
private: System::Void btnHouseKeeper_Click(System::Object^ sender, System::EventArgs^ e) {
	if (status == "Empty") {
		callHouserKeeper(Convert::ToInt32(roomNo), floor);
		getInfos(tc);
		if (status == "Cleaning") {
			btnHouseKeeper->Enabled = false;
		}
	}
	else {
		MessageBox::Show("You have already called housekeeper!");
	}
	
}
};
}
