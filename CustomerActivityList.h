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
	/// Summary for CustomerActivityList
	/// </summary>
	public ref class CustomerActivityList : public System::Windows::Forms::Form
	{
	public:
		Form^ previousForm;
		CustomerActivityList(Form^ previousForm)
		{
			this->previousForm = previousForm;
			InitializeComponent();
			this->FormClosing += gcnew FormClosingEventHandler(this, &CustomerActivityList::MyForm_FormClosing);
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~CustomerActivityList()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridViewActivity;
	protected:
	private: System::Windows::Forms::Label^ lblTc;
	private: System::Windows::Forms::TextBox^ txtTc;

	private: System::Windows::Forms::Button^ btnOk;
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
			this->dataGridViewActivity = (gcnew System::Windows::Forms::DataGridView());
			this->lblTc = (gcnew System::Windows::Forms::Label());
			this->txtTc = (gcnew System::Windows::Forms::TextBox());
			this->btnOk = (gcnew System::Windows::Forms::Button());
			this->btnBack = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewActivity))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridViewActivity
			// 
			this->dataGridViewActivity->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewActivity->Location = System::Drawing::Point(41, 108);
			this->dataGridViewActivity->Name = L"dataGridViewActivity";
			this->dataGridViewActivity->Size = System::Drawing::Size(570, 430);
			this->dataGridViewActivity->TabIndex = 0;
			// 
			// lblTc
			// 
			this->lblTc->AutoSize = true;
			this->lblTc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->lblTc->Location = System::Drawing::Point(41, 40);
			this->lblTc->Name = L"lblTc";
			this->lblTc->Size = System::Drawing::Size(181, 20);
			this->lblTc->TabIndex = 1;
			this->lblTc->Text = L"Please enter your TC:";
			// 
			// txtTc
			// 
			this->txtTc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->txtTc->Location = System::Drawing::Point(229, 39);
			this->txtTc->Name = L"txtTc";
			this->txtTc->Size = System::Drawing::Size(382, 26);
			this->txtTc->TabIndex = 2;
			// 
			// btnOk
			// 
			this->btnOk->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->btnOk->Location = System::Drawing::Point(639, 32);
			this->btnOk->Name = L"btnOk";
			this->btnOk->Size = System::Drawing::Size(101, 33);
			this->btnOk->TabIndex = 3;
			this->btnOk->Text = L"OK";
			this->btnOk->UseVisualStyleBackColor = true;
			this->btnOk->Click += gcnew System::EventHandler(this, &CustomerActivityList::btnOk_Click);
			// 
			// btnBack
			// 
			this->btnBack->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->btnBack->Location = System::Drawing::Point(772, 32);
			this->btnBack->Name = L"btnBack";
			this->btnBack->Size = System::Drawing::Size(101, 33);
			this->btnBack->TabIndex = 4;
			this->btnBack->Text = L"Back";
			this->btnBack->UseVisualStyleBackColor = true;
			this->btnBack->Click += gcnew System::EventHandler(this, &CustomerActivityList::btnBack_Click);
			// 
			// CustomerActivityList
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1070, 649);
			this->Controls->Add(this->btnBack);
			this->Controls->Add(this->btnOk);
			this->Controls->Add(this->txtTc);
			this->Controls->Add(this->lblTc);
			this->Controls->Add(this->dataGridViewActivity);
			this->Name = L"CustomerActivityList";
			this->Text = L"CustomerActivityList";
			this->Load += gcnew System::EventHandler(this, &CustomerActivityList::CustomerActivityList_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewActivity))->EndInit();
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
	private: System::Void btnOk_Click(System::Object^ sender, System::EventArgs^ e) {
		int result = insertCustomerCheck(txtTc->Text);
		if (result == 0) {
			MessageBox::Show("You don't have a room!");
		}
		else if (result == -1) {
			MessageBox::Show("You are not our customer!");
		}
		else {
			if (showCustomerActivities(txtTc->Text, dataGridViewActivity)) {
				dataGridViewActivity->Show();
				ResizeDataGridViewToFitContent(dataGridViewActivity);
				dataGridViewActivity->ClearSelection();

				System::Drawing::Size dataGridSize = dataGridViewActivity->Size;

				// Butonun yerleþtirileceði koordinatlar
				int x = dataGridViewActivity->Location.X + dataGridSize.Width + 20;
				int y = dataGridViewActivity->Location.Y;

				Button^ btnDelete = gcnew Button();
				btnDelete->Size = System::Drawing::Size(120, 50);
				btnDelete->Location = System::Drawing::Point(x, y);
				btnDelete->Text = "Delete";
				btnDelete->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(162)));
				btnDelete->Click += gcnew EventHandler(this, &CustomerActivityList::OnRoomButtonClick);
				this->Controls->Add(btnDelete);
			}
			
		}
	}
	private: System::Void OnRoomButtonClick(Object^ sender, EventArgs^ e)
	{
		Button^ btnDelete = safe_cast<Button^>(sender);
		// Öncelikle seçili hücrenin olup olmadýðýný kontrol edin
		if (dataGridViewActivity->SelectedCells->Count > 0) {
			// Seçili hücreyi alýn
			DataGridViewCell^ selectedCell = dataGridViewActivity->SelectedCells[0];

			// Seçili hücrenin bulunduðu satýrý alýn
			DataGridViewRow^ selectedRow = selectedCell->OwningRow;

			// Seçili hücrenin sütun indeksini alýn
			int columnIndex = selectedCell->ColumnIndex;

			Object^ cellValueObj = selectedRow->Cells[columnIndex]->Value;

			if (cellValueObj != nullptr) {

				String^ name = selectedRow->Cells[columnIndex]->Value->ToString();

				String^ tc = txtTc->Text;

				deleteCustomerActivity(tc, name);
				ResizeDataGridViewToFitContent(dataGridViewActivity);
				txtTc->ResetText();
				dataGridViewActivity->Hide();
				dataGridViewActivity->ClearSelection();
				btnDelete->Hide();
				this->Controls->Remove(btnDelete);
			}
			else {
				MessageBox::Show("The selected cell is empty or null.");
			}

		}
		else {
			MessageBox::Show("No activity is selected.");
		}
	}
	private: System::Void CustomerActivityList_Load(System::Object^ sender, System::EventArgs^ e) {
		dataGridViewActivity->Hide();
		dataGridViewActivity->AllowUserToAddRows = false;
		dataGridViewActivity->AllowUserToDeleteRows = false;
		dataGridViewActivity->ReadOnly = true;
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
