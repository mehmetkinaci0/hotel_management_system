#pragma once
#include "CustomerRoomInfo.h"
#include "CustomerJoinActivity.h"
#include "CustomerActivityList.h"

namespace HotelManagementSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for CustomerEntry
	/// </summary>
	public ref class CustomerEntry : public System::Windows::Forms::Form
	{
	public:
		Form^ previousForm;
		CustomerEntry(Form^ previousForm)
		{
			this->previousForm = previousForm;
			InitializeComponent();
			this->FormClosing += gcnew FormClosingEventHandler(this, &CustomerEntry::MyForm_FormClosing);
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~CustomerEntry()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	protected:
	private: System::Windows::Forms::Button^ btnRoomInfo;
	private: System::Windows::Forms::Button^ btnActivity;
	private: System::Windows::Forms::Button^ btnMyActivity;
	private: System::Windows::Forms::Button^ btnBack;

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
			this->btnRoomInfo = (gcnew System::Windows::Forms::Button());
			this->btnActivity = (gcnew System::Windows::Forms::Button());
			this->btnMyActivity = (gcnew System::Windows::Forms::Button());
			this->btnBack = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->Controls->Add(this->btnRoomInfo, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->btnActivity, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->btnMyActivity, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->btnBack, 0, 4);
			this->tableLayoutPanel1->Location = System::Drawing::Point(295, 103);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 5;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50.83333F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 49.16667F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 57)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 62)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 41)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(331, 294);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// btnRoomInfo
			// 
			this->btnRoomInfo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->btnRoomInfo->Location = System::Drawing::Point(3, 3);
			this->btnRoomInfo->Name = L"btnRoomInfo";
			this->btnRoomInfo->Size = System::Drawing::Size(325, 62);
			this->btnRoomInfo->TabIndex = 0;
			this->btnRoomInfo->Text = L"Room Info";
			this->btnRoomInfo->UseVisualStyleBackColor = true;
			this->btnRoomInfo->Click += gcnew System::EventHandler(this, &CustomerEntry::btnRoomInfo_Click);
			// 
			// btnActivity
			// 
			this->btnActivity->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->btnActivity->Location = System::Drawing::Point(3, 71);
			this->btnActivity->Name = L"btnActivity";
			this->btnActivity->Size = System::Drawing::Size(325, 59);
			this->btnActivity->TabIndex = 1;
			this->btnActivity->Text = L"Join Activity";
			this->btnActivity->UseVisualStyleBackColor = true;
			this->btnActivity->Click += gcnew System::EventHandler(this, &CustomerEntry::btnActivity_Click);
			// 
			// btnMyActivity
			// 
			this->btnMyActivity->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->btnMyActivity->Location = System::Drawing::Point(3, 136);
			this->btnMyActivity->Name = L"btnMyActivity";
			this->btnMyActivity->Size = System::Drawing::Size(325, 51);
			this->btnMyActivity->TabIndex = 2;
			this->btnMyActivity->Text = L"My Activities";
			this->btnMyActivity->UseVisualStyleBackColor = true;
			this->btnMyActivity->Click += gcnew System::EventHandler(this, &CustomerEntry::btnMyActivity_Click);
			// 
			// btnBack
			// 
			this->btnBack->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->btnBack->Location = System::Drawing::Point(3, 255);
			this->btnBack->Name = L"btnBack";
			this->btnBack->Size = System::Drawing::Size(325, 36);
			this->btnBack->TabIndex = 3;
			this->btnBack->Text = L"Back";
			this->btnBack->UseVisualStyleBackColor = true;
			this->btnBack->Click += gcnew System::EventHandler(this, &CustomerEntry::btnBack_Click);
			// 
			// CustomerEntry
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(939, 692);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"CustomerEntry";
			this->Text = L"CustomerEntry";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void MyForm_FormClosing(System::Object^ sender, FormClosingEventArgs^ e) {
		Application::Exit(); // Uygulamayý tamamen kapatýr
	}


	private: System::Void btnRoomInfo_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		CustomerRoomInfo^ info = gcnew CustomerRoomInfo(this);
		info->Show();
	}
private: System::Void btnBack_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	previousForm->Show();
}
private: System::Void btnActivity_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	CustomerJoinActivity^ join = gcnew  CustomerJoinActivity(this);
	join->Show();
}
private: System::Void btnMyActivity_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	CustomerActivityList^ list = gcnew CustomerActivityList(this);
	list->Show();
}
};
}
