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
	/// Summary for ShowWorkers
	/// </summary>
	public ref class ShowWorkers : public System::Windows::Forms::Form
	{
	public:
		Form^ previousForm;
		ShowWorkers(Form^ previousForm)
		{
			this->previousForm = previousForm;
			InitializeComponent();
			this->FormClosing += gcnew FormClosingEventHandler(this, &ShowWorkers::MyForm_FormClosing);
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ShowWorkers()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridViewWorkers;
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
			this->dataGridViewWorkers = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewWorkers))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridViewWorkers
			// 
			this->dataGridViewWorkers->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewWorkers->Location = System::Drawing::Point(44, 32);
			this->dataGridViewWorkers->Name = L"dataGridViewWorkers";
			this->dataGridViewWorkers->Size = System::Drawing::Size(503, 396);
			this->dataGridViewWorkers->TabIndex = 0;
			// 
			// ShowWorkers
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1026, 777);
			this->Controls->Add(this->dataGridViewWorkers);
			this->Name = L"ShowWorkers";
			this->Text = L"ShowWorkers";
			this->Load += gcnew System::EventHandler(this, &ShowWorkers::ShowWorkers_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewWorkers))->EndInit();
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
	private: System::Void ShowWorkers_Load(System::Object^ sender, System::EventArgs^ e) {
		showWorkers(dataGridViewWorkers);
		ResizeDataGridViewToFitContent(dataGridViewWorkers);
		dataGridViewWorkers->AllowUserToAddRows = false;
		dataGridViewWorkers->AllowUserToDeleteRows = false;
		dataGridViewWorkers->ReadOnly = true;
		dataGridViewWorkers->ClearSelection();

		System::Drawing::Size dataGridSize = dataGridViewWorkers->Size;
		int x = dataGridViewWorkers->Location.X + dataGridSize.Width + 20;
		int y = dataGridViewWorkers->Location.Y;

		Button^ btnBack = gcnew Button();
		btnBack->Size = System::Drawing::Size(150, 60);
		btnBack->Location = System::Drawing::Point(x, y);
		btnBack->Text = "Back";
		btnBack->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(162)));
		this->Controls->Add(btnBack);
		btnBack->Click += gcnew EventHandler(this, &ShowWorkers::OnRoomButtonClick);

	}
	private: System::Void OnRoomButtonClick(Object^ sender, EventArgs^ e)
	{
		this->Hide();
		previousForm->Show();
	}

	private: System::Void MyForm_FormClosing(System::Object^ sender, FormClosingEventArgs^ e) {
		Application::Exit(); // Uygulamayý tamamen kapatýr
	}
	};
}
