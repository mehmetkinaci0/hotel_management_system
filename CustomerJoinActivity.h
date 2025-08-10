#pragma once
#include "functions.h"
namespace HotelManagementSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for CustomerJoinActivity
	/// </summary>
	public ref class CustomerJoinActivity : public System::Windows::Forms::Form
	{
	public:
		Form^ previousForm;
		CustomerJoinActivity(Form^ previousForm)
		{
			this->previousForm = previousForm;
			InitializeComponent();
			this->FormClosing += gcnew FormClosingEventHandler(this, &CustomerJoinActivity::MyForm_FormClosing);
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~CustomerJoinActivity()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridViewActivities;
	private: System::Windows::Forms::Label^ lblTc;
	private: System::Windows::Forms::TextBox^ txtTc;
	private: System::Windows::Forms::Button^ btnJoin;
	private: System::Windows::Forms::Button^ btnBack;
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
			this->dataGridViewActivities = (gcnew System::Windows::Forms::DataGridView());
			this->lblTc = (gcnew System::Windows::Forms::Label());
			this->txtTc = (gcnew System::Windows::Forms::TextBox());
			this->btnJoin = (gcnew System::Windows::Forms::Button());
			this->btnBack = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewActivities))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridViewActivities
			// 
			this->dataGridViewActivities->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewActivities->Location = System::Drawing::Point(36, 135);
			this->dataGridViewActivities->Name = L"dataGridViewActivities";
			this->dataGridViewActivities->Size = System::Drawing::Size(1079, 513);
			this->dataGridViewActivities->TabIndex = 0;
			// 
			// lblTc
			// 
			this->lblTc->AutoSize = true;
			this->lblTc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->lblTc->Location = System::Drawing::Point(36, 51);
			this->lblTc->Name = L"lblTc";
			this->lblTc->Size = System::Drawing::Size(181, 20);
			this->lblTc->TabIndex = 1;
			this->lblTc->Text = L"Please enter your TC:";
			// 
			// txtTc
			// 
			this->txtTc->Location = System::Drawing::Point(224, 50);
			this->txtTc->Name = L"txtTc";
			this->txtTc->Size = System::Drawing::Size(463, 20);
			this->txtTc->TabIndex = 2;
			// 
			// btnJoin
			// 
			this->btnJoin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->btnJoin->Location = System::Drawing::Point(733, 39);
			this->btnJoin->Name = L"btnJoin";
			this->btnJoin->Size = System::Drawing::Size(124, 43);
			this->btnJoin->TabIndex = 3;
			this->btnJoin->Text = L"Join";
			this->btnJoin->UseVisualStyleBackColor = true;
			this->btnJoin->Click += gcnew System::EventHandler(this, &CustomerJoinActivity::btnJoin_Click);
			// 
			// btnBack
			// 
			this->btnBack->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->btnBack->Location = System::Drawing::Point(894, 39);
			this->btnBack->Name = L"btnBack";
			this->btnBack->Size = System::Drawing::Size(110, 43);
			this->btnBack->TabIndex = 4;
			this->btnBack->Text = L"Back";
			this->btnBack->UseVisualStyleBackColor = true;
			this->btnBack->Click += gcnew System::EventHandler(this, &CustomerJoinActivity::btnBack_Click);
			// 
			// CustomerJoinActivity
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1484, 684);
			this->Controls->Add(this->btnBack);
			this->Controls->Add(this->btnJoin);
			this->Controls->Add(this->txtTc);
			this->Controls->Add(this->lblTc);
			this->Controls->Add(this->dataGridViewActivities);
			this->Name = L"CustomerJoinActivity";
			this->Text = L"CustomerJoinActivity";
			this->Load += gcnew System::EventHandler(this, &CustomerJoinActivity::CustomerJoinActivity_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewActivities))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		void ResizeDataGridViewToFitContent(DataGridView^ dataGridView) {
			// Sütun geniþliklerini ve satýr yüksekliklerini otomatik olarak ayarla
			dataGridView->AutoResizeColumns(DataGridViewAutoSizeColumnsMode::AllCells);
			dataGridView->AutoResizeRows(DataGridViewAutoSizeRowsMode::AllCells);

			// Toplam geniþliði ve yüksekliði hesapla
			int totalWidth = 0;
			for each (DataGridViewColumn ^ column in dataGridView->Columns) {
				totalWidth += column->Width;
			}

			int totalHeight = 0;
			for each (DataGridViewRow ^ row in dataGridView->Rows) {
				totalHeight += row->Height;
			}

			// Header eklenmiþse onun boyutunu da ekle
			if (dataGridView->ColumnHeadersVisible) {
				totalHeight += dataGridView->ColumnHeadersHeight;
			}
			if (dataGridView->RowHeadersVisible) {
				totalWidth += dataGridView->RowHeadersWidth;
			}

			// Scroll barlarý hesaba katmak için ek geniþlik ve yükseklik ekle
			int scrollBarWidth = SystemInformation::VerticalScrollBarWidth;
			int scrollBarHeight = SystemInformation::HorizontalScrollBarHeight;

			// DataGridView boyutunu güncelle
			dataGridView->Width = totalWidth + scrollBarWidth;
			dataGridView->Height = totalHeight + scrollBarHeight;

			// DataGridView panelde veya formda, varsa, ortalanabilir veya belli bir düzene göre konumlandýrýlabilir.
			dataGridView->Refresh();
		}
	private: System::Void CustomerJoinActivity_Load(System::Object^ sender, System::EventArgs^ e) {
		dataGridViewActivities->AllowUserToAddRows = false;
		dataGridViewActivities->AllowUserToDeleteRows = false;
		dataGridViewActivities->ReadOnly = true;
		showHotelActivities(dataGridViewActivities);
		ResizeDataGridViewToFitContent(dataGridViewActivities);
		dataGridViewActivities->ClearSelection();
	}


	private: System::Void MyForm_FormClosing(System::Object^ sender, FormClosingEventArgs^ e) {
		Application::Exit(); // Uygulamayý tamamen kapatýr
	}
	private: System::Void btnJoin_Click(System::Object^ sender, System::EventArgs^ e) {

		// Öncelikle seçili hücrenin olup olmadýðýný kontrol edin
		if (dataGridViewActivities->SelectedCells->Count > 0) {
			// Seçili hücreyi alýn
			DataGridViewCell^ selectedCell = dataGridViewActivities->SelectedCells[0];

			// Seçili hücrenin bulunduðu satýrý alýn
			DataGridViewRow^ selectedRow = selectedCell->OwningRow;

			// Seçili hücrenin sütun indeksini alýn
			int columnIndex = selectedCell->ColumnIndex;

			Object^ cellValueObj = selectedRow->Cells[columnIndex]->Value;

			if (cellValueObj != nullptr) {
				if (!String::IsNullOrEmpty(txtTc->Text)) {
					if (insertCustomerCheck(txtTc->Text) != 0 && insertCustomerCheck(txtTc->Text) != -1) {
						int activity_id = Convert::ToInt32(selectedRow->Cells[columnIndex]->Value->ToString());
						String^ name = selectedRow->Cells[columnIndex + 1]->Value->ToString();
						String^ activityDate = selectedRow->Cells[columnIndex + 3]->Value->ToString();
						int participants = Convert::ToInt32(selectedRow->Cells[columnIndex + 4]->Value->ToString());
						String^ tc = txtTc->Text;
						joinActivity(tc, activity_id, name, activityDate, participants);
						showHotelActivities(dataGridViewActivities);
						ResizeDataGridViewToFitContent(dataGridViewActivities);
						txtTc->ResetText();
						dataGridViewActivities->ClearSelection();
					}
					else {
						MessageBox::Show("You don't have a room!");
					}
					
				}
				else {
					MessageBox::Show("Please enter your TC!");
				}
				
			}
			else {
				MessageBox::Show("The selected cell is empty or null.");
			}

		}
		else {
			MessageBox::Show("No activity is selected.");
		}

	}
private: System::Void btnBack_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	previousForm->Show();
}
};
}
