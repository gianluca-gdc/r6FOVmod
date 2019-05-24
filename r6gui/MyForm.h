#pragma once
#include <iostream>
#include <string>
#include "Yeet.h"
#include "utils.h"


namespace r6gui {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:

		delegate void setLabel4Text(String^ textFov);
		setLabel4Text^ myDelegate;

		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ button1;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label1->Font = (gcnew System::Drawing::Font(L"Impact", 20.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(0, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(227, 34);
			this->label1->TabIndex = 0;
			this->label1->Text = L"R6 FOV Mdfr by GDC";
			
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Black;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI Black", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->label2->Location = System::Drawing::Point(340, 130);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(150, 30);
			this->label2->TabIndex = 1;
			this->label2->Text = L"FOV Modifier";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(285, 163);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(261, 20);
			this->textBox1->TabIndex = 2;
			this->textBox1->Text = L"Input Desired FOV here...";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label3->ForeColor = System::Drawing::SystemColors::Info;
			this->label3->Location = System::Drawing::Point(330, 238);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(80, 13);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Current FOV:";
			
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label4->ForeColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->label4->Location = System::Drawing::Point(407, 238);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(14, 13);
			this->label4->TabIndex = 4;
			this->label4->Text = L"0";
			
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(362, 189);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(104, 29);
			this->button1->TabIndex = 5;
			this->button1->Text = L"Enter";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::Button1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(798, 416);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->Text = L"R6SFOVModifier";
			this->ResumeLayout(false);
			this->PerformLayout();

			myDelegate = gcnew setLabel4Text(this, &MyForm::setLabel4TextMethod);
		}
#pragma endregion
	
	private: System::Void Button1_Click(System::Object^ sender, System::EventArgs^ e) {
		int userInputContainer = 0;
		System::String^ userInput = textBox1->Text;
		if (ifIntEntered(userInput)) {
			userInputContainer=stringToInt(userInput);
			writeFovValue(userInputContainer);

		}

	}
	public: 

		void setLabel4TextMethod(String^ textFov) {
			this->label4->Text = textFov;
		}

};
}
