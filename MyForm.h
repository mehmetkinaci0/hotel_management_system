#pragma once
#include "AdminEntry.h"
#include "CustomerEntry.h"
#include "HireRoom.h"
#include "InsertCustomerCheck.h"

namespace HotelManagementSystem {

    using namespace System::IO::Ports;
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class MyForm : public System::Windows::Forms::Form
    {
    private:
        SerialPort^ serialPort;

    public:
        MyForm(void)
        {
            InitializeComponent();
          //  InitializeSerialPort(); // Initialize serial port at the start.
            this->FormClosing += gcnew FormClosingEventHandler(this, &MyForm::MyForm_FormClosing);
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
        }

    protected:
        ~MyForm()
        {
            if (components)
            {
                delete components;
            }
            if (serialPort != nullptr && serialPort->IsOpen)
            {
                serialPort->Close(); // Ensure to close the serial port on form destruction.
            }
        }

    private:
        System::Windows::Forms::Button^ btnAdmin;
        System::Windows::Forms::Button^ btnCustomer;
    private: System::Windows::Forms::Button^ btnExit;

        System::ComponentModel::Container^ components;

        void InitializeComponent(void)
        {
            this->btnAdmin = (gcnew System::Windows::Forms::Button());
            this->btnCustomer = (gcnew System::Windows::Forms::Button());
            this->btnExit = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
            // 
            // btnAdmin
            // 
            this->btnAdmin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(162)));
            this->btnAdmin->Location = System::Drawing::Point(199, 110);
            this->btnAdmin->Name = L"btnAdmin";
            this->btnAdmin->Size = System::Drawing::Size(376, 90);
            this->btnAdmin->TabIndex = 0;
            this->btnAdmin->Text = L"ADMIN";
            this->btnAdmin->UseVisualStyleBackColor = true;
            this->btnAdmin->Click += gcnew System::EventHandler(this, &MyForm::btnAdmin_Click);
            // 
            // btnCustomer
            // 
            this->btnCustomer->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(162)));
            this->btnCustomer->Location = System::Drawing::Point(199, 275);
            this->btnCustomer->Name = L"btnCustomer";
            this->btnCustomer->Size = System::Drawing::Size(376, 90);
            this->btnCustomer->TabIndex = 1;
            this->btnCustomer->Text = L"CUSTOMER";
            this->btnCustomer->UseVisualStyleBackColor = true;
            this->btnCustomer->Click += gcnew System::EventHandler(this, &MyForm::btnCustomer_Click);
            // 
            // btnExit
            // 
            this->btnExit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(162)));
            this->btnExit->Location = System::Drawing::Point(199, 440);
            this->btnExit->Name = L"btnExit";
            this->btnExit->Size = System::Drawing::Size(376, 83);
            this->btnExit->TabIndex = 2;
            this->btnExit->Text = L"EXIT";
            this->btnExit->UseVisualStyleBackColor = true;
            this->btnExit->Click += gcnew System::EventHandler(this, &MyForm::btnExit_Click);
            // 
            // MyForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(778, 561);
            this->Controls->Add(this->btnExit);
            this->Controls->Add(this->btnCustomer);
            this->Controls->Add(this->btnAdmin);
            this->Name = L"MyForm";
            this->Text = L"MEHMET HOTEL";
            this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
            this->ResumeLayout(false);

        }

        void InitializeSerialPort()
        {
            serialPort = gcnew SerialPort("COM6", 9600);
            serialPort->DataReceived += gcnew SerialDataReceivedEventHandler(this, &MyForm::SerialPort_DataReceived);
            try {
                serialPort->Open();
            }
            catch (Exception^ ex) {
                MessageBox::Show("Could not open serial port: " + ex->Message);
            }
        }

        void SerialPort_DataReceived(Object^ sender, SerialDataReceivedEventArgs^ e)
        {
            String^ data = serialPort->ReadLine();
            this->Invoke(gcnew Action<String^>(this, &MyForm::ProcessSerialData), data);
        }

        void ProcessSerialData(String^ data)
        {
            if (data->Contains("PASSWORD_CORRECT")) {
                AdminEntry^ adminEntry = gcnew AdminEntry(this);
                adminEntry->Show();
                this->Hide();
            }
            else if (data->Contains("PASSWORD_INCORRECT")) {
                MessageBox::Show("Incorrect password. Try again.");
            }
        }

        System::Void btnAdmin_Click(System::Object^ sender, System::EventArgs^ e)
        {
            this->Hide();
            AdminEntry^ admin = gcnew AdminEntry(this);
            admin->Show();
            //MessageBox::Show("Please enter password");
        }

        System::Void btnCustomer_Click(System::Object^ sender, System::EventArgs^ e)
        {
            CustomerEntry^ customerEntry = gcnew CustomerEntry(this);
            customerEntry->Show();
            this->Hide();
        }

        System::Void MyForm_FormClosing(System::Object^ sender, FormClosingEventArgs^ e)
        {
            Application::Exit();
        }

        System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e)
        {
            connectDB();
        }
    private: System::Void btnExit_Click(System::Object^ sender, System::EventArgs^ e) {
        Application::Exit();
    }
};
}
