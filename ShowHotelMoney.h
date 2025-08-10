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
	/// Summary for ShowHotelMoney
	/// </summary>
	public ref class ShowHotelMoney : public System::Windows::Forms::Form
	{
	public:
		Form^ previousForm;
		ShowHotelMoney(Form^ form)
		{
			this->previousForm = form;
			InitializeComponent();
			this->FormClosing += gcnew FormClosingEventHandler(this, &ShowHotelMoney::MyForm_FormClosing);
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ShowHotelMoney()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridViewBudget;
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
			this->dataGridViewBudget = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewBudget))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridViewBudget
			// 
			this->dataGridViewBudget->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewBudget->Location = System::Drawing::Point(46, 59);
			this->dataGridViewBudget->Name = L"dataGridViewBudget";
			this->dataGridViewBudget->Size = System::Drawing::Size(546, 352);
			this->dataGridViewBudget->TabIndex = 0;
			// 
			// ShowHotelMoney
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1251, 650);
			this->Controls->Add(this->dataGridViewBudget);
			this->Name = L"ShowHotelMoney";
			this->Text = L"ShowHotelMoney";
			this->Load += gcnew System::EventHandler(this, &ShowHotelMoney::ShowHotelMoney_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewBudget))->EndInit();
			this->ResumeLayout(false);

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


	private: System::Void MyForm_FormClosing(System::Object^ sender, FormClosingEventArgs^ e) {
		Application::Exit(); // Uygulamayý tamamen kapatýr
	}

	private: System::Void ShowHotelMoney_Load(System::Object^ sender, System::EventArgs^ e) {
		showHotelMoney(dataGridViewBudget);
		ResizeDataGridViewToFitContent(dataGridViewBudget);
		dataGridViewBudget->ClearSelection();
		dataGridViewBudget->AllowUserToAddRows = false;
		dataGridViewBudget->AllowUserToDeleteRows = false;
		dataGridViewBudget->ReadOnly = true;

		System::Drawing::Size dataGridSize = dataGridViewBudget->Size;
		int x = dataGridViewBudget->Location.X + dataGridSize.Width + 20;
		int y = dataGridViewBudget->Location.Y;

		Button^ btnBack = gcnew Button();
		btnBack->Size = System::Drawing::Size(150, 60);
		btnBack->Location = System::Drawing::Point(x, y);
		btnBack->Text = "Back";
		btnBack->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(162)));
		this->Controls->Add(btnBack);
		btnBack->Click += gcnew EventHandler(this, &ShowHotelMoney::OnRoomButtonClick);

	}

	private: System::Void OnRoomButtonClick(Object^ sender, EventArgs^ e)
	{
		this->Hide();
		previousForm->Show();
	}
	};
}
