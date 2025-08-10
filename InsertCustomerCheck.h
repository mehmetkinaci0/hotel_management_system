#pragma once
#include "functions.h"

ref class ShowRooms;  // Forward declaration




namespace HotelManagementSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// Summary for HireRoom
	/// </summary>
	public ref class InsertCustomerCheck : public System::Windows::Forms::Form
	{
	private:
		Form^ previousForm ;
	private: System::Windows::Forms::Panel^ pnlExistsHire;
	private: System::Windows::Forms::Button^ btnHire;
	private: System::Windows::Forms::DateTimePicker^ dateTimePickerCheckInExists;
	private: System::Windows::Forms::DateTimePicker^ dateTimePickerCheckOutExists;
	private: System::Windows::Forms::Label^ lblCheckOutDateExists;
	private: System::Windows::Forms::Label^ lblCheckInExists;
	private: System::Windows::Forms::Button^ btnBack;
	public:
		int roomNo;
		InsertCustomerCheck(void)
		{
			InitializeComponent();
			this->FormClosing += gcnew FormClosingEventHandler(this, &InsertCustomerCheck::MyForm_FormClosing);
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			//
			//TODO: Add the constructor code here
			//
		}
		InsertCustomerCheck(int roomNo, Form^ parentForm)
		{
			this->roomNo = roomNo;
			this->previousForm = parentForm;
			InitializeComponent();
			this->FormClosing += gcnew FormClosingEventHandler(this, &InsertCustomerCheck::MyForm_FormClosing);
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~InsertCustomerCheck()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lblTC;
	private: System::Windows::Forms::TextBox^ txtTC;
	private: System::Windows::Forms::Button^ btnTcOk;
	private: System::Windows::Forms::Panel^ pnlInsert;

	private: System::Windows::Forms::Label^ lblAge;

	private: System::Windows::Forms::Label^ lblSurname;

	private: System::Windows::Forms::Label^ lblName;
	private: System::Windows::Forms::Button^ btnInsert;
	private: System::Windows::Forms::TextBox^ txtAge;
	private: System::Windows::Forms::TextBox^ txtSurname;
	private: System::Windows::Forms::TextBox^ txtName;
	private: System::Windows::Forms::DateTimePicker^ dateTimePickerCheckOut;
	private: System::Windows::Forms::Label^ lblCheckOutDate;
	private: System::Windows::Forms::DateTimePicker^ dateTimePickerCheckIn;
	private: System::Windows::Forms::Label^ lblCheckInDate;

	protected:


	protected:

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
			this->lblTC = (gcnew System::Windows::Forms::Label());
			this->txtTC = (gcnew System::Windows::Forms::TextBox());
			this->btnTcOk = (gcnew System::Windows::Forms::Button());
			this->pnlInsert = (gcnew System::Windows::Forms::Panel());
			this->dateTimePickerCheckOut = (gcnew System::Windows::Forms::DateTimePicker());
			this->lblCheckOutDate = (gcnew System::Windows::Forms::Label());
			this->dateTimePickerCheckIn = (gcnew System::Windows::Forms::DateTimePicker());
			this->lblCheckInDate = (gcnew System::Windows::Forms::Label());
			this->btnInsert = (gcnew System::Windows::Forms::Button());
			this->txtAge = (gcnew System::Windows::Forms::TextBox());
			this->txtSurname = (gcnew System::Windows::Forms::TextBox());
			this->txtName = (gcnew System::Windows::Forms::TextBox());
			this->lblAge = (gcnew System::Windows::Forms::Label());
			this->lblSurname = (gcnew System::Windows::Forms::Label());
			this->lblName = (gcnew System::Windows::Forms::Label());
			this->pnlExistsHire = (gcnew System::Windows::Forms::Panel());
			this->btnHire = (gcnew System::Windows::Forms::Button());
			this->dateTimePickerCheckInExists = (gcnew System::Windows::Forms::DateTimePicker());
			this->dateTimePickerCheckOutExists = (gcnew System::Windows::Forms::DateTimePicker());
			this->lblCheckOutDateExists = (gcnew System::Windows::Forms::Label());
			this->lblCheckInExists = (gcnew System::Windows::Forms::Label());
			this->btnBack = (gcnew System::Windows::Forms::Button());
			this->pnlInsert->SuspendLayout();
			this->pnlExistsHire->SuspendLayout();
			this->SuspendLayout();
			// 
			// lblTC
			// 
			this->lblTC->AutoSize = true;
			this->lblTC->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->lblTC->Location = System::Drawing::Point(12, 76);
			this->lblTC->Name = L"lblTC";
			this->lblTC->Size = System::Drawing::Size(142, 20);
			this->lblTC->TabIndex = 0;
			this->lblTC->Text = L"Please enter TC:";
			// 
			// txtTC
			// 
			this->txtTC->Location = System::Drawing::Point(161, 76);
			this->txtTC->Name = L"txtTC";
			this->txtTC->Size = System::Drawing::Size(388, 20);
			this->txtTC->TabIndex = 1;
			// 
			// btnTcOk
			// 
			this->btnTcOk->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->btnTcOk->Location = System::Drawing::Point(602, 70);
			this->btnTcOk->Name = L"btnTcOk";
			this->btnTcOk->Size = System::Drawing::Size(143, 32);
			this->btnTcOk->TabIndex = 2;
			this->btnTcOk->Text = L"OK";
			this->btnTcOk->UseVisualStyleBackColor = true;
			this->btnTcOk->Click += gcnew System::EventHandler(this, &InsertCustomerCheck::btnTcOk_Click);
			// 
			// pnlInsert
			// 
			this->pnlInsert->Controls->Add(this->dateTimePickerCheckOut);
			this->pnlInsert->Controls->Add(this->lblCheckOutDate);
			this->pnlInsert->Controls->Add(this->dateTimePickerCheckIn);
			this->pnlInsert->Controls->Add(this->lblCheckInDate);
			this->pnlInsert->Controls->Add(this->btnInsert);
			this->pnlInsert->Controls->Add(this->txtAge);
			this->pnlInsert->Controls->Add(this->txtSurname);
			this->pnlInsert->Controls->Add(this->txtName);
			this->pnlInsert->Controls->Add(this->lblAge);
			this->pnlInsert->Controls->Add(this->lblSurname);
			this->pnlInsert->Controls->Add(this->lblName);
			this->pnlInsert->Location = System::Drawing::Point(16, 115);
			this->pnlInsert->Name = L"pnlInsert";
			this->pnlInsert->Size = System::Drawing::Size(435, 353);
			this->pnlInsert->TabIndex = 3;
			// 
			// dateTimePickerCheckOut
			// 
			this->dateTimePickerCheckOut->CalendarFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(162)));
			this->dateTimePickerCheckOut->Location = System::Drawing::Point(145, 259);
			this->dateTimePickerCheckOut->Name = L"dateTimePickerCheckOut";
			this->dateTimePickerCheckOut->Size = System::Drawing::Size(257, 20);
			this->dateTimePickerCheckOut->TabIndex = 9;
			// 
			// lblCheckOutDate
			// 
			this->lblCheckOutDate->AutoSize = true;
			this->lblCheckOutDate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->lblCheckOutDate->Location = System::Drawing::Point(3, 260);
			this->lblCheckOutDate->Name = L"lblCheckOutDate";
			this->lblCheckOutDate->Size = System::Drawing::Size(142, 20);
			this->lblCheckOutDate->TabIndex = 8;
			this->lblCheckOutDate->Text = L"Check Out Date:";
			// 
			// dateTimePickerCheckIn
			// 
			this->dateTimePickerCheckIn->CalendarFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(162)));
			this->dateTimePickerCheckIn->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dateTimePickerCheckIn->Location = System::Drawing::Point(145, 204);
			this->dateTimePickerCheckIn->Name = L"dateTimePickerCheckIn";
			this->dateTimePickerCheckIn->Size = System::Drawing::Size(257, 20);
			this->dateTimePickerCheckIn->TabIndex = 4;
			this->dateTimePickerCheckIn->Value = System::DateTime(2024, 9, 1, 16, 25, 8, 0);
			// 
			// lblCheckInDate
			// 
			this->lblCheckInDate->AutoSize = true;
			this->lblCheckInDate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->lblCheckInDate->Location = System::Drawing::Point(3, 204);
			this->lblCheckInDate->Name = L"lblCheckInDate";
			this->lblCheckInDate->Size = System::Drawing::Size(129, 20);
			this->lblCheckInDate->TabIndex = 7;
			this->lblCheckInDate->Text = L"Check In Date:";
			// 
			// btnInsert
			// 
			this->btnInsert->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->btnInsert->Location = System::Drawing::Point(256, 303);
			this->btnInsert->Name = L"btnInsert";
			this->btnInsert->Size = System::Drawing::Size(146, 35);
			this->btnInsert->TabIndex = 6;
			this->btnInsert->Text = L"Hire Room";
			this->btnInsert->UseVisualStyleBackColor = true;
			this->btnInsert->Click += gcnew System::EventHandler(this, &InsertCustomerCheck::btnInsert_Click);
			// 
			// txtAge
			// 
			this->txtAge->Location = System::Drawing::Point(107, 149);
			this->txtAge->Name = L"txtAge";
			this->txtAge->Size = System::Drawing::Size(295, 20);
			this->txtAge->TabIndex = 5;
			// 
			// txtSurname
			// 
			this->txtSurname->Location = System::Drawing::Point(107, 103);
			this->txtSurname->Name = L"txtSurname";
			this->txtSurname->Size = System::Drawing::Size(295, 20);
			this->txtSurname->TabIndex = 4;
			// 
			// txtName
			// 
			this->txtName->Location = System::Drawing::Point(107, 58);
			this->txtName->Name = L"txtName";
			this->txtName->Size = System::Drawing::Size(295, 20);
			this->txtName->TabIndex = 3;
			// 
			// lblAge
			// 
			this->lblAge->AutoSize = true;
			this->lblAge->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->lblAge->Location = System::Drawing::Point(4, 149);
			this->lblAge->Name = L"lblAge";
			this->lblAge->Size = System::Drawing::Size(46, 20);
			this->lblAge->TabIndex = 2;
			this->lblAge->Text = L"Age:";
			// 
			// lblSurname
			// 
			this->lblSurname->AutoSize = true;
			this->lblSurname->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->lblSurname->Location = System::Drawing::Point(3, 104);
			this->lblSurname->Name = L"lblSurname";
			this->lblSurname->Size = System::Drawing::Size(86, 20);
			this->lblSurname->TabIndex = 1;
			this->lblSurname->Text = L"Surname:";
			// 
			// lblName
			// 
			this->lblName->AutoSize = true;
			this->lblName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->lblName->Location = System::Drawing::Point(4, 59);
			this->lblName->Name = L"lblName";
			this->lblName->Size = System::Drawing::Size(60, 20);
			this->lblName->TabIndex = 0;
			this->lblName->Text = L"Name:";
			// 
			// pnlExistsHire
			// 
			this->pnlExistsHire->Controls->Add(this->btnHire);
			this->pnlExistsHire->Controls->Add(this->dateTimePickerCheckInExists);
			this->pnlExistsHire->Controls->Add(this->dateTimePickerCheckOutExists);
			this->pnlExistsHire->Controls->Add(this->lblCheckOutDateExists);
			this->pnlExistsHire->Controls->Add(this->lblCheckInExists);
			this->pnlExistsHire->Location = System::Drawing::Point(505, 115);
			this->pnlExistsHire->Name = L"pnlExistsHire";
			this->pnlExistsHire->Size = System::Drawing::Size(440, 353);
			this->pnlExistsHire->TabIndex = 4;
			// 
			// btnHire
			// 
			this->btnHire->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->btnHire->Location = System::Drawing::Point(286, 149);
			this->btnHire->Name = L"btnHire";
			this->btnHire->Size = System::Drawing::Size(116, 30);
			this->btnHire->TabIndex = 4;
			this->btnHire->Text = L"Hire Room";
			this->btnHire->UseVisualStyleBackColor = true;
			this->btnHire->Click += gcnew System::EventHandler(this, &InsertCustomerCheck::btnHire_Click);
			// 
			// dateTimePickerCheckInExists
			// 
			this->dateTimePickerCheckInExists->Location = System::Drawing::Point(161, 64);
			this->dateTimePickerCheckInExists->Name = L"dateTimePickerCheckInExists";
			this->dateTimePickerCheckInExists->Size = System::Drawing::Size(241, 20);
			this->dateTimePickerCheckInExists->TabIndex = 3;
			// 
			// dateTimePickerCheckOutExists
			// 
			this->dateTimePickerCheckOutExists->Location = System::Drawing::Point(161, 109);
			this->dateTimePickerCheckOutExists->Name = L"dateTimePickerCheckOutExists";
			this->dateTimePickerCheckOutExists->Size = System::Drawing::Size(241, 20);
			this->dateTimePickerCheckOutExists->TabIndex = 2;
			// 
			// lblCheckOutDateExists
			// 
			this->lblCheckOutDateExists->AutoSize = true;
			this->lblCheckOutDateExists->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->lblCheckOutDateExists->Location = System::Drawing::Point(12, 110);
			this->lblCheckOutDateExists->Name = L"lblCheckOutDateExists";
			this->lblCheckOutDateExists->Size = System::Drawing::Size(142, 20);
			this->lblCheckOutDateExists->TabIndex = 1;
			this->lblCheckOutDateExists->Text = L"Check Out Date:";
			// 
			// lblCheckInExists
			// 
			this->lblCheckInExists->AutoSize = true;
			this->lblCheckInExists->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->lblCheckInExists->Location = System::Drawing::Point(8, 65);
			this->lblCheckInExists->Name = L"lblCheckInExists";
			this->lblCheckInExists->Size = System::Drawing::Size(129, 20);
			this->lblCheckInExists->TabIndex = 0;
			this->lblCheckInExists->Text = L"Check In Date:";
			// 
			// btnBack
			// 
			this->btnBack->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->btnBack->Location = System::Drawing::Point(791, 543);
			this->btnBack->Name = L"btnBack";
			this->btnBack->Size = System::Drawing::Size(138, 38);
			this->btnBack->TabIndex = 5;
			this->btnBack->Text = L"Back";
			this->btnBack->UseVisualStyleBackColor = true;
			this->btnBack->Click += gcnew System::EventHandler(this, &InsertCustomerCheck::btnBack_Click);
			// 
			// InsertCustomerCheck
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(957, 593);
			this->Controls->Add(this->btnBack);
			this->Controls->Add(this->pnlExistsHire);
			this->Controls->Add(this->pnlInsert);
			this->Controls->Add(this->btnTcOk);
			this->Controls->Add(this->txtTC);
			this->Controls->Add(this->lblTC);
			this->Name = L"InsertCustomerCheck";
			this->Text = L"HireRoom";
			this->Load += gcnew System::EventHandler(this, &InsertCustomerCheck::HireRoom_Load);
			this->pnlInsert->ResumeLayout(false);
			this->pnlInsert->PerformLayout();
			this->pnlExistsHire->ResumeLayout(false);
			this->pnlExistsHire->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void btnTcOk_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ tc = txtTC->Text;
		// Alýnan metni insertCustomerCheck fonksiyonuna gönderiyoruz
		connectDB();
		int result = insertCustomerCheck(tc);

		// Sonuca göre mesaj kutusu gösteriyoruz
		if (result == 0) {
			MessageBox::Show("Customer already exists!");
			this->pnlExistsHire->Show();
		}
		else if (result == -1) {
			MessageBox::Show("Customer doesn't exist!");
			this->pnlInsert->Show();
		}
		else {
			MessageBox::Show("Customer already have a room! Room No: "+result.ToString());
			previousForm->Show();
			this->Hide();
		}
	}

private: System::Void btnInsert_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ tc = txtTC->Text;
	String^ name = txtName->Text;
	String^ surname = txtSurname->Text;
	int age = Convert::ToInt32(txtAge->Text);
	String^ entryDate = dateTimePickerCheckIn->Text;
	String^ lastDate = dateTimePickerCheckOut->Text;

	insertCustomer(tc, name, surname, age);
	int result=hireRoom(tc, roomNo, entryDate, lastDate);

	if (result == 0) {
		totalCost(tc, roomNo);
		this->Hide();
		previousForm->Show();
		
	}
	
}
private: System::Void HireRoom_Load(System::Object^ sender, System::EventArgs^ e) {
	this->pnlInsert->Hide();
	this->pnlExistsHire->Hide();
	dateTimePickerCheckIn->MinDate = DateTime::Today;
	dateTimePickerCheckOut->MinDate = dateTimePickerCheckIn->Value.AddDays(1);

	dateTimePickerCheckIn->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
	dateTimePickerCheckIn->CustomFormat = "yyyy-MM-dd";

	dateTimePickerCheckOut->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
	dateTimePickerCheckOut->CustomFormat = "yyyy-MM-dd";

	dateTimePickerCheckInExists->MinDate = DateTime::Today;
	dateTimePickerCheckOutExists->MinDate = dateTimePickerCheckInExists->Value.AddDays(1);

	dateTimePickerCheckInExists->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
	dateTimePickerCheckInExists->CustomFormat = "yyyy-MM-dd";

	dateTimePickerCheckOutExists->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
	dateTimePickerCheckOutExists->CustomFormat = "yyyy-MM-dd";

}
private: System::Void MyForm_FormClosing(System::Object^ sender, FormClosingEventArgs^ e) {
	Application::Exit(); // Uygulamayý tamamen kapatýr
}

private: System::Void btnHire_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ entryDate = dateTimePickerCheckInExists->Text;
	String^ lastDate = dateTimePickerCheckOutExists->Text;
	String^ tc = txtTC->Text;

	int result = hireRoom(tc, roomNo, entryDate, lastDate);

	if (result == 0) {
		totalCost(tc, roomNo);
		this->Hide();
		previousForm->Show();

	}
	else {
		pnlExistsHire->Hide();
	}
	
}
private: System::Void btnBack_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	previousForm->Show();
	
}
};
}
