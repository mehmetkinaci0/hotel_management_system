#pragma once
#include "functions.h"
#include "HireRoom.h"
#include "CheckOut.h"
#include "ShowRoomsInfo.h"
#include "ShowHotelMoney.h"
#include "ShowWorkers.h"
namespace HotelManagementSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Summary for AdminEntry
	/// </summary>
	public ref class AdminEntry : public System::Windows::Forms::Form
	{
	private:
		System::Windows::Forms::Form^ previousForm;
	public:
		AdminEntry(System::Windows::Forms::Form^ previousForm)
		{
			this->previousForm = previousForm;
			InitializeComponent();
			this->FormClosing += gcnew FormClosingEventHandler(this, &AdminEntry::MyForm_FormClosing);
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AdminEntry()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	protected:
	private: System::Windows::Forms::Button^ btnHireRoom;
	private: System::Windows::Forms::Button^ btnEmptyRoom;

	private: System::Windows::Forms::Button^ btnBack;
	private: System::Windows::Forms::Button^ btnShowRooms;
	private: System::Windows::Forms::Button^ btnBudget;
	private: System::Windows::Forms::Button^ btnWorkers;


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
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->btnHireRoom = (gcnew System::Windows::Forms::Button());
			this->btnEmptyRoom = (gcnew System::Windows::Forms::Button());
			this->btnShowRooms = (gcnew System::Windows::Forms::Button());
			this->btnBudget = (gcnew System::Windows::Forms::Button());
			this->btnBack = (gcnew System::Windows::Forms::Button());
			this->btnWorkers = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->Controls->Add(this->btnHireRoom, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->btnEmptyRoom, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->btnShowRooms, 0, 3);
			this->tableLayoutPanel1->Controls->Add(this->btnBudget, 0, 4);
			this->tableLayoutPanel1->Controls->Add(this->btnWorkers, 0, 5);
			this->tableLayoutPanel1->Location = System::Drawing::Point(230, 65);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 7;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 75)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 69)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 54)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 53)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 76)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(331, 368);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// btnHireRoom
			// 
			this->btnHireRoom->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->btnHireRoom->Location = System::Drawing::Point(3, 3);
			this->btnHireRoom->Name = L"btnHireRoom";
			this->btnHireRoom->Size = System::Drawing::Size(325, 69);
			this->btnHireRoom->TabIndex = 0;
			this->btnHireRoom->Text = L"Check In";
			this->btnHireRoom->UseVisualStyleBackColor = true;
			this->btnHireRoom->Click += gcnew System::EventHandler(this, &AdminEntry::btnHireRoom_Click);
			// 
			// btnEmptyRoom
			// 
			this->btnEmptyRoom->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->btnEmptyRoom->Location = System::Drawing::Point(3, 78);
			this->btnEmptyRoom->Name = L"btnEmptyRoom";
			this->btnEmptyRoom->Size = System::Drawing::Size(325, 63);
			this->btnEmptyRoom->TabIndex = 1;
			this->btnEmptyRoom->Text = L"Check Out";
			this->btnEmptyRoom->UseVisualStyleBackColor = true;
			this->btnEmptyRoom->Click += gcnew System::EventHandler(this, &AdminEntry::btnEmptyRoom_Click);
			// 
			// btnShowRooms
			// 
			this->btnShowRooms->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->btnShowRooms->Location = System::Drawing::Point(3, 147);
			this->btnShowRooms->Name = L"btnShowRooms";
			this->btnShowRooms->Size = System::Drawing::Size(325, 35);
			this->btnShowRooms->TabIndex = 2;
			this->btnShowRooms->Text = L"Show Rooms";
			this->btnShowRooms->UseVisualStyleBackColor = true;
			this->btnShowRooms->Click += gcnew System::EventHandler(this, &AdminEntry::btnShowRooms_Click);
			// 
			// btnBudget
			// 
			this->btnBudget->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->btnBudget->Location = System::Drawing::Point(3, 188);
			this->btnBudget->Name = L"btnBudget";
			this->btnBudget->Size = System::Drawing::Size(325, 48);
			this->btnBudget->TabIndex = 3;
			this->btnBudget->Text = L"Show Budget";
			this->btnBudget->UseVisualStyleBackColor = true;
			this->btnBudget->Click += gcnew System::EventHandler(this, &AdminEntry::btnBudget_Click);
			// 
			// btnBack
			// 
			this->btnBack->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->btnBack->Location = System::Drawing::Point(230, 439);
			this->btnBack->Name = L"btnBack";
			this->btnBack->Size = System::Drawing::Size(325, 55);
			this->btnBack->TabIndex = 3;
			this->btnBack->Text = L"Back";
			this->btnBack->UseVisualStyleBackColor = true;
			this->btnBack->Click += gcnew System::EventHandler(this, &AdminEntry::btnBack_Click);
			// 
			// btnWorkers
			// 
			this->btnWorkers->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->btnWorkers->Location = System::Drawing::Point(3, 242);
			this->btnWorkers->Name = L"btnWorkers";
			this->btnWorkers->Size = System::Drawing::Size(325, 47);
			this->btnWorkers->TabIndex = 4;
			this->btnWorkers->Text = L"Show Workers";
			this->btnWorkers->UseVisualStyleBackColor = true;
			this->btnWorkers->Click += gcnew System::EventHandler(this, &AdminEntry::btnWorkers_Click);
			// 
			// AdminEntry
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(806, 590);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->btnBack);
			this->Name = L"AdminEntry";
			this->Text = L"AdminEntry";
			this->Load += gcnew System::EventHandler(this, &AdminEntry::AdminEntry_Load);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->ResumeLayout(false);

		}


#pragma endregion
	private: System::Void MyForm_FormClosing(System::Object^ sender, FormClosingEventArgs^ e) {
		Application::Exit(); // Uygulamayý tamamen kapatýr
	}

	private: System::Void AdminEntry_Load(System::Object^ sender, System::EventArgs^ e) {
		connectDB();
	}
	private: System::Void btnHireRoom_Click(System::Object^ sender, System::EventArgs^ e) {
		HireRoom^ hireRoom = gcnew HireRoom(this);
		hireRoom->Show();

		this->Hide();
	}

private: System::Void btnBack_Click(System::Object^ sender, System::EventArgs^ e) {
	previousForm->Show();
	this->Hide();
}

private: System::Void btnEmptyRoom_Click(System::Object^ sender, System::EventArgs^ e) {
	CheckOut^ checkOut = gcnew CheckOut(this);
	checkOut->Show();
	this->Hide();
}
private: System::Void btnShowRooms_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	ShowRoomsInfo^ info = gcnew ShowRoomsInfo(this);
	info->Show();
}
private: System::Void btnBudget_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	ShowHotelMoney^ money = gcnew ShowHotelMoney(this);
	money->Show();
}
private: System::Void btnWorkers_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	ShowWorkers^ workers = gcnew ShowWorkers(this);
	workers->Show();
}
};
	}
