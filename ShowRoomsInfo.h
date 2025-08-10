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
	/// Summary for ShowRoomsInfo
	/// </summary>
	public ref class ShowRoomsInfo : public System::Windows::Forms::Form
	{
	public:
		Form^ previousForm;
		ShowRoomsInfo(void)
		{
			InitializeComponent();
			this->FormClosing += gcnew FormClosingEventHandler(this, &ShowRoomsInfo::MyForm_FormClosing);
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			LoadRoomStatuses();
			totalNumbers();
			//
			//TODO: Add the constructor code here
			//
		}
		ShowRoomsInfo(Form^ previousForm)
		{
			this->previousForm = previousForm;
			InitializeComponent();
			this->FormClosing += gcnew FormClosingEventHandler(this, &ShowRoomsInfo::MyForm_FormClosing);
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			LoadRoomStatuses();
			totalNumbers();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ShowRoomsInfo()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
	private:
		System::Windows::Forms::Panel^ panelRooms;
	private: System::Windows::Forms::Label^ lblRooms;
	private: System::Windows::Forms::Label^ lblEmpty;
	private: System::Windows::Forms::Label^ lblFull;
	private: System::Windows::Forms::Button^ btnBack;



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
			this->lblRooms = (gcnew System::Windows::Forms::Label());
			this->lblEmpty = (gcnew System::Windows::Forms::Label());
			this->lblFull = (gcnew System::Windows::Forms::Label());
			this->btnBack = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// panelRooms
			// 
			this->panelRooms->Location = System::Drawing::Point(10, 10);
			this->panelRooms->Name = L"panelRooms";
			this->panelRooms->Size = System::Drawing::Size(1099, 500);
			this->panelRooms->TabIndex = 0;
			// 
			// lblRooms
			// 
			this->lblRooms->AutoSize = true;
			this->lblRooms->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->lblRooms->Location = System::Drawing::Point(1125, 15);
			this->lblRooms->Name = L"lblRooms";
			this->lblRooms->Size = System::Drawing::Size(115, 20);
			this->lblRooms->TabIndex = 1;
			this->lblRooms->Text = L"Total Rooms:";
			// 
			// lblEmpty
			// 
			this->lblEmpty->AutoSize = true;
			this->lblEmpty->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->lblEmpty->Location = System::Drawing::Point(1125, 64);
			this->lblEmpty->Name = L"lblEmpty";
			this->lblEmpty->Size = System::Drawing::Size(125, 20);
			this->lblEmpty->TabIndex = 2;
			this->lblEmpty->Text = L"Empty Rooms:";
			// 
			// lblFull
			// 
			this->lblFull->AutoSize = true;
			this->lblFull->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->lblFull->Location = System::Drawing::Point(1125, 109);
			this->lblFull->Name = L"lblFull";
			this->lblFull->Size = System::Drawing::Size(104, 20);
			this->lblFull->TabIndex = 3;
			this->lblFull->Text = L"Full Rooms:";
			// 
			// btnBack
			// 
			this->btnBack->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->btnBack->Location = System::Drawing::Point(978, 540);
			this->btnBack->Name = L"btnBack";
			this->btnBack->Size = System::Drawing::Size(131, 40);
			this->btnBack->TabIndex = 4;
			this->btnBack->Text = L"Back";
			this->btnBack->UseVisualStyleBackColor = true;
			this->btnBack->Click += gcnew System::EventHandler(this, &ShowRoomsInfo::btnBack_Click);
			// 
			// ShowRoomsInfo
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1368, 665);
			this->Controls->Add(this->btnBack);
			this->Controls->Add(this->lblFull);
			this->Controls->Add(this->lblEmpty);
			this->Controls->Add(this->lblRooms);
			this->Controls->Add(this->panelRooms);
			this->Name = L"ShowRoomsInfo";
			this->Text = L"ShowRoomsInfo";
			this->ResumeLayout(false);
			this->PerformLayout();

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
				button->Click += gcnew EventHandler(this, &ShowRoomsInfo::OnRoomButtonClick);
			}
			else if (status == "empty")
			{
				button->BackColor = Color::Green;
				
			}
		}

		void totalNumbers() {
			int room, empty, full;
			String^ query1 = "SELECT Count(*) FROM Hotel Where status = 'Empty'";
			String^ query2 = "SELECT Count(*) FROM Hotel";
			MySqlConnection^ conn = gcnew MySqlConnection("Server=localhost;port=3306;database=hoteldb;uid=root;password=mehmetknc2720");
			MySqlCommand^ cmd = gcnew MySqlCommand(query1, conn);

			try {
				conn->Open();
				MySqlDataReader^ reader = cmd->ExecuteReader();

				while (reader->Read()) {
					empty = Convert::ToInt32(reader[0]) - 1;

				}
				reader->Close();
				cmd = gcnew MySqlCommand(query2, conn);
				reader = cmd->ExecuteReader();

				while (reader->Read()) {
					room = Convert::ToInt32(reader[0]) - 1;

				}
				full = room - empty;
				lblRooms->AutoSize = true;
				lblRooms->Text = "Total Rooms: " + room.ToString();

				lblEmpty->AutoSize = true;
				lblEmpty->Text = "Empty Rooms: " + empty.ToString();

				lblFull->AutoSize = true;
				lblFull->Text = "Full Rooms: " + full.ToString();

			}
			catch (Exception^ e) {
				Console::WriteLine("Query failed: " + e->Message);
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


		System::Void MyForm_FormClosing(System::Object^ sender, FormClosingEventArgs^ e) {
			Application::Exit(); // Uygulamayý tamamen kapatýr
		}

private: System::Void btnBack_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	previousForm->Show();
}
};
}
